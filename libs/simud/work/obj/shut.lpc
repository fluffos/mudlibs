/// To be documented.

int seconds_to_live;
int shutdown_in_progress = 0;

void pull_the_plug();

void shut_warn() {
   int time_till_warn;

   msg_all("The MUD driver shouts: Shutdown in " + int_to_time(seconds_to_live) + "!");
   time_till_warn = random(seconds_to_live / 8) + 15;
   if(time_till_warn > seconds_to_live) time_till_warn = seconds_to_live;

   call_out("shut_warn", time_till_warn);
   seconds_to_live -= time_till_warn;
   if(seconds_to_live <= 0) pull_the_plug();
}

int shut(int minutes) {
   if( find_call_out("shut_warn") >= 0 ) return 0;
   // this annoys me - Al [Jan 26, '05]
   //   if(minutes < 2) minutes = 2;
   if( minutes < 1 ) minutes = 1;
   seconds_to_live = minutes * 60;
   shut_warn();
   return 1;
}

int shut_cancel() {
   int success;

   success = 0;
   while( remove_call_out("shut_warn") != -1 ) success = 1;
   if( success )
      msg_all("The MUD driver shouts: Shutdown cancelled!  Thank you for your patience.");
   return success;
}

void pull_the_plug() {
   remove_call_out("shut_warn");
   shutdown_in_progress = 1;
   // check if we're planning on a -real- shutdown
   if( sizeof(get_dir("/clean.shutdown")) ) {
      msg_all("Shutdown sequence begins.\nNo immediate reboot scheduled, hopefully one of the wizards told you what was going on ;)");
   } else {
      msg_all("Shutdown sequence begins.\nGoodbye everybody!\nWe'll probably be back up in a few minutes.");
   }
   users()->quit(0);
   call_other("world/world", "save_self", "world/world");
   shutdown();
}

int query_shutdown_in_progress() {
   return shutdown_in_progress;
}
