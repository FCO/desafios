/*
    Problem url: https://arena.topcoder.com/#/u/practiceCode/1626/4170/4512/2/1626

    Problem Statement:

        An abacus can be used to do arithmetic. The version that we have has 6 horizontal rows, each with nine beads on it. The beads on each row are always arranged with just one gap, possibly at one of the ends. However many beads are adjacent and at the right end of the row is the digit value of the row. The value on the abacus is read by taking the digits in order from top row to bottom row and arranging them from left to right (so the top row is the one that contains the most significant digit).

        Create a class Abacus that contains a method add that is given a String[] original and a number val and that returns a String[] showing the abacus after val has been added to the original abacus.

        Both in original and in the return, the String[] will contain exactly 6 elements representing the 6 rows in order from top row to bottom row. Each element will contain a lowercase 'o' to represent each bead and three consecutive hyphens '-' to indicate the empty part of the row. Each element will thus contain exactly 12 characters.

    Definition:

        Class:
        Abacus

        Method:
        add

        Parameters:
        String[], int

        Returns:
        String[]

        Method signature:
        String[] add(String[] original, int val)
        (be sure your method is public)

        Limits:
        Time limit (s):
        840.000
        Memory limit (MB):
        64

    Constraints:

        - original will contain exactly 6 elements.
        - Each element of original will contain exactly 12 characters, 9 lowercase 'o's and 3 consecutive '-'s.
        - val will be between 0 and 999,999 inclusive.
        - val added to the original abacus will result in a value that can be shown on the abacus.

    Examples:

        0)
        {"ooo---oooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "oo---ooooooo", "---ooooooooo"}
        5
        Returns: {"ooo---oooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "o---oooooooo", "ooooo---oooo" }
        When we add 5 to the original, it is necessary to "carry" 1 to the next row up. This shows the arithmetic 699979 + 5 = 699984

        1)
        {"ooo---oooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "oo---ooooooo", "---ooooooooo"}
        21
        Returns: {"oo---ooooooo", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---" }
        This shows 699979 + 21 = 700000

        2)
        {"ooooooooo---", "---ooooooooo", "ooooooooo---", "---ooooooooo", "oo---ooooooo", "---ooooooooo"}
        100000
        Returns: {"oooooooo---o", "---ooooooooo", "ooooooooo---", "---ooooooooo", "oo---ooooooo", "---ooooooooo" }

        3)
        {"o---oooooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo", "---ooooooooo" }
        1
        Returns: {"---ooooooooo", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---", "ooooooooo---" }
*/

public class Abacus {

    private final int TOTAL_ROWS = 6;
    private final int MAX_ROWS_COUNT = 9;
    private int[] rows;

    // This should be commented out during submission
    public static void main(String[] args) throws Exception {

        Abacus abacus = new Abacus();

        String[] rows = new String[args.length - 1];
        for (int i = 0; i < (args.length - 1); i++) {
            rows[i] = args[i];
        }
        int value = Integer.parseInt(args[args.length - 1]);

        String[] result = abacus.add(rows, value);
        for (String row : result) {
            System.out.println(row);
        }
    }

    public Abacus() {

        rows = new int[6];
    }

    public String[] add(String[] original, int val) {

        parseRows(original);
        for (int i = 0; i < TOTAL_ROWS; i++) {
            //System.out.println(rows[i]);
        }
        return processAddOperation(val);
    }

    private void parseRows(String[] rowStrs) {

        for (int i = 0; i < rowStrs.length; i++) {
            rows[i] = rowStrToInt(rowStrs[i]);
        }
    }

    private int rowStrToInt(String rowStr) {

        for (int i = 0; i < rowStr.length(); i++) {
            if(rowStr.charAt(i) == '-') {
                return MAX_ROWS_COUNT - i;
            }
        }

        // Error, should never happen
        return -1;
    }

    private String rowIntToStr(int value) {

        String rowStr = "";
        for (int i = 0; i <= MAX_ROWS_COUNT; i++) {
            if(i == value) {
                rowStr = "---" + rowStr;
            } else {
                rowStr = "o" + rowStr;
            }
        }
        return rowStr;
    }

    private String[] processAddOperation(int addValue) {

        String[] output = new String[TOTAL_ROWS];

        int addToNext = 0;
        // We go bottom up
        for (int i = TOTAL_ROWS - 1; i >= 0; i--) {

            int rowValue = rows[i];
            int result = rowValue;

            // only add on first row
            if(i == TOTAL_ROWS - 1) {
                result += addValue;
            }

            if(addToNext > 0) {
                result += addToNext;
                addToNext = 0;
            }

            if(result > MAX_ROWS_COUNT) {
                addToNext = result / (MAX_ROWS_COUNT+1);
                result = result % (MAX_ROWS_COUNT+1);
            }

            //System.out.println("row = " + i + " with " + rowValue + " becomes " + result + "add passes " + addToNext);

            output[i] = rowIntToStr(result);
            //System.out.println(output[i]);
        }

        return output;
    }
}