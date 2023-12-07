#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool compareJobs(const Job& job1, const Job& job2) {
    return (job1.profit > job2.profit);
}

void jobSequencing(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compareJobs);

    int n = jobs.size();
    vector<char> result(n, ' ');
    vector<bool> slot(n, false);

    for (int i = 0; i < n; ++i) {
        for (int j = min(n, jobs[i].deadline) - 1; j >= 0; --j) {
            if (!slot[j]) {
                result[j] = jobs[i].id;
                slot[j] = true;
                break;
            }
        }
    }

    cout << "Job Sequence: ";
    for (int i = 0; i < n; ++i) {
        if (slot[i]) {
            cout << result[i] << " ";
        }
    }
    cout << endl;
}

int main() {
    vector<Job> jobs = {
        {'a', 2, 100},
        {'b', 1, 19},
        {'c', 2, 27},
        {'d', 1, 25},
        {'e', 3, 15}
    };

    cout << "Jobs before sequencing:\n";
    for (const auto& job : jobs) {
        cout << "Job " << job.id << ": Deadline=" << job.deadline << ", Profit=" << job.profit << "\n";
    }

    jobSequencing(jobs);

    return 0;
}
