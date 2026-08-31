#include <std.h>
#include <radyne.h>
#include <daemons.h>

#define CLASS     "wanderer"
#define SUBCLASS  "jester"
#define ALIGNMENT -1000

inherit ROOM;
void init() {
    ::init();
    add_action("become", "become");
    add_action("go_down","west");
    add_action("preview","preview");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_property("no bump", 1);
    set("short", "Entrance to the Jester hall");
    set("long", "This is the entrance to the Jester hall. There is a "
                "lot of laughter coming from inside the shack. This is "
                "where Jesters gather and train. You may <preview> "
                "them to see if you will choose their path of life.");
    set_items(
        (["door" : "The door is closed." ]) );
    set_exits( 
         (["south" : ROOMS"seganthus2",
           "west" : "(: down :)"]) );
}
int preview() {
 if (this_player()->query_class() != CLASS ||
     this_player()->query_subclass() != "none")  {
        message("info", "You have not the training to join.", this_player());
        return 1;
    }
    if(this_player()->query_subclass() == SUBCLASS){
        message("info", "You are already one of the chosen.", this_player());
        return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about jesters.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Jesters use their ability to entertain and cause "
                    "laughter to take advantage of people.\n "
                    "You may become one by typing <become jester>.", this_player());
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

    write("The master jester initiates you into the life path of the jester.");
    say(this_player()->query_cap_name()+" becomes a jester.", this_player());
CHAT_D->do_raw_chat("rogue", 
"%^WHITE%^"+this_player()->query_cap_name()+" has become a %^YELLOW%^jester.%^RESET%^");
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start", "/d/tirun/wand/"+SUBCLASS+"/"+SUBCLASS+"_hall");
this_player()->register_channels();
    return 1;
}
int go_down() {
    if((string)this_player()->query_subclass() != SUBCLASS) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "jester hall, but fails.", this_player());
        return 1;
    }
    
this_player()->move_player(ROOMS+"wand/"+SUBCLASS+"/"+SUBCLASS+"_hall",
                          "through the door");
    return 1;
}
