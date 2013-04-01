#include <iostream>

using namespace std;
int main()
{
    int lastday,lastmonth,lastyear;
    int day,month,year;
    bool c1,c2,c3;
    cout<<"Enter today's date in form MM DD YYYY\n";
    cin>>month>>day>>year;
    c1=(day>=1)&&(day<=31);
    c2=(month>=1)&&(month<=12);
    c3=(year>=1812)&&(year<=2013);
    if (!c1)
        cout<<"Value of day not in the range 1...31"<<"\n";
    if (!c2)
        cout<<"Value of month not in the range 1...12"<<"\n";
    if (!c3)
        cout<<"Value of year not in the range 1812...2013"<<"\n";
    do
    {
        switch(month)
        {
        case 5:
        case 7:
        case 10:
        case 12:
            if(day>1)
            {
                lastday=day-1;
                lastmonth=month;
                lastyear=year;
            }
            else
            {
                lastday=30;
                lastmonth=month-1;
                lastyear=year;
            }
            break;
        case 2:
        case 4:
        case 6:
        case 8:
        case 9:
        case 11:
            if(day>1)
            {
                lastday=day-1;
                lastmonth=month;
                lastyear=year;
            }
            else
            {
                lastday=31;
                lastmonth=month-1;
                lastyear=year;
            }
            break;
        case 3:
            if(day>1)
            {
                lastday=day-1;
                lastmonth=month;
                lastyear=year;
            }
            else
            {
                if((year%4==0&&year%100!=0)||year%400==0)
                {
                    lastday=29;
                    lastmonth=2;
                    lastyear=year;
                }
                else
                {
                    lastday=28;
                    lastmonth=2;
                    lastyear=year;
                }
            }
            break;
        case 1:
            if(day>1)
            {
                lastday=day-1;
                lastmonth=month;
                lastyear=year;
            }
            else
            {
                lastday=31;
                lastmonth=12;
                if(year!=1812)
                    lastyear=year-1;
                else cout<<"lastyear is not in range";
            }
            break;
        default:
            cout<<"error!";
        }
        if(c1&&c2&&c3)
            cout<<"the lastday is "<<lastmonth<<"  "<<lastday<<"  "<<lastyear<<"\n";
        return 0;
    }
    while(c1&&c2&&c3);

    return 0;
}
