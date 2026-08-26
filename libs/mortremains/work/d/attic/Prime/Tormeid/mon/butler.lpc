#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "a butler");
  set("long", @ENDLONG
The butler looks very serious.
ENDLONG
  );
  set("id", ({ "butler" }) );
  set("gender", "male");
  set("race", "human");
  set_name("butler");
  credit(random(75)) ;
  set_align("ln") ;
  set_level(5);
  set("CLASS", "warrior") ;
  set("natt", 1);
  set("damage", ({ 2, 4 }) );
  if (!random(10)) clone_object(OBJ(servant_key))->move(TO) ;
  set_size( 6);
  set("weapon_name", "fists");
  set("smell", "The butler smells very clean.") ;
  set_verbs( ({ "swing at", "attack" }) );
  set("chat_chance", 11) ;
  set("chat_output", ({
   "The butler looks at you blankly.\n",
  "The butler shifts uncomfortably.\n",
  "Butler says: May I take your coat?\n",
   "The butler adjusts his uniform.\n",
  "Butler says: May I take your hat?\n",
  "Butler says: Good day to you.\n",
   "The butler nods solemnly at you.\n",
  }) );
  set("att_chat_output", ({
   "Butler says: You ruffian!\n",
  "Butler says: You scoundrel!\n",
  "Butler says: You villian!\n",
  "Butler says: Don't make me resort to fisticuffs!\n",
  "Butler says: Don't make me give you boxing!\n",
  "Butler dances about awkwardly, fists raised.\n",
   "Butler says: I will give you boxing!\n",
  "The butler bounces back and forth, ducking and bobbing.\n",
  "Butler says: You will regret this!\n",
 "Butler says: Take that, you trouble-maker!\n",
  "The butler dances about awkwardly, fists raised.\n",
  }) );
}

