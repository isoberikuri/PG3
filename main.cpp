#include <chrono>
#include <fstream>
#include <iostream>
#include <mutex>
#include <sstream>
#include <thread>
#include <vector>

using namespace std;

vector<vector<int>> mapData;
bool loaded = false;

mutex mapMutex;
bool running = true;

void LoadCSV() {
    cout << "[BG] CSV Load Start" << endl;

    ifstream file("map.csv");
    string line;

    vector<vector<int>> tempMap;

    while (getline(file, line)) {
        stringstream ss(line);
        string value;
        vector<int> row;

        while (getline(ss, value, ',')) {
            row.push_back(stoi(value));
        }
        tempMap.push_back(row);
    }

    {
        lock_guard<mutex> lock(mapMutex);
        mapData = tempMap;
        loaded = true;
    }

    cout << "[BG] CSV Load Complete" << endl;
}

void MainLoop() {
    while (running) {
        if (loaded) {
            lock_guard<mutex> lock(mapMutex);

            system("cls");
            cout << "=== MAP ===" << endl;

            for (auto& row : mapData) {
                for (int chip : row) {
                    cout << chip << " ";
                }
                cout << endl;
            }
        } else {
            cout << "Loading..." << endl;
        }

        this_thread::sleep_for(chrono::milliseconds(500));
    }
}

int main() {

    thread bgThread(LoadCSV);
    thread mainThread(MainLoop);

    this_thread::sleep_for(chrono::seconds(5));
    running = false;

    bgThread.join();
    mainThread.join();

    cout << "終了" << endl;
    return 0;
}