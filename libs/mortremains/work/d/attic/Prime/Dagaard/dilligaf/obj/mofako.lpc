#include <mudlib.h>   //This calls all the neat stuff Cy programed

inherit WEAPON;

void create() {
  seteuid(getuid());
  set("name" , "katana");
  set_weapon_type("sword/two-handed");
  set_material_type("metal/steel");
  set("id" , ({ "katana" }) );
set("short", "Katana of Might");
  set("long" , @EndText
  The fabled Katana of Doom. A powerful weapon forged by a long lost
  forgotten tribe of Dwarven samurai, its edges have been keened and
  sharpened so that they might cut stone. It hums with a powerful 
  magic, and you are sure that the metal itself has been folded over
  thousands of times.

EndText
);
  set("value" , 120000);
  set_bonus(15);
  set_verbs( ({ "slice" , "slash" , "dice" }) );
  set("natt" , 10000);
  set_verbs2( ({ "slices" , "slashes" , "dices" }) );
  set("damage" , ({ 300,500}) );
  set("hit_func", 1);
}
  int hit_func(object targ,int damage){
    if(!targ->save_throw()){
    targ->recieve_damage((random(50)+35), "necromancy");targ->set("last_attacker",this_player());
    write ("The katana FLARES up and inflicts massive damage to "+targ->query("cap_name")+".\n");

  }
  return damage;
}
