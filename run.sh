compile='clang -g -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c &&  clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c && clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft '
run_simple='&& ./test_gnl t && echo '
#run_valgrind='&& valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./test_gnl t 2>&1 | grep "LEAK SUMMARY:" -A 5'
run_valgrind='&& valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./test_gnl t'

eval $compile $run_simple $run_valgrind
