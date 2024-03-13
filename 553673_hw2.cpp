#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <climits>

void vulnerabilities() {
    char b[10] = { 0 }, * ptr = new char[10];
    int arr[5] = { 0 };
    std::cin >> b; // Buffer Overflow
    printf(b); // Format String Vulnerability
    delete[] ptr; std::cout << reinterpret_cast<void*>(ptr); // Use After Free
    ptr = new char[5]; delete[] ptr; delete[] ptr; // Double Free
    int* nPtr = nullptr; // Null Pointer Dereference
    *nPtr = 1;
    strcpy(b, "longtext"); // Stack Buffer Overflow
    std::cout << arr[10]; // Array Index Out of Bounds
    long lValue = LONG_MAX; int iValue = (int)lValue; // Improper Type Conversion
    int underflow = INT_MIN; underflow--; // Signed Integer Underflow
    char noTerm[6] = { 'a', 'b', 'c', 'd', 'e'}; // Incorrect String Termination
    std::cout << noTerm;
    char* leakyPtr = new char[50]; // Memory Leak
}

int main() {
    vulnerabilities();
    return 0;
}