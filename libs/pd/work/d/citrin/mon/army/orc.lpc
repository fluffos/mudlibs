//  Created by Whit
//  Designed for multiple monsters.

#include <std.h>
#include <citrin.h>
inherit MONSTER;

string *deaths = ({ "scream", "say You will not defeat us!", 
  "say Sorry i have failed you!" });

int dead() {
    this_object()-force_me(deaths[random(sizeof(deaths))]);
    return 1;
}

void create() {
    ::create();
    set_name("orc soldier");
    set_long("The orc is a dark green color.  Its eyes glow red.");
    set_short("orc soldier");
    set_id(({"soldier", "orc soldier", "orc"}));
    set_race("orc");
    set_body_type("orc");
    set_level(60);
    set_gender("male");
    set_die( (: dead() :) );
}

