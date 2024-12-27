#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
void createDataFile(const string& filename) {
    ofstream dataFile(filename, ios::out);
    if (!dataFile.is_open()) {
        cerr << "Failed to open data file!" << endl;
        return;
    }
    dataFile << "1 John Doe\n";
    dataFile << "2 Jane Smith\n";
    dataFile << "3 Alice Johnson\n";
    dataFile.close();
    cout << "Data file created." << endl;
}
void createIndexFile(const string& dataFilename, const string& indexFilename) {
    ifstream dataFile(dataFilename, ios::in);
    ofstream indexFile(indexFilename, ios::out);
    if (!dataFile.is_open() || !indexFile.is_open()) {
        cerr << "Failed to open files!" << endl;
        return;
    }
    string line;
    long offset = 0;
    while (getline(dataFile, line)) {
        istringstream iss(line);
        int id;
        if (iss >> id) {
            indexFile << id << " " << offset << endl;
        }
        offset += line.size() + 1;
    }
    dataFile.close();
    indexFile.close();
    cout << "Index file created." << endl;
}
void searchRecord(const string& dataFilename, const string& indexFilename, int searchId) {
    ifstream dataFile(dataFilename, ios::in);
    ifstream indexFile(indexFilename, ios::in);
    if (!dataFile.is_open() || !indexFile.is_open()) {
        cerr << "Failed to open files!" << endl;
        return;
    }
    string line;
    while (getline(indexFile, line)) {
        istringstream iss(line);
        int id;
        long offset;
        if (iss >> id >> offset) {
            if (id == searchId) {
                dataFile.seekg(offset, ios::beg);
                getline(dataFile, line);
                cout << "Record found: " << line << endl;
                break;
            }
        }
    }
    dataFile.close();
    indexFile.close();
}
int main() {
    const string dataFilename = "data.txt";
    const string indexFilename = "index.txt";
    int searchId = 2; // ID we want to find
    createDataFile(dataFilename);
    createIndexFile(dataFilename, indexFilename);
    searchRecord(dataFilename, indexFilename, searchId);
    return 0;
}
