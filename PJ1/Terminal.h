#ifndef TERMINAL_H_
#define TERMINAL_H_

#include <sys/types.h>
#include <map>
#include <string>
#include <vector>
#include "Process.h"

using namespace std;

class Terminal {
public:
    Terminal();
    virtual ~Terminal();

    int run();
    pid_t pid();

private:
    string trim(string& str);
    vector<string> Tokenizer(string& str);
    bool extract_cmd(string cmd, vector<string> * tokens);
    pid_t _my_pid;
    pid_t _parent;
    typedef map<pid_t,Process*> ProcessMap;
    ProcessMap _processes;
    char hostname[50];
    char user[50];
    string command, limit, hostname2, first, user2, comp;
    vector<string> token, token3;
    int tamanho,k;
    bool block;
};

#endif /* TERMINAL_H_ */
