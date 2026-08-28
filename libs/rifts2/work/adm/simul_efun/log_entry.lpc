/*    /adm/simul_efun/log_entry.c
 *    a simul_efun for logging to the log dir
 *    This is/will be the new log simul
 */

#include <dirs.h>
#include <security.h>
#include <objects.h>
#include <config.h>

void log_entry(string fl, string msg) {

  if(base_name(previous_object()) != OB_USER && 
    geteuid(previous_object()) != UID_LOG &&
    geteuid(previous_object()) != UID_ROOT) return;
  if(!stringp(fl))
    error("Bad argument 1 <filename> to log_entry().\n");
  if(!stringp(msg)) 
    msg = identify(msg);
  if(strsrch(fl, "..") != -1)
    error("Illegal file reference [security violation] to log_entry().\n");
  seteuid(UID_LOG);
  if(file_size(fl = sprintf("%s/%s", DIR_LOGS, fl)) > MAX_LOG_SIZE) 
    rename(fl, fl+time());
  write_file(fl, msg);
  write_file(DIR_LOGS+"/secure/master", fl+":"+msg);
  seteuid(UID_MUDLIB);
}
