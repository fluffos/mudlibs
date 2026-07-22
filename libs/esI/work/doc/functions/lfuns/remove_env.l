
REMOVE_ENV(L)           LOCAL FUNCTIONS             REMOVE_ENV(L)

NAME
     remove_env() - remove an environment variable from a  living
     object.

SYNOPSIS
     int remove_env (string env) ;

DESCRIPTION
     The remove_env()  lfun is defined in  /std/living/env.c.That
     file provides support for UNIX-like enviromnent variables in
     living objects. The remove_env() lfun delets the environment
     variable with the name passed as argument.

     The commands set and unset allow  the  user  to  change  the
     values of his own environment variables.

KNOWN BUGS
     The environment variables system has been made redundant  by
     the  addition  of properties into the standard object; it is
     only included to provide backwards compatibility with  other
     mudlib code.

SEE ALSO
     set_env(), remove_env(), set(), query(), /std/object/prop.c,
     /std/living/env.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

