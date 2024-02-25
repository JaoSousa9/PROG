#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

void advance(int delta, int& d, int& m, int& y){
    //Base case
    int temp = d;
    if(delta <= 0) return;
    if(y%4==0){
        if(y%100==0 && y%400!=0){
            if(delta >= 365){
                y++;
                return advance(delta - 365, d, m, y);
            }else{
                if(delta + d > 31 && m==12){
                    d=1, m=1, y++;
                    return advance(delta -(31 - temp), d ,m, y);
                }else{
                    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
                        if(delta + d <= 31){
                            d += delta;
                        }else{
                            d=1, m++;
                            delta --;
                        }
                        return advance(delta -(31-temp),d,m,y);
                    }else{
                        if(m==2){
                            if(delta + d <= 28){
                                d += delta;
                            }else{
                                d=1, m++;
                                delta--;
                            }
                            return advance(delta -(28-temp),d,m,y);
                        }else{
                            if(delta + d <= 30){
                                d += delta;
                            }else{
                                d=1, m++;
                                delta--;
                            }
                            return advance(delta -(30-temp),d,m,y);
                        }
                    }
                }
            }  
        }else{
            if(delta >= 366){
                y++;
                return advance(delta - 366, d, m, y);
            }else{
                if(delta + d > 31 && m==12){
                    d=1, m=1, y++;
                    return advance(delta -(31 - temp), d ,m, y);
                }else{
                    if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
                        if(delta + d <= 31){
                            d += delta;
                        }else{
                            d=1, m++;
                            delta --;
                        }
                        return advance(delta -(31-temp),d,m,y);
                    }else{
                        if(m==2){
                            if(delta + d <= 29){
                                d += delta;
                            }else{
                                d=1, m++;
                                delta--;
                            }
                            return advance(delta -(29-temp),d,m,y);
                        }else{
                            if(delta + d <= 30){
                                d += delta;
                            }else{
                                d=1, m++;
                                delta--;
                            }
                            return advance(delta -(30-temp),d,m,y);
                        }
                    }
                }
            }
        }
    }else{
        if(delta >= 365){
            y++;
            return advance(delta - 365, d, m, y);
        }else{
            if(delta + d > 31 && m==12){
                d=1, m=1, y++;
                return advance(delta -(31 - d), d ,m, y);
            }else{
                if(m==1 || m==3 || m==5 || m==7 || m==8 || m==10 || m==12){
                    if(delta + d <= 31){
                        d += delta;
                    }else{
                        d=1, m++;
                        delta--;
                    }
                    return advance(delta -(31-temp),d,m,y);
                }else{
                    if(m==2){
                        if(delta + d <= 28){
                            d += delta;
                        }else{
                            d=1, m++;
                            delta--;
                        }
                        return advance(delta -(28-temp),d,m,y);
                    }else{
                        if(delta + d <= 30){
                            d += delta;
                        }else{
                            d=1, m++;
                            delta--;
                        }
                        return advance(delta -(30-temp),d,m,y);
                    }
                }
            }
        }
    }
}

int main(){

    int delta, d, m, y;
    cin >> delta >> d >> m >> y;
    advance(delta, d, m, y);
    cout << d << ' ' << m << ' ' << y;
    return 0;
}