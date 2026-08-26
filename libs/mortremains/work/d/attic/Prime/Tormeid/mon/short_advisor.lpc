#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "an advisor") ;
  set("long", @ENDLONG
He is a short, squat man with squinty eyes.
Looking at him closely, you get the feeling he is a very greedy man.
He looks at you with disgust and contempt.
ENDLONG
  );
  set("id", ({ "short advisor", "advisor" }) ) ;
  set("gender", "male");
  set("race", "human");
  set_name("advisor") ;
  credit(random(500) + 69) ;
  set_level(5);
  set_alignment("n") ;
  set("damage", ({ 2, 4 }) );
  set_size( 6);
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  set("chat_chance", 11) ;
  set("chat_output", ({
  "Advisor says: What are you doing in here, scum?!\n",
  "Advisor says: What are you doing in here, street rat?!\n",
  "Advisor says: Take your dirt and filth somewhere else, vagabond!\n",
  "Advisor says: Remove yourself immediately!\n",
 "Advisor scoffs at you.\n",
 "Advisor frowns in disgust.\n",
  "Advisor mutters something under his breath.\n",
  "Advisor says: I cannot believe the audacity of these vagrants.\n",
  "Advisor says: Are you daft?!  Leave us be!\n",
  "Advisor says: Guards!  Remove this peasant!\n",
  "Advisor scowls at you.\n",
  "Advisor mutters something under his breath.\n",
  "Advisor glares at you.\n",
  }) );
  set("att_chat_output", ({
  }) );
}

