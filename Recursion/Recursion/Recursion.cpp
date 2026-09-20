
#include <iostream>
using namespace std;
int factorial(int x) {
    if (x == 0)
        return 1;


    return x*factorial(x-1) ;


}
int power(int num, unsigned pow) {
    if (pow == 0)
        return 1;
    return num * power(num, pow - 1);

}
int fib(int n) {
    if (n == 1 || n == 2)
        return 1;
    return fib(n - 1) + fib(n - 2);
}

void print1(int a[], int l, int u) {
    if (l <= u) {
        cout << a[l];
        print1(a, l + 1, u);



    }



}

void print2(int a[], int l, int u) {
    if (l <= u) {
        print2(a, l + 1, u);
        cout << a[l];




    }



}


int maxEl(int arr[],int l,int u) {

    if (l == u) {
        return arr[l];
    }
    int maxel = maxEl(arr, l + 1, u);
    if (maxel < arr[l])
        return arr[l];
    else
        return maxel;


}
int min(int arr[], int l, int u) {
    if (u == l)return arr[l];
    int minel = min(arr, l + 1, u);
    if (minel > arr[l])
        return arr[l];
    else return minel;
}

int sum(int arr[], int l, int u) {
    if (l == u)
        return arr[l];

    return arr[l] + sum(arr, l + 1, u);
}
int count(int arr[], int l, int u) {
    if (l == u)
        return 1;

    return 1 + count(arr, l + 1, u);


}
double avg(int arr[], int l, int u) {
    return (double)sum(arr, l, u) / count(arr, l, u);
}

int main()
{
   /* cout << factorial(6) << endl;
    cout << power(6,2) << endl;
    for (int i = 1;i <= 17;i++)
        cout << fib(i) << " ";*/

    int arr[] = { 1,2,3,4,5 };
    print1(arr, 0, 4);


}

