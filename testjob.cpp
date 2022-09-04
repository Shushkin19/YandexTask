#include<iostream>
#include<string>
#include<vector>
#include<sstream>

using namespace std;




struct pers {
	vector<string> name;
	string ch;
	int d, m, y;
	void fill(string arr);
	int sum_diff_char();
	int sum_day_month();
	int all_sum_hex();
};



const vector<string> explode(const string& s, const char& c)
{
	string buff{ "" };
	vector<string> v;

	for (auto n : s)
	{
		if (n != c) buff += n; else
			if (n == c && buff != "") { v.push_back(buff); buff = ""; }
	}
	if (buff != "") v.push_back(buff);

	return v;
}

void pers::fill(string arr) {
	vector<string> v{ explode(arr, ',') };
	if (v.size() == 6) {
		for (int i = 0; i < 3; i++) {
			this->name.push_back(v[i]);
			
		}
		d = stoi(v[3]);
		m = stoi(v[4]);
		y = stoi(v[5]);
	}
	else {
		cout << "Line error\n";
	}
}


int pers::sum_diff_char() {

	ch = name[0] + name[1] + name[2];
	int result = 0;
	/*for (const char c : ch) {
		result += ch.find(c) != string::npos;
	}*/
	
	int cnt = 0;
	for (int i = 0; i < ch.length(); i++) {
		for (int j = i + 1; j < ch.length(); j++) {
			if (ch[i] == ch[j]) {
				ch.erase(j,1);
			}
		}
	}

	return ch.length();
}
int pers::sum_day_month() { //d =12 m = 8
	int res = 0;
	if (d > 10) {
		int d1 = d / 10;
		int d2 = d % 10;
		res += d1 + d2;
	}
	else {
		res += d;
	}
	if (m > 10) {
		int m1 = m / 10;
		int m2 = m % 10;
		res += m1 + m2;
	}
	else {
		res += m;
	}
	return res;
}



int pers::all_sum_hex() {
	char s[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int ch = 0;
	char c = name[0][0];
	while (s[ch] != c) {
		ch++;
	}
	int result = 0;
	
	result = sum_diff_char() + sum_day_month() * 64 + 256 * (ch + 1);
	return result;
}

int main() {
	pers p;
	int N;
	cin >> N;
	vector<string> vcstr;
	vector<string> vchx;
	string arr;
	ostringstream hx;
	for (int u = 0; u < N; u++) {
		cin >> arr;
		vcstr.push_back(arr);
		p.fill(arr);
		hx << hex << p.all_sum_hex();
		vchx.push_back(hx.str());
		vchx[u].erase(vchx[u].begin(), vchx[u].end() - 3);
	}

	for (int i = 0; i < N; i++) {
		cout << vchx[i] << " ";
	}
	
	
	
	return 0;

}