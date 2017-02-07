#include <bits/stdc++.h>
#define FOR(i,start,end) for (int i=start; i<end; ++i)
using namespace std;

class Mat {
private:
    int _arr[100][100], _rows, _cols, _mod;
public:
    friend Mat operator*(const Mat& x, const Mat& y);
    friend ostream& operator<<(ostream& os, const Mat& x);
    friend Mat operator%(Mat x, int m);
    friend Mat operator^(Mat x, int e);

    Mat(int rows=0, int cols=0, int mod=1) {
        memset(_arr, 0, sizeof _arr);
        _rows = rows;
        _cols = cols;
        _mod = mod;
    }
    Mat& operator=(const Mat& x) {
        memcpy(_arr, x._arr, sizeof _arr);
        _rows = x._rows;
        _cols = x._cols;
        _mod = x._mod;
        return *this;
    }
    static Mat identity_matrix(size_t size, int mod) {
        Mat x;
        x._rows = x._cols = size;
        x._mod = mod;
        FOR(i,0,size) x._arr[i][i]=1;
        return x;
    }
    bool Gauss() {
        FOR(i,0,_rows) {
            for (int j=i+1; j<_rows && _arr[i][i]==0; j++)
                swap(_arr[i], _arr[j]);
            if (_arr[i][i] == 0) return false;
            FOR(j,0,_rows) {
                if (j != i) {
                    double t = _arr[j][i] / _arr[i][i];
                    FOR(k,0,_cols) {
                        _arr[j][k] -= _arr[i][k]*t;
                    }
                }
            }
        }
        return true;
    }
};
ostream& operator<<(ostream& os, const Mat& x) {
    FOR(i,0,x._rows) {
        FOR(j,0,x._cols) os<<x._arr[i][j]<<' ';
        os<<endl;
    }
    return os;
}
Mat operator*(const Mat& x, const Mat& y) {
    if (x._cols != y._rows) {
        cout<<"ERR\n";
        return Mat();
    }
    Mat z(x._rows, y._cols, x._mod);
    FOR(i,0,x._rows) FOR(j,0,y._cols) FOR(k,0,x._cols) {
        z._arr[i][j] += x._arr[i][k] * y._arr[k][j];
        z._arr[i][j] %= x._mod;
    }
    return z;
}
Mat operator%(Mat x, int m) {
    FOR(i,0,x._rows) FOR(j,0,x._cols) x._arr[i][j]%=m;
    return x;
}
Mat operator^(Mat x, int e) {
    Mat y = Mat::identity_matrix(x._rows, x._mod);
    while (e) {
        if (e & 1) y = y * x % x._mod;
        x = x * x % x._mod;
        e >>= 1;
    }
    return y;
}
