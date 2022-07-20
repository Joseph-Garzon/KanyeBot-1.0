#include <iostream>
#include <fstream>
#include <cmath>
#include <array>
#include <string>
#include <sstream>
#include <algorithm>
#include <list>
#include <vector>
#include <limits>
#include <boost/algorithm/string.hpp>

using namespace std;

//makes the song class used as entrys in the dictionary (name lyrics pair)
class Song{
    public:
				string title;
        vector<string> lyrics;
        Song(string t);
};

//Constructor for a Song
Song::Song(string t){
    title = t;
}

vector<Song*> d;
string comp = "";

void wrong(){
	int sel2 = rand()%3;
	if(sel2 == 0){
		cout<<"Wake up Mr. West! You input an incorect response, try something corect."<<endl;
	}else if(sel2 == 1){
		cout<<"You were sleeping on me huh, had a good snooze? Well I hope you're awake now, because I need you too give me a correct response this time."<<endl;
	}else{
		cout<<"Look man, I dont really wanna wrestle, so put in a valid response next time, OK?"<<endl;
	}
	cout<<endl;
}

//converts txt file into string and dictionary
void convert(){
    int nTemp = 0;
		int sCount = 4;
    stringstream ss, st;
    string temp; 
		bool sens;
		ifstream myfile("KWL.txt");

		if(myfile.is_open()){
			while(getline(myfile,temp)){

				if(temp == ""){
					sCount++;
				}else if(sCount > 3 && temp.find_first_of("[") == temp.npos){
					d.push_back(new Song(" "));
					sCount = 0;
					d.back()->lyrics.push_back(temp);
					boost::to_lower(temp);
					comp+=temp;
				}else if(temp.find_first_of("[") == temp.npos){
					sCount = 0;
					d.back()->lyrics.push_back(temp);
					boost::to_lower(temp);
					comp+=temp;
				}

			}
			myfile.close();
		}

}

int main() {
	int sel = 0;

	convert();

	while(sel != 3){
		cout<<"Welcome to BotYe [1.0 pre alpha]"<<endl;
		cout<<"Select a function to run:"<<endl;
		cout<<"1. Kanye Finder"<<endl;
		cout<<"2. Kanye Generator"<<endl;
		cout<<"3. Exit Program"<<endl<<endl;

		cin>>sel;

		cout<<endl;

		if(sel == 1){
			string check = "";
			cout<<"Enter the excact phrase you wanna check for \'Yezzyness\': ";
			cin>>check;
			cout<<endl;
			boost::to_lower(check);
			if(comp.find(check) != comp.npos){
				cout<<"You're \"only making the highlights\" with that one, this is a Kanye reference"<<endl<<endl;
			}else{
				cout<<"I'm \'so appalled\', that is NOT a Kanye reference"<<endl<<endl;
			}
			
		}else if(sel == 2){
			int ssel = rand()%d.size()-1;
			int lsel = d.at(ssel)->lyrics.size();
			int llsel = rand()%lsel;
			string quote = d.at(ssel)->lyrics.at(llsel);
			cout<<"\""<<quote<<"\""<<endl<<endl;
		}else if(sel == 3){
			cout<<"Good night Mr. West.";
			break;
		}else{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			sel = 0;
			wrong();
		}
	}
} 