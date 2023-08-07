#include <iostream>
using namespace std;
#include <array>
#include <queue>
class landUnit {
public:
    landUnit(int d, int x, int y) : data(d), visited(false) {
        loc_x = x;
        loc_y = y;
    }

    int data;
    int visited;
    int loc_x, loc_y;
};

template<size_t inner, size_t outer>
bool isValidUnit(array<array<landUnit*, inner>, outer> &land, int i, int j) {
    return (i >= 0 && i < outer && j >= 0 && j < inner && 
        land[i][j]->visited == false && land[i][j]->data == 0);
}

template<size_t inner, size_t outer>
int breadth_first_search(array<array<landUnit*, inner>, outer> &land, int i, int j) {
    queue<landUnit*> q;

    landUnit* temp = land[i][j];
    temp->visited = true;

    q.push(temp);
    int pondSize = 1;

    while (!q.empty()) {
        j = q.front()->loc_x;
        i = q.front()->loc_y;
        q.pop();
        // vertically, diagonally, or horizontally = pond
        // we must check for the 8 possible locations that
        // surround the pond unit

        // top 3
        for (int k = -1; k < 2; k++) {
            if (isValidUnit(land, i - 1, j + k)) {
                q.push(land[i - 1][j + k]);
                land[i - 1][j + k]->visited = true;
                pondSize++;
            }
        }

        // bottom 3
        for (int k = -1; k < 2; k++) {
            if (isValidUnit(land, i + 1, j + k)) {
                q.push(land[i + 1][j + k]);
                land[i + 1][j + k]->visited = true;
                pondSize++;
            }
        }

        // left and right
        if (isValidUnit(land, i, j - 1)) {
            q.push(land[i][j - 1]);
            land[i][j - 1]->visited = true;
            pondSize++;
        }

        if (isValidUnit(land, i, j + 1)) {
            q.push(land[i][j + 1]);
            land[i][j + 1]->visited = true;
            pondSize++;
        }
    }
    return pondSize;
}

template<size_t inner, size_t outer>
vector<int> pondSizes(array<array<landUnit*, inner>, outer> &land) {
    vector<int> pondSizes;

    // 1) Iterate through matrix
    for (int i = 0; i < land.size(); i++) {
        for (int j = 0; j < land.at(i).size(); j++) {
            // if == 0 and not visited preform breadh first search
            if (land[i][j]->data == 0 && land[i][j]->visited == false) {
                int size = breadth_first_search(land, i, j);
                pondSizes.push_back(size);
            }
        }
    }
    return pondSizes;
}



int main()
{
    array<array<int, 16>, 4> data =
    {
        {
            { 0, 2, 1, 0, 0, 2, 1, 0, 0, 2, 1, 0, 0, 2, 1, 0 },
            { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 },
            { 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 0, 1 },
            { 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 }
        }
    };


    array<array<landUnit*, 16>, 4> land;

    landUnit *temp;
    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data.at(i).size(); j++) {
            temp = new landUnit(data[i][j], j, i);
            land[i][j] = temp;
        }
    }

    for (int i = 0; i < data.size(); i++) {
        for (int j = 0; j < data.at(i).size(); j++) {
            cout << land[i][j]->data << " ";
        }
        cout << endl;
    }
    cout << endl;
    vector<int> ret = pondSizes(land);
    for (auto i : ret) {
        cout << i << " ";
    }
    cout << endl;
}
