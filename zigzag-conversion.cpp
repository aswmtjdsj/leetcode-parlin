class Solution {
	public:
		string convert(string s, int nRows) {
			if(nRows == 1) return s;
			vector < string > refactor;
			refactor.resize(nRows);

			int l = s.size();
			int prev = -1, cur = 0;
			for(int i = 0; i < l; i++) {
				refactor[cur].push_back(s[i]);
				if(cur > prev) {
					prev = cur;
					cur++;
					if(cur >= nRows) {
						cur-= 2;
						prev = cur + 1;
					}
				}
				else {
					prev = cur;
					cur--;
					if(cur < 0) {
						cur += 2;
						prev = cur - 1;
					}
				}
			}
			string a = "";
			for(int i = 0; i < nRows; i++) {
				a += refactor[i];
				// a += "/";
			}
			return a;
		}
};
