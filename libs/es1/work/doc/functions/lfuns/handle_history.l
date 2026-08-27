
HANDLE_HISTORY(L)       LOCAL FUNCTIONS         HANDLE_HISTORY(L)

NAME
     handle_history() - check a string against the history queue,
     and add it

SYNOPSIS
     string handle_history(string str) ;

DESCRIPTION
     The handle_history() lfun is defined in /std/user/history.c.
     It  takes  a  string  argument  and checks to see if it is a
     history-related command.  If the string does NOT begin  with
     an  !,  it adds the string to the history queue, and returns
     the string. If the string is "!!", it gets the last  command
     issued  from  the  history  queue  and  returns that. If the
     string is "!<number>", it returns command <number> from  the
     history queue, if available. Otherwise, it parses the string
     as !<string> and returns the most  recently  issued  command
     that began with <string> in the history queue. In any of the
     last three cases, the returned string is added to  the  his-
     tory  queue  before  returning.  Note that in the last case,
     <string> MAY contain spaces, unlike the  UNIX  history  com-
     mand.  Thus,  if  you have typed "say fred foo" and you then
     type "!say f", the handle_history() lfun  WILL  return  "say
     fred  foo".   The  handle_history()  lfun is called from the
     process_input() function, before aliases and  nicknames  are
     applied.

SEE ALSO
     process_input(),      query_history(),      /std/user/tsh.c,
     /std/user/history.c

AUTHOR
     Mobydick@TMI-2.


TMI-2 Release 0.9         Last change:                   4-2-93

