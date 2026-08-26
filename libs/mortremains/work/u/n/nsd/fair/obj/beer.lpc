/*
** File: beer.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", wrap(
	"Bud-wise..er, the favorite beer of all the perverts\n"+
	"and weirdos!... drink it!\n"));
    set("short", "Bud-wise..er beer");
    set("id", ({ "beer", "bud", "Bud-wise..er beer" }) );
    set("value", 60);
    set("mass", 0);
}

void init() {
    add_action("drink", "drink");
}
int drink( string str ) {
    write("You drink your beer like an alcoholic expert!\n"+
      "You burp... How rude!\n");
    say(TPN+" drinks "+POSS+" beer like an alcoholic expert!\n"+
      TPN+" burps... How rude!\n");
    TP->add("drunk", 1);
    remove();
    return 1;
}
/* End of file */
