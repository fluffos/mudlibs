#include <mudlib.h>
#include <config.h>

inherit "/std/monster" ;


void create () {
 ::create() ;
  seteuid(getuid());
   
   set("stat/dexterity", 20);
   set("stat/strength", 22);
   set("stat/constitution", 25);
   set("armor_class", -23);
   set_size(271);
   set("short", "Huge, Ancient Red Dragon");
  set("long", @ENDLONG
You stand before an ancient red dragon, one of Tiamat's spawn.
Large leathery wings flap lazily while smoke curls from the nostrils
of this monstruous beast.  The dragon focuses his large yellow eyes
on you nonchalantly, and fear begins to well up inside you.
This dragon is truly a paragon of its species.
ENDLONG
  ) ;
   set("id", ({ "paragonred", "dragon", "red", "red dragon" }) );
 set("magic_resist",115);
   set("resist_type", ([ "fire" : 0, "poison" : 50 ]) );
   set("special", 15);
   set("natt", 2);
   set("race", "dragon");
   enable_commands();
set("damage_type", "slashing");
   set("damage", ({ 29,56 }) );
   set("weapon_name", "razor sharp claws");
   set_verbs( ({ "slash", "slice", "smite" }) );
   set_verbs2( ({ "slashes", "slices", "smites" }) );
   set_name("paragon red dragon");
   set_living_name("paragon red dragon");
   set_level(48);
   credit(17000+random(17000)) ;
 }


void special_attack() {
object ob;
int sv;   
   ob = this_object()->query_current_attacker();
     if (random(3) == 0) {
     say("The Red Dragon engulfs "+ob->query("cap_name")+" in flames!\n", ob);
     tell_object(ob, "The Red Dragon engulfs you in flames!\n");
   sv = (ob->save_throw(-6));
   if (sv){
   if ((ob->query_skill("Evasion"))>0){
     tell_object(ob, "You dive out of the way!\n");
   }else{
     ob->receive_damage((random(154)+26), "fire");
  }
   			}
   if (sv == 0){
     ob->receive_damage((random(307)+51), "fire");
   }
 }else{
     say("The Red Dragon sinks it's teeth into "+ob->query("cap_name")+"!\n", ob);
     tell_object(ob, "The Red Dragon sinks it's teeth into your flesh!\n");
     ob->receive_damage((random(46)+18), "slashing", this_object(), 1);
 	}

}
