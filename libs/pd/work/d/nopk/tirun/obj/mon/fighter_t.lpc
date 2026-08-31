inherit MONSTER;
 
void create() {
 ::create();
   set_name("drelamar");
   set_id( ({ "drelamar", "fighter", "trainer" }) );
   set_short("Drelamar, Master of Arms");
   set("aggressive", 0);
   set_level(50);
   set_long("A seasoned veteran of combat, Drelamar trains initiates "
            "in the way of the fighter.");
   set_gender("male");
   set_alignment(340);
   set("race", "sauran");
   set_exp(0);
   set_body_type("sauran");
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
    if(str != "fighter") {
        this_object()->force_me("say I'm sorry, I can only initiate you into the fighter class.\n");
        return 1;
    }
    if((string)this_player()->query_class() != "child") {
        this_object()->force_me("say You have already chosen your way in life.");
        return 1;
    }
    shout("All hail "+(string)this_player()->query_cap_name()+" the new Fighter!");
    this_object()->force_me("say I proclaim you to be a fighter!\n");
    this_object()->force_me("say Now go forth and find your path in life. Find the hall "
                            "of the Berserker, the hall of the Paladin, the hall of the "
                            "Ranger, or the hall of the Warrior to join one of these "
                            "grand orders of the fighter class. I warn you though, there "
                            "are rumours of Antipaladins who have no honor.\n");
    this_player()->set_class("fighter");
    this_player()->setenv("TITLE", "$N the novice page");
    this_player()->init_skills("fighter");
    this_player()->register_channels();
    return 1;
}
