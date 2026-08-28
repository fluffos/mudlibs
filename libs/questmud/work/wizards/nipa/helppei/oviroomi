inherit "room/room";
inherit "room/door";
reset(arg) {

   add_exit("north", "r17.c");
   add_exit("south", "r14.c");
  short_desc = "Dark tunnel";
  long_desc =
  ("Quite dark tunnel, leading north and south. There is a small door on the\n"+
  "western wall. You can hear some children's voices from behind it.\n");
set_light(2);

door_reset();
set_door_label("wooden door",1);
 set_door_dir("west", "r16.c",1);
set_door_link("/wizards/kaappi/mine/r16.c",1);
set_locked(0, 1);

set_not_out();
}

init() {
  ::init();
  door_init();
}
