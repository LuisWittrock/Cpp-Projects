#include <iostream>
#include <vector>

using namespace std;

void bubbleSort(vector<int> &v)
{
    int tmp;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v.size(); j++)
        {
            if (v[i] < v[j])
            {
                tmp = v[i];
                v[i] = v[j];
                v[j] = tmp;
            }
        }
    }
}
void selectionSort(vector<int> &v)
{
    int p, j, tmp;
    for (int i = 0; i < v.size(); i++) //hier wird die sortierte von der nicht-sortierten seite geteilt erst ist nichts sortiert dann ist das erste richtig dann das zweite usw.
    {
        p = i;
        j = i + 1;
        while (j < v.size()) //es wird das kleinste element gesucht auf der sortierten seite der Liste die sortierte seite wird durch "p=i" definiert.
        {
            if (v[j] < v[p])
            {
                p = j;
            }
            j++;
        }
        tmp = v[p]; //das kleinste element der nicht sortierten seite der liste wird an das ende der sortierten seite der list gehängt.
        v[p] = v[i];
        v[i] = tmp;
    }
}
void insertionSort(vector<int> &v) //hier wird die sortierte von der nicht-sortierten seite geteilt erst ist nichts sortiert dann ist das erste richtig dann das zweite usw.
{
    int x, y;
    for (int i = 1; i < v.size(); i++)
    {
        x = v[i];
        y = i;
        while (y > 0 and x < v[y - 1])
        {
            v[y] = v[y - 1];
            y--;
        }
        v[y] = x;
    }
}


int main()
{
   
}