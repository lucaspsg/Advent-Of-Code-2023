use std::cmp;

#[path = "./utils.rs"]
mod utils;

pub fn solve_puzzle_2(input: String) -> i32 {
    let games = input.lines();
    let mut sum = 0;

    for game in games {
        let mut n_of_red_cubes: i32 = 0;
        let mut n_of_green_cubes: i32 = 0;
        let mut n_of_blue_cubes: i32 = 0;

        let subsets = utils::get_subsets(game);

        for subset in subsets {
            let cubes = utils::get_cubes(subset);
            for cube in cubes {
                let (n_of_cubes, color) = utils::get_cube_n_and_color(cube);
                match color {
                    "red" => {
                        n_of_red_cubes = cmp::max(n_of_cubes, n_of_red_cubes);
                    }
                    "green" => {
                        n_of_green_cubes = cmp::max(n_of_cubes, n_of_green_cubes);
                    }
                    "blue" => {
                        n_of_blue_cubes = cmp::max(n_of_cubes, n_of_blue_cubes);
                    }
                    _ => {
                        println!("Error");
                    }
                }
            }
        }
        sum += n_of_red_cubes * n_of_green_cubes * n_of_blue_cubes;
    }
    return sum;
}
