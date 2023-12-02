pub fn solve_puzzle_1(input: String) -> i32 {
    let lines = input.lines();
    let mut sum = 0;
    for line in lines {
        let first_num_char = get_first_numerical_char(line);
        let last_num_char = get_last_numerical_char(line);
        let line_num = concat_chars_to_int(first_num_char, last_num_char);
        sum += line_num;
    }
    return sum;
}

fn get_first_numerical_char(s: &str) -> char {
    for c in s.chars() {
        if c.is_numeric() {
            return c;
        }
    }
    return '0';
}
fn get_last_numerical_char(s: &str) -> char {
    for c in s.chars().rev() {
        if c.is_numeric() {
            return c;
        }
    }
    return '0';
}

fn concat_chars_to_int(c1: char, c2: char) -> i32 {
    let s = format!("{}{}", c1, c2);
    return s.parse().unwrap();
}
