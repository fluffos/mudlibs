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
    set_alignment("ng") ;
    set("chat_chance", 15) ;
    //credit(random(100) + 65) ;
    credit(query_level() * 20); 
    set("chat_output", ({
      "The zookeeper gives a child a lollipop.\n",
      "The zookeeper hugs a child.\n",
      "Zookeeper says: Welcome to the Petting Zoo!\n",
      "Zookeeper says [to you]: Welcome to the Petting Zoo, youngster!\n",
      "Zookeeper says [to you]: Feel free to pet the animals, youngster!\n",
      "The zookeeper smiles at you.\n",
    }) );
    set("damage", ({ 2, 4 }) );
    set("weapon_name", "fists");
    set_verbs( ({ "bite at", "attack" }) );
    set("att_chat_output", ({
      "The zookeeper screams in rage and tries to beat you with his cane.\n",
      "The zookeeper hobbles at you in a rage!\n",
      "The zookeeper curses you!\n",
      "Zookeeper says: Damn you to Hell!\n",
      "Zookeeper says: I'm just helping kids, you Asshole!\n",
      "Zookeeper says: You dirty bastard!\n",
      "Zookeeper says: I'll beat you senseless, you fucking prick!\n",
    }) ) ;
    arm(WEAPONS(cane), "cane");
    set("prevent_summon", 1);
    set_level(10);
}
