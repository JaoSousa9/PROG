#ifndef __interval_h__
#define __interval_h__

struct time_of_day {
  unsigned char h; // Hours [0,23]
  unsigned char m; // Minutes [0,59]
};

struct interval {
  time_of_day start; // Start time
  time_of_day end;   // End time
};

void initInterval(struct interval *it, time_of_day start, time_of_day end) {
    it -> start = start;
    it -> end = end;
}

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

#endif // __interval_h__

interval intersection(interval a, interval b){
    interval commonInterval =  {{0,0},{0,0}};

    time_of_day s, e;
    if(a.start.h == b.start.h){
        s = {a.start.h, max(a.start.m,b.start.m)};
    }else{
        if(max(a.start.h, b.start.h) == a.start.h){
            s = {a.start.h,a.start.m};    
        }else{
            s= {b.start.h, b.start.m};
        }
    }

    if(a.end.h == b.end.h){
        e = {a.end.h, min(a.end.m,b.end.m)};
    }else{
        if(min(a.end.h, b.end.h) == a.end.h){
            e = {a.end.h,a.end.m};    
        }else{
            e = {b.end.h, b.end.m};
        }
    }

    if(s.h == e.h){
        if(s.m < e.m){
            initInterval(&commonInterval, s,e);
        }
    }else if(s.h < e.h){
        initInterval(&commonInterval, s,e);
    }

    
    return commonInterval;
}

int main(){

    time_of_day t1{4 ,30};
    time_of_day t2{7, 59};
    time_of_day t3{4, 0};
    time_of_day t4{7, 29};

    interval i1{t1,t2};
    interval i2{t3,t4};

    interval result = intersection(i1,i2);

    cout << result;
    return 0;
}