#!/bin/zsh

function lets_go()
{
  nb_test=$1
  test_mod=$2

  if [[ $test_mod == 1 ]]
  then
    list_size=3
    max_move=3
  elif [[ $test_mod == 2 ]]
  then
    list_size=5
    max_move=12
  elif [[ $test_mod == 3 ]]
  then
    list_size=100
    max_move=1500
  elif [[ $test_mod == 4 ]]
  then
    list_size=500
    max_move=11500
  fi
  echo "\033[33m$list_size numbers test\033[0m"
  while [[ 0 -lt $nb_test ]] 
  do
    ARG=$(./random_number/random_number.out $list_size)
    nb_moves=$(./push_swap $ARG | wc -l)
    is_sort=$(./push_swap $ARG | ./checker_linux $ARG)
    if [[ $max_move -lt $nb_moves ]]
    then
      echo -n "nb_move = \033[31m$nb_moves\033[0m | "
    else
      echo -n "nb_move = \033[32m$nb_moves\033[0m | "
    fi
    if [[ 'OK' == $is_sort ]]
    then
      echo "\033[32mList sorted! 👍\033[0m"
    else
      echo "\033[31mNot sorted\033[0m"
    fi
    nb_test=$(($nb_test-1))
  done
}

if [[ $# == 0 ]] || [[ 2 < $# ]]
then
  echo "Please select mod:"
  echo "0 : all test"
  echo "1 : 3 numbers"
  echo "2 : 5 numbers"
  echo "3 : 100 numbers"
  echo "4 : 500 numbers"
  echo "5 : quit"
  read test_mod

  echo "How many tests you want to do?"
  read nb_test
else
  test_mod=$1
  nb_test=$2
fi
if [[ $test_mod == 0 ]]
then
  mod=1
  tmp_nb_test=$nb_test
  while [[ $mod -lt 5 ]]
  do
    lets_go $nb_test $mod
    nb_test=$tmp_nb_test
    mod=$(($mod+1))
  done
else
  lets_go $nb_test $test_mod
fi
echo "------------------------------------------------------------------------"