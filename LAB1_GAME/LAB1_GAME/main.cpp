#include <iostream>
#include <random>
#include <time.h>
#include "Field.h"

int main()
{
	srand(time(nullptr));

	Field p(30, 30);
	p.show();
}