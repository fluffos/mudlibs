#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_no_clean(1);
    set_short("Saints Equipment Supply");
    set_long("This is the storage room where equipment is kept.");
    set_exits((["west" : GUILDROOM+"object_room"]) );
}
void reset() {
    ::reset();
    if(!present("leather sack")) {
	new(GUILDOBJ+"leather_sack")->move(this_object());
	new(GUILDOBJ+"leather_sack")->move(this_object());
	new(GUILDOBJ+"leather_sack")->move(this_object());

    }

    if(!present("seal")) {
	if(!random(3)) new(GUILDOBJ+"last_saints_seal")->move(this_object());
    }
    if (!present("abyss")) {
	new(GUILDOBJ+"abyss")->move(this_object());
	new(GUILDOBJ+"abyss")->move(this_object());
	new(GUILDOBJ+"abyss")->move(this_object());
    }
}
