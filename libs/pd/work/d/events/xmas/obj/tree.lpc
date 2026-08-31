//  Christmas Garland

#include <std.h>

inherit OBJECT;
string *names;
void create() {
    ::create();
   set_id(({"tree", "christmas tree"}));
    set_name("a christmas tree");
    set_short("a christmas tree");
    set_long("The christmas tree is brightly lit up and decorated with "
      "several ornaments.  The ornaments look as if they were gathered "
      "from all over the land.  There are several presents under the "
      "tree.  Looking closer you see that one of the presents is "
      "yours.  You should <take present> to get your christmas present.");
    set_weight(20000);
    set_prevent_get("You shouldn't be such a grinch!");
}

void init() {
    ::init();
    add_action("take", "take");
}

int take(string s) {
    int i;
    if(s != "present") return notify_fail("Take what.\n");
    if(!names) names = ({});
    if(member_array(this_player()->query_name(), names)!=-1) return
	notify_fail("Dont be so greedy, you only get one.\n");
    i=random(3);
    switch(i) {
    case 0:
    case 1:
	write("You take some garland from your present under the tree.");
	say(this_player()->query_cap_name()+" gets some garland from "+
	  possessive(this_player())+" present under the tree.\n");
	new("/d/events/xmas/obj/garland")->move(this_player());
	names += ({this_player()->query_name()});
	break;
    case 2:
	write("You take a potion from your present under the tree.");
	say(this_player()->query_cap_name()+" gets a potion from "+
	  possessive(this_player())+" present under the tree.\n");
	new("/d/events/xmas/obj/potion")->move(this_player());
	names += ({this_player()->query_name()});
	break;
    }
   return 1;
}

