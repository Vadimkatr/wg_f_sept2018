#include <iostream>
#include <vector>
#include <algorithm>

void calculateNumberOfDishes () {
    int n, q;
    std::cin >> n;
    std::vector<int> prices;
    
    // Save price of dishes to vector<int> prices
    for(int i = 0, price = 0; i < n; i ++) {
        std::cin >> price;
        prices.push_back(price / 2);
    }
    
    // Sort vector<int> prices for easy search
    std::sort (prices.begin(), prices.end());
    std::cin >> q;

    for(int i = 0, money = 0; i < q; i ++) {
        std::cin >> money;
        // Find price that are less than the specified
        auto upperPrice = std::upper_bound(prices.begin(), prices.end(), money);
        std::cout << std::distance(prices.begin(), upperPrice) << std::endl;
    }
}

int main () {

    calculateNumberOfDishes();
    return 0;
}