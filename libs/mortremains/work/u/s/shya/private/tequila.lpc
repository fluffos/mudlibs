//Created by Shya July 7, 2000.  Modified from wine.c by NSD//

inherit OBJECT ;
void create() {
    set("author", "shya");
    set ("short", "Tequila");
    set ("long", wrap(
	"A bottle of tequila.\n"+
	"The bottle looks like it came from Mexico.\n"+
      "The bottle has a label on the back.\n"));
    set ("id", ({ "bottle", "bottle of tequila", "tequila"}) ) ;
}
void init() {
    add_action ("serve_tequila", "serve");
    add_action ("open_tequila", "open");
    add_action ("read_label", "read");
}
int serve_tequila (string str) {
    if (!str || str!="tequila") {
	write("What do you wish to serve?\n");
	return 0;
    }
    say(TPN+" fills a goblet with tequila. Beware of the worm.\n");
    write(wrap(
	"You fill a goblet with tequila . All you have\n"+
	"to do now is drink it.\n"));
    return 1;
}
int open_tequila (string str) {
    if (!str || str!="tequila") {
	write("Open what?\n");
	return 0;
    }
    say(
      TPN+" opens the bottle of Irish whiskey. Watch out for the worm.\n");
    write(wrap(
	"You open the bottle of tequila.\n"));
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
|     1.'open' the 'tequila' to open the bottle.|
|                                               |
|     2.'Serve' the 'tequila' in the goblets    |
|                                               |
|     3. You may want to 'sip' your 'drink'     |
|        in order to taste it.                  |
|                                               |
|     4. Then you can 'drink' 'from' the        |
|        'goblet'.                              |
|                                               |
|"Shya's personal best bottle of Tequila."      |
|                                               |
-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-
EndText);
    return 1;
}
