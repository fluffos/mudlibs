#include <mudlib.h>
#include "../defs.h"

inherit MONSTER;

create(){
  ::create();
  set("short", "a stable boy");
  set("smell", "He smells like manure and sweat.") ;
  set("long", @ENDLONG
A simple human boy of no more than 15 or 16 years of age who helps
keep the stables clean.
ENDLONG
  );
  set("id", ({ "stable boy", "boy" }) );
  set("gender", "male");
  set("race", "human");
  set_name("stable boy");
  credit(random(20)) ;
  set_level(3);
  set_alignment("cg") ;
  set("damage", ({ 2, 4 }) );
  set_size( 6);
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
  arm(WEP(pitchfork), "fork");
  wear(ARM(overalls), "overalls");
 set("chat_chance", 6);
  set("chat_output", ({
  "The boy whistles a little ditty.\n",
  "The boy wipes some manure on his overalls.\n",
  "The boy pitches some hay.\n",
  "The boy slips in some manure and curses under his breath.\n",
  "The boy pitches some hay and wipes the sweat from his brow.\n",
  }) );
  set("att_chat_output", ({
  "The boy cries out in pain!\n",
  "The boy slings some manure at you!\n",
  }) );
}

