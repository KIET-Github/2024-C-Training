#include<bits/stdc++.h>
using namespace std;

typedef long long int     ll;

void file_i_o() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}

bool cmp(pair<int, int> &a, pair<int, int> &b) {
    if (a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

int bs(vector<pair<int, int>> &v, int &i, int &d) {
    int l = i, h = v.size() - 1, m;

    while (l <= h) {
        m = l + ((h - l) >> 1);

        if (v[i].first + d > v[m].first) {
            if (m == v.size() - 1 || v[m + 1].first >= v[i].first + d) return m;
            l = m + 1;
        }
        else h = m - 1;
    }

    return i;
}

int main ()
{
    file_i_o();

    int n, d;
    cin >> n >> d;

    vector<pair<int, int>> v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    vector<ll> pre(n);
    pre[0] = v[0].second;

    for (int i = 1; i < n; i++) {
        pre[i] = pre[i - 1] + (ll)v[i].second;
    }

    int tmp, j;
    ll ans = 0;

    for (int i = 0; i < n; i++) {
        j = bs(v, i, d);

        if (i == 0) ans = max(ans, pre[j]);
        else ans = max(ans, pre[j] - pre[i - 1]);
    }

    cout << ans;

    return 0;
}