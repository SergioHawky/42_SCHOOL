#!/bin/bash

# Caminho para o executável push_swap
PUSH_SWAP=./push_swap

# Cor para terminal
GREEN="\033[0;32m"
RED="\033[0;31m"
NC="\033[0m"

# Entradas inválidas que DEVEM produzir "Error"
invalid_cases=(
  "-"
  "+"
  "--3"
  "++4"
  "+-5"
  "-+6"
  "42a"
  "a42"
  "3#4"
  "7_8"
  ""
  " "
  "   "
  "- "
  "+ "
  "+ 42"
  "- 5"
  "4-2"
  "7+3"
)

# Entradas válidas que NÃO devem produzir "Error"
valid_cases=(
  "42"
  "-42"
  "+7"
  "   -1   +3 4"
  "0"
  "-0"
  "+0"
  "2147483647"
  "-2147483648"
)

echo -e "======== ${RED}Invalid Cases (should print Error)${NC} ========"

for input in "${invalid_cases[@]}"; do
  output=$($PUSH_SWAP $input 2>&1)
  if echo "$output" | grep -q "Error"; then
    echo -e "${GREEN}PASS${NC}: '$input' -> Error detected"
  else
    echo -e "${RED}FAIL${NC}: '$input' -> No Error!"
  fi
done

echo
echo -e "======== ${GREEN}Valid Cases (should NOT print Error)${NC} ========"

for input in "${valid_cases[@]}"; do
  output=$($PUSH_SWAP $input 2>&1)
  if echo "$output" | grep -q "Error"; then
    echo -e "${RED}FAIL${NC}: '$input' -> Unexpected Error!"
  else
    echo -e "${GREEN}PASS${NC}: '$input' -> OK"
  fi
done

