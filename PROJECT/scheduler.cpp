#include <bits/stdc++.h>
using namespace std;

struct Task {
    int id;
    string name;
    int priority;
    int deadline;
};

struct Compare {
    bool operator()(Task a, Task b) {
        if (a.priority == b.priority)
            return a.deadline > b.deadline;
        return a.priority < b.priority;
    }
};

priority_queue<Task, vector<Task>, Compare> pq;
unordered_map<int, Task> taskMap;

void saveToFile() {
    ofstream file("tasks.txt");
    for (auto &p : taskMap) {
        Task t = p.second;
        file << t.id << " " << t.name << " "
             << t.priority << " " << t.deadline << endl;
    }
}

void loadFromFile() {
    ifstream file("tasks.txt");
    Task t;
    while (file >> t.id >> t.name >> t.priority >> t.deadline) {
        taskMap[t.id] = t;
        pq.push(t);
    }
}

int main(int argc, char* argv[]) {
    loadFromFile();

    string cmd = argv[1];

    if (cmd == "add") {
        Task t;
        t.id = stoi(argv[2]);
        t.name = argv[3];
        t.priority = stoi(argv[4]);
        t.deadline = stoi(argv[5]);

        taskMap[t.id] = t;
        pq.push(t);
        saveToFile();

        cout << "Task Added";
    }

    else if (cmd == "execute") {
        if (pq.empty()) {
            cout << "No tasks";
            return 0;
        }

        Task t = pq.top();
        pq.pop();
        taskMap.erase(t.id);
        saveToFile();

        cout << t.name;
    }

    else if (cmd == "view") {
        for (auto &p : taskMap) {
            Task t = p.second;
            cout << t.id << " "
                 << t.name << " "
                 << t.priority << " "
                 << t.deadline << endl;
        }
    }

    return 0;
}