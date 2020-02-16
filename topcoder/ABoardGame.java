/*
    Problem url:

        https://arena.topcoder.com/#/u/practiceCode/15895/38490/13033/1/320754

    Problem Statement:

        Your friends Alice and Bob are playing a board game. They have asked you to help them to determine the winner.
        The game is played on a square board with 2N rows and 2N columns. The exact rules of the game itself are not
        important for this problem. Once the game is over, each cell of the board is either empty or contains a single
        piece that belongs to either Alice or Bob. You are given board, where the j-th character in i-th element
        (0-based indices) describes the contents of the cell in row i, column j: '.' represents an empty cell, 'A' a
        cell with Alice's piece and 'B' a cell with Bob's piece.

        The entire board is divided into N regions. Region 1 occupies the 4 central cells of the board. Each next
        region contains all cells that are horizontally, vertically or diagonally adjacent to cells of the immediately
        previous region and do not belong to any of the previous regions. For example, when N = 4, here is how the
        regions look:

            44444444
            43333334
            43222234
            43211234
            43211234
            43222234
            43333334
            44444444

        The winner is determined as follows. Consider the lowest numbered region that contains a different number of
        Alice's and Bob's pieces. The player who has more pieces in this region is the winner. If all regions contain
        the same number of Alice's and Bob's pieces, the game ends in a draw.

        Return "Alice" if Alice wins the given game, "Bob" if Bob wins and "Draw" if the game ends in a draw. Note that return values are case-sensitive.

    Definition

        Class:
        ABoardGame

        Method:
        whoWins

        Parameters:
        String[]

        Returns:
        String

        Method signature:
        String whoWins(String[] board)
        (be sure your method is public)

        Limits
        Time limit (s):
        2.000
        Memory limit (MB):
        256

    Constraints

        - board will contain between 2 and 50 elements, inclusive.
        - The number of elements in board will be even.
        - Each element of board will contain the same number of characters as the number of elements in board.
        - Each character in board will be 'A', 'B' or '.'.

    Examples

        0)
        {".....A", "......", "..A...", "...B..", "......", "......"}
        Returns: "Alice"
        Both Alice and Bob have 1 piece in region 1, so they are tied there. In region 2, they have no pieces at all, so a tie again. Finally, in region 3 Alice has 1 piece, while Bob has none. So Alice is the winner of this game.

        1)
        {"AAAA", "A.BA", "A..A", "AAAA"}
        Returns: "Bob"
        Even though Alice has 12 pieces and Bob just one, this one piece is enough for him to win.

        2)
        {"..", ".."}
        Returns: "Draw"
        The board can be entirely empty.

        3)
        {"BBB..BAB...B.B", ".AAAAAAAAAAAA.", "AA.AA.AB..A.AB", "..........B.AB", ".A..BBAB.A.BAB", ".AB.B.......A.", ".A..A.AB.A..AB", ".ABAA.BA...BA.", "BAAAB.....ABA.", ".A....B..A..B.", "B...B....B..A.", "BA.B..A.ABA.A.", "BAAAA.AAAAA.A.", "B.B.B.BB.B...."}
        Returns: "Alice"

        4)
        {"..A..AAA..AA", "ABABB..AAAAA", "ABBBBBBBBBA.", "AABBBABABBAA", "...BABABABBA", "B.BA..A.BBA.", "AA.A..B.AB.B", "..BA.B.AABAA", "..ABABBBABA.", ".ABB.BBBBBAA", "ABAAA.AA.A.A", "A..AAA.AAA.A"}
        Returns: "Bob"

        5)
        {"B..ABAABBB", "B.........", "A..A.AA..B", "A.BBBAA..A", "B.AAAAB...", "A..BBBBB.A", "B..ABAABBA", "A......B.B", "B......A.A", "BA.AABBB.A"}
        Returns: "Draw"
        This problem statement is the exclusive and proprietary property of TopCoder, Inc. Any unauthorized use or reproduction of this information without the prior written consent of TopCoder, Inc. is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved.

*/

