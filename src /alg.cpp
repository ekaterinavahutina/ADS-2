int countPairs1(int* arr, int len, int value)
{
    int quantity = 0;
    for (int i = 0; i < len - 1; i++)
        for (int j = i + 1; j < len; j++)
            if (arr[i] + arr[j] == value)
                quantity++;
    return quantity;
}

int countPairs2(int* arr, int len, int value) {

    int quantity = 0;

    for (int i = 0; i < len; i++)
        for (int j = 0; j < len; j++) {
            if (i == j) continue;
            else if (arr[i] + arr[j] == value) {
                quantity++;
                continue;
            }
            else if (arr[i] + arr[j] > value) break;
        }
    return quantity / 2;
}

int countPairs3(int* arr, int len, int value)
{
    int quantity = 0;
    int middle = 0;
    for (int i = 0; i < len - 1; i++)
    {
        int left = i, right = len;

        while (left < right - 1)
        {
            middle = (left + right) / 2;
            if (arr[i] + arr[middle] == value)
            {
                quantity++;
                int j = middle + 1;
                while (arr[i] + arr[j] == value && j < right)
                {
                    quantity++;
                    j++;
                }
                j = middle - 1;
                while (arr[i] + arr[j] == value && j > left)
                {
                    quantity++;
                    j--;
                }
                break;
            }
            if (arr[i] + arr[middle] > value)
                right = middle;
            else
                left = middle;
        }

    }
    return quantity;
}
