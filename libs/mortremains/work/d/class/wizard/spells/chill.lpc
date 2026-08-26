/*
** FILE: chill.c  (originally missile.c)
** PURPOSE: 1st level mage necromancy spell.
** COST: 4 SP
** EFFECTS: Slight cold damage. For the sake of simplicity,
**          this spell is basically a cold version of missile.
** CHANGES:
**  18 Jun 1996    Chronos    Created the file.
**  21 Jun 1996    Cyanide    "Borrowed" the file...
**                              (Thanks, C!)
**  21 Spr 1998    Cyanide    Converted to HIS mudlib!  Whee!
*/

#include <m_spells.h>
#include "/u/c/cyanide/debug.h"

inherit SPELL;

#define TPP possessive(this_player()->query("gender"))
#define SUBJ subjective(target->query("gender"))

#define COST 4
#define ROLL random(4)+2

varargs int cast_chill(string str, int obj) {
    object room = environment(TP);
    object target ;
    int damage = 0, x;
    string name;

    if (!str) str = "NONE";
    if (str == "NONE") target = TP->query_current_attacker();
    else target = present(str,environment(TP)) ;

    if (!target) {
	write ("Usage: cast chill at <target>\n");
	return 1 ;
    }
    name = target->query("cap_name");
    // if obj==1, then the call came from an object and we don't want to
    // assess the spell point cost.

    if (!obj) {
	if (!cast_spell(TP, COST)) {
	    return 1;
	}

	obj = query_caster_level(TP, "wizard");
    }

    if (!check_magic_resist(obj,target,COST,damage)) return; 

    obj = 1 + (obj/2);

#ifdef MAX_TO_SPELLS
    if (obj>5) obj = 5;
#endif

    for (x=0; x<obj; x++) damage+=ROLL;
    damage = spell_mult(damage);

    // Note: it's a touch attack. Stoneskin and fireshield 
    // WILL be triggered by this spell.

    damage = target->receive_damage(damage,"cold",target,1);
    target->set("last_attacker", TP);
    target->kill_ob(TP);
    switch(damage) {
    case -10000..-1 :
	tell_room(room, "The elemental cold actually heals "+name+"!\n",
	  target);
	tell_object(target, "The elemental cold actually heals you!\n");
	break;
    case 0 : 
	tell_room(room, name+" stands unaffected by the chill.\n",
	  target);
	tell_object(target, "You stand unaffected by the chill.\n"+
	  "You just laugh.\n");
	break;
    case 1..4: tell_object(target, 
	  "A slight chill touches you.\n");
	write ("A slight chill touches "+name+".\n");
	say ("A slight chill touches "+name+".\n");
	break;
    case 5..10: tell_object(target, 
	  "Your soul recoils at the unnatural cold.\n");
	say(name+"'s soul recoils at the unnatural cold.\n");
	write(name+"'s soul recoils at the unnatural cold.\n");
	break;
    case 11..18: tell_object(target, 
	  "You grit your teeth as the bitter chill stings your body.\n");
	say(name+" grites "+POSS+" teeth as the bitter chill stings "+POSS+
	  " body.\n");
	write(name+" grits "+POSS+" teeth as the bitter chill stings "+POSS+
	  " body.\n");
	break;
    case 19..28: tell_object(target, 
	  "You are chilled to the very marrow of your bones.\n");
	say(name+" is chiled to the very marrow of "+POSS+" bones.\n");
	write (name+" is chilled the the very marrow of "+POSS+" bones.\n");
	break;
    case 29..40: tell_object(target, 
	  "The chill of the dead withers your very soul.\n");
	say("The chill of the dead withers "+name+"'s very soul.\n");
	write("The chill of the dead withers "+name+"'s very soul.\n");
	break;
    default: tell_object(target, 
	  "Your soul is torn by the chill of death.\nYou scream in agony.\n");
	say(name+"'s soul is torn by the chill of death.\n"+
	  capitalize(SUBJ)+" screams in agony.\n");
	write (name+"'s soul is torn by the chill of death.\n"+
	  capitalize(SUBJ)+" screams in agony.\n");
	break;
    }

    return 1 ;
}


string spellcraft() {
    return (@EndSC
Chill Touch (Necromancy, 1st Level Mage Spell)
Category: Offensive

	This spell opens a minute rift to the negative material 
plane, effectively sucking heat from that target.
EndSC
    );
}
