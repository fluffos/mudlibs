void crash(string crash_mess, object command_giver, object current_object) {
  	log_file("CRASH", ctime(time())+" ");
  	if (current_object) log_file("CRASH", "cur_ob:"+file_name(current_object)+" ");
  	if (command_giver) log_file("CRASH", "Command_giver:"+command_giver->query_cap_name());
  	log_file("CRASH", " Reason: "+crash_mess+"\n");
	cp("/log/debug.log", "/log/debug.log.old");
 	event(users(),"say","Alguien ha tocado algo que no debia y hay que crashear el mud...\n");
	}
