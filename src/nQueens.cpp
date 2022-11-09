/*
 * This program provides a solution to the problem
 * of how to fit n queens on a chess board of size nxn 
 * such that none of the queens can attack the other.
 * 
 * @author Christopher Hardy
 * 
*/


#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Board {
public:
    int* arr;
    int boardSize;
    int count = 0;

    Board() {}

    Board(int n) {
        arr = new int[n];
        for (int i = 0; i < n; i++) {
            arr[i] = 0;
        }
        boardSize = n;
    }
    void printBoard() {
        for (int i = 0; i < boardSize; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    bool checkLeft(int c) {
        for (int i = 0; i < c; ++i) {
            // Queens are on the same row

            if (arr[i] == arr[c]) {
                return false;
            }
        }
        return true;
    }
    bool checkDiagonalUp(int c) {
        int row = arr[c];
        for (int i = 1; (arr[c] - i >= 0) && (c - i >= 0); i++) {
            if (arr[c] - i == arr[c - i]) {
                return false;
            }
        }
        return true;
    }
    bool checkDiagonalDown(int c) {
        int row = arr[c];
        for (int i = 1; (arr[c] + i < 8) && (c - i >= 0); i++) {
            if (arr[c] + i == arr[c - i]) {
                return false;
            }
        }
        return true;
    }
    bool ok(int c) {
        // c represents the row of the observed queen.
        if (checkLeft(c) && checkDiagonalUp(c) && checkDiagonalDown(c)) {
            return true;
        }
        else {
            return false;
        }
    }

    int solve() {
        int n = 0;

        // if we backtrack beyond the first col, we are done
        while (n >= 0) {
            if (n > boardSize - 1) {
                // backtrack
                n--;
                ++arr[n];
                // Add Solution
                count++;

            }
            // If we have moved bey the last row 
            if (arr[n] > boardSize - 1) {
                // reset queen
                arr[n] = 0;
                // backtrack
                n--;
                ++arr[n];


            }
            // Check if the placed queen is ok.
            else if (ok(n)) {
                // move to next column if ok
                ++n;
            }
            else {
                // move to next row if not ok
                ++arr[n];
            }
        }
        return count;

    }

};

int main() {


    Board x;
    for (int i = 0; i < 10; i++) {
        x = Board(i);
        cout << "solution for " << i << " queens problem: " << x.solve() << endl;

    }


}