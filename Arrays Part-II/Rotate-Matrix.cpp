// Link: - https://leetcode.com/problems/rotate-image/

#include <iostream>
#include <vector>
using namespace std;

// Approach - 1 - (Initializing extra Space) Time: - O(n^2) Space: - O(n^2)
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        vector<vector<int>> temp(matrix.size(), vector<int>(matrix.size()));
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                temp[j][matrix.size() - i - 1] = matrix[i][j];
            }
        }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix.size(); j++)
            {
                matrix[i][j] = temp[i][j];
            }
        }
    }
};

// Approach -2 - (Transpose and Reverse each row) Time: - O(n^2) Space: - O(1)
class Solution
{
    void swap(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }

    void reverse(vector<int> &arr)
    {
        int i = 0;
        int j = arr.size() - 1;
        while (i < j)
        {
            swap(arr[i++], arr[j--]);
        }
    }

    void transpose(vector<vector<int>> &matrix)
    {
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }

public:
    void rotate(vector<vector<int>> &matrix)
    {
        transpose(matrix);
        for (int i = 0; i < matrix.size(); i++)
        {
            reverse(matrix[i]);
        }
    }
};

// Approach - 3 - (Rotate) Time: - O(n^2) Space: - O(1)
class Solution
{
public:
    void rotate(vector<vector<int>> &matrix)
    {
        int n = matrix.size();
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            for (int j = 0; j < n / 2; j++)
            {
                int temp = matrix[n - 1 - j][i];
                matrix[n - 1 - j][i] = matrix[n - 1 - i][n - j - 1];
                matrix[n - 1 - i][n - j - 1] = matrix[j][n - 1 - i];
                matrix[j][n - 1 - i] = matrix[i][j];
                matrix[i][j] = temp;
            }
        }
    }
};

//Approach 3 is better since it does half the operations than approach 2