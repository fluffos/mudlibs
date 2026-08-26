/*
** File: glove.c
** Author: won't tell
** Other: Private intentions. Stop snooping!!!!
*/

#include <mudlib.h>

inherit ARMOR ;

void create() {
    set ("short", "a nlub glove");
    set("long", @EndText
A nlub glove. It's made of latex. 'Wear' it.
Commands are:
*rub <player>
*thrust <player>
*cum
EndText);
set("id", ({ "glove", "latex glove", "condom" }) );
set_armor_type("robes");
set("mass", 1);
}

void init() {
    add_action("thrust", "thrust");
    add_action("cum", "cum");
    add_action("rub", "rub");
}

int thrust (string name) {
    object target;
    target = present(name, environment(this_player() ));
    if (!target) {
	notify_fail ("There's no player loged in by that name.\n");
	return 0;
    }
    if(!living(target)) {
	notify_fail("You can't thrust that.\n");
	return 0;
    }
    write(wrap(
	"You thrust "+capitalize(name)+" real hard and with so much passion.\n"+
	"You become hornier each second...\n"));
    tell_object(target, wrap(
	TPN+" Thrusts you real hard and with so much passion.\n"+
	"Your temperature increases as you and him become hornier...\n"));
    say(
      TPN+"thrusts "+capitalize(name)+
      " real hard and with passion.\n", ({ target }) );
    return 1;
}
int cum (string str) {
    say(wrap(
	TPN+" has reached "+POSS+" climax and cums messily and plenty.\n"+
	"He feels satisfied...\n"));
    write(wrap(
	"You reached your climax and cum messily and plenty.\n"+
	"Now you're satisfied...\n"));
    return 1;
}
int rub (string name) {
    object target;
    target = present(name, environment(this_player() ));
    if(!target) {
	notify_fail("No one by that name is logged in.\n");
	return 0;
    }
    if (!living(target)) {
	notify_fail("Oh great. You really wanna rub that???  LOL\n");
	return 0;
    }
    write(wrap(
	"You rub the clit of "+capitalize(name)+", making her hornier\n"+
	"and desperate. "+capitalize(name)+" wants you badly...\n"));
    tell_object(target, wrap(
	TPN+" rubs your clit, making you hornier and desperate.\n"+
	"You want him badly...\n"));
    say(
      TPN+" rubs the clit of "+capitalize(name)+", making her hornier\n"+
      "and desperate. "+capitalize(name)+
      " wants him badly...\n", ({ target }) );
    return 1;
}
/* EOF */
