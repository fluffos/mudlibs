/*
** File: hotdog.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", wrap(
	"A 6-inches long  hot dog. It has sawerkraut, sliced pickles, \n"+
	"mustard, katsup, and onions!! Eat it, you'll love it.\n"));
    set("short", "6 inches hot dog");
    set("id", ({ "hotdog", "hot dog", "6 inches hot dog" }) );
    set("value", 50);
    set("mass", 0);
}

void init() {
    add_action("eat", "eat");
}
int eat( string str ) {
    write(wrap(
	"You bite on your hot dog, and blush!\n"));
    say(TPN+" bites "+POSS+" hot dog and blushes.\n");
    remove();
    return 1;
}
/* End of file */
