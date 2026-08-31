#include <std.h>
#include <amun.h>
inherit ROOM;
#include <tirun.h>
void create() {
    ::create();
    set_no_clean(1);
    set_short("SKY TEMPLE MISC SHOP SUPPLY");
    set_long("This is the storage room where misc. things are kept.");
    set_exits((["northwest" : SKYROOM "misc_shop"]) );
    if(random(100) > 50)
	new(OBJ "tirun_seal")->move(this_object());
    if(random(100) > 60)
	new(OBJ "tirun_seal")->move(this_object());
    if(random(100) > 70)
	new(OBJ "tirun_seal")->move(this_object());
    if(random(100) > 80)
	new(OBJ "tirun_seal")->move(this_object());
    if(random(100) > 50)
	new(OBJ "seal_blank")->move(this_object());
    if(random(100) > 60)
	new(OBJ "seal_blank")->move(this_object());
    if(random(100) > 70)
	new(OBJ "seal_blank")->move(this_object());
    if(random(100) > 80)
	new(OBJ "seal_blank")->move(this_object());
    new(SKYOBJ "angelskin_backpack")->move(this_object());
    new(SKYOBJ "angelskin_backpack")->move(this_object());
    new(SKYOBJ "angelskin_backpack")->move(this_object());
}
