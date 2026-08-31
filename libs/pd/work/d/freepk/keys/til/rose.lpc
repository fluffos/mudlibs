#include <std.h>
inherit OBJECT;

void create() {
 ::create();
   set_name("rose");
   set_short("thorny rose");
   set_long("%^RED%^---<--{(@%^RESET%^
   The rose is unusually thorny. A single red petal drops from
   the rose and hits the ground.
%^RED%^@)}--->---");
   set_weight(1);
   set_value(19);
   set_id(({ "rose", "red rose", "thorny rose", "flower" }));
}

int query_auto_load() { if (this_player()->query_gender() == "female") return 1; }
