//冒泡
void maopao(vector<int>& nums) {
    int size = nums.size();
    for (int i=0; i<size-1; i++) {
        for (int j=0; j<size-i-1; j++) {
            if (nums[j] < nums[j+1])
                swap(nums[j], nums[j+1]);
        }
    }
}

//选择排序
void choiceSort(vector<int>& nums) {
    int size = nums.size();
    int temp = 0;
    for (int i=0; i<size-1; i++) {
        temp = i;
        for (int j=i+1; j<size; j++) {
            if (nums[temp] > nums[j])
                temp = j;
        }
        swap(nums[temp], nums[i]);
    }
}

//插入排序
void insertSort(vector<int>& nums) {
    int size = nums.size(), temp;
    for (int i=1; i<size; i++) {
        temp = nums[i]; //假设为无序的第一个元素
        int j = i-1;
        while (j>=0 && temp < nums[j]) {
            nums[j+1] = num[j];
            j--;
        }
        nums[j+1] = temp;
    }
}

//快速排序
int partition(vector<int>& nums, int left, int right) {
    int random_pivot_index = rand() % (right - left + 1) + left;
    int pivot = nums[random_pivot_index];
    swap(nums[random_pivot_index], nums[right]);
    int i = left - 1;
    for (int j = left; j < right; j++) {
        if (nums[j] < pivot) {
            i++;
            swap(nums[j], nums[i]);
        }
    }
    int pivot_index = i + 1;
    swap(nums[pivot_index], nums[right]);
    return pivot_index;
}

void quickSort(vector<int>& nums, int left, int right) {
    if (left < right) {
        int pivot_index = partition(nums, left, right);
        quickSort(nums, left, pivot_index-1);
        quickSort(nums, pivot_index+1, right);
    }
}

//归并排序

void mergeSort(vector<int>& nums, int left, int right) {
    if (left >= right)
        return;
    int mid = (left + right) >> 1;
    mergeSort(nums, left, mid);
    mergeSort(nums, mid + 1, right);
    merge(nums, left, mid, right);
}

void merge(vector<int>& nums, int left, int mid, int right) {
    vector<int> temp(right - left + 1);
    int i = left, j = mid + 1, k = 0;
    while (i <= mid && j <= right) 
        temp[k++] = nums[i] < nums[j] ? nums[i++] : nums[j++];
    while (i <= mid)
        temp[k++] = nums[i++];
    while (j <= right)
        temp[k++] = nums[j++];
    k = 0;
    for (i = left; i < right;) 
        nums[i++] = temp[k++];  
}