//What is the largest prime factor of the number 600851475143
const NUM: f64 = 600851475143f64;
const NUM_INT: i64 = 600851475143;
fn main() {
    let sqrt = NUM.sqrt() as i32;
    for i in (0..sqrt).rev() {
        if NUM_INT % i as i64 == 0 {
            if prime(i as i64){
                println!("{:?}", i);
                break;
            }
        }
    }
}

fn prime(p: i64) -> bool {
    let sqrt = (p as f64).sqrt();
    for i in 2..sqrt as i64{
        if p % i == 0 {
            return false;
        }
    }
    return true;
}
