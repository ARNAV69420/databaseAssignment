/*
        Who : arnav
        Roll :20CS01070
        When : 10:01:45 PM 
        On : Saturday 25 February 2023 
        Why : Because it is an assignment
        About : Lossless and Dependency Preserving Decomposition into 3NF
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
typedef pair<int,int> pi;
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
    int n,q; re(n);
    string per; re(per,q);
    V<string> depe(q); re(depe);
    V<string> canon;
    for(auto g:depe)
    {
        auto [LHS,RHS]=split(g);
        for(auto h:RHS) canon.pb(LHS+">"+h);
    }
    depe=canon; q=sz(depe);
    for(auto &g:depe)
    {
        auto [LHS,RHS]=split(g);
        auto H=LHS;
        for(auto h:H)
        {
            if(sz(LHS)==1) break;
            auto temp=g;
            string effLHS;
            for(auto k:LHS) if(k!=h) effLHS+=k;
            g=RHS+">"+RHS;
            auto res=clos(effLHS,depe);
            for(auto k:res) if(h==k) {LHS=effLHS; break; }
            g=LHS+">"+RHS;
        }
    }
    //dbg(depe);
    V<string> ans;
    for(auto &g:depe)
    {
        auto [LHS,RHS]=split(g);;
        auto temp=g;
        g=RHS+">"+RHS;
        auto res=clos(LHS,depe);
        auto f=0;
        for(auto h:res) if(h==RHS[0]) {f=1; break;}
        if(!f) {g=temp; ans.pb(g);} 
    }
    dbg(ans);
    set<string> s;
    int i=1;
    vector<set<char>> tables;
    for(auto g:ans) s.insert(split(g)[0]);
    for (auto k:s) 
    {
        dbg(k);
        auto [a,b]=split(k);
        tables.eb(all(a));
        for(auto g:ans) 
        {
            auto [c,d]=split(g);
            if(c==a) tables.back().insert(all(d));
        }
    }
    int flag=0;
    for(auto g:tables)
    {
        auto a=string(all(g));
        auto clo=clos(a,ans);
        if(clo==per) {flag=1; break;}
    }
    if(!flag)
    {
        set<pair<int,string>> sk;
        rep(b,0,(1<<n)) 
        {
            string subset;
            rep(i,0,n) if (b&(1<<i)) subset+=(per[i]);
            auto r=clos(subset,ans);
            if(r==per) sk.insert({sz(subset),subset});
        }
        tables.eb(all(sk.begin()->second));
    }
    dbg(tables);
    V<string> FINAL;
    V<int> isSubset(sz(tables),0);
    rep(i,0,sz(tables))
    {
        for(auto h:tables)
            if(!isSubset[i]&&h!=tables[i]&&includes(all(h),all(tables[i])))
            {
                isSubset[i]=1;
                break;
            }
        if(!isSubset[i])
        {
            FINAL.pb(string(all(tables[i])));
        }
    }
    int idx=1;
    for(auto g:FINAL) cout<<"R"<<idx++<<"("<<g<<")"<<endl;
}
int main()
{
	int t=1;
	//cin>>t;//comment this one out if single test case
	while(t-->0)
		solve();
	return 0;
}
