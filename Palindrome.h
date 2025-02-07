#ifndef PALINDROME_H
#define PALINDROME_H

#include <string>
#include <algorithm>
#include <cctype>
#include <iostream>

class Palindrome {
public:
    Palindrome(const std::string& sent) : sentence(sent) {}

    bool isPalindrome() const {
        std::string cleanedSentence = stripSentence(); 

        std::string reversedSentence = cleanedSentence;

        std::reverse(reversedSentence.begin(), reversedSentence.end()); 

        return cleanedSentence == reversedSentence;
    }

    friend std::ostream& operator<<(std::ostream& out, const Palindrome& p) {

        out << "original sentence - " << p.sentence << std::endl;

        out << "stripped sentence - " << p.stripSentence() << std::endl;

        out << "is this a palindrome - " << (p.isPalindrome() ? "yes" : "no") << std::endl;

        return out;
    }

private:
    std::string sentence;

    std::string stripSentence() const {

        std::string cleaned;

        for (char c : sentence) {

            if (std::isalnum(c)) {

                cleaned += std::tolower( c );

            }

        }

        return cleaned;
    }
};

#endif