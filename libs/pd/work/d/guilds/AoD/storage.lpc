#include <std.h>
#include <guild.h>
inherit ROOM;
int i = 0;
void create() {
    ::create();
    set_short("Storage Room");
    set_long("This is the holding area for Flints inventory.");
    set_exits((["east" : AoD"hall"]) );

}
void
reset()
{
    ::reset();


    while(++i < 3) {
	if(!present("gloves "+i))
	    new(AoD"special/gloves")->move(this_object());
	if(!present("angrist "+i))
	    new(AoD"special/angrist")->move(this_object());
	if(!present("darkness "+i))
	    new(AoD"special/darkness")->move(this_object());
	if(!present("skullcrusher"+i))
	    new(AoD"special/skullcrusher")->move(this_object());
	if(!present("bloodring"+i))
	    new(AoD"special/bloodring")->move(this_object());
	if(!present("wingflames"+i))
	    new(AoD"special/wingflames")->move(this_object());
	if(!present("nunchaku"+i))
	    new(AoD"special/nunchaku")->move(this_object());
	if(!present("kabuto"+i))
	    new(AoD"special/helmet")->move(this_object());
//if(!present("armor"=i))
//new(AoD"special/armor")->move(this_object());
	if(!present("belt "+i))
	    new(AoD"special/belt")->move(this_object());
//if(!present('mask "+i))
//new(AoD"special/mask")->move(this_object());
	if(!present("sack"+i))
	    new(AoD"special/sack")->move(this_object());
	if(!present("tabi"+i))
	    new(AoD"special/tabi")->move(this_object());
	if(!present("tattoo"+i))
	    new(AoD"special/tattoo")->move(this_object());
	if(!present("cloak"+i))
	    new(AoD"special/cloak")->move(this_object());
	/*
		if(!present("krull"+i))
		    new(AoD"special/krull")->move(this_object());
	*/
    }
}
