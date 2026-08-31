//
// Trivia quest-prize for Waterworld
//       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ARMOUR;

int extra_wear();
int extra_remove();

void create() {
  ::create();
  set_name("gloves of valor");
  set_id(({"gloves of valor","gloves","valor"}));
  set_short("The %^CYAN%^Gl%^MAGENTA%^ov%^RED%^es%^RESET%^ of %^BOLD%^V%^BLACK%^%^BOLD%^al%^GREEN%^or%^MAGENTA%^");
  set_long("The %^CYAN%^Gl%^MAGENTA%^ov%^RED%^es%^RESET%^ of %^BOLD%^V%^BLACK%^%^BOLD%^al%^GREEN%^or%^MAGENTA%^"
   " are soft velvet gloves crafted by the magi of Atlantis.");
  set_type("gloves");
  set_ac(2);
  set_weight(15);
  set_read("default", "Crafted by the master magi of Atlantis.");
  set_wear( (: extra_wear :) );
  set_remove( (: extra_remove :) );
}

int extra_wear() {
  object TP=this_player();
  object TR=environment(TP);
  string cap_tp=TP->query_cap_name();
  string sex_tp=TP->query_possessive();
  string ME=query_short();

  if( (TP->query_property("gloves-of-valor")>=1) ) {
    message("info",
      "The gloves vibrate with power as you slip them on."
     ,TP);
    message("info",
      cap_tp+"'s gloves seem to vibrate with power as "+TP->query_subjective()+" slips them on."
     ,TR,TP);
    TP->add_skill_bonus("defense",20);
    return 1;}
  else {
    message("info",
     "The gloves suddenly disintegrate at your touch!"
     ,TP);
    message("info",
     "The gloves of valor suddenly disintegrate at "+cap_tp+"'s touch!"
     ,TR,TP);
    remove();
    return 0;}
}
int extra_remove() {
  object TP=this_player();
  object TR=environment(TP);
  string cap_tp=TP->query_cap_name();
  string ME=query_short();
  string sex_tp=TP->query_possessive();

  TP->add_skill_bonus("defense",-20);
  return 1;
}
int query_auto_load() {
  if ( (this_player()->query_property("gloves-of-valor"))==1) return 1;
}
