const dj: [isize; 8] = [0, 1, 1, 1, 0, -1, -1, -1];
const di: [isize; 8] = [1, 1, 0, -1, -1, -1, 0, 1];

pub fn solve_puzzle_2(input: String) -> u64 {
    let grid: Vec<Vec<char>> = input.lines().map(|line| line.chars().collect()).collect();
    let mut seen: Vec<Vec<bool>> = vec![vec![false; grid[0].len()]; grid.len()];
    let mut sum = 0;
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            let mut parts: Vec<u64> = Vec::new();
            if grid[i][j] != '*' {
                continue;
            }
            for k in 0..di.len() {
                let ii = i as isize + di[k];
                let jj = j as isize + dj[k];
                if ii >= 0
                    && ii < grid.len() as isize
                    && jj >= 0
                    && jj < grid[0].len() as isize
                    && grid[ii as usize][jj as usize].is_numeric()
                    && !seen[ii as usize][jj as usize]
                {
                    let num = get_num(ii as usize, jj as usize, &grid);
                    parts.push(num);
                    if ii as usize != i {
                        if grid[ii as usize][j].is_numeric() {
                            if j > 0 {
                                seen[ii as usize][j - 1] = true;
                            }
                            seen[ii as usize][j] = true;
                            if j + 1 < grid[0].len() {
                                seen[ii as usize][j + 1] = true;
                            }
                        }
                    } else {
                        seen[ii as usize][jj as usize] = true;
                    }
                    println!("for * at pos i = {i} j = {j} appending num = {num} at pos ii = {ii} jj = {jj}");
                }
            }
            if parts.len() == 2 {
                sum += parts[0] * parts[1];
                println!("Summing {sum}");
            }
            for k in 0..di.len() {
                let ii = i as isize + di[k];
                let jj = j as isize + dj[k];
                if ii >= 0 && ii < grid.len() as isize && jj >= 0 && jj < grid[0].len() as isize {
                    seen[ii as usize][jj as usize] = false;
                }
            }
        }
    }
    return sum;
}

fn get_num(i: usize, j: usize, grid: &Vec<Vec<char>>) -> u64 {
    let mut jj = j;
    let beg_j = loop {
        if jj == 0 || !grid[i][jj - 1].is_numeric() {
            break jj;
        } else {
            jj -= 1;
        }
    };
    jj = beg_j;
    let end_j = loop {
        if jj == grid[0].len() - 1 || !grid[i][jj + 1].is_numeric() {
            break jj;
        } else {
            jj += 1;
        }
    };
    let mut num = String::new();
    for jj in beg_j..(end_j + 1) {
        num.push(grid[i][jj]);
    }
    return num.parse().unwrap();
}
