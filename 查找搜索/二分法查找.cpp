 int Method(int nums[] , int low, int high, int target)
        {
            while (low <= high)
            {
                int middle = (low + high) / 2;
                if (target == nums[middle])
                {
                    return middle;
                }
                else if (target > nums[middle])
                {
                    low = middle + 1;
                }
                else if (target < nums[middle])
                {
                    high = middle - 1;
                }
            }
            return -1;
        }