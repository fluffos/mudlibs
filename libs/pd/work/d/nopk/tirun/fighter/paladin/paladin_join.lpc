#include <std.h>
#include <tirun.h>
#include <daemons.h>
#define CLASS     "fighter"
#define SUBCLASS  "paladin"
#define ALIGNMENT 2000
inherit ROOM;
void init() {
    ::init();
    add_action("become", "become");
    add_action("preview","preview");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Entrance to the Paladin hall");
    set("long",
        "People of many beliefs come here to say prayers for themselves "
        "and others.  The paladins of the church also initiate young "
        "adventurers into the subclass of paladins.  <preview> will tell you "
        "about becoming a paladin.");
    set_items(
        (["church" : "It holds a small chapel for wedding ceremonies "
            "west, and there is an inner sanctum for clerics north",
          "light" : "A %^BLUE%^blue%^RESET%^ light protects this place.",
          "passage" : "It leads down into the paladin's inner sanctum."]) );
    set_exits( 
         (["up" : ROOMS"church",
           "down" : ROOMS+""+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall"]) );
    add_pre_exit_function("down","go_down");
}
int preview() {
 if (this_player()->query_class() != "fighter" ||
     this_player()->query_subclass() != "none")  {
        message("info", "You have not the training to join.", this_player());
        return 1;
    }
    if(this_player()->query_subclass() == SUBCLASS){
        message("info", "You are already one of the chosen.", this_player());
        return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about paladins.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Paladins are deeply religious fighters of greatly varied "
        "beliefs, yet united in their belief in the sanctity of the world.  They "
        "defend the realms from the darkness of evil.  Their faith in good "
        "gives them great healing powers as well as powers of protection.  "
        "Destruction is the most horrible of evils to them, and they will "
        "lose the powers they have through prayer if they become too "
        "destructive.  Type <become paladin> to become a paladin.", this_player());
    return 1;
}
int become(string str) {
    if(!str) {
        notify_fail("Become what?\n");
        return 0;
    }
    if(str != SUBCLASS) {
        notify_fail("You cannot become that here.\n");
        return 0;
    }
     if((string)this_player()->query_race() == "demon") {
        write("You are a demon!");
        return 1;
     }
    if((string)this_player()->query_class() != "fighter") {
        write("You must choose the path of Fighter first.");
        return 1;
    }
   if (this_player()->query_subclass()!="none")
        return notify_fail("You have already chosen your path in life!");
    write("The Holy Warrior initiates you into the life path of the paladins.");
    say(this_player()->query_cap_name()+" becomes a paladin.", this_player());
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start", "/d/tirun/"+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall");
   this_player()->register_channels();
    return 1;
}
int go_down() {
    if(wizardp(this_player())) return 1;
    if((string)this_player()->query_subclass() != SUBCLASS) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "paladin's inner sanctum, but fails.", this_player());
        return 0;
    }
    return 1;
}
