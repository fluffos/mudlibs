// An experiment in cybernetics.
// Cyanide, 22 Jun 99

inherit CYBERWARE;

void create() {
    ::create();
    seteuid(getuid());

    set("id", ({ "claws", "cyberclaws" }) );
    set("essence", 10);
    set("value", 7500);
}

int activate ( object owner ) {
    set("extra_look", "$N has a set of sharp cyberclaws.\n");
    owner->set("damage", ({ 2, 10 }) );
    owner->set("damage_type", "slashing");
    owner->set("weapon_name", "cyberclaws");
    return 1;
}

int deactivate ( object owner ) {
    delete("extra_look");
    owner->delete("damage");
    owner->delete("damage_type");
    owner->delete("weapon_name");
    return 1;
}

// EOF //
