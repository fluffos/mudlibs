/*
** File: frappe.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", wrap(
	"A glass of Tropical frappe, which is no other thing than\n"+
	"a shake of tropical fruits. Good to drink it.\n"));
    set("short", "A glass of Tropical Frappe");
    set("id", ({ "frappe", "glass", "tropical frappe" }) );
    set("value", 60);
    set("mass", 0);
}

void init() {
    add_action("drink", "drink");
}
int drink( string str ) {
    write(wrap(
	"As you drink your tropical frappe, you feel a carnival\n"+
	"of tropical fruits that suits your tastes... MMMMMM!\n"));
    say(TPN+" drinks "+POSS+" frappe, and feels joyful... :-q\n");
    remove();
    return 1;
}
/* End of file */
