
INIT_SETUP()      MISC. REFERENCE MANUAL PAGES       INIT_SETUP()

NAME
     init_setup() - initialize a body prior to use.

SYNOPSIS
     void init_setup() ;

DESCRIPTION
     The init_setup() lfun is defined in /std/body.c. It does the
     housekeeping needed to prepare a body for use. Specifically,
     it:
       1. Sets the living name of the body ;
       2. Sets the EUID of the body ;
       3. Starts the body's heart_beat ;
       4. Sets the name and ip properties ;
       5. Enables wizard status if appropriate ;
       6. Initializes the command hook of the body ;
       7. Begins the autosave call_out ;
       8. Initializes the tshell, if appropriate.

SEE ALSO
     heart_beat(), enable_wizard(), cmd_hook(),  /std/user/tsh.c,
     /std/body.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

