// graf.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int N, a = 0, b, k = 0;
	cout << "Enter amount of verices" << endl;
	cin >> N;
	vector<int> vec(N, 0);

	while (a != -1) {
		cin >> a;
		if (a == -1)
			break;
		cin >> b;
		a -= 1;
		b -= 1;
		if ((vec[a] == 0) && (vec[b] == 0)) {
			k += 1;
			vec[a] = k;
			vec[b] = k;
		}
		else if ((vec[a] != 0) && (vec[b] == 0)) {
			vec[b] = vec[a];
		}
		else if ((vec[a] == 0) && (vec[b] != 0)) {
			vec[a] = vec[b];
		}
		else if ((vec[a] != 0) && (vec[b] != 0) && (vec[a] != vec[b])) {
			int t = vec[b];
			for (int i = 0; i < N; i++) {
				if (vec[i] == t) {
					vec[i] = vec[a];
				}
			}
			vec[b] = vec[a];

		}
	}
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i] == 0) {
			k += 1;
			vec[i] = k;
		}
	}

	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	cout << vec.size() - 1;
	return 0;

}