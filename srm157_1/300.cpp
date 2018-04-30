#include <stdlib.h>
#include <vector>
#include <tuple>

using namespace std;

class Salary {
	public:
	int howMuch(vector <string> arrival, vector <string> departure, int wage){
		vector <tuple<int,int,double>> overtime = {
			make_tuple(0, 6 * 3600, (double)wage * 1.5), 
			make_tuple(6 * 3600, 18 * 3600, (double)wage), 
			make_tuple(18 * 3600, 24 * 3600, (double)wage * 1.5)
		};
		double res = 0;
		for (size_t i = 0; i < arrival.size(); i++) {
			string at = arrival[i];
			string dt = departure[i];
			int arrivalTime = stoi(at.substr(0, 2)) * 3600 + stoi(at.substr(3, 2)) * 60 + stoi(at.substr(6, 2));
			int departureTime = stoi(dt.substr(0, 2)) * 3600 + stoi(dt.substr(3, 2)) * 60 + stoi(dt.substr(6, 2));

			printf("AT: %d, DT: %d\n", arrivalTime, departureTime);

			for (size_t j = 0; j < overtime.size(); j++) {
				int start = get<0>(overtime[j]);
				int finish = get<1>(overtime[j]);
				double wage = get<2>(overtime[j]);
				printf("Start: %d, finish: %d, wage: %f\n", start, finish, wage);
				if (start > departureTime || finish <= arrivalTime) {
					continue;
				}
				double delta = (min(departureTime, finish) - max(arrivalTime, start)) * wage;
				printf("Delta: %f\n", delta);
				res += delta;
			}
		}
		return (int)res/3600;
	}
};
