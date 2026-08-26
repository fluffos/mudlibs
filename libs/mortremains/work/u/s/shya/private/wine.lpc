inherit OBJECT ;
void create() {
    set("author", "shya");
    set ("short", "a bottle of wine");
    set ("long", wrap(
	"A bottle of sparkling white wine.\n"+
	"The bottle alone is crafted out of the finest crystal.\n"));
    set ("id", ({ "bottle", "bottle of wine", "wine", "white wine" }));
}
void init() {
    add_action ("serve_wine", "serve");
    add_action ("open_wine", "open");
}
int serve_wine (string str) {
    if (!str || str!="wine") {
	write("What do you wish to serve?\n");
	return 1;
    }
    say(TPN+" fills a glass with sparkling white wine.\n");
    write(wrap(
	"You fill a glass with the white wine. All you have\n"+
	"to do now is drink it.\n"));
    return 1;
}
int open_wine (string str) {
    if (!str || str!="wine") {
	write("Open what?\n");
	return 0;
    }
    say(
      TPN+" pops the cork to open the bottle, and the wine "+
      "jumps out a little.\n");
    write(wrap(
	"You open the bottle. Some wine spills\n"+
	"from the pressure of the removed cork.\n"));
    return 1;
}


