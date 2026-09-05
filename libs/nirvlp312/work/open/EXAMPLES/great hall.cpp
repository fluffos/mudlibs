inherit "room/room";

int i;

reset(arg) {
	if(!present("brutus")) {
	  for(i=0;i<2;i++) {
	  move_object(clone_object("open/EXAMPLES/brutus"), this_object());
	}
    }
	if(!arg) {
	set_light(1);
	short_desc = "Great Hall";
	long_desc = "\n"+
	"     This is the great hall of the Castle, here you notice a throne\n"+
	"in the far distance.t.\n";
	dest_dir = ( {
		"open/EXAMPLES/exampleroom", "north",
		"open/EXAMPLES/exampleroom2", "south",
		"room/shop", "shop",
		});
	}
}
