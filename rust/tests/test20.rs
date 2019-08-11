//find 100 factorial...yikes
mod include;

use include::bigint::Bigint;

fn main() {
    let a = Bigint::from_int(100);
    let b = Bigint::from_int(4657);
    
    let c = a.clone() + b.clone();
    
    println!("{} + {} = {}", a, b, c);
}
