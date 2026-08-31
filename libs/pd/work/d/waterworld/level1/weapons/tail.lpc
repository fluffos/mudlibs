#include <std.h>
inherit WEAPON;

void create() {
    ::create();

      set_name("bass tail");
      set_id(({"bass tail","tail","flail","fin","caudal fin","bass fin"}));
      set_short("the caudal fin of a stripper bass.");
      set_long("This is the caudal(or tail) fin of a bass. It can be used as a flail, but it feels kinda slimy considering the bass is no longer attached to it.");
       set_type("flail");
       set_wc(4);
        set_weight(10);
        set_decay_rate(400);
        set_curr_value("gold",5);
}
int query_auto_load() {
        if( (this_player()->query_level())>= 20) {return 1;}
        else {return 0;}
}
