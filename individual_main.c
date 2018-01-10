#include "fillit.h"

#include <stdio.h>// REMOVE THIS
void test_delete_this_later(char array[10][4][4])
{
	printf("%s", array[1][3]);
}





int		main(int argc, char **argv)
{
	char *input;
	char **OneDPieces;
	char *grid;
	char shapearray[10][4][4];
	int dimension;
	int piecesindex;
	int piececount;
	int index;
	int piecesplaced;
	int x;
	int y;

	index = 0;
	piecesindex = 0;
	dimension = 2;
	input = fileRead(argv[1]);
	x = 0;
	y = 0;
	if (argc != 2 || !validates(input))
	{
		write(1, "error", 5);
		return (0);
	}
	OneDPieces = split_into_tetro(input);
	piececount = piececounter(OneDPieces);
	while (OneDPieces[index])
	{
		OneD_TwoD(OneDPieces[index], shapearray[index]);
		index++;
	}
	index = 0;
	while (shaperarray[index])
	{
		move_to_corner(shapearray[index]);
		index++;
	}
	grid = (char*)malloc(sizeof(char) * dimension * dimension);
	spotify(grid); // function not written yet. fill empty grid with dots.
	while (piecesplaced < piececount)
	{
		if (can_place(x, y, grid, shapearray[index]))
		{
			place_piece(shapearray[index], grid, x, y);
			index++;
			piecesplaced++;
		}
			x++;
		if (x == dimension && y < dimension)
		{
			y++;
			x = 0;
		}
		if (y == dimension)
		{
			y = 0;
			dimension++;
			free (grid);
			grid = (char*)malloc(sizeof(char) * dimension * dimension);
			spotify(grid);
			x = 0;
		}
	}
}
