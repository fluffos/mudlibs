/*
** FILE:     _lore.c
** PURPOSE:  Gives the players some basic info on a monster. How
**           much is dependant on level and skills.
** AUTHOR:   Cyanide@Mortal Remains
** CHANGES:
**   28 Jun 2000  Cyanide created the file, replacing the dinosaur
**                created by Ilzarion. A very few details were 
**                borrowed from that file.
*/

#include "/u/c/cyanide/debug.h"
#include <daemons.h>

inherit DAEMON;

#undef MONSTER
#define ANIMAL 0
#define MONSTER 1
#define DEMON 2
#define UNDEAD 3
#define CONSTRUCT 4

#define SKILLS ({ "Animal Lore", "Monster Lore", "Demon Lore", \
    "Undead Lore", "Arcanology" })


string is_valid_skill( string skill ) {
    if (!skill) return "";

    skill = cap_all_words( skill );

    if (member_array(skill, SKILLS) == -1) {
	switch(lower_case(skill)[0..3]) {
	case "unde" : skill = "Undead Lore"; break;
	case "mons" : skill = "Monster Lore"; break;
	case "demo" : skill = "Demon Lore"; break;
	case "spel" : case "arca" : skill = "Arcanology"; break;
	case "anim" : skill = "Animal Lore"; break;
	default : skill = "";
	}     
    }

    return skill;
}

string get_skill_used( object ob ) {
    string skill;

    skill = ob->query("lore_type");
    skill = is_valid_skill(skill);

    if (skill && strlen(skill)) return skill;

    if (ob->query("undead")) {
	skill = SKILLS[ UNDEAD ];
    } else {
	if (ob->query("magic_resistance") || 
	  ob->query("weap_resist") || 
	  (ob->query("resist_type") && 
	    sizeof(keys(ob->query("resist_type")))) ) {
	    if (base_name(ob)[0..4] == "/d/Pl")
		skill = SKILLS[ DEMON ];
	    else
		skill = SKILLS[ MONSTER ];
	} else {
	    skill = SKILLS[ ANIMAL ];
	} // if (query("magic_resist")... etc
    } // if undead

    return skill;
}

int cmd_lore( string str ) {
    object ob;
    string skill, lore_text;
    int xpv, roll, deviation, chance;

    if (!str) {
	ob = TP->query_current_attacker();
	if (!ob) {
	    write("What would you like to lore?\n");
	    return 1;
	}
    } else {
	ob = present(str, environment(TP));
	if (!ob || !visible(ob)) {
	    write("You don't see that here.\n");
	    return 1;
	}
    }

    if (!living(ob)) {
	write("You're pretty sure it won't fight back.\n");
	return 1;
    }

    skill = get_skill_used(ob);
    if (!TP->query_skill(skill)) {
	write(wrap("You don't have sufficient knowledge in "+
	    lower_case(skill)+"."));
	return 1;
    }

    deviation = 25 - (int)TP->query("stat/intelligence");
    deviation -= (TP->query_level() - ob->query_level());
    if (deviation < 0) deviation = 0;
    chance = 100 - (deviation << 2);

    if (!undefinedp(TP->query("roll"))) {
	roll = (int)TP->query("roll");
    } else {
	roll = (random(100) + 2);   
	TP->set("roll", roll);
    }

    roll += random((deviation << 1) + 1) - deviation;
    roll = chance = roll;

    if (roll < 0) {
	write("You've heard of this creature, but aren't sure about it.\n");
	return 1;
    }

    write("Your mastery of "+lower_case(skill)+
      " tells you the following:\n");

    if (!undefinedp(ob->query("lore")))
	write(ob->query("lore"));
    // Even is 100. The higher, the more powerful ob releative to TP
    switch((PROPERTY_D->get_xp_rank(ob)*100)/
      PROPERTY_D->get_xp_rank(TP)) {
    case -1000..9  : write("Its mere sight makes you laugh.\n"); break;
    case  10.. 29  : write ("It seems to be beneath your"+
	  " notice.\n");break;
    case  30.. 49 : write ("You could probably tear it a new "+
	  "asshole.\n");break;
    case  50.. 69 : write ("Unless it's packing some serious power, "+
	  "you got it.\n");break;
    case  70.. 89 : write("You slightly overpower it.\n");
    case  90..109 : write ("It's about your size.\n");break;
    case 110..129 : write("It slightly overpowers you.\n"); break;
    case 130..149 : write ("It will probably put up a "+
	  "good fight.\n");break;
    case 150..169 : write ("It looks kinda mean.\n");break;
    case 170..189 : write ("It looks like it can do you a world "+
	  "of hurt.\n");break;
    case 190..209 : write ("It looks like a mack mutha'"+
	  "fucka'.\n");break;
    case 210..229 : write ("Looks like it can kick ass "+
	  "and take names.\n");break;
    default : write ("Do you really want to die?\n");break;
    }

    // AC ranking if they beat the roll by 5+
    if (roll < 5) return 1;

    switch((int)ob->query("armor_class")
      - PROPERTY_D->query_dex_ac_bonus(ob) -
      - (int)ob->query("magical_defense"))
    {
    case -1000..-20 : write("It looks impossible to damage.\n"); break
	;
    case -19..-7 : write ("It looks you'll have an "+
	  "extremely hard time damaging it.\n");break;
    case -6..-1 : write ("It looks very hard to hit.\n");break;
    case 0..3 : write ("It looks hard to hit.\n");break;
    case 4..6 : write ("It doesn't look too tough "+
	  "to damage.\n");break;
    case 7..100 : write ("It looks a bit soft and sluggish.\n");break;
    default: write("You have no idea how hard it is to hit.\n");
	break ;
    }

    if (roll < 10) return 1;
    switch((int)ob->query("weap_resist")) {
    case -1..0 : write("It can be hit by any weapon.\n"); break;
    case 1 : write("Any magical weapon will hit it.\n"); break;
    case 2 : write("Most magical weapons will hit it.\n"); break;
    case 3 : write("A pretty powerful magical weapon "+
	  "will hit it.\n"); break;
    case 4 : write("A highly magical weapon is needed to hit it.\n"); break;
    case 5 : write("Only truly mighty enchanted weapons can hit it.\n");
	break;
    case 6 : write("It can only be hit by a weapon of the Gods.\n"); break;
    }

    if (roll < 15) return 1;
    if (ob->query("resist_type")) {
	mapping res = ob->query("resist_type");
	string *dam = keys(res);
	int i;

	for (i=0; i<sizeof(res); i++) {
	    string out = "ERROR";

	    switch(res[dam[i]]) {
	    case -4000..-1 : out = "native to "; break;
	    case  0 : out = "immune to "; break;
	    case  1..49 : out = "highly resistant to "; break;
	    case 50..74 : out = "resistant to "; break;
	    case 75..99: out = "slightly resistant to "; break;
	    case 100 : continue; break;
	    default : out = "susceptible to "; break;
	    }
	    write("It is "+out+dam[i]+".\n");
	}
    } // end query("resist_type")

    if (roll < 20) return 1;

    if (ob->query("mage_spells")) 
	write("It is known to use the magic of mages.\n");

    if (ob->query("priest_spells"))
	write("It is known to use the magic of priests.\n");

    return 1;
}

string help() {
    return(wrap(
	"Syntax: lore (target)\n\nThis command gives you some information "+
	"about a potential combatant. The amount and detail of this "+
	"information depends on the 'lore' skills you have, your "+
	"intelligence, and the relative power of the creature.\n"+
	"If in combat, this command without an argument will give "+
	"the lore of the creature you're fighting."));
}
/* EOF */
