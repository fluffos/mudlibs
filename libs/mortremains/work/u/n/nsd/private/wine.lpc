/*
** File: wine.c
** Author: Lady Nsd
*/

inherit OBJECT ;
void create() {
    set("author", "nsd");
    set ("short", "a bottle of wine");
    set ("long", wrap(
	"A bottle of sparkling wine, which label reads 'Segura Viudas'.\n"+
	"Its ornaments are surely royal and medieval. The bottle alone\n"+
	"is beautifully crafted. Invites to drink from it...\n"+
	"The bottle has a label in the back.\n"));
    set ("id", ({ "bottle", "bottle of wine", "wine", "sparkling wine" }) ) ;
    set("mass", 0);
}
void init() {
    add_action ("serve_wine", "serve");
    add_action ("pop_cork", "pop");
    add_action ("read_label", "read");
}
int serve_wine (string str) {
    if (!str || str!="wine") {
	write("What do you wish to serve?\n");
	return 1;
    }
    say(TPN+" fills a glass with wine.\n");
    write(wrap(
	"You fill a glass with the sparkling wine. All you have\n"+
	"to do now is drink it.\n"));
    return 1;
}
int pop_cork (string str) {
    if (!str || str!="cork") {
	write("Pop what?\n");
	return 1;
    }
    say(
      TPN+" pops the cork to open the bottle, and the wine "+
      "spills a little.\n");
    write(wrap(
	"You pop the cork to open the bottle. Some wine spills\n"+
	"from the pressure of the removed seal.\n"));
    return 1;
}
int read_label (string str) {
    if (!str || str!="label") {
	write("What do you want to read?\n");
	return 1;
    }
    say(TPN+" reads the label on the bottle.\n");
    write(@EndText
-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-
|                                               |
|                 INSTRUCTIONS:                 |
|                                               |
|    To enjoy this delicious drink, you may     |
|    need two crystal glasses, and a partner.   |
|                                               |
|     1.'Pop' the 'cork' to open the bottle.    |
|                                               |
|     2.'Serve' the 'wine' in the glasses.      |
|                                               |
|     3. You may want to 'sip' your 'drink'     |
|        in order to taste it.                  |
|                                               |
|     4. Then you can 'drink' 'from' the        |
|        'glass'.                               |
|                                               |
|    "Segura Viudas, a pleasant experience"     |
|                                               |
-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-
EndText);
    return 1;
}
/* End of file */
