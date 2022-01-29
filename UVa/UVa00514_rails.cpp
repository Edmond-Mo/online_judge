#include <iostream>
#include <stack>
using namespace std;

int main() {
    cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
    while (1) {
        int n;
        cin >> n;
        if (n == 0)
            break;
        int train[n];
        while (1) {
            int id;
            bool done = false;
            for (int i = 0; i < n; i++) {
                cin >> id;
                if (id == 0) {
                    done = true;
                    break;
                }
                train[i] = id;
            }
            if (done) break;

            std::stack<int> station; 
            int loc = 0;
            int k = 1; // current train coach id
            while (loc < n) {
                // if current incoming train order (k)
                // matches with the desired output train
                // order, push&pop instantaneouesly (bascially
                // means not using stack, just pass through)
                if (train[loc] == k) {
                    loc++;
                    k++;
                }
                // if not, then need to either pop the top of the
                // station/stack if the top(s) match with the desired
                // output train order.
                // if stack is empty or top not matching, need to push
                // input train into stack.
                else {
                    while (!station.empty()) {
                        int t = station.top();
                        if (t != train[loc])
                            break;
                        station.pop();
                        loc++;
                    }
                    station.push(k);
                    k++;
                }

                if (k > n && !station.empty() && station.top() != train[loc])
                    break;
            }

            if (loc == n) {
                cout << "Yes\n";
            }
            else {
                cout << "No\n";
            }
        }
        cout << "\n";
    }    
    return 0;
}
