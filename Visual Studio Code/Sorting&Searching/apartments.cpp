#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int allocate_apartments(int n, int m, int k, vector<int>& applicants, vector<int>& apartments) {
    sort(applicants.begin(), applicants.end());
    sort(apartments.begin(), apartments.end());

    int i = 0, j = 0;
    int allocated = 0;

    while (i < n && j < m) {
        if (apartments[j] < applicants[i] - k) {
            j++;  // Apartment is too small for this applicant
        } else if (apartments[j] > applicants[i] + k) {
            i++;  // Applicant wants a smaller apartment
        } else {
            // Suitable apartment found for this applicant
            allocated++;
            i++;
            j++;
        }
    }

    return allocated;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    vector<int> applicants(n);
    vector<int> apartments(m);

    for (int i = 0; i < n; i++) {
        cin >> applicants[i];
    }

    for (int i = 0; i < m; i++) {
        cin >> apartments[i];
    }

    int result = allocate_apartments(n, m, k, applicants, apartments);
    cout << result << endl;

    return 0;
}
