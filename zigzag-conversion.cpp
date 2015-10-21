/*****************************************************************************
URL: https://leetcode.com/problems/zigzag-conversion/

The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of
rows like this:

P   A   H   N
A P L S I I G
Y   I   R

And then read line by line: "PAHNAPLSIIGYIR"

Write the code that will take a string and make this conversion given a number
of rows:

    // convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR". 
    string convert(string text, int nRows);

*****************************************************************************/

#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

class Solution
{
public:

    string convert(string s, int nRows)
    {
    	if(s.size() < 2 || nRows == 1)
    		return s;

        string output = s;

        setupData(s, nRows);

        for(unsigned int i = 0; i < s.size(); i++)
        {
        	int row = getRow(i, nRows);
        	int pos = (row == 0 ? 0 : _rowSums[row-1]);

        	int currentBlock = i / _blockSize;
        	pos += (currentBlock) * (row == 0 || row == (nRows-1) ? 1 : 2);

        	int currentIncomplete = i % _blockSize;
        	pos += (currentIncomplete > row ? 1 : 0);
        	pos += (currentIncomplete > nRows && 
                    currentIncomplete - nRows + row >= (nRows - 1) ? 1 : 0);

        	output[pos] = s[i];
        }

        return string(output);
    }

private:

	void setupData(string s, int nRows)
	{
		_blockSize = nRows + (nRows-2);
		_numBlocks = s.size() / _blockSize;
		_incompleteBlockSize = s.size() % _blockSize;

		_rowSums.clear();
		for(int i = 0; i < nRows; i++)
		{
			if(i == 0 )
			{
				int rowCount = _numBlocks + (_incompleteBlockSize != 0 ? 1 : 0);
				_rowSums.push_back( rowCount );
			}
			else if(i != (nRows-1))
			{
				int rowCount = (_numBlocks * 2);
				rowCount += (_incompleteBlockSize > i ? 1 : 0);
				rowCount += (_incompleteBlockSize > nRows && 
                       _incompleteBlockSize - nRows + i >= (nRows - 1) ? 1 : 0);

				_rowSums.push_back( rowCount + _rowSums[i-1] );
			}
		}
	}

	int getRow(int pos, int nRows)
	{
		int currentIncomplete = pos % _blockSize;
		if(currentIncomplete < nRows)
			return currentIncomplete;
		else
			return (_blockSize - nRows) - (currentIncomplete - nRows);
	}

private:

	int _blockSize;
	int _numBlocks;
	int _incompleteBlockSize;

	vector<int> _rowSums;
};

//***************************************************//
//************ Main for offline testing *************//
//***************************************************//

int main(void)
{
	Solution* solution = new Solution();
	string input = "PAYPALISHIRINGPAYPALISHIRIN";
	string result = solution->convert( input, 3);

	printf("%s", result.c_str() );

	return 1;
}
