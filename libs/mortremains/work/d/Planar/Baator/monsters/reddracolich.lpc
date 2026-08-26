#include <mudlib.h>
#include <config.h>

inherit "/std/monster" ;


void create () {
 ::create() ;
  seteuid(getuid());
   
   set("stat/dexterity", 18);
   set("stat/strength", 22);
   set("stat/constitution", 20);
   set("armor_class", "@@query_armor_class");
   set_size(350);
   set("short", "Great Wyrm Red Dracolich");
   set("long", "This is an undead red dragon.\n");
   set("id", ({ "dragon", "red", "red dragon", "dracolich" }) );
 set("magic_resist", 60 );
   set("resist_type", ([ "fire" : 0, "poison" : 0, "electricity" : 0, "necromancy" : -100, "cold" : 0 ]) );
   set("special", 15);
   set("natt", 2);
   set("race", "dracolich");
   set("undead", 100);
   enable_commands();
set("damage_type", "slashing");
   set("damage", ({ 15,38 }) );
   set("weapon_name", "razor sharp chilling claws");
   set_verbs( ({ "slash", "slice", "smite" }) );
   set_verbs2( ({ "slashes", "slices", "smites" }) );
   set_name("red dracolich");
   set_living_name("red dracolich");
   set_level(23);
set("wealth", (this_object()->query("hit_points")));
 }

int query_armor_class(){
object ob;
int ac, thac;
   ob = this_object()->query_current_attacker();
ac = -13;
if (ob){
thac = this_object()->query("thac0");
//put all the query hit code here.
}
return ac;
}

int receive_damage(int num, string type, object ob, int weap){
if (weap){
num = (num/3);
}
::receive_damage();
}

void special_attack() {
object ob;
int sv;   
   ob = this_object()->query_current_attacker();
     if (random(3) == 0) {
     say("The Red Dracolich engulfs "+ob->query("cap_name")+" in flames!\n", ob);
     tell_object(ob, "The Red Dracolich engulfs you in flames!\n");
   sv = (ob->save_throw());
   if (sv){
   if ((ob->query_skill("Evasion"))>0){
     tell_object(ob, "You dive out of the way!\n");
   }else{
     ob->receive_damage((random(103)+18), "fire");
  }
   			}
   if (sv == 0){
     ob->receive_damage((random(205)+36), "fire");
   }
 }else{
     say("The Red Dragon sinks it's teeth into "+ob->query("cap_name")+"!\n", ob);
     tell_object(ob, "The Red Dragon sinks it's teeth into your flesh!\n");
     ob->receive_damage((random(33)+31), "slashing", this_object(), 1);
 	}

}
