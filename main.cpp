#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <utility>
#include <string>
#include "Process/process.h"

using namespace std;

int main() {

    // This would be typically static keys and the corresponding values for any process running in AuditD
    vector<pair<string,string> > static_keys = {
        {"pid", "5445"}, {"u_ud", "a_9545"}, {"message", "The process produced a log"}, {"node_no", "12"}
    };

    // This would be dynamic keys for any process
    vector<string> dynamic_keys = {"Timestamp", "Error message"};

    process process(static_keys, dynamic_keys);
    process.run_process();
}