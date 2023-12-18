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
  int ans = 0;
  int time = 0, dist = 0;
  for (int i = times.size() - 1; i >= 0; i--) {
	  if (i != times.size() -1) for (int j = 0; j < to_string(times[i+1]).size(); j++) times[i] *= 10;
	  time += times[i];
  }
  for (int i = distances.size() - 1; i >= 0; i--) {
	  if (i != distances.size() -1) for (int j = 0; j < to_string(distances[i+1]).size(); j++) distances[i] *= 10;
	  dist += distances[i];
  }
  for (int i = 0; i <= time; i++) {
	  if ((time - i) * i > dist) ans++;
  }
  cout << "ans = " << ans << endl;
  return 0;
}
