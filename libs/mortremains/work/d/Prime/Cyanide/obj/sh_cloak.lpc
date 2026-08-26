// Sh_cloak.c

#include <mudlib.h>
#include <magic.h>

inherit ARMOR;
void create() {
    set("short", "a Cloak of Night");
    set("long", @Suckme
A transluscent black cloak, woven from the very essence of night.
Suckme
    );
    set("id", ({ "cloak", "cloak of night" }) );
    set_armor_type("cloak");
    set("size", -1);
    set("bonus", 2);
}

void init() {
    if (!living(environment(this_object())))
	call_out("remove", 1);
}

void remove() {
    object ob = environment(this_object());

    if (ob)
	tell_room(ob,
	  "The cloak evaporates into a fine black smoke.\n");
    ::remove();
}

