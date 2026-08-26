//ilz
// Cyanide cleaned, 11 Jul 2000

#include <magic.h>
#include <p_spells.h>
#include <mudlib.h>

#define COST 15

string help();

inherit SPELL;

int invoke_barkskin (string str) {
    object target, shield;
    int flag;

    seteuid(getuid());

    if (!str||str=="me"||str==(string)TP->query("name")) {
	target = TP;
    } else {
	target = present(str, environment(TP));
	if (!target) {
	    write("Couldn't find "+capitalize(str)+" here.\n");
	    return 1;
	}
	if (!living(target)) {
	    write("The target must be alive.\n");
	    return 1;
	}
	flag=1;
    }
    if (present("#BARKSKIN_SPELL#", target)) {
	if (flag) write("They have a barkskin spell active!\n");
	if (!flag) write("You have a barkskin spell active!\n");

	return 0;
    }

    if (!invoke_spell(TP, COST)) return 0;

    write ("You begin casting barkskin.\n");
    say(TPN+" begins to pray...\n");

    shield = clone_object("/d/class/priest/obj/barkskin_ob");

    if (!shield) {
	write("Your spell fizzles.  Contact Cyanide.\n");
	say(TPN+"'s spell fizzles...\n");
	return 0;
    }

    shield->move(target);
    shield->begin_spell(TP, target);
    return 1;
}

string spellcraft() {
    return (@EndSpellcraft
Barkskin (Priest - Level II - Protection, Plant)

Duration: 30 rounds/lvl			Area of Effect: 1 Target
Cost: 15 TP

	This spell turns the target's skin to armor as tough as
an old tree.
EndSpellcraft
    );
}
