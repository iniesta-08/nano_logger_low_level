#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include "../AuditD/logger.h"

using namespace std;

class process {
    public:
        map<string,string> static_keys;
        vector<string> dynamic_keys;

        process(vector<pair<string,string> > &key_value_pairs, vector<string> &dynamic_keys_vector) {
            for(size_t i = 0; i <key_value_pairs.size(); i++) {
                string key = key_value_pairs[i].first;
                string value = key_value_pairs[i].second;
                static_keys[key] = value;
            }
            dynamic_keys = dynamic_keys_vector;
        }

        void run_process() {
            logger logger(static_keys, dynamic_keys, "log_file.txt");

            for(size_t i=0; i<100; i++) {
                vector<string> random_values;
                for(int j=0; j<dynamic_keys.size(); j++) {
                    random_values.push_back(gen_random());
                }
                logger.log(random_values);
            }
        }

        private:
            string gen_random() {
                static const char alphanum[] =
                    "0123456789"
                    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                    "abcdefghijklmnopqrstuvwxyz";
                std::string tmp_s;
                tmp_s.reserve(10);

                for (int i = 0; i < 10; ++i) {
                    tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];
                }
                return tmp_s;
            }

};