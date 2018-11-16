import os

# Compile all of our tests
os.system('clang tests/test1.c -o tests/test1')
os.system('clang tests/test2.c -o tests/test2')
os.system('clang tests/test3.c -o tests/test3')
os.system('clang tests/test_malloc.c -o tests/test_malloc')
os.system('clang tests/static_array_insertion.c -o tests/static_array_insertion')
os.system('clang tests/binary_tree_test.c -o tests/binary_tree_test')
os.system('clang tests/test_null.c -o tests/test_null')

# Compile our malloc program
os.system('clang -c mymalloc.c')

# Compile our tests with our custom allocator
os.system('clang -I. -o ./tests/test1_mymalloc ./tests/test1.c mymalloc.o')
os.system('clang -I. -o ./tests/test2_mymalloc ./tests/test2.c mymalloc.o')
os.system('clang -I. -o ./tests/test3_mymalloc ./tests/test3.c mymalloc.o')
os.system('clang -I. -o ./tests/test_malloc ./tests/test_malloc.c mymalloc.o')
os.system('clang -I. -o  ./tests/static_array_insertion ./tests/static_array_insertion.c mymalloc.o')
os.system('clang -I. -o ./tests/binary_tree_test ./tests/binary_tree_test.c mymalloc.o')
os.system('clang -I. -o ./tests/test_null ./tests/test_null.c mymalloc.o ')
