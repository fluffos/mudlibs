#include <std.h>
#include <illuminati.h>

inherit LOCKER;

void create() {
    set_path(ILOBJ"ilstorage");
    ::create();
    set_properties( ([ "light" : 2, "no scry":1, "indoors":1]) );
    set_short("Illuminati Tower");
    set_long("%^ORANGE%^The Illuminati storage room. Lockers cover three of the four walls and each is labeled with a name. Members of the guild are able to %^BOLD%^WHITE%^<store [item]> %^RESET%^ORANGE%^here and then %^BOLD%^WHITE%^<reclaim> %^RESET%^ORANGE%^it later.%^RESET%^");
    set_exits(([
      "northeast" : ILROOM"floor3"
    ]));
}

void init() {
   ::init();
     if(this_player()->query_guild() != "illuminati" && !wizardp(this_player()))
       ILOBJ"ejection"->eject(this_player());
}
