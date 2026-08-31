#include <std.h>
#include <radyne.h>
inherit ROOM;
void init() {
    ::init();
    add_action("become", "become");
    add_action("go_down","down");
    add_action("preview","preview");
}
void create() {
    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "Inside a tree");
    set("long",
        "The inside of the hall impossibly occupies more space than "
        "its physical size!  Torches circle the stone walls of the "
        "hall, giving it a magical light.  A flight of stairs leads "
        "down into a hole in the ground protected by a magical "
        "%^BLUE%^blue%^RESET%^ "
        "light.  The High Mage Warlock waits here to initiate aspiring "
        "magic users into the mysterious class of the mages.  "
        "<preview> will tell you about becoming a mage.");
    set_items(
        (["hall" : "Like Dr. Who's tardis, bigger inside than outside.",
          "hole" : "The hole leads down into an undergorund room.",
          "light" : "You are certain that it is a field which allows "
            "only mages to pass.",
          "walls" : "They are made from a single slab of solid granite. An "
            "opening leads outside.",
          "stairs" : "They are very nice.",
          "torch" : "It is locked magically into the wall.",
          "warlock" : "He awaits to initiate new mages.",
          "mage" : "He awaits to initiate new mages and explain "
            "the difference between transitive and intransitive verbs.",
          "opening" : "It leads out to Honin Road.",
          "torches" : "They create an eerie glow to the room."]) );
    set_exits( 
     (["out" : ROOMS "tr04e",
           "down" : "(: down :)"]) );
}
int preview() {
    if((string)this_player()->query_class() != "child") {
        message("info", "This is not for you.", this_player());
        return 1;
    }
    message("other_action", this_player()->query_cap_name()+" seeks to learn about mages.", this_object(), ({this_player()}));
    message("info", "Welcome, child!", this_player());
    message("info", "Mages have no overriding beliefs which unite them, but instead "
        "they are united in their love of the art of magic.  Some of them "
        "are devoted practitioners of white magic, while others are evil "
        "dark mages.  Their magical arts are centered around those "
        "which will most help them along in the material world, the arts "
        "of conjuring and magical combat.  To become a mage, type <become mage> "
        "and strike out now and find your path in life, go and find the hall "
        "of the Necromancer, the hall of the Pyromancer, the hall of the Sorceror, "
        "or the hall of the Wizard.", this_player());
    return 1;
}
int become(string str) {
    if(!str) {
        notify_fail("Become what?\n");
        return 0;
    }
    if(str != "mage") {
        notify_fail("You cannot become that here.\n");
        return 0;
    }
    if((string)this_player()->query_class() != "child") {
        message("my_action", "You are much too old to start learning our ways now!", this_player());
        return 1;
    }
    message("my_action", "The High Mage Warlock initiates you into the class of mages.", this_player());
    message("other_action", this_player()->query_cap_name()+" becomes a mage.", this_object(), ({this_player()}));
    this_player()->set_class("mage");
    this_player()->setenv("TITLE", "$N the novice mage");
    this_player()->init_skills("mage");
   this_player()->register_channels();
    return 1;
}
int go_down() {
    if((string)this_player()->query_class() != "mage") {
        message("my_action", "You cannot penetrate the force field that blocks the passage.", this_player());
        message("other_action", this_player()->query_cap_name()+" tries to get into the mage's sanctuary, but fails.", this_object(), ({this_player() }));
        return 1;
    }
    this_player()->move_player(ROOMS "mage_hall", "through the light in the passage");
    return 1;
}
