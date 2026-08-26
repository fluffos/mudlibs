//ilz

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

#define COST 8

string help();

inherit SPELL;

int invoke_bless (string str) {
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
    if (present("#BLESS_SPELL#", target)) {
	if (flag) 
	    write("That personal already has a bless spell active!\n");
	else
	    write("You have a bless spell active!\n");

	return 0;
    }

    if (!invoke_spell(TP, COST)) return 0;

    write ("You begin casting bless.\n");
    if (flag) 
	say(wrap(TPN+" blesses "+target->query("cap_name")+
	    " with a prayer from "+possessive(TP->query("gender"))+"deity."));

    shield = clone_object("/d/class/priest/obj/bless_ob");

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
Bless (Priest - Level I - All)

Duration: 20 seconds/lvl                Area of Effect: 1 Target
Cost: 8 TP

	This spell a blessing upon the target.
EndSpellcraft
    );
}
