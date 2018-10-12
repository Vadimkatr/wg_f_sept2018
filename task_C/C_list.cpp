#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include <algorithm>
/**
 * For this task I will use 3 implementation:
 * 1) use set and list;
 * 2) use unordered_set and list;
 * 3) use only list.
 * Set and unordered_set: find in set works for O(lgn), but find in unordered_set - works for O(1), 
 * for hashtable comes from the assumption that there are no collision. 
 * 
 * Case 3:
 * Total complexity will be O(n^2).
 */

/**
 * Chat location calculation.
 * @param n Number of messages.
 */
void calculateChatLocation (const int n) {
    std::list<std::string> chats; // chat list
    std::string s;
    std::list<std::string>::iterator findName; // iterator to set<list> names

    for (int i = 0; i < n; i ++) {
        std::cin >> s;
        // find chat in setx
        findName = find(chats.begin(), chats.end(), s);
        if (findName == chats.end()) { // if not found - add chat to the list
                chats.push_front(s);
        } else { // remove chat from chats, and add again
            chats.erase(findName);
            chats.push_front(s);
        }
    }
    
    // try use copy for output ??)
    copy(chats.begin(), chats.end(), std::ostream_iterator<std::string>(std::cout, "\n"));
}

int main() {
    int n;
    std::cin >> n;

    calculateChatLocation(n);

    return 0;
}