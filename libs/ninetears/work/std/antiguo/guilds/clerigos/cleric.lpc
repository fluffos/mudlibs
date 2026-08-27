/* the work in removing spell things..
   Baldrick..
   */

inherit "/std/guild";
#define SPELL_TABLE "/table/spell_table"

int query_skill_cost(string skill)
{
 return 5;
}

void setup()
{
 set_name("cleric");
 set_short("cleric");
 set_long(
         "Clerics are the normal priests on Magisk Jord.  They need not be "
         "bound to a special god/goddess, but usually are.  Clerics have "
         "the power to turn undead creatures and are especially good at "
         "healing wounds and protection.  They are also competent fighters, "
         "and are quite susceptible to pain.\n");
 reset_get();
}

void create()
  {
  ::create();
  set_main_skill("wis");
}

/* Nope, not needed.. 
void set_gp(object ob)
{
ob->set_max_gp((int)ob->query_level()+(int)ob->query_wis());
}
*/


int query_legal_race(string race)
{
  switch(race)
  {
    case "half-orc": return 0;
    default        : return 1;
  }
}

string query_spell_directory(){return "/std/spells/cleric/";}

int query_legal_weapon(string type)
{
  switch(type)
  {
    case "flail":
    case "hammer":
    case "mace":
    case "quarterstaff":
    case "sling":
    case "staff":
    case "war-hammer":
         return 1;
    default: return 0;
  }
}

string query_main_skill() {return "wis";}
int query_dice()         { return 8; }
int query_advance_cost() { return  500; }
int query_xp_cost()      { return 1500; }
int query_thac0_step()   { return 3; }

int query_dual_wield_penalty(object me, object w1, object w2)
{
  int bon;

  bon = 50 - (int)me->query_level()/3;
  bon = (bon<30 ? 30 : bon);

  return bon;
}
void on_death(object player, object killer) {
}
