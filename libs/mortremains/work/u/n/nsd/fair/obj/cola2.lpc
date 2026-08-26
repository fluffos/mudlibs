/*
** File: cola2.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", wrap(
	"Brite Cola, the clear one. Come on, obey your thirst\n"+
	"and drink it! ;-) \n"));
    set("short", "Brite Cola");
    set("id", ({ "cola", "brite cola" }) );
    set("value", 60);
    set("mass", 0);
}

void init() {
    add_action("drink", "drink");
}
int drink( string str ) {
    write("You finish your Brite Cola of one sip.\n"+
      "You might be thirsty!\n");
    say(TPN+" finishes "+POSS+" cola of one sip!\n");
    remove();
    return 1;
}
/* End of file */
