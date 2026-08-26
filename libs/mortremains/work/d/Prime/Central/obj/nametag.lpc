// Cyanide, 27 May 99

inherit ARMOR;

void create() {
    seteuid(getuid());
    set("id", ({ "tag", "name tag" }) );
    set("extra_look", iwrap("$N is wearing a name tag with "+
	"the name \"Jeff\" engraved in it.") );
    set_armor_type("clothing");
    set("short", "@@query_short");
    set("long", wrap("A simple green plastic name tag, with the "+
	"name \"Jeff\" engraved in it.") );
}


string query_short() {
    if (!query("equipped")) return "a name tag";
}
