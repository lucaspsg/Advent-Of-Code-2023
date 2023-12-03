const di: [isize; 8] = [1, 1, 0, -1, -1, -1, 0, 1];
const dj: [isize; 8] = [0, 1, 1, 1, 0, -1, -1, -1];

pub fn solve_puzzle_1(input: String) -> i32 {
    let grid: Vec<Vec<char>> = input.lines().map(|line| line.chars().collect()).collect();
    let mut sum = 0;
    let mut s: String = String::new();
    let mut is_part = false;
    for i in 0..grid.len() {
        for j in 0..grid[0].len() {
            if grid[i][j].is_numeric() {
                s.push(grid[i][j]);
                for k in 0..di.len() {
                    let ii = (i as isize) + di[k];
                    let jj = (j as isize) + dj[k];
                    if (ii >= 0
                        && ii < (grid.len() as isize)
                        && jj >= 0
                        && jj < (grid[0].len() as isize)
                        && !grid[(ii as usize)][(jj as usize)].is_numeric()
                        && grid[(ii as usize)][(jj as usize)] != '.')
                    {
                        is_part = true;
                    }
                }
            } else {
                if is_part {
                    sum += s.parse::<i32>().unwrap();
                }
                s = String::new();
                is_part = false;
            }
        }
    }
    return sum;
}
