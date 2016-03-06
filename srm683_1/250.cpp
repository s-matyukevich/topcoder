#include <stdlib.h>
#include <vector>

using namespace std;


class MoveStones {
	public:
		long long get(vector<int>, vector<int>);
};

long long MoveStones::get(vector<int> a, vector<int> b) {
	long long res = 1e18;
	int n = a.size();
	for (int rot = 0; rot < n; rot++){
		long long sum, res1 = 0;
		for (int i = rot; i < rot + n; i++){
			int k = i % n;
			sum += a[k] - b[k];
			res1 += sum > 0 ? sum : -sum; 
		}
		if (sum != 0) {
			return -1;
		}
		res = min(res, res1);
	}
	return res;
}
