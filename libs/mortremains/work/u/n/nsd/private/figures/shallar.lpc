/*
** File: shallar.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", @EndText
An action figure that ressembles The wizard Shallar.
Is wearing the purple robes of a sinner, and has a
red button on the back that you can 'press' ;-)
EndText);
    set("short", "Shallar's action figure");
    set("id", ({ "figure", "shallar", "Shallar" }) );
    set("mass", 0);
}

void init() {
    add_action("press_button", "press");
}
int press_button (string str) {
    if (!str) return 0;
    say(TPN+" presses the button...\n");
    say("Shallar action figure says: It's a twelve-step program.\n"+
      "I keep on forgetting the first step... *wink*\n");
    write("You press the button...\n");
    write("Shallar action figure says: It's a twelve-step program.\n"+
      "I keep on forgetting the first step... *wink*\n");
    return 1;
}
/* End of file */
