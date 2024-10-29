# PA1

Q1
Consider the 3-byte sequence 11100000 10000000 10100001.
Answer the following questions:
What code point does it encode in UTF-8, and what character is that?
1110 = 3 start byte
10 means continuing byte
Let’s encode it:
11100000 10000000 10100001
0000 000000 100001
0000 0000 0010 0001 =  U+0021 = “!”

Q2
What are the three other ways to encode that character?
1.One byte 
 01010001  
2.Two byte
 11000000 10100001
3.Four byte
 11110000 10000000 10000000 10100001

Q3
Give an example of a character that has exactly three encodings (but not four, like the one in the previous example does)
For example:é
1.can not be one byte character
2.Two byte
11000011 1010 1001
3.Three byte
11100000 10000011 10101001
4.Four byte
11110000 10000000 10000011 10101001

Q4
What are some problems with having these multiple encodings, especially for ASCII characters?
A web search for “overlong UTF-8 encoding” may be useful here.
Code point requirements for each UTF8 encoding type
1 Byte encoding:
Bits required for code point: 7 bits
2 Bytes encoding:
Bits required for code point: 8~11 bits
3 Bytes encoding:
Bits required for code point: 12~16 bits
4 Byte encoding:
Bits required for code point: 17~21 bits
