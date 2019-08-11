// How many routes are there through a 20x20 grid?

// I dont think rust has a datasize big enough for this problem
fn main() {
    let mut old: [u64; 20] = [1; 20];
    for i in 0..20 {
        for j in 0..i {
            if j == 0 {
                old[j] = old[j] + 1;
            } else {
                old[j] = old[j] + old[j-1];
            }
        }
        if i == 0 {
            old[i] = 2;
        } else {
            old[i] = 2 * old[i-1];
        }
    }
    println!("{}", old[19]);
}
