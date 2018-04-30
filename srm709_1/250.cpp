#include <stdlib.h>
#include <vector>

using namespace std;


class Xscoregame {
	public:
	int getscore(vector <int> A){
		return rec(A, 0, 0);
	}

	private:
	int rec(vector <int> a, int cur, int pos){
		int n = a.size();
		if (pos == n) {
			return cur;
		}
		int x = a[pos];
		int res = 0;
		for (int i = pos; i < n; i++){
			a[pos] = a[i];
			a[i] = x;
			int r = rec(a, cur + (cur ^ a[pos]), pos + 1);
			a[i] = a[pos];
			a[pos] = x;
			if (r > res) {
				res = r;
			}
		}
		return res;
	}
};

