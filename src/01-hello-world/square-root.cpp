#include <iostream>

void print_square(double d){
	double square_root = d*d;
	std::cout << "Square of "<<d<<", is : " << square_root << std::endl;
}

int main(){
	print_square(34.22);
	return 0;
}
