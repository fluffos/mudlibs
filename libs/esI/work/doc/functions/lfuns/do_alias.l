
DO_ALIAS(L)             LOCAL FUNCTIONS               DO_ALIAS(L)

NAME
     do_alias() - apply global and user-defined  aliases  to  the
     input string.

SYNOPSIS
     string do_alias (string str) ;

DESCRIPTION
     The do_alias lfun() is defined in /std/body/alias.c.  It  is
     inherited  by  body.c,  and  thence  by the user and monster
     objects. It is  called  from  process_input;  it  takes  the
     user's  input  string  as  argument  and checks to see if it
     matches a user-defined alias, or one of the  global  aliases
     stored  in the file /adm/daemons/ga_server.c. If an alias is
     found, it applies that  alias.   It  returns  the  processed
     string back to process_input.

SEE ALSO
     do_nicknames(),        do_history(),        /std/user/tsh.c,
     /adm/daemons/ga_server.c, process_input()

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

