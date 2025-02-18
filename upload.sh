#!/bin/bash

set -eu
cd $(dirname $0)

cat .vscode/arduino.json | jq -r \
  '"-b \(.board):\(.configuration) upload --port \(.port) --build-path \(.output) \(.sketch)"' | \
  xargs arduino-cli
