#include <bits/stdc++.h>

using namespace std;

#define IO                            \
    freopen("../../../input.txt", "r", stdin); \
    freopen("../../../output.txt", "w", stdout);

struct car {
    string name = "";
    int catalog = 0;
    int pickup = 0;
    int mileage_cost = 0;
};

struct spy {
    string name = "";
    bool has_car = false;
    car *c;
    bool inconsistent = false;
    long long bill = 0;
};

unordered_map<string, car*> cars;
map<int, string> events;
map<string, spy*> spies;

void read_event(string s) {
    vector<string> v;
    char delim = ' ';
    string tmp;
    stringstream ss(s);
    while(getline(ss, tmp, delim)) {
        v.push_back(tmp);
    }
    string name = v[0];
    if (!spies.count(name)) {
        spy *sp = new spy();
        sp->name = name;
        spies[name] = sp;
    }
    string event = v[1];

    if (event == "p") {
        string car_name = v[2];
        if (!cars.count(car_name) || spies[name]->has_car || spies[name]->inconsistent) {
            spies[name]->inconsistent = true;
            return;
        }
        spies[name]->has_car = true;
        spies[name]->bill += cars[car_name]->pickup;
        spies[name]->c = cars[car_name];
    } else if (event == "r") {
        if (!spies[name]->has_car || spies[name]->inconsistent) {
            spies[name]->inconsistent = true;
            return;
        }
        int d = stoi(v[2]);
        spies[name]->bill += d * spies[name]->c->mileage_cost;
        spies[name]->has_car = false;
    } else if (event == "a") {
        if (!spies[name]->has_car || spies[name]->inconsistent) {
            spies[name]->inconsistent = true;
            return;
        }
        int perc = stoi(v[2]);
        double cost = spies[name]->c->catalog * (double) perc/100;
        spies[name]->bill += ceil(cost);
    }
}

int main() {
    IO;
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int tests;
    cin >> tests;
    while(tests--) {
        int n, m;
        cin >> n >> m;
        
        while(n--) {
            string name;
            int c, p ,m;
            car *car1 = new car();
            cin >> name >> c >> p >> m;
            car1->name = name;
            car1->catalog = c;
            car1->pickup = p;
            car1->mileage_cost = m;
            cars[name] = car1;
        }
        string s;
        while(m--) {
            int t;
            cin >> t;
            getline(cin, s);
            s = s.erase(0, 1);
            events[t] = s;
        }
        for (auto it : events) {
            read_event(it.second);
        }
        for (auto it : spies) {
            cout << it.second->name << " ";
            if (it.second->inconsistent || it.second->has_car) {
                cout << "INCONSISTENT" << "\n";
            } else {
                cout << it.second->bill << "\n";
            }
        }
        //clear maps
        spies.clear();
        events.clear();
        cars.clear();
    }

    return 0;
}