#include <std.h>
#include <radyne.h>
#include <daemons.h>
#define CLASS     "wanderer"
#define SUBCLASS  "swashbuckler"
#define ALIGNMENT 0
inherit ROOM;
void init() {
    ::init();
    add_action("become", "become");
    add_action("go_enter","enter");
    add_action("preview","preview");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "A gypsy's wagon");
    set("long",
        "The room is a simple wooden cubical.  Swashbucklers had rather be out "
        "wanderering than be in here decorating.  They are just glad John gave "
        "them the room for free."
        "<preview> to find out more about becoming a swashbuckler.");
    set_items(
        ([
          "light" : "A %^BLUE%^blue%^RESET%^ light protects this place.",
          "passage" : "It leads down into the gypsy's inner sanctum."]) );
    set_exits( 
         (["out" : ROOMS"boatstore",
           "enter" : "(: enter :)"]) );
}
int preview() {
 if (this_player()->query_class() != "wanderer" ||
     this_player()->query_subclass() != "none")  {
        message("info", "You have not the training to join.", this_player());
        return 1;
    }
    if(this_player()->query_subclass() == SUBCLASS){
        message("info", "You are already a swashbuckler.", this_player());
        return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about swashbuckler.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Swashbucklers are fun loving, adventuring, trick swords. "
                    "They wander the land showing off their skill with a blade. "
                    "While this skill rivals that of a fighter, they are not warriors. "
"Type <become swashbuckler> to become a swashbuckler.", this_player());
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
    if((string)this_player()->query_class() != "wanderer") {
        write("You must choose the path of Wanderer first.");
        return 1;
    }
   if (this_player()->query_subclass()!="none")
        return notify_fail("You have already chosen your path in life!");
    write("The Grand Gypsy initiates you into the life path of the swashbuckler.");
    say(this_player()->query_cap_name()+" becomes a swashbuckler.", this_player());
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start", "/d/tirun/wand/"+SUBCLASS+"/"+SUBCLASS+"_hall");
this_player()->register_channels();
    return 1;
}
int go_enter() {
    if((string)this_player()->query_subclass() != SUBCLASS) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "swashbuckler's inner sanctum, but fails.", this_player());
        return 1;
    }
    
this_player()->move_player(ROOMS+"wand/"+SUBCLASS+"/"+SUBCLASS+"_hall",
                          "through the light in the passage");
    return 1;
}
