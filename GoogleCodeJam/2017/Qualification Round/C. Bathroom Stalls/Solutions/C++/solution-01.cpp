#include <iostream>
#include <map>

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int tests;
    std::cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        int64_t stalls, people;
        std::cin >> stalls >> people;
        std::map<int64_t, int64_t> bathroom;
        bathroom.insert(std::make_pair(stalls, (int64_t) 1));
        while (people > 0) {
            auto it = bathroom.end();
            it--;
            int64_t small_stalls = it->first;
            int64_t count = it->second;
            if (count >= people) {
                people = 0;
            } else {
                people -= count;
                bathroom.erase(it);
                if (small_stalls % 2 != 0) {
                    if (bathroom.find(small_stalls / 2) != bathroom.end()) {
                        bathroom[small_stalls / 2] += 2 * count;
                    } else {
                        bathroom.insert(
                            std::make_pair(small_stalls / 2, 2 * count));
                    }
                } else {
                    if (bathroom.find(small_stalls / 2) != bathroom.end()) {
                        bathroom[small_stalls / 2] += count;
                    } else {
                        bathroom.insert(
                            std::make_pair(small_stalls / 2, count));
                    }
                    if (bathroom.find(small_stalls / 2 - 1) != bathroom.end()) {
                        bathroom[small_stalls / 2 - 1] += count;
                    } else {
                        bathroom.insert(
                            std::make_pair(small_stalls / 2 - 1, count));
                    }
                }
            }
        }
        auto it = bathroom.end();
        it--;
        int64_t small_stalls = it->first;
        int64_t min = (small_stalls % 2) != 0 ? small_stalls / 2 :
                      small_stalls / 2 - 1;
        std::cout << "Case #" << test << ": " << small_stalls / 2 << " " << min
                  << std::endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
