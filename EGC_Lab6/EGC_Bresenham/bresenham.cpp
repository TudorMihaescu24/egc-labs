#include <iostream>
#include "bresenham.h"
#include "math.h"

using namespace std;
//Detects in which octant a line is situated
int getOctant(BresenhamLine line)
{
	int deltaY = (line.endY - line.startY);
	int deltaX = (line.endX - line.startX);
	//Slope		
	float m = abs(deltaY) / (float)abs(deltaX);

	if ((m < 1) && (deltaX > 0) && (deltaY <= 0)) //first octant
		return 1;

	if ((m >= 1) && (deltaX > 0) && (deltaY < 0)) //2th octant
		return 2;

	if ((m >= 1) && (deltaX <= 0) && (deltaY < 0)) //3th octant
		return 3;

	if ((m < 1) && (deltaX <= 0) && (deltaY < 0)) //4th octant
		return 4;

	if ((m < 1) && (deltaX <= 0) && (deltaY > 0)) //4th octant
		return 5;

	if ((m > 1) && (deltaX <= 0) && (deltaY > 0)) //4th octant
		return 6;

	if ((m > 1) && (deltaX >= 0) && (deltaY > 0)) //7th octant
		return 7;

	if ((m < 1) && (deltaX >= 0) && (deltaY > 0)) //8th octant
		return 8;

	return 0;
}


//Draws a new raster line using Bresenham's algorithm
void BresenhamDraw(BresenhamLine line, SDL_Renderer* renderer)
{
	int tmpStartX = 0;
	int tmpStartY = 0;
	int tmpEndX = 0;
	int tmpEndY = 0;
	int tmpCurrentX = 0;
	int tmpCurrentY = 0;

	int dy = abs(line.endY - line.startY);
	int dx = abs(line.endX - line.startX);

	int d, inc1, inc2;

	int octant = getOctant(line);

	switch (octant)
	{
	case 1:
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dy - dx;
		inc1 = 2 * dy;
		inc2 = 2 * (dy - dx);

		while (tmpCurrentX < tmpEndX)
		{
			//Draw current point
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			++tmpCurrentX;

			if (d < 0)
				d += inc1;
			else
			{
				d += inc2;
				--tmpCurrentY;
			}
		}
		break;
	case 2:
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dx - dy;
		inc1 = 2 * dx;
		inc2 = 2 * (dx - dy);

		while (tmpCurrentY > tmpEndY)
		{
			//Draw current point
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			--tmpCurrentY;

			if (d < 0)
				d += inc1;
			else
			{
				d += inc2;
				++tmpCurrentX;
			}
		}
		break;
	case 3:
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dx - dy;
		inc1 = 2 * dx;
		inc2 = 2 * (dx - dy);

		while (tmpCurrentY > tmpEndY)
		{
			//Draw current point
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			--tmpCurrentY;

			if (d < 0)
				d += inc1;
			else
			{
				d += inc2;
				--tmpCurrentX;
			}
		}
		break;
	case 4:
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dy - dx;
		inc1 = 2 * dy;
		inc2 = 2 * (dy - dx);

		while (tmpCurrentX > tmpEndX)
		{
			//Draw current point
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			--tmpCurrentX;

			if (d < 0)
				d += inc1;
			else
			{
				d += inc2;
				--tmpCurrentY;
			}
		}
		break;
	case 5:
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dy - dx;
		inc1 = 2 * dy;
		inc2 = 2 * (dy - dx);

		while (tmpCurrentX > tmpEndX)
		{
			//Draw current point
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			--tmpCurrentX;

			if (d < 0)
				d += inc1;
			else
			{
				d += inc2;
				++tmpCurrentY;
			}
		}
		break;
	case 6:
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dx - dy;
		inc1 = 2 * dx;
		inc2 = 2 * (dx - dy);

		while (tmpCurrentY < tmpEndY)
		{
			//Draw current point
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			++tmpCurrentY;

			if (d < 0)
				d += inc1;
			else
			{
				d += inc2;
				--tmpCurrentX;
			}
		}
		break;
	case 7:
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dx - dy;
		inc1 = 2 * dx;
		inc2 = 2 * (dx - dy);

		while (tmpCurrentY < tmpEndY)
		{
			//Draw current point
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			++tmpCurrentY;

			if (d < 0)
				d += inc1;
			else
			{
				d += inc2;
				++tmpCurrentX;
			}
		}
		break;
	case 8:
		tmpStartX = tmpCurrentX = line.startX;
		tmpEndX = line.endX;
		tmpStartY = tmpCurrentY = line.startY;
		tmpEndY = line.endY;

		d = 2 * dy - dx;
		inc1 = 2 * dy;
		inc2 = 2 * (dy - dx);

		while (tmpCurrentX < tmpEndX)
		{
			//Draw current point
			SDL_RenderDrawPoint(renderer, tmpCurrentX, tmpCurrentY);
			++tmpCurrentX;

			if (d < 0)
				d += inc1;
			else
			{
				d += inc2;
				++tmpCurrentY;
			}
		}

		break;

	default:
		break;
	}
}



//Draws a new raster circle using Bresenham's algorithm
void plot_points(int x, int y, SDL_Renderer *renderer, BresenhamCircle circle)
{
	SDL_RenderDrawPoint(renderer, x + circle.centerX, y + circle.centerY);
	SDL_RenderDrawPoint(renderer, x + circle.centerX, -y + circle.centerY);
	SDL_RenderDrawPoint(renderer, -x + circle.centerX, y + circle.centerY);
	SDL_RenderDrawPoint(renderer, -x + circle.centerX, -y + circle.centerY);
	SDL_RenderDrawPoint(renderer, y + circle.centerX, x + circle.centerY);
	SDL_RenderDrawPoint(renderer, -y + circle.centerX, x + circle.centerY);
	SDL_RenderDrawPoint(renderer, y + circle.centerX, -x + circle.centerY);
	SDL_RenderDrawPoint(renderer, -y + circle.centerX, -x + circle.centerY);
}

void BresenhamDraw(BresenhamCircle circle, SDL_Renderer* renderer) {
	int currentY = circle.radius;

	int d = 1 / 4.0f - circle.radius;

	for (int x = 0; x < ceil(circle.radius / sqrt(2)); x++)
	{
		plot_points(x, currentY, renderer, circle);
		d = d + 2 * x + 1;
		if (d > 0)
		{
			d = d + 2 - 2 * currentY;
			--currentY;
		}
	}

}