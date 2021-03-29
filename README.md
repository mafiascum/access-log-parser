# access-log-parser

## Prepare environment, clone & build:
apt update
apt install cmake g++ gcc -y
git clone https://github.com/mafiascum/access-log-parser
make -C access-log-parser/src/ -j12

## To execute:
cat ACCESS_FILE_NAME | sort -t' ' -k4,5 | access-log-parser/bin/access_log_parser -fileNameFormat access-parsed.%s.log -writePath DESTINATION_DIRECTORY

## Versions tested:
g++: 9.3.0
gcc: 9.3.0
cmake: 3.16.3
