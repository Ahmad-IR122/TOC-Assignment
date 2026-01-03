#include <iostream>
#include <string>
#include <regex>
#include <fstream>
using namespace std;

int main()
{
    ifstream file("input.txt");
    string line, updatedContent = "";

    if (!file.is_open()) {
        cout << "Error opening file" << endl;
        return 1;
    }

    int numberOfLine;
    cout << "Enter line number: ";
    cin >> numberOfLine;

    regex failRegex(R"(\bfail(s|ed|ing|ure|ures)?\b)", regex_constants::icase);
    regex firstWordRegex(R"(^\s*fail(s|ed|ing|ure|ures)?\b)", regex_constants::icase);

    int currentLine = 1;
    int counterOfFails = 0;
    int totalNumberOfOccurrences = 0;

    int maxFailsInLine = 0;
    string maxFailLines = "";
    string firstWordLines = "";

    while (getline(file, line)) {

        int failsInThisLine = 0;

        if (regex_search(line, firstWordRegex)) {
            if (!firstWordLines.empty())
                firstWordLines += ", ";
            firstWordLines += to_string(currentLine);
        }

        sregex_iterator it(line.begin(), line.end(), failRegex);
        sregex_iterator end;

        while (it != end) {
            totalNumberOfOccurrences++;
            failsInThisLine++;

            if (currentLine == numberOfLine) {
                counterOfFails++;
            }
            ++it;
        }

        if (failsInThisLine > maxFailsInLine) {
            maxFailsInLine = failsInThisLine;
            maxFailLines = to_string(currentLine);
        }
        else if (failsInThisLine == maxFailsInLine && failsInThisLine > 0) {
            maxFailLines += ", " + to_string(currentLine);
        }

      
        line = regex_replace(line, failRegex, "$&");
        for (char& c : line) c = toupper(c);

        updatedContent += line + "\n";
        currentLine++;
    }

    file.close();

    ofstream outFile("input.txt");
    outFile << updatedContent;
    outFile.close();

    if (numberOfLine >= currentLine) {
        cout << "Line number out of range\n";
        return 1;
    }
    else {
        cout << "Occurrences in line " << numberOfLine
            << " is " << counterOfFails << endl;
    }

    cout << "Total occurrences in entire file: "
        << totalNumberOfOccurrences << endl;

    cout << "Line number(s) with highest number of failures ("
        << maxFailsInLine << "): "
        << maxFailLines << endl;

    cout << "Line numbers where failure word is first: "
        << firstWordLines << endl;

    cout << "File updated: all fail-related words converted to UPPERCASE\n";

    return 0;
}
