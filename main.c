#include <stdio.h>
void print_line(int x)
{
	for (int i = 0; i <= (x * 4); i++)
	{
		putchar('-');
	}
}

void print_spacial(int x)
{
	printf("\n|%*c\n", (x * 4), '|');
}

void copy_matix(int y, int x, int a[y][x], int b[y][x])
{
	for (int i = 0; i < y; i++)
	{
		for (int j = 0; j < x; j++)
		{
			b[i][j] = a[i][j];
		}
	}
}

void print_map(int y_axis, int x_axis, int matrix[y_axis][x_axis])
{
	for (int i = 0; i < y_axis; i++)
	{
		print_line(x_axis);
		print_spacial(x_axis);
		for (int j = 0; j < x_axis; j++)
		{
			printf("| %d ", matrix[i][j]);
			if (j == (x_axis - 1))
			{
				putchar('|');
			}
		}
		print_spacial(x_axis);
	}
	print_line(x_axis);
	putchar('\n');
}

void input_coordinates(int a[])
{
	int coord_y = 0;
	int coord_x = 0;
	
	scanf("%d %d", &coord_y, &coord_x);
	a[0] = coord_y -1;
	a[1] = coord_x -1;
	putchar('\n');
}

void plan_route(int y, int x, int map[y][x], int curlock[], int dest[])
{
	int planned_route[y][x];
	
	copy_matix(y, x, map, planned_route);
	
	int route_steps[10][2] =   {{0,0},
								{0,0},
								{0,0},
								{0,0},
								{0,0},
								{0,0},
								{0,0},
								{0,0},
								{0,0},
								{0,0}};
	int counter = 0;
	
	while(curlock[0] != dest[0])
	{
		if (curlock[0] < dest[0])
		{
			curlock[0] += 1;
		}
		else if (curlock[0] > dest[0])
		{
			curlock[0] -= 1;
		}
		planned_route[curlock[0]][curlock[1]] = 5;
		
		for (int i = 0; i < 2; i++)
		{
			route_steps[counter][i] = curlock[i];
		}
		counter++;
	}
	
	
		while(curlock[1] != dest[1])
	{
		if (curlock[1] < dest[1])
		{
			curlock[1] += 1;
		}
		else if (curlock[1] > dest[1])
		{
			curlock[1] -= 1;
		}
		planned_route[curlock[0]][curlock[1]] = 5;
		
		for (int i = 0; i < 2; i++)
		{
			route_steps[counter][i] = curlock[i];
		}
		counter++;
	}
	print_map(y, x, planned_route);
	print_map(10, 2, route_steps);
}

int main(int argc, char **argv)
{
	int current_location[2] = {0, 0};
	int destination[2] = {0, 0};
	
	int matrix[5][5] = {{0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0},
						{0, 0, 0, 0, 0}};

	int size_y_axis = ((sizeof(matrix) / sizeof(matrix[0])));
	int size_x_axis = (sizeof(matrix[0]) / sizeof(int));
	
	print_map(size_y_axis, size_x_axis, matrix);
	
	printf("Voer het startpunt in: ");
	input_coordinates(current_location);
	
	printf("Voer de bestemminh in: ");
	input_coordinates(destination);
	
	matrix[current_location[0]][current_location[1]] = 1;
	matrix[destination[0]][destination[1]] = 2;
	
	print_map(size_y_axis, size_x_axis, matrix);
	
	plan_route(size_y_axis, size_x_axis, matrix, current_location, destination);
					
	return 0;
}
