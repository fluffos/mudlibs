/*
** File: valkyrie.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", @EndText
An action figure that ressembles The wizard Valkyrie.
Has the pointy elf ears, and a cute face. It has a red
button on the back that you can 'press' ;-)
EndText);
    set("short", "Valkyrie's action figure");
    set("id", ({ "figure", "valkyrie", "Valkyrie" }) );
    set("mass", 0);
}

void init() {
    add_action("press_button", "press");
}
int press_button (string str) {
    if (!str) return 0;
    say(TPN+" presses the button...\n");
    say("Valkyrie action figure says: I want smoochies too :( \n");
    write("You press the button...\n");
    write("Valkyrie action figure says: I want smoochies too :( \n");
    return 1;
}
/* End of file */
