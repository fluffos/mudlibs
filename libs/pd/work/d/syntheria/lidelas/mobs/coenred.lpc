#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("coenred");
   set_id( ({ "coenred", "wanderer", "trainer" }) );
   set_short("Coenred, the seasoned wanderer.");
   set("aggressive", 0);
   set_level(50);
   set_long("A seasoned wanderer, Coenred trains initiates in the way of the wanderer.");
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
    if(str != "wanderer") {
        this_object()->force_me("say I'm sorry, I can only initiate you into the wanderer class.\n");
        return 1;
    }
    if((string)this_player()->query_class() != "child") {
        this_object()->force_me("say You have already chosen your way in life.");
        return 1;
    }
    this_object()->force_me("say I proclaim you to be a wanderer!\n");
    this_object()->force_me("Now go forth, and choose how you wish to wander these lands!\n");
    this_player()->force_me("wandereremote has become a Wanderer!");
    this_player()->set_class("wanderer");
    this_player()->setenv("TITLE", "$N the novice traveler");
    this_player()->init_skills("wanderer");
    this_player()->register_channels();
    return 1;
}

