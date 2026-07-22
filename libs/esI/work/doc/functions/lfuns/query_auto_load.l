
QUERY_AUTO_LOAD(L)      LOCAL FUNCTIONS        QUERY_AUTO_LOAD(L)

NAME
     query_auto_load - "used in player-held objects that need  to
     reload automatically at each login

SYNOPSIS
     mixed query_auto_load(); void init_arg(mixed arg);

DESCRIPTION
     Autoloading objects are those objects that the game automat-
     ically  loads  into  the  player's inventory when the player
     logs in to the game.

     Any object that wishes to be autoloaded must define a method
     named query_auto_load.  query_auto_load should return one of
     three things:

     1) A two-element array with  the  first  element  being  the
     filename of the object and the second element being any data
     structure is to be preserved across logins.

     2) A string consisting of the base filename  of  the  object
     (without  the  .c  extension) followed by a colon optionally
     followed by any values that the autoloading object wishes to
     preserve across logins.

     3) The integer 1.  This is the simplest (and least flexible)
     way to cause the object to be autoloaded.

     player.c  calls  query_auto_load  on  each  object  in   the
     player's  inventory  just  prior  to  the player being saved
     before quitting.  It uses the returned information to  build
     an  array  of  information  on which objects are to be auto-
     loaded (and what data they are to  be  sent  when  they  are
     reloaded  at  the  next  login).   Note that all autoloading
     objects  must  define   a   method   named   "remove"   (see
     /doc/lfun/remove)  that self-destructs the object.  The best
     way to do this is to make sure that your object inherits the
     standard  object  (this ensures that remove() is included in
     your object).  Note: the remove method  is  responsible  for
     updating  the player's internal encumbrance (how much weight
     being carried).  At logout time, the player object calls the
     remove  method on each autoloading object.  Note, that auto-
     loading objects may be droppable (which wasn't the  case  in
     LPmud 2.4.5).

     init_arg is an optional method that may be defined in  auto-
     loading objects.

     At login time, the player object sends a message init_arg to
     each object that is autoloaded.  The argument that is passed


TMI-2 Release 0.9         Last change:                   4-2-93

QUERY_AUTO_LOAD(L)      LOCAL FUNCTIONS        QUERY_AUTO_LOAD(L)

     to init_arg comes from the value previously supplied by  the
     object's query_auto_load method.  (either the second element
     of the two element array, or the string  following  the  ":"
     depending upon which method was used).

     For example, consider an autoloading object that defines  an
     integer  named  "count"  and  a string named "name" that you
     wish to keep the values of across logins.

     Here are the query_auto_load and init_arg methods  for  such
     an object.

     #include  <mudlib.h>  inherit  OBJECT  ;  #define  THIS_FILE
     "/usr/student/joe/obj/sample"

     int count; string name;

     mixed  *query_autoload()  {       return  ({  THIS_FILE,  ({
     count, name }) }); }

     void init_arg(mixed *arg) {      count = arg[0];      name =
     arg[1]; }

     Here is an example of the old way to do it (method  #2  from
     above).   Using  this  method may ensure that your code will
     work on more mudlibs (without being modified).

     /* THIS_FILE should be defined to be the  base  filename  of
     this object */

     inherit "/std/Object"; /* gives us the  "remove"  method  */
     #define THIS_FILE "/usr/student/joe/obj/sample"

     int count; string name;

     string query_auto_load() {      return  THIS_FILE  +  ":"  +
     count + "," + name; }

     void            init_arg(string            arg)            {
          sscanf(arg,"%d,%s",count,name); }

     Now suppose that you don't care what the value of "count" or
     "name"  are in the next login.  In that case you would rede-
     fine query_auto_load as follows:

     string query_auto_load() {      return THIS_FILE + ":"; }

     and omit the init_arg method in your obj

SEE ALSO
     /std/user/autoload.c, /std/user.c

Sun Release 4.1           Last change:                          2

QUERY_AUTO_LOAD(L)      LOCAL FUNCTIONS        QUERY_AUTO_LOAD(L)

AUTHOR
     Truilkan@TMI

Sun Release 4.1           Last change:                          3

