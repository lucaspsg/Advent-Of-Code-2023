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
      tokens.push_back(token);
      token = "";
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

vector<vector<int>> mappings[8];

int find_location(int seed, int depth) {
  int val = -1;
  for (auto m : mappings[depth]) {
    if (seed >= m[1] && seed < m[1] + m[2]) {
      val = m[0] + seed - m[1];
    }
  }
  val = (val == -1 ? seed : val);
  return (depth == 7 ? val : find_location(val, depth + 1));
}

signed main() {
  ifstream Input("./input.txt");
  string first_line;
  int minn = LONG_MAX;
  getline(Input, first_line);
  vector<string> s_seeds = split(trim(split(first_line, ':')[1]), ' ');
  vector<int> seeds;
  for (string seed : s_seeds)
    seeds.push_back(stoul(seed));
  string line;
  int index = 0;
  while (getline(Input, line)) {
    if (isalpha(line[0]))
      index += 1;
    else if (isdigit(line[0])) {
      vector<string> s_nums = split(line, ' ');
      vector<int> i;
      for (auto s : s_nums)
        i.push_back(stoul(s));
      mappings[index].push_back(i);
    }
  }
  for (int seed : seeds) {
    minn = min(minn, find_location(seed, 1));
  }
  Input.close();
  cout << "Puzzle 1 Answer = " << minn << endl;
  return 0;
}
