//Find the sum of all primes below two million
fn main() {
    let mut curr_num = 2;
    let mut sum:u64 = 0;
    while curr_num < 2000000 {
        if is_prime(curr_num) {
            sum += curr_num as u64;
        }
        if curr_num == 2 {
            curr_num += 1;
        }
        else {
            curr_num += 2;
        }
    }
    println!("{}", sum);    
}

fn is_prime(num: i32) -> bool{
    for i in 2..((num as f32).sqrt()) as i32 + 1{
        if num % i == 0 {
            return false;
        }
    }
    return true;
}
