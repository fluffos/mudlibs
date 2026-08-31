#define HOME "players/qclxxiv/"
#include "/players/qclxxiv/naming.h"  /* TITLE + NAME */

inherit "players/qclxxiv/island/bird";

#define PLACE_IN_THIS(OBJNAME, FILNAME)\
OBJNAME = place_in_this(OBJNAME,FILNAME,this_object());

#define MAKE_IN_THIS(FILNAME)\
make_in_this(FILNAME,this_object());

#define set_size(SIZE)\
size = SIZE;
