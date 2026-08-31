#include <std.h>
#include <radyne.h>
#include <daemons.h>
#define CLASS     "clergy"
#define SUBCLASS  "cleric"
#define ALIGNMENT 2000
inherit ROOM;
void init() {
    ::init();
    add_action("become", "become");
    add_action("go_up","up");
    add_action("preview","preview");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Entrance to the Cleric Hall");
    set("long",
        "People of many beliefs come here to say prayers for themselves "
        "and others.  The clerics of the church also initiate young "
        "adventurers into the class of clerics.  <preview> will tell you "
        "about becoming a cleric.");
    set_items(
        (["church" : "It holds a small chapel for wedding ceremonies "
            "west, and there is an inner sanctum for clerics north",
          "chapel" : "The clerics of the church perform wedding "
            "ceremonies there.",
          "light" : "A %^BLUE%^blue%^RESET%^ light protects this place.",
          "passage" : "It leads north into the cleric's inner sanctum."]) );
    set_exits( 
         (["down" : ROOMS"hospital",
           "up" : "(: up :)"]) );
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
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about clerics.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Clerics are deeply religious people of greatly varied "
        "beliefs, yet united in their belief in the sanctity of the natural world.  Their "
        "ability to get in touch with the unity of thier gods through prayer "
        "gives them great healing powers as well as powers of protection.  "
        "Destruction is the most horrible of evils to them, and they will "
        "lose the powers they have through prayer if they become too "
        "destructive.  Type <become cleric> to become a cleric.", this_player());
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
    write("The High Priestess of Clerics initiates you into the life path of clerics.");
    say(this_player()->query_cap_name()+" becomes a cleric.", this_player());
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start", "/d/radyne/nova/rooms/"+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall");
   this_player()->register_channels();
    return 1;
}
int go_up() {
    if((string)this_player()->query_subclass() != SUBCLASS) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "cleric's inner sanctum, but fails.", this_player());
        return 1;
    }   
this_player()->move_player(ROOMS+""+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall",
                          "through the light in the passage");
    return 1;
}
