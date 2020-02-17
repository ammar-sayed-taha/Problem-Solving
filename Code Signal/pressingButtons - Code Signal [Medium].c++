
// create static letters of each button
void fillLetters(vector<char> *letters){
    letters[0].push_back(' ');
    letters[1].push_back(' ');
    letters[2] = {'a', 'b', 'c'};
    letters[3] = {'d', 'e', 'f'};
    letters[4] = {'g', 'h', 'i'};
    letters[5] = {'j', 'k', 'l'};
    letters[6] = {'m', 'n', 'o'};
    letters[7] = {'p', 'q', 'r', 's'};
    letters[8] = {'t', 'u', 'v'};
    letters[9] = {'w', 'x', 'y', 'z'};
}

// create dfs function
std::vector<std::string> dfs(std::string &buttons, int index,  vector<char> *letters){

    if(index >= buttons.size()) return {""}; // if index exceds size then return list of one empty string

    vector<string> result, st; //  result which holds the final result and st temporary list
    int btnIndex = buttons[index] - 48; // ex:- '1' - 48 = 1, '2' - 48 = 2

    for(char letter : letters[btnIndex]){ // loop over all letters of the pressed button
        st = dfs(buttons, index+1, letters);
        for(string & s : st)
            result.push_back(letter + s);
    }
    return result;
}


std::vector<std::string> pressingButtons(std::string buttons) {
    if(buttons.empty()) return {};
    vector<char> letters [10];
    fillLetters(letters);
    return dfs(buttons, 0, letters);
}
