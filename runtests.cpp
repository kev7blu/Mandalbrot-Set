#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include<math.h>
#include <complex>
extern "C"
{
#include "gfx.h"
}

#define WINDOW_HEIGHT 800
#define WINDOW_WIDTH 800
#define MaxN 240
#define MaxR 2.0 
#define MinR -2.0 //neg
#define MaxI 1.0 
#define MinI -1.0 //neg

int main()
{
	srand(time(NULL));

	gfx_open(800,800, "MANDELBROT SET");
	for(int x = 0; x < WINDOW_HEIGHT; x++)
	{
		for(int y = 0; y < WINDOW_WIDTH; y++)
		{
			std::complex<double> z((x - 600.0) *.003, (y - 400.0) * .003);
			std::complex<double> c = z;
			int n = 0;	
			while(n < MaxN)
			{
				z = z*z + c;
				if (abs(z.real() + z.imag()) > 16)
				{
					break;
				}
				n++;		
			}
			gfx_color(250 * n % 250, 250/ n % 269, 250 + n % 300);
			//gfx_color(2500, 11000 , 250 + n % 10);
			gfx_point(x,y);
		}
	}
	gfx_wait();
	
	return 0;
}
