#include <iostream>
using namespace std;
#include <vector>
#include <math.h>
vector<Schedule> masseuse_max_bookings(const vector<int> & appointments) {
    vector<Schedule> s;
    s.reserve(appointments.size());
    int prev = 0;
    for (const int i : appointments) {
        int acc_next = i + prev;
        s.emplace_back(prev, acc_next + 15);
        prev = acc_next;
    }
    vector<int> sol1 = interval_scheduling(s);
    vector<Schedule> sol2;
    for (int i : sol1) {
        sol2.push_back(s[i]);
    }
    return sol2;
}

int main()
{
    vector<int> bookings = { 30, 15, 60, 75, 45, 15, 15, 45 };
    vector<Schedule> sol = masseuse_max_bookings(bookings);
    int acc_sum = 0;
    for (auto i : sol) {
        acc_sum += i.weight - 15;
        cout << "(" << i.start << ", " << i.end << ")" << " -> " << acc_sum << endl;
    }
}
