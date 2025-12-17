#include "Binary.h"
#include "Array.h"
#include "Dynamic Programming.h"

int main() {
    vector<int> str{ 2, 3, 5};

    DP::combinationSum(str, 8);

    return 0;
}