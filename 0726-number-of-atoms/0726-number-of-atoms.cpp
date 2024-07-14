class Solution {
public:
    string countOfAtoms(string formula) {
        vector<pair<string, int> > st;
        for(int i = 0;i < formula.size();i++) {
            char c = formula[i];
            if (c == '(') 
                st.push_back(make_pair("(", 1));
            
            if ('A' <= c && c <= 'Z') {
                string atom = readAtomName(i, formula);
                int cnt = readDigits(i, formula);
                st.push_back(make_pair(atom, cnt));
            }
            
            if (c == ')') {
                int cnt = readDigits(i, formula);
                // update atoms inside parentheses
                int j = st.size() - 1;
                while (st[j].first != "(" || !st[j].second) // first available "("
                    st[j--].second *= cnt;
                st[j].second--;
            }
        }
        // accumulate results
        map<string, int> atoms;
        for(auto e : st) 
            if (e.first != "(") 
                atoms[e.first] += e.second;
        
        // format the output
        string output = "";
        for(auto it = atoms.begin(); it != atoms.end(); it++) {
            output.append(it->first);
            if (it->second == 1) continue;
            output.append(to_string(it->second));
        }
        return output;
    }
    
    int readDigits(int &i, string &formula) {
        int cnt = 0;
        while (i + 1 < formula.size() && isdigit(formula[i+1])) 
            cnt = cnt * 10 + formula[++i] - '0';
        return max(1, cnt);
    }
    
    string readAtomName(int &i, string &formula) {
        string atom = string(1, formula[i]);
        while (i + 1 < formula.size() && 'a' <= formula[i+1] && formula[i+1] <= 'z') 
            atom.push_back(formula[++i]);
        return atom;
    }
};