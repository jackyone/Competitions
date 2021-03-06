#include <iostream>
#include <std::vector>
#include <algorithm>

using uint64 = unsigned long long int;

class SegmentTree
{
private:
   uint64 n;
	std::vector<uint64> data;
public:
	SegmentTree(uint64 count)                   // array initialization constructor.
	{
		this->n    = count;                   // the size of the array.
		this->data = std::vector<uint64>(2 * n, 0);   // initialize the std::vector with 2n.
	}

	SegmentTree(std::vector<uint64> const &values)
	{  // std::vector initialization constructor.
		this->n = values.size();
		this->data = std::vector<uint64>(2 * n);
		copy(values.begin(), values.end(), &data[0] + n);
		for (auto idx = n - 1; idx > 0; idx--)
			data[idx] = max(data[idx * 2], data[idx * 2 + 1]);
	}

	void updateST(uint64 idx, uint64 value)      // to input/ update the values.
	{
		idx += n;                           // index=index+size of the array.
		data[idx] = value;                  // assign the value to respective index.

		while (idx > 1)            // Updating all other minimum values in the tree.
      {
			idx >>= 1;
			uint64 new_min = max(data[idx<<1], data[idx<<1|1]);
         if (new_min == data[idx]) break;
         data[idx] = new_min;

		}
	}

	uint64 Range_Max(uint64 left, uint64 right)          // interval [left, right).
	{
		//int result = numeric_limits<int>::max();   // std::set minimum to infinity.
		left += n;                                   // both left & right index+1.
		right += n;

		uint64 result = data[left];
		while (left < right)
      {
			if (left & 1)  result = max(result, data[left++]);
			if (right & 1) result = max(result, data[--right]);
			left >>= 1;
			right >>= 1;
		}
		return result;
	}
};
//***************************************************************************
int main()
{
   unsigned int T=0;         //T denoting the number of test cases.
   std::cin>>T;
   if(1 <= T && T<=10)
   {
      for(unsigned int queri=0; queri<T; ++queri)
      {
         unsigned int N=0; //each test case contains a single integer N.
         std::cin>>N;
         if(1 <= N && N<= 700)
         {
            SegmentTree st_max(N*N);
            uint64 Max_Ni=0, Sum=0, Max_pre=0, temp=0;;
            bool possible=true;

            for(uint64 i=0; i<(N*N); ++i)
            {
               std::cin>>temp;
               st_max.updateST(i,temp);
            }

            //for (uint64 i = 0; i < (N*N); i++)
               //std::cout << i << ": " << st_max.Range_Max(i, i+1) << std::endl;

            for(uint64 i=0; i<(N*N); i=i+N)
            {
               Max_Ni=st_max.Range_Max(i, i+N);
               //std::cout<<Max_Ni<<std::endl;
               if(Max_Ni>Max_pre)
               {
                  Sum+=Max_Ni;
                  Max_pre=Max_Ni;
               }
               else
               {
                  possible=false;
                  break;
               }
            }
            (possible) ? std::cout<<Sum<<std::endl: std::cout<<-1<<std::endl;
         }
      }
   }
   return 0;
}


