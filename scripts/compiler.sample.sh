#!/bin/sh

case "${CPU}" in
   "RX3081") echo "mips-elf-gcc" 
   ;;
   "Taroko") echo "mips-elf-gcc" 
   ;;
   "KR0ec") echo "riscv32-elf-gcc" 
   ;;
   "KR0") echo "riscv32-elf-gcc" 
   ;;
   "TR9") echo "riscv32-elf-gcc" 
   ;;
esac