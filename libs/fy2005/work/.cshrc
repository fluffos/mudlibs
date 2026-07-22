setenv USER `/usr/ucb/whoami`
#  Set the prompt.
alias cd 'cd \!* ; set prompt=\[$USER.$GROUP\@$HOST\]" `dirs`"\[\!\]\%\ '
cd .

setenv PATH /u/ssc/chenj/bin\:/usr/local/bin:\/usr/sbin\:/usr/bin\:/usr/ucb\:/usr/ccs/bin\:/opt/SUNWicg/SunScreen/bin\:$PATH
setenv MANPATH '/usr/man:/usr/share/man:/usr/local/man:/usr/openwin/share/man:/usr/local/samba/man'
##setenv LD_LIBRARY_PATH /usr/openwin/lib:/usr/lib:/usr/dt/lib:/usr/local/lib
umask 002
alias ls ls -F
