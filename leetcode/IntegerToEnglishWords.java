/*
    https://leetcode.com/problems/integer-to-english-words/

    Convert a non-negative integer to its english words representation. Given input is guaranteed to be less than 231 - 1.

    Example 1:

    Input: 123
    Output: "One Hundred Twenty Three"

    Example 2:

    Input: 12345
    Output: "Twelve Thousand Three Hundred Forty Five"

    Example 3:

    Input: 1234567
    Output: "One Million Two Hundred Thirty Four Thousand Five Hundred Sixty Seven"

    Example 4:

    Input: 1234567891
    Output: "One Billion Two Hundred Thirty Four Million Five Hundred Sixty Seven Thousand Eight Hundred Ninety One"

*/
class Solution {
    public String numberToWords(int num) {

        if(num == 0) {
            return "Zero";
        }

        int scaleIdx = 0;
        String[] scale = new String[]{null, "Thousand", "Million", "Billion"};

        String result = "";
        while(num > 0) {

            String level = "";
            int units = num % 1000;
            if(units != 0) {
                level = hundredToWord(units);

                if(scale[scaleIdx] != null) {
                    level += " " + scale[scaleIdx];
                }

                if(result != "") level += " ";
                result = level + result;
            }

            num /= 1000;
            scaleIdx++;
        }

        return result;
    }

    private String hundredToWord(int num) {

        String result = "";
        int hundreds = num / 100;
        if(hundreds > 0) {
            result = digitToWord(hundreds) + " Hundred";
        }

        int tens = num % 100;
        if(tens > 0) {
            if(!result.isEmpty()) {
                result += " ";
            }
            result += tensToWord(tens);
        }

        return result;
    }

    private String tensToWord(int num) {

        String result = "";
        int tens = num / 10;
        if(tens > 0) {
            switch(tens) {
                case 2: result = "Twenty";  break;
                case 3: result = "Thirty";  break;
                case 4: result = "Forty";   break;
                case 5: result = "Fifty";   break;
                case 6: result = "Sixty";   break;
                case 7: result = "Seventy"; break;
                case 8: result = "Eighty";  break;
                case 9: result = "Ninety";  break;

                case 1:
                    switch(num) {
                        case 10: return "Ten";
                        case 11: return "Eleven";
                        case 12: return "Twelve";
                        case 13: return "Thirteen";
                        case 14: return "Fourteen";
                        case 15: return "Fifteen";
                        case 16: return "Sixteen";
                        case 17: return "Seventeen";
                        case 18: return "Eighteen";
                        case 19: return "Nineteen";
                    }

                default: break;
            }
        }

        int singleDigit = num % 10;
        if(singleDigit == 0) {
            return result;
        }

        if(!result.isEmpty()) {
            result = result + " ";
        }

        result += digitToWord(num);
        return result;
    }

    private String digitToWord(int num) {

        int singleDigit = num % 10;
        switch(singleDigit) {
            case 1: return "One";
            case 2: return "Two";
            case 3: return "Three";
            case 4: return "Four";
            case 5: return "Five";
            case 6: return "Six";
            case 7: return "Seven";
            case 8: return "Eight";
            case 9: return "Nine";
            case 0: return "Zero";
        }

        return null;
    }
}