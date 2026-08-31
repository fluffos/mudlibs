#include <std.h>
inherit MONSTER;
void create() {
    ::create();
    set_name("crab");
    set_id(({"crab"}));
    set_short("A small blue crab scurries past your feet");
    set_long("This is a small generic blue crab with 6 legs and 2 claws....");
    set_level(10);
    set_body_type("crab");
    set_class("fighter");
    set_race("crab");
    set_subclass("warrior");
    //set_spell_chance(20);
    set_money("silver",40);
}

void heart_beat()
{
    object ob;
    ::heart_beat();
    if (!this_object()) return;

    if(sizeof(this_object()->query_attackers()))
    {
	if(random(100)>70)
	{	
	    if (ob = this_object()->query_current_attacker()) {
  	    message("attacker", "The crab pinches you with its claws!", ob);
  	    message("room" "The crab pinches " +ob->query_cap_name()+ " with its claws!", 
  	      environment(this_object()), ob);
  	    ob->damage(10+random(15));
            }
	}
    }    

}
