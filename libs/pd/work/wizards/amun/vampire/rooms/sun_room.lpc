#include <std.h>

inherit PERIODIC_ROOM;

void create() { periodic_room::create(); set_period(4);}
void init() { periodic_room::init(); }

int periodic() {
    object *livs;

    livs = filter(all_inventory(this_object()), (: $1->is_living() :) );
    livs = filter(livs,
      function (object l) {
	  object c = present("daywalker cloak", l);
	  if (c && c->query_worn() == l)
	      return 0;
	  return 1;
      }
    );
    if (sizeof(livs)) {
	livs->add_hp(-(200+random(100)));
	message("info", "%^BOLD%^%^YELLOW%^The sun %^RED%^burns %^YELLOW%^into your skin causing you to lose health!%^RESET%^", livs);
	return 1;
    }

    return 0;
}
