# @(#)Cshrc 1.5 90/11/01 SMI
#################################################################
#
#         .cshrc file
#
#         initial setup file for both interactive and noninteractive
#         C-Shells
#
#################################################################

limit datasize 32M
limit coredumpsize 4M

# Set openwin as my default window system 
set mychoice=openwin

#         set up search path

# add directories for local commands
set lpath = ( )
if ( ${?mychoice} != 0 ) then
	if ( ${mychoice} == "openwin" ) then
		set lpath = ( /usr/openwin/bin/xview /usr/openwin/bin /usr/openwin/lib $lpath )
	endif
endif

set path = (. ./ ~/bin ~ $lpath /usr/local /usr/local/bin /usr/ucb /usr/etc /usr/bin)

#         cd path

#set lcd = ( )  #  add parents of frequently used directories
#set cdpath = (.. ~ ~/bin ~/src $lcd)

#         set this for all shells

set noclobber
set term=vt100


#         aliases for all shells
#alias cd            'cd \!*;echo $cwd'
alias cp            'cp -i'
alias mv            'mv -i'
alias rm            'rm -i'
alias pwd           'echo $cwd'
alias r		    '/data/mud/bin/restart_mud >/dev/null &'
alias k		    '/data/mud/pk-bin/driver'
alias pc	    '/data/mud/bin/parse >/dev/null &'
alias mc2	    'telnet localhost 2001'
alias mx		'xterm -ls -sb -bg lightgray -e tcsh &'
umask 007

#         skip remaining setup if not an interactive shell

if ($?USER == 0 || $?prompt == 0) exit

#          settings  for interactive shells

set history=40
set ignoreeof
#set notify
set savehist=40
#set prompt="% "
set prompt="`whoami`@`hostname` # "
#set time=100

#          commands for interactive shells

#date
#pwd

#         other aliases

alias h            'history \!* | head -39 | more'
alias cls	   clear

#alias list         cat
#alias lock          lockscreen
#alias type         more

alias dir          ls -l
alias la            'ls -la'
alias ll            'ls -ls'

alias	mc2	'telnet localhost 2001'

# IRC settings
  setenv IRCNICK Sourcer
  setenv IRCNAME "Michael Achleitner"

# For compiling the parser:

#  setenv LD_LIBRARY_PATH /data/mud/lib:/usr/openwin/lib:/usr/lib
setenv LD_LIBRARY_PATH /data/mud/lib:/usr/openwin/lib

#
# Vorgeschlagene Tastaturbelegung
#
# Pos1 = [2~
# Ende = [5~
# Einfg = [1~
# Entf = [4~

bindkey	"[2~"	beginning-of-line
bindkey	"[5~"	end-of-line
bindkey	"[1~"	overwrite-mode
bindkey	"[4~"	delete-char
