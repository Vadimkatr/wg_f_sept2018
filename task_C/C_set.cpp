#include <iostream>
#include <set>
#include <list>
#include <string>
#include <iterator>
/**
 * For this task I will use 3 implementation:
 * 1) use set and list;
 * 2) use unordered_set and list;
 * 3) use only list.
 * Set and unordered_set: find in set works for O(lgn), but find in unordered_set - works for O(1), 
 * for hashtable comes from the assumption that there are no collision. 
 * 
 * Case 1:
 * Total complexity will be O(n lgn) (but we will lose by memory).
 */

/**
 * Chat location calculation.
 * @param n Number of messages.
 */
void calculateChatLocation (const int n) {
    std::list<std::string> chats; // chat list
    std::set<std::string> names; // chat list, where we will use "find"
    std::string s;
    std::set<std::string>::iterator findName; // iterator to set<list> names

    for (int i = 0; i < n; i ++) {
        std::cin >> s;
        // find chat in set
        findName = names.find(s);
        if (findName == names.end()) { // if not found - add chat to the set and list
                chats.push_front(s);
                names.insert(s);
        } else { // remove chat from chats, and add again
            chats.remove(s);
            chats.push_front(s);
        }
    }

    for (std::list<std::string>::iterator iter = chats.begin(); iter != chats.end(); ++iter) {
        std::cout << *iter << std::endl;
    }
}

int main() {
    int n;
    std::cin >> n;

    calculateChatLocation(n);

    return 0;
}