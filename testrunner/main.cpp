#include "/Users/Popan/Dropbox/CPPProjects/CPPProjects/tasks/CodeForces/R318/TaskB.cpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <cctype>
#include <ctime>

namespace jhelper {

struct Test {
    std::string input;
    std::string output;
    bool active;
};

bool check(std::string expected, std::string actual) {
    while(!expected.empty() && isspace(*--expected.end()))
        expected.erase(--expected.end());
    while(!actual.empty() && isspace(*--actual.end()))
        actual.erase(--actual.end());
    return expected == actual;
}

} // namespace jhelper

int main() {
    std::vector<jhelper::Test> tests = {
        {"6\n2 1 4 6 2 2\n", "3\n", true},{"7\n3 3 3 1 3 3 3\n", "2\n", true},{"1\n1000000", "1", true},{"2\n5 2", "1", true},{"3\n3 2 1", "2", true},{"4\n4 3 2 1", "2", true},{"6\n1 1 1 1 1 1", "1", true},{"6\n2 2 2 2 2 2", "2", true},{"6\n15 15 15 15 15 15 ", "3", true},
    };
    bool allOK = true;
    int testID = 0;
    std::cout << std::fixed;
    double maxTime = 0.0;
    for(const jhelper::Test& test: tests ) {
        std::cout << "Test #" << ++testID << std::endl;
        std::cout << "Input: \n" << test.input << std::endl;
        std::cout << "Expected output: \n" << test.output << std::endl;
        if (test.active) {
            std::stringstream in(test.input);
            std::ostringstream out;
            std::clock_t start = std::clock();
            TaskB solver;
            solver.solve(in, out);
            std::clock_t finish = std::clock();
            double currentTime = double(finish - start) / CLOCKS_PER_SEC;
            maxTime = std::max(currentTime, maxTime);
            std::cout << "Actual output: \n" << out.str() << std::endl;
            bool result = jhelper::check(test.output, out.str());
            allOK = allOK && result;
            std::cout << "Result: " << (result ? "OK" : "Wrong answer") << std::endl;
            std::cout << "Time: " << currentTime << std::endl;
        }
        else {
            std::cout << "SKIPPED\n";
        }

        std::cout << std::endl;

    }
    if(allOK) {
        std::cout << "All OK" << std::endl;
    }
    else {
        std::cout << "Some cases failed" << std::endl;
    }
    std::cout << "Maximal time: " << maxTime << "s." << std::endl;
    return 0;
}
