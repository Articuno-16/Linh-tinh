#include <iostream>
#include <sstream>

using namespace std;

class Time
{
private: 
    int hour;
    int minute;
    int second;
public:
    Time(int hour, int minute, int second){
        setTime(hour, minute, second);
    }
    
    void setTime(int hour, int minute, int second){
        this->setHour(hour);
        this->setMinute(minute);
        this->setSecond(second);
    }
    void setHour(int hour){
        this->hour = hour;
    }    
    void setMinute(int minute){
        this->minute = minute;
    }
    void setSecond(int second){
        this->second = second;
    }

    int getHour(){
        return hour;
    }    
    int getMinute(){
        return minute;
    }
    int getSecond(){
        return second;
    }
    
    void nextSecond(){
        if(second == 59)
        {
            second = 0;
            if(minute == 59)
            {
                minute = 0;
                if (hour == 23)
                {
                    hour = 0;
                }
                else hour+=1;
            }
            else minute+=1; 
        }
        else second+=1;
    }
    
    void previousSecond(){
        if(second == 0)
        {
            second = 59;
            if(minute == 0)
            {
                minute = 59;
                if (hour == 0)
                {
                    hour = 23;
                }
                else hour-=1;
            }
            else minute-=1; 
        }
        else second-=1;    
    }
    
    void display(){
        string s_hour = to_string(this->hour);
        string s_minute = to_string(this->minute);
        string s_second = to_string(this->second);
        if (s_second.length() == 1) s_second = "0" + s_second;
        if (s_hour.length() == 1) s_hour = "0" + s_hour;
        if (s_minute.length() == 1) s_minute = "0" + s_minute;
        //printf("%s:%s:%s",s_hour,s_minute,s_second);
        cout << s_hour << ":" << s_minute << ":" << s_second << endl;
    }
};

int main() {
	Time t(12, 1, 1);
	t.display();
	t.setTime(23, 59, 59);
	t.display();
	t.nextSecond();
	t.display();
	t.nextSecond();
	t.display();
	t.setTime(7, 0, 0);
	t.display();
	t.previousSecond();
	t.display();
	return 0;
}
