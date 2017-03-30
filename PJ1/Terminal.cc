#include "Terminal.h"
#include <unistd.h>
#include <string>
#include <iostream>
#include <string>
#include <signal.h>
#include <sys/types.h>
#include <ctype.h>

using namespace std;

Terminal::Terminal()
{
   
}

Terminal::~Terminal()
{
    
}

int Terminal::run()
{
	getlogin_r(user, sizeof user);
	gethostname(hostname, sizeof hostname);

	user2=user;
	if (user2.compare("root") != 0){
		limit="$";
	} else limit="#";

LOOP:
	do{
 		cout << "<" << user << "/" << hostname << ">" << limit << " ";
		getline(cin,command);		
		if(command.empty()) goto LOOP; //tratamento caso command zerado.
		command=trim(command); //retira os espacos no comeco e fim da sequencia de strings.
		token=Tokenizer(command);
		first=token[0];
		tamanho=token.size();
		for(k=1;k<tamanho;k++){
			token3.push_back(token[k]);
		}
		comp=token[tamanho-1];
		if(comp.compare("&")==0) block=false;
		else block=true;
		if(comp.compare("exit")==0) break;
		Process Processo(first, token, block);
	} while(true);
}


string Terminal::trim(string& str)
{
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');
    return str.substr(first, (last-first+1));
}

vector<string> Terminal::Tokenizer(string& str)
{
	vector<string> token2;
	char delim=' ';
	int aux0=0, aux1=0,aux2=0;
	string palavra;
	while(aux0!=string::npos){
		aux0=str.find(delim,aux1);
		aux2=aux0-aux1;
		palavra=str.substr(aux1,aux2);
		aux1=aux0+1;
		token2.push_back(palavra);
	}
	
	return token2;
}
