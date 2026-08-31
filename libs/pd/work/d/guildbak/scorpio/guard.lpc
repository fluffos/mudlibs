#include <std.h>

inherit MONSTER;

void create() {
    ::create();
    set_name("Scorpion King");
    set_short("The Scorpion King");
    set_long("This is the Scorpion King. Although he was "
      "frozen and buried, he was dug up by the spawn of "
      "Rejik. He is still alive however, and is willing "
      "to kill anyone who threatens his guild.");
    set_race("gnoll");
    set_body_type("gnoll");
    set_level(30);
    set_class("mage");
    set_subclass("wizard");
    set_id(({ "king", "guild guard", "scorpian king" }));
}

void init() {
    object *ob;
    int i;
    ::init();

    ob = this_object()->query_hunted();
    if(member_array(this_player(), ob) == -1 ) i = 1;

    ob = this_object()->query_attackers();
    if(member_array(this_player(), ob) == -1 ) i = 1;

    if(this_player()->query_guild() != "scorpio" && this_player()->is_player())
	if(i == 1) 
	    this_object()->force_me("kill "+this_player()->query_name());
}

