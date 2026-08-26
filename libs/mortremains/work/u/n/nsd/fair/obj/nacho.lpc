/*
** File: nacho.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", wrap(
	"Just a nacho chip. 'Dip' it on the cheese, and 'munch' on it.\n"));
    set("short", "a nacho chip");
    set("id", ({ "nacho", "chip", "nacho chip" }) );
    set("mass", 0);
}

void init() {
    add_action("dip", "dip");
    add_action("munch", "munch");
}
int dip( string str ) {
    object bowl = present("bowl",TP);
    if(!bowl) {
	write("You can't dip your nacho without the bowl.\n");
	return 1;
    }
    write("You dip your nacho in that melted juicy cheddar...\n");
    say(TPN+" dips "+POSS+" nacho in the melted cheddar....\n");
    return 1;
}
int munch( string str ) {
    write(wrap(
	"You munch on your nacho most noisily. It's very crunchy!\n"));
    say(TPN+" munches on "+POSS+" nachos most noisily...\n");
    remove();
    return 1;
}
/* End of file */
