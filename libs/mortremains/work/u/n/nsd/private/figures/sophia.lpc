/*
** File: sophia.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", @EndText
An action figure that ressembles The wizard Sophia.
It's got the pointy elf ears, and a bunch of cookies
to toss someone. It has a red button on the back that
you can 'press' ;-)
EndText);
    set("short", "Sophia's action figure");
    set("id", ({ "figure", "sophia", "Sophia" }) );
    set("mass", 0);
}

void init() {
    add_action("press_button", "press");
}
int press_button (string str) {
    if (!str) return 0;
    say(TPN+" presses the button...\n");
    say("Sophia action figure tosses you a cookie :)\n");
    write("You press the button...\n");
    write("Sophia action figure tosses you a cookie :)\n");
    return 1;
}
/* End of file */
