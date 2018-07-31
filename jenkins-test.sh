#!/bin/bash
# This script is executed by Jenkins to verify the uploaded change.
# The patch is verified +1 if the script exit 0, otherwise -1.
#
# Shun-Yen Lu
#

if [ "$GERRIT_PROJECT" != "" ]; then
  repo download $GERRIT_PROJECT $GERRIT_CHANGE_NUMBER/$GERRIT_PATCHSET_NUMBER
fi

# exit the shell for any fail
set -e
gcc -Wall -o test.elf test.c
./test.elf
