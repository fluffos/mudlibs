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
  set_bonus(5);
  set_verbs( ({ "slice" , "slash" , "dice" }) );
  set("natt" , 10000);
  set_verbs2( ({ "slices" , "slashes" , "dices" }) );
  set("damage" , ({ 5,25 }) );
 
}
void special_attack() {
  object ob;
  int sv;
  ob = this_object()->query_current_attacker();
  if (ob){
  if (ob->query("hit_points") < 45000) {
    say("The Katana FLARES in your hand and inflicts massive damage." , ob);
  write(TPN+"'s Katana FLARES, and inflicts massive damage.");
  ob->recieve_damage(500, "necromancy", this_object() , 0);
  return;
  }
  }
  return;
 }
