//      /adm/simul_efun/personal_log.c
//      from the Nightmare Mudlib
//      simulf efun allowing an immortal to log things securely
//      created by Descartes of Borg 09 july 1993
//      updated by Pallando @ Nightmare, 20 april 1994

#include <dirs.h>
#include <security.h>

void personal_log(string str) {
    string dir, sub, where;

    if(!str) return;
    //   /cmds/mortal/_foo.c would log to .../cmds
    //   /std/foo.c logs to .../std
    // etc, but domain and realm objects are an exception, eg:
    //   /domains/desert/foo.c logs to .../desert (not .../domains)
    //   /realms/pallando/foo.c logs to .../pallando (not .../realms)
    if( (2==sscanf(file_name(previous_object()), "/%s/%s/%*s", dir, sub)) &&
      (dir == "domains" || dir == "realms") )
        where = sub;
    else
        where = dir;
    write_file(DIR_PERSONAL_LOGS+"/"+where, str);
}
