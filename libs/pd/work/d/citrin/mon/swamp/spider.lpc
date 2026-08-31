//  Created by Whit

#include <std.h>
#include <citrin.h>

inherit MONSTER;

int x;

string get_short() {
    if(random(2)) {
	x = 1;
	return "a black spider";
    }
    return "a green spider";
}

string *get_id() {
    if(x) 
	return ({"spider", "black spider"});
    return ({"spider", "green spider"});
}


void create() {
    ::create();
    set_name("spider");
    set_long("The spider hangs from his web waiting for unsuspecting "
      "prey.");
    set_short(get_short());
    set_id(get_id());
    set_race("spider");
    set_body_type("archnid");
    if(random(2))
	set_level(50);
    else set_level(60);
    if(random(2))
	set_gender("male");
    else set_gender("female");
}


