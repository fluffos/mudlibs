/* Dagger of Thieves */

#include <weapon.h>

void
create_weapon()
{
    set_name("dagger");
    set_weight(2);
    set_value(400);
    set_short("thieven dagger");
    set_id("thieven dagger");
    set_info("A magic weapon made especially for thieves");
}

init() {
    int cl;

    if(!this_player() || !living(this_player())) return;
    ::init();

    set_wc(1);

    if(!present("tmark",this_player())) {
	tell_object(this_player(),"The dagger disintegrates.\n");
	destruct(this_object());
	return;
    }
    // Let's alter this a bit. Where do thieves get these?!?!
    // Also, wc 18 is max. for non-unique 1-handed weapons.
    cl = (int) this_player()->query_level();
    cl = cl * 2 / 3;
    if(cl > 18) cl = 18;
    if(cl < 5) cl = 5;
    set_wc(cl);
}
