// C++ Program to implement
// the above approach
#include <bits/stdc++.h>
using namespace std;

// Function to check a subsequence can
// be formed with min difference mid
bool can_place(int A[], int n,
            int B, int mid)
{
    int count = 1;
    int last_position = A[0];

    // If a subsequence of size B
    // with min diff = mid is possible
    // return true else false
    for (int i = 1; i < n; i++) {

        if (A[i] - last_position
            >= mid) {
            last_position = A[i];
            count++;
            if (count == B) {
                return true;
            }
        }
    }
    return false;
}

// Function to find the maximum of
// all minimum difference of pairs
// possible among the subsequence
int find_min_difference(int A[],
                        int n, int B)
{

    // Sort the Array
    sort(A, A + n);

    // Stores the boundaries
    // of the search space
    int s = 0;
    int e = A[n - 1] - A[0];

    // Store the answer
    int ans = 0;

    // Binary Search
    while (s <= e) {

        long long int mid = (s + e) / 2;

        // If subsequence can be formed
        // with min diff mid and size 
        if (can_place(A, n, B, mid)) {
            ans = mid;

            // Right half
            s = mid + 1;
        }
        else {

            // Left half
            e = mid - 1;
        }
    }

    return ans;
}

// Driver Code
int main()
{
    int A[] = { 1, 2, 3, 5 };
    int n = sizeof(A) / sizeof(A[0]);
    int B = 3;

    int min_difference
        = find_min_difference(A, n, B);
    cout << min_difference;
    return 0;
}
