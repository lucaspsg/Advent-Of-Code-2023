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

string trim(string s, char c) {
  int i = s.find_first_not_of(c);
  int j = s.find_last_not_of(c);
  return s.substr(i, j - i + 1);
}


signed main() {
  ifstream Input("./input.txt");
  string line;
  getline(Input, line);
  string instructions = line;
  getline(Input, line);
  map<string,pair<string,string>> adj;
  while(getline(Input, line)) {
    string node = trim(split(line, '=')[0], ' ');
    string adj1 = split(trim(trim(trim(split(line, '=')[1], ' '), '('), ')'), ',')[0];
    string adj2 = trim(split(trim(trim(trim(split(line, '=')[1], ' '), '('), ')'), ',')[1], ' ');
    adj[node] = make_pair(adj1, adj2);
  }
  string node = "AAA";
  int steps = 0;
  while (node != "ZZZ") {
    if (instructions[steps % instructions.size()] == 'L') node = adj[node].first;
    else node = adj[node].second;
    steps++;
  }
  cout << "ans = " << steps << endl;
  return 0;
}
