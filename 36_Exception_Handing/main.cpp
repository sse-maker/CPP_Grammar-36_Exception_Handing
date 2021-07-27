//
//  main.cpp
//  36_Exception_Handing
//
//  Created by 세광 on 2021/07/27.
//

#include <iostream>
#include <string>

using namespace std;

int fact(int n) {
    if (n < 0) throw to_string(n) + ": nagative number";
    if (n == 0) return 1;
    return n * fact(n - 1);
}

int comb(int n, int r) {
    int a = fact(n);
    int b = fact(r);
    int c = fact(n - r);
    return a / b / c;
}

int main() {
    int n, r;
    try {
        while (true) {
            cin >> n >> r;
            cout << comb(n, r) << endl;
        }
    }
    catch (const string &e) {
        cout << e << endl;
    }
    catch (int e) {
        cout << e << endl;
    }
    catch (...) { // switch의 default와 비슷한 역할
        cout << "Unknown error occurred" << endl;
    }
    // try 안에서 throw를 하면 throw된 객체를 catch에서 받음 (throw 타입은 어떤 것이든 가능)
    // throw된 객체가 여러 함수 간에도 이동할 수 있음
    // catch문을 여러 개 달아서 여러 개의 자료형의 예외를 받을 수도 있음
    // throw 객체를 catch문을 통해 잡지 못했을 경우 (throw 객체를 받을 적절한 catch문이 없을 경우) 런타임 에러 발생
}
