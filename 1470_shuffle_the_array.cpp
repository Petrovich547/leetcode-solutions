#include <vector>

class Solution {
public:
    std::vector<int> shuffle(std::vector<int>& nums, int n) {
        // Создаем вектор под ответ сразу размером 2 * n
        std::vector<int> ans(2 * n);

        // Проходим по первой половине элементов (от 0 до n - 1)
        for (int i = 0; i < n; i++) {
            ans[2 * i] = nums[i];       // Ставим x_i на четную позицию (0, 2, 4...)
            ans[2 * i + 1] = nums[i + n]; // Ставим y_i на нечетную позицию (1, 3, 5...)
        }

        return ans; // Возвращаем собранный массив
    }
};