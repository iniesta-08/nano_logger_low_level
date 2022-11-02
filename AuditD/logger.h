#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class logger {
    private:
        map<string, string> static_keys;
        vector<string> dynamic_keys;
        ofstream logging_file;
        string logging_file_path;

    public:
        logger(map<string,string> &static_keys_map, vector<string> &dynamic_keys_vector, string logging_file_path_) {
            static_keys = static_keys_map;
            dynamic_keys = dynamic_keys_vector;
            logging_file_path = logging_file_path_;

            logging_file.open(logging_file_path, ios_base::app);
            // Writing the static keys to logging file
            for(auto it = static_keys.begin(); it != static_keys.end(); it++) {
                logging_file << it->first << " " << it->second << ".\n";
            }

            // Writing the dynamic keys to the file
            for(auto it = dynamic_keys_vector.begin(); it != dynamic_keys_vector.end(); it++) {
                logging_file << *it << " ";
            }
            logging_file << "\n";
            logging_file.close();
        }

        void log(vector<string> &dynamic_values_vector) {
            logging_file.open(logging_file_path, ios_base::app);

            // We can further reduce the space complexity by generating some sort of hash I guess.
            
            for(auto it = dynamic_values_vector.begin(); it != dynamic_values_vector.end(); it++) {
                logging_file << *it << " ";
            }

            logging_file << "\n";
            logging_file.close();
        }
};