_This project has been created as part of the 42 curriculum by @gpeixoto_

__PUSH SWAP__ 🚀
The project is about developing a sorting algorithm for a set of integers using a limited set of operations.
The primary goal is to rearrange a stack of numbers in ascending order using only a predefined set of instructionsuch as swpping two numbers or rotating the stack. It seems simple, but becomes complex due to the constraint of minimizing the number of operations while sorting the stack efficiently. 

__DESCRIPTION__

	Moves:
    sa : swap a - swap the first 2 elements at the top of stack a. Do nothing if there is only one or no elements).
    sb : swap b - swap the first 2 elements at the top of stack b. Do nothing if there is only one or no elements).
    ss : sa and sb at the same time.
    pa : push a - take the first element at the top of b and put it at the top of a. Do nothing if b is empty.
    pb : push b - take the first element at the top of a and put it at the top of b. Do nothing if a is empty.
    ra : rotate a - shift up all elements of stack a by 1. The first element becomes the last one.
    rb : rotate b - shift up all elements of stack b by 1. The first element becomes the last one.
    rr : ra and rb at the same time.
    rra : reverse rotate a - shift down all elements of stack a by 1. The last element becomes the first one.
    rrb : reverse rotate b - shift down all elements of stack b by 1. The last element becomes the first one.
    rrr : rra and rrb at the same time.

 - Parsing : read and interpret the input list (from command-line) of integers that need to be sorted ensuring it meets certain criteria such as being a list of int within a specified range.
	__Error Cases:__
	- Integer range check : from INT MIN to INT MAX;
	- Duplicate entries : duplicates are not allowed;
	- Empty argument : empty arg is considered an error. " ";
	- Must imput only numbers separated by spaces;
	- Must skip zeros before numbers : "001" is valid;
	- Only one sign is allowed;
	- In _no parameters_ case : the program must not display anything;

	__The algorithm__
	1. Start by pushing two nodes to stack B;
	2. Find the easiest node to push : by calculating the number of movements to bring the closests nodes together;
	3. Last three nodes - petit sort (2 operations in worst case);
	4. Push everything back to stack A;
	5. Final arrangement : if the smallest node is not at the top rotate/reverse rotate the stac until it is;
	6. Clean the stack.

	__Petit Sort__
	If the stack size is 3 nodes, if the biggest number is the first then rotate the stack, or if it's the second then reverse rotate. Then look for the second biggest between first and second node, if it's the first, swap, else it's already sorted; Basically it's about to make sure the biggest number is in the last node, then swap if needed.
	
	
__INSTRUCTIONS__

1. Make;
2. Run /.push_swap with the arguments;


__RESOURCES__

- Linked lists - Short introduction to linked lists in C by CodeVault :  https://www.youtube.com/watch?v=uBZHMkpsTfg&list=PLfqABt5AS4FmXeWuuNDS3XGENJO1VYGxl
- Algo inspiration - https://medium.com/@ayogun/push-swap-c1f5d2d41e97

