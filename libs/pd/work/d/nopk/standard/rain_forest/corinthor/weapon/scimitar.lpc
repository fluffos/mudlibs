inherit WEAPON;

void create() {
::create();
set_name("scimitar");
set_short("A steel scimitar");
set_id(({"scimitar", "steel scimitar"}));
set_long("Made of steel, the scimitar has a curved blade with a good cutting edge. This one has the markings of an elven smith.");
set_wc(3);
set_type("blade");
set_curr_value("gold", 20);
set_mass(10);
}

int query_auto_load() {
    if(this_player()->query_level() > 4) return 1;
    return 0;
}
