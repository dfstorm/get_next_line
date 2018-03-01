clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c &&  clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c && clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft


make -C libft/ fclean && make -C libft/ && clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c &&  clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c && clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft


/*
		Un recois un fichier et une reference a un fichier
		On lit le fichier via le buffer seter tant qu'un trouve pas un /n.

		On sauvegarde l'endroit du dernier \n (int) trouver. Donc a chaque
		nouvelle lecture, on avance ver le next.

		return value
			Si on trouve un /n = 1
			Si on trouve /0 = 0
			Sur erreur : -1.


	=======================================================

		En fait, je cherche a aller trop loins.

		Le put: Un lit tant qu'on trouve pas un \n. Et on stock le restant dans une statick pour la prochaine fois. POINT.

		Donc.

		First : Un colle le stuff de l<action precedante SAVE a une lecture dans DT.
		
		On fait un pres-test avec le buff pour savoir si on peut juste avancer dedans... et quand ya pu de \n

		Tant que ya des buff
			On colle a le stuff dans DT
				On cherche un /n. Si trouver
					On coupe la string. le bout avant est retourner, le reste est mis dans la SAVE
				Si on trouve pas.. on continue..
	*/
