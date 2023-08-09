#include <iostream>
using namespace std;
#include <math.h>
class Line {
public:
    Line(pair<float, float> p1, pair<float, float> p2) {
        this->p1 = p1;
        this->p2 = p2;
        line = defineLine(p1, p2);
    }

    static string defineLine(pair<float, float> p1, pair<float, float> p2);
    string line;

private:
    pair<float, float> p1, p2;

    static float getSlope(pair<float, float> p1, pair<float, float> p2);
    static float getY_int(pair<float, float> p1, float slope);
};

float round_down_2(float flt) {
    return floorf(flt * 100) / 100;
}

float Line::getSlope(pair<float, float> p1, pair<float, float> p2) {
    return (round_down_2((p2.second - p1.second) / (p2.first - p1.first)));
}

float Line::getY_int(pair<float, float> p1, float slope) {
    return (round_down_2(p1.second - (slope * p1.first)));
}

string Line::defineLine(pair<float, float> p1, pair<float, float> p2) {
    float slope = getSlope(p1, p2);
    float y_int = getY_int(p1, slope);
    string line = "y = " + to_string(slope) + "x + " + to_string(y_int);
    return line;
}

string getMostFreqLine(unordered_map<string, int> &lines) {
    string str;
    int max = 0;

    for (auto &i : lines) {
        if (i.second > max) {
            max = i.second;
            str = i.first;
        }
    }
    return str;
}

string findBiggestLine(vector<pair<int, int>> &points) {

    unordered_map<string, int> lines;
  //we want to define the line and then map it to the table

    int size = points.size();
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (i == j) continue;
            else {
     
                Line line(points.at(i), points.at(j));

                auto &found = lines.find(line.line);
                if (found == lines.end()) {
                    // not found
                    lines.insert({ {line.line},{1} });
                }
                else {
                    
                    found->second++;
                }
            }
        }
    }


    return getMostFreqLine(lines);
}
int main()
{
    vector<pair<int, int>> points = 
    {
        { { 1 },{ 1 } }, { { 2 },{ 2 } },
        { { 3 },{ 3 } }, { { 4 },{ 4 } },
        { { 5 },{ 5 } }, { { 6 },{ 6 } },
        { { 7 },{ 7 } }, { { 8 },{ 8 } }
    };

    cout << findBiggestLine(points) << endl;
    pause();


    points =
    {
        { { 1 },{ 1 } },{ { 3 },{ 3 } },
        { { 5 },{ 5 } },{ { 1 },{ 3 } },
        { { 5 },{ 1 } },{ { 7 },{ 4 } }
    };

    cout << findBiggestLine(points) << endl;
    pause();

    points =
    {
        { { -3 },{ -2 } },{ { -2 },{ 1 } },
        { { -1 },{ 4 } },{ { 2 },{ -1 } },
        { { 4 },{ -1 } },{ { 3 },{ -2 } }
    };

    cout << findBiggestLine(points) << endl;
    pause();

}
