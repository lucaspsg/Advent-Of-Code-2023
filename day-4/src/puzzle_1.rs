use std::collections::HashMap;

pub fn solve_puzzle_1(input: String) -> u64 {
    let lines = input.lines();
    let mut sum = 0;
    for line in lines {
        let cards = line.split(": ").collect::<Vec<&str>>()[1];
        let cards = cards
            .split("|")
            .map(|cards| cards.trim())
            .collect::<Vec<&str>>();
        let winning_cards = cards[0].split_whitespace().collect::<Vec<&str>>();
        let your_cards = cards[1].split_whitespace().collect::<Vec<&str>>();
        let mut seen_cards = HashMap::new();
        for card in winning_cards {
            seen_cards.insert(card, true);
        }
        let mut count = 0;
        for card in your_cards {
            if seen_cards.contains_key(card) {
                count += 1;
            }
        }
        if count > 0 {
            sum += (2 as u64).pow(count - 1);
        }
    }
    return sum;
}
