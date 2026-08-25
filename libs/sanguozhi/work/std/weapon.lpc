// Updated by stefan on 10 Jan 1997
/* Do not remove the headers from this file! see /USAGE for more info. */

#include <mudlib.h>

inherit OBJ;
inherit M_WIELDABLE;
inherit M_GETTABLE;
inherit M_MESSAGES;

void mudlib_setup()
{
    ::mudlib_setup();
    set_gettable(1);
}

void remove() {
    object::remove();
    m_wieldable::remove();
}	    
int indirect_kill_liv_with_obj()
{
  return 1;
}
