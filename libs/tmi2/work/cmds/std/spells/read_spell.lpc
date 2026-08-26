// read_spell.c.  The read magic spell.
// If you have a scroll in your possession, with a spell written on it,
// then you can use this spell to learn the on one the scroll.
// One should not create objects that cast this spell.
// Mobydick, 3-24-93.

#include <mudlib.h>
#include <magic.h>

inherit DAEMON ;

int cast (string str) {

	object scroll ;
	string *known ;
	int which, sp, cost, skill ;
	string spell ;

	if (str!="NONE") {
		scroll = present(str,this_player()) ;
	} else {
		scroll = present ("scroll", this_player()) ;
	}
	if (!scroll) {
		write ("You must have a scroll with a spell written on it before you can learn the new\nspell with the read spell.\n") ;
		return 1 ;
	}
	spell = scroll->query("spell") ;
	if (!spell) {
		write ("There's no spell written on it to learn.\n") ;
		return 1 ;
	}
	which = member_array(spell,SPELLS) ;
	if (which==-1) {
		write ("You can't make any sense of what's written on the scroll.\n") ;
		return 1 ;
	}
	known = this_player()->query("spells") ;
	if (member_array(spell,known)>-1) {
		write("You already know the "+spell+" spell!\n") ;
		return 1 ;
	}
	skill = this_player()->query_skill(SPELL_SKILLS[which]) ;
	if (skill<LEARN_LEVELS[which]) {
		write ("You do not have enough skill to learn that spell.\n") ;
		return 1 ;
	}
	sp = this_player()->query("spell_points") ;
	skill = this_player()->query_skill("Divinations spells") ;
        cost = 100/(skill+10) ;
        if (sp<cost) {
                write ("You haven't got enough spell points to cast it.\n") ;
                return 1 ;
        }
        this_player()->set ("spell_points", sp-cost) ;
	known += ({ spell }) ;
	this_player()->set("spells", known) ;
	write ("You cast the read spell... You now know the "+spell+" spell!\n") ;
	say (this_player()->query("cap_name")+" studies his scroll intensely.\n") ;
	scroll->remove() ;
        this_player()->improve_skill("Divinations spells", 5) ;
        return 1 ;
}
