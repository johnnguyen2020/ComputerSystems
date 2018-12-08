import subprocess
import signal
import os

os.system('python compile.py')

binaries = [
    'test1_mymalloc',
    'test2_mymalloc',
    'test3_mymalloc',
    'test_malloc',
    'static_array_insertion',
    'binary_tree_test',
    'test_null'
]

for f in binaries:

    print "running tests ... >>",f

    args = ["./tests/{}".format(f)]
    res = subprocess.Popen(args, shell=True ,stdout=subprocess.PIPE, stderr=subprocess.PIPE)
    output, _err = res.communicate()

    print 'segmentation fault' if res.returncode == -signal.SIGSEGV else output
    print ('\n')

