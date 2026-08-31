#include <std.h>
inherit MONSTER;
void create() {
 ::create();
   set_name("ryrr");
   set_id( ({ "ryrr", "wanderer", "trainer" }) );
   set_short("Ryrr, the Grand Entertainer");
   set("aggressive", 0);
   set_level(50);
   set_long("A seasoned entertainer, Ryrr trains initiates "
            "in the way of the wanderer.");
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
    this_object()->force_me("say Now go forth and find your path in life. Find the hall "
                            "of the Bard, the hall of the Gypsy, the hall of the "
                            "Jester, or the hall of the Swashbuckler to join one of these "
                            "grand orders of the wanderer class.\n");
    shout("All hail "+(string)this_player()->query_cap_name()+" the new Wanderer!");
    this_player()->set_class("wanderer");
    this_player()->setenv("TITLE", "$N the novice traveler");
    this_player()->init_skills("wanderer");
    this_player()->register_channels();
    return 1;
}
