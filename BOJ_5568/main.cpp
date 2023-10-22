#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

int n, k;
vs cards;
set<string> ans;

vb isSelected;
vs selected;
void solve() {
	if (k == selected.size()) {
		auto newStr = string{};
		for (const auto& x : selected) {
			newStr += x;
		}

		ans.insert(newStr);
		return;
	}

	for (auto i = 0; i < n; ++i) {
		if (isSelected[i]) {
			continue;
		}

		selected.push_back(cards[i]);
		isSelected[i] = true;
		solve();
		selected.pop_back();
		isSelected[i] = false;
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> k;
	cards = vs(n);
	for (auto&& x : cards) {
		cin >> x;
	}

	isSelected = vb(n, false);
	selected = vs{};
	solve();

	cout << ans.size();

	return 0;
}