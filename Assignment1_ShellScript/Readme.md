# Due Date: Sept 11, 2018 at 11:59 PM.

(This means push your changes to the repository by 5pm--whatever you see on the web is what I grade)

TODO Please edit the following information in your assignment

- Name(s):
- How many hours did it take you to complete this lab?
- Did you collaborate with any other students/TAs/Professors?
- Did you use any external resources? (Cite them below)
  - tbd
  - tbd
- (Optional) What was your favorite part of the assignment?
- (Optional) How would you improve the assignment?

# Automate (some of) your life

Getting familiar with the terminal is a fundamental skill to have. Many of you have various levels of experience using the terminal.

For this assignment, you will be warming up by writing a 1-2 page tutorial on bash scripting. Your tutorial will be embededded in a shell script, explaining how to do something on the terminal that is non-trivial but that can be automated. You will run your script `myScript.sh` on command line as an executable shell script.  You can look at example 'sh' scripts for inspiration on what you can achieve on the web. 

The tutorial will be done purely  in text and and within a file called 'myscript.sh'. You are required to type your tutorial using a terminal based text editor like 'vim', 'emacs', or 'nano' to write your tutorial (I personally use the vim text editor).

An example of a non-trivial script would be a few lines of code that sorts a particular column of data from a .csv file. You can use your imagination to continue further.

# Part 1 - myScript.sh

## Very Brief Example Tutorial (Template)
(Note this example is fairly trivial)

* Problem Statement: "Often I have to search for different files and directories within my computer system. In order to do this I use the 'ls' command to help orient myself.
* Name of command: ls
* Example of its usage: 
```
-bash-4.2$ ls
Lab1  README.md
```

* Here is the list.sh script that can list the directories and how many total directories are in the current folder.

``` 
ls
ls | wc -l
```

# Part 2 - VIM and TMUX

(Note this part is ungraded--but you are required to do it!)

Figuring out a good workflow on Unix, Mac, (and even windows) is an important part of becoming a good programmer. My work environment (and the suggested one so I can help you during class), is to use the combination of the VIM text editor and tmux window manager to program your assignments in.

### Student and Teacher Dialouge

*"But I love visual studio, sublime, XCode, Atom, etc."*

*That's great, but you cannot use those in a remote environment easily--so I suggest learning another skill. By all means, use both or multiple tools to write the highest quality code.*

*"Hehe, the professor will never know if I just use notepad. I'll just take a shortcut on this assignment"*

*While that's true you can take a shortcut now, it will eventually catch up to you. I promise this is a good skill to learn! This first assignment is much more lightweight, take the time now to do things properly.*

Here are some suggested resources to get started.
* (VIM+TMUX Example) https://www.youtube.com/watch?v=YD9aFIvlQYs (16:31)
* Type *man tmux* in a terminal.
* Tmux tutorial - https://www.youtube.com/watch?v=BHhA_ZKjyxo (11:23)

# Resources to help

- A pretty good introduction to shell scripting is here: https://www.howtogeek.com/67469/the-beginners-guide-to-shell-scripting-the-basics/ .

# Rubric

* 33.3% Was your tutorial 1-2 pages (estimate this as 2 regular pieces of printed paper)
    * (If you decided you were doing something so cool it had to be longer, was this well justifed)
    * If your tutorial is your actual script with comments in it, then it should be able to run. Otherwise, you should also have a script file that can actually be run accompanying your tutorial.
* 33.3% Polish
    * Was the tutorial well polished, did something useful, and did not contain any bugs?
* 33.4% Presentation
    * Was the writing presented in a clear manner in your own voice (i.e. I should not be able to Google it).
  * (Please indicate in your submission at the top if these tutorials can be shared on our piazza board)
  * (The very brief tutorial example I gave would probably earn a C- at best :) Go beyond!)

* Note: Your code **must** run on the CCIS machines. That is where you should test it, and this is where we grade it!
* Note: You must also commit any additional files into your repository so we can test your code.
  * Points will be lost if you forget!

# Feedback Loop

(An optional task that will reinforce your learning throughout the semester)

Read this article and implement the little 'whatis' command in your .bashrc. https://lifehacker.com/how-can-i-quickly-learn-terminal-commands-1494082178

```
echo "Did you know that:"; whatis $(ls /bin | shuf -n 1)
```

This is a nice way to learn a new command everytime you log on!

