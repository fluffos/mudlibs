#include <mudlib.h>

inherit MONSTER;

create(){
  ::create();
  set("short", "a prisoner") ;
  set("long", @ENDLONG
The prisoner lives in this cell.
ENDLONG
  );
  set("id", ({ "prisoner", "man" }) ) ;
  set("gender", "male") ;
  set("author", "Chronos") ;
  set("race", "human");
  set_name("prisoner") ;
  set_align("ln") ;
  set_level(2) ;
  set("CLASS", "warrior") ;
  set("natt", 1);
  set("damage", ({ 2, 4 }) );
  set_size( 6);
  set("weapon_name", "fists");
  set_verbs( ({ "swing at", "attack", "punche at", "trie to punch" }) ) ;
}
