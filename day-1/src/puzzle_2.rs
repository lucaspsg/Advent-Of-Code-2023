static NUMBERS: [&str; 18] = [
    "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "1", "2", "3", "4",
    "5", "6", "7", "8", "9",
];

pub fn solve_puzzle_2(input: String) -> i32 {
    let lines = input.lines();
    let mut sum = 0;
    for line in lines {
        let first_number = cast_num(get_first_number(line));
        let last_number = cast_num(get_last_number(line));
        sum += first_number * 10 + last_number;
    }
    return sum;
}

fn get_first_number(s: &str) -> &str {
    let mut min_num_index = std::i32::MAX;
    let mut min_num = "";
    for number in NUMBERS {
        let index = s.find(number);
        match index {
            Some(x) => {
                let y = x as i32;
                if y < min_num_index {
                    min_num_index = y;
                    min_num = number;
                }
            }
            None => (),
        }
    }
    return min_num;
}

fn get_last_number(s: &str) -> &str {
    let reversed_s = s.chars().rev().collect::<String>();
    let mut max_num_index = std::i32::MAX;
    let mut max_num = "";
    for number in NUMBERS {
        let reversed_num = number.chars().rev().collect::<String>();
        let index = reversed_s.find(&reversed_num);
        match index {
            Some(x) => {
                let y = x as i32;
                if y < max_num_index {
                    max_num_index = y;
                    max_num = number;
                }
            }
            None => (),
        }
    }
    return max_num;
}

fn cast_num(s: &str) -> i32 {
    match s {
        "one" | "1" => 1,
        "two" | "2" => 2,
        "three" | "3" => 3,
        "four" | "4" => 4,
        "five" | "5" => 5,
        "six" | "6" => 6,
        "seven" | "7" => 7,
        "eight" | "8" => 8,
        "nine" | "9" => 9,
        _ => 0,
    }
}
