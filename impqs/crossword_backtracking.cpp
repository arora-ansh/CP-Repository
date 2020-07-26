//Basically try fitting single strings and then if they dont fit conme back and reset it to that position i.e. 
//the backtracking step
//Normal recursion problem + backtracking step

#include<bits/stdc++.h>
#include<string>
#include<vector>
using namespace std;

char game[10][10];
char empty[10][10];
vector<string> words;

bool verticalfit(int row, int col, string word){
    int j = row;
    int c = col;
    for(int i=0;i<word.length();i++){
        if (j > 9)
			return false;
		if (game[j][c] == '+' || (game[j][c] != '-' && game[j][c] != word[i]))
			return false;
		if (game[j][c] == '-' || game[j][c] == word[i])
			j++;
    }
    return true;
}

bool horizontalfit(int row, int col, string word){
    int j = col;
    int r = row;
	for (int i = 0;i < word.length();i++) {
		if (j > 9)
			return false;
		if (game[r][j] == '+' || (game[r][j] != '-' && game[r][j] != word[i]))
			return false;
		if (game[r][j] == '-' || game[r][j] == word[i])
			j++;
	}
	return true;
}

void solver(int wordnumber,int wordlistsize){
    /*cout<<wordnumber<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<game[i][j];
        }
        cout<<endl;
    }
    cout<<endl;*/
    if(wordnumber>=wordlistsize){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                cout<<game[i][j];
            }
            cout<<endl;
        }
    }
    //cout<<"I am here";
    //Ek ek karke word ki specific position dhundhenge and agar saare place ho gaye toh
    //base case reach warna backtrack
    string word = words[wordnumber];
    cout<<word<<endl;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            //cout<<i<<" "<<j<<" "<<word<<endl;
            if(game[i][j]=='-'|| game[i][j]==word[0]){
                if(horizontalfit(i,j,word)){
                    //cout<<"Horizontal"<<" "<<i<<" "<<j<<endl;
                    vector<bool> helper;//Stores whether char is - (true) or a letter(false)
                    for(int k=0;k<word.length();k++){
                        if(game[i][j+k]=='-'){
                        	game[i][j+k]=word[k];
                            helper.push_back(true);
                        }
                        else{
                            helper.push_back(false);
                        }
                    }
                    solver(wordnumber+1,wordlistsize);
                    for(int k=0;k<word.length();k++){
                        if(helper[k]){
                        	game[i][j+k]='-';
                        }
                    }
                }
                if(verticalfit(i,j,word)){
                    //cout<<"Vertical"<<" "<<i<<" "<<j<<endl;
                    vector<bool> helper;//Stores whether char is - (true) or a letter(false)
                    for(int k=0;k<word.length();k++){
                        if(game[i+k][j]=='-'){
                        	game[i+k][j]=word[k];
                            helper.push_back(true);
                        }
                        else{
                            helper.push_back(false);
                        }
                    }
                    solver(wordnumber+1,wordlistsize);
                    for(int k=0;k<word.length();k++){
                        if(helper[k]){
                        	game[i+k][j]='-';
                        }
                    }
                }
        	}
        }
    }
    return;
}

int main() {
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            char temp;
            cin>>temp;
            game[i][j]=temp;
            empty[i][j]=temp;
        }
    }
    string wordlist;
    cin>>wordlist;
    int cur = -1;
    while(wordlist.find(";",cur+1)!=string::npos){
        int x = wordlist.find(";",cur+1);
        int w = cur+1;
        //cout<<w<<" "<<x<<endl;
        words.push_back(wordlist.substr(w,(x-w)));
        cur = x;
    }
    int x = wordlist.find(";",cur+1);
    int w = cur+1;
    words.push_back(wordlist.substr(w,(x-w)));
    cur = x;
    int wordlistsize = words.size();
    //cout<<wordlistsize<<endl;
    solver(0,wordlistsize);
}




