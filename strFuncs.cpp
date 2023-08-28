#include "strFuncs.h"
#include <cctype>

using namespace std;


/* Precondition: s1 is a valid string that may contain upper or lower case alphabets, no spaces or special characters
 * Postcondition: Returns true if s1 is a palindrome, false otherwise
 *
 * Palindromes are NOT case-sensitive - "RaCecaR" is a valid palindrome
 *
 *You should provide a recursive solution*/
bool isPalindrome(const string s1){
    if (s1.length() <= 1) { // if length of string is 0 0r 1
        return true;    // then return true
    } else {
        char first = s1[0];   // get first character
        char last = s1[s1.length()-1];   // get last character
        if (first >= 'A' && first <= 'Z')   // if first character is uppercase
            first = first - 'A' + 'a';  // change it to lowercase
        if (last >= 'A' && last <= 'Z')   // if last character is uppercase
            last = last - 'A' + 'a';  // change it to lowercase
        return first == last && isPalindrome(s1.substr(1, s1.length()-2)); // recursive check if rest of the string is a palindrome
    }
}
