#include <std.h>
#include <radyne.h>
#include <daemons.h>
#define CLASS     "fighter"
#define SUBCLASS  "antipaladin"
#define ALIGNMENT -1500
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
    set("short", "Entrance to the Antipaladin hall");
    set("long",
        "Fighters burning with hatred for the order of Paladins come here to "
        "devote their lives to evil.  Antipaladin initiate anyone evil into their "
        "dark ranks.  <preview> will tell you about becoming an antipaladin.");
    set_items(
        ([
          "light" : "A %^BLUE%^blue%^RESET%^ light protects this place.",
          "passage" : "It leads down into the paladin's inner sanctum."]) );
    set_exits( 
         (["out" : "/d/standard/cemetary/building",
           "up" : "(: up :)"]) );
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
    message("info", (string)this_player()->query_cap_name()+" seeks to learn about antipaladin.", this_object(), ({ this_player() }));
    message("info", "Welcome, child!", this_player());
    message("info", "Antipaladins are darkly evil fighters of greatly varied "
        "beliefs, yet united in their wanton destruction of the world.  They "
        "search the realms looking to spreas evil.  Their love of evil "
        "gives them great powers from the evil gods of the realms.  "
        "Destruction is the greatest of accomplishments for them, and they will "
        "lose the powers they have through prayer if they become too "
        "good.  Type <become antipaladin> to become an antipaladin.", this_player());
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
    write("The Evil One initiates you into the life path of the antipaladin.");
    say(this_player()->query_cap_name()+" becomes an antipaladin.", this_player());
    this_player()->set_subclass(SUBCLASS);
    this_player()->set_alignment(ALIGNMENT);
    this_player()->setenv("TITLE", "$N the novice "+SUBCLASS);
    this_player()->init_skills(CLASS);
    this_player()->setenv("start", "/d/tirun/"+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall");
   this_player()->register_channels();
    return 1;
}
int go_up() {
    if((string)this_player()->query_subclass() != SUBCLASS) {
        write("You cannot penetrate the force field that blocks the passage.");
        say(this_player()->query_cap_name()+" tries to get into the "
            "antipaladin's inner sanctum, but fails.", this_player());
        return 1;
    }
    
this_player()->move_player(ROOMS+""+CLASS+"/"+SUBCLASS+"/"+SUBCLASS+"_hall",
                          "through the light in the passage");
    return 1;
}
