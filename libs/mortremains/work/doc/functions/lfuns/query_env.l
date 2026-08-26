
QUERY_ENV(L)            LOCAL FUNCTIONS              QUERY_ENV(L)

NAME
     query_env - get the value of a living  object's  environment
     variables.

SYNOPSIS
     mixed query_env (string env) ;

DESCRIPTION
     The query_env() lfun is  defined  in  /std/living/env.c.That
     file provides support for UNIX-like enviromnent variables in
     living objects. The query_env() lfun returns  the  value  of
     the environment variable named env in the given object.

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

