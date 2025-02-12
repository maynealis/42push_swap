# PUSH_SWAP

## Functions and files

[x] stack_manager.c
	- t_stack *ft\_stacknew(int number)
	- t\_stack *ft_stacklast(t_stack *stack)
	- void ft\_stackadd\_back(t\_stack **stack, t_stack *new)
	- void free\_stack(t_stack **stack)
	
[x] parse_arguments.c
	- static char is\_valid_integer(char *arg)
	- static char is\_not\_duplicate(t_stack *a, int n)
	- char is\_valid\_argument(char *arg, t_stack *a)
	
[x] rules.c
	- void swap(t_stack **stack)
	- void push(t_stack **src, t\_stack **dst)
	- void rotate(t_stack **stack)
	- void reverse\_rotate(t_stack **stack)
	
	
	
[Generator random numbers](https://numbergenerator.org/randomnumbergenerator#!numbers=500&low=-2147483648&high=2147483647&unique=true&csv=&oddeven=&oddqty=0&sorted=false&addfilters=)
	
## References
[First idea](https://m4nnb3ll.medium.com/my-journey-to-find-a-good-sorting-algorithm-for-the-push-swap-42-project-4a18bc38b474)

[Turk Algorithm](https://medium.com/@ayogun/push-swap-c1f5d2d41e97)

[Radix Sort](https://medium.com/nerd-for-tech/push-swap-tutorial-fa746e6aba1e)

[To read](https://medium.com/@ulysse.gerkens/push-swap-in-less-than-4200-operations-c292f034f6c0)
