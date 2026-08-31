#include <std.h>
#include <tirun.h>
#include <daemons.h>

#define CLASS     "mage"
#define SUBCLASS  "pyromancer"
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
    set_property("no bump", 1);
    set("short", "The fire of the Pyromancers");
    set("long",
        "A great fire burns here.  This is the true birthplace "
        "of pyromancers.  The wooden walls and ceiling are charred "
        "black by their awesome flames.  Ashes are everywhere. "
        "<preview> will tell you about becoming a pyromancer.");
    set_items(
        (["fire" : "%^RED%^The flames reach high, charring the ceilng.",
          "ashes" : "The ashes are grey and black."]) );
    set_exits( 
         (["out" : ROOMS"spartin2",
           "west"  : ROOMS+""+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall"]) );
    add_pre_exit_function("west", "go_down");
}
int preview() {
 if (this_player()->query_class() != "mage" ||
     this_player()->query_subclass() != "none")  {
        message("info", "You have not the talent to join.", this_player());
        return 1;
    }
    if(this_player()->query_subclass() == SUBCLASS){
        message("info", "You are already one of the chosen.", this_player());
        return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about pyromancers.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Pyromancers are the masters of fire.  They can accomplish many devastating fire "
              "based attacks. Type <become pyromancer> to become a pyromancer.",
this_player());
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
    if((string)this_player()->query_class() != "mage") {
        write("You must choose the path of Mage first.");
        return 1;
    }
   if (this_player()->query_subclass()!="none")
        return notify_fail("You have already chosen your path in life!");

    write("The wicked pyromancer initiates you into the path of the
pyromancer.");
    say(this_player()->query_cap_name()+" becomes a pyromancer.",
this_player());
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start",
"/d/tirun/"+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall");
   this_player()->register_channels();
    return 1;
}
int go_down() {
    if(wizardp(this_player())) return 1;
    if((string)this_player()->query_subclass() != SUBCLASS) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "pyromancer's inner sanctum, but fails.", this_player());
        return 0;
    }
    return 1;
}
