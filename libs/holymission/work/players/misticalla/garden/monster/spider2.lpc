 
inherit "obj/monster";

#include "../garden.h"

#define TP this_player()
 object me;
 
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("spider");
    set_alt_name("brown spider");
    set_level(1);
    set_hp(30);
    set_size(1);
    set_hp(80);
    set_al(-100); 
    set_race("spider"); 
    set_short("A brown spider");
    set_long("You see a big brown spider.\n"+
             "It has a little cross on its\n"+
             "back.\n");  
    set_wc(1+random(8));
    set_ac(1+random(4));
    set_aggressive(1);
    load_chat(10,({
      "T a p   T a p  T a p\n"}));
    me=TO;    
}
}

#define CHANCE  40 	
#define POISON 2
#define MSG	me->query_name()+" bites into "+vic->query_name()+"'s feet !\n" 

attack() {
object vic;
vic=TP->query_attack();

  if(::attack()) {	
    if(random(100)<CHANCE) {
      tell_room(E(),MSG);
      tell_object(vic," You feel a weak sting on your feet !\n");
      vic->add_poison(POISON);
        }
      }
  return 1;
  }
  init() {
   object ob;
   if (ob=present("rat",environment())) {
   attack_object(ob);
   }
   add_action("hold","hold");
   ::init();
  }

  hold(arg) {
   if (arg!="spider" && arg!="brown spider") return;
   tell_room(E()," The spider hides under a stone !\n");
      destruct(TO); 
    return 1;
   }
   

    

