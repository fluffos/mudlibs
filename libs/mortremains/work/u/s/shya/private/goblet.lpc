//Created by Shya July 7, 2000. Modified from glass.c by NSD//

inherit OBJECT ;

void create() {
    set("author", "shya");
    set ("short", "a crystal goblet");
    set ("long", wrap(
	"A crystal goblet with a hint of cobalt blue.\n"+
	"It's perfect for serving drinks in it.\n"));
    set ("id", ({ "goblet", "crystal goblet" }) ) ;
}
void init() {
    add_action ("drink_from_goblet", "drink");
    add_action ("sip_drink", "sip");
}
int drink_from_goblet (string str) {
    say(TPN+" drinks from "+POSS+" goblet. "+TPN+" looks a little tipsy *oO*\n");
    write("You drink from your goblet.\n");
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