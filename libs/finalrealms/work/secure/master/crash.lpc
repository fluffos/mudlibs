void crash(string crash_mess, object command_giver, object current_object) {

  log_file("CRASH", ctime(time())+" ");
  if (current_object)
    log_file("CRASH", "cur_ob:"+file_name(current_object)+" ");
  if (command_giver)
    log_file("CRASH", "Command_giver:"+command_giver->query_cap_name());
  log_file("CRASH", " Reason: "+crash_mess+"\n");
cp("/log/debug.log", "/log/debug.log.old");
 "/secure/simul_efun"->shout("Ducky shouts: Oh No! I have to crash "+
                                  "the driver now.\n");
/* Want to make sure we dont go and bomb in here. */
/* Next stuff just ends up meaning that the mud never goes down.
  obs = users();
  for (i=0;i<sizeof(obs);i++)
    obs[i]->do_force_on_me("quit");
*/
rename("/log/runtime_debug.log","/log/crash_log"+time());
} /* crash() */
