#include<iostream>
#include<cstring>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

const int MAXN = 10003;

int f[MAXN];

struct Node {
	int id, fid, mid, num, area;
	int cid[6];
} a[MAXN];

struct Recoder {
	int id, people;
	double num, area;
	bool flag;
} b[MAXN];

int book[MAXN] = {0};

int getf(int x) {
	while(x != f[x]) {
		x = f[x];
	}
	return x;
}

void merge(int x, int y) {
	int t1 = getf(x);
	int t2 = getf(y);
	if (t1 > t2) {
		f[t1] = t2;
	} else {
		f[t2] = t1;
	}
}

int cnt = 0;
int cmp(Recoder x, Recoder y) {
	if (x.area != y.area) {
		return x.area > y.area;
	} else{
		return x.id < y.id;
	}
}

int main() {
	int n, k;
	cin >> n;

	for (int i = 0; i < MAXN; i++){
		f[i] = i;
	}

	for (int i = 0; i < n; i++) {
		cin >> a[i].id >> a[i].fid >> a[i].mid >> k;
		book[a[i].id] = 1;

		if (a[i].fid != -1) {
			book[a[i].fid] = 1;
			merge(a[i].fid, a[i].id);
		}

		if (a[i].mid != -1) {
			book[a[i].mid] = 1;
			merge(a[i].mid, a[i].id);
		}

		for (int j = 0; j < k; j++) {
			cin >> a[i].cid[j];
			book[a[i].cid[j]] = 1;
			merge(a[i].cid[j], a[i].id);
		}

		cin >> a[i].num >> a[i].area;
	}

	for (int i = 0; i < n; i++) {
		int id = getf(f[a[i].id]);
		b[id].id = id;
		b[id].num += a[i].num;
		b[id].area += a[i].area;
		b[id].flag = 1;
	}

	for (int i = 0; i < 10000; i++) {
		if (book[i]) {
			b[getf(i)].people++;
		}
		if (b[i].flag) {
			cnt++;
		}
	}

	for (int i = 0; i < 10000; i++) {
		if(b[i].flag) {
			b[i].num = (double)(b[i].num * 1.0 / b[i].people);
			b[i].area = (double)(b[i].area * 1.0 / b[i].people);
		}
	}

	sort(b, b + 10000, cmp);
	
    cout << cnt << endl;
	
    for(int i = 0; i < cnt; i++){
		printf("%04d %d %.3f %.3f\n", b[i].id, b[i].people, b[i].num, b[i].area);
	}
	
    return 0;
} 