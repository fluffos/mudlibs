/*
** File:enzyme.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", @EndText
An action figure that ressembles The wizard Enzyme.
It's got the badge of law, and is a pain in the ass
at times, but it's generally cool. It has a red button
on the back that you can 'press' ;-)
EndText);
    set("short", "Enzyme's action figure");
    set("id", ({ "figure", "enzyme", "Enzyme" }) );
    set("mass", 0);
}

void init() {
    add_action("press_button", "press");
}
int press_button (string str) {
    if (!str) return 0;
    say(TPN+" presses the button...\n");
    say("Enzyme action figure says: Crash the mud, and I'll crash you!\n");
    write("You press the button...\n");
    write("Enzyme action figure says: Crash the mud, and I'll crash you!\n");
    return 1;
}
/* End of file */
