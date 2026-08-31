
#include <std.h>
#include <dragonevent.h>

inherit DRAG_ITEMS+"geminherit";

string *colors = ({ "white", "blue", "red", "black" });

void create() {
  ::create();
  set_id( ({ "gem", "white gem", "dragon_event_gem_white" }) );
  set_short("a %^BOLD%^%^WHITE%^white%^RESET%^ gem");
  set_long("%^BOLD%^%^WHITE%^This gem is a clear white color. It glows brightly.%^RESET%^");
}

void init() {
  ::init();
  if (this_player() && this_player()->is_player())
    set_heart_beat(2);
}

void heart_beat() {
  object env;

  ::heart_beat();
  if (!this_object()) return;
  env = environment(this_object());

  if (!env || !env->is_player() || DRAG_D->query_data("cangathergems") != 1) {
    set_heart_beat(0);
    return;
  }

  foreach (string c in colors)
    if (!present("dragon_event_gem_"+c, env))
      return;

  // don't let the same person get all the rewards

  if (DRAG_D->query_data("winnergemogrekilled") != 0 &&
      DRAG_D->query_data("winnergemogrekilled") == env->query_name())
        return;

  if (DRAG_D->query_data("winnerchargedgem") != 0 &&
      DRAG_D->query_data("winnerchargedgem") == env->query_name())
        return;

  // this player has gathered all the gems

  DRAG_D->set_data("winnergatheredgems", env->query_name());
  DRAG_D->set_data("cangathergems", 0);
  DRAG_D->set_data("canplacegems", 1);

  message("magic", "%^YELLOW%^The gems resonate in your hands.%^RESET%^", env);
  message("magic", "%^YELLOW%^The gems resonate in "+
    env->query_cap_name()+"'s hands.%^RESET%^", environment(env), env);

  // this is a pretty easy part to do, so lower the reward
  env->add_exp(100000);
  foreach (string stat in ({ "wisdom", "dexterity", "constitution" }) )
    env->set_stats(stat, env->query_base_stats(stat)+1);

  message("magic", "%^BOLD%^%^BLUE%^You feel empowered.%^RESET%^", env);
}

