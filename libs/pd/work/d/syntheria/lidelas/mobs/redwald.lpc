#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("Redwald");
   set_id( ({ "redwald", "fighter", "trainer" }) );
   set_short("Redwald, the Ancient Fighter.");
   set("aggressive", 0);
   set_level(50);
set_long("One of the oldest living fighters ever, Redwald is the ripe age of
forty. Few have seen as much combat as this grizzled warrior.");
   set_gender("male");
   set_alignment(340);
   set("race", "human");
   set_exp(0);
   set_body_type("human");
   set_property("no bump", 1);
}

void init()
{
 ::init();
 add_action("fBecome", "become");
}

int fBecome(string str) {
    if(!str) {
        this_object()->force_me("say Become what?\n");
        return 1;
    }
    if(str != "mage") {
        this_object()->force_me("say I'm sorry, I can only initiate you into
the fighter class.\n");
        return 1;
    }
    if((string)this_player()->query_class() != "child") {
        this_object()->force_me("say You have already chosen your way in
life.");
        return 1;
    }
    this_object()->force_me("say I proclaim you to be a fighter!\n");
    this_object()->force_me("Now go forth, and choose how you wish to
fight!\n");
    this_player()->force_me("fighteremote has become a Fighter!");
    this_player()->set_class("fighter");
    this_player()->setenv("TITLE", "$N the novice mage");
    this_player()->init_skills("fighter");
    this_player()->register_channels();
    return 1;
}
