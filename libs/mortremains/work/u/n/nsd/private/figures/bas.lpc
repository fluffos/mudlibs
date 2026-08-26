/*
File: bas.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", @EndText
An action figure that ressembles The wizard Sebastian.
It's a half-orc with an ever-horney face, and has a
red button on the back that you can 'press' ;-)
EndText);
    set("short", "Sebastian's action figure");
    set("id", ({ "figure", "sebastian", "bas", "Sebastian" }) );
    set("mass", 0);
}

void init() {
    add_action("press_button", "press");
}
int press_button (string str) {
    if (!str) return 0;
    say(TPN+" presses the button...\n");
    say("Sebastian action figure says: I'm so perverted, it's scary :-P\n");
    write("You press the button...\n");
    write("Sebastian action figure says: I'm so perverted, it's scary :-P\n");
    return 1;
}
/* End of file */
