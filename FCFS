#include <bits/stdc++.h>
#include <string.h>

using namespace std;

class Process {

public:
    string p_name;
    int at, bt, wt, tat, ct;
    Process() {
        at = bt = wt = tat = ct = 0;
        p_name = "p";
    }
    void print() {
        cout<<p_name<<"\t"<<at<<"\t"<<bt<<"\t"<<ct<<"\t"<<tat<<"\t"<<wt<<endl;
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


class cmp_by_name {
public:
    bool operator()(const Process &a, const Process &b) {
        return a.p_name < b.p_name;
    }
};

void FCFS(Process p[], int n) {
    sort(p, p + n, cmp());

    int cur_time = 0;

    for(int i = 0; i < n; i++) {
        if(cur_time < p[i].at) cur_time = p[i].at;
        cur_time += p[i].bt;

        p[i].ct = cur_time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;
    }
}

int main()
{
    freopen("input.txt", "r", stdin);

    int n;
    cin>>n;
    Process p[n];
    for(int i = 0; i < n; i++) {
        p[i].input(i + 1);
    }

    FCFS(p, n);

    sort(p, p + n, cmp_by_name());

    printf("p\tat\tbt\tct\ttat\twt\n");
    for(int i = 0; i < n; i++) {
        p[i].print();
    }

    return 0;
}
/*
5
2 2
0 1
2 3
3 5
4 4
*/
