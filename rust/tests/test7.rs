//const N:f32 = 10001f32;
const N:i32 = 10001;
fn main() {
    /*
    let min_f = N*N.ln() + N*(((N-1f32).ln()).ln());
    let max_f = N*N.ln() + N*((N.ln()).ln());
    let min = min_f as i32;
    let max = max_f as i32;
    println!("{:?}", (min, max));
    for i in min-1..max+2 {
        if is_prime(i) {
            println!("{}", i);
            return;
        }
    }
     */

    let mut prime_count = 1; //2 is counted
    let mut curr_num = 3; //need to start at three for this to work
    loop {
        if is_prime(curr_num) {
            prime_count += 1;
            
        }

        if prime_count == N {
            println!("{}", curr_num);
            break;
        }

        curr_num += 2;
    }
    
}

fn is_prime(num: i32) -> bool{
    for i in 2..((num as f32).sqrt()) as i32 + 1{
        if num % i == 0 {
            return false;
        }
    }
    return true;
}
