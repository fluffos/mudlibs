#include <std.h>
#include <radyne.h>
#include <daemons.h>
#define CLASS     "clergy"
#define SUBCLASS  "monk"
#define ALIGNMENT 2000
inherit ROOM;
void init() {
    ::init();
    add_action("become", "become");
    add_action("go_east","east");
    add_action("preview","preview");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Entrance to the Monk Hall");
    set("long",
        "Candles illuminate the chambers of the monastery. "
        "The monks who run the monastery keep home here "
        "and initiate new believers into way of monks. "
        "A passage to the east is filled with a shimmering light. "
        "<preview> will tell you about becoming a monk.");
    set_items(
        (["candles" : "They are all over the monastery.",
          "candle" : "It burns brightly and helps light the room.",
          "monk" : "She is wandering about peacefully.",
          "passage" : "You sense that only monks may pass that way."]) );
    set_exits( 
        (["down" : ROOMS "stairs",
          "east" : "(: east :)"]) );
}
int preview() {
 if (this_player()->query_class() != "clergy" ||
     this_player()->query_subclass() != "none")  {
        message("info", "You have not the training to join.", this_player());
        return 1;
    }
    if(this_player()->query_subclass() == SUBCLASS){
        message("info", "You are already one of the chosen.", this_player());
        return 1;
    }
   say(this_player()->query_cap_name()+" seeks to learn about the monks.", 
        this_player());
    message("info", "Welcome, child!", this_player());
    message("info", "Monks make up people of many different beliefs of "
      "great faith, but they are all united in their belief in a single "
      "deity of Goodness and will devote themselves to Holy War to fight "
      "evil wherever it might be.  They are nearly fanatical about their "
      "beliefs.  To become a monk, type <become monk>,", this_player());
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
    if((string)this_player()->query_class() != "clergy") {
        write("You must choose the path of Clergy first.");
        return 1;
    }
   if (this_player()->query_subclass()!="none")
        return notify_fail("You have already chosen your path in life!");
    message("info", "The Grand Lord High Priestess initiates you into the class of monks.", this_player());
    message("other_action", this_player()->query_cap_name()+" becomes a monk.",
      this_object(), ({ this_player() }));
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start", "/d/tirun/"+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall");
   this_player()->register_channels();
    return 1;
}
int go_east() {
    if((string)this_player()->query_subclass() != SUBCLASS) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the monk's sanctuary, but fails.", this_player());
        return 1;
    }   
this_player()->move_player(ROOMS+""+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall",
                          "through the light in the passage");
    return 1;
}
