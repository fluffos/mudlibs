#include <mudlib.h>

inherit MONSTER;

void create(){
int desc, x;
desc = random(10+1);
x = random(6)+5;
  ::create();
  set("author", "Waxer");
    set("id", ({ "clown" }) );
    set("race", "human");
  switch(desc) {

   case 1:{
               set("short", "a clown with a funny hat");
               break;
              }

   case 2: {
                set("short", "a dwarven clown with big shoes");
                set("id", ({ "clown", "dwarf" }) );
                set("race", "dwarf");
                break;
                }

  case 3:{
               set("short", "a fat clown with clothes that are too small");
               set("id", ({ "clown", "fat clown" }) );
               break;
              }

   case 4:{
               set("short", "a clown with a black and white striped shirt");
               break;
              }

  case 5:{
              set("short", "a clown with makeup running in his eyes");
              break;
             }

  case 6:{
             set("short", "a tall, lanky clown" );
             set("id", ({ "clown", "tall clown" }) );
             break;
             }

  case 7:{
              set("short", "a short, bearded clown");
              break;
             }

  case 8:{
               set("short", "a clown with oversized overalls");
               break;
              }

  case 9:{
               set("short","a clown with a giant, red nose");
               break;
             }

  case 10: {
                  set("short", "a mutated clown with large fangs");
                  break;
               }
  default: set("short", "a clown");

    break;
  }
  set("long", "This is a clown who works for the Cirque di Mal, funny isn't he?\n");

  set("gender", "male");
  set_name("clown");
  set_level(x);
  credit((int)query_level()*80);
  set_alignment(12);
  set("weapon", (int)query_level()+7);
  set("damage", ({ x, x+20 }) );
  set("weapon_name", "fists");   // And the weapon name.
  set_verbs( ({ "swing at", "punch at", "attack", "jab at" }) );
  set_verbs2(({ "swings at", "punches at", "attacks", "jabs at" }) );
  set("chat_chance", 1);
  set("chat_output", ({
    "The "+query("short")+" tries to make you laugh.\n",
   "The "+query("short")+" works hard and steady to ready himself for the show.\n",
   "The "+query("short")+" does a neat trick.\n",
   "The "+query("short")+" looks at you suspiciously.\n",
  }) );
  set("att_chat_output", ({
   "The "+query("short")+" does a backflip to avoid the blow!\n",
   "The "+query("short")+" slaps you like a woman would.\n",
   "The "+query("short")+" laughs at you as though you are toying with him.\n",
  }) );
}