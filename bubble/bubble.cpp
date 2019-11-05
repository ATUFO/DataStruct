#include <iostream>
#include <iomanip>
using namespace std;

int seq[1000];
int index[1000];
int n;

void display();

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> seq[i];
        index[i] = i;
    }

    for (int i = 1; i < n; i++)
    {
        display();
       // display(n - i + 1);
        for (int j = 0; j < n - i; j++)
        {
            if (seq[j] > seq[j + 1])
            {
                swap(seq[j], seq[j + 1]);
                swap(index[j], index[j + 1]);
            }
        }
    }
  //  display(n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << setw(2) << index[i] << " ";
    }
    cout << endl;
}

void display()
{
    for (int i = 0; i <= n; i++)
        if (seq[i])
            cout << setw(2) << seq[i] << " ";
    cout << endl;
}