use std::collections::HashMap;

pub fn solve_puzzle_2(input: String) -> u64 {
    let lines = input.lines().collect::<Vec<&str>>();
    let mut cards_qty = vec![1; lines.len() + 1];
    let mut sum = 0;
    for line in lines {
        let card_n = line.split(":").collect::<Vec<&str>>()[0]
            .split_whitespace()
            .collect::<Vec<&str>>()[1]
            .parse::<u64>()
            .unwrap();
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
            for i in (card_n + 1)..(card_n + 1 + count) {
                cards_qty[i as usize] += cards_qty[card_n as usize];
            }
        }
        sum += cards_qty[card_n as usize];
    }
    return sum;
}
