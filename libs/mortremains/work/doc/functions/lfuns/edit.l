
EDIT(L)                 LOCAL FUNCTIONS                   EDIT(L)

NAME
     edit() - allow a user to begin editing a file.

SYNOPSIS
     varargs int edit (string fname, string fun, object ob, mixed
     args) ;

DESCRIPTION
     The edit() lfun is defined in /std/living/edit.c. It  allows
     users to edit files in temporary space, usually for the pur-
     pose of sending mail or making posts on boards or  appending
     to  log  files.   If the player sets his enviroment variable
     "editor" to "ed", then the edit() lfun will  call  the  ed()
     efun  to allow the player to use ed to edit the file. Other-
     wise, he will be allowed to  enter  text  himself,  line  by
     line, with each line being appending to a file.

     There is no security in the edit() lfun;  instead,  security
     is   handled  by  the  driver  making  use  of  the  applies
     valid_read() and valid_write().  fname is the  name  of  the
     file to save the results of the edit to. fun is the function
     to be called when the player finishes the edit; this is usu-
     ally  a  function  defined in the calling object which sends
     the mail or puts the post onto the board or whatever  action
     needs  to  be taken. Ob is the calling object: it can be the
     mailer or the board, or if not supplied it is  taken  to  be
     this_player().  args  are  optional  arguments  than  can be
     passed to the editor, and are available largely  for  future
     use.

SEE ALSO
     ed(), valid_write(), valid_read(), /std/living/edit.c

AUTHOR
     Mobydick@TMI-2


TMI-2 Release 0.9         Last change:                   4-2-93

