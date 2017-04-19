#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
typedef pair<char, char> pcc;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<ull> vull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef tuple<int, int, int> tiii;
#define mod 1000000007LL
#define mx9 1000000000LL
#define mx10 10000000000LL
#define mx5 100000
#define mx8 100000000LL
#define mx7 10000000LL
#define mx6 1000000LL
#define mx6_5 5000000
#define last 4444444444
#define f first
#define s second
#define rep(i, a, b) for (ll i = (a); i <= (b); i++)
#define reprev(i, a, b) for (ll i = (a); i >= (b); i--)
#define repi(i, a, b) for (int i = (a); i <= (b); i++)
#define reprevi(i, a, b) for (int i = (a); i >= (b); i--)
#define mp make_pair
#define pb push_back
#define x first
#define y second
//#define PI 3.14159265
const long double PI = 2 * acos(0.0);
typedef vector<bool> vb;
void print(vb& a)
{
    for (bool i : a) {
        cout << i << " ";
    }
    cout << "\n";
}
void print(vi& a)
{
    for (int i : a) {
        cout << i << " ";
    }
    cout << "\n";
}
void print(vll& a)
{
    for (ll i : a) {
        cout << i << " ";
    }
    cout << "\n";
}
void print(vector<vi>& a)
{
    for (vi i : a) {
        print(i);
    }
    cout << "\n";
}
void print(vector<vll>& a)
{
    for (vll i : a) {
        print(i);
    }
    cout << "\n";
}
void print(vector<double>& a)
{
    for (double i : a) {
        cout << i << " ";
    }
    cout << "\n";
}
void print(vector<long double>& a)
{
    for (long double i : a) {
        cout << i << " ";
    }
    cout << "\n";
}
void print(vector<pll>& a)
{
    for (pll i : a) {
        cout << i.f << " " << i.s << "\n";
    }
    cout << "\n";
}
void print(deque<pll>& a)
{
    for (pll i : a) {
        cout << i.f << " " << i.s << "\n";
    }
    cout << "\n";
}
ll dist_sq(pll a, pll b)
{
    return ((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
ll po(ll a, ll b)
{
    if (b <= 0)
        return 1;
    else if (b == 1)
        return a;
    ll vl = po((a * a), b / 2);
    if (b % 2 == 0)
        return vl;
    else
        return (vl)*a;
}
ll pomod(ll a, ll b)
{
    a = a % mod;
    if (b <= 0)
        return 1 % mod;
    else if (b == 1)
        return a % mod;
    ll vl = pomod((a * a) % mod, b / 2);
    vl = vl % mod;
    if (b % 2 == 0)
        return vl;
    else
        return ((vl)*a) % mod;
}

ll pomod(ll a, ll b, ll mo)
{
    a = a % mo;
    if (b <= 0)
        return 1 % mo;
    else if (b == 1)
        return a % mo;
    ll vl = pomod((a * a) % mo, b / 2);
    vl = vl % mo;
    if (b % 2 == 0)
        return vl;
    else
        return ((vl)*a) % mo;
}

ll inv(ll a, ll mo)
{
    return pomod(a, mo - 2, mo);
}

ll floorlog2(ll n)
{
    ll h = 0;
    ll p = 1;
    while (p <= n) {
        h++;
        p *= 2;
    }
    return h - 1;
}
ll floorlog2(ll n, ll b)
{
    ll h = 0;
    ll p = 1;
    while (p <= n) {
        h++;
        p *= b;
    }
    return h - 1;
}

struct trie {
    ll occ = 0;
    trie* ch[2];
};
struct trie* new_trie()
{
    trie* root = new trie;
    root->occ = 1;
    root->ch[0] = NULL;
    root->ch[1] = NULL;
    return root;
}
ll bit_to_ll(const string& bits)
{
    int ln = bits.length();
    ll p = 1;
    ll ans = 0;
    reprev(i, ln - 1, 0)
    {
        if (bits[i] == '1') {
            ans += p;
        }
        p *= 2;
    }
    return ans;
}
string ll_to_bit(const ll& el)
{
    string ans = "";
    ll tmp = el;
    while (tmp != 0) {
        int d = tmp % 2;
        if (d) {
            ans = "1" + ans;
        }
        else {
            ans = "0" + ans;
        }
        tmp /= 2;
    }
    int ln = ans.length();
    while (ans.length() != 33) {
        ans = "0" + ans;
    }
    return ans;
}
void insert(trie* root, const ll& el)
{
    string str = ll_to_bit(el);
    int len = str.length();
    trie* temp = root;
    rep(i, 0, len - 1)
    {
        char c = str[i];
        if (c == '0') {
            if (temp->ch[0] == NULL) {
                temp->ch[0] = new_trie();
            }
            else {
                temp->ch[0]->occ++;
            }
            temp = temp->ch[0];
        }
        else {
            if (temp->ch[1] == NULL) {
                temp->ch[1] = new_trie();
            }
            else {
                temp->ch[1]->occ++;
            }
            temp = temp->ch[1];
        }
    }
}
void del(trie* root, const ll& el)
{
    string str = ll_to_bit(el);
    int len = str.length();
    trie* temp = root;
    rep(i, 0, len - 1)
    {
        char c = str[i];
        if (c == '0') {
            if (temp->ch[0] == NULL) {
                return;
            }
            else {
                temp->ch[0]->occ--;
            }
            temp = temp->ch[0];
        }
        else {
            if (temp->ch[1] == NULL) {
                return;
            }
            else {
                temp->ch[1]->occ--;
            }
            temp = temp->ch[1];
        }
    }
}
ll maxxor(trie* root, const ll& el)
{
    string str = ll_to_bit(el);
    int len = str.length();
    trie* temp = root;
    ll mx = el;
    string maxstring = "";
    rep(i, 0, len - 1)
    {
        char c = str[i];
        if (c == '0') {
            if (temp->ch[1] == NULL || temp->ch[1]->occ == 0) {
                maxstring = maxstring + "0";
                temp = temp->ch[0];
            }
            else {
                maxstring = maxstring + "1";
                temp = temp->ch[1];
            }
        }
        else {
            if (temp->ch[0] == NULL || temp->ch[0]->occ == 0) {
                maxstring = maxstring + "0";
                temp = temp->ch[1];
            }
            else {
                maxstring = maxstring + "1";
                temp = temp->ch[0];
            }
        }
        // cout<<maxstring<<"\n";
    }
    return bit_to_ll(maxstring);
}

void del_trie(trie* root)
{
    if (root->ch[1] != NULL) {
        del_trie(root->ch[1]);
    }
    if (root->ch[0] != NULL) {
        del_trie(root->ch[0]);
    }
    delete root;
}

vb seen(mx5 + 5, false);
vll len(mx5 + 5, mx10);
vector<pair<ll, ll> > adj[mx5 + 5];
vll dist(mx5 + 5, mx10);
vll par(mx5 + 5, 0);
void bfs(int src)
{
    seen[src] = true;
    len[src] = 0;
    queue<int> q;
    q.push(src);
    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (pll p : adj[node]) {
            int v = p.first;
            if (!seen[v]) {
                seen[v] = true;
                len[v] = len[node] + 1;
                q.push(v);
            }
        }
    }
}

void reset()
{
    rep(i, 1, mx5)
    {
        seen[i] = false;
    }
}

int arr[100005];

void dijkstra(int src)
{
    multiset<pair<pair<int, int>, int> > Q;
    pair<pair<int, int>, int> p;
    //p.first.first;
    //p.first.second;
    //p.second;
    Q.insert(make_pair(make_pair(0, arr[src]), src));
    dist[src] = 0;
    while (!Q.empty()) {
        pair<pair<int, int>, int> front = *(Q.begin());
        Q.erase(Q.begin());
        int node = front.second;
        int dst = front.first.first;
        //ll ln = front.first.second;
        if (seen[node])
            continue;
        seen[node] = true;
        dist[node] = dst;
        //par[node]=front.second.first;
        //len[node]=ln;
        cout << node << " " << dist[node] << "\n";
        int sz = adj[node].size();
        for (int i = 0; i < sz; i++) {
            pair<int, int> p = adj[node][i];
        }
        for (pair<int, int> p : adj[node]) {
            int v = p.first;
            int w = p.second;
            if (!seen[v]) {
                //len[v]= len[node]+1;
                Q.insert(make_pair(make_pair(dst + w, arr[v]), v));
            }
        }
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int a, b, d;
        cin >> a >> b >> d;
        adj[a].push_back(make_pair(b, d));
    }
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    // bfs(1);
    reset();
    dijkstra(1);
    rep(i, 1, 4)
    {
        cout << dist[i] << " ";
        cout << "\n";
    }
    return 0;
}
