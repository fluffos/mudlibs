inherit MONSTER;
 
void create() {
 ::create();
   set_name("elrih");
   set_id( ({ "elrih", "mage", "trainer" }) );
   set_short("Elrih, Grand Mage");
   set("aggressive", 0);
   set_level(50);
   set_long("A powerful magic user, Elrih trains initiates "
            "in the way of the mage.");
   set_gender("female");
   set_alignment(340);
   set("race", "illithid");
   set_exp(0);
   set_body_type("illithid");
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
    this_object()->force_me("say Now go forth and find your path in life. Find the hall "
                            "of the Necromancer, the hall of the Pyromancer, the hall of the "
                            "Sorceror, or the hall of the Wizard to join one of these "
                            "grand orders of the mage class.\n");
    shout("All hail "+(string)this_player()->query_cap_name()+" the new Mage!");
    this_player()->set_class("mage");
    this_player()->setenv("TITLE", "$N the novice magic user");
    this_player()->init_skills("mage");
    this_player()->register_channels();
    return 1;
}