import java.util.Map;
import java.util.HashMap;

class ABoardGame {

    // This should be commented out during submission
    public static void main(String[] args) throws Exception {

        ABoardGame game = new ABoardGame();
        System.out.println(game.whoWins(args));
    }

    public String whoWins(String[] board) throws Exception {

        Board boardObj = new Board(board);
        //System.out.println(boardObj);
        int levelCount = board.length / 2;

        for (int l = 1; l <= levelCount; l++) {
            String result = boardObj.checkRegion(l);
            //System.out.println("Level [" + l + "] result = [" + result + "]");
            if (!result.equals("Draw")) {
                return result;
            }
        }
        return "Draw";
    }

    static class Board {

        private char[][] elements;

        public enum Cell {
            Alice,
            Bob,
            Empty
        }

        public Board(String[] board) throws Exception {

            populateElements(board);
        }

        private void populateElements(String[] board) throws Exception {

            int n = board.length;

            if (n % 2 != 0) {
                throw new Exception("Odd numbers of rows");
            }

            elements = new char[n][n];

            for (int i = 0; i < board.length; i++) {

                String row = board[i];
                if (row.length() != n) {
                    throw new Exception("Mismatching columns and rows size");
                }

                for (int j = 0; j < row.length(); j++) {

                    char element = row.charAt(j);
                    if (!isValidElement(element)) {
                        throw new Exception("Invalid element char: " + element);
                    }

                    elements[i][j] = element;
                }
            }
        }

        public String checkRegion(int level) throws Exception {

            int centerRow = (elements.length / 2) - 1;
            int regionFirstRow = centerRow - (level - 1);
            int regionLastRow = centerRow + level;
            int regionSize = level * 2;

            Map<Cell,Integer> scoreCount = new HashMap<>();

            for (int i = regionFirstRow; i <= regionLastRow; i ++) {
                for (int j = regionFirstRow; j <= regionLastRow; j++) {
                    if(isElementFromRegion(i,j,regionFirstRow,regionLastRow)) {
                        Cell cell = elementToCell(elements[i][j]);
                        //System.out.println("Cell [" + i + "][" + j + "] = " + cell);
                        if(cell != Cell.Empty) {
                            int count = getScore(scoreCount, cell);
                            scoreCount.put(cell, count + 1);
                        }
                    }
                }
            }

            int aliceScore = getScore(scoreCount, Cell.Alice);
            int bobScore = getScore(scoreCount, Cell.Bob);
            if (aliceScore > bobScore) {
                return "Alice";
            }
            else if (aliceScore < bobScore) {
                return "Bob";
            }
            return "Draw";
        }

        private int getScore(Map<Cell,Integer> scoreCount, Cell cell) {
            return scoreCount.containsKey(cell) ? scoreCount.get(cell) : 0;
        }

        private boolean isValidElement(char element) {

            switch(element) {

                case 'A':
                case 'B':
                case '.':
                    return true;

                default:
                    return false;
            }
        }

        private boolean isElementFromRegion(int i, int j, int firstRow, int lastRow) {

            if(i == firstRow || i == lastRow || j == firstRow || j == lastRow) {
                return true;
            }
            return false;
        }

        private Cell elementToCell(char element) throws Exception {

            switch(element) {
                case 'A': return Cell.Alice;
                case 'B': return Cell.Bob;
                case '.': return Cell.Empty;
                default : throw new Exception("Invalid element type");
            }
        }

        @Override
        public String toString() {

            if(elements == null || elements.length == 0) {
                return "[[]]";
            }

            String output = "";
            for (int i = 0; i < elements.length; i++) {

                if(i > 0) {
                    output += "\n";
                }

                output += "[";
                for (int j = 0; j < elements[i].length; j++) {
                    output += elements[i][j];
                }
                output += "]";
            }
            output += "\n";
            return output;
        }
    }
}