#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_no_clean(1);
    set_short("Saints ARMOUR SUPPLY");
    set_long("This is the storage room where armour is kept.");
    set_exits((["east" : GUILDROOM+"armour_room"]) );
}
void reset() {
    ::reset();
    if (!present("ring")) {
	new(GUILDARM+"all_saints_ring")->move(this_object());
	new(GUILDARM+"all_saints_ring")->move(this_object());
    }
    if (!present("bracers")) {
	new(GUILDARM+"lux_bracers")->move(this_object());
	new(GUILDARM+"lux_bracers")->move(this_object());
    }
    if (!present("rosary")) {	
	new(GUILDARM+"saints_rosary")->move(this_object());
	new(GUILDARM+"saints_rosary")->move(this_object());
    }
}
