#include <bits/stdc++.h>
#include <string.h>

using namespace std;

class Process {

public:
    string p_name;
    int at, bt, wt, tat;
    Process() {
        at = bt = wt = tat = 0;
        p_name = "p";
    }
    void print() {
        cout<<p_name<<" "<<at<<" "<<bt<<" "<<wt<<" "<<tat<<endl;
    }
    void input(int p_no) {
        p_name.push_back(p_no + '0');
        cin>>at>>bt;
    }
};

class cmp {
public:
    bool operator()(const Process &a, const Process &b) {
        return a.at < b.at;
    }
};

int main()
{

    int n;
    cin>>n;
    Process p[n];
    priority_queue<Process, vector<Process>, cmp> pq;
   
    for(int i = 0; i < n; i++) {

        p[i].input(i + 1);
    }

    sort(p, p + n, cmp());

    for(int i = 0; i < n; i++) {
        p[i].print();
    }

    return 0;
}
