#include <iostream>
using namespace std;

int main()
{
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n + 1];

    cout << "Enter " << n + 1 << " dimensions: ";
    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    // m[i][j] stores minimum multiplication cost
    int m[n + 1][n + 1];

    // Cost of multiplying one matrix is 0
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    // Chain length
    for (int length = 2; length <= n; length++)
    {
        for (int i = 1; i <= n - length + 1; i++)
        {
            int j = i + length - 1;

            // Initialize with a very large value
            m[i][j] = 999999999;

            // Try every possible split
            for (int k = i; k < j; k++)
            {
                int cost = m[i][k]
                         + m[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if (cost < m[i][j])
                {
                    m[i][j] = cost;
                }
            }
        }
    }

    cout << "Minimum number of scalar multiplications = "
         << m[1][n] << endl;

    return 0;
}
