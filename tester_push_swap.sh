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
    nb_moves=$(./t_push_swap $ARG | wc -l)
    is_sort=$(./t_push_swap $ARG | ./checker_linux $ARG)
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
if [[ $test_mod == 1 ]] || [[ $test_mod == 0 ]]
then
  echo "\033[33m3 numbers test\033[0m"
  list_size=3
  ARG=$(./random_number/random_number.out $list_size)
  nb_moves=$(./t_push_swap $ARG | wc -l);
  if [[ 3 -lt $nb_moves ]]
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
    if [[ 12 -lt $nb_moves ]]
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
  echo "\033[33m100 numbers test\033[0m"
  ARG="256 206 5 792 703 732 262 959 549 485 191 219 709 100 261 377 865 \
  242 118 935 323 677 41 672 277 97 151 725 142 320 981 348 325 773 50 56 \
  34 8 605 518 199 824 226 298 84 416 675 949 658 884 980 468 924 652 745 \
  21 802 469 162 121 450 510 445 222 559 501 567 106 765 929 999 63 12 415 \
  737 961 72 529 844 52 996 768 741 788 505 210 950 626 659 459 71 881 18 \
  572 136 584 909 349 908 412"
  nb_moves=$(./t_push_swap $ARG | wc -l);
  if [[ 1500 -lt $nb_moves ]]
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
if [[ $test_mod == 4 ]] || [[ $test_mod == 0 ]]
then
  echo "\033[33m500 numbers test\033[0m"
  ARG=$(cat "500.txt")
  nb_moves=$(./t_push_swap $ARG | wc -l);
  if [[ 11500 -lt $nb_moves ]]
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
if [[ $test_mod == 5 ]]
then
  echo "Goodbye"
fi
echo "------------------------------------------------------------------------"