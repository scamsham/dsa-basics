/*
Problem Statement

Given an integer N representing the number of pairs of parentheses,
generate all valid combinations of  N pairs of parentheses.
*/

#include <iostream>
#include <vector>

using namespace std;

void generateBrackets(int i, string output, int opening, int closing, int N)
{
    // Base case
    if (i == 2 * N)
    {
        // output[i] = '\0';
        cout << output << endl;
        return;
    }
    if (opening < N)
    {
        generateBrackets(i + 1, output + "(", opening + 1, closing, N);
    }
    if (closing <= opening && opening > 0)
    {
        generateBrackets(i + 1, output + ")", opening, closing + 1, N);
    }
    return;
}

int main()
{
    int N;
    cin >> N;
    string output = "";
    generateBrackets(0, output, 0, 0, N);

    return 0;
}