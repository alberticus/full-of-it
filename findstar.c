void    findstar(x, y, grid, dimension)
{
    while (y < dimension)
    {
        if (grid[x][y] == '*')
        {
            grid[x][y] = '.';
        }
        if (x == dimension)
        {
            x = 0;
            y++;
        }
        x++;
    }
    if (y == dimension)
    {
        x = 0;
        y = 0;
    }
}
