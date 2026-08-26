/*
** File: strawberry.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", wrap(
	"A fresh red strawberry. You drool at it's appearance.\n"+
	"You want to eat it.\n"));
    set("short", "a strawberry");
    set("id", ({ "strawberry", "berry" }) );
    set("mass", 0);
}

void init() {
    add_action("eat", "eat");
}
int eat( string str ) {
    write(wrap(
	"You eat that juicy strawberry in a sinful way...\n"+
	"You have lustful thoughts while eating it.\n"));
    say(wrap(TPN+" eats "+possessive(TP->query("gender"))+""+
	" strawberry in a sinful way...\n"));
    remove();
    return 1;
}
/* End of file */
