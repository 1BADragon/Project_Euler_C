fn main() {
    let mut tri_num: u64 = 0;
    let mut index: u64 = 1;
    loop {
        tri_num += index;
        index += 1;
        if num_factors(tri_num) > 500 {
            println!("{}", tri_num);
            break;
        }
    }
}

fn num_factors(num: u64) -> i32 {
    let mut count = 0;
    let sqrt:u64 = (num as f64).sqrt() as u64;
    if num % sqrt == 0 {
        count += 1;
    }
    for i in 1u64..sqrt {
        if num % i == 0 {
            count += 2;
        }
    }
    return count;
}
