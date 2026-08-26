/*
** File: nsd.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", @EndText
An action figure that ressembles The wizard Nsd.
Has a red spandex dress and dark brown lose curls.
It's got black eyes that stare at you deeply
and empty. It's really sexy. It has a red button
on the back that you can 'press' ;-)
EndText);
    set("short", "Lady Nsd's action figure");
    set("id", ({ "figure", "nsd", "Nsd", "lady" }) );
    set("mass", 0);
}

void init() {
    add_action("press_button", "press");
}
int press_button (string str) {
    if (!str) return 0;
    say(TPN+" presses the button...\n");
    say("Lady Nsd IS the queen of EVIL!!!!\n");
    write("You press the button...\n");
    write("Lady Nsd IS the queen of EVIL!!!!\n");
    return 1;
}
/* End of file */
