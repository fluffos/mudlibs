/*
** File: toothbrush.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", wrap(
	"An auto-loadable toothbrush to 'brush' your teeth.\n"+
	"'Autoload' it to make the paste appear.\n"));
    set("short", "a magic toothbrush");
    set("id", ({ "toothbrush" }) );
    set("mass", 0);
}

void init() {
    add_action("autoload", "autoload");
    add_action("brush", "brush");
    add_action("spit", "spit");
}
int autoload(string str) {
    write(
      "Your toothbrush magically auto-loads with Breath Fixer paste.\n");
    say(
      TPN+"'s toothbrush magically auto-loads with paste.\n");
    return 1;
}
int brush(string str) {
    write(
      "You brush your teeth thoroughly. You can 'spit' now.\n");
    say(
      TPN+" brushes "+POSS+" teeth.\n");
    return 1;
}
int spit(string str) {
    write(wrap(
	"You spit the toothpaste in the wash stand.\n"+
	"You may want to use some mouthwash.\n"));
    say(
      TPN+" spits the toothpaste in the wash stand.\n");
    return 1;
}
/* End of file */
