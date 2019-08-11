//Which starting number, under one million, produces the longest chain?
use std::cmp;
fn main() {
    let mut max = (0,0);
    for i in 1..1000000 {
        let temp = chain_len(i);
        if temp > max.0 {
            max = (temp, i);
        }
    }

    println!("{:?}", max);
}

fn eval(num: u64) -> u64 {
    if num % 2 == 0 {
        num / 2
    } else {
        3*num + 1
    }
}

fn chain_len(mut num: u64) -> i32 {
    let mut count = 0;
    while num > 1 {
        num = eval(num);
        count += 1;
    }

    return count;
}
