#include <std.h>


inherit OBJECT;


int create() {
 ::create();
 set_name("blah");
 set_short("blah");
 set_id ( ({ "blah" }) );
 set_weight( 1 );
 set_value ( 1);
}

int init()
{
 add_action("trans", "trans");
}

int trans(string blah) {
 if (!blah) return 0;
 write("Blam");
 this_player()->move(blah);
 return 1;

}
