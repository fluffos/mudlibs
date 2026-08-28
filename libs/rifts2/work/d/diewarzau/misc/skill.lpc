//	Generic skill.c to be inherited by all skills.  Major handler of
//	The DarkeMUD skills system.
//	DarkeLIB 0.1
//	Diewarzau 4/1/94

#include <std.h>

inherit OBJECT;

string query_stat();
void set_stat(string what);
int query_dev();
int query_fast_dev();
void set_dev_cost(int cost);
void set_fast_dev_cost(int cost);
string stat;

void do_skill(object from, string arg) {
    string target, args;
    object at;

    if(!arg) { this_object()->skill_func(from); return; }
    if(!props["no target"]) {
	if(sscanf(arg,"%s %s",target, args) != 2 &&
	    sscanf(arg,"%s",target) != 1) {
	    message("info","This skill requires a target",from);
	    return;
	}
	switch(props["target type"]) {
	    case "player":
		if(!props["must be present"])
		at = find_player(target);
		else at = present(target, environment(from));
		if(at && !at->is_player()) at = 0;
		break;
	    case "living":
		if(!props["must be present"])
		at = find_living(target);
		else at = present(target, environment(from));
		if(at && !living(at)) at = 0;
		break;
	    case "any":
	    default:
		at = present(target, environment(from));
		if(!at) at = present(target, from);
	}
	if(!at) {
	    message("info","Cannot find "+target+".",from);
	    return;
	}
    }
    else args = arg;
	if(!function_exists("skill_func", this_object())) {
	    message("info", "This skill is latent and cannot be used.",
		from);
	    return;
	}
    this_object()->skill_func(from,at,args);
    return;
}


string query_stat() { return stat; }

void set_stat(string what) { stat = lower_case(what); }

void set_dev_cost(int cost) { props["dev cost"] = cost; }

void set_fast_dev_cost(int cost) { props["fast dev cost"] = cost; }

int query_dev() { return props["dev cost"]; }

int query_fast_dev() { return props["fast dev cost"]; }
