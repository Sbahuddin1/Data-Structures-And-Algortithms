#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
using std::vector;

double get_optimal_value(double capacity, vector<double> weights, vector<double> values)
{

    double total_value = 0.0;
    int n = weights.size();

    if (capacity == 0 || weights.empty() || values.empty())
    {
        return 0;
    }
    else
    {
        // i loop iterates over each item we have
        for (int i = 0; i < n; i++)
        {
            double max_val_per_weight = 0;
            double best_item = 0;
            // j loop selects the best item comparing their value/weigh ratio
            for (int j = 0; j < n; j++)
            {
                if (weights[j] > 0)
                {
                    if (values[j] / weights[j] > max_val_per_weight)
                    {
                        max_val_per_weight = values[j] / weights[j];
                        best_item = j;
                    }
                }
            }
            // then the amount of best item is taken and amount is reduced from capacity

            double amount = min(weights[best_item], capacity); // this func returns min value of the two numbers
            total_value += amount * max_val_per_weight;
            weights[best_item] -= amount;
            capacity -= amount;
        }
    }
    // returns the max value we looted 
    return total_value;
}

int main()
{
    int n;
    int capacity;
    std::cin >> n >> capacity;
    vector<double> values(n);
    vector<double> weights(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> values[i] >> weights[i];
    }
    double optimal_value = get_optimal_value(capacity, weights, values);

    std::cout << optimal_value << std::endl;
    return 0;
}
