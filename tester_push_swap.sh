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
  echo "\033[33m100 numbers test\033[0m"
  ARG="256 206 5 792 703 732 262 959 549 485 191 219 709 100 261 377 865 \
  242 118 935 323 677 41 672 277 97 151 725 142 320 981 348 325 773 50 56 \
  34 8 605 518 199 824 226 298 84 416 675 949 658 884 980 468 924 652 745 \
  21 802 469 162 121 450 510 445 222 559 501 567 106 765 929 999 63 12 415 \
  737 961 72 529 844 52 996 768 741 788 505 210 950 626 659 459 71 881 18 \
  572 136 584 909 349 908 412"
  nb_moves=$(./t_push_swap $ARG | wc -l);
  if [[ 1500 < $(($nb_moves)) ]]
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
  echo "500 numbers test"
fi
if [[ $test_mod == 5 ]]
then
  echo "Goodbye"
fi