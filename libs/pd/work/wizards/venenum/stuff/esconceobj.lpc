#include <std.h>
#include <venenum.h>
inherit OBJECT;

string *lines = ({"newbie","auction","dragon","black","DW","ethereal","unholy","scorpio","vorticon","forsaken","illuminati","chosen","dw","aod","acheron","hm","legend","colosseum","gossip","OOC","trivia","elite","guild","council","tell","emoteto"});

void create() {
    ::create();
    set_name("");
    set_id( ({ ""}) );
    set_short("");
    set_long("If you can see this, you are cheating somehow!");
    set_mass(0);
    set_value(0);
    set_prevent_get("You can't pick this up! SCUM!");
}

void init() 

{
    ::init();
    add_action("catch_talk", "");
}

int catch_talk(string str)
{
    str = query_verb();          
    if(member_array(str, lines) == -1)
    {
	write("You reveal yourself.");
	this_player()->set_invis();
	this_object()->remove();
	return 1;
    }
}
