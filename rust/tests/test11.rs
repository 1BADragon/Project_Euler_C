use std::fs::File;
use std::io::Read;
use std::u64;
use std::cmp;
fn main() {
    let mut inf = File::open("./data/test11.dat").unwrap();
    let mut data = String::new();
    let _ = inf.read_to_string(&mut data);
    let mut mat:Vec<Vec<u64>> = Vec::new();
    for l in data.lines() {
        let mut row: Vec<u64> = Vec::new();
        for num in l.split_whitespace() {
            row.push(u64::from_str_radix(num, 10).unwrap());
        }
        mat.push(row);
    }

    let mut max = 0;
    for i in 0..20 {
        for j in 0..16 {
            let prod = mat[i][j] * mat[i][j+1] * mat[i][j+2] * mat[i][j+3];
            max = cmp::max(max, prod);
            let prod = mat[j][i] * mat[j+1][i] * mat[j+2][i] * mat[j+3][i];
            max = cmp::max(max, prod);
        }
    }

    for i in 3..20 {
        for j in 0..16 {
            let prod = mat[i][j] * mat[i-1][j+1] * mat[i-2][j+2] * mat[i-3][j+3];
            max = cmp::max(max, prod);
        }
    }

    println!("{}", max);
}
