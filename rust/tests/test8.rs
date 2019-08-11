use std::io::prelude::*;
use std::fs::File;
use std::i32;

fn main() {
    let mut f = File::open("./data/test8.dat").unwrap();
    let mut s = String::new();
    let _ = f.read_to_string(&mut s);
    let mut data: Vec<u32> = Vec::new();
    for l in s.lines() {
        for c in l.chars() {
            data.push(c.to_digit(10).unwrap() - '0'.to_digit(10).unwrap());
        }
    }
    let mut index = 13;
    let mut max = 0;
    while index < data.len() {
        let mut product: u64 = 1;
        for i in 0..13 {
            product *= data[index-i] as u64;
        }
        if product > max{
            max = product;
        }
        index += 1;
    }

    println!("{}", max);
}
