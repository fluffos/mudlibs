#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "the zookeeper");
  set("long", @ENDLONG
This middle-aged man has a huge smile on his face.  He looks like
he loves his jobs, his animals, and the kids.  He leans on a hefty
cane, overseeing the zoo.
ENDLONG
  );
  set("id", ({ "zookeeper", "keeper", "man" }) );
  set("race", "human");
  set_name("zookeeper");
  set("gender", "male");
  set_level(5);
  set_alignment(30);
  set("chat_chance", 2);
  credit(random(100) + 65) ;
  set("chat_output", ({
    "The zookeeper gives a child a lollipop.\n",
    "The zookeeper hugs a child.\n",
    "The zookeeper smiles at you.\n",
  }) );
  set("damage", ({ 2, 4 }) );
  set("weapon_name", "fists");
  set_verbs( ({ "bite at", "attack" }) );
  arm(WEAPONS(cane), "cane");
}
