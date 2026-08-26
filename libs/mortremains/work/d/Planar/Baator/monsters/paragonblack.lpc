#include <mudlib.h>
#include <config.h>

inherit "/std/monster" ;


void create () {
 ::create() ;
  seteuid(getuid());
     set("stat/dexterity", 20);
   set("stat/strength", 22);
   set("stat/constitution", 25);
   set("armor_class", -19);
   set_size(155);
   set("short", "Huge, Ancient Black Dragon");
   set("long", "This is an ancient black dragon, one of tiamat's spawn\n"+
       "It is a paragon of it's species.\n");
   set("id", ({ "paragonblack", "dragon", "black", "black dragon" }) );
set("magic_resist", 95);
   set("resist_type", ([ "acid" : 0, "poison" : 50 ]) );
   set("special", 10);
   set("natt", 2);
   set("race", "dragon");
   enable_commands();
   set("damage", ({ 29,44 }) );
   set("damage_type", "slashing");
   set("weapon_name", "razor sharp claws");
set("damage_type", "slashing");
   set_verbs( ({ "slash", "slice", "smite" }) );
   set_verbs2( ({ "slashes", "slices", "smites" }) );
   set_name("paragon black dragon");
   set_living_name("paragon black dragon");
    set_level(45);
 set("wealth", (this_object()->query("hit_points")));
 }


void special_attack() {
object ob;
int sv;   
   ob = this_object()->query_current_attacker();
     if (random(3) == 0) {
     say("The Black Dragon engulfs "+ob->query("cap_name")+" in a gout of acid!\n", ob);
     tell_object(ob, "The Black Dragon engulfs you in a gout of acid!\n");
   sv = (ob->save_throw(-6));
   if (sv){
   if ((ob->query_skill("Evasion"))>0){
     tell_object(ob, "You dive out of the way!\n");
   }else{
     ob->receive_damage((random(51)+26), "acid");
  }
   			}
   if (sv == 0){
     ob->receive_damage((random(103)+51), "acid");
   }
 }else{
     say("The Black Dragon sinks it's teeth into "+ob->query("cap_name")+"!\n", ob);
     tell_object(ob, "The Black Dragon sinks it's teeth into your flesh!\n");
     ob->receive_damage((random(26)+37), "slashing", this_object(), 1);
 	}

}
