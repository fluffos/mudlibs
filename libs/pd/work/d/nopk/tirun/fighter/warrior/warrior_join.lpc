#include <std.h>
#include <tirun.h>
#include <daemons.h>

#define CLASS     "fighter"
#define SUBCLASS  "warrior"
#define ALIGNMENT 500

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
    set_property("no bump", 1);
    set("short", "Entrance to the Warrior hall");
    set("long",
        "There are several sweaty warriors standing outside the door. "
        "This is where the warriors come to train in their skills and "
        "to initiate new warriors. You may <preview> them, as this will "
        "give you information on the way of warriors.");
    set_items(
        (["door" : "The door is closed." ]) );
    set_exits( 
         (["out" : ROOMS"sganthus",
           "east" : ROOMS"fighter/warrior/warrior_hall"]) );
    add_pre_exit_function("east", "go_down");
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
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about warriors.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Warriors are very intense trainers of combat."
                    " You may become one by typing <become warrior>.", this_player());
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
    if((string)this_player()->query_class() != "fighter") {
        write("You must choose the path of Fighter first.");
        return 1;
    }
   if (this_player()->query_subclass()!="none")
        return notify_fail("You have already chosen your path in life!");

    write("The Grand Warrior initiates you into the life path of the warriors.");
    say(this_player()->query_cap_name()+" becomes a warrior.", this_player());
// CHAT_D->do_raw_chat("fighter", "%^WHITE%^"+this_player()->query_cap_name()+" has become a %^ORANGE%^warrior.%^RESET%^");
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
            "warriors hall, but fails.", this_player());
        return 0;
    }
    return 1;
}
