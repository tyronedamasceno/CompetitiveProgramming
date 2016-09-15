#include <iostream>
#include <array>
#include <algorithm>
#include <iterator>
#include <string>

bool
compare(int a, int b)
{
	return a < b;
}
bool compareName(std::string a, std::string b)
{
	return a < b;
}

template <typename FwrdIt, typename Comparator>
void
insertion(FwrdIt first_, FwrdIt last_, Comparator cmp)
{
	for (FwrdIt it = first_ + 1; it != last_; it++)
	{
		auto curr = *it;
		auto it2 = (it - 1);
		
		while ((it2 >= first_) && cmp(curr, *it2))
		{
			*(it2 + 1) = *it2;
			it2--;
		}
		*(it2 + 1) = curr;  
		
	}
}
template <typename FwrdIt, typename Comparator>
void 
selection(FwrdIt first_, FwrdIt last_, Comparator cmp)
{
	
	for (/* empty*/ ; first_ != last_; first_++)
	{
		auto aux = first_;
		auto smaller = *first_;
		auto pos = first_;
		
		for (/* empty */ ; aux != last_; aux++)
		{
			if (cmp(*aux, smaller))
			{
				smaller = *aux;
				pos = aux;
			}	
		}
		std::swap(*pos, *first_);	
	}
}

template <typename FwrdIt, typename Comparator>
void 
bubble(FwrdIt first_, FwrdIt last_, Comparator cmp)
{
	auto sz = last_ - first_;
	for (auto i(0); i < sz; i++)
	{
		auto aux = first_ + 1;
		auto swapped = false;
		for (/* empty */; aux != last_ - i; aux++)
		{
			if (cmp(*aux, *(aux-1)))
			{
				swapped = true;
				std::swap(*aux, *(aux-1));
			}
		}
		if (!swapped) break;
	}
}



int main()
{
	std::array< int, 10 > A = {6, 2, 1, 8, 5, 3, 4, 9, 0, 7 };
	std::array< int, 10 > B = {6, 2, 1, 8, 5, 3, 4, 9, 0, 7 };
	std::array< int, 10 > C = {6, 2, 1, 8, 5, 3, 4, 9, 0, 7 };

	std::cout << "\n\n>>> Selection Sort" << std::endl;
	std::cout << ">>> Original array: " << std::endl;
	std::copy( A.begin(), A.end(), std::ostream_iterator<int>(std::cout, " ") );
	std::cout << std::endl;
	
	std::cout <<"\n>>> Processing..."; 
	selection(A.begin(), A.end(), compare);
	
	std::cout << "\n\n>>> Sorted array: " << std::endl;
	std::copy( A.begin(), A.end(), std::ostream_iterator<int>(std::cout, " ") );
	std::cout << std::endl;
	
	std::cout << "\n\n\n>>> Insertion Sort" << std::endl;
	std::cout << ">>> Original array: " << std::endl;
	std::copy( B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " ") );
	std::cout << std::endl;
	
	std::cout <<"\n>>> Processing..."; 
	insertion(B.begin(), B.end(), compare);
	
	std::cout << "\n\n>>> Sorted array: " << std::endl;
	std::copy( B.begin(), B.end(), std::ostream_iterator<int>(std::cout, " ") );
	std::cout << std::endl;
		
	std::cout << "\n\n\n>>> Bubble Sort" << std::endl;
	std::cout << ">>> Original array: " << std::endl;
	std::copy( C.begin(), C.end(), std::ostream_iterator<int>(std::cout, " ") );
	std::cout << std::endl;
	
	std::cout <<"\n>>> Processing..."; 
	bubble(C.begin(), C.end(), compare);
	
	std::cout << "\n\n>>> Sorted array: " << std::endl;
	std::copy( C.begin(), C.end(), std::ostream_iterator<int>(std::cout, " ") );
	std::cout << std::endl << std::endl;

	return 0;
}
