#include <cmath>
#include <limits>
#include <std::set>
#include <std::vector>
#include <iostream>
#include <algorithm>
#include <iterator>


using ull = unsigned long long int;
int main()
{
    ios_base::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    ull n, miles=0;
    std::cin>>n;
    std::multiset<ull> mySet;
    for(auto i=0; i<n;++i)
    {
       ull temp=0;
       std::cin>>temp;
       mySet.insert(temp);
    }

    ull a,b,c;
    int idx=0;
    for(auto itr=mySet.rbegin(); itr!=mySet.rend(); ++itr)
       {
          if(idx <= (n-3)) // till n-3
          {
             a= *(itr++);
             b= *(itr++);
             c= *(itr++);

             if(a < (b+c) )
               break;

             itr--; itr--; itr--; // going back to current position.
          }
          ++idx;
       }
    if(a < (b+c) )
      std::cout<<c <<" "<<b <<" "<<a<<std::endl;
    else
      std::cout<<"-1"<<std::endl;
    return 0;
}
