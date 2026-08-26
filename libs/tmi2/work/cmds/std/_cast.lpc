// cast.c
// Command hook for spellcasting.
// A player casts a spell by typing "cast <name> [at|on] <name>"
// The input is parsed for spell name and target, and control is passed
// to /cmds/std/<name>_spell.c, which takes the target as an argument
// and does the Right Thing.
// Many of the spells require hooks in the user object. These hooks are
// found in /std/living/spells.c.
// You can make monsters cast spells also. See /obj/foobird.c or any other
// spellcasting monster's code for the details.

// Created 10-5-92 by Mobydick@TMI-2

#include <mudlib.h>
#include <magic.h>

inherit DAEMON ;

int spell_exists (string spell) ;
string help() ;

int cmd_cast (string str) {

	string targname, spell, code ;
	int found ;
	object target ;
	string *known ;

	if (!str) {
		help() ;
		return 1 ;
	}
	if ((int)this_player()->query("stop_attack")>0) {
		notify_fail ("You are too busy to cast a spell now.\n") ;
		return 0 ;
	}
// Check for the form "cast spell at opponent".
	if (sscanf(str,"%s at %s",spell,targname)==2 ||
		sscanf(str,"%s on %s",spell,targname)==2) {
		code = PATH+spell+EXTENSION ;
		known = this_player()->query("spells") ;
		if (!known || member_array(spell,known)==-1) {
			notify_fail ("You don't know any such spell.\n") ;
			return 0 ;
		}
		found = call_other(code,"cast",targname) ;
		if (found==1) return 1 ;
	}
// Check for the form "cast spell name".
	if (sscanf(str,"%s %s",spell,targname)==2) {
                code = PATH+spell+EXTENSION ;
		known = this_player()->query("spells") ;
		if (!known || member_array(spell,known)==-1) {
                        notify_fail ("You don't know any such spell.\n") ;
                        return 0 ;
                }
                found = call_other(code,"cast",targname) ;
                if (found==1) return 1 ;
	}
// If we got here, assume the form "cast spell".
	spell = str ;
	code = PATH+str+EXTENSION ;
	known = this_player()->query("spells") ;
	if (!known || member_array(spell,known)==-1) {
		notify_fail ("You don't know such a spell.\n") ;
		return 0 ;
	}
	found = call_other(code,"cast","NONE") ;
	if (found==1) return 1 ;
	notify_fail("That spell doesn't seem to exist.\n") ;
	return 0 ;
}

int spell_exists (string spell) {
	if (member_array(spell,SPELLS)!=-1) return 1 ;
	return 0 ;
}

string help() {
	return(@HELP
Syntax: cast <spellname> [spell arguments]

This command allows you to cast spells you know.
The spells are:

Read:	      Learn a new spell from a scroll.
Missile:      Cast a magic missile at an opponent.
Fireball:     Cast a fireball at all your current opponents.
Heal:         Increase the hit points of the target.
Vision:       See the surroundings of another player.
Invisibility: Turn your target invisibile.
Message:      Send a message to another player.
Raise:        Bring a corpse back to life.

Some spells require a target: for example,
cast missile at orc
cast raise on fred
Others do not: for example,
cast fireball
HELP
    ) ;
}
