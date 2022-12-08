#!/bin/zsh

echo "Please select mod:"
echo "0 : all test"
echo "1 : 3 numbers"
echo "2 : 5 numbers"
echo "3 : 100 numbers"
echo "4 : 500 numbers"
echo "5 : quit"

read test_mod

if [[ $test_mod == 1 ]] || [[ $test_mod == 0 ]]
then
  echo "\033[33m3 numbers test\033[0m"
  ARG="3 2 1"
  nb_moves=$(./t_push_swap $ARG | wc -l);
  if [[ 3 < $(($nb_moves)) ]]
  then
    echo "\033[31mToo many moves. | moves = $nb_moves\033[0m"
  else
    echo "\033[32mGood moves numbers | moves = $nb_moves\033[0m"
  fi
  is_sort=$(./t_push_swap $ARG | ./checker_linux $ARG)
  if [[ 'OK' == $is_sort ]]
  then
    echo "\033[32mList sorted! 👍\033[0m"
  else
    echo "\033[31mNot sorted\033[0m"
  fi
fi
if [[ $test_mod == 2 ]] || [[ $test_mod == 0 ]]
then
  echo "\033[33m5 numbers test\033[0m"
  ARG="5 4 3 2 1"
    nb_moves=$(./t_push_swap $ARG | wc -l);
    if [[ 12 < $(($nb_moves)) ]]
    then
      echo "\033[31mToo many moves. | moves = $nb_moves\033[0m"
    else
      echo "\033[32mGood moves numbers | moves = $nb_moves\033[0m"
    fi
    is_sort=$(./t_push_swap $ARG | ./checker_linux $ARG)
    if [[ 'OK' == $is_sort ]]
    then
      echo "\033[32mList sorted! 👍\033[0m"
    else
      echo "\033[31mNot sorted\033[0m"
    fi
fi
if [[ $test_mod == 3 ]] || [[ $test_mod == 0 ]]
then
  echo "100 numbers test"
fi
if [[ $test_mod == 4 ]] || [[ $test_mod == 0 ]]
then
  echo "500 numbers test"
fi
if [[ $test_mod == 5 ]]
then
  echo "Goodbye"
fi