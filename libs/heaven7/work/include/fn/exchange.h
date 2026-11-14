#ifndef EXCHANGE_H
#define EXCHANGE_H

void exchange(object ob1, object ob2) {
  string *fn;
  int i;

  fn = ({  /* base_obj */
              
           "name", "alias_name", "alt_name", "short", "alt_short",
           "inv_short", "long", "alt_long", "extra_long", 
           "alt_extra_long", "info", "extra_info", 
           "read", "listen", "smell", "weight", "value",
           "light_value", "enchanted", "modified", "quest_item",
           "domain_safe", "sell_destruct",

           /* armour */
             
           "ac", "max_strength", "current_strength", "repair",
           "armour_material", "type", 

           /* weapon */

           "wc", "length", "weapon_strength", "attack_msg",

           /* wand + magic_armour + magic_weapon */

           "charges", "spells", "class", "cast_level",
           "protection",
  });
  for(i = 0; i < sizeof(fn); i++) {

    if(ob1->query_wc() && fn[i] == "class") continue;
    call_other(ob2,"set_"+ fn[i], (mixed)call_other(ob1,"query_"+ fn[i]));
  }
}

#endif
