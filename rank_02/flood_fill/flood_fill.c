#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct	s_point
{
	int	x;
	int	y;
}				t_point;

void	dfs(char **grid, t_point size, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return ;
	if (grid[row][col] == 'F' || grid[row][col] != target)
		return ;
	grid[row][col] = 'F';

	dfs(grid, size, target, row -1, col);
	dfs(grid, size, target, row +1, col);
	dfs(grid, size, target, row, col - 1);
	dfs(grid, size, target, row, col + 1);
}

void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target = tab[begin.y][begin.x];

	dfs(tab, size, target, begin.y, begin.x);
}

/*void	print_tab(char **area)
{
	int	x = 0;
	int	y = 0;

	while(area[y])
	{
		x = 0;
		while(area[y][x])
		{
			write(1, &area[y][x], 1);
			x++;
		}
		y++;
	}
}

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
	}*/
