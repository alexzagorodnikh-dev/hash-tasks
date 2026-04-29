#include <iostream>
#include <vector>
#include <string>
using namespace std;

// -------- Задача 3 --------
int hash_linear(int x, int a, int b, int p, int m) {
    return ((a * x + b) % p) % m;
}

// -------- Задача 10 --------
struct point {
    int x;
    int y;
};

int hash_point(const point& p, int m) {
    long long val = (long long)p.x * 31 + p.y;
    return (val % m + m) % m;
}

// -------- Поліноміальний хеш --------
int poly_hash(string s, int p, int m) {
    long long hash = 0;
    long long power = 1;

    for (char c : s) {
        int val = (c - 'a' + 1);
        hash = (hash + val * power) % m;
        power = (power * p) % m;
    }
    return hash;
}

// -------- Проста сума --------
int simple_hash(string s, int m) {
    int sum = 0;
    for (char c : s) {
        sum += c;
    }
    return sum % m;
}

int main() {

    // Задача 1
    vector<int> nums = {15,27,44,11,33,0,-3};
    cout << "Task 1:\n";
    for (int x : nums) {
        int h = ((x % 11) + 11) % 11;
        cout << x << " -> " << h << endl;
    }

    // Задача 2
    cout << "\nTask 2:\n";
    cout << "bad: " << poly_hash("bad", 31, 100) << endl;
    cout << "dab: " << poly_hash("dab", 31, 100) << endl;

    // Задача 3
    cout << "\nTask 3:\n";
    for (int i = 0; i < 10; i++) {
        cout << i << " -> " << hash_linear(i, 3, 7, 101, 10) << endl;
    }

    // Задача 9
    cout << "\nTask 9:\n";
    vector<string> strs = {"abc","bca","cab"};

    for (auto s : strs) {
        cout << s << " simple: " << simple_hash(s,100)
             << " poly: " << poly_hash(s,31,100) << endl;
    }

    // Задача 10
    cout << "\nTask 10:\n";
    point a{1,2}, b{2,1};
    cout << "(1,2): " << hash_point(a,100) << endl;
    cout << "(2,1): " << hash_point(b,100) << endl;

    return 0;
}
