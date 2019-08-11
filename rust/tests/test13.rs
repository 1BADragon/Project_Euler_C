use std::io::Read;
use std::fs::File;
use std::u64;
fn main() {
    let mut inf = File::open("./data/test13.dat").unwrap();
    let mut indat = String::new();
    let _ = inf.read_to_string(&mut indat);
    let mut carry: u64 = 0;
    let mut sum: u64 = 0;
    for i in (0..5).rev() {
        sum = carry;
        for l in indat.lines() {
            sum += u64::from_str_radix(&(&l[(i*10)..(i*10 + 9)]), 10).unwrap();
        }
        carry = sum / (10u64.pow(9u32));
        println!("{} {}", sum, carry);
    }
    println!("{}", &((sum).to_string())[0..10]);
}
