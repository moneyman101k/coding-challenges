#!/bin/bash
# Deserializing the access tokens text file (serialized_tokens.txt)

# Check for input file on command-line.
ARGS=1
E_BADARGS=85
E_NOFILE=86

if [ $# -ne "$ARGS" ]  # Correct number of arguments passed to script?
then
  echo "Usage: `basename $0` filename"
  exit $E_BADARGS
fi

if [ ! -f "$1" ]       # Check if file exists.
then
  echo "File \"$1\" does not exist."
  exit $E_NOFILE
fi

while IFS= read -r line; do
    node question1_deserialize.js $line
done <question1_serialized_tokens.txt