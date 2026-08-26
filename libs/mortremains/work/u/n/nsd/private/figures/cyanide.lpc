/*
** File: cyanide.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", @EndText
An action figure that ressembles The admin Cyanide.
It's got a black t-shirt that reads "everybody loves Cy",
and is irressistably handsome to female wizards.
It has a red button on the back that you can 'press' ;-)
EndText);
    set("short", "Cyanide's action figure");
    set("id", ({ "figure", "cyanide", "Cyanide" }) );
    set("mass", 0);
}

void init() {
    add_action("press_button", "press");
}
int press_button (string str) {
    if (!str) return 0;
    say(TPN+" presses the button...\n");
    say("Cyanide action figure says: I can be nasty if you like ;)\n");
    write("You press the button...\n");
    write("Cyanide action figure says: I can be nasty if you like ;)\n");
    return 1;
}
/* End of file */
