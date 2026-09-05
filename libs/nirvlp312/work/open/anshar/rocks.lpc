inherit "obj/treasure";
#include "/players/maledicta/ansi.h"
#define USER environment(this_object()) 
#define ATT USER->query_attack() 
int uses;
int used;
int old_used;
reset (arg) {
if(!arg){
  
  set_id("bag");
  set_short("a bag of rocks");
  set_weight(6);
  set_value(10000);
  uses = 20;
    }
  }
long(){
write("  This is the leftover remains of the giant golem. Contained within\n"+
      "each rock is a powerful bit of magic that used to hold the powerful\n"+
      "creature together. Now it serves as a capable enchantment that can\n"+
      "be used to clobber your opponents. You can 'throwstone <who>'\n");
write(
"The bag has "+uses+" stones left.\n");   
}

  init(){
  ::init();
  add_action("throw_it", "throwstone");
}

throw_it(str) {
object target;
int damage; 
       if(USER->query_ghost()) return 0; 
       if(!uses) return 1;
       if(USER->query_spell_dam()) return 1;
      
	if(!str && USER->query_attack())
		target = USER->query_attack();

	else if(str)
		target = present(str, environment(USER));

	else if(!str && !USER->query_attack())
		return 0;

	if(!target){
		
	tell_object(USER, "You don't see "+str+" here.\n");
		return 1;
	}

	if(!living(target)){
	tell_object(USER,
		"You cannot attack "+str+"!\n");
		return 1;
	}
        damage = random(30) + 10;
        
        uses -= 1;
        USER->spell_object(target, "rock", damage, 0, 
	"You throw a rock\n",
	"Your hit by a rock\n",
	"You see a rock thrown\n");
        return 1;
         }