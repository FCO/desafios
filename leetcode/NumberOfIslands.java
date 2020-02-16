/*
    https://leetcode.com/problems/number-of-islands/

    Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

    Example 1:

    Input:
    11110
    11010
    11000
    00000

    Output: 1

    Example 2:

    Input:
    11000
    11000
    00100
    00011

    Output: 3

*/
class Solution {

    class Tile {
        public int x;
        public int y;

        public Tile(int x, int y) {
            this.x = x;
            this.y = y;
        }
    }

    public int numIslands(char[][] grid) {

        int height = grid.length;
        if(height == 0) return 0;
        int width = grid[0].length;
        if(width == 0) return 0;

        int islandCount = 0;
        Queue<Tile> toVisit = new LinkedList<>();
        boolean[][] visited = new boolean[height][width];

        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {

                if (!visited[i][j]) {
                    toVisit.add(new Tile(j, i));
                    visited[i][j] = true;
                }

                boolean foundIsland = false;
                while (toVisit.size() > 0) {
                    Tile tile = toVisit.remove();
                    if (grid[tile.y][tile.x] == '1') {

                        foundIsland = true;

                        if(tile.x > 0 && !visited[tile.y][tile.x-1]) {
                            toVisit.add(new Tile(tile.x-1, tile.y));
                            visited[tile.y][tile.x-1] = true;
                        }
                        if(tile.x < width-1 && !visited[tile.y][tile.x+1]) {
                            toVisit.add(new Tile(tile.x+1, tile.y));
                            visited[tile.y][tile.x+1] = true;
                        }
                        if(tile.y > 0 && !visited[tile.y-1][tile.x]) {
                            toVisit.add(new Tile(tile.x, tile.y-1));
                            visited[tile.y-1][tile.x] = true;
                        }
                        if(tile.y < height-1 && !visited[tile.y+1][tile.x]) {
                            toVisit.add(new Tile(tile.x, tile.y+1));
                            visited[tile.y+1][tile.x] = true;
                        }
                    }
                }

                if(foundIsland) {
                    islandCount++;
                }
            }
        }

        return islandCount;
    }
}