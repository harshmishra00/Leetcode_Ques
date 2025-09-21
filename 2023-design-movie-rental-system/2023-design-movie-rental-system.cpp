class MovieRentingSystem {
public:

    unordered_map<int, unordered_map<int, int>> priceMap;
    

    unordered_map<int, set<pair<int,int>>> available;
    

    set<tuple<int,int,int>> rented;

    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto &e : entries) {
            int shop = e[0], movie = e[1], price = e[2];
            priceMap[shop][movie] = price;
            available[movie].insert({price, shop});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> ans;
        int cnt = 0;
        for (auto &p : available[movie]) {
            if (cnt == 5) break;
            ans.push_back(p.second);
            cnt++;
        }
        return ans;
    }
    
    void rent(int shop, int movie) {
        int price = priceMap[shop][movie];
        available[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = priceMap[shop][movie];
        rented.erase({price, shop, movie});
        available[movie].insert({price, shop});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> ans;
        int cnt = 0;
        for (auto &t : rented) {
            if (cnt == 5) break;
            auto [price, shop, movie] = t;
            ans.push_back({shop, movie});
            cnt++;
        }
        return ans;
    }
};
