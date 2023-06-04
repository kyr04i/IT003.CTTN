#include<bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e5 + 7;
int root[N];

int FindRoot(int u) {
    if (u == root[u]) {
        return u;
    }
    return root[u] = FindRoot(root[u]);
}

void UnionSet(int u, int v) {
    int rootu = FindRoot(u);
    int rootv = FindRoot(v);
    if (rootu != rootv) {
        root[rootu] = rootv;
    }
}

struct krus {
    int w, u, v;
};

bool cmp(krus a, krus b) {
    return a.w <= b.w;
}

void solve() {
    ifstream input("Graph.TXT");
    ofstream output("Kruskal.TXT");

    int n, m;
    input >> n;
    m = n * n;

    for (int i = 1; i <= m; ++i) {
        root[i] = i;
    }

    vector<krus> a(m);
    int index = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            int w;
            input >> w;
            if (j > i) {
                a[index] = {w, i, j};
                index++;
            }
        }
    }

    sort(a.begin(), a.end(), cmp);

    int res = 0;
    for (auto c : a) {
        if (FindRoot(c.u) != FindRoot(c.v)) {
            res += c.w;
            UnionSet(c.u, c.v);
        }
    }

    double roundedRes = round(res * 100.0) / 100.0;
    output << fixed << setprecision(2) << roundedRes;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}
