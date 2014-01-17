#include <iostream>
#include <vector>

enum Color = {red, green, blue};

bool paintFill(vector<vector<Color>>& grid, int x, int y, Color oldColor, Color newColor) {
	if(x < 0 || x >= grid[0].size() ||
		y < 0 || y >= grid.size())
			return false;
	else if(grid[x][y] == oldColor) {
		grid[x][y] = newColor;
		paintFill(grid, x-1, y, oldColor, newColor);
		paintFill(grid, x+1, y, oldColor, newColor);
		paintFill(grid, x, y-1, oldColor, newColor);
		paintFill(grid, x, y+1, oldColor, newColor);
	}
	return true;
}
