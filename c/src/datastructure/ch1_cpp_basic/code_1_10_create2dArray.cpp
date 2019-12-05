//
// Created by wkgreat on 2019/12/1.
//
#include <iostream>
#include <new>

using namespace std;

//创建二维数组
template <class T>
bool make2dArray(T ** &x, int numberOfRows, int numberOfColumns) {
    try {
        //创建行指针
        x = new T * [numberOfRows];

        //为每一行分配空间
        for(int i=0; i<numberOfRows; ++i) {
            x[i] = new T [numberOfColumns];
        }
        return true;
    } catch (bad_alloc) {
        return false;
    }

}

//删除二维数组
template <class T>
void delete2DArray(T ** &x, int numberOfRows) {
    for(int i=0; i<numberOfRows; i++) {
        delete [] x[i];
    }
    delete [] x;
    x = NULL;
}

class Coord {
        friend ostream &operator<<(ostream &os, Coord &coord) {
            os << "Coord(" << coord.x << "," << coord.y << ")";
            return os;
        }
private:
        int x;
        int y;
public:
        Coord(int x=0, int y=0):x(x),y(y){};
};

void test() {
    Coord ** coords;
    make2dArray(coords, 5, 5);
    for(int i=0; i<5; ++i) {
        for(int j=0; j<5; ++j) {
            cout << coords[i][j] << endl;
        }
    }
    delete2DArray(coords, 5);
}
