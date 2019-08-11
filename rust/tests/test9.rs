fn main() {
    'outer: for a in 1..1000 {
        for b in a..1000 {
            for c in b..1000 {
                if a*a + b*b == c*c && a + b + c == 1000 {
                    println!("{}", a*b*c);
                    break 'outer;
                }
            }
        }
    }
}
