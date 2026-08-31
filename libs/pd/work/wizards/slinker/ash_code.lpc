#include <std.h>

inherit OBJECT;

int MANA;
int quick=0;

void create()
{
 ::create();
 set_name("ashes");
 set_short("%^BOLD%^%^WHITE%^A pile of ashes%^RESET%^");
 set_long("%^BOLD%^%^WHITE%^These Ashes are from the burnt corpses of the fallen "
          "members of the %^BLACK%^D%^WHITE%^a%^BLACK%^r%^WHITE%^k %^BLACK%^" 
          "S%^WHITE%^o%^BLACK%^u%^WHITE%^l%^BLACK%^s%^WHITE%^ clan. To use the "
          "power within the ashes you must <sprinkle> ashes.");
 set_id( ({ "ashes", "black ashes" }) );
 set_mass(1);
 set_value(0);
 MANA = random(6000)+6000;
 
}
int query_mana() { return MANA; }
void init()
{
 ::init();
 set_heart_beat(1);
 add_action("sprinkle", "sprinkle");
}

int sprinkle(string str)
{
 if (str!="ashes") return notify_fail("Sprinkle what?\n");
 write("%^BOLD%^%^WHITE%^You sprinkle ashes around your body and feel a rush of mana shot into your body."); 
 quick = 1;
 return 1;
}

string query_short()
{
 string str;

 str = ::query_short()+" ";
 if (MANA >= 5000)
   str += "(circling)";
  else
 if (MANA >= 4000)
   str += "(levitateing)";
  else
 if (MANA >= 3000)
   str += "(riseing)";
  else
 if (MANA >= 2000)
   str += "(floating)";
  else
 if (MANA >= 1000)
  str += "(falling)";
 else 
if (MANA < 500)
  str += "(spining)";
 return str;
}
void heart_beat()
{
 object owner;

 owner = environment(this_object());
 if (!owner) return;
 if (!owner->is_living())
   {
    if (random(100) > 80)
    MANA--;
    return;
   }
    
 if (MANA <= 0)
   {
    write("The Ashes vanish");
    this_object()->remove();
    return;
   }
 if (random(100) > 40 )
 if (quick && owner->query_mp() < owner->query_max_mp())
   {
    owner->add_mp(200);
    MANA -= 200;
    write("Your body is filled with magical powers.");
    if (owner->query_mp() >= owner->query_max_mp())
      quick = 0;
    return;
   }
 if (random(100) > 50) 
   {
    owner->add_mp(10);
    MANA -= 10;
   }
}

