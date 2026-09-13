#include <vector>
#include <algorithm> // Нужно для встроенной функции std::max

class Solution {
public:
    int findMaxConsecutiveOnes(std::vector<int>& nums) {
        int max_count = 0;     // Рекорд единиц подряд
        int current_count = 0; // Текущая подряд идущая цепочка

        for (int num : nums) { // Удобный диапазонный цикл (range-based for)
            if (num == 1) {
                current_count++;
                // Обновляем максимум, если текущая цепочка превысила рекорд
                max_count = std::max(max_count, current_count);
            } else {
                current_count = 0; // Встретили 0 — цепочка обнулилась
            }
        }

        return max_count;
    }
};