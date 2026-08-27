
SET_LINK(L)             LOCAL FUNCTIONS               SET_LINK(L)

NAME
     set_link() - set a pointer to a body's connection object.

SYNOPSIS
     void set_link (object ob) ;

DESCRIPTION
     The set_link() lfun is defined in /std/body.c. In the  TMI-2
     mudlib,  each  user is first given a connection object which
     handles his name, password, and other data relevant  to  the
     user.  When  he  logs  in, he is connected to a body object,
     which contains data related to the character he  plays.  The
     set_link()  function  sets  the  link  variable in the body,
     which is a pointer to the  user's  connection  object.  This
     pointer  is needed to access the real name and email address
     of the person controlling a given body.

     The link pointer is a relatively sensitive  thing,  and  the
     following  security  check  is  made;  only  an  object with
     ROOT_UID, or the connection object, may alter the link vari-
     able.

SEE ALSO
     query_link(), /std/body.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

