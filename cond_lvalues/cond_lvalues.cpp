#include <iostream>

int main(int argc, char **argv)
{
	int i = 0;
	int j = 0;
	
	((true) ? i : j) = 1;
	
	std::cout << "i: " << i << " j: " << j << std::endl;
}