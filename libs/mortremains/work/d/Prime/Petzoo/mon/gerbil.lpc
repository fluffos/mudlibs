// A gerbil you can shove up your ass!
// Written by Chronos, YEARS ago.
#include <mudlib.h>

inherit MONSTER;

create(){
    ::create();
    set("short", "a furry gerbil");
    set("race", "furry rodent") ;
    set("long", "It's a cute little gerbil, Awwww.  How Cute.\n") ;
    set("id", ({ "#BLAH", "gerbil", "rodent" }) );
    set_name("gerbil");
    set_level(1) ;
    set_alignment("n");
    set("damage", ({ 1, 2 }) );
    set("weapon_name", "teeth");
    set("chat_chance", 12) ;
    set("chat_output", ({ 
      "The gerbil scurries around.\n",
      "The gerbil sniffs you cautiously.\n",
      "The gerbil looks around carefully.\n",
      "The gerbil looks at you carefully.\n",
      "The gerbil squeaks.\n",
      "The gerbil stand up on its hind legs.\n",
    }) );
    credit(query_level() * 20); 
    set_verbs( ({ "bite at", "attack" }) );
}

void init() {
    add_action("put", "put") ;
    add_action("put", "shove") ;
    add_action("put", "place") ;
}

int put(string str) {
    if (!str) return 0 ;
  if (str == "gerbil") {
     write("Where would you like to put the gerbil?\n") ;
   return 1;
  }
    if (sscanf(str, "%s in ass", str)!=1 && 
      sscanf(str, "%s up my ass", str) != 1 &&
      sscanf(str, "%s in my ass", str) != 1 &&
      sscanf(str, "%s up ass", str)!=1) return 0 ;
    if (str!="gerbil") return 0 ;
    write("You shove the gerbil up your ass.\n") ;
    say(TPN+" shoves the gerbil up "+TP->query_possessive()+" ass.\n") ;
    remove() ;
    return 1;
}

void die() {
  tell_room(environment(),
@ENDDIE
The gerbil appears thankful for being killed instead of being shoved
up someone's ass, like Richard Gere might have done.
ENDDIE
  ) ;
  ::die() ;
}
