inherit "obj/weapon";
 
void setup() 
{
  new_weapon(600);
  add_immune("sharp");
  add_immune("pierce");
  set_damage_chance(10);
  add_attack("slash", 0, 100, 120, 10, 0, "sharp");
  add_attack("pierce", 0, 10, 50, 0, 0, "pierce");
  set_weap_skill("fighting.combat.melee.sharp");
  set_weight(200);
  set_value(2300);
  set_name("broadsword");
  add_adjective("magic");
  add_alias("sword");
  set_short("broadsword");
  set_main_plural("broadswords");
  add_plural("swords");
  set_enchant(20);
  set_long("The broadsword is in fantastic shape.\n");
  set_read_mess("Forged especially for Baergon by Ducky.\n");
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
