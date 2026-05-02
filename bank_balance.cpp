#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Bank {
private:
    unordered_map<string, long long> accounts;

public:
    bool CREATE(string X, long long Y) {
        if (accounts.find(X) != accounts.end()) {
            accounts[X] += Y;
            return false;
        }
        accounts[X] = Y;
        return true;
    }

    bool DEBIT(string X, long long Y) {
        if (accounts.find(X) == accounts.end()) return false;
        if (accounts[X] < Y) return false;
        accounts[X] -= Y;
        return true;
    }

    bool CREDIT(string X, long long Y) {
        if (accounts.find(X) == accounts.end()) return false;
        accounts[X] += Y;
        return true;
    }

    long long BALANCE(string X) {
        if (accounts.find(X) == accounts.end()) return -1;
        return accounts[X];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q;
    cin >> Q;

    Bank bank;
    string query;
    string user_id;
    long long amount;

    for (int i = 0; i < Q; i++) {
        cin >> query;
        if (query == "CREATE") {
            cin >> user_id >> amount;
            bool result = bank.CREATE(user_id, amount);
            cout << (result ? "true" : "false") << "\n";
        } else if (query == "DEBIT") {
            cin >> user_id >> amount;
            bool result = bank.DEBIT(user_id, amount);
            cout << (result ? "true" : "false") << "\n";
        } else if (query == "CREDIT") {
            cin >> user_id >> amount;
            bool result = bank.CREDIT(user_id, amount);
            cout << (result ? "true" : "false") << "\n";
        } else if (query == "BALANCE") {
            cin >> user_id;
            long long result = bank.BALANCE(user_id);
            cout << result << "\n";
        }
    }

    return 0;
}
