#include "../priest.h"

mapping targets;

#define SAVE_FILE PRIEST_SAVE_DIR "auto_targets"

#define LIST_NAMES ({"auto-target", "exclude"})

#define ERR(x) return notify_fail(x),0


create() {
    if(!restore_object(SAVE_FILE))
	targets = ([ ]);
}


string*
get_list(string my_name, int list_n) {
    string *list;

    if(!member(targets, my_name))
	targets += ([my_name: ({}); ({}) ]);
    list = targets[my_name, list_n];
    if(!sizeof(list))
	ERR(sprintf("But your %s list is empty.\n", LIST_NAMES[list_n]));
    return list;
}


status
add_to_list(string my_name, string tar_name, int list_n) {
    string *list;

    if(list = get_list(my_name, list_n)) {
	if(member(list, tar_name) >=0)
	    ERR(sprintf("'%s' is already on your %s list.\n",
		tar_name, LIST_NAMES[list_n]));
    }
    targets[my_name, list_n] += ({ lower_case(tar_name) });
    save_object(SAVE_FILE);
    return 1;
}


status
remove_from_list(string my_name, string tar_name, int list_n) {
    string *list;

    notify_fail(sprintf("'%s' is not on your %s list.\n",
	tar_name, LIST_NAMES[list_n]));
    if(!(list = get_list(my_name, list_n))) return 0;
    if(member(list, tar_name) == -1) return 0;
    targets[my_name, list_n] -= ({ lower_case(tar_name) });
    save_object(SAVE_FILE);
    return 1;
}


status
clear_list(string my_name, int list_n) {
    if(!get_list(my_name, list_n)) return 0;
    targets[my_name, list_n] = ({});
    save_object(SAVE_FILE);
    return 1;
}


object
check_baddies(object who) {
    object ob;
    string *list;
    string name;

    if(!(list = get_list(who->query_real_name(), BADDIES)))
	return 0;

    ob = first_inventory(environment(who));
    while(ob) {
	name = ob->query_name();
	if(name && (member(list, lower_case(name)) >=0) &&
	  (ob->query_guild() != GN_PRIEST))
	    return ob;
	ob = next_inventory(ob);
    }
    return 0;
}


object
check_room(object who, string tar_name) {
    object ob;
    string *good_guys;

    good_guys = get_list(who->query_real_name(), GOOD_GUYS);
    if(!good_guys) good_guys = ({});
    ob = first_inventory(environment(who));
    while(ob) {
	if(living(ob) && ob->id(tar_name) &&
	  (member(good_guys, lower_case(ob->query_name())) == -1) &&
	  (ob->query_guild() != GN_PRIEST))
	    return ob;
	ob = next_inventory(ob);
    }
    return 0;
}


object
find_without_args(object who) {
    object ob;

    if(ob = who->is_fighting())
	return ob;
    if(ob = check_baddies(who))
	return ob;
    if(ob = check_room(who, "monster"))
	return ob;
    who->tell_me("You've got no target.");
}


object
find_target(object who, string str)
{
    object ob;
    string tar_name;
    string s;

    if(!who->query_can_see()) {
	who->tell_me("You can't see anything!");
	return 0;
    }
    if(str == "") {
	if(!(ob = find_without_args(who))) return 0;
    }
    else {
	tar_name = lower_case(str);
	if(!(ob = present(tar_name, environment(who)))) {
	    if(!(ob = check_baddies(who))) {
		who->tell_me(sprintf("There's no '%s' here.", str));
		return 0;
	    }
	}
	if(!living(ob)) {
	    who->tell_me("That doesn't seem to be alive.");
	    return 0;
	}
	if(ob->query_guild() == GN_PRIEST) {
	    ob = check_room(who, tar_name);
	    if(!ob) {
		who->tell_me("You don't want to attack other priests.");
		return 0;
	    }
	}
    }
    if(ob == who) {
	who->tell_me("OK. You kill yourself. C'Mon...");
	return 0;
    }
    if(!ob->attacked_by(who, -1)) {
	s =  ob->query_objective();
	if (!s) s = "it";
	who->tell_me(sprintf("You feel " GOD_NAME " is very displeased \
because of your attempt to attack %s.",s));
	return 0;
    }
    return ob;
}

