/*    /adm/simul_efun/log_file.c
 *    from Nightmare Mudlib 3.2
 *    a simul_efun for logging to the log dir
 *    created by Descartes of Borg 940121
 */

#include <dirs.h>
#include <objects.h>
#include <commands.h>
#include <config.h>
#include <privs.h>

void log_file(string fl, string msg) {
    if(!stringp(fl)) error("Bad argument 1 to log_file().\n");
    if(!stringp(msg)) msg = identify(msg);
    msg = timestamp()+" "+msg;
    if(msg[<1..] != "\n") msg += "\n";
    if(strsrch(fl, "..") != -1) error("Illegal file reference.\n");
    if(userp(previous_object(0)) || previous_object(0) == master())
      fl = DIR_LOGS+"/secure/"+fl;
    else if(member_array(PRIV_SECURE,explode(query_privs(previous_object()),":"))
      != -1) fl = DIR_LOGS+"/"+fl;
    else {
        switch(base_name(previous_object(0))) {
            case CMD_CALL:
                fl = DIR_LOGS+"/"+fl;
                break;
            default:
                fl = DIR_LOGS+"/etc/"+fl;
        }
    }
    if(this_object()->unguarded((: file_size, fl :)) > MAX_LOG_SIZE)
      this_object()->unguarded((: rename, fl, fl+".old" :));
    this_object()->unguarded((: write_file, fl, msg :));
}
