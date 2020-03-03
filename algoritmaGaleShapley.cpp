/*
Name 	: Sharashena Chairani
Class 	: B
NPM 	: 140810180022
Analisis Algoritma - Stable Matching Problem : dilihat dari Pria
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define N  5

bool PilihPria(int prefer[2*N][N], int w, int m, int m1)
{
    for (int i = 0; i < N; i++)
    {
        if (prefer[w][i] == m1)
            return true;

        if (prefer[w][i] == m)
           return false;
    }
}

void stableMatchingProb(int prefer[2*N][N], string name[10])
{
    int wanita[N];

    bool priaFree[N];

    memset(wanita, -1, sizeof(wanita));
    memset(priaFree, false, sizeof(priaFree));
    int jmlhJomblo = N;

    while (jmlhJomblo > 0)
    {
        int m;
        for (m = 0; m < N; m++)
            if (priaFree[m] == false)
                break;

        for (int i = 0; i < N && priaFree[m] == false; i++)
        {
            int w = prefer[m][i];

            if (wanita[w-N] == -1)
            {
                wanita[w-N] = m;
                priaFree[m] = true;
                jmlhJomblo--;
            }

            else
            {
                int m1 = wanita[w-N];

                if (PilihPria(prefer, w, m, m1) == false)
                {
                    wanita[w-N] = m;
                    priaFree[m] = true;
                    priaFree[m1] = false;
                }
            }
        }
    }

	cout << "Sharashena C - 140810180022" << endl;
	cout << endl;
	cout << "~~~~~~~~~~~~~~~" << endl;
    cout << " Pria   Wanita" << endl;
    cout << "~~~~~~~~~~~~~~~" << endl;
    for (int i = 0; i < N; i++)
       cout << " " << name[i+N] << "\t" << name[wanita[i]] << endl;
       cout << "~~~~~~~~~~~~~~~" << endl;
}

int main()
{
    string name[10] = {"Amy","Bertha","Clare","Diane","Erika", "Victor","Wyatt","Xavier","Yancey","Zeus"};

    int prefer[2*N][N] = {
        {6, 5, 8, 9, 7},
        {8, 6, 5, 7, 9},
        {6, 9, 7, 8, 5},
        {5, 8, 7, 6, 9},
        {6, 8, 5, 9, 7},
        {4, 0, 1, 3, 2},
        {2, 1, 3, 0, 4},
        {1, 2, 3, 4, 0},
        {0, 4, 3, 2, 1},
        {3, 1, 4, 2, 0},

    };
    stableMatchingProb(prefer, name);

    return 0;
}
