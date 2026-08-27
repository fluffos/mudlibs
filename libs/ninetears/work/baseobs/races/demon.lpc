inherit "/std/races/standard";
#include "light_defs.inc"

void setup()
{
  set_long("Demons are creatures from the Abyss...it's is NOT wise to "
          "annoy them...unless of course you have a very good life "
          "insurance.\n");
  set_name("demon");
  /* new thing for light */
  set_light_limits(LIGHT_BOUNDS_LOW, LIGHT_BOUNDS_HIGH);
  reset_get();
}

void set_racial_bonuses()
{
}

int query_skill_bonus(int lvl, string skill)
{
  return 0;
}

int query_limbs() { return 4; }
string query_desc(object ob)
{
 if((int)ob->query_gender() == 1)
    return("A powerfull, malicious demon.\n");
  return("A powerfull, malicious demon.\n");
}
