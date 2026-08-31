#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("osfrid");
   set_id( ({ "osfrid", "mage", "trainer" }) );
   set_short("Osfrid, the High Mage.");
   set("aggressive", 0);
   set_level(50);
   set_long("An old and wise mage, Osfrid stands ready to pass on his knowledge.");
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
        this_object()->force_me("say I'm sorry, I can only initiate you into the mage class.\n");
        return 1;
    }
    if((string)this_player()->query_class() != "child") {
        this_object()->force_me("say You have already chosen your way in life.");
        return 1;
    }
    this_object()->force_me("say I proclaim you to be a mage!\n");
    this_object()->force_me("Now go forth, and choose what magical path you wish to take!\n");
    this_player()->register_channels();
    this_player()->force_me("mageemote has become a Mage!");
    this_player()->set_class("mage");
    this_player()->setenv("TITLE", "$N the novice mage");
    this_player()->init_skills("mage");
    
    return 1;
}

