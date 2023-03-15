/*
        Who : arnav
        Roll : 20CS01070
        When : 08:58:51 PM 
        On : Saturday 25 February 2023 
        Why : Because it is an assignment
        About: Testing Lossless Join Criterion of the Decomposition
*/
#ifdef LOCAL
	#include "/home/arnav/c++/new_folder_env/pch/stdc++.h"
#else
	#include <bits/stdc++.h>
	#define dbg(...) 0
	#define chk(...) 0
#endif
using namespace std;
#define rep(i,j,n) for(int i=j;i<n;++i)
#define dep(i,j,n) for(int i=j;i>=n;--i)
#define tcT template<class T
#define tcTU tcT, class U
#define tcTUU tcT, class ...U
typedef long long ll;
typedef vector<vector<int>> vvi;
typedef vector<int> vi;
#define V vector
#define endl "\n"  
#define pb push_back
#define popb pop_back
#define eb emplace_back
#define all(x) x.begin(),x.end()
#define sz(x) int((x).size())
const int MOD=1e9+7;
mt19937 rng(0);
tcT> void re(T& x) { cin >> x; }
void re(double& d) { string t; re(t); d = stod(t); }
void re(long double& d) { string t; re(t); d = stold(t); }
tcTUU> void re(T& t, U&... u) { re(t); re(u...); }
tcT> void re(complex<T>& c) { T a,b; re(a,b); c = {a,b}; }
tcTU> void re(pair<T,U>& p) { re(p.first,p.second); }
tcT> void re(vector<T>& x) { for(auto &a:x) re(a); }
tcT, size_t SZ> void re(array<T,SZ>& x) { for(auto &a:x) re(a); }
string A(int j)
{
    return "a"+to_string(j);
}
string B(int i,int j)
{
    return "b"+to_string(i)+to_string(j);
}
string res(int i, V<int> idx,V<V<string>> &M)
{
    string ans;
    for(auto g:idx) ans+=M[i][g];
    return ans;
}
void solve()
{
    int q,n,m; re(n,m);
    V<string> depe(m); re(depe); re(q);
    V<string> v(q); re(v);
    V<V<string>> M(q,V<string>(n));
    for(int i=0;i<q;i++) for(int j=0;j<n;j++) M[i][j]=B(i,j);
    for(int i=0;i<q;i++) for(auto g:v[i]) M[i][g-'A']=A(g-'A');
    dbg(M);
    int flag=1;
    while(flag)
    {
        flag=0;
        for(auto g:depe)
        {
            int f=0;
            string LHS,RHS;
            for(auto h:g)
            {
                if(h=='>') {f^=1; continue;}
                if(!f) LHS+=h;
                else RHS+=h;
            }// breaking the functional dependency into lhs and rhs
            V<int> idx;
            for(auto h:LHS) idx.pb(h-'A');//finding the column indices that need to match
            rep(i,0,q)
            {
                string comp=res(i,idx,M);
                V<int> idx2;
                rep(j,i,q)
                    if(res(j,idx,M)==comp) idx2.pb(j);
                for(auto h:RHS)
                {
                    int deeznuts=h-'A';
                    string s;
                    for(auto k:idx2)
                    {
                        s=M[k][deeznuts];
                        if(s[0]=='a') break;
                    }
                    for(auto k:idx2)
                    {
                        if(s!=M[k][deeznuts]) flag=1;
                        M[k][deeznuts]=s;
                    }
                }
            }
        }
    }
    rep(i,0,q)
    {
        flag=1;
        rep(j,0,n)
            if(M[i][j][0]!='a') flag=0;
        if(flag)
        {
            cout<<"The above decomposition satisfies lossless join property\n";
            return;
        }
    }
    cout<<"The above decomposition does not satisfy lossless join property\n";
    dbg(M);
}
int main()
{
	int t=1;
	while(t-->0)
		solve();
	return 0;
}
/* INT->LL remember 'mark the sweeper' whenever you return any sum of multiple numbers
possibly the entire array, then take care to define int as long long, that has to be the saddest mistake ever*/
