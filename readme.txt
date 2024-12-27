PROJECT PUSH_SWAP FOR 42
- By chdonnat (Christophe Donnat from 42 Perpignan, France)

Some commands you can use:
make
	compiles the push_swap programm
make bonus
	compiles the checker programm
make fclean
	remove all .o files and executable files generated par the make command
ARG=$(./tests/test_generator n)
	generate a list of n integers (without doubles) separated by spaces
	and assign the list to the variable ARG
	("n" must be a positive integer)
./push_swap "$ARG" | wc -l
	counts the number of steps used by push_swap to sort the numbers in ARG
./push_swap "$ARG" | ./tests/checker_Mac "$ARG"
	for Mac
	verifies the output of push_swap by using the 42 tester:
	returns OK if the output of push_swap sorts the numbers in ARG
	or returns KO if not
	returns error if there was an error
./push_swap "$ARG" | ./tests/checker_linux "$ARG"
	same as above but for linux
./push_swap "$ARG" | ./checker "$ARG"
	same as above but using my own tester (made for the bonus of the project)