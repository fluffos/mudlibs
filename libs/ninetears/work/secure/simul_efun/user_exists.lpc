//      /secure/simul_efun/user_exists.c
//      from the RotD Mudlib
//      returns true if there is such a player
//      created by Descartes of Borg 930822

#include <dirs.h>

int user_exists(string str) {
    int ret;

    seteuid((string)master()->get_root_uid());
    ret = file_exists(DIR_USERS+"/"+str[0..0]+"/"+str+".o");
    seteuid(0);
    return ret;
}
