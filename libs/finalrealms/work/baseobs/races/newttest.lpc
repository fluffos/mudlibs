#include "light_defs.inc"
inherit "/std/races/standard";

#define SELF_INTOX 35
#define OTHER_INTOX 40
#define INTOXLIMIT 2000

void setup() 
{
    set_long("The newt is a small, agile reptile with a long "
             "tail. Growing to about 4 inches, a newt begins its "
             "life in the water as a larvae. It then lives on "
             "land for a while until it returns to the water "
             "as an adult.\n");
    set_name("newt");
    set_light_limits(LIGHT_LIZARDMAN_LOW, LIGHT_LIZARDMAN_HIGH);
    set_race_size(1);
    reset_get();
}
int query_swim_stamina(object player) { return -1; }
int query_underwater_breathing(object player) {return -1; }

void set_racial_bonuses() 
{
    previous_object()->adjust_bonus_str(-4);
    previous_object()->adjust_bonus_dex(7);
    previous_object()->adjust_bonus_con(-2);
}

int query_skill_bonus(int lvl, string skill) 
{
    return 0;
}

string query_desc(object ob) 
{
return "A green-skinned, orange-eyed, purple-dotted newt";
}

void race_heartbeat(object player)
{
object *people;
int i;

    if(!player || !ENV(player) || player->query_dead()) return;

// Lousy check for water. Need to change this.
    if(file_name(ENV(player))[0..8] == "/d/ss/sea") return;

    people = all_inventory(ENV(player));
    people -= ({ player });
    if(sizeof(people))
     for(i=0;i<sizeof(people);i++)
      {
        if(people[i]->query_alive())
           people[i]->adjust_volume(0,OTHER_INTOX);
      }
    tell_object(player,"You feel kind of weird being out of your "
      "normal habitat.\n");
     if(player->query_volume(0) > INTOXLIMIT)
    player->adjust_volume(0,SELF_INTOX);
    
}

void start_player(object player)
{
 player->set_gender(0);
 ::start_player(player);
}
