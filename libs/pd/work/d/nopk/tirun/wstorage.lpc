#include <std.h>
inherit ROOM;
#include <tirun.h>

void create() {
    ::create();
    set_short("Xor's Storage Room");
    set_long("This is the storage room for Xor.");
    set_exits((["east" : ROOMS"weapon"]) );
    set_no_clean(1);
    new(WEP"halberd")->move(this_object());
    new(WEP"ssword")->move(this_object());
    new(WEP"knife")->move(this_object());
    new(WEP"dagger")->move(this_object());
    new(WEP"mace")->move(this_object());
}
