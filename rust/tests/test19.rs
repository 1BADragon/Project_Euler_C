fn main() {
	let days = [31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31];
	let mut count = 0;
	let mut day_o_week = 1;
	for year in 1900..2001 {
		for month in 0..12 {
			let mut days_this_month = days[month];
			if month == 1 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)){
				days_this_month += 1;
			}
			if day_o_week == 0 && year != 1900{
				count += 1;
			}
			day_o_week = (day_o_week + days_this_month) % 7
		}
	}
	
	println!("{}", count);
}