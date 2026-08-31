#include <std.h>
#include <events.h>

inherit OBJECT;

void create() {
    ::create();
    set_name("staff of immortals");
    set_long("The staff seems pretty simple for something "
      "so fit for immortals.  An old woodvine crawls up "
      "the side.  However a strange type of heat is emmitting "
      "from it.");
    set_short("staff of immortals");
    set_weight(50);
    set_id(({"staff","staff of immortals"}));
}

void init() {
    ::init();
    add_action("endevent", "endevent");
}

int endevent() {
    write("Ending event.");
#ifndef EVENT
    write("Cannot end.  Event is not defined.\n");
    return 0;
#endif
    call_out("the_end", 5);
    return 1;
}

int the_end() {
    message("info", "%^BOLD%^%^YELLOW%^A bright flash lights "
      "up the skys.  A loud crackling noise is heard throughout "
      "the realms.", users());
    call_out("con_end", 10);
    return 1;
}

int con_end() {
    if(find_player())
	find_player("desmos")->force_me("shout You will never hold me for long.");	
    else message("info", "Desmos shouts: You will never hold me for long!", users());
    message("info", "The voice of Desmos fades as his soul and very "
      "essence is absorbed into the ground.", users());
    find_player("desmos")->invis();
    find_player("desmos")->quit();
    return 1;
}

int finish_end() {
    message("info", "%^RED%^%^BOLD%^the messenger tells you:%^RESET%^ "
      "After many long hours of fighting.  The evil overlord demon "
      "Desmos' soul has been banished forever.  Never again shall he "
      "be able to walk Primal Darkness making it safer for all.  With "
      "Desmos gone i have served my purpose here for now.  Perhaps "
      "another day i shall return if evil again rears its evil "
      "head.", users());
    return 1;
}


