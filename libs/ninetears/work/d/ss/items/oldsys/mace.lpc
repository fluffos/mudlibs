inherit "obj/weapon";
 
void setup() {
  new_weapon(6000);
  add_immune("blunt");
  set_damage_chance(10);
  add_attack("mace",    0, 100, 120, 10, 0, "blunt");
  add_attack("disrupt", 0, 0, 200, 10, 0, "magic");
  add_attack("bash",    0, 10, 50, 0, 0, "blunt");
  set_weap_skill("fighting.combat.melee.blunt");
  set_weight(8);
  adjust_money(500, "silver");
  set_name("disruptor");
  add_adjective("of disruption");
  add_alias("mace");
  set_short("mace of disruption");
  set_main_plural("maces of disruption");
  add_plural("maces");
  set_long("This mace has an aura of holy power surrounding itself. It seems "+
   "to be the perfect clerical weapon.\n");
  set_read_mess("Forged by Ducky, the God of Ducks.\n");
}

int write_message(int dam, object him, object me, string type, string attack) 
{
  switch (attack) 
  {
    case "disrupt" :
     write("You disrupt "+him->query_name()+" with the power of your mace.\n");
     say(me->query_cap_name()+" disrupts "+him->query_name()+" with a holy THUD!\n", him);
     tell_object(him,me->query_cap_name()+" disrupts you with a holy mace.\n");
     break;
    case "bash" :
      say(me->query_cap_name()+" bashes "+him->query_name()+".\n",him);
      write("You bash "+him->query_name()+".\n");
      tell_object(him, me->query_cap_name()+" bashes you.\n");
      break;
    default :
      ::write_message(dam, him, me, type, attack);
   if(him->query_property("undead", 1) && random(2) && me->query_alignment()>20)
       do_attack("disrupt");
      break;
  }
}
