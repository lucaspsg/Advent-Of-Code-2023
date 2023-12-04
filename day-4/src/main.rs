use std::fs;

mod puzzle_1;
mod puzzle_2;

fn main() {
    let input = fs::read_to_string("./src/input.txt").expect("Should have been able to read file");
    let puzzle_1_ans = puzzle_1::solve_puzzle_1(input.clone());
    let puzzle_2_ans = puzzle_2::solve_puzzle_2(input.clone());
    println!("Puzzle 1 Answer = {puzzle_1_ans}");
    println!("Puzzle 2 Answer = {puzzle_2_ans}");
}
