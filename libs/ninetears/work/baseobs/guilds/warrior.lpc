/* Baldrick: Added stat modifier for extreme strength */

inherit "/std/guild";

void setup() 
  {
  set_name("warrior");
  set_short("warrior");
  set_long(
     "Warriors are the best fighters, and can take an enourous amount "
     "of damage, but have no magical skill at all.  Warriors can use all "
     "weapons and armour available on Magisk Jord.  "
     "The Warriors guild teaches one principle of survival: beating "
     "people to a pulp!  It gives you skills that relate to finding "
     "out how good a weapon or armour is. Warriors hack and slash "
     "their way through life, and do not appear to be much good at "
     "anything else.\n");
  reset_get();
}

void create()
  {
  ::create();
}

int query_extr_str()    { return 1;    }
int query_extra_con_bonus() { return 1; }

int query_dual_wield_penalty(object me, object w1, object w2)
{
  int bon;

  bon = 50 - (int)me->query_level()*2;
  bon = ( bon<0 ? 0 : bon );

  return bon;
}
void on_death(object player, object killer) {
}
