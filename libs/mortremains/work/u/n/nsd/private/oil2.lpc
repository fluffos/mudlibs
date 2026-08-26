/*
** File: oil2.c
** Author: Lady Nsd
*/

#include <mudlib.h>
string body_part(int x) ;
object target;

inherit OBJECT;

void create() {
    seteuid(getuid());
    set("author", "nsd");
    set ("short", "a bottle of massage oil");
    set("long", @EndLong
A bottle of oil. Good to 'massage someone. Leaves the skin
smooth and moisturized. It has a label on the back.
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
    int x ;
    // Chronos remarks:
    //   Don't forget to cover all instances.. What if people don't
    //   use an argument?  What if they try to massage themselves..
    if (!name) {
	write("Massage who?\n") ;
	return 1;
    }
    if (name==TP->query("name") ) {
	write("It's not nearly as fun to massage yourself.\n") ;
	return 1;
    }
    target = present(name,environment(this_player())) ;
    if (!target) {
	notify_fail("I don't that person here.\n") ;
	return 0 ;
    }
    if (!living(target)) {
	notify_fail ("Now that's funny.. You can't massage that.\n");
	return 0 ;
    }
    x = random(7) ;
    write(
      "You massage the "+body_part(x) + 
      " of "+capitalize(name)+" with the oil,\n"+
      "til "+possessive(target->query("gender"))+" skin feels"+
      " soft and smooth.\n"+
      capitalize(name)+" starts to relax...\n");

    tell_object(target,
      TPN + " massages your "+ body_part(x) + 
      " with the oil, til your skin feels\n"+
      "soft and smooth. You start to relax...\n");

    say(
      TPN + " massages "+capitalize(name)+"'s "+body_part(x) + 
      " in a sensual way with oil...\n", ({ target }) );
    /* ????
	tell_room(environment(TP), body_part()+"\n");
    */
    return 1 ;
}
string body_part(int x) {
    string str ;
    switch(x) {
    case 1: str = "chest" ; break ;
    case 2: str = "legs" ; break ;
    case 3: str = "bottom" ; break ;
    case 4: str = "shoulders" ; break ;
    case 5: str = "thighs" ; break ;
    case 6: str = "torso" ; break ;
    case 7: str="back"; break ;
    default: str = "back" ; break ;
    }
    return str ;
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
|     1. 'Squeeze' the 'bottle' on     |
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
