#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    // Function to check if two strings are isomorphic
    bool isIsomorphic(std::string s, std::string t) {
        // Use an unordered_map to store the mapping from characters in 's' to characters in 't'.
        // This map will ensure each character from 's' has only one corresponding character in 't'.
        std::unordered_map<char, char> s_to_t_map;

        // Use another unordered_map to store the mapping from characters in 't' to characters in 's'.
        // This is crucial to ensure no two characters from 's' map to the same character in 't'.
        std::unordered_map<char, char> t_to_s_map;

        // Iterate through both strings simultaneously using a single loop.
        for (int i = 0; i < s.length(); ++i) {
            char s_char = s[i]; // Get the character from string 's'
            char t_char = t[i]; // Get the corresponding character from string 't'

            // Case 1: The character from 's' is already in our map.
            if (s_to_t_map.count(s_char)) {
                // Check if the existing mapping for 's_char' matches the current 't_char'.
                // If they don't match, it means 's_char' is trying to map to a different character,
                // violating the isomorphic property.
                if (s_to_t_map[s_char] != t_char) {
                    return false; // Not isomorphic
                }
            } 
            // Case 2: The character from 's' is new.
            else {
                // Check if the character from 't' is already a mapped value.
                // This prevents multiple 's' characters from mapping to the same 't' character.
                if (t_to_s_map.count(t_char)) {
                    return false; // Not isomorphic
                }
                
                // If both checks pass, establish a new mapping in both directions.
                s_to_t_map[s_char] = t_char;
                t_to_s_map[t_char] = s_char;
            }
        }

        // If the loop completes without finding any violations, the strings are isomorphic.
        return true;
    }
};