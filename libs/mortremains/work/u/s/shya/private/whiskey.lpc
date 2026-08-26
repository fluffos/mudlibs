//Created by Shya July 7, 2000.  Modified from wine.c by NSD//

inherit OBJECT ;
void create() {
    set("author", "shya");
    set ("short", "Irish Whiskey");
    set ("long", wrap(
	"A bottle of whiskey.\n"+
	"The bottle looks like it came from Ireland.\n"+
      "The bottle has a label on the back.\n"));
    set ("id", ({ "bottle", "bottle of whiskey", "whiskey", "irish whiskey"}) ) ;
}
void init() {
    add_action ("serve_whiskey", "serve");
    add_action ("open_whiskey", "open");
    add_action ("read_label", "read");
}
int serve_whiskey (string str) {
    if (!str || str!="whiskey") {
	write("What do you wish to serve?\n");
	return 0;
    }
    say(TPN+" fills a goblet with Irish whiskey.\n");
    write(wrap(
	"You fill a goblet with whiskey . All you have\n"+
	"to do now is drink it.\n"));
    return 0;
}
int open_whiskey (string str) {
    if (!str || str!="whiskey") {
	write("Open what?\n");
	return 0;
    }
    say(
      TPN+" opens the bottle of Irish whiskey.\n");
    write(wrap(
	"You open the bottle of whiskey.\n"));
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
|     1.'open' the 'whiskey' to open the bottle.|
|                                               |
|     2.'Serve' the 'whiskey' in the goblets    |
|                                               |
|     3. You may want to 'sip' your 'drink'     |
|        in order to taste it.                  |
|                                               |
|     4. Then you can 'drink' 'from' the        |
|        'goblet'.                              |
|                                               |
|"Shya's personal best bottle of Irish whiskey."|
|                                               |
-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-=+=-
EndText);
    return 1;
}
