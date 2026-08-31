inherit MONSTER;
 
void create() {
 ::create();
   set_name("pelissi");
   set_id( ({ "pelissi", "clergy", "trainer" }) );
   set_short("Pelissi, Priestess of Faith");
   set("aggressive", 0);
   set_level(50);
   set_long("A faithful priestess, Pelissi trains initiates "
            "in the way of the clergy.");
   set_gender("female");
   set_alignment(340);
   set("race", "archangel");
   set_exp(0);
   set_body_type("archangel");
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
    if(str != "clergy") {
        this_object()->force_me("say I'm sorry, I can only initiate you into the clergy class.\n");
        return 1;
    }
    if((string)this_player()->query_class() != "child") {
        this_object()->force_me("say You have already chosen your way in life.");
        return 1;
    }
    this_object()->force_me("say I proclaim you to be a clergy!\n");
    this_object()->force_me("say Now go forth and find your path in life. Find the hall "
                            "of the Cleric, the hall of the Druid, the hall of the "
                            "Monk, or the hall of the Kataan to join one of these "
                            "grand orders of the clergy class.\n");
    shout("All hail "+(string)this_player()->query_cap_name()+" the new Clergy!");
    this_player()->set_class("clergy");
    this_player()->setenv("TITLE", "$N the novice believer");
    this_player()->init_skills("clergy");
    this_player()->register_channels();
    return 1;
}
