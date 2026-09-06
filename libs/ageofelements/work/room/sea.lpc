#include <mxp.h>

inherit "/lib/room";

void create_room() {
    set_lumens(1);

    set_brief("All at sea");

    set_description(
	sprintf("You are swimming out at sea. Go ahead and take a %sdive%s!"
	    , MXPTAG("send")
	    , MXPTAG("/send")
	  )
      );

    add_exit("west", "/room/jetty2");

    add_command("dive", "dive_cmd");
}

int dive_cmd(string arg) {
    object ob;

    ob = first_inventory(this_player());

    while (ob) {
	if (ob->can_put_and_get()) {
	    this_player()->move_player("down#room/sea_bottom");
	    return 1;
	}

	ob = next_inventory(ob);
    }

    write("You can't breathe under water!\n");
    write("Go get a portable air supply and try again!\n");

    return 1;
}
