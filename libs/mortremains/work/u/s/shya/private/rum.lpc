//Created by Shya July 7, 2000.  Modified from wine.c by NSD//

inherit OBJECT ;
void create() {
    set("author", "shya");
    set ("short", "Rum");
    set ("long", wrap(
	"A bottle of rum.\n"+
	"The bottle looks like it came from the caribbiean.\n"+
      "The bottle has a label on the back.\n"));
    set ("id", ({ "bottle", "bottle of rum", "rum" }) ) ;
}
void init() {
    add_action ("serve_rum", "serve");
    add_action ("open_rum", "open");
    add_action ("read_label", "read");
}
int serve_rum (string str) {
    if (!str || str!="rum") {
	write("What do you wish to serve?\n");
	return 0;
    }
    say(TPN+" fills a goblet with rum.\n");
    write(wrap(
	"You fill a goblet with rum . All you have\n"+
	"to do now is drink it.\n"));
    return 1;
}
int open_rum (string str) {
    if (!str || str!="rum") {
	write("Open what?\n");
	return 0;
    }
    say(
      TPN+" opens the bottle, and the rum "+
      "jumps out a little.\n");
    write(wrap(
	"You open the bottle of rum.\n"));
    return 1;
}
int read_label (string str) {
    if (!str || str!="label") {
	write("What do you want to read?\n");
	return 0;
    }
    say(TPN+" reads the label on the bottle.\n");
    write(@EndText
-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-
|                                               |
|                 INSTRUCTIONS:                 |
|                                               |
|    To enjoy this delicious drink, you may     |
|    need goblets, and a friend.                |
|                                               |
|     1.'open' the 'rum' to open the bottle.    |
|                                               |
|     2.'Serve' the 'rum' in the glasses.       |
|                                               |
|     3. You may want to 'sip' your 'drink'     |
|        in order to taste it.                  |
|                                               |
|     4. Then you can 'drink' 'from' the        |
|        'goblet'.                              |
|                                               |
|   "Shya's personal best bottle of rum."       |
|                                               |
-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-
EndText);
    return 1;
}
