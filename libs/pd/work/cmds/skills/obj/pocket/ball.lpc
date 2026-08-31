
#include <std.h>

inherit OBJECT;

mapping BALL_COLORS = ([
    "blue" : "%^BOLD%^%^BLUE%^",
    "red" : "%^BOLD%^%^RED%^",
    "yellow" : "%^YELLOW%^",
    "green" : "%^BOLD%^%^GREEN%^",
    "purple" : "%^RESET%^%^MAGENTA%^",
    "orange" : "%^RESET%^%^ORANGE%^",
]);

void create() {
  string *colors;
  string color;
  string short;
  ::create();
  colors = keys(BALL_COLORS);
  color = colors[random(sizeof(colors))];
  short = BALL_COLORS[color]+color+"%^RESET%^ juggling ball";
  set_name("ball");
  set_id( ({ "juggling ball", color+" ball", color+" juggling ball" }) );
  set_short(a_or_an(color)+" "+short);
  set_long("The ball is weighted so as to be perfect for juggling, and "
      "it might be good for throwing too. This one is a bright "+
      BALL_COLORS[color]+color+"%^RESET%^ color.");
  set_weight(8);
  set_curr_value("gold", 0);
}

// this is called by the jokers jingle song, to avoid having millions of balls lying around
void remove_if_untouched() {
  object to = this_object();
  object env;
  if (!to) return;
  if (!(env=environment(to)) || (env->is_room() && !to->query_last_location()))
    remove();
}
