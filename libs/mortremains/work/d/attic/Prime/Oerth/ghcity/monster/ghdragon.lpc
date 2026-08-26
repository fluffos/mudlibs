/* code from Ilzarion */
#include <mudlib.h>
#include <config.h>

inherit "/std/monster" ;


void create () {
 ::create() ;
  seteuid(getuid());
 
   set("stat/dexterity", 25);
   set("stat/strength", 25);
   set("stat/constitution", 25);
   set("armor_class", -12);
   set_size(145);
   set("short", "An ancient Greyhawk Dragon");
   set("long", "This is an ancient Greyhawk dragon. It's scales \n"+
   "are a rich metallic grey reminiscent of brushed steel, ranging \n"+
   "to a darker hue - almost like blued gunmetal - on the creatures \n"+
   "underside and towards it's tail. The membranes of its wings \n"+
   "have the sheen of fine silk. Although it is smaller then it's \n"+
   "kin, it shares their strength and robustness typical to other \n"+
   "dragons.\n");
   set("id", ({ "greyhawk dragon", "dragon", "greyhawk" }) );
   set("magic_resist",75);
   set("resist_type", ([ "poison" : 0 ]) );
   set("special", 10);
   set("natt", 2);
   set("race", "dragon");
   enable_commands();
   set("damage", ({ 10, 40 }) );
   set("damage_type", "slashing");
   set("weapon_name", "sharp claws");
   set_verbs( ({ "gash", "tear", "gouge", "slice" }) );
   set_verbs2( ({ "gashes", "tears", "gouges", "slices" }) );
   set_name("greyhawk dragon");
   set_living_name("greyhawk dragon");
   set_level(30);
 set("wealth", (this_object()->query("hit_points")));
 }


void special_attack() {
object ob;
int sv;   
   ob = this_object()->query_current_attacker();
     if (random(3) == 0) {
   say("The Greyhawk Dragon engulfs "+ob->query("cap_name")+" in a cloud of lethal poison!!!\n", ob);
   tell_object(ob, "The Greyhawk Dragon engulfs you in a cloud of poison!!!\n");
   sv = (ob->save_throw(-4));
   if (sv){
   if ((ob->query_skill("Evasion"))>0){
     tell_object(ob, "You dive out of the way!\n");
   }else{
    ob->receive_damage((random(100)+12), "poison");
  }
   			}
   if (sv == 0){
   ob->receive_damage((100000), "poison");
   }
 }else{
   say("The Greyhawk dragon latches on to "+ob->query("cap_name")+" with it's fangs!!!\n");
   tell_object(ob, "The Greyhawk dragon latches on to you with it's sharp fangs!\n");
   ob->receive_damage((random(30)+20), "slashing", this_object(), 1);
 	}

}
