#include <mudlib.h>

inherit MONSTER;

create(){
  ::create();
  set("short", "a lost adventurer") ;
  set("smell", "He smells bad.  Probably been lost a while.");
  set("long", @ENDLONG
This young man obviously thought adventuring was easy.  He's wandered far
from home, and now he's lost without a clue.  Much like yourself.
He looks like he's been robbed and beat up a few times now.
ENDLONG
  );
  set("id", ({ "man", "adventurer", }) ) ;
  set("gender", "male");
  set("race", "human");
  set_name("adventurer") ;
  set_level(3);
  set_alignment("cg") ;
  set("damage", ({ 2, 4 }) );
  set_size( 6);
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack" }) );
 set("chat_chance", 6);
  set("chat_output", ({
  "The adventurer looks around and tries to get his bearings.\n",
  "The adventurer asks you for a coin or two.\n",
  "The adventurer scratches his head and looks around.\n",
  "Adventurer says: Where the hell am I?\n",
  "Adventurer sighs.\n",
  }) ) ;
  set("att_chat_output", ({
  "The adventurer panics.\n",
  "The adventurer tries to run away.\n",
  }) );
set("wimpy", 10 ) ;
}

