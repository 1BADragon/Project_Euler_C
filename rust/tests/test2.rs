///Find the sum of the even-valued fib terms less then 4 million
fn main() {
    let mut prev: i64 = 1;
    let mut curr: i64 = 2;
    let mut sum: i64 = curr;
    while curr< 4000000 {
        let temp = prev;
        prev = curr;
        curr = prev + temp;
        if curr % 2 == 0 {
            sum += curr;
        }
    }
    println!("{}", sum);
}
