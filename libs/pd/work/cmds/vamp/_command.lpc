//  Command command

#define f_cmds ({ "quit", "bite" }) 

int cmd_command(string s) {
    string a, verb;
    if(!s || s=="") return notify_fail("Command what?\n");
    if(!this_player()->query_trancing())  return 
	notify_fail("You do not have control of anyones mind.\n");
    if(sscanf(s, "%s %s", a, verb)==2); else
	verb=s;
    if(member_array(verb, f_cmds)!=-1) return 
	notify_fail("Your command fails.");
    write("You command "+this_player()->query_trancing()->query_cap_name()+" to "+s+".\n");
    message("", "You are told a command from "+this_player()->query_cap_name()
      +" and do your best to obey.", this_player()->query_trancing());
    this_player()->query_trancing()->force_me(s);
    return 1;
}

