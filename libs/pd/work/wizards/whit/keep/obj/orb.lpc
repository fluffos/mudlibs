//  The keeps lighting orbs
#include <std.h>
inherit OBJECT;
int in_use;
object holder;
void create() {
    ::create();
    set_name("Keeps Orb");
    set_short("light orb");
    set_id(({"keep_orb", "orb", "light orb", "magical orb"}));
    if(!in_use)
	set_long("The orb is glowing dim blue.  The light doesnt "
	  "seem to help with viewing the room.");
    else
	set_long("The orb is emitting a bright orange color.  "
	  "Despite how bright the orb is, it still remains "
	  "cool to touch.");
}
void check() {
    if(environment(this_object())->is_player()) {
	environment(this_object())->force_me("light 12345");
	holder=this_player();
    }

}
void init() {
    ::init();
    add_action("light", "light");
    check();
}
int light(string s) {
    if(s != "12345" && s != "54321") return 0;
    switch(s) {
    case "12345":
	if(!in_use) {
	    message("", "As you pick up the orb, its glow "
	      "changes from a dim blue to a bright orange.", 
	      environment(this_player()));
	    in_use=1;
	    create();
	} else return 0;
	break;
    case "54321":
	if(in_use) {
	    message("", "The orb returns to its original dim blue color as "
	      "it leaves your hands.", 
	      environment(this_player()));
	    in_use=0;
	    create();
	} else return 0;
	break;
    default: return 0; break;
    }
}
