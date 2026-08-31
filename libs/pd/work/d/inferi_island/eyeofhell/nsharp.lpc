#include <std.h>
#include <amun.h>
inherit OBJECT;
void create() {
    ::create();
    set_name("A Harp");
    set("id", ({"harp"}) );
    set_short("%^BOLD%^%^YELLOW%^A Harp%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^Made by Amun herself, this diamond amulet can be found around the %^CYAN%^Queens %^WHITE%^neck. It is made of pure diamond, with cr%^RESET%^%^WHITE%^y%^BOLD%^%^WHITE%^st%^RESET%^%^WHITE%^a%^BOLD%^%^WHITE%^ls surrounding it.  It is very beautiful and very valuable.");
    set_weight(10);
    set_value(200);
}
void init() {
    ::init();
    add_action( "play_harp", "play");
}
int play_harp (string str) {

    if(!str || str != "harp") {
	return notify_fail("Maybe you should try playing the harp.");
    }

    if( present( "dragon", environment(this_player()) ) ) {
        present("dragon", environment(this_player()))->set_rest_type(1);
        write("You put the dragon to sleep with your bootiful moosik.");
        say(this_player()->query_cap_name() + " puts the dragon to sleep.");
        return 1;
    }

    write("You fumble around with the harp and play a quick tune.");
    say(this_player()->query_cap_name() + " plays a quick tune.");

    return 1;
}
