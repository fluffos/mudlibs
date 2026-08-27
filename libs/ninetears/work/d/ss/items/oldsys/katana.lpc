inherit "obj/weapon";

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

int write_message(int dam, object him, object me, string type, string attack) 
{
   switch (attack) 
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
