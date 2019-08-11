
fn main() {
    let single_things = [0,3,3,5,4,4,3,5,5,4,3,6,6,8,8,7,7,9,8,8]; //1-19
    let double_things = [0,3,6,6,5,5,5,7,6,6]; //10-90
    let hundred = 7; //hundred
    let thousand = 8; //thousand

    let mut sum = 0;

    for i in 1..1000{
        let c = i % 10; //one's place 
        let b = ((i % 100) - c) / 10; //ten's place
        let a = ((i % 1000) - (b * 10) - c) / 100; //hundred's place
		
		if a != 0 {
			sum += single_things[a] + hundred;
			if b != 0 || c != 0 {
				sum += 3;
			}
		}
		if b == 0 || b == 1 {
			sum += single_things[(b * 10 + c) % single_things.len()];
		}
		else {
			sum += double_things[b] + single_things[c];
		}		
	}
	sum += single_things[1] + thousand;
	println!("{}", sum);
}
