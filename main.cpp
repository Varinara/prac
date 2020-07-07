#include <bits/stdc++.h>

using namespace std;

const int INF = int(1e9);

vector<vector<pair<int, int> > > g;
vector<int> ans;

int v;

int main() {
    freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    g.resize(n);
    int s, f;
    cin >> s >> f;

    s--, f--;

    while (cin >> v){
        int u, cost;
        cin >> u >> cost;
        u--, v--;
        g[v].push_back({u, cost});
    }
    vector<int> cost(n, INF),  p(n);
    cost[s] = 0;
    vector<bool> u (n, false);

    for (int i = 0; i < n; i++) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!u[j] && (v == -1 || cost[j] < cost[v]))
                v = j;
        if (cost[v] == INF)
            break;
        u[v] = true;

        for (int j = 0; j < g[v].size(); j++) {
            int to = g[v][j].first, cnt = g[v][j].second;
            if (cost[v] + cnt < cost[to]) {
                cost[to] = cost[v] + cnt;
                p[to] = v;
            }
        }
    }

    if (cost[f] == INF){
        cout << "Not way\n";
        return 0;
    }

    cout << cost[f] << endl;
    while(s != f){
        ans.push_back(f);
        f = p[f];
    }
    ans.push_back(s);
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] + 1 <<' ';
    cout << endl;
    return 0;
}