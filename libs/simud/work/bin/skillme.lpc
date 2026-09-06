// Increment this value EVERY time you update the command - well, every time
// you want players to actually benefit from the changes ;)
#define PATCH_LEVEL 20

int query_patchlevel() { return PATCH_LEVEL; }

int main(string arg) {
	string *sk_list = ({ "combat.armour.light", "combat.armour.shield",
						 "combat.dodging", "combat.grappling",
						 "combat.intuition", "combat.technique.parry",
						 "combat.weapon.axe", "combat.weapon.dagger",
						 "combat.weapon.mace", "combat.weapon.sword",
						 "combat.weapon.unarmed", "combat.tactics",
						 // crafting
						 "craft.butcher", "craft.carpentry.buildings",
						 "craft.carpentry.furniture", "craft.cooking",
						 "craft.farming", "craft.leatherworking",
						 "craft.masonry", "craft.mining",
						 "craft.smithing.black", "craft.smithing.white",
						 "craft.smithing.weapons", "craft.tanning",
						 "craft.bonecarving", "craft.smithing.armour",
						 // knowledge
						 "knowledge.architecture",
						 "knowledge.language.common.spoken",
						 "knowledge.language.common.written",
						 "knowledge.science.geology",
						 // magic
						 "magic.concentration", "magic.faith.devotion",
						 "magic.faith.healing", "magic.intuition",
						 "magic.item.scroll", "magic.item.wand", "magic.item.misc",
						 "magic.mana.fire", "magic.mana.spirit",
						 "magic.mana.wind",
						 "magic.technique.abjuring",
						 "magic.technique.channeling",
						 "magic.technique.chanting",
						 "magic.technique.charming",
						 "magic.technique.evoking",
						 "magic.technique.scribing",
						 // other
						 "other.endurance", "other.medicine.first_aid",
						 "other.mentoring",
					  });
	string *form_list = ({ "spellcaster", "knife", "sword", "brawl",
					       "axe", "bludgeon" });
	string *recipe_list = ({ "pick", "hatchet", "knife", "club", "mine", "flint and steel",
							 "paper box", "disposable cup",
					         "field", "shack", "shop", "sign", "copper",
							 "tin", "lead", "paper", "salt", "flour", "grain",
							 "jerky", "pumpkin seed", "roast pumpkin seed" });
	string *spell_list = ({ "cantrip", "channel", "heal", "mana bolt",
							"invigorate", "stun" });

	// ----- You shouldn't have to edit anything below here ----- //
	
	string str;
	int x, pl = this_player()->query_env_var("skill_patchlevel");
	int force = (arg == "force");
	
	// character predates the patchlevel record
	if( !pl ) {
		// check if they're absolutely ancient
		this_player()->validate_skills();
   		// check if they're coming from the old tree
		if( sizeof(this_player()->query_skills()) ) {
			msg("~CBRTYou have old skills ;)~CDEF");
			// convert them
			"/bin/wiz/newskillme"->main();
			// NOTE: Yeah, I know this is heinously crufty, but shrug.
		}
	}

	// migrate lightning skill
	if( x = this_player()->query_skill_level("magic.mana.electricity") ) {
		msg("~CTITThe electricity skill has been renamed to lightning.~CDEF");
		this_player()->set_skill("magic.mana.lightning", x);
		this_player()->remove_skill("magic.mana.electricity");
	}

	// check if they're already up-to-date
	if( pl == PATCH_LEVEL ) {
		if( force )
			msg("~CBRTForcing re-evaluation of skills, forms, and spells.~CDEF");
		else {
			msg("~CBRTYou already have current skills.~CDEF");
			return 1;
		}
	}
	
	// Skills
	msg("~CCOMChecking your skills...~CDEF");
	foreach( str : sort_array(sk_list, #'>) ) {
		if( !this_player()->query_skill( str ) ) {
			this_player()->add_skill( str );
			msg("~CTITYou have been given the "+str+" skill.~CDEF");
		}
	}
	// convert over misspelled saccrifice skill
	if( this_player()->query_skills()["magic.faith.saccrifice"] ) {
		int tmp = this_player()->query_skills()["magic.faith.saccrifice"];
		msg("~CTITMigrating 'saccrifice' skill to sacrifice :)~CDEF");
		this_player()->set_skill( "magic.faith.sacrifice", tmp );
		this_player()->remove_skill( "magic.faith.saccrifice" );
	}

	// Forms
	msg("~CCOMChecking your forms...~CDEF");
	foreach( str : sort_array(form_list, #'>) ) {
		if( !member(this_player()->query_known_forms(), str) ) {
			this_player()->add_form( str );
			msg("~CTITYou have been given the "+str+" combat form.~CDEF");
		}
	}
	// Recipes
	msg("~CCOMChecking your recipes...~CDEF");
	foreach( str : sort_array(recipe_list, #'>) ) {
		if( member(this_player()->query_known_recipes(), str) == -1 ) {
			this_player()->add_recipe( str );
			msg("~CTITYou have been given the "+str+" recipe.~CDEF");
   		}
	}
	// Spells
	msg("~CCOMChecking your spells...~CDEF");
	foreach( str : sort_array(spell_list, #'>) ) {
		if( !member(this_player()->query_known_spells(), str) ) {
			this_player()->add_spell( str );
			msg("~CTITYou have been given the "+str+" spell.~CDEF");
		}
	}

	// set new patchlevel
	this_player()->set_env_var("skill_patchlevel",PATCH_LEVEL);
	msg("~CBRTSkills, forms, and spells updated.~CDEF");
	return 1;
}
