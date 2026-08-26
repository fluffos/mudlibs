/*
** File: tyran.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", @EndText
An action figure that ressembles The wizard Tyran.
This action figure has a little yellow sign on his
right hand. It has a red button on the back that
you can 'press' ;-)
EndText);
    set("short", "Tyran's action figure");
    set("id", ({ "figure", "tyran", "Tyran" }) );
    set("mass", 0);
}

void init() {
    add_action("press_button", "press");
}
int press_button (string str) {
    if (!str) return 0;
    say(TPN+" presses the button...\n");
    say(" Tyran action figure says: That's sign worthy...!!\n");
    write("You press the button...\n");
    write(" Tyran action figure says: That's sign worthy...!!\n");
    return 1;
}
/* End of file */
