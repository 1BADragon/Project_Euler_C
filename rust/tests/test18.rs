use std::io::Read;
use std::fs::File;
use std::i32;
use std::cmp;

fn main() {
	let mut inf = File::open("./data/test18.dat").unwrap();
	let mut indat = String::new();
	let _ = inf.read_to_string(&mut indat);
	let mut tri: Vec<Vec<i32>> = Vec::new();
	for l in indat.lines() {
		let mut temp: Vec<i32> = Vec::new();
		for n in l.split_whitespace() {
			temp.push(i32::from_str_radix(n, 10).unwrap());
		}
		tri.push(temp);
	}
	let sum = find_route(0, 0, &tri);
	/*
	let mut last_index = 0;
	let mut sum = tri[0][0];
	for i in 1..tri.len() {
		if tri[i][last_index] > tri[i][last_index + 1] {
			sum += tri[i][last_index];
		}
		else {
			sum += tri[i][last_index + 1];
			last_index += 1;
		}
	}
	*/
	
	println!("{}", sum);
}

fn find_route(level: usize, index: usize, tri: &Vec<Vec<i32>>) -> i32 {
	if level >= tri.len() {
		return 0;
	}
	
	return cmp::max(find_route(level + 1, index, tri) + tri[level][index],
					find_route(level + 1, index + 1, tri) + tri[level][index]);
}