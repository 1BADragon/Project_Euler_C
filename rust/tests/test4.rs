//find the largest palindrome made from the product of two 3-digit numbers
fn main() {
    let mut ans: Vec<i32> = Vec::new();
    for i in (100..999).rev(){     //O(n2) ugg.. it works
        for j in (100..999).rev(){
            if is_palin(i*j) {
                ans.push(i*j);
            }
        }
    }
    ans.sort();
    println!("{}", ans.last().unwrap());
}

fn is_palin(num: i32) -> bool {
    let num = num.to_string().into_bytes();
    let len = num.len();
    for i in 0..len {
        if num[i] != num[len-(i+1)] {
            return false;
        }
    }
    return true;
}
