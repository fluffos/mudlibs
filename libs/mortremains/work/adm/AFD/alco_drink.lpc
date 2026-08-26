/* The standard alcoholic beverage.
(04-28-96) Written by Chronos.
(08-24-96) Modified by Chronos.
*/

#include <mudlib.h>
#include <drinks.h>

void drink_msg();
inherit OBJECT;

void create() {
  set("effect", 1);   // How much healing power this object has.
}

void init(){
  add_action("drink", "drink");
}

int drink(string str){
  int effect;
  if (!str) return notify_fail("Drink what?\n");
  if (!id(str)) return 0;
  effect = this_object()->query("effect");
  if (!effect) effect = 1;
  drink_msg();
  if (!TP->drink_alco(effect)) return 1;
  if (LEAVES_EMPTIES) 
     clone_object("/obj/std/empty_bottle")->move(environment());
  remove();
  return 1;
}

void drink_msg() {
  tell_object(TP, "You drink some beer.\n");
  message("drink",
  TPN + " drinks some beer.\n",
  environment(TP), ({ TP }) );
}
