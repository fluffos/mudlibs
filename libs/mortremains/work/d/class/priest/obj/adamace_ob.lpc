// Ilzarion created this originally.
// Changes:
//   16 Dec 98  Cyanide cleaned up and updated.

#include <magic.h>

inherit SPELL;
inherit WEAPON;

void create() {
    seteuid(getuid());
    set("id", ({ "adamantium mace", "mace" }) );
    set("short", "an adamantium mace");
    set("name", "adamantium mace");
    set("long", "A un-initialized mace.\n");
    set_weapon_type("mace");
    set_bonus(4, 2, 2);
    set_material_type("metal/adamantium");
    set("prevent_drop", 1);
    set("prevent_sell", 1);
    set("dest_at_die", 1);
    set_verbs(({ "hit", "pound on", "maul" }));
}

int begin_spell(object caster, int lvl) {
    string str = caster->query("deity");

    if (str) str = ", a gift from "+capitalize(str);
    else str = "";

    set("long", wrap("A magical adamantite mace"+str+"."));
    set("level", lvl);
    set("caster", caster->query("name"));
    set("enchantment", 3);
    set("schools", ({ "evocation" }) );
    write("Make sure you wield the adamantium mace if you want to use it!\n");
    call_out("remove", lvl * 80 );
    return 1;
}

/* EOF */
