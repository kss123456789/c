#include <stdio.h>

int countof(int arr[], int n);
void solution(int arr[]);

int main (void)
{
    int a = 0;
    int count;
    int arr[100] = {2, 5, 4 ,5 ,2 ,1, 2};  //받은 값
    //printf("%i\n",countof(arr, 5));
    solution(arr);

}

int countof(int arr[], int n)
{
    int count = 0;

    for (int i = 0; arr[i] != 0; i++)
    {
        if (arr[i] == n)
        {
            count++;
            arr[i] = -1;
        }
    }
    return count;
}

void solution(int arr[])
{
    int a = 0;
    int answer[100];
    for (int i = 0; arr[i] > 0; i++)
    {
        int n = arr[i];

        int count = countof(arr, n);

        if (count > 1)
        {
            printf("%i\n", count);
            answer[a] = count;
            a++;
        }
    }
    if (a == 0)
    {
      printf("-1\n");
    }

}
