// Created by Cyanide
// 12 July 2000

#include "/u/c/cyanide/debug.h"
#define NO_FOLLOWERS "You have no followers at the moment.\n"

inherit DAEMON;

int cmd_followers() {
    object *followers;
    int num, i;

    if (undefinedp(TP->query("followers"))) {
	write(NO_FOLLOWERS);
	return 1;
    }

    followers = (object *)TP->query("followers");
    followers = filter_array(followers, "filter_followers", TO);

    num = sizeof(followers);
    if (!num) {
	write(NO_FOLLOWERS);
	return 1;
    }

    for (i=0; i<num; i++) {
	int hp;
	string str = ""+(i+1)+"> ";

	str += sprintf("%|20s", followers[i]->query("cap_name"));

	hp = (int)followers[i]->query("hit_points") * 100;
	hp /= (int)followers[i]->query("max_hp");
	str += "  " + sprintf("%-11s",
	  "HP: "+hp+"%"
	);

	write(str + "\n");
    }

    write("You have "+num+" followers.\n");

    return 1;
}

int filter_followers( object ob ) {
    if (!ob) return 0;
    return 1;
}

