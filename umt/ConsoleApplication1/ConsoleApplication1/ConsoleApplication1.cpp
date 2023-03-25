#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;
ifstream fin("rectangle.in");
//ofstream fout("rectangle.out");

bool checkRectangle(pair<int, int> p1, pair<int, int> p2, pair<int, int> p3, pair<int, int> p4)
{
    // checking if p1, p2, p3, p4 form a rectangle that is parallel to x,y axes
    // for example, be the following rectangle:
    //
    //  p1 ------------------------- p3
    //     |                       |
    //     |                       |
    //     |                       |
    //     |                       |
    //  p2 ------------------------- p4
    //
    // p1(xp1, yp1), p2(xp2, yp2), etc. 
    // xp1 = p1.first, yp1 = p1.second,     xp2 = p2.first, yp2 = p2.second, etc.
    // p1p2p3p4 is a rectangle that is parallel to X, Y axes if: p1, p2 have the same x point and p3,p4 have the same x point and p1,p3 have the 
    // same y point and p2,p4 have the same y point
    // but we don't know in which corner every point is since we generate every possibility of 4 points, so we try every checking possibility
    return ((p1.first == p2.first && p3.first == p4.first && p1.second == p3.second && p2.second == p4.second) ||
        (p1.first == p3.first && p2.first == p4.first && p1.second == p2.second && p3.second == p4.second) ||
        (p1.first == p4.first && p2.first == p3.first && p1.second == p4.second && p2.second == p3.second));
}


int getNrOfRectangles(vector< pair<int, int> > v)
{
    int result = 0;
    for (int i = 0; i < v.size() - 3; i++)
        for (int j = i + 1; j < v.size() - 2; j++)
            for (int k = j + 1; k < v.size() - 1; k++)
                for (int l = k + 1; l < v.size(); l++)
                {   // generating every possibility of 4 points
                    pair<int, int> p1 = v[i];
                    pair<int, int> p2 = v[j];
                    pair<int, int> p3 = v[k];
                    pair<int, int> p4 = v[l];
                    if (checkRectangle(p1, p2, p3, p4) == true) result++;
                }
    return result;
}

int main()
{
    vector<pair<int, int>> v;
    int x, y;
    while (fin >> x >> y) v.push_back(make_pair(x, y));
    cout << getNrOfRectangles(v);
    return 0;
}
