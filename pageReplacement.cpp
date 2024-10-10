#include <bits/stdc++.h>
using namespace std;

void printTable(const vector<int> &frames, int page, bool pageFault) {
    cout << "|   " << page << "    |";
    for (int frame : frames) {
        if (frame != -1)
            cout << "   " << frame << "   |";
        else
            cout << "       |";
    }
    cout << "     " << (pageFault ? "Yes" : "No") << "     \n";
}

void fifoPageReplacement(int pages[], int n, int capacity) {
    vector<int> frames(capacity, -1);
    int index = 0, pageFaults = 0;

    cout << "\nFIFO Page Replacement Algorithm\n";
    cout << "+--------+";
    for (int i = 0; i < capacity; i++) {
        cout << " Frame " << i + 1 << " +";
    }
    cout << " Page Faults +\n";
    cout << "+--------+";
    for (int i = 0; i < capacity; i++) {
        cout << "---------+";
    }
    cout << "-------------+\n";

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool pageFault = true;

        for (int j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                pageFault = false;
                break;
            }
        }

        if (pageFault) {
            frames[index] = page;
            index = (index + 1) % capacity;  
            pageFaults++;
        }

        printTable(frames, page, pageFault);
    }

    cout << "Total Page Faults: " << pageFaults << "\n\n";
}

int predict(int pages[], vector<int> &frames, int n, int index) {
    int res = -1, farthest = index;
    for (int i = 0; i < frames.size(); i++) {
        int j;
        for (j = index; j < n; j++) {
            if (frames[i] == pages[j]) {
                if (j > farthest) {
                    farthest = j;
                    res = i;
                }
                break;
            }
        }
        if (j == n) return i;
    }
    return res == -1 ? 0 : res;
}

void optPageReplacement(int pages[], int n, int capacity) {
    vector<int> frames(capacity, -1);
    int pageFaults = 0;

    cout << "\nOPT Page Replacement Algorithm\n";
    cout << "+--------+";
    for (int i = 0; i < capacity; i++) {
        cout << " Frame " << i + 1 << " +";
    }
    cout << " Page Faults +\n";
    cout << "+--------+";
    for (int i = 0; i < capacity; i++) {
        cout << "---------+";
    }
    cout << "-------------+\n";

    for (int i = 0; i < n; i++) {
        int page = pages[i];
        bool pageFault = true;

        for (int j = 0; j < capacity; j++) {
            if (frames[j] == page) {
                pageFault = false;
                break;
            }
        }

        if (pageFault) {
            if (i < capacity) {
                frames[i] = page;
            } else {
                int victim = predict(pages, frames, n, i + 1);
                frames[victim] = page;
            }
            pageFaults++;
        }

        printTable(frames, page, pageFault);
    }

    cout << "Total Page Faults: " << pageFaults << "\n\n";
}

int main() {
    int n, capacity;

    cout << "Enter the number of pages: ";
    cin >> n;

    int pages[n];
    cout << "Enter the page reference string (space-separated): ";
    for (int i = 0; i < n; i++) {
        cin >> pages[i];
    }

    cout << "Enter the number of frames: ";
    cin >> capacity;

    fifoPageReplacement(pages, n, capacity);
    optPageReplacement(pages, n, capacity);

    return 0;
}
