This project contains a very low-level implementation of nanolog.

We are trying to harvest the idea of seperating dynamic and static content from a log. Where we don't need to log the static content everytime, thus saving some space and increasing performance.

Useful links:
https://documentation.suse.com/sles/12-SP4/html/SLES-all/cha-audit-comp.html
https://www.usenix.org/sites/default/files/conference/protected-files/atc18_slides_yang.pdf

To run the main file on mac use the following commands:

1. clang++ -std=c++11 main.cpp
2. ./a.out

This will generate a log file in the root repository.
