#include <std.h>
#include <tirun.h>
#include <daemons.h>
#define CLASS     "wanderer"
#define SUBCLASS  "bard"
#define ALIGNMENT 0
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
    set("short", "Entrance to the bard hall");
    set("long",
        "The basement of the pub is a little gloomy, but being so "
        "close to the bar makes it the perfect place for bards to call home. "
       "Bards are in and out of here quite a bit."
        "<preview> to find out more about becoming a bard.");
    set_items(
        ([
          "light" : "A %^BLUE%^blue%^RESET%^ light protects this place.",
          "passage" : "It leads down into the paladin's inner sanctum."]) );
    set_exits( 
         (["up" : ROOMS"pub",
           "south" : ROOMS+"wand/"+SUBCLASS+"/"+SUBCLASS+"_hall"]) );
    add_pre_exit_function("south", "go_south");
}
int preview() {
 if (this_player()->query_class() != "wanderer" ||
     this_player()->query_subclass() != "none")  {
        message("info", "You have not the training to join.", this_player());
        return 1;
    }
    if(this_player()->query_subclass() == SUBCLASS){
        message("info", "You are already one of the singers.", this_player());
        return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about bards.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Bards are people of soong and free spirit. Travelling the realms "
                    "spreading entertainment as they go. Using songs, they give help "
                    "where needed and get donations for their pay."
                    "Type <become bard> to become a bard.", this_player());
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
    write("The Great Bard of Tirun initiates you into the life path of the bard.");
    say(this_player()->query_cap_name()+" becomes a bard.", this_player());
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start", "/d/tirun/"+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall");
this_player()->register_channels();
    return 1;
}
int go_south() {
    if(wizardp(this_player())) return 1;
    if((string)this_player()->query_subclass() != SUBCLASS) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "bard's inner sanctum, but fails.", this_player());
        return 0;
    }
    return 1;
}
