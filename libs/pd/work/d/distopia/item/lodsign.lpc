//Used and modified from Whit's original code by Hermes.
#include <std.h>
#include <hermes.h>
inherit OBJECT;
void create() 
{
	::create();
    set_name("God sign");
    set_short("a lighted sign");
    set_long("This is an illuminated sign set down by a concerned God for players.");
    set_prevent_get
    (
    	"The Gods would not want anyone "
    	"to take their sign."
    );
    set_id(({"run down sign","sign"}));
}
void init() {
    ::init();
    add_action("read", "read");
}
int read(string str) {
    if(!str || str != "sign") {
        write("Read what?\n");
        return 1;
    }
    say(this_player()->query_cap_name()+" "
      "reads the sign.");
   	message("info",
	"A warning to all adventures by the Gods above. "
	"The land to the east is one of death and should "
	"not be entered by those that are not at least "
	"level twenty five.", this_player());
    return 1;
}
