#include <iostream>

#define MINUTES_PER_HOUR 60
#define MAX_ONE_DIGIT_NUMBER 9

using namespace std;

struct Time {
    int hours;
    int minutes;
    Time& operator+(Time& other);
    friend ostream& operator<<(ostream& ostream, Time& time);
    friend istream& operator>>(istream& istream, Time& time);
};

Time& Time::operator+(Time& other) {
    int addittionalHours = 0;
    int sumMinutes = this->minutes + other.minutes;
    
    if (sumMinutes > MINUTES_PER_HOUR) {
        addittionalHours = (int) (sumMinutes / MINUTES_PER_HOUR);
        this->minutes = sumMinutes % MINUTES_PER_HOUR;
        this->hours += addittionalHours;
    } else {
        this->minutes = sumMinutes;
    }

    return *this;
}

ostream& operator<<(ostream& ostream, Time& time) {
    ostream << time.hours << ':';
    if (time.minutes < MAX_ONE_DIGIT_NUMBER) ostream << '0';
    ostream << time.minutes;
    return ostream;  
}

istream& operator>>(istream& istream, Time& time) {
    istream >> time.hours >> time.minutes;
    return istream;
}

int main() {
    Time currentTime = {0, 0}, auxTime = {0, 0};

    cout << "Current Time: ";
    cin >> currentTime;
    cout << "Current Time: " << currentTime << endl;

    while (true) {
        cout << "Time to add: ";
        cin >> auxTime;

        currentTime = currentTime + auxTime;
        cout << "Current Time: " << currentTime << endl;
    }

    return 0;
}