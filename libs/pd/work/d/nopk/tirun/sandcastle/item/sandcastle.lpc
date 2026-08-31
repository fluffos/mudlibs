#include <sandcastle.h>
#include <std.h>

inherit OBJECT;

void create() {
  ::create();
    set_name("Sandcastle");
    set_id( ({ "castle", "sandcastle"}) );
    set_short("A Sandcastle");
    set_long("It is a four foot tall sandcastle, made out of sand and water, and standing fairly stable. It has it's own moat and drawbridge. You can see little footprints on the sand-drawbridge, as if someone has %^BOLD%^%^WHITE%^entered%^RESET%^ the sandcastle before, perhaps you should try to enter it.");
    set_weight (100000);
    set_prevent_get("You wouldn't dare ruin such a fine sand castle!");
}

void init() {
  ::init();
    add_action("enter", "enter");
}

int enter(string str) {
  if(!str)
    if(str != "sandcastle") return 0;
    write("%^BOLD%^%^YELLOW%^%^FLASH%^As you walk towards the drawbridge, you seem to shrink in size! Smaller and smaller...%^RESET%^");
    this_player()->move_player(ROOMS "sandcastle1", "into the sandcastle");
    return 1;
}
