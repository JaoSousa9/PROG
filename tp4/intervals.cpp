#ifndef __intervals_h__
#define __intervals_h__

struct time_of_day {
  unsigned char h; // Hours [0,23]
  unsigned char m; // Minutes [0,59]
};

struct interval {
  time_of_day start; // Start time
  time_of_day end;   // End time
};

#include <iostream>
using namespace std;

ostream& operator<<(ostream& out, time_of_day t) {
  if (t.h < 10) out << '0';
  out << (int) t.h << ':';
  if (t.m < 10) out << '0';
  out << (int) t.m;
  return out;
}

ostream& operator<<(ostream& out, interval il) {
  return out << '[' << il.start << ',' << il.end << '[';
}

#endif // __intervals_h__

int search_intervals(time_of_day t, const interval a[], int n, interval& u){

    u.start.h = t.h;
    u.start.m = t.m;
    u.end.h = t.h;
    u.end.m = t.m;

    int t_min = t.h*60 + t.m;

    int u_start_min = u.start.h*60 + u.start.m;
    int u_end_min = u.end.h*60 + u.end.m;

    for(int i = 0; i< n; i++){
        int a_start_min = a[i].start.h*60 + a[i].start.m;
        int a_end_min = a[i].end.h*60 + a[i].end.m;
        if(t_min >= a_start_min && t_min < a_end_min){
            if(a_start_min < u_start_min){
                u.start = a[i].start;
            }
            if(a_end_min > u_end_min){
                u.end = a[i].end;
            }
            u_start_min = u.start.h*60 + u.start.m;
            u_end_min = u.end.h*60 + u.end.m;
        }
    }

    return u_end_min - u_start_min;

}

int main(){

    const int n = 5;
    const time_of_day t = { 15, 15 };
    const interval a[n] { { { 12, 30 }, { 14, 30 } }, 
                  { { 14, 30 }, { 15, 30 } }, 
                  { { 15, 10 }, { 16, 10 } }, 
                  { {  9, 30 }, { 15, 15 } }, 
                  { {  9, 45 }, { 15, 16 } } };
    interval u;
    int d = search_intervals(t, a, n, u);
    cout << d << ' ' << u << '\n';

    return 0;
}