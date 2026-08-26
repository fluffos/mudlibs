/*
** File: herself.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", @EndText
An action figure that ressembles The wizard Herself.
Has the pointy elf ears, long reddish hair, and a
blue dress with glitters. It has a little crown of
red roses and a red button on the back that you can
'press' ;-)
EndText);
    set("short", "Herself's action figure");
    set("id", ({ "figure", "herself", "Herself" }) );
    set("mass", 0);
}

void init() {
    add_action("press_button", "press");
}
int press_button (string str) {
    if (!str) return 0;
    say(TPN+" presses the button...\n");
    say("Herself action figure says: I'm sweet and innocent.\n"+
      "believe me, please!!!\n");
    write("You press the button...\n");
    write("Herself action figure says: I'm sweet and innocent.\n"+
      "believe me, please!!!\n");
    return 1;
}
/* End of file */
