/*
        Who : arnav
        Roll : 20CS01070
        When : 11:47:56 PM 
        On : Tuesday 14 March 2023 
        Why : Because it is an assignment
        About : Lossless Decomposition into BCNF
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
array<string,2> split(string s)
{
    int flag=0;
    string LHS,RHS;
    for(auto h:s)
    {
        if(h=='>') {flag=1; continue;}
        if(!flag) LHS+=h;
        else RHS+=h;
    }
    return {LHS,RHS};
}
string clos(string s,V<string> v)
{
    set<int> se;
    for(auto a:s) se.insert(a);
    s="";
    for(auto g:se) s+=g;
    while(1)
    {
        string newX=s;
        for(auto g:v)
        {
            auto [LHS,RHS]=split(g);
            int flag=1;
            for(auto h:LHS)
                if(se.find(h)==se.end()) flag=0;
            if(flag) for(auto h:RHS) se.insert(h);
            newX="";
            for(auto h:se) newX+=h;
        }
        if(newX==s) break;
        s=newX;
    }
    return s;
}
void solve()
{
    int n,m;
    string all; re(n,all,m);
    V<string> v(m); re(v);
    bool isbcnf=0;
    int relation_No=1;
    set<char> intable;
    for(auto h:all) intable.insert(h);
    while(!isbcnf)
    {
        isbcnf=1;// assume it is 1 and test.. if its not then its set to 0
        for(auto g:v)
        {
            auto [LHS,RHS]=split(g);
            if(clos(LHS,v)!=all)
            {
                dbg(g);
                for(auto k:RHS) intable.erase(k);
                set<char> se;
                string table;
                for(auto h:g) if(h!='>') se.insert(h);
                for(auto h:se) table+=h;
                cout<<"R"<<relation_No<<"("<<table<<")"<<endl;
                dbg(table);
                relation_No++;
                vector<string> temp;
                all="";
                for(auto h:intable) all+=h;
                dbg(all);
                rep(i,1,(1<<sz(all)))
                {
                    string s;
                    string ans;
                    rep(j,0,sz(all)) if(i&(1<<j)) s+=all[j];
                    string right=clos(s,v);
                    se.clear();
                    se.insert(s.begin(),s.end());
                    for(auto k:right) if(se.find(k)==se.end()&&intable.find(k)!=intable.end()) ans+=k;
                    if(sz(ans)) temp.pb(s+">"+ans);
                }
                v=temp;
                dbg(v);
                isbcnf=0;
                break;
            }
        }
    }
    if(sz(all)) cout<<"R"<<relation_No<<"("<<all<<")"<<endl;
}
int main()
{
	int t=1;
	while(t-->0)
		solve();
	return 0;
}
