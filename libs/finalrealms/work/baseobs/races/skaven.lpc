inherit "/std/races/standard";
#include "light_defs.inc"

void setup() {
    set_long("The skaven are a dangerous and deviouse race.\n");
    set_name("skaven");
    set_light_limits(-50, 200);
    reset_get();
}

void set_racial_bonuses() {
    previous_object()->adjust_bonus_int(-1);
    previous_object()->adjust_bonus_dex(1);
}

int query_skill_bonus(int lvl, string skill) {
    return 0;
}

string query_desc(object ob) {
    if((int)ob->query_gender() == 1)
	return ("A dirty male skaven.\n");
    return("A dirty female skaven.\n");
}
void poisonem(object player)
{
    object *list;
    object ob;
    int i;
    list = player->query_attacker_list();
    i = sizeof(list);
    if(i && random(5))
    {
	i = random(i);
	ob = clone_object("/std/spells/cleric/poisoned");
        if(ob && list[i] && !list[i]->query_property("poisoned") &&
            !random(100)<list[i]->query_property("poison"))
	{
	    ob->set_get();
	    ob->move(list[i]);
	    ob->reset_drop();
	    ob->reset_get();
	    ob->set_spell(player,random(20));
	    list[i]->add_timed_property("poisoned",1,1800);
	    tell_object(list[i],(string)player->query_cap_name()+"bites you savagely.\n");
	    tell_object(player,"In your battle fury you bite someone.\n");
	    tell_room(environment(player),(string)player->query_cap_name()+" bites "+
	      (string)list[i]->query_cap_name()+" OUCH that gotta smart !\n",({player,list[i]}));
	}
    }
}
void race_heartbeat(object player)
{
    ::race_heartbeat(player);
    poisonem(player);
}
