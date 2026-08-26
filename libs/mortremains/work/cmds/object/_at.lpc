
// This is part of the TMI distribution mudlib.
// Please retain this header if you use this code.
// Written by Buddha (5-3-92)

#include <move.h>
#include <mudlib.h>

inherit DAEMON ;

void help() {

	write("\tUsage:\tat <living> <command>\n" +
	"Executes the command in the room of the creature you have specified.\n" +
	"If the room isn't there, or cannot be entered, then it won't work.\n");
}

int cmd_at(string str) {
	string who, cmd;
	object prev, act_ob, whom;
	if (!str || sscanf(str, "%s %s", who, cmd) != 2) {
		notify_fail("Usage:\tAt <living> <command>\n");
		return 0;
	}
	act_ob = previous_object();
	whom = find_living(who);
	if (!whom) {
		notify_fail("No such target.\n");
		return 0;
	}
	prev = environment(act_ob);
	if(environment(whom) && act_ob->move(environment(whom)) == MOVE_OK) {
		act_ob->force_me(cmd);
		act_ob->move(prev);
		return 1;
	}
	write("At: could not move to target.\n");
	return 1;
}


