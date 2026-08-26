/* Pirated from Cattt's hunter.c */
/* By Grull */
#include <mudlib.h>
#include "../GenericLib.h"

inherit MONSTER;

void create(){
  ::create();
  seteuid(getuid());
  set("author", "grull");
  set("short", "A bone-rattling skeleton"); 
  set("long", "This skeleton is all skin and bones, minus the skin. It moves as if in a world of its own. Its heels click on the rock floors, echoing a rhythmic beat as it walks.\n");
  set("id", ({"skeleton", "Skeleton"}) );
  set_name("Skeleton");
  enable_commands();
  set("gender", "male");
  set("race", "undead");
  set("damage", ({ 2,4 }) );
  set("weapon_name", "fists");
  set("stat/strength", 16);
  set("stat/dexterity", 12);
  set_verbs( ({ "punch at", "shove at", "push at" }) );
  set_verbs2( ({ "punches at", "shoves at", "pushes at" }) );
  set("chat_chance", 5);
  set("chat_output",
      ({
	"The skeleton scares the bejeezers out of you!\n",
	  "Suddenly, a loose bone clatters from the skeleton's torso to the floor.\n",
	  }));

  set_size(6);
  set_level(random(4)+4);
}

