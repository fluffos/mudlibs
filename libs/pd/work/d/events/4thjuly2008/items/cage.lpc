
#include <std.h>
#include <id4.h>
#include <rest.h>

inherit OBJECT;

int oktodie;

void touch_cage(string);
int grab_bars(string);
void next(mixed *args);

void set_ok(int i) { oktodie = i; }

void create() {
  ::create();
  set_name("cage");
  set_id( ({ "cage", "lightning cage", "cage of lightning" }) );
  set_short("a cage made of lightning");
  set_long("A magical cage made entirely of lightning. The bars are "
    "%^YELLOW%^va%^WHITE%^ri%^BLACK%^ou%^RESET%^%^ORANGE%^s %^RESET%^"
    "colors of lightning and in constant flux, moving wildly about.\n"
    "Inside, a white dragon cringes away from the bars.");
  set_prevent_get("It would surely kill you.");
  set_weight(5000);
  set_touch( ({ "default", "bars" }), (: touch_cage :) );
}

void touch_cage(string what) {
  object tp = this_player();
  object env = environment();
  
  if (tp->query_busy()) return;
  tp->set_disable(1);
  tp->add_hp(-(100+random(250)));
  if (tp->query_hp() < 1) tp->set_hp(1);

  message("magic", "%^BOLD%^As you touch the cage, a lightning bolt "
    "ZAPS out and electrocutes you!", tp);
  message("magic", "%^BOLD%^As "+tp->query_cap_name()+" touches the cage, "
    "a lightning bolt ZAPS out and electrocutes "+
    tp->query_objective()+"!", env, tp);

  tp->show_status_line();

  if (!random(4)) {
    tp->set_rest_type(LAY);
    message("magic", "You are thrown backward from the shock!", tp);
    message("magic", tp->query_cap_name()+" is thrown backward "
      "from the shock!", env, tp);
  }

}

void init() {
  ::init();
  add_action("grab_bars", ({ "grab", "hold", "grip", }) );
}

int grab_bars(string str) {
  object tp = this_player();
  object to = this_object();
  object env = environment();
  object *tokens;

  if (!tp || !to || !env || env != environment(tp)) return 0;

  if (!str || (str != "bars" && str != "cage"))
    return notify_fail(capitalize(query_verb())+" what?\n");
  
  if (oktodie && tp->query_race() != "dragon" &&
      !(sizeof(tokens = children(ITEMS+"token")) &&
      sizeof(filter(tokens, (: $1->query_owner() == $2 :), tp))) ) {
    message("magic", "%^BOLD%^You grab hold of two of the bars of the cage."
      "\n\n"
      "%^YELLOW%^Lightning surges through your body!", tp);
    message("magic", "%^BOLD%^"+tp->query_cap_name()+" grabs hold of two of "
      "the bars of the cage.\n\n"
      "%^YELLOW%^Lightning surges through "+tp->query_possessive()+" body!",
      env, tp);
    tp->set_paralyzed(50, "Your body is spasming from the lightning!");
    oktodie=0;
    call_out("next", 1, ({ 0, tp }));
  }

  else touch_cage("bars");

  return 1;
}

void next(mixed *args) {
  int count = args[0];
  object tp = args[1];
  object env;
  object dragon;

  if (!tp) return;
  env = environment(tp);
  if (!env || env != environment()) return;

  switch (count) {
    default:
    case 0:
      message("magic", "%^YELLOW%^The power of the lightning intensifies!", env);
    break;

    case 1:
      message("magic", "%^BOLD%^The pain is almost too much to bear, but you "
	  "can't make your hands let go!", tp);
      message("magic", "%^BOLD%^"+tp->query_cap_name()+" spasms in "
	  "incredible pain!", env, tp);
    break;

    case 2:
      message("magic", "%^ORANGE%^Your body starts to sizzle and steam!", tp);
      message("magic", "%^ORANGE%^"+tp->query_cap_name()+"'s body starts to "
	  "sizzle and steam!", env, tp);
    break;

    case 3:
      message("magic", "%^BOLD%^%^BLACK%^Starbursts and pits of blackness dance "
	  "before your eyes as the last of your senses leaves you.", tp);
      message("magic", "%^BOLD%^%^BLACK%^The lightning engulfs "+tp->query_cap_name()+
	  " completely!", env, tp);
    break;

    case 4:
      message("magic", "%^BOLD%^One last surge of pain, and you fall to the "
	  "ground, unconscious and dying.", tp);
      message("magic", "%^BOLD%^One last surge of lightning blasts through "+
	  tp->query_cap_name()+", and "+tp->query_subjective()+" falls "
	  "to the ground.\n\n"
	  "%^RESET%^The cage of lightning dissipates.", env, tp);
      tp->set_rest_type(LAY);
      tp->set_hp(3);
      tp->set_paralyzed(20, "You are unconscious and dying.");
      dragon = new(MOBS+"white_dragon");
      dragon->move(environment());
      dragon->set_person(tp);
      dragon->start();
	  environment()->set_property("finished_quest", 1);
      remove();
    return;

  }

  tp->add_hp( -(tp->query_hp() / ( 7 - count )) );
  if (tp->query_hp() < 1) tp->set_hp(1);
  tp->show_status_line();

  call_out("next", 4, ({ count+1, tp }) );
}

