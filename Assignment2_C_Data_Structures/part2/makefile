cc = gcc
logpath = `printf "\`realpath .. | xargs basename\`-\`echo \"Assignment2-valgrind\"\`.log"`
output_file = `printf "\`realpath .. | xargs basename\`-\`echo \"Assignment2-test_output\"\`.log"`

TestAssignment2 : TestAssignment2_part2.c unity.c main.c
	$(cc) TestAssignment2_part2.c unity.c -o TestAssignment2 -std=gnu99
	$(cc) main.c -o TestAssignment2_Valgrind -std=gnu99

queue_array_test : queue_array.c
	ls ./queue_array_test.c && rm ./queue_array_test.c; \
	sed '/main(/,$$d' queue_array.c >> queue_array_test.c

run : TestAssignment2_Valgrind
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=$(logpath) --verbose ./TestAssignment2_Valgrind > $(output_file)

clean : TestAssignment2 
	rm ./TestAssignment2 $(output_file) $(logpath) 
