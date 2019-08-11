//find the smallest number that is evenly divided by all number 1-20
fn main() {
    let mut num = 1;
    loop { //hey it works
        if works(num) {
            println!("{}", num);
            return;
        }
        num += 1;
    }
}

fn works(num: i32) -> bool {
    for i in 1..20 {
        if num % i != 0 {
            return false;
        }
    }
    return true;
}
                
    
