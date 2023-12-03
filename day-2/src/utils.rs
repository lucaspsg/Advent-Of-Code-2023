pub fn get_subsets(game: &str) -> Vec<&str> {
    let subsets = game.split(":").last().unwrap().trim();
    let subsets = subsets.split(";").collect();
    return subsets;
}

pub fn get_cubes(subset: &str) -> Vec<&str> {
    let cubes = subset.split(",");
    let cubes = cubes.map(|x| x.trim()).collect();
    return cubes;
}

pub fn get_cube_n_and_color(cube: &str) -> (i32, &str) {
    let n_of_cubes: i32 = cube.split(" ").next().unwrap().trim().parse().unwrap();
    let color = cube.split(" ").last().unwrap();
    return (n_of_cubes, color);
}

pub fn get_game_n(game: &str) -> i32 {
    let game_n = game
        .split(":")
        .next()
        .unwrap()
        .split(" ")
        .last()
        .unwrap()
        .parse::<i32>()
        .unwrap();
    return game_n;
}
