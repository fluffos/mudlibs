inherit "/std/races/standard";
#include "light_defs.inc"

void setup() 
{
    set_long("This is a Kender - a small demi-human, much like a halfling, "
      "except that they do not outwardly age. They all have "
      "their hair bound up in a ponytail on the top of their head, "
      "called a topknot.\n");
    set_name("kender");
    set_light_limits(LIGHT_HALFLING_LOW, LIGHT_HALFLING_HIGH);
    set_race_size(3);
    reset_get();
}

void set_racial_bonuses() 
{
    previous_object()->adjust_bonus_wis(-2);
    previous_object()->adjust_bonus_dex(2);
    previous_object()->adjust_bonus_str(-1);
    // This whole code is based on Khelben's halfling code,
    // Which is similar to a Kender anyway.
    // thanks to Khelben for his help.
    // The differences I'm trying to emphasize is the Kender's
    // foolishness and extreme dexterity. The Strength minus
    // is logical, considering their size (approx. halfling size)
    // Anavrin the Kender Mage 12-13-96
}

int query_skill_bonus(int lvl, string skill) 
{
    return 0;
}

string query_desc(object ob) 
{
    if((int)ob->query_gender() == 1)
        return("A childlike Kender lad.\n");
    return("A childlike Kender lass.\n");
}
void race_heartbeat(object player)
{
    object *list;
    object item;
    if(!player || !ENV(player) || player->query_dead()) return;
    ::race_heartbeat(player);
    if(player->query_property("noguild") || ENV(player)->query_property("noguild")) return;
    list = all_inventory(ENV(player));
    item = list[random(sizeof(list))];
    if(item != player && item->query_alive()&& (!item->query_creator()))
    {
        list = all_inventory(item);
        if(!sizeof(list)) return;
        item = list[random(sizeof(list))];
        if(!item->query_in_use())
        {
            item->move(player);
            call_out("oops",5,player,item->query_short());
        }
    }
    if(!living(item))item->move(player);
    if(!player->query_hide_shadow())
    {
        item = clone_object("/std/commands/shadows/hide");
        item->setup_shadow(player);
    }
}
void oops(object player,string name)
{
    if(player)
        tell_object(player,"Hmm you seem to have acquired a "+name+" which someone carelessly misplaced.\n");
}
