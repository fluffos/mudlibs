inherit "obj/weapon";

  /*This is the old setup, forget it for now.
   *Keep it to the special stuff later. */

  /*
void setup() 
{
   new_weapon(6000);
   add_immune("blunt");
   set_damage_chance(10);
   add_attack("katana",    0, 100, 150, 10, 0, "sharp");
   add_attack("pierce",    0, 10, 100, 0, 0, "pierce");
   set_weap_skill("fighting.combat.melee.sharp");
   set_value(4000);
   set_weight(80);
   set_name("katana");
   add_adjective("sharp");
   add_alias("sword");
   set_short("sharp katana");
   set_main_plural("katanas");
   add_plural("sharp katanas");
   set_long("The katana is honed to a fantastic sharpness "+
      "this sure is a fighters weapon.\n");
   set_read_mess("Forged by Ducky, the God of Ducks.\n");
}

  */

  /* This the new setup. It has no real weapon setup stuff,
   * just oblect setups such as names and stuff. No money either. */

  void setup()
    {
    /* Baldricks comment: The base_weapon is a lookup value in 
     * /table/weapon_table.c. So it has to be in that table.
     * So find the "nearest" weapon there and use that one as the base 
     * weapon, but everythning else will be Katana ond so on.. (set_short++)
     */
    set_base_weapon("long sword"); /* Zosos comment: I picked a long 
                                    * sword cause that is what the
                                    * katana came closes to in AD&D */
    set_name("katana");
    add_adjective("sharp");
    set_main_plural("katanas");
    add_plural("sharp katanas");
    set_long(" The katana is honed to a fantastic sharpness " +
             "this sure is a fighter's weapon.\n");
  }
  /*
  int write_message( int dam, object him, object me, string type, string attack)
  {
  switch(attack)
   {
      case "pierce" :
      say(me->query_cap_name()+" guts "+him->query_name()+".\n",him);
      write("You pierce "+him->query_name()+"'s guts.\n");
      tell_object(him, me->query_cap_name()+" guts you.\n");
      break;
      default :
      ::write_message(dam, him, me, type, attack);
      break;
    }
  }
  */

