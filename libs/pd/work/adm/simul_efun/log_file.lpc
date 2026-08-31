/*    /adm/simul_efun/log_file.c
 *    from Nightmare Mudlib 3.2
 *    a simul_efun for logging to the log dir
 *    created by Descartes of Borg 940121
 */

#include <dirs.h>
#include <security.h>
#include <objects.h>
#include <config.h>

void log_file(string fl, string msg) {
    int i;
    if(base_name(previous_object()) != OB_USER && 
        geteuid(previous_object()) != UID_LOG &&
        geteuid(previous_object()) != UID_ROOT) return;
    if(!stringp(fl)) error("Bad argument 1 to log_file().\n");
    if(!stringp(msg)) msg = identify(msg);
    if(strsrch(fl, "..") != -1) error("Illegal file reference.\n");
    seteuid(UID_LOG);
    if(file_size(fl = sprintf("%s/%s", DIR_LOGS, fl)) > MAX_LOG_SIZE) 
      rename(fl, sprintf("%s.old", fl));
    i=write_file(fl, msg);
    if(!i) 
      write("log_file("+fl+") in "+file_name(previous_object())+" failed.");
    seteuid(UID_MUDLIB);
}

