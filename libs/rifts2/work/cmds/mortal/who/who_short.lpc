/* Cygnus@Nightmare */

#include <std.h>


int
cmd_short(string order) {
    int i;
    object *user_ob;
    string name, *user_name;

    user_ob = users();
    user_ob = (object *)this_object()->master_sort(user_ob,order);
    user_name = ({ });
    for (i = 0; i < sizeof(user_ob); i++) {
        if ((wizardp(user_ob[i]) && user_ob[i]->query_invis()) ||
	    !user_ob[i]->is_player())
	    continue;
	name = (string)user_ob[i]->query_name();
	if (stringp(name))
	    user_name += ({ capitalize(name) });
    }
	write(format_page(user_name, 4));
	write(sprintf("Total : %d", sizeof(user_name)));
    return 1;
}

int
sort_names(string name1, string name2) {
    if (name1 == name2)
	return 0;
    if (name1 < name2)
	return -1;
    else
	return 1;
}

int help_short()
{
  write( @EndText
Effect: Lists the names of player logged in. 
        A shorter and quicker version of "who"
EndText
  );
  return 1;
}
