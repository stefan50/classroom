#include <iostream>

using namespace std;

class Time {
private:
    int hour;
    int minutes;
public:
    int get_hour() const {
        return hour;
    }

    int get_minutes() const {
        return minutes;
    } 

    void set_hour(int hour) {
        if(hour >= 0 && hour <= 23)
            this -> hour = hour;
        else 
            cout << "Not a valid hour" << endl;
    }

    void set_minutes(int minutes) {
        if(minutes >= 0 && minutes <= 59)
            this -> minutes = minutes;
        else 
            cout << "Minutes are not valid" << endl;
    }

    void normalize() {
        while(minutes >= 60) {
            hour++;
            minutes -= 60;
            while(hour >= 24) {
                hour -= 24;
            }
        }
        while(minutes < 0) {
            hour--;
            minutes += 60;
            while(hour < 0) {
                hour += 24;
            }
        }
    }

    void add_minutes(int minutes) {
        this -> minutes += minutes;
        normalize();
    }

    int all_minutes() const {
        return hour * 60 + minutes;
    }

    bool operator<(Time t) {
        if(hour == t.get_hour()) {
            return (minutes < t.get_minutes());
        }
        return (hour < t.get_hour());
    }

    Time operator+(Time t) {
        Time result;
        result.set_hour(0);
        result.set_minutes(0);
        result.add_minutes(all_minutes() + t.all_minutes());
        result.normalize();
        return result;
    }

    Time operator-(Time t) {
        Time result;
        result.set_hour(0);
        result.set_minutes(0);
        result.add_minutes(all_minutes() - t.all_minutes());
        result.normalize();
        return result;
    }

    Time operator*(Time t) {
        Time result;
        result.set_hour(0);
        result.set_minutes(0);
        result.add_minutes(all_minutes() * t.all_minutes());
        result.normalize();
        return result;
    }
 };

int main() {
    Time t1, t2;
    t1.set_hour(22);
    t1.set_minutes(5);
    t2.set_hour(23);
    t2.set_minutes(1);
    t1 = t1 * t2;

    cout << t1.get_hour() << ":" << t1.get_minutes() << endl;
    cout << (t1 < t2) << endl;
    return 0;
}