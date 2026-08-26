// Sh_sword.c

#include <mudlib.h>
#include <magic.h>

inherit WEAPON;

void create() {
    set("short", "a Shadow Blade");
    set("long", wrap("A seemingly delicate blade crafted of"+
	" what appears to be a dark, smoky crystal."));
    set("id", ({ "sword", "blade", "shadow blade" }) );
    set_weapon_type("sword/long");
    set_material_type("crystal");
    set("name", "Shadow Blade");
    set("bonus", 3);
}

void init() {
    if (!living(environment(this_object())))
	call_out("remove", 1);
}

void remove() {
    object ob = environment(this_object());

    if (ob)
	tell_room(ob,
	  "The sword evaporates into a fine black smoke.\n");
    ::remove();
}

