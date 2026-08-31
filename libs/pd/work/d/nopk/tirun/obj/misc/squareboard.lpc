#include <std.h>
inherit OBJECT;
void init()
{
 ::init();
 add_action("read_post", "read");
}
void create() {
 ::create();
   set_id(({ "squareboard", "board" }));
   set_name("tattered board");
   set_long("An old tattered board. There is one post upon it.");
   set_short("an old tattered board");
   set_weight(1);
   set("value", 0);
set_prevent_get( "The sign is stuck in the ground." );
}
int read_post(string str)
{
 if (!str || str=="") return 0;
 if (str!="post" && str!="board") return 0;
 write("The board has been moved to the Drowning Fish Tavern.  It is located in the tavern to the south and east.");
 return 1;
}
