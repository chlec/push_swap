### Push_swap proje
ct at 42.

In this project we should order a list of number with 2 stacks (A and B) using less possible operations.

We were limited by these operators:

- **sa**: Swap the two first element of stack A
- **sb**: Swap the two first element of stack B
- **ra**: Rotate number from stack A to the left, the first become the last.
- **rb**: Rotate number from stack B to the left, the first become the last.
- **rra**: Rotate number from stack A to the right, the last become the first. 
- **rrb**: Rotate number from stack B to the right, the last become the first.
- **pa**: Push the first number from stack B to stack A. It will be at the first position of A
- **pb**: Push the first number from stack A to stack B. It will be at the first position of B

### Example

- Operator: sa  
  Stack A: 	1 2 3 6 5 8  
  Stack B:  

- Operator: pb  
  Stack A: 	2 3 6 5 8  
  Stack B: 	1  

- Operator: pb  
  Stack A: 	3 6 5 8  
  Stack B: 	2 1  

- Operator: pb  
  Stack A: 	6 5 8  
  Stack B: 	3 2 1  

- Operator: sa  
  Stack A: 	5 6 8  
  Stack B: 	3 2 1  

- Operator: pa  
  Stack A: 	3 5 6 8  
  Stack B: 	2 1  

- Operator: pa  
  Stack A: 	2 3 5 6 8  
  Stack B: 	1  

- Operator: pa  
  Stack A: 	1 2 3 5 6 8  
  Stack B:  

### Allowed functions

Only these functions were allowed: write, read, malloc, free and exit.
