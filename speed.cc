#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include <vector>

using namespace std;

int main()
{
  int n,m,max=0;

  cout << "N, M:" << endl;
  cin >> n;
  assert(n >= 2 && n <=1000);
  cin.ignore(1);
  cin >> m;
  assert(m >= 1 && m<=10000);

  int* first_villages = new int[m];
  int* second_villages = new int[m];
  int* optimal_speeds = new int[m];
  vector<int> positions(1);

  for(int i=0; i<m; i++)
  {
    cin >> first_villages[i];
    assert(first_villages[i] >= 1);
    cin.ignore(1);
    cin >> second_villages[i];
    assert(second_villages[i] <= n);
    if(max < abs(first_villages[i] - second_villages[i]))
    {
      max = abs(first_villages[i] - second_villages[i]);
    }
    cin.ignore(1);
    cin >> optimal_speeds[i];
    assert(optimal_speeds[i] >= 1 && optimal_speeds[i] <= 30000);
    cin.ignore(1);
  }

  for(int i=0,j=0; i<m; i++)
  {
    if(abs(first_villages[i] - second_villages[i]) == max)
    {
      positions.push_back(i);
      j++;
      positions.resize(j);
    }
  }

  positions.shrink_to_fit();

  //for(auto it=positions.rbegin(); it != rend)

  delete[] first_villages;
  delete[] second_villages;
  delete[] optimal_speeds;
  return 0;
}
