#include <std.h>
#include <amun.h>
inherit OBJECT;
void create() {
    ::create();
    set_name("A Harp");
    set("id", ({"harp"}) );
    set_short("%^BOLD%^%^YELLOW%^A Harp%^RESET%^");
    set_long("%^BOLD%^%^YELLOW%^A soothing song from this dear harp, may save a land from falling apart.  Find the beast within a hole, and save these wild inferi's souls.%^RESET%^");
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

    if( present( "amun_dragon", environment(this_player()) ) ) {
	if( this_player()->query_current_attacker() ) {
	    write("You cannot play in combat!");
	    return 1;
	}
	present("amun_dragon", environment(this_player()))->set_rest_type(1);
        new("/d/nopk/standard/obj/misc/pillow")->move(present("amun_dragon", environment(this_player())));
	write("You manage to play a melody on the harp, putting the dragon to sleep.");
	say(this_player()->query_cap_name() + " manages to play a melody on the harp, putting the dragon to sleep.");
	if (this_player()->set_manual_quest("inferi", 2) ) {
	    write("%^BOLD%^%^YELLOW%^You have saved the land of Inferi!  Thank you!  You have been rewarded.");
	    this_player()->set_stats("strength", this_player()->query_base_stats("strength") + 2 );
	    this_player()->set_stats("dexterity", this_player()->query_base_stats("dexterity") + 2 );
	    this_player()->set_stats("constitution", this_player()->query_base_stats("constitution") + 2 );
	    this_player()->set_stats("charisma", this_player()->query_base_stats("charisma") + 2 );
	    this_player()->set_stats("wisdom", this_player()->query_base_stats("wisdom") + 2 );
	    this_player()->set_stats("intelligence", this_player()->query_base_stats("intelligence") + 2 );
	}
	return 1;
    }

    write("You play beautiful music, but nothing happens.");
    say(this_player()->query_cap_name() + " plays beautiful music, but nothing happens.");
    return 1;
}
