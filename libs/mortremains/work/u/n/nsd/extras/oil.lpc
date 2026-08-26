/*
** File: oil.c
** Author: Lady Nsd
*/

#include <mudlib.h>
inherit OBJECT ;

void create() {
    set("author", "nsd");
    set ("short", "a bottle of massage oil");
    set("long", @EndLong
A bottle of oil. Good to 'massage someone. Leaves the skin
smooth and moisturized. It has a label in the back.
EndLong
    );
    set("id", ({ "oil", "massage oil", "bottle", "bottle of oil" }) );
    set("mass", 0);
}
void init() {
    add_action("massage", "massage") ;
    add_action("read_label", "read");
    add_action("squeeze_bottle", "squeeze");
}

int massage (string name)  {
    object target ;
    target = present(name,environment(this_player())) ;
    if (!target) {
	notify_fail ("I don't see that here.\n") ;
	return 0 ;
    }
    if (!living(target)) {
	notify_fail ("Now that's funny.. You can't massage that.\n");
	return 0 ;
    }
    write(wrap(
	"You massage the body of "+capitalize(name)+" with the oil,\n"+
	"til "+possessive(target->query("gender"))+" skin feels"+
	" soft and smooth.\n"+
	capitalize(name)+" starts to relax...\n"));

    tell_object(target, wrap(
	TPN+" massages your body with the oil, til your skin feels\n"+
	"soft and smooth. You start to relax...\n"));

    say(
      TPN+" massages "+capitalize(name)+
      " in a sensual way with oil...\n", ({ target }) );
    return 1 ;
}
int squeeze_bottle(string str) {
    say(TPN+" squeezes a generous amount of oil in "+POSS+" hand.\n");
    write(wrap(
	"You squeeze the bottle of oil in your hand. You got\n"+
	"a generous amount of oil.\n"));
    return 1;
}
int read_label(string str) {
    say(TPN+" reads the label.\n");
    write(@EndText
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
|                                      |
|            INSTRUCTIONS              |
|                                      |
|     1. 'Squeeze' the 'bottle' in     |
|         the palm of your hand.       |
|                                      |
|     2. 'Massage' your partner.       |
|                                      |
|                                      |
-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=
EndText);
    return 1;
}
/* EOF */
