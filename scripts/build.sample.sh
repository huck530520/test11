#!/bin/bash
#echo "${CPU}"
#echo "hello world" 

if [ "${SYSTEM}" == "freertos" -o "${SYSTEM}" == "bare_metal" ]; then

  #package/test/build.sh
  if [ "${CPU}" == "RX3081" ]; then
    RSDK=rsdk-9.3.0-3081-EL-rtos-n3.0-m16ut-201019.tar.bz2
  elif [ "${CPU}" == "Taroko" ]; then
    RSDK=jrjang-rsdk-9.3.0-5281-EL-rtos-n3.3-m32ut-201006.tar.bz2
  elif [ "${CPU}" == "KR0ec" ]; then
    RSDK=jrjang-vsdk-10.1.1-rv32ec-EL-rtos-n3.3-rv32ut-201006.tar.bz2
  elif [ "${CPU}" == "KR0" ]; then
    RSDK=jrjang-vsdk-10.1.1-rv32i-EL-rtos-n3.3-rv32ut-201006.tar.bz2
  elif [ "${CPU}" == "TR9" ]; then
    RSDK=vsdk-10.1.1-rv32imac-EL-rtos-n3.3-rv32ut-201006.tar.bz
  else
    echo "${CPU} ${SYSTEM} build not supported"
    exit 0
  fi
  
  #echo "${RSDK}"
  rm -rf toolchain && mkdir -p toolchain
  pwd
  ls -la
  tar jxf /home/STools/share/jrjang/jenkins-workspace/toolchains/$RSDK -C toolchain
  
  DIR_TOOLCHAIN=$(pwd)/toolchain/`ls toolchain`
  
  echo "RSDK ${RSDK}"
  echo "DIR_TOOLCHAIN ${DIR_TOOLCHAIN}"
  cd spock
  DIR_TOOLCHAIN=$DIR_TOOLCHAIN CPU_SYS=${CPU}_${SYSTEM} package/test/build.sh

else
  #package/test/run-unit-test.py
  case "${CPU}" in
    "RX3081")
      BOARD=sheipa3-rx3081
      ;;
    "Taroko")
      BOARD=sheipa3-taroko
      ;;
    "TR9")
      BOARD=sheipa3-tr9-rv32ic-plic
      ;;
    "TR9-noplic")
      BOARD=sheipa3-tr9-rv32ic
      ;;
    "KR0")
      BOARD=sheipa3-kr0-rv32ic-plic
      ;;
    "KR0-noplic")
      BOARD=sheipa3-kr0-rv32ic
      ;;
    "KR0ec")
      BOARD=sheipa3-kr0-rv32ec-plic
      ;;
    "KR0ec-noplic")
      BOARD=sheipa3-kr0-rv32ec
      ;;
    *)
      ;;
  esac
  
  cd spock
  ln -s /home/STools/share/jrjang/jenkins-workspace/toolchains/vsdk-10.3.0-newlib host/vsdk
  ln -s /home/STools/share/jrjang/jenkins-workspace/toolchains/rsdk-10.3.0-newlib host/rsdk
  ln -s /home/STools/share/jrjang/jenkins-workspace/rlxvm/RLX-VM_3.6.0_2021-08-10_linux host/rlxvm

  result=`python3 package/test/run-unit-test.py ${BOARD} ${SYSTEM}`
  echo result: ${result}

  pass=`echo ${result} |grep "PASS"`
  fail=`echo ${result} |grep "FAIL"`
  if [ -n "${pass}" ]; then
    exit 0
  elif [ -n "${fail}" ]; then
    failcon=`echo ${result} |grep "Config is not supported"`
    if [ -n "${failcon}" ] ; then
      exit 0
    else
      exit 1
    fi
  fi
  
fi