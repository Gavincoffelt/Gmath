#include <iostream>
#include "mathutilities.h"
#include "Vector2.h"
int main() {

	vec2 bob;

	std::cout << bob.magnitude() << std::endl;

	bob.normalize();

	std::cout << bob.magnitude() << std::endl;




	
 	return 0;
}