
DO_NICKNAMES(L)         LOCAL FUNCTIONS           DO_NICKNAMES(L)

NAME
     do_nicknames() - replace any nicknames in a user's command.

SYNOPSIS
     string do_nicknames(string str) ;

DESCRIPTION
     The do_nicknames() lfun is defined in /std/user/nicknames.c.
     Any  user  may  use  the nickname command to enter nicknames
     into an array of  nicknames  stored  in  his  .o  file.  The
     do_nicknames()  lfun  takes  a  string  argument, breaks the
     string up into its component words using the  explode  efun,
     and checks to see if any of the words are nicknames. If they
     are, the nicknamed strings are substituted in. This is  used
     mostly  to  avoid  typing  long names repeatedly: ie, "alias
     nova supernova" lets you use "nova" to refer to Supernova in
     tells, kills, gotos, and other commands.  The use of a nick-
     name can be defeated by prepending  a  slash:  thus,  typing
     "The  sun  is  about  to go nova" will expand to "The sun is
     about to go Supernova" but "The sun is about to go 0va" will
     expand  to "The sun is about to go nova" thus preventing the
     wildcard from taking effect.   The  do_nicknames()  lfun  is
     called  from  process_input  on each line the user types in,
     after history is applied but before aliases are applied.

SEE ALSO
     process_input(), /std/user/tsh.c, /std/user/nicknames.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

