# Push-Swap-42

___

![Score_ps](https://github.com/BilelLk/42/blob/main/push_swap/.img/score_push_swap.png)

Push_Swap is a 42-SP project which consist to produce a sorting Algorithm following some
concepts to standardize the process;
We were free to develop this project with any tools created or available (respecting the 42-norm);

Within the sorting process we should work the logic arround some operations determined by the subject,
Please, find bellow the list of operations:
```
- sa :swap 'a' - swap the first 2 elements at the top of stack 'a';
- sb :swap 'b' - swap the first 2 elements at the top of stack 'b';
- ss :sa and sb at the same time.
- pa :push 'a' - take the first element at the top of 'b' and put it at the top of 'a'.
- pb :push 'b' - take the first element at the top of 'a' and put it at the top of 'b'.
- ra :rotate 'a' - shift up all elements of stack 'a' by 1.
- rb :rotate 'b' - shift up all elements of stack 'b' by 1.
- rr :ra and rb at the same time.
- rra :reverse rotate 'a' - shift down all elements of stack 'a' by 1.
- rrb :reverse rotate 'b' - shift down all elements of stack 'b' by 1;
- rrr :rra and rrb at the same time.
```

## Results

![100 Entiers](https://github.com/BilelLk/42/blob/main/push_swap/.img/100_result_ps.png)

![500 Entiers](https://github.com/BilelLk/42/blob/main/push_swap/.img/500_result_p_s.png)

## Instructions

To run the application you shall input the program plus the arguments, which is the list of numbers to organize. For example:
```
$ ./push_swap 3 4 8 9 7 5 1 0 2 6
or
$ ./push_swap "10 30 60 42 80 99 -42"
or
$ ./push_swap "12 24 36" 48 60 "72 84" 98
```
I put an asterisk on the last one because it is not explicitely asked to manage this type of argument but if you are 
working on push swap i highly recommand you tu do it so youre push_swap will be unbreakable. For doing this instead of using strjoin for 
joining all the arguments in a string you just have to use ft_split with a space as aa charset so you could split all the arguments in double quotes
and the arguments whp are not. You can refer to ft_parsing_stack function in ft_parsing.c.

This project was structured to run with integers, with numbers within the range of -2147483648 to 2147483647.
Also, even accepting a string of numbers, if you try to input a word or a letter, as 'a' or 'hello', it will not work, returning an error message.

## Other Information

- This project was made using C language, obeying all 42 norms;
- The tests folder has several tests and lists to better understand the project.
- There is also a visualizer (pyviz.py), it uses the operations that your program produces and present a graphic representation of this proccess. Keep in mind that you need to have installed python and the Tkinter lib;
- There is also an script in perl to automate the list generation and execution of the program, created by a fellow cadetes in 42-SP (ps_tester.pl) - Please, check the notion produced;

##Visualizer

https://youtu.be/4m7n-5vAbkI

## Acknowledgements

- [Florian Guirama](https://github.com/Florian1215)
- [Carolina Daniel](https://github.com/caroldaniel)

## Useful Links

- ["How to eat push_swap as easily as a cake - 1"](https://techdebt.tistory.com/26)
- ["How to eat push_swap as easily as a cake - 2"](https://techdebt.tistory.com/27)
- [Push_swap Tester SCROS](https://github.com/SimonCROS/push_swap_tester)
- [Push_swap Tester Florian Guirama](https://github.com/Florian1215/Push_Swap-Tester)