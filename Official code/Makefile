build:
	gcc -Wall main.c utils.c -o solved_task

run:
	./solved_task inputs/data_scenarios_a_example.in > output1.txt
	./solved_task inputs/data_scenarios_b_mumbai.in > output2.txt
	./solved_task inputs/data_scenarios_c_metropolis.in > output3.txt
	./solved_task inputs/data_scenarios_d_polynesia.in > output4.txt
	./solved_task inputs/data_scenarios_e_sanfrancisco.in > output5.txt
	./solved_task inputs/data_scenarios_f_tokyo.in > output6.txt

valgrind:
	valgrind --leak-check=full ./solved_task data_scenarios_a_example.in

clear:
	rm solved_task