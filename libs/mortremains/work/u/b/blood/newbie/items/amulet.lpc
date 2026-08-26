inherit ARMOR;

int last_used, charges;

void create() {
    last_used = 0;
    charges = 7;

    seteuid(getuid());
    set("short", "an amulet");
    set("long", "@@query_long");
    set("id", ({ "amulet" }) );
    set_armor_type("amulet");
}

void init() {
    add_action("empower", "empower");
}

string query_long() {
    string str = "This amulet was formed from the shadered blades
    of steel which belonged to  the broken spirits of evil warriors. "+
    "a single magical stone rests in the center, ";

    if (time() - last_used < 300)  
        str += "which is a strangely dull green in color.";
    else
	str += "which is glowing brightly.";

    return wrap(str);
}

int empower() {
    if (time() - last_used < 300) {
	write("Nothing happens.\n");
	return 1;
    }

    TP->modify_skill(
      "Long Blades", 1, 300
    );
    write("You suddenly feel more skilled!\n");
    last_used = time();

    return 1;
}

/* EOF */
