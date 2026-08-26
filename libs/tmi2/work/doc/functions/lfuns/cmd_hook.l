
CMD_HOOK(L)             LOCAL FUNCTIONS               CMD_HOOK(L)

NAME
     cmd_hook() - find the appropriate command to handle a user's
     input.

SYNOPSIS
     nomask static int cmd_hook(string cmd) ;

DESCRIPTION
     The cmd_hook() lfun is defined in every body object.  It  is
     added   as   an   add_action   to   the  string  ""  in  the
     init_commands() lfun. As a result,  anything  typed  by  the
     user that does not match another add_action is passed to the
     cmd_hook() lfun to be interpreted as a command.

     The cmd_hook() uses the query_verb efun to  determine  which
     of  the  words  typed should be treated as the command name.
     Once it has the name of the command,  it  scans  the  direc-
     tories  listed  in the user's PATH property to see if any of
     them have a file called _<verb>.c in them. If one does, then
     the function "cmd_<verb>" is called in that file, which han-
     dles the command properly: the rest of  the  typed  line  is
     passed as an argument.  For example, if the user types:

     "put frog into sack"

     the cmd_hook() lfun will scan the user's  path  for  a  file
     named  "_path.c".   If it finds one, it will call "cmd_path"
     in that file, passing the string  "frog  into  sack"  as  an
     argument.  The  put command then takes that argument, parses
     it, and takes the appropriate action.

     The reason for using this method  of  handling  commands  is
     that  it  permits  a  tremendous  savings  in memory and CPU
     because each command is listed in only one place, instead of
     being loaded in every user object. It also permits different
     body objects to call the same functions, although  different
     bodies  may  also  access  different versions of commands by
     having  different  paths   (eg,   the   ghost   object   and
     /cmds/ghost).

     Note - the cmd_hook will call cmd_<verb> in the  first  file
     that  it  finds.   If  a  _<verb>.c  exists in more than one
     directory, the command will be called ONLY in the one listed
     FIRST  in  the  user's path. It is best to avoid having com-
     mands with the same name in different bins, but  if  you  do
     so,  then the path order will determine which one is called.
     This can be used to make test versions of commands, by  mak-
     ing a directory such as "/u/f/foo/cmds" and adding it to the
     front of your path. Then, the test version  of  the  command
     will  be  called  for  you, while the normal version will be


TMI-2 Release 0.9         Last change:                   4-2-93

CMD_HOOK(L)             LOCAL FUNCTIONS               CMD_HOOK(L)

     called for everyone else.

SEE ALSO
     init_commands, /std/user.c, /std/monster.c, /std/ghost.c

AUTHOR
     Mobydick@TMI-2

Sun Release 4.1           Last change:                          2

