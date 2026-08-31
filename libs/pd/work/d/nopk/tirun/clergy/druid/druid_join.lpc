#include <std.h>
#include <tirun.h>
#include <daemons.h>
#define CLASS     "clergy"
#define SUBCLASS  "druid"
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
    set("short", "Entrance to the Druid Hall");
    set("long",
        "Welcome to the church of Nature. "
        "People of many beliefs come here to say prayers for themselves "
        "and others. The druids of the church also initiate young "
        "adventurers into the class of druids. <preview> will tell you "
        "about becoming a druid.  There is a passage up.");
    set_items(
        ([
          "light" : "A %^BLUE%^blue%^RESET%^ light protects this place.",
          "passage" : "It leads north into the cleric's inner sanctum."]) );
    set_exits( 
         (["out" : ROOMS"clergy/druid/druid_tree",
           "up" : ROOMS+""+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall"]) );
    add_pre_exit_function("up","go_up");
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
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about druids.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Druids are deeply religious people of greatly varied "
       "beliefs, yet united in their belief in the sanctity of the natural world.  Their "
        "ability to get in touch with the unity of nature through prayer "
        "gives them great healing powers as well as powers of protection.  "
        "Destruction is the most horrible of evils to them, and they will "
        "lose the powers they have through prayer if they become too "
        "destructive.  Type <become druid> to become a druid.", this_player());
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
    if((string)this_player()->query_class() != "clergy") {
        write("You must choose the path of Clergy first.");
        return 1;
    }
   if (this_player()->query_subclass()!="none")
        return notify_fail("You have already chosen your path in life!");
    write("The High Priest of Druids initiates you into the life path of druids.");
    say(this_player()->query_cap_name()+" becomes a druid.", this_player());
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start", "/d/tirun/"+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall");
   this_player()->register_channels();
    return 1;
}
int go_up() {
    if(wizardp(this_player())) return 1;
    if((string)this_player()->query_subclass() != SUBCLASS) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "druid's inner sanctum, but fails.", this_player());
        return 0;
    }   
    return 1;
}
