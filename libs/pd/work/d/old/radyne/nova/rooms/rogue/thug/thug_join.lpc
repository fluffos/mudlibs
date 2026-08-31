#include <std.h>
#include <radyne.h>
#include <daemons.h>
#define CLASS     "rogue"
#define SUBCLASS  "thug"
#define ALIGNMENT -500
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
    set("short", "A tunnel");
    set("long",
        "The tunnel is a dead end. There is not much in this room. "
        "The tunnel walls are dry. The floor has been swept clean. "
        "The only exits seem to be through a door on the north wall or south. "
        "<preview> to find out more about becoming a thug.");
    set_items(
        ([
          "light" : "A %^BLUE%^blue%^RESET%^ light protects this place.",
          "passage" : "It leads down into the thug's inner sanctum."]) );
    set_exits( 
         (["south" : ROOMS"rogue/rogue2",
           "enter" : "(: enter :)"]) );
}
int preview() {
 if (this_player()->query_class() != "rogue" ||
     this_player()->query_subclass() != "none")  {
        message("info", "You have not the training to join.", this_player());
        return 1;
    }
    if(this_player()->query_subclass() == SUBCLASS){
        message("info", "You are already one of the thugs.", this_player());
        return 1;
    }
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about bards.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "thugs are the losest of the low. Not really evil, "
                    "but they would sell their own mothers.  Thugs try "
                    "to lie, cheat, and steal their way to the top. "
                    "<become thug> to join this nasty group of rogues. ", this_player());
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
    if((string)this_player()->query_class() != "rogue") {
        write("You must choose the path of Rogue first.");
        return 1;
    }
   if (this_player()->query_subclass()!="none")
        return notify_fail("You have already chosen your path in life!");
    write("The Shameless One initiates you into the life path of the thug.");
    say(this_player()->query_cap_name()+" becomes a thug.", this_player());
// CHAT_D->do_raw_chat("fighter", "%^WHITE%^"+this_player()->query_cap_name()+" has become a %^RED%^bard.%^RESET%^");
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start", "/d/tirun/"+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall");
   this_player()->register_channels();
    return 1;
}
int go_enter() {
    if((string)this_player()->query_subclass() != SUBCLASS) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "thug's inner sanctum, but fails.", this_player());
        return 1;
    }
    
this_player()->move_player(ROOMS+""+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall",
                          "through the light in the passage");
    return 1;
}
