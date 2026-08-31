#include <std.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("imp");
   set_id( ({ "imp" }) );
    set_short("an evil imp");
   set_level(8);
   set_long("An evil imp. He smiles as you cringe.");
   set_body_type("imp");
   set_alignment(-10);
   set("race", "imp");
   set_gender("male");
set_spell_chance(99);
set_spells( ({ "Bugga" }) );
}
int Bugga(string str) {
    string limb;
    object ob;
    int amount;

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
