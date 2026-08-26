
SET_ENV(L)              LOCAL FUNCTIONS                SET_ENV(L)

NAME
     set_env() - set a value in the users environment variables.

SYNOPSIS
     int set_env (string env, mixed value) ;

DESCRIPTION
     The set_env() lfun is  defined  in  /std/living/env.c.  That
     file provides support for UNIX-like enviromnent variables in
     living objects. The set_env lfun takes  the  argument  value
     and  adds  the  to  the environment variables list under the
     name env.

     The commands set and unset allow the user to set  and  unset
     his own environment variables.

KNOWN BUGS
     The environment variables system has been made redundant  by
     the  addition  of properties into the standard object; it is
     only included to provide backwards compatibility with  other
     mudlib code.

SEE ALSO
     query_env(),       remove_env(),       set(),       query(),
     /std/object/prop.c, /std/living/env.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

