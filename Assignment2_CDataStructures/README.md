# Due Date: July 22, 2018 at 11:59 PM.

TODO Please edit the following information in your assignment

- Name:
- How many hours did it take you to complete this assignment?
- Did you collaborate with any other students/TAs/Professors?
- Did you use any external resources? (Cite them below)
  - tbd
  - tbd
- (Optional) What was your favorite part of the assignment?
- (Optional) How would you improve the assignment?

# Logistics

For this assignment (and every assignment/lab), you must login into the servers through `your_ccis_name@login.ccs.neu.edu` to complete and test your work. The reason is the examples I will provide below are compiled strictly for our machines architecture, and this is a consistent architecture where your submission will be graded.

# Building Data Structures - Queue
<img align="right" src="https://upload.wikimedia.org/wikipedia/commons/thumb/5/52/Data_Queue.svg/450px-Data_Queue.svg.png" alt="Queue picture">

We have previously learned the Linked List Data Structure. Now we will introduce another data structure, known as the 'queue'.

A 'queue' data structure is analogous to waiting in line at a grocery store. The first person to the checkout counter is served, followed by the next person, and then the next until the line is empty. A queue is what is known as a 'first-in first-out' (FIFO) data structure. Thus queues have a strict policy about how information is stored and accessed.

For this assignment, you are going to implement a specific implementation of a queue using an array. This data structure is also called a circular queue (specifically a ring buffer when the maximum storage size is fixed).

Provided for you is a skeleton of the implementation queue_array.c that you will implement and test.

## Part 1 - Queue implementation as an array (Ring Buffer).

A circular buffer has a fixed sized, or maximum number of elements that it can hold. This is advantageous if we know how many elements are typically stored in a data structure (If we do not know, then a queue with a linked list implemetation is needed). 

For more information on the Circular buffer, see here: https://en.wikipedia.org/wiki/Circular_buffer

This animation below gives an idea about how the data structure 'wraps' around. Think about what mathematical operator has a *wrap around behavior* that could be useful in your implementation when enqueuing and dequeuing items in your queue (*hint* this operator will save you from writing many if-statements in your code!).

![](https://upload.wikimedia.org/wikipedia/commons/thumb/f/fd/Circular_Buffer_Animation.gif/400px-Circular_Buffer_Animation.gif)

Your task will be to implement the functions in the queue_array.c to have a working implementation of queue.

### Unit Tests

A unit test is a standalone test that checks for the correctness of a specific use case in your code. In our case, we are testing if we have a working queue implementation. A sample unit tests is given:

```
void unitTest1(){
	queue_t* test1 = create_queue(1);
	printf("Attempting to add %d\n",1);
	queue_enqueue(test1,1);	
	printf("Removing: %d\n",queue_dequeue(test1));	

	free_queue(test1);
}
```

You *may* also consider writing some unit tests to test your implementation (In fact, I would strongly encourage you to do so). Note that you can include your unit tests in your submission, and we will have our own test suite. Some example tests we might come up with include:

* Fill a queue, empty the queue, and fill the queue again.
* Create an empty queue and attempt to add something to it.
* Make sure your queue does not overwrite any data.
* etc.

## Part 2 - Why is a ring buffer/circular queue useful?

Circular queues are used quite a bit in operating systems and high performance systems, especially when performance matters. Do a little outside research, and edit this section of the readme answering specifically: Why is a ring buffer useful and/or when should it be used?

# TODO: Put your answer here

*My answer is ...*

# Rubric

- 80% Correct Queue implementation
  - All functions should be implemented. Do not rename the functions, but you may add any 'helper' functions if you deem necessary.
    - (e.g. You might have a 'queue_print' to help you debug)
  - There should be no memory leaks
  - There should be no bugs in your functions 
  - Your implementation will be graded by our set of unit tests, and we will check your code 'style' as well.
- 20% Correct writeup on the importance of queues/ring buffers as related to OS
  - I expect this to be in the range of 2-3 paragraphs (Can include complexity, example usage, pros/cons, etc).

# Resources to help

- This is a nice interactive tutorial for learning C
  - http://www.learn-c.org/
- Queue Data Type High level description
  - https://en.wikipedia.org/wiki/Queue_(abstract_data_type)
  
# Going Further
(An optional task to extend this assignment--not for bonus, but just for fun)

* Add additional functions like:
  * queue_peek - Returns the first value in the queue
  * queue_back - Returns the last value in the queue
  * queue_equals - Checks if two queues are equal
  
# Feedback Loop

(An optional task that will reinforce your learning throughout the semester)

- Investigate/Review more data strutures on this webpage: https://www.cs.usfca.edu/~galles/visualization/Algorithms.html
  - There are visuals for the linked list and array based queue here!

