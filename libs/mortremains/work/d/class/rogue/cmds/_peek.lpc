/* File: _disarm.c
** Purpose: Ability for the thief class.
** Date: August 1st, 1997  (first attempt)
** Creator: Nightmask
*/

#include <rogues.h>
#include <mudlib.h>

// Prototypes...
int drop();
int disarm();
int unwield();

inherit DAEMON;

#define POSS possessive(this_player()->query("gender"))

// Global variables.
object attkr, weap;

int cmd_peek(string targ) {
  
object ob;
int money;

  if (!targ){
  write("Who did you want to peek?\n");
  return 1;
  }
  ob = present(targ, environment(this_player()));

   if (!ob) {
      write("There's nothing by that name to peek.\n") ;
      return 1;
   }    
  
  if (TP->query_level() < 5) {
    write("You are not yet skilled enough to do that!\n");
    return 1;
  }
  attkr = (object)TP->query_current_attacker(); 
  if (attkr) {
     write("You are a bit busy at the moment.\n");
  return 1;
  }

    if(!this_player()->query("vision")) {
   write("Peek who?  You can't see anything!\n");
   return 1; }
  
money = ob->query("wealth");
	switch (money){
	case -10..100 : write ("looks like a po mutha fo.\n");break;
	case 101..1000 : write ("looks like they buying the next round of drinks.\n");break;
	case 1001..10000 : write ("look like thier pockets are full.\n");break;
	case 10001..100000 : write ("looks like a shitload of cash.\n");break;
	case 100001..1000000 : write ("looks like they could buy the town.\n");break;
	case 1000001..10000000 : write ("HOLY SHIT!, thats alot of cash!\n");break;
	default : write ("looks like a metric butt-load of cash.\n");break;
	}
return 1;
}
