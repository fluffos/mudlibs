
LINK_DATA()       MISC. REFERENCE MANUAL PAGES        LINK_DATA()

NAME
     link_data() - query the information in a  body's  connection
     object.

SYNOPSIS
     mixed link_data (string what) ;

DESCRIPTION
     The link_data() lfun is defined in /std/body.c. In the TMI-2
     mudlib,  all  users  have  a connection object, which stores
     information about the person connecting, and a body  object,
     which  stores  information about their character in the MUD.
     The  link_data()  lfun  takes  a  string   argument,   calls
     query("what")  in  the  link object, and returns the result.
     This lets you access  the  properties  of  the  link  object
     without having to worry excessively about the details of the
     link.

SEE ALSO
     query(), query_link(), set_link(), /std/body.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

