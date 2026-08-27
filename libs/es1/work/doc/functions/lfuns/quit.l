
QUIT(L)                 LOCAL FUNCTIONS                   QUIT(L)

NAME
     quit() - prepare to destroy a body object.

SYNOPSIS
     int quit(string str) ;

DESCRIPTION
     The quit() lfun  is  defined  in  all  user  bodies.  It  is
     accessed  by  the  player  via  an  add_action  added in the
     basic_commands() lfun. It handles whatever  housekeeping  is
     necessary  when  a body object is destroyed. This can happen
     when the player quits,  or  it  can  happen  when  a  player
     changes  bodies,  either from swapping into a monster or new
     user body, or from dying and swapping into the  ghost  body.
     Exactly  what is done depends on the particular body; in the
     user body objects are dropped, invisibility  is  taken  off,
     the  quit  script is executed, and the player's data file is
     saved. In the monster and ghost bodies, the amount of house-
     keeping to be done is not as great.

SEE ALSO
     remove(),   save_data(),   basic_commands(),    /std/user.c,
     /std/monster.c, /std/ghost.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

