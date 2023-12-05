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

vector<tuple<int, int, int>> mappings[8];
vector<tuple<int, int, int>> seeds;

int find_location(int start, int end, int map_i) {
  for (auto p : mappings[map_i]) {
    int first = get<0>(p);
    int third = get<2>(p);
    if ((first >= start && first <= end) ||
        (first + third - 1 >= start && first + third - 1 <= end)) {
      if (map_i == 0)
        return first;
      else {
        return find_location(first, first + third - 1, map_i - 1);
      }
    }
  }
  if (map_i == 0)
    return -1;
  else {
    return find_location(start, end, map_i - 1);
  }
}

signed main() {
  ifstream Input("./input.txt");
  string first_line;
  int minn = LONG_MAX;
  getline(Input, first_line);
  vector<string> s_seeds = split(trim(split(first_line, ':')[1]), ' ');
  for (int i = 0; i < s_seeds.size() - 1; i += 2) {
    int a = stoul(s_seeds[i]);
    int b = stoul(s_seeds[i + 1]);
    if (a < b)
      seeds.push_back({a, a, b - a + 1});
    else
      seeds.push_back({b, b, a - b + 1});
  }
  string line;
  int index = 0;
  while (getline(Input, line)) {
    if (isalpha(line[0]))
      index += 1;
    else if (isdigit(line[0])) {
      vector<string> s_nums = split(line, ' ');
      mappings[index].push_back(
          {stoul(s_nums[0]), stoul(s_nums[1]), stoul(s_nums[2])});
    }
  }
  mappings[0] = seeds;
  for (int i = 0; i <= 7; i++)
    sort(mappings[i].begin(), mappings[i].end());
  sort(seeds.begin(), seeds.end());
  for (auto m : mappings[7]) {
    minn = find_location(get<1>(m), get<1>(m) + get<2>(m) - 1, 6);
    if (minn != -1) {
      Input.close();
      cout << "Puzzle 2 answer = " << get<0>(m) << endl;
      return 0;
    }
  }
  Input.close();
  return 0;
}
