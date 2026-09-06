#include "../priest.h"

status
target_cmd(object who, object sym, string str) {
    string sw, tar_name, my_name;
    string tmp, *list;

    my_name = who->query_real_name();
    if(!str) {
	tmp = "Your auto-targets:\n";
	list = TARGET_D->get_list(my_name, BADDIES);
	if(!list) tmp += "(List is empty)";
	else tmp += sprintf("%-#78s", implode(list, "\n"));
	who->tell_me(tmp);
	return 1;
    }
    if(!sscanf(str, "-%s %s", sw, tar_name) && !sscanf(str, "-%s", sw)) {
	if(!TARGET_D->add_to_list(my_name, str, BADDIES))
	    return 0;
	who->tell_me("Ok.");
	return 1;
    }
    switch(sw) {
    case "clear":
	TARGET_D->clear_list(my_name, BADDIES);
	break;

    case "delete": case "del": case "d":
	if(!tar_name)
	    return notify_fail("Specify a name you want to delete.\n"),0;
	if(!TARGET_D->remove_from_list(my_name, tar_name, BADDIES))
	    return 0;
	break;

    default:
	return notify_fail("No such switch.\n"),0;
    }
    who->tell_me("Ok.");
    return 1;
}
