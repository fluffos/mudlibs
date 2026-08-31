#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("jeale keljorm");
   set_id( ({ "jeale", "rogue", "trainer", "keljorm", "jeale keljorm" }) );
   set_short("Jeale Keljorm, the Grand Rogue Master.");
   set("aggressive", 0);
   set_level(50);
   set_long("One of the oldest rogues in all the lands, which is amazing in of itself. Jeale now trains youths in the art of the rogue. He is always willing to train any young rogue in any of the fine types of thuggery.");
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
    if(str != "assassin" && str != "thug" && str != "scout" && str != "thief") {
        this_object()->force_me("say I'm sorry, I don't know how to train you in that.\n");
        return 1;
    }
    if((string)this_player()->query_subclass() != "none") {
        this_object()->force_me("say You have already chosen your way in life.");
        return 1;
    }
    if(str == "assassin")
    {
        this_object()->force_me("say I proclaim you to be an Assassin!\n");
        this_object()->force_me("say Now go forth, and take many contracts!\n");
        this_player()->force_me("rogueemote has become an Assassin!");
        this_player()->set_subclass("assassin");
        this_player()->setenv("TITLE", "$N the murderer");
        this_player()->init_skills("rogue");
        this_player()->register_channels();
    }
    if(str == "thug")
    {
        this_object()->force_me("say I proclaim you to be a Thug!\n");
        this_object()->force_me("say Now go forth, and shake down many a poor soul!\n");
        this_player()->force_me("rogueemote has become a Thug!");
        this_player()->set_subclass("thug");
        this_player()->setenv("TITLE", "$N the troubled youth");
        this_player()->init_skills("rogue");
        this_player()->register_channels();
    }
    if(str == "scout")
    {
        this_object()->force_me("say I proclaim you to be a Scout!\n");
        this_object()->force_me("say Now go forth, and learn the land as none before you!\n");
        this_player()->force_me("rogueemote has become a Scout!");
        this_player()->set_subclass("scout");
        this_player()->setenv("TITLE", "$N the world traveller");
        this_player()->init_skills("rogue");
        this_player()->register_channels();
    }
    if(str == "thief")
    {
        this_object()->force_me("say I proclaim you to be a Thief!\n");
        this_object()->force_me("say Now go forth, and take all ye can, and give nothing back!\n");
        this_player()->force_me("rogueemote has become a Thief!");
        this_player()->set_subclass("thief");
        this_player()->setenv("TITLE", "$N the innocent looking");
        this_player()->init_skills("rogue");
        this_player()->register_channels();
    }
    return 1;
}

