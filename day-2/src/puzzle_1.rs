#[path = "./utils.rs"]
mod utils;

pub fn solve_puzzle_1(input: String) -> i32 {
    const RED_CUBES: i32 = 12;
    const GREEN_CUBES: i32 = 13;
    const BLUE_CUBES: i32 = 14;

    let games = input.lines();
    let mut sum = 0;

    for game in games {
        let mut is_possible = true;

        let subsets = utils::get_subsets(game);

        for subset in subsets {
            let cubes = utils::get_cubes(subset);
            for cube in cubes {
                let (n_of_cubes, color) = utils::get_cube_n_and_color(cube);
                match color {
                    "red" => {
                        if n_of_cubes > RED_CUBES {
                            is_possible = false;
                        }
                    }
                    "green" => {
                        if n_of_cubes > GREEN_CUBES {
                            is_possible = false;
                        }
                    }
                    "blue" => {
                        if n_of_cubes > BLUE_CUBES {
                            is_possible = false;
                        }
                    }
                    _ => {
                        println!("Error");
                    }
                }
            }
        }
        if is_possible {
            let game_n = utils::get_game_n(game);
            sum += game_n;
        }
    }
    return sum;
}
