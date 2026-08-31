#include <std.h>
#include <amun.h>
inherit ROOM;
void create() {
    ::create();
    set_property("night light", 0);
    set("short", "MARSHES");
    set("long","%^RESET%^%^ORANGE%^The ground is covered in shrubs and bogs making it trialing to find solid ground to walk on. The waters to the east and west show dead bodies floating. There must have been a great battle here long ago of all races. To the north, something can be seen coming out of the water.%^RESET%^");
    set_exits( ([ "northwest" : MARSHROOM+"BM_18", "north" : MARSHROOM+"BM_20", "southwest" : MARSHROOM+"BM_10", "south" : MARSHROOM+"BM_12" ]) );
    add_pre_exit_function("north", "sp_sap");
    add_pre_exit_function("south", "sp_sap");
}
void reset() {
    ::reset();
    if (!present("giant", this_object()))
	new(MARSHMON+"inferi_giant")->move(this_object());
    if (!present("netherman", this_object()))
	new(MARSHMON+"inferi_netherman")->move(this_object());
}
