/*
** File: cotton.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", wrap(
	"A fluffy blue cotton candy. It's really big.\n"+
	"Like a piece of heaven to any kid. Just eat it.\n"));
    set("short", "a sky-blue cotton candy");
    set("id", ({ "candy", "cotton", "cotton candy" }) );
    set("value", 50);
    set("mass", 0);
}

void init() {
    add_action("eat", "eat");
}
int eat( string str ) {
    write(wrap(
	"You start to eat your cotton candy that seems to never end.\n"+
	"Finally you finish it :(\n"));
    say(
      TPN+" eats "+POSS+" cotton candy without offering you ;-P\n");
    remove();
    return 1;
}
/* End of file */
