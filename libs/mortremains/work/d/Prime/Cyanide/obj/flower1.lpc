#include <mudlib.h>
inherit OBJECT;

void create () {
    set ("id", ({ "flower", "rose" }) );
    set ("short", "a perfect flower picked from Cyanide's garden");
    set ("long", @EndText
An unusual flower, which you find both enchantingly beautiful
and strikingly alien. It is blood red in color, and seems to be
something like a cross between a lily and a rose.
EndText
    );
}

void init() {
    add_action("eat", "eat");
    add_action ("snort", "smell");
    add_action ("snort", "sniff");
}

int snort(string str) {

    if (str!="flower") {
	notify_fail("Smell what?\n");
	return 0;
    }
    write ("You smell the strange, foreign flower...\n"+
      "Simply extraordinary, unlike anything you've ever known.\n");
    say (this_player()->query("cap_name")+" takes a sniff of "+
      possessive(this_player()->query("gender"))+" flower.\n");
    return 1;
}

int eat(string str) {
    if (str!="flower") {
	return 0;
    }

    write("You stuff the whole thing into your mouth!\n");
    say(TPN+" stuffs a flower into "+possessive(TP->query("gender"))+
      " mouth!\n");
    remove();
    return 1;
}
