//What is the sum of the digits fo the number 2^1000?
fn main() {
    let mut crazy_num = [0; 1000]; //i know that 2^1000 is no more that 1000 digits
    crazy_num[0] = 1;
    for exp in 0..1000 {
        let mut carry = 0;
        for index in 0..1000 {
            let mut prod = crazy_num[index] * 2 + carry;
            carry = if prod > 9 {
                prod = prod % 10;
                1
            } else {
                0
            };
            crazy_num[index] = prod;
        }
    }
    let sum = crazy_num.iter().fold(0, |sum, x| sum + x);
    println!("{}", sum);
}
