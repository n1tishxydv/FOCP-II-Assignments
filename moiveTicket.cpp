#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class MovieTicket {
private:
    unordered_map<int, unordered_set<int>> movieBookings;
    unordered_map<int, unordered_set<int>> customerBookings;
    const int totalSlots = 100;

public:
    bool BOOK(int X, int Y) {
        auto movieIt = movieBookings.find(Y);
        if (movieIt != movieBookings.end() && movieIt->second.size() >= totalSlots) {
            return false;
        }
        auto custIt = customerBookings.find(X);
        if (custIt != customerBookings.end() && custIt->second.find(Y) != custIt->second.end()) {
            return false;
        }
        movieBookings[Y].insert(X);
        customerBookings[X].insert(Y);
        return true;
    }

    bool CANCEL(int X, int Y) {
        auto it = customerBookings.find(X);
        if (it == customerBookings.end() || it->second.find(Y) == it->second.end()) {
            return false;
        }
        auto movieIt = movieBookings.find(Y);
        if (movieIt != movieBookings.end()) {
            movieIt->second.erase(X);
        }
        it->second.erase(Y);
        return true;
    }

    bool IS_BOOKED(int X, int Y) {
        auto it = customerBookings.find(X);
        if (it == customerBookings.end()) {
            return false;
        }
        return it->second.find(Y) != it->second.end();
    }

    int AVAILABLE_TICKETS(int Y) {
        auto it = movieBookings.find(Y);
        if (it == movieBookings.end()) {
            return totalSlots;
        }
        return totalSlots - it->second.size();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int Q;
    cin >> Q;
    MovieTicket mt;
    
    for (int i = 0; i < Q; i++) {
        string query;
        cin >> query;
        
        if (query == "BOOK") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.BOOK(X, Y) ? "true" : "false") << "\n";
        } else if (query == "CANCEL") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.CANCEL(X, Y) ? "true" : "false") << "\n";
        } else if (query == "IS_BOOKED") {
            int X, Y;
            cin >> X >> Y;
            cout << (mt.IS_BOOKED(X, Y) ? "true" : "false") << "\n";
        } else if (query == "AVAILABLE_TICKETS") {
            int Y;
            cin >> Y;
            cout << mt.AVAILABLE_TICKETS(Y) << "\n";
        }
    }
    
    return 0;
}