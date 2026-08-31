#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("swidhelm");
   set_id( ({ "swidhelm", "rogue", "trainer" }) );
   set_short("Swidhelm, the Deadly Rogue.");
   set("aggressive", 0);
   set_level(50);
   set_long("A wise and old rogue, Swidhelm trains initiates in the way of the rogue.");
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
    if(str != "rogue") {
        this_object()->force_me("say I'm sorry, I can only initiate you into the rogue class.\n");
        return 1;
    }
    if((string)this_player()->query_class() != "child") {
        this_object()->force_me("say You have already chosen your way in life.");
        return 1;
    }
    this_object()->force_me("say I proclaim you to be a rogue!\n");
    this_object()->force_me("Now go forth, and choose how you wish to plunder these lands!\n");
    this_player()->force_me("rogueemote has become a Rogue!");
    this_player()->set_class("rogue");
    this_player()->setenv("TITLE", "$N the petty criminal");
    this_player()->init_skills("rogue");
    this_player()->register_channels();
    return 1;
}

