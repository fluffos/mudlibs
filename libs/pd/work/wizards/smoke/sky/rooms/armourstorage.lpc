#include <std.h>
inherit ROOM;
#include <cp.h>

void create() {
    ::create();
    set_no_clean(1);
    set_short("Dwarven Tailor's Storage");
    set_long("This is the storage room for the dwarven tailor.");
    set_exits((["shop" : ROOMS"armory"]) );
    new(ARM"l_helm")->move(this_object());
    new(ARM"l_bracers")->move(this_object());
    new(ARM"l_boots")->move(this_object());
    new(ARM"l_gloves")->move(this_object());
    new(ARM"l_armour")->move(this_object());
    new(ARM"l_pants")->move(this_object());
}
