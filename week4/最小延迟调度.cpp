#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_SIZE = 100;

struct Request {
	int begin, end;
} req[MAX_SIZE];


bool cmp(Request A,Requuest B) {
	return A.end < B.end;
}

int main() {
	int requestNum;
	cin >> requestNum;
	if (requestNum > MAX_SIZE) {
		cout << "请求数量过多" << endl;
		return 0;
	}
	for (int i = 0; i < requestNum; ++i) {
		cin >> req[i].begin >> req[i].end;
	}

	sort(req, req + requestNum,cmp);

	vector<Request> rvec;
	rvec.push_back(req[0]);
	
	for (int i = 1; i < requestNum; ++i) {
		if (rvec[rvec.size() - 1].end <= req[i].begin) {
			rvec.push_back(req[i]);
		}
	}

	cout << "最大兼容量: " << rvec.size() << endl;
	return 0;
}
