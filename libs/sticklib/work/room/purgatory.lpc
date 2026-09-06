#include <room.h>
#include <areas.h>

#define	SHOP	(AREA_TRISTEZA+"shops/shop")
#define	WEAPONER	(AREA_TRISTEZA+"shops/weaponer")
#define	ARMOURER	(AREA_TRISTEZA+"shops/armourer")

void
create_room()
{
    set(PREVENT_TELEPORT);
    set_light_level(LT_LIGHTS);
    set_outdoors(WD_INDOORS);
    set(NO_CLEANUP);
    set_short("Purgatory");
    set_long("This room could as well be a hydroponic garden to all looks\
 and appearances. This is where they stow all those link-deaders to spend the\
 rest of their days as living vegetables.");
    set_exits(([ "church" : "/room/church" ]));
}

void
bail_out(status arg)
{
    object *inv;
    status left;
    int i;
    inv = all_inventory(this_object());
    for (i = left = 0; i < sizeof(inv); i++) {
	if (object_name(inv[i])[0 .. 9] == "obj/player") {
	    if (find_call_out("bail_out") < 0)
		call_out("bail_out", 1, arg);
	    left = 1;
	    // Let's do this by looping!
	    // (to prevent too_big_eval_cost) -+ Doomdark +-
	    if (!arg || !inv[i] -> query_coder_level()) {
		move_object(inv[i], SHOP);
		command("sell all", inv[i]);
		move_object(inv[i], WEAPONER);
		command("sell all", inv[i]);
		move_object(inv[i], ARMOURER);
		command("sell all", inv[i]);
		command("quit", inv[i]);
	    }
	}
	if (inv[i]) destruct(inv[i]);
	if (left) return;
    }
}

void init_room()
{
    // Lets let coders come here - Germ 4/15/96
    if ( interactive(this_player())
      && !this_player()->query_coder_level() )
    {
	this_player()->tell_me("You are teleported to the church yard.");
	this_player()->move_player("X", "/room/church");
    }
}
