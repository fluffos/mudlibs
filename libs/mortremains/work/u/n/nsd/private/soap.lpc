/*
** File: soap.c
** Author: Lady Nsd
*/

inherit OBJECT;

void create() {
    set("author", "nsd");
    set("long", wrap(
	"Botanical Essences Soap. Leaves the skin soft and\n"+
	"smelling good. 'Wash' your partner with it, or\n"+
	"yourself by typing 'washme'.\n"));
    set("short", "a soap bar");
    set("id", ({ "soap", "bar", "soap bar" }) );
    set("mass", 0);
}

void init() {
    add_action("wash", "wash");
    add_action("washme", "washme");
}
int wash(string str) {
    object ob;
    if (!str) return 0;
    ob = present(str, environment(TP));
    if(!ob) {
	write("Who you want to wash?\n");
	return 1;
    }
    if (!living(ob) ) {
	notify_fail("That player is not in the room.\n");
	return 0;
    }
    write(wrap(
	"You wash "+ob->query("cap_name")+"'s body with the "+
	"Botanical Essences\n"+
	"soap bar. "+ob->query("cap_name")+" smells terrific now.\n"));
    say(
      TPN+" washes "+ob->query("cap_name")+"'s body with the"+
      " soap bar.\n", ({ ob }) );
    tell_object(ob, wrap(
	TPN+" washes your body with the Botanical Essences soap bar.\n"+
	"You smell terrific now.\n"));
    return 1;
}
int washme(string str) {
    write(wrap(
	"You wash your body with the Botanical Essences soap bar.\n"+
	"You smell terrific, and your skin feels soft.\n"));
    say(
      TPN+" washes "+POSS+" body with the Botanical Essences soap bar.\n"
    );
    set("extra_look", (capitalize(subjective(TP->query("gender"))))+
      " smells terrific.\n");
    return 1;
}
/* End of file */
