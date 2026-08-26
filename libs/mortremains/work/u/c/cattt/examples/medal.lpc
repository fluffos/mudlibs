// Cyanide, 27 May 99
// Cattt June 99

inherit ARMOR;

void create() {
    seteuid(getuid());
    set("id", ({ "medal" }) );
    set("extra_look", iwrap("$N is wearing a medal with "+
	"the name \"My Hero\" engraved in it from Cattt.") );
    set_armor_type("clothing");
    set("short", "@@query_short");
    set("long", wrap("A fashionable medal, with the "+
	"name \"My Hero\" engraved in it.") );
}

string query_short() {
    if (!query("equipped")) return "a medal";
}
