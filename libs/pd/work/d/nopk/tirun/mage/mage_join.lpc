#include <std.h>
#include <tirun.h>
inherit ROOM;
void init() {
    ::init();
    add_action("preview","preview");
}
void create() {
    ::create();
 set_properties( ([ "no attack"   : 1,
                    "no magic"    : 1,
                    "light"       : 2,
                    "night light" : 2]) );
    set("short", "The mage hall.");
    set("long",
        "The inside of the hall impossibly occupies more space than "
        "its physical size!  Torches circle the stone walls of the "
        "hall, giving it a magical light.  A flight of stairs leads "
        "up into the heart of the tower.  The stairs are glowing with "
        "a %^BLUE%^blue%^RESET%^ "
        "light.  <preview> will tell you about becoming a mage.");
    set_items(
        ([
          "light" : "You are certain that it is a field which allows "
            "only mages to pass.",
          "walls" : "They are made from a single slab of solid granite. An "
            "opening leads outside.",
          "stairs" : "They are very nice.",
          "torch" : "It is locked magically into the wall.",
          "opening" : "It leads out to Honin Road.",
          "torches" : "They create an eerie glow to the room."]) );
    set_exits( 
         (["out" : ROOMS "ehonin4",
           "up" : ROOMS "mage_hall"]) );
    add_pre_exit_function("up", "go_up");
}
void reset()
{
 if (!present("trainer"))
   new(MOB "mage_t")->move(this_object());
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
int go_up() {
    if(wizardp(this_player())) return 1;
    if((string)this_player()->query_class() != "mage") {
        message("my_action", "You cannot penetrate the force field that blocks the passage.", this_player());
        message("other_action", this_player()->query_cap_name()+" tries to get into the mage's sanctuary, but fails.", this_object(), ({this_player() }));
        return 0;
    }
    return 1;
}
