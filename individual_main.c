#include "fillit.h"

#include <stdio.h>// REMOVE THIS
void test_delete_this_later(char array[10][4][4])
{
	printf("%s", array[1][3]);
}





int		main(int argc, char **argv)
{
	char alphabet[26]
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
	alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	piecesplaced = 0;
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
	index = 0;
	grid = (char*)malloc(sizeof(char) * dimension * dimension);
	spotify(grid);
	while (piecesplaced < piececount)
	{
		if (can_place(x, y, grid, shapearray[piecesplaced]))
		{
			place_piece(shapearray[piecesplaced], grid, x, y);
			piecesplaced++;
			x = 0;
			y = 0;
			index++;
		}
		if (x == dimension)
		{
			x = 0;
			y++;
		}
		if (y == dimension)
		{
			undo(grid, alphabet[index], dimension);
			piecesplaced--;
		}
		if (piecesplaced == 0)
		{
			free(grid);
			dimension++;
			grid = (char*)malloc(sizeof(char) * dimension * dimension);
		}
		x++;
	}
	return (0);
}
}
