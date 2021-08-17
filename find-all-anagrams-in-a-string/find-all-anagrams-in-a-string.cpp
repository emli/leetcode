class Solution {
public:
    vector<int> findAnagrams(string a, string b) {
     vector<int> ans;   
    swap(a,b);    
    unordered_map<char,int> map_a;
    unordered_map<char,int> map_b;
    int letter_in_a = 0;
    for(char x : a){
        map_a[x]++;
        if(map_a[x] == 1){
            letter_in_a++;
        }
    }

    int i;
    int same_letters = 0;
    for(i = 0; i < a.size(); i++){
        map_b[b[i]]++;
        if (map_b[b[i]] == map_a[b[i]]){
            same_letters++;
        }
        if (map_a[b[i]] > 0 && map_b[b[i]] - 1 == map_a[b[i]]){
            same_letters--;
        }
    }
    if (same_letters == letter_in_a){
        ans.push_back(0);
    }
        // ab[aac]babc
        // abc


    
    int pos = 0;
    for(; i < b.size(); i++){
        map_b[b[pos]]--;
        cout << "map_a[b[pos]] = " << map_a[b[pos]]<< endl;
        cout << "map_b[b[pos]] = " <<  map_b[b[pos]] << endl;
        if (map_a[b[pos]] > 0 && (map_a[b[pos]] - map_b[b[pos]] == 1)){
             cout << "here1 = " << endl;
            same_letters--;
        }
        if (map_a[b[pos]] > 0 && map_b[b[pos]] == map_a[b[pos]]){
            same_letters++;
        }
        map_b[b[i]]++;
        // cout << "map_b[b[i]] = " << map_b[b[i]]<< endl;
        // cout << "map_a[b[i]] = " <<  map_a[b[i]]<< endl;
        if (map_a[b[i]] > 0 && map_b[b[i]] == map_a[b[i]]){
            same_letters++;
        }
        cout << "map_a[b[i]] = " << map_a[b[i]]<< endl;
        cout << "map_b[b[i]] = " <<  map_b[b[i]] << endl;
        if (map_a[b[i]] > 0 && ( map_b[b[i]] - 1 ==  map_a[b[i]])){
                        cout << "here2 = " << endl;

            same_letters--;
        }
        cout << "b[i] =" << b[i] << endl;
        cout << "same_letters = " << same_letters << endl; 

        pos++;
        
        if (same_letters == letter_in_a){
            ans.push_back(pos);
        }
    }
        // "c[bae]babacd"
        // "abc"
        
      

    return ans;
    }
};
