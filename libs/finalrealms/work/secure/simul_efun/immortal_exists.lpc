//      /secure/simul_efun/user_exists.c
//      from the RotD Mudlib
//      returns true if there is such a player
//      created by Descartes of Borg 930822
//
// Now this returns true if there is an immortal with the name.
// Baldrick, nov '97.

#include <dirs.h>

int immortal_exists(string str) {
    int ret;

    seteuid((string)master()->get_root_uid());
    if (file_exists("/immortals/"+str[0..0]+"/"+str+".o"))
      ret = 1;
     else
      ret = 0;
    seteuid(0);
    return ret;
}
