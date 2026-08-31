#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_no_clean(1);
    set_short("Saints Weapon Supply");
    set_long("This is the storage room where weapons are kept.");
    set_exits((["west" : GUILDROOM+"weapon_room"]) );
}

void reset(){
    ::reset();
    if (!present("dagger")) {
	new(GUILDWEP+"lux_dagger")->move(this_object());
	new(GUILDWEP+"lux_dagger")->move(this_object());
    }
    if (!present("staff")) {
	new(GUILDWEP+"saints_staff")->move(this_object());
	new(GUILDWEP+"saints_staff")->move(this_object());
    }
    if (!present("renegade")) {
	new(GUILDWEP+"renegade")->move(this_object());
	new(GUILDWEP+"renegade")->move(this_object());
    }
}
