#include<iostream>
#include<set>
#include<numeric>
#include<tuple>
#include<iomanip>
#include<stdlib.h>
#include<queue>
#include<stack>
#include<map>
#include<unordered_map>
#include<math.h>
#include<vector>
#include<climits>
#include<algorithm>
#include<string>
#include<sstream>
#include<string.h>
#include<deque>
using namespace std;
int max(int x, int y) {
   return (x > y) ? x : y;
}

int knapSack(int W, int w[], int v[], int n) 
{
   int i, wt;

   int K[n + 1][W + 1];

   for (i = 0; i <= n; i++) 
   {
      for (wt = 0; wt <= W; wt++) 
	  {
         if (i == 0 || wt == 0)
         K[i][wt] = 0;
         else if (w[i - 1] <= wt)
            K[i][wt] = max(v[i - 1] + K[i - 1][wt - w[i - 1]], K[i - 1][wt]);
         else
		 	K[i][wt] = K[i - 1][wt];

      }
   }
   return K[n][W];
}

int main() 
{
   int n, W;
   cin >> n;
   int v[n], w[n];
   for (int i = 0; i < n; i++) 
   {
      cin >> v[i];
   }
   for (int i = 0; i < n; i++) 
   {
      cin >> w[i];
   }
   cin >> W;
   cout << knapSack(W, w, v, n);
   return 0;
}