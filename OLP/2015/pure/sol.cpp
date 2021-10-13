#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

ifstream fi("E:\\Test\\PURE\\Test07\\PURE.INP");
//ofstream fo("E:\\Test\\PURE\\Test07\\PURE.INP");
int m, vTri = 0, tmp = 0;
int vTri_tmp;
string s,st, stmp, stmp1;
char ch;

int main() {
	fi >> m;
	fi >> s;
	ch = s[0];
	vTri = s.find(ch, vTri + 1);
	while (vTri < m) {
		st = s.substr(0, vTri);
		vTri_tmp = vTri;
		while (vTri_tmp < s.length()) {
			if (s.length() - vTri_tmp <= st.length()) {
				stmp = s.substr(vTri_tmp, s.length() - vTri_tmp);
				stmp1 = st.substr(0, s.length() - vTri_tmp);
				if (stmp == stmp1) {
					cout << st << endl;
					return 0;
				}
			}
			stmp = s.substr(vTri_tmp, st.length());
			if (stmp == st)
				vTri_tmp += st.length();
			else
				break;
		}
		vTri = s.find(ch, vTri + 1);
	}
	cout << "NO" << endl;
	return 0;
}