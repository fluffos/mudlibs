#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("cearl");
   set_id( ({ "cearl", "father cearl", "clergy", "trainer" }) );
   set_short("Father Cearl, the High Priest.");
   set("aggressive", 0);
   set_level(50);
   set_long("Father Cearl is one of the oldest people living in Lidelas, he
teaches people the way of the church.");
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
the clergy class.\n");
        return 1;
    }
    if((string)this_player()->query_class() != "child") {
        this_object()->force_me("say You have already chosen your way in
life.");
        return 1;
    }
    this_object()->force_me("say I proclaim you to be a clergy!\n");
    this_object()->force_me("Now go forth, and choose how to serve!\n");
    this_player()->force_me("clergyemote has become a Clergy!");
    this_player()->set_class("clergy");
    this_player()->setenv("TITLE", "$N the believer");
    this_player()->init_skills("clergy");
    this_player()->register_channels();
    return 1;
}
