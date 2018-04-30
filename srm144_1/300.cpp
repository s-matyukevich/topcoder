#include <stdlib.h>
#include <vector>
#include <string>

using namespace std;

class BinaryCode {
	public:
	vector <string> decode(string message){
		return vector<string> { decode(0, message), decode(1, message)};
	}

	private:
	string decode(int digit, string message) {
		string res = to_string(digit);
		int pPrev = 0;
		int pCur = digit;
		int pNext = 0;
		for (unsigned int i = 0; i < message.size() - 1; i++) {
			// q[i] = p[i-1] + p[i] + p[i + 1]
			int q = message[i] - '0'; 
			pNext = q - pCur - pPrev;
			if (pNext < 0) {
				return "NONE";
			}
			res += to_string(pNext);
			pPrev = pCur;
			pCur = pNext;
		}
		int last = message[message.size() - 1] - '0';
		if (last != pCur + pPrev) {
			return "NONE";
		}
		return res;
	}
};
