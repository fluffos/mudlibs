
// Prize-item for Quessalaz
//    coded by Ironman

#include <std.h>
#include <waterworld.h>

inherit ARMOUR;
int extra_wear();
int extra_remove();

void create() {
  ::create();
  set_name("helm of honor");
  set_id(({"helm of honor","helm","helmet"}));
  set_short("The %^CYAN%^At%^YELLOW%^la%^BLUE%^%^BOLD%^nt%^ORANGE%^ia%^GREEN%^n Helm of %^GREEN%^Ho%^BLACK%^%^BOLD%^no%^RED%^r%^RESET%^");

  set_long("The %^CYAN%^At%^YELLOW%^la%^BLUE%^%^BOLD%^nt%^ORANGE%^ia%^GREEN%^n Helm of %^GREEN%^Ho%^BLACK%^%^BOLD%^no%^RED%^r%^RESET%^"
   " is the personal armor of Prince Triton."
   " On rare events, he gives out copies to those who have proved their wisdom and intelligence to the throne."
  );

  set_type("helmet");
  set_ac(9);
  set_weight(30);
  set_wear( (: extra_wear :) );
  set_remove( (: extra_remove :) );
  set_read("default",
   "\n\n %^ORANGE%^Forged in the royal Atlantian Blacksmith's"
   "\n\n             By Prince Triton"
  );

}

int extra_wear() {
  object TP=this_player();
  string cap_tp=TP->query_cap_name();
  object TR=environment(TP);

  if( (TP->query_property("helm-of-honor"))>=1) {
    message("info","Your mind races as your helmet fuses to your skin.",TP);
    message("info",cap_tp+"'s helmet seems to fuse with "+TP->query_possessive()+" flesh.",TR,TP);
    TP->add_skill_bonus("magic attack",10);
    TP->add_skill_bonus("magic defense",10);
    return 1;
  }
  else {
    message("info","The helmet bursts into flames in your hands and turns to ash!!!",TP);
    message("info","The helmet bursts into flames in "+cap_tp+"'s hands and turns to ash!!!",TR,TP);
    remove();
    return 0;
  }
}
int extra_remove() {
  object TP=this_player();
  object TR=environment(TP);
  string cap_tp=TP->query_cap_name();

  message("info","You sigh heavily as you lift the helmet from your head.",TP);
  message("info",cap_tp+" sighs heavily as "+TP->query_subjective()+" lifts the helmet from "+TP->query_possessive()+" head.",TR,TP);
  TP->add_skill_bonus("magic attack",-10);
  TP->add_skill_bonus("magic defense",-10);
  return 1;
}
int query_auto_load() {
  if( (this_player()->query_property("helm-of-honor"))>=1) return 1;
}
