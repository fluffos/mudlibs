/*
** File: mouthwash.c
** Author: Lady Nsd
** Special thanks: To the only NK admin that really likes me; NM,
**            for teaching me the "extra_look" string.
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", wrap(
	"This is the official Breath Fixer mouthwash. 'Sip' it\n"+
	"to get fresh breath.\n"));
    set("short", "a bottle of mouthwash");
    set("id", ({ "mouthwash", "bottle", "bottle of mouthwash" }) );
    set("mass", 0);
}

void init() {
    add_action("gargle", "gargle");
    add_action("sip", "sip");
    add_action("spit", "spit");
}
int gargle(string str) {
    write(wrap(
	"You do gargles with the mouthwash. You're ready\n"+
	"to 'spit'.\n"));
    say(
      TPN+" makes gargles with the mouthwash. *oOoOoOo*\n");
    return 1;
}
int sip(string str) {
    write(wrap(
	"You sip a small ammount of mouthwash. Now 'gargle'\n"+
	"with it.\n"));
    say(
      TPN+" sips a little of mouthwash.\n");
    return 1;
}
int spit(string str) {
    write(wrap(
	"You spit the mouthwash in the wash stand.\n"+
	"You have nice breath now.\n"));
    say(wrap(
	TPN+" spits the mouthwash in the wash stand.\n"+
	POSS+" breath smells nice now.\n"));
    set("extra_look", (capitalize(subjective(TP->query("gender"))))+
      " has nice fresh breath.\n");
    return 1;
}
/* End of file */
