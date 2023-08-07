#include <iostream>
using namespace std;
#include <vector>
class Line {
public:
    Line(double length, double freq_a, double freq_b) {
        // edge cases, (vertical or horizontal lines)
        // then there is only 1 valid point
        // vertical
        bool flag = true;
        if (freq_b == 0) {
            valid_points.push_back({ { int(length / freq_a) },{ 0 } });
            flag = false;
        }
        // horizontal
        if (freq_a == 0) {
            valid_points.push_back({ { 0 },{ int(length / freq_b) } });
            flag = false;
        }

        if (flag) {
            // solving for b
            y_int = length / freq_b;
            slope = freq_a / freq_b;

            // finding zeros 0 = l - Aa / B simplifies to
            zero_a = length / freq_a;
            zero_b = length / freq_b;

            // defining all valid points - using floor ensures a non negative number
            for (double i = 1; i < zero_a; i++) {
                // b = l - Aa / B
                double y = length / freq_b - (freq_a * i) / freq_b;
                // check for whole number
                if (y == int(y)) {
                    valid_points.push_back({ { int(i) },{ int(y) } });
                }
            }
        }

    }


    vector<pair<int, int>> valid_points;

private:
    float y_int, slope;
    double zero_a, zero_b;
};


bool check_if_valid_point(pair<int, int> &point, string pattern, string value) {
    string interp_a = "";
    string interp_b = "";
    string last_a, last_b;
    int count = 0;

    for (int i = 0; i < pattern.length(); i++) {
        if (pattern.at(i) == 'a') {
            for (int i = 0; i < point.first; i++) {
                interp_a += value.at(count++);
            }
            if (!last_a.empty() && last_a != interp_a) {
                return false;
            }
            last_a = interp_a;
            interp_a = "";
        }
        else {
            for (int i = 0; i < point.second; i++) {
                interp_b += value.at(count++);
            }
            if (!last_b.empty() && last_b != interp_b) {
                return false;
            }
            last_b = interp_b;
            interp_b = "";
        }
    }
    return true;
}

bool pattern_match(string pattern, string value) {
    // pattern cannot exceed value
    if (pattern.empty() || value.empty() || 
        pattern.size() > value.size()) return false;

    // a and b are ambigious and value is not empty
    else if (pattern.length() == 1) return true;

    // algorithm:
    // 1) Find frequencies of a and b
    double freq_a = 0, freq_b = 0;
    double length = value.length();
    for (auto i : pattern) {
        if (i == 'a') freq_a++;
        else if (i == 'b') freq_b++;
    }

    // 2) Define the line and check for valid points
    Line line(value.length(), freq_a, freq_b);
    vector<pair<int, int>> points = line.valid_points;
    for (auto &i : points) {
        if (check_if_valid_point(i, pattern, value)) {
            return true;
        }
    }
    return false;
}


int main() {
    cout << boolalpha << pattern_match("aabaa", "catcatgocatcat") << endl;
    cout << boolalpha << pattern_match("bbabb", "catcatgocatcat") << endl;
    cout << boolalpha << pattern_match("aba", "catgocat") << endl;
    cout << boolalpha << pattern_match("aab", "catcatgo") << endl;
    cout << boolalpha << pattern_match("bbaba", "dandandavdandav") << endl;
    cout << boolalpha << pattern_match("aaa", "catcatcat") << endl;

    cout << boolalpha << pattern_match("aabba", "catcatgocatcat") << endl;
    cout << boolalpha << pattern_match("baabb", "catcatgocatcat") << endl;
    cout << boolalpha << pattern_match("abb", "catgocat") << endl;
    cout << boolalpha << pattern_match("abb", "catcatgo") << endl;
    cout << boolalpha << pattern_match("bbb", "catcatgo") << endl;
}
