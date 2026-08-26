/*
** File: shya.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", @EndText
An action figure that ressembles The wizard Shya.
It's got long blonde hair and brown eyes that 
sparkle. It has a red button on the back that
you can 'press' ;-)
EndText);
    set("short", "Shya's action figure");
    set("id", ({ "figure", "shya", "Shya" }) );
    set("mass", 0);
}

void init() {
    add_action("press_button", "press");
}
int press_button (string str) {
    if (!str) return 0;
    say(TPN+" presses the button...\n");
    say("Shya action figure licks you erotically...\n");
    write("You press the button...\n");
    write("Shya action figure licks you erotically...\n");
    return 1;
}
/* End of file */
