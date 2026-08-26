
inherit WEAPON;

void create() {
    seteuid(getuid());
    set("short", "the Ruby Rod of Asmodeus");
    set("long", "The much feared scepter of the Lord of the Nine Hells.\n");
    set("id", ({ "rod", "scepter", "ruby rod" }) );
    set_weapon_type("club");
    set("dest_at_sell", 1);
    set_bonus(6,0,0);
    set_material_type("metal/gold");
    set("name", "Ruby Rod of Asmodeus");
    set_verbs( ({ "swing at" }) );
    set("value", 50000);
}

int wield_func() {
    TP->add("magic_resist", 1000);
    return 1;
}

int unwield() {
    TP->add("magic_resist", -1000);
    return ::unwield();
}

