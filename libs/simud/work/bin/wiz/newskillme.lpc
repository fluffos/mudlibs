#define NEW	("/daemon/skill")

mapping name_map;
mapping skills;

int create() {
	name_map = ([
		// crafting
		"craft.sculptor": "craft.art.sculpture",
		"craft.tailor": "craft.sewing",
		"craft.mason": "craft.masonry",
		"craft.tanner":	"craft.tanning",
		"craft.blacksmith": "craft.smithing.black",
		"craft.carpenter": ({"craft.carpentry.furniture","craft.carpentry.buildings"}),
		"craft.armoursmith": "craft.smithing.armour",
		"craft.weaponsmith": "craft.smithing.weapons",
		"craft.leatherworker": "craft.leatherworking",
		"craft.goldsmith": "craft.smithing.white",
		"craft.painter": "craft.art.painting",
		"craft.papermaker": 0,
		"craft.cobbler": 0,
		// combat
		"combat.weapon.knife": "combat.weapon.dagger",
		"combat.weapon.hammer": "combat.weapon.mace",
		"combat.weapon.whip": "combat.weapon.flail",
		"combat.weapon.staff": "combat.weapon.polearm",
		"combat.dodge": "combat.dodging",
		"combat.parry": "combat.technique.parry",
		"combat.counter": "combat.technique.counter",
		"combat.technique.shove": 0,
		// other
		"other.firstaid": "other.medicine.first_aid",
		// knowledge
		"knowledge.nature": ({"knowledge.herbology","knowledge.science.botany"}),
		"knowledge.agriculture": ({"craft.farming","knowledge.science.botany"}),
		"knowledge.technology": ({"knowledge.architecture","knowledge.science.mathematics"}),
		"knowledge.mathematics": "knowledge.science.mathematics",
		"knowledge.geology": ({"knowledge.science.geology","craft.mining"}),
		"knowledge.anatomy": "knowledge.science.biology",
		"knowledge.literacy": ({"knowledge.history.terador","knowledge.language.common.written"}),
		"knowledge.astronomy": "knowledge.science.astronomy",
		// magic
		"magic.concentration": ({"magic.concentration","magic.meditation"}),
		"magic.faith": ({"magic.faith.blessing","magic.faith.healing"}),
		"magic.spellcraft": ({"magic.technique.abjuring","magic.technique.animating","magic.technique.binding","magic.technique.channeling","magic.technique.chanting","magic.technique.evoking","magic.technique.singing"}),
	]);
	return 1;
}

int skill_cost(string skill, int lvl) {
	if( !NEW->query_skill_exists(skill) ) {
		msg("~CWRNError! ~CBRT"+skill+" is not a valid skill under the new system!~CDEF");
	}
	return NEW->query_skill_difficulty(skill) * lvl * (lvl+1) / 2;
}

int main() {
	string str;
	int spells, x, xp, l;
	mapping new_skills = ([:4]);
	mapping skills = this_player()->query_skills();
	
	if( !this_player()->query_env_var("skill_backup") ) {
		msg("~CACTBacking up your old skill data...~CDEF");
		this_player()->set_env_var("skill_backup", skills);
	}

	msg("~CCOMConverting your skills over to the new system...~CDEF");
	
	foreach( str : m_indices(skills) ) {
		if( member(name_map,str) ) {
			if( name_map[str] ) {
				/* msg( str + " = " + as_lpc(name_map[str]) ); */
				if( pointerp(name_map[str]) ) {
					msg("~CBRT"+str+" has been broken up into "+sizeof(name_map[str])+" new skills.~CDEF");
					for( x = 0; x < sizeof(name_map[str]); x++ ) {
						msg("~CTITYou have been given the "+name_map[str][x]+" skill.~CDEF");
						l = max(1, min(skills[str,0] - 2*sizeof(name_map[str]), 100));
						xp = skill_cost(name_map[str][x], l);
						new_skills[name_map[str][x],0] = l;
						new_skills[name_map[str][x],1] = xp;
						new_skills[name_map[str][x],2] = 0;
						new_skills[name_map[str][x],3] = xp + 500;
					}
				} else {
					msg("~CBRT"+str+" has been renamed.~CDEF");
					msg("~CTITYou have been given the "+name_map[str]+" skill.~CDEF");
					l = skills[str,0];
					xp = skill_cost(name_map[str], l);
					new_skills[name_map[str],0] = l;
					new_skills[name_map[str],1] = xp;
					new_skills[name_map[str],2] = 0;
					new_skills[name_map[str],3] = xp + 500;
				}
			} else {
				// skill go bbye
				msg( "~CBRT"+str+" has been removed from the game.~CDEF" );
			}
		} else if (str[0..11] == "magic.spell.") {
			spells = 1;
		} else if ( !NEW->query_skill_exists(str) ) {
			msg( "~CWRN" + str + " = ???~CDEF");
			return 1;
		} else {
			/* msg( str + " = unchanged" ); */
			l = skills[str,0];
			xp = skill_cost(str, l);
			new_skills[str,0] = l;
			new_skills[str,1] = xp;
			new_skills[str,2] = 0;
			new_skills[str,3] = xp + 500;
		}
	}
	/* The regular /bin/skillme command should teach them languages
	 *
	new_skills += ([ "knowledge.language.common.spoken": 100; 50500; 0; 50500,
				    "knowledge.language.common.written":100; 50500; 0; 50500]);
	*/
	if( spells )
		msg( "~CACTYour magic.spell.* skills will be deleted in this change, but will eventually come back as changes are made to the magic system~CDEF" );

	this_player()->set_skills( new_skills );
	return 1;
}
