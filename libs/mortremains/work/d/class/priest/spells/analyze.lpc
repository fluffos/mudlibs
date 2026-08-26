//ilz
//  16 Dec 98  Cyanide updated and cleaned up.

#include <magic.h>

#define COST 8
#define SYNTAX "Syntax: invoke analyze at target\n" 
string help();

inherit SPELL;

int invoke_analyze (string str) {
    object target, shield;
    int flag, x;

    seteuid(getuid());

    if (!str) str = "NONE";
    if (str=="NONE") target = TP->query_current_attacker();
    if (!target) target = present(str, environment(TP));
    if (!target) {
	write(SYNTAX);
	return 0;
    }

    if (!check_valid_targ(TP, target)) return 0;  

    if (!living(target)) {
	write("The target must be alive.\n");
	return 1;
    }

if (!invoke_spell(TP, COST)) return 0;

    if (!check_magic_resist((TP->query_level()),target,COST,0)) return;

    write ("You begin casting Analyze Opponent upon "+
      target->query("cap_name")+".\n");
    say(wrap(TPN+" begins casting Analyze Opponent upon "+
	target->query("cap_name")+"."), ({ target }) );
    tell_object(target, wrap(TPN+" begins casting Analyze "+
	"Opponent upon you.") );

    write ("Level : "+target->query_level()+"\n");
    write ("Immune to weapons less than +"+target->query("weap_resist")+"\n");
    write ("Special Attack : Rank "+target->query("special")+"\n");
    return 1;
}

string spellcraft() {
    return (@EndSpellcraft
Analyze Opponent (Priest - Level I - Divination)

Duration: Instant			Area of Effect: 1 Target
Cost: 8 TP

    This spell gives information about the target. It is even 
know to exceed lore in some respects.
EndSpellcraft
    );
}
