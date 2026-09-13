/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 1. Вспомогательная функция: считает сумму всех значений в поддереве
    int getSum(TreeNode* node) {
        if (node == nullptr) return 0; // Если узла нет, сумма 0
        return node->val + getSum(node->left) + getSum(node->right);
    }

    // 2. Вспомогательная функция: считает количество узлов в поддереве
    int getCount(TreeNode* node) {
        if (node == nullptr) return 0; // Если узла нет, количество 0
        return 1 + getCount(node->left) + getCount(node->right);
    }

    // Основная функция
    int averageOfSubtree(TreeNode* root) {
        if (root == nullptr) return 0;

        // Считаем сумму и количество для текущего узла
        int sum = getSum(root);
        int count = getCount(root);

        // Переменная для результата (1 если условие совпало, иначе 0)
        int matches = 0;
        if (sum / count == root->val) {
            matches = 1;
        }

        // Рекурсивно проверяем левую и правую ветки и складываем всё вместе
        return matches + averageOfSubtree(root->left) + averageOfSubtree(root->right);
    }
};