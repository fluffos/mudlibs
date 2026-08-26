#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

void create(){
  ::create();
  set("short", "a young boy") ;
  set("long", @ENDLONG
This child is playing outside of the castle walls without his mother's
permission.  He is a naughty, naughty child.
ENDLONG
  );
  set("id",({ "boy", "child" }) ) ;
  set("gender", "male");
  set("race", "human");
  set_name("young boy") ;
  credit( 4 ) ;
  set_level(1) ;
  set("stat", ([
   "strength" : 8, "dexterity" : 11, "intelligence" : 13,
   "wisdom" : 8, "charisma" : 14, "constitution" : 11
  ]) ) ;
  set("size", 4) ;
  set_skill("Two Weapon Style", 2, "strength") ;
  set_skill("Ambidexterity", 1, "dexterity") ;
  set_skill("Short Blades", 2, "strength") ;
  set_alignment("cg") ;
  set("damage", ({ 1, 3 }) );
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  set("chat_chance", 5) ;
  set("chat_output", ({
    "The young boy plays in the stagnant waters of the moat.\n",
    "The young boy plays in the mud near the moat.\n",
   "The young boy farts loudly and laughs.\n",
  "The young boy smells his finger and wrinkles his nose in disgust.\n",
    "The young boy looks at you curiously.\n",
    "The young boy digs through his pockets intently.\n",
    "The young boy chases a frog.\n",
    "The young boy chases a snake.\n",
    "The young boy scratches his ass.\n",
    "The young boy pees in the moat.\n",
    "The young boy sings \"Oh Ye Camel of Merriment\".\n",
    "The young boy chases a butterfly.\n",
  }) );
  set("att_chat_output", ({
   "The young boy screams for help!\n",
   "The young boy cries out in pain!\n",
   "The young boy begins to cry.\n",
   "The boy looks at you pleadingly.\n",
   "Young boy says: Please don't hurt me!\n",
   "Young boy exclaims: Help me!  Help me!\n",
  }) ) ;
}
