/*
** File: glass.c
** Author: Lady Nsd
*/

inherit OBJECT ;

void create() {
    set("author", "nsd");
    set ("short", "a crystal glass");
    set ("long", wrap(
	"A clear crystal glass with a light shade of green.\n"+
	"It has square shapes carved in its surface. It belongs\n"+
	"to the rare collection of noble exclusive items. \n"+
	"It's perfect for serving drinks in it.\n"));
    set ("id", ({ "glass", "crystal glass" }) ) ;
    set("mass", 0);
}
void init() {
    add_action ("drink_from_glass", "drink");
    add_action ("sip_drink", "sip");
}
int drink_from_glass (string str) {
    say(TPN+" drinks from "+POSS+" glass. "+TPN+" looks a little tipsy *oO*\n");
    write("You drink from your glass.\n");
    write("You feel a little tipsy *oO*\n");
    TP->add("drunk", 3);
    return 1;
}
int sip_drink (string str) {
    if (!str || str!="drink") {
	write("What do you want to sip?\n");
	return 1;
    }
    say(TPN+" sips "+POSS+" drink and loves the taste of it.\n");
    write("You sip your drink and feel the pleasant taste of it.\n");
    TP->add("drunk", 1);
    return 1;
}
/* End of file */
