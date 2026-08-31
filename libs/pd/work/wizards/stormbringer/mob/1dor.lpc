#include <std.h>

inherit UNDEAD;
/*
void init() {
    ::init();
    add_action("Bugga", "Bugga");
    }*/
void create() {
   ::create();
   set_name("dour");
   set_id( ({ "dour","guard","dour guard" }) );
   set_short("A dour guard");
   set_long("A short stocky humanoid about two and a half feet tall."
            "Powerfully muscled, it looks mean.\n");
   set_level(100);
   set_body_type("human");
   set_alignment(-200);
   set_race("dour");
   set_class("fighter");
   set_spell_chance(50);
   set_spells( ({ "bugga" }) );
   set_money("gold", 500);
   }

void die() {
   if (present("bugga", this_object()))
     present("bugga", this_object())->remove();
   ::die();
}

int Bugga(string str) {
    string limb;
    object ob;
    int amount;
   
    say("Blehhhh..");
    return 1;
    if(this_player()->is_player()) return 0;
    ob = (object)this_player()->query_current_attacker();
    if(!ob) return 1;
    limb = (string)ob->return_limb();
    if((string)ob->query_class() == "rogue") amount = 24 + random(30);
    else amount = 20 + random(20);
    ob->do_damage(limb, amount);
        tell_object(ob, "The guard bashes your "+limb+" with his "
                    "left fist!");
    tell_room(this_object(), "The guard bashes "+ob->query_cap_name()+"'s "+
        limb+" with his left fist!", ({ ob }));
    return 1;
}
