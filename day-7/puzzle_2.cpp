#include <bits/stdc++.h>
#define int long long int
using namespace std;

vector<string> split(string s, char delimiter) {
  vector<string> tokens;
  string token = "";
  for (char c : s) {
    if (c != delimiter)
      token += c;
    else {
      if (token != "") {
	      tokens.push_back(token);
	      token = "";
      }
    }
  }
  if (token != "")
    tokens.push_back(token);
  return tokens;
}

string trim(string s) {
  int i = s.find_first_not_of(" ");
  int j = s.find_last_not_of(" ");
  return s.substr(i, j - i + 1);
}

enum Card {J, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, T, Q, K, A, CARD_ERROR};
enum HandType { FIVE_OF_A_KIND = 7, FOUR_OF_A_KIND = 6, FULL_HOUSE = 5, THREE_OF_A_KIND = 4, TWO_PAIR = 3, ONE_PAIR = 2, HIGH_CARD = 1, HAND_ERROR = 0 };
typedef vector<Card> Hand;
typedef pair<HandType,Hand> HandData;

Hand createHand(string s) {
  Hand hand;
  for (auto c : s) {
    switch (c) {
      case '2':
        hand.push_back(TWO);
        break;
      case '3':
        hand.push_back(THREE);
        break;
      case '4':
        hand.push_back(FOUR);
        break;
      case '5':
        hand.push_back(FIVE);
        break;
      case '6':
        hand.push_back(SIX);
        break;
      case '7':
        hand.push_back(SEVEN);
        break;
      case '8':
        hand.push_back(EIGHT);
        break;
      case '9':
        hand.push_back(NINE);
        break;
      case 'T':
        hand.push_back( T);
        break;
      case 'J':
        hand.push_back(J);
        break;
      case 'Q':
        hand.push_back(Q);
        break;
      case 'K':
        hand.push_back(K);
        break;
      case 'A':
        hand.push_back(A);
        break;
      default:
        hand.push_back(CARD_ERROR);
        break;
    }
  }
  return hand;
}

// using a map
// five of a kind - one key only with 5 value
// four of a kind - two keys with 4 and 1 values respectively
// full house - two keys with 3 and 2 values respectively
// three of a kind - three keys with 3, 1 and 1 values respectively
// two pair - three keys with 2, 2 and 1 values respectively
// one pair - four keys with 2, 1, 1 and 1 values respectively
// high card - five keys with 1, 1, 1, 1 and 1 values respectively
HandData get_hand_data(Hand hand) {
  map<Card,int> m;
  for (auto c : hand) m[c]++;
  Card card_not_j = CARD_ERROR;
  int biggest_val_not_j = -1;
  for (auto p : m) {
    if (p.second > biggest_val_not_j && p.first != J) {
      biggest_val_not_j = p.second;
      card_not_j = p.first;
    }
  }
  m[card_not_j] += m[J];
  m[J] = -1;
  multiset<int> values;
  for (auto p : m) if (p.second != -1) values.insert(p.second);
  switch (values.size()) {
    case 1:
      return make_pair(FIVE_OF_A_KIND, hand);
      break;
    case 2:
      if (*values.rbegin() == 4) return make_pair(FOUR_OF_A_KIND, hand);
      else return make_pair(FULL_HOUSE, hand);
      break;
    case 3:
      if (*values.rbegin() == 3) return make_pair(THREE_OF_A_KIND, hand);
      else return make_pair(TWO_PAIR, hand);
      break;
    case 4:
      return make_pair(ONE_PAIR, hand);
      break;
    case 5:
      return make_pair(HIGH_CARD, hand);
    default:
      return make_pair(HAND_ERROR, hand);
  }
}

void printHand(Hand h) {
  for (auto c : h) {
    switch (c) {
      case TWO:
        cout << "2";
        break;
      case THREE:
        cout << "3";
        break;
      case FOUR:
        cout << "4";
        break;
      case FIVE:
        cout << "5";
        break;
      case SIX:
        cout << "6";
        break;
      case SEVEN:
        cout << "7";
        break;
      case EIGHT:
        cout << "8";
        break;
      case NINE:
        cout << "9";
        break;
      case T:
      cout << "T";
        break;
      case J:
    cout << "J";
        break;
      case Q:
    cout << "Q";
        break;
      case K:
    cout << "K";
        break;
      case A:
    cout << "A";
        break;
      default:
        return;
        break;
    }
  }
}


bool comp(pair<HandData, int> p1, pair<HandData, int> p2) {
  if (p1.first.first != p2.first.first) return p1.first.first < p2.first.first;
  else {
    return p1.first.second < p2.first.second;
  }
}


signed main() {
  ifstream Input("./input.txt");
  string line;
  vector<pair<HandData, int>> hand_data_bid;
  while (getline(Input, line)) {
    vector<string> s = split(line, ' ');
    Hand hand = createHand(s[0]);
    int bid = stol(s[1]);
    HandData hand_data = get_hand_data(hand);
    hand_data_bid.push_back(make_pair(hand_data, bid));
  }
  sort(hand_data_bid.begin(), hand_data_bid.end(), comp);
  int ans = 0;
  for (int i = 1; i <= hand_data_bid.size(); i++) {
    ans += hand_data_bid[i-1].second * i;
  }
  cout << "ans = " << ans << endl;
  return 0;
}