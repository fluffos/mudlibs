/*
** File: nemar.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", @EndText
An action figure that ressembles The wizard Nemar.
Has the pointy elf ears, long reddish hair, and
a black T-shirt with white letters that read
"I'm da man"  It has a red button on the back
that you can 'press' ;-)
EndText);
    set("short", "Nemar's action figure");
    set("id", ({ "figure", "nemar", "Nemar" }) );
    set("mass", 0);
}

void init() {
    add_action("press_button", "press");
}
int press_button (string str) {
    if (!str) return 0;
    say(TPN+" presses the button...\n");
    say("Nemar action figure says: Don't let the long hair fool you!\n");
    write("You press the button...\n");
    write("Nemar action figure says: Don't let the long hair fool you!\n");
    return 1;
}
/* End of file */
