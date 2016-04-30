--This project accomplishes the first three steps
--test cases are as follows:
       valgrind --leak-check=full ./myshell 
       ./test a\ b c\ \ d
       ./test a\  b c\   \ d
       ./test \a\ b\
       ./test \
       ./test     \
       ./test 
       /home/gh84/ece551/classwork/c08/p4/minesweeper 3 3 1
       ./ppppp                                                  #this is for program which does not exit in the directory
       /home/gh84/ece551/classwork/c08/p4/ppppp			        #this is for program which does not exit in the directory
       ls -al /etc/passwd
               ls -al /etc/passwd                               
       emacs 
       ./test2                                                  #test2 is used to test how myShell would behave when test2 is segfaulted 
       exit
          exit
       new line                                                 #type enter
       C-d          
       cd 
       	   cd   
       cd .
       cd ..
       pushd
       pushd .
       pushd ..
       pushd /home/gh84/ece551/classwork/c08/p4/
       cd ..
       pushd ./var
       dirstack
       popd 
       popd
       popd

Generally, This baby shell can deal with unexpected input typed by user in a sane way and it is valgrind clean.
       
        
       
	   
       
