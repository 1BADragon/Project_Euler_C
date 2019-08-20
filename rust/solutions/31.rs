use std::env;

static COINS: &'static [i32] = &[1, 2, 5, 10, 20, 50, 100, 200];

fn get_ways(val: i32, current: i32) -> i32 {
    if val <= 0 {
        return 1;
    }
    else {
        let mut sum = 0;
        for c in COINS {
            if val >= *c && *c >= current {
                sum += get_ways(val - *c, *c);
            }
        }
        return sum;
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();
    let val: i32 = args[1].parse().unwrap();
    println!("{}", get_ways(val, 0));
}
