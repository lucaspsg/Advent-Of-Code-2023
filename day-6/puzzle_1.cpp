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

signed main() {
  ifstream Input("./input.txt");
  string line;
  vector<int> times;
  vector<int> distances;
  getline(Input, line);
  vector<string> ss = split(line, ' ');
  for (int i = 1; i < ss.size(); i++) times.push_back(stol(trim(ss[i])));
  getline(Input, line);
  ss = split(line, ' ');
  for (int i = 1; i < ss.size(); i++) distances.push_back(stol(trim(ss[i])));
  vector<int> ans;
  for (int i = 0; i < times.size(); i++) {
	  int time = times[i];
	  int dist = distances[i];
	  int counter = 0;
	  for (int j = 0; j < time; j++) {
		  if ((time-j)*j > dist) counter++;
	  }
	  ans.push_back(counter);
  }
  int acc_ans = 1;
  for (auto i : ans) acc_ans *= i;
  cout << "ans = " << acc_ans << endl;
  return 0;
}
