/* Cygnus@Nightmare */

#include <std.h>
#include <daemons.h>


int
cmd_users(string order) {
    int i;
    object *user_ob;
    string name, pos, room, pre_str;
    string users_on;
    string level;

    user_ob = users();
    user_ob = filter_array(user_ob,"who_on",this_object());
    user_ob = (object *)this_object()->master_sort(user_ob, order);
    if(sizeof(user_ob))
	write(sprintf("   %-16s %-15s %-12s %s",
	    "Name","Level","Position","Room")
	    +"\n------------------------------------------------------------"+
	    "-------------");
    users_on = "";

    for(i=0;i<sizeof(user_ob);i++) {
	if(stringp(user_ob[i]->query_name()))
	    name = capitalize((string)user_ob[i]->query_name());
	else
	    name = "Someone";
	if(wizardp(user_ob[i])) level = "Immortal";
        else if((int)user_ob[i]->query_level() >= 20)
          sscanf((string)ADVANCE_D->get_new_title(user_ob[i], (int)user_ob[i]->query_level()), "%s $N%*s", level);
        else if(stringp(user_ob[i]->getenv("TITLE")))
          sscanf((string)user_ob[i]->getenv("TITLE"), "%s $N%*s", level);
	else level = "New Player";
	if(!level) level = "Unknown";
	switch((string)user_ob[i]->query_position()) {
	    case "superuser":
		pos = "God";
		break;
	    case "assist":
		pos = "Archwiz";
		break;
	    default:
		if(stringp(user_ob[i]->query_position()))
		pos = capitalize((string)user_ob[i]->query_position());
		else pos = "Unknown";
	    }
        if(query_idle(user_ob[i]) > 120)
	    pre_str = "I";
	else
	    pre_str = " ";
	if(in_edit(user_ob[i]))
	    pre_str += "E";
	else
	    pre_str += " ";
	if(wizardp(this_player()) && objectp(environment(user_ob[i])))
	room = file_name(environment(user_ob[i]));
        else if(objectp(environment(user_ob[i])) && stringp(user_ob[i]->
             getenv("ROOM_KNOWN")) && (string)user_ob[i]->getenv("ROOM_KNOWN")
	     != "0")
	room = (string)environment(user_ob[i])->query_short();
	else room = "unknown";
        users_on += arrange_string(sprintf("%-3s%-16s %-15s (%|10s) %s",pre_str,
            name, level, pos, room), 72);
	users_on += "\n";
    }
    this_player()->more(explode(users_on, "\n"));
    return 1;
}

int who_on(object ob) {
    if(wizardp(this_player())) return 1;
    if(!stringp(ob->query_name())) return 0;
    if(!stringp(ob->query_short())) return 0;
    if(ob->query_invis() && wizardp(ob)) return 0;
    return 1;
}

int help_line()
{
  write( @EndText
Effect: Lists users by name, position, level, and location on the mud,
    one line per user.
EndText
  );
  return 1;
}
