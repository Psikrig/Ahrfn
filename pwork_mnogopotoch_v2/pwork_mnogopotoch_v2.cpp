#include <iostream>
#include <vector>
#include <thread>

class MergeSort {
public:
    void Sort(std::vector<int>& nums) {
        if (nums.size() <= 1) return;

        int mid = nums.size() / 2;
        std::vector<int> left(nums.begin(), nums.begin() + mid);
        std::vector<int> right(nums.begin() + mid, nums.end());

        Sort(left);
        Sort(right);
        Merge(nums, left, right);
    }

private:
    void Merge(std::vector<int>& nums, const std::vector<int>& left, const std::vector<int>& right) {
        int left_size = left.size();
        int right_size = right.size();
        int i = 0, j = 0, k = 0;

        while (i < left_size && j < right_size) {
            if (left[i] <= right[j]) {
                nums[k++] = left[i++];
            }
            else {
                nums[k++] = right[j++];
            }
        }

        while (i < left_size) {
            nums[k++] = left[i++];
        }

        while (j < right_size) {
            nums[k++] = right[j++];
        }
    }
};

int main() {
    setlocale(LC_ALL, "");
    std::vector<int> nums(10);

    std::cout << "Введите 10 целых чисел для массива:\n";
    for (int i = 0; i < 10; ++i) {
        std::cin >> nums[i];
    }

    MergeSort merge_sort;
    auto merge_sort_func = [&merge_sort, &nums]() { merge_sort.Sort(nums); };
    std::thread merge_sort_thread(merge_sort_func);

    merge_sort_thread.join();

    std::cout << "Отсортированный массив:\n";
    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}