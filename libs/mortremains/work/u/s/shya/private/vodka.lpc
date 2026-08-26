//Created by Shya July 7, 2000.  Modified from wine.c by NSD//

inherit OBJECT ;
void create() {
    set("author", "shya");
    set ("short", "Vodka");
    set ("long", wrap(
	"A bottle of vodka.\n"+
	"The bottle looks like it came from cold side of Russia.\n"+
      "The bottle has a label on the back.\n"));
    set ("id", ({ "bottle", "bottle of vodka", "vodka" }) ) ;
}
void init() {
    add_action ("serve_vodka", "serve");
    add_action ("open_vodka", "open");
    add_action ("read_label", "read");
}
int serve_vodka (string str) {
    if (!str || str!="vodka") {
	write("What do you wish to serve?\n");
	return 0;
    }
    say(TPN+" fills a goblet with vodka.\n");
    write(wrap(
	"You fill a goblet with vodka . All you have\n"+
	"to do now is drink it.\n"));
    return 1;
}



int open_vodka (string str) {
    if (str != "vodka") {
	write("Open what?\n");
	return 0;
    }
    say(
      TPN+" opens the bottle of russian vodka.\n");
    write(wrap(
	"You open the bottle of vodka.\n"));
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
|     1.'open' the 'vodka' to open the bottle.  |
|                                               |
|     2.'Serve' the 'vodka' in the goblets.     |
|                                               |
|     3. You may want to 'sip' your 'drink'     |
|        in order to taste it.                  |
|                                               |
|     4. Then you can 'drink' 'from' the        |
|        'goblet'.                              |
|                                               |
|   "Shya's personal best imported vodka."       |
|                                               |
-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-
EndText);
    return 1;
}
