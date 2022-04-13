#!/bin/sh

if [ "${SYSTEM}" == "freertos" -o "${SYSTEM}" == "bare_metal" ]; then
    if [ "${CPU}" == "RX3081" ]; then
      echo true
    elif [ "${CPU}" == "Taroko" ]; then
      echo true
    elif [ "${CPU}" == "KR0ec" ]; then
      echo true
    elif [ "${CPU}" == "KR0" ]; then
      echo true
    elif [ "${CPU}" == "TR9" ]; then
      echo true
    else
      echo false
    fi
else
    echo false
fi