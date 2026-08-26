/*
** File: cola1.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", wrap(
	"The famous Coco Cola that many americans like!\n"+
	"Drink your cola and stop jerking around!\n"));
    set("short", "Coco Cola");
    set("id", ({ "cola", "coco cola" }) );
    set("value", 60);
    set("mass", 0);
}

void init() {
    add_action("drink", "drink");
}
int drink( string str ) {
    write("You finish your Coco Cola of one sip.\n"+
      "You might be thirsty!\n");
    say(TPN+" finishes "+POSS+" cola of one sip!\n");
    remove();
    return 1;
}
/* End of file */
