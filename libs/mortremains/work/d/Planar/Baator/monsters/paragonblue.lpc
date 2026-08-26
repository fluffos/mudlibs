#include <mudlib.h>
#include <config.h>

inherit "/std/monster" ;


void create () {
 ::create() ;
  seteuid(getuid());
 
   set("stat/dexterity", 20);
   set("stat/strength", 22);
   set("stat/constitution", 25);
   set("armor_class", -20);
   set_size(195);
   set("short", "Huge, Ancient Blue Dragon");
   set("long", "This is an ancient blue dragon, one of tiamat's spawn\n"+
       "It is a paragon of it's species.\n");
   set("id", ({ "paragonblue", "dragon", "blue", "blue dragon" }) );
 set("magic_resist",105);
   set("resist_type", ([ "lightning" : 0, "poison" : 50 ]) );
   set("special", 10);
   set("natt", 2);
   set("race", "dragon");
   enable_commands();
   set("damage", ({ 29,50 }) );
   set("damage_type", "slashing");
set("damage_type", "slashing");
   set("weapon_name", "razor sharp claws");
   set_verbs( ({ "slash", "slice", "smite" }) );
   set_verbs2( ({ "slashes", "slices", "smites" }) );
   set_name("paragon blue dragon");
   set_living_name("paragon blue dragon");
     set_level(47);
 set("wealth", (this_object()->query("hit_points")));
 }


void special_attack() {
object ob;
int sv;   
   ob = this_object()->query_current_attacker();
     if (random(3) == 0) {
     say("The Blue Dragon engulfs "+ob->query("cap_name")+" in a storm of lightning!\n", ob);
     tell_object(ob, "The Blue Dragon engulfs you in a storm of lightning!\n");
   sv = (ob->save_throw(-6));
   if (sv){
   if ((ob->query_skill("Evasion"))>0){
     tell_object(ob, "You dive out of the way!\n");
   }else{
     ob->receive_damage((random(119)+26), "lightning");
  }
   			}
   if (sv == 0){
     ob->receive_damage((random(239)+51), "lightning");
   }
 }else{
     say("The Blue Dragon sinks it's teeth into "+ob->query("cap_name")+"!\n", ob);
     tell_object(ob, "The Blue Dragon sinks it's teeth into your flesh!\n");
     ob->receive_damage((random(36)+37), "slashing", this_object(), 1);
 	}

}
