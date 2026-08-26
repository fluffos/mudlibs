// A hole.

inherit CONTAINER;

void create() {
    ::create();
    set("short", "@@query_short");
    set_open_long("A hole in the ground somebody seems to have dug.\n");
    set("id", ({ "hole", "small hole", "Cy_hole" }) );
    set("capacity", 40);
    set("prevent_get", 1);
    set_possible_to_close(0);
}

string query_short() {
    string str = "a small hole";

    if (query("invisible")) str += " (invisible)";
    return str;
}
// EOF 
