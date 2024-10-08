# table of content
- [[#Shell operations]]
- [[#Environment variables]]
- [[#env expansions]]
- [[#File name expansions]]
- [[#Redirections]]
- [[#Pipelines]]
- [[#Command lists]]
- [[#Sub-shell]]
- [[#Quoting]]
- [[#Command search and execution]]
- [[#Builtins]]
- [[#Signals]]

# Shell operations

1. it reads the input from the terminal.
2. breaks the input into character and tries to assemble them into a command following the grammar of the command language ( see [[project documentation/comand language gramar/README.md|command language grammar]] ). 
4. goes through the command executing all the here documents until it finds a syntax error.
6. preform shell expansions of the "\*" wild cards (see [[#Expansions (file name)]]) and the environment expansions (see [[#env expansions]]).
7. runs the commands in the sequence described by the command line.
8. preform all the redirections.
9. execute the command.

# Environment variables

 thou the execution of the shell there will be a set of name value pairs that are the environment. This environment serves the purpose of storing variables accessible to all commands executed under it. variable names are restricted to only use alphabetical characters uppercase or lower case, digits and the "\_", and they can never start with a digit.

# env expansions

on the command you can use values stored on environment variables. To make use of that just write a "$" followed by the name of your environment variable, no spaces or anything in the middle. at the time of execution it will expand (be replaced) to the value of the env variable.
it would look like this 
```bash
echo $word
```
or 
```bash
echo $PATH
```
if the env variable is not enclosed in quotes and contains spaces it will trigger word splitting.
the "$?" is specially treated, on expansion its value is expanded to the return of the last command.

# File name expansions

if any word contains the character "\*" it is consider a pattern. any pattern will be replaced with a list of filenames that mach that pattern separated by blanks. after this the "word"(to be changed) will cause word splitting. any pattern that dose not match with anything will not get replaced and stay as it is.

# Redirections

redirections redirect to witch files the inputs and outputs of commands are hooked on. redirection can be behind, in front and in the middle of the command and its arguments.
```bash
> redirection_file1 cat < redirection_file2 -e test1 > redirection_file3
```
If redirections are executed in order and 
there are 4 kinds of redirections: redirect output, redirect appended output, redirect input, here document.
they all will take the form of "(redirection simbol)" any amount of spaces and a "word"(to be changed, I still need to define all the tokens that this language will use).
```bash
cat `redirection simbol` `word`
```
if the word expansion leads to word spiting, or expands to nothing or blank the redirection will return a error of ambiguous redirection.
#### Redirect output
it redirects the output of the command. it will delete and make again the file if it already exists and just make it if it doesn't exists.
it takes the form of ">" with or without blank in the middle and a "word"
```bash
cat > test_file_1
```
#### Redirection input
it redirects the input to the command.
it takes the form of "<" with or without blank in the middle and a "word"
```bash
cat < test_file_2
```
#### Redirect output append
it redirects the output of the command. it will create the file it it doesn't exists or just append if it already exists.
it takes the form of ">>" with or without blank in the middle and a "word"
```bash
cat >> test_file_1
```
#### Here document
it redirects the input of the command. it will request from the user text to fill a temporal file made on the spot. the text will contain any kind of characters and will be delimited by the "word" used.
it takes the form of "<<" with or without blank in the middle and a "word"
```bash
cat << test_file_1
```
[!NOTE]- code
# Pipelines
pipelines are a list of commands arranged sequentially with "|" pipes between them. like this:
```bash
cat | cat | cat | cat | cat
```
this will execute all the commands on the pipe at the same time and redirect their inputs and outputs to the previous and next commands. like this:
```bash
ls | cat -e | echo
```
the output of the "ls" will go to the input of "cat -e" and the output of "cat -e" will go to the input of "echo".

pipelines have precedence over command lists.
```bash
cat && cat && cat | cat | cat
```
will execute as 
```bash
cat && cat && { cat | cat | cat ; }
```
and not like
```bash
{ cat && cat && cat ; } | cat | cat
```
# Command lists
pipelines are a list of commands arranged sequentially with "&&"(and) or "||"(or) between them. like this:
```bash
cat && cat || cat && cat && cat || cat
```
this will execute only the first command and depending on the return value will do the next element on the list or not. if an element on the list is not done it will skip it and check the next one.
#### AND operator
it will check for a successful execution of the last command, return value of 0. 
#### OR operator
it will check for a unsuccessful execution of the last command, return value of not 0. 
# Sub-shell
runs a shell with its own environment inherited of the parent and executes the command inside it. then it closes with the return value of the command run.
it takes the form of "(" command ")".
```bash
(exit 1) || echo $?
```
# Quoting
any special character between quotes is going to lose its meaning and be treated as part of the word. it too prevents word splinting between its members (see [[#env expansions]]).
#### Single quotes
will remove the meaning of any special character between them except for a single quote. single quote can't be between single quotes. the shell will read it as two different single quotes.
this
```bash
echo 'test the -->'''
```
will expand to
```bash
echo test the -->
```
and not to
```bash
echo test the -->''
```
#### Double quotes
will remove the meaning of any special character between them except for double quotes and "$" env variables.
this
```bash
echo "$?  1"
```
expands to
```bash
echo "1  1"
```
# Command search and execution

after all the steps before (lexical analysis, expansions, word splitting, redirections). There will be a list of words for the simple command to execute. the first word will be used as the command name and the rest as arguments.
the command name is search in the following order:
 - if it has slashes "/" it is executed in its own execution environment.
 - searches it on the builtins. if it is found it executes it.
 - searches it on the $PATH directories. if it is found it is executed in its own execution environment.
