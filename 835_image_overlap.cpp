#include <vector>
#include <map>
#include <algorithm>

class Solution {
public:
    int largestOverlap(std::vector<std::vector<int>>& img1, std::vector<std::vector<int>>& img2) {
        int n = img1.size();
        std::vector<std::pair<int, int>> ones1, ones2;

        // 1. Сохраняем координаты всех единиц из обеих матриц
        for (int r = 0; r < n; ++r) {
            for (int c = 0; c < n; ++c) {
                if (img1[r][c] == 1) ones1.push_back({r, c});
                if (img2[r][c] == 1) ones2.push_back({r, c});
            }
        }

        // 2. Считаем частоту каждого вектора сдвига (dx, dy)
        std::map<std::pair<int, int>, int> shift_count;
        int max_overlap = 0;

        for (auto& p1 : ones1) {
            for (auto& p2 : ones2) {
                std::pair<int, int> shift = {p1.first - p2.first, p1.second - p2.second};
                shift_count[shift]++;
                max_overlap = std::max(max_overlap, shift_count[shift]);
            }
        }

        return max_overlap;
    }
};