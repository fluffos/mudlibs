/* Pirated from Cattt's hunter.c */
/* By Grull */
#include <mudlib.h>
#include "../GenericLib.h"

inherit MONSTER;
void create(){
  ::create();
  seteuid(getuid());
  set("author", "grull");
  set("short","A wiry kobold");
  set("long", "This kobold moves with short, furtive glances all around. It hasn't been in here very long, but apparently long enough to learn a healthy respect for its neighbors. It looks very frightened.\n");
  set("id", ({"Kobold", "kobold"}) );
  set_name("Kobold");
  enable_commands();
  set("gender", "male");
  set("race", "kobold");
  set("damage", ({ 2,4 }) );
  set("weapon_name", "fists");
  set("stat/strength", 12);
  set("stat/dexterity", 16);
  set_verbs( ({ "punch at", "shove at", "push at" }) );
  set_verbs2( ({ "punches at", "shoves at", "pushes at" }) );
  set("chat_chance", 5);
  set("chat_output",
      ({
	"The kobold makes some frightened noises, and shrinks away from you.\n",
	  "In a desperate effort, the kobold lunges for your weapon!\n",
	  }) );
  set_size(4);
  set_level(random(4)+4);
}



