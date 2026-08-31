
#include <std.h>
#include <waterworld.h>
inherit ARMOUR;

int extra_worn();
int extra_remove();
int check_up();

void create() {
  ::create();
  set_name("atlantian coat-of-arms");
  set_id(({"atlantian coat-of-arms","coat-of-arms","armour","coat", "coat of arms", "arms", "coat"}));
  set_short("The %^BLUE%^BOLD%^Atlantian%^RESET%^%^BLUE%^ coat of arms%^RESET%^%^RED%^");
  set_long(
   " Only the members of the royal family and their personal guards wear this armour."
   " On occasion, this living armour is rewarded for valiant service to the Atlantian crown."
  );
  set_type("body armour");
  set_ac(16);
  set_limbs( ({"head","left hand","left arm","right hand","right arm","torso"}));
  set_weight(110);
  set_curr_value("gold", 5000);
  set_wear( (: extra_worn :) );
  set_remove( (: extra_remove :) );
  set_read("default", "%^YELLOW%^Issued by the Atlantian Royal Command.");
}

int extra_worn() {
  object tp=this_player();
  string cap_tp=(this_player()->query_cap_name());
  object area=(environment(tp));


  if((tp->query_property("coat-of-arms"))>=1) {
    message("info","The %^BLUE%^%^BOLD%^Atlantian%^RESET%^%^BLUE%^ Royal%^RESET%^ coat of arms comes alive and fuses with your skin!!!",tp);
    message("info","The %^BLUE%^%^BOLD%^Atlantian%^RESET%^%^BLUE%^ Royal%^RESET%^ coat of arms comes alive and fuses with "+cap_tp+"'s skin!!",area,tp);
    tp->do_damage("torso", random(100));

    return 1;
  }
  else {
    message("info","The armour screams at the touch of your skin then melts into a puddle of oily slime!!",tp);
    message("info","The armour screams at the touch of "+cap_tp+"'s skin then melts into a puddle of oily slime!!",area,tp);
    this_object()->remove();
    return 0;
  }
}
int extra_remove() {
  object tp=this_player();
  string cap_tp=(this_player()->query_cap_name());
  object area=(environment(tp));

  message("info","The %^BLUE%^%^BOLD%^Atlantian%^RESET%^%^BLUE%^ Royal%^RESET%^ coat of arms screams as you tear it from your flesh!!",tp);
  message("info","The %^BLUE%^%^BOLD%^Atlantian%^RESET%^%^BLUE%^ Royal%^RESET%^ coat of arms screams as "+cap_tp+" tears it off!!", area, tp);
  tp->do_damage("torso", random(100));
  return 1;
}
int query_auto_load() {
  if( (this_player()->query_property("coat-of-arms"))==1 ) return 1;
  return 0;
}
