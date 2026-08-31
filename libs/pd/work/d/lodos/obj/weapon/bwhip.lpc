#include <std.h>
inherit WEAPON;

create() {
 ::create();
   set_id(({ "whip", "barbed whip", "razor barbed whip" }) );
   set_name("whip");
   set_short("a long, razor barbed whip");
   set_long("The whip is made of a very thin, round, silver coloured, "
     "metal. Along the length of the whip are sharp razorblade barbs. "
     "At the base, is a long, fairly thick black leather handle. This "
     "looks like a torturer's favorite weapon.");
   set_weight(11);
    set_curr_value("gold", 40);
   set_wc(6);
   set_type("flail");
}

int query_auto_load() { if (this_player()->query_skill("flail") >= 20) return 1; }
