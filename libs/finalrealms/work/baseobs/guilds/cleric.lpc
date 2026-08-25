/* the work in removing spell things..
   Baldrick..
   */

inherit "/std/guild";

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
}

string query_spell_directory(){return "/std/spells/cleric/";}

int query_dual_wield_penalty(object me, object w1, object w2)
{
  int bon;

  bon = 50 - (int)me->query_level()/3;
  bon = (bon<30 ? 30 : bon);

  return bon;
}

void on_death(object player, object killer) {

}
