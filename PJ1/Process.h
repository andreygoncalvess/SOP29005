#ifndef PROCESS_H_
#define PROCESS_H_

#include <sys/types.h>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

class Process {
public:
    Process(string & program, vector<string> & params, bool block);
    virtual ~Process();

    int pid();
    int status();

private:
    void exec(string & program, vector<string> & params);
    static char * string_to_c_convert(const string & s);
    int pid2, ppid2;

private:
    int _status;
    string param1,param2;
};

#endif /* PROCESS_H_ */
