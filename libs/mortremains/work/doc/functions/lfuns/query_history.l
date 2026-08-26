
QUERY_HISTORY(L)        LOCAL FUNCTIONS          QUERY_HISTORY(L)

NAME
     query_history() - return a user's queue of recent commands

SYNOPSIS
     string *query_history() ;

DESCRIPTION
     The query_history() lfun is defined in  /std/user/history.c.
     The  user object keeps track of the last N commands the user
     entered, where N defaults to 20 but may  be  set  using  the
     HISTORY   enviroment  variable,  up  to  a  maximum  of  50.
     Query_history() returns a pointer  to  the  linked  list  of
     strings  which  stores these commands.  This function can be
     abused, either by altering the commands stored or by  creat-
     ing  a  pseudo-snoop on the user. To guard against this kind
     of   behavior,   the   function   returns   0   unless   the
     previous_object  is  either  ROOT_UID  or  an  admin's EUID.
     Failed attempts are logged.   The  query_history()  lfun  is
     called    from    handle_history(),    also    defined    in
     /std/user/history.c,   which   in   turn   is   called    by
     process_input() whenever the user types a command line.

SEE_ALSO
     handle_history(), /std/user/history.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

