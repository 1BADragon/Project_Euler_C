//Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
const NUM:i32 = 100;
fn main() {
    let sum = (NUM/2)*(NUM + 1);
    let sqr_of_sum = sum*sum;

    let sum_of_sqrs = (NUM*(NUM+1)*(2*NUM+1)) / 6;

    println!("{}", sqr_of_sum - sum_of_sqrs);
}
