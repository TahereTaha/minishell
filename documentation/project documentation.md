
this minishell is made as a simple interpreter for a language that lets you execute commands and write some logic to the execution of the command.

#### journey of a command
the command starts from the terminal input.
1. the command get read or autocomplete by the read line library. ending up with a simple string.
	![[Untitled-2024-09-16-1730(1).svg]]
2. this now in string format gets trough a lexer/tokenizer witch transforms it into an array of tokens.
	![[Untitled-2024-09-16-1730(2).svg]]
3. then the lexical analyzer/parser goes through the array of tokens to build the AST (Abstract Syntax Tree). 
	![[Untitled-2024-09-16-1730(4).svg]]
	>**NOTE**
	>in case of a syntax error the parser will fail to get all the tokens on the AST
	
4. now the executor will take control. the first thing is to take all the here documents and cue them, if there is a syntax error print the correct error message, execute all the here documents cued.
	![[Untitled-2024-09-16-1730(13).svg]]
5. after that it will descend the three until reaching a "simple command". the descent of the tree will respect the rules for sub-shells and pipes.
	![[Untitled-2024-09-16-1730(7).svg]]
6. in here it will only expand inside the "simple command".
	>**NOTE**
	>if any expansion results in a word count different from 1 it will re-parse this section to reflect that change.
7. concatenate all the characters or strings inside words.
8. now it is going to abstract the command data into a struct with a list arguments and a list of redirections.
	>**NOTE**
	> the only thing that maters is the order between arguments or between redirections.
	
	![[Untitled-2024-09-16-1730(6).svg]]
9. execute and redirect all the redirections in order.
10. run the command search for the first argument and execute this simple command.
11. evaluate how to continue with the following commands. see witch if any is the next command to execute and repeat. 
	![[Untitled-2024-09-16-1730(9).svg]]

#### code structure
this project is split in several concern areas.
the most important is the separation between the core of the program, interpreting and executing commands, and the rest that is needed to have a working executable.

The core will only concern itself with interpreting and executing a command received in form of a string. to achieve this objective the core is divided into 2 distinct parts:
- the lexical analysis + semantic analysis.
- the executor/interpreter.


# I don't know what to do with that.
https://www.cs.princeton.edu/courses/archive/spring20/cos320/LL1/?
https://andrewbegel.com/cs164/ll1.html
https://tomassetti.me/guide-parsing-algorithms-terminology/
https://www.geeksforgeeks.org/construction-of-ll1-parsing-table/
https://en.wikipedia.org/wiki/LL_parser
https://mariomeissner.github.io/ll1-grammar/
https://groups.seas.harvard.edu/courses/cs153/2018fa/lectures/Lec03-Lexing.pdf
https://railroad.omegatower.net/generator.html
https://github.com/madebypixel02/minishell?tab=readme-ov-file#mind-map
http://lab.antlr.org/