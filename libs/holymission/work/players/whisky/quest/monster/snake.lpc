/* SNAKE.C - Programmed by Whisky */
/* the ring of the snake is getable there is a way without kill: quest */

#include "../monkway.h"

 inherit "obj/monster";
 object me;
 
  reset(arg) {
    ::reset(arg);
  if (!arg) {

    set_name("snake");
    set_alt_name("green snake");
    set_level(2);
    set_size(1);
    set_hp(280);
    set_al(-100); 
    set_race("snake"); 
    set_short("A green snake");
    set_long("You see a big green snake.\n"+
             "It has a little cross on it's\n"+
             "back.\n");  
    set_wc(2);
    set_ac(2);
    load_chat(20,({
      "Ssssssss Zzzzzzzzzzz\n"}));
    me=TO;    
}
}

#define CHANCE  100 	
/* 111292 */
#define MSG	me->query_name()+" winds itself around "+vic->query_name()+"'s feet !\n" 

attack() {

object vic;
vic=TP->query_attack();

  if(::attack()) {	
    if ( (CHANCE - (vic->query_dex() * 2)) > random(200) )
    {
      tell_room(E(),MSG);
      tell_object(vic," You feel an awful sting on your feet !\n");
      vic->add_poison(vic->query_max_hp()/6 + 8);
        }
      }
  return 1;
  }
  init() {
   object ob1,ob2;
     if (ob1 = present("rat",environment())) {
    attack_object(ob1);
    return 1;
   } 
   if (ob2=present("corpse",environment())) {
      tell_room(environment()," The snake munches the "+ob2->short()+"\n");
      destruct(ob2);
   return 1;
   }
   add_action("hold","hold");
   ::init();
  }

  hold(arg) {
   object ob;
   if (arg!="snake" && arg!="green snake") return;
   tell_room(E()," The snake hides under a stone !\n");
   if (ob=present("mring",E())) {
      destruct(ob);
      destruct(TO); 
    return 1;
   }
  return 1;
 }
   

    

