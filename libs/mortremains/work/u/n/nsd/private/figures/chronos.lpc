/*
** File: chronos.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", @EndText
An action figure that ressembles The admin Chronos.
It's wearing a NAVY suit, and has hard-rock-cafe
pins of the whole world. It has a red button on
the back that you can 'press' ;-)
EndText);
    set("short", "Chronos's action figure");
    set("id", ({ "figure", "chronos", "Chronos" }) );
    set("mass", 0);
}

void init() {
    add_action("press_button", "press");
}
int press_button (string str) {
    if (!str) return 0;
    say(TPN+" presses the button...\n");
    say("Chronos action figure says: Who's da man?\n");
    write("You press the button...\n");
    write("Chronos action figure says: Who's da man?\n");
    return 1;
}
/* End of file */
