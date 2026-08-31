#include <std.h>
inherit MONSTER;

void create() {
 ::create();
   set_name("zombie");
   set_id( ({ "zombie", "corpse" }) );
   set("short", "a rotting zombie");
   set("aggressive", 2);
   set_level(8);
   set("long", "The zombie is a walking, and rotting, corpse "
               "of some humanoid creature.");
   set_alignment(-200);
   set("race", "undead");
   set_property("no_corpse", 1);
   if (random(10) > 5) set_gender("male");
   else set_gender("female");
   set_money("gold",random(5));
   set_die( "The zombie falls %^RED%^dead%^RESET%^ before you.\nThe corpse turns to dust and blows away." );
   set_body_type("human");
}

void catch_tell(string str) {
    object ob;
    string a, b;

    if(sscanf(str, "%s gives you %s.", a, b) == 2) {
	ob = present( lower_case(a), environment(this_object()));
	if(ob) {
	    tell_room(environment(this_object()),
            "The zombie wails in rage!", ({ this_object() }));
            this_object()->force_me("say "+(string)ob->query_cap_name()
            +", you show kindness. That will take you nowhere!");
            this_object()->force_me("bury "+b);
	}
    }
}
