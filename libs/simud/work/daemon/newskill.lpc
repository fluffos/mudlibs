mapping skill_map;
// keep the names under 25 chars for wizard 'skills' view
// keep the descriptions under 45 chars for player 'skills' view

mapping query_skill_map() { return skill_map; }

struct Skill {
	int	difficulty;		// number 8-20, with 10-15 being normal
	string	*stats;		// 3 stats involved
	string	desc;		// short description of the skill
	string	help_desc;	// long description used on help files
};

// list of skills that don't generate party bonuses
int query_no_share(string skill) {
	return member( ([
		"combat.intuition", "magic.concentration", "magic.intuition",
		"magic.meditation", "other.mentoring"
	]), skill );
}

int create() {
skill_map = ([
	// Combat skills
	"combat":	(<Skill> 0, ({ }),
		 		 "fighting for fun and profit",
				 "The combat skill tree governs all aspects of physical "+
				 "conflict, be it melee or ranged, with or without weapons."),
		"combat.armour":
				(<Skill> 0, ({ }),
				 "using armour effectively",
				 "Armour skills are important if you want to be able to "+
				 "wear heavy metal armour without experiencing stat "+
				 "penalties for so doing.\n\nSome armour is impossible to "+
				 "use at all unless you have sufficient skill."),
			"combat.armour.heavy":
				(<Skill> 15, ({"str","str","dex"}),
				 "moving about in heavy armour",
				 "This skill reduces your penalties for walking around in "+
				 "heavy armour - plate armour and some particularly large "+
				 "chain type armours qualify as heavy."),
			"combat.armour.helmet":
				(<Skill> 15, ({"emp","emp","emp"}),
				 "keeping your head covered",
				 "Normally, wearing a helmet would reduce your perception "+
				 "and has a somewhat unbalancing effect on your reactions "+
				 "to things that happen in combat. This skill helps to "+
				 "offset those penalties when appropriate."),
			"combat.armour.light":
				(<Skill> 10, ({"str","dex","dex"}),
				 "moving about in light armour",
				 "This skill reduces your penalties for wearing light "+
				 "armour and is completely independant of skill with heavy "+
				 "armour. Some leather and hide equipment is classified "+
				 "as light as are most types of mail. Heavy clothing does "+
				 "not usually require this skill."),
			"combat.armour.shield":
				(<Skill> 13, ({"str","dex","emp"}),
				 "blocking attacks with a shield",
				 "This skill directly affects your ability to interpose "+
				 "a shield between yourself and injury. Some shields will "+
				 "actually require a good level of this skill before you "+
				 "are allowed to even attempt using them."),
		"combat.dodging":
				(<Skill> 10, ({"dex","spd","emp"}),
				 "avoiding attacks"),
		"combat.dual_wield":
				(<Skill> 18, ({"dex","dex","str"}),	
				 "wielding two weapons at once"),
		"combat.grappling":
				(<Skill> 16, ({"dex","str","emp"}),
				 "grabbing and disabling opponents with your bare hands"),
		"combat.intuition":
				(<Skill> 20, ({"emp","cha","int"}),
				 "understanding your enemy"),
		"combat.ranged":
				(<Skill> 0, ({ }),
				 "hitting people from afar"),
			"combat.ranged.bow":
				(<Skill> 15, ({"dex","str","emp"}),
				 "shooting bows"),
			"combat.ranged.crossbow":
				(<Skill> 15, ({"dex","dex","emp"}),
				 "shooting crossbows"),
			"combat.ranged.gun":
				(<Skill> 14, ({"dex","emp","emp"}),
				 "shooting guns"),
			"combat.ranged.thrown":
				(<Skill> 13, ({"dex","str","str"}),
				 "throwing weapons"),
		"combat.tactics":
				(<Skill> 20, ({"int","dex","emp"}),
				 "fighting with your head"),
		"combat.technique":
				(<Skill> 0, ({ }),
				 "advanced combat maneuvers"),
			"combat.technique.ambush":
				(<Skill> 17, ({"spd","cha","emp"}),
				 "catching your foes unawares"),
			"combat.technique.counter":
				(<Skill> 18, ({"spd","emp","wil"}),
				 "responding to enemy attacks"),
			"combat.technique.critical":
				(<Skill> 20, ({"emp","int","cha"}),
				 "landing critical blows"),
			"combat.technique.disarm":
				(<Skill> 16, ({"str","dex","spd"}),
				 "disarming your foes"),
			"combat.technique.mounted":
				(<Skill> 18, ({"emp","emp","dex"}),
				 "fighting while mounted"),
			"combat.technique.parry":
				(<Skill> 13, ({"str","spd","dex"}),
				 "parrying attacks with your weapon"),
			"combat.technique.riposte":
				(<Skill> 18, ({"spd","spd","spd"}),
				 "turning parries into counters"),
		"combat.two_handed":
				(<Skill> 15, ({"str","str","str"}),
				 "using a weapon with both hands"),
		"combat.weapon":
				(<Skill> 0, ({ }),
				 "skill with weapons"),
			"combat.weapon.unarmed":
				(<Skill> 8, ({"str","dex","con"}),
				 "fighting unarmed"),
			"combat.weapon.dagger":
				(<Skill> 9, ({"dex","spd","cha"}),
				 "skill with daggers and knives"),
			"combat.weapon.sword":
				(<Skill> 12, ({"str","str","dex"}),
				 "skill with swords"),
			"combat.weapon.axe":
				(<Skill> 10, ({"str","str","con"}),
				 "skill with axes and picks"),
			"combat.weapon.mace":
				(<Skill> 9, ({"str","str","str"}),
				 "skill with maces and hammers"),
			"combat.weapon.flail":
				(<Skill> 13, ({"dex","dex","emp"}),
				 "skill with flails and whips"),
			"combat.weapon.polearm":
				(<Skill> 12, ({"str","dex","con"}),
				 "skill with polearms"),
			"combat.weapon.exotic":
				(<Skill> 17, ({"int","emp","dex"}),
				 "skill with exotic weapons"),
	// Craft
	"craft":
				(<Skill> 0, ({ }),
				 "skilled professions"),
		"craft.animal_training":
				(<Skill> 17, ({"wil","cha","cha"}),
				 "training animals"),
		"craft.art":
				(<Skill> 0, ({ }),
				 "artistic creation"),
			"craft.art.drawing":
				(<Skill> 8, ({"int","cha","dex"}),
				 "drawing"),
			"craft.art.engraving":
				(<Skill> 12, ({"wil","dex","int"}),
				 "engraving"),
			"craft.art.painting":
				(<Skill> 10, ({"int","cha","dex"}),
				 "painting"),
			"craft.art.sculpture":
				(<Skill> 16, ({"str","emp","wil"}),
				 "sculpting"),
			"craft.art.writing":
				(<Skill> 18, ({"cha","wil","int"}),
				 "creative writing"),
		"craft.bonecarving":
				(<Skill> 15, ({"dex","dex","emp"}),
				 "carving things from bone and shell"),
		"craft.brewing":
				(<Skill> 8, ({"con","wil","str"}),
				 "brewing drinks"),
		"craft.butcher":
				(<Skill> 10, ({"str","con","con"}),
				 "cutting meat from bones"),
		"craft.carpentry":
				(<Skill> 0, ({ }),
				 "working in wood"),
			"craft.carpentry.furniture":
				(<Skill> 18, ({"str","int","dex"}),
				 "building furniture"),
			"craft.carpentry.vehicles":
				(<Skill> 20, ({"str","str","dex"}),
				 "bulding vehicles"),
			"craft.carpentry.buildings":
				(<Skill> 16, ({"str","str","con"}),
				 "constructing buildings"),
		"craft.cooking":
				(<Skill> 12, ({"dex","wil","con"}),
				 "cooking"),
		"craft.dying":
				(<Skill> 18, ({"int","int","int"}),
				 "making dyes and paints"),
		"craft.farming":
				(<Skill> 10, ({"str","con","wil"}),
				 "farming"),
		"craft.gemcutting":
				(<Skill> 20, ({"dex","dex","emp"}),
				 "working with precious stones"),
		"craft.leatherworking":
				(<Skill> 15, ({"int","dex","dex"}),
				 "working with leather and hide"),
		"craft.masonry":
				(<Skill> 18, ({"str","con","int"}),
				 "laying bricks and stones"),
		"craft.mining":
				(<Skill> 15, ({"str","str","emp"}),
				 "digging for ore"),
		"craft.pottery":
				(<Skill> 15, ({"emp","emp","dex"}),
				 "throwing pots"),
		"craft.sewing":
				(<Skill> 15, ({"wil","dex","dex"}),
				 "working with cloth"),
		"craft.smithing":
				(<Skill> 0, ({ }),
				 "working with metals"),
			"craft.smithing.armour":
				(<Skill> 16, ({"cha","emp","con"}),
				 "making armour"),
			"craft.smithing.black":
				(<Skill> 15, ({"str","str","con"}),
				 "working in hard metals"),
			"craft.smithing.locks":
				(<Skill> 20, ({"int","emp","dex"}),
				 "making locks"),
			"craft.smithing.weapons":
				(<Skill> 16, ({"str","str","emp"}),
				 "making weapons"),
			"craft.smithing.white":
				(<Skill> 17, ({"dex","str","emp"}),
				 "working in soft metals"),
		"craft.tanning":
				(<Skill> 8, ({"con","con","int"}),
				 "making leather"),
		"craft.weaving":
				(<Skill> 16, ({"emp","dex","spd"}),
				 "weaving cloth"),
	// Knowledge
	"knowledge":
				(<Skill> 0, ({ }),
				 "knowledge of the world"),
		"knowledge.alchemy":
				(<Skill> 18, ({"int","int","cha"}),
				 "knowledge of potions"),
		"knowledge.arcana":
				(<Skill> 16, ({"int","int","cha"}),
				 "knowledge of magic"),
		"knowledge.architecture":
				(<Skill> 14, ({"int","int","emp"}),
				 "knowledge of architecture"),
		"knowledge.cryptography":
				(<Skill> 20, ({"int","int","emp"}),
				 "knowledge of codes and ciphers"),
		"knowledge.etiquette":
				(<Skill> 14, ({"int","cha","cha"}),
				 "knowledge of polite society"),
		"knowledge.evaluating":
				(<Skill> 0, ({ }),
				 "determining the worth of things"),
			"knowledge.evaluating.armour":
				(<Skill> 16, ({"int","int","emp"}),
				 "evaluating armour"),
			"knowledge.evaluating.weapons":
				(<Skill> 14, ({"int","int","str"}),
				 "evaluating weapons"),
		"knowledge.heraldry":
				(<Skill> 16, ({"int","int","cha"}),
				 "knowledge of heraldric symbols"),
		"knowledge.herbology":
				(<Skill> 16, ({"int","emp","cha"}),
				 "knowledge of useful herbs"),
		"knowledge.history":
			// each historical nation/culture
			// TODO: add non-human cultures as well
				(<Skill> 0, ({ }),
				 "knowledge of history"),
			"knowledge.history.asile":
				(<Skill> 10, ({"int","int","int"}),
				 "the history of Asile"),
			"knowledge.history.buamer":
				(<Skill> 10, ({"int","int","int"}),
				 "the history of Buamer"),
			"knowledge.history.cru":
				(<Skill> 10, ({"int","int","int"}),
				 "the history of Cru"),
			"knowledge.history.terador":
				(<Skill> 10, ({"int","int","int"}),
				 "the history of Terador"),
		"knowledge.language":
				(<Skill> 0, ({ }),
				 "knowledge of languages"),
			"knowledge.language.arcane":
				(<Skill> 0, ({ }),
				 "the language of magic"),
				// no spoken component
				"knowledge.language.arcane.written":
				(<Skill> 15, ({"int","int","int"}),
				 "written magical texts"),
			"knowledge.language.cant":
				(<Skill> 0, ({ }),
				 "the language of thieves"),
				"knowledge.language.cant.spoken":
				(<Skill> 12, ({"int","dex","dex"}),
				 "spoken thieves' cant"),
				// no written component
			"knowledge.language.common":
				(<Skill> 0, ({ }),
				 "the common tongue"),
				"knowledge.language.common.spoken":
				(<Skill> 10, ({"int","int","int"}),
				 "spoken common"),
				"knowledge.language.common.written":
				(<Skill> 10, ({"int","int","int"}),
				 "written common"),
			"knowledge.language.draconic":
				(<Skill> 0, ({ }),
				 "the language of dragons"),
				"knowledge.language.draconic.spoken":
				(<Skill> 18, ({"int","int","dex"}),
				 "spoken draconic"),
				"knowledge.language.draconic.written":
				(<Skill> 16, ({"int","int","int"}),
				 "written draconic"),
			"knowledge.language.dwarven":
				(<Skill> 0, ({ }),
				 "the dwarven language"),
				"knowledge.language.dwarven.spoken":
				(<Skill> 12, ({"int","int","int"}),
				 "spoken dwarven"),
				"knowledge.language.dwarven.written":
				(<Skill> 8, ({"int","int","int"}),
				 "written dwarven"),
			"knowledge.language.elven":
				(<Skill> 0, ({ }),
				 "the elven language"),
				"knowledge.language.elven.spoken":
				(<Skill> 8, ({"int","int","int"}),
				 "spoken elven"),
				"knowledge.language.elven.written":
				(<Skill> 16, ({"int","int","dex"}),
				 "written elven"),
			"knowledge.language.gnomish":
				(<Skill> 0, ({ }),
				 "the gnomish language"),
				"knowledge.language.gnomish.spoken":
				(<Skill> 9, ({"int","dex","cha"}),
				 "spoken gnomish"),
				// no written equivalent
			"knowledge.language.halfling":
				(<Skill> 0, ({ }),
				 "the halfling language"),
				"knowledge.language.halfling.spoken":
				(<Skill> 10, ({"int","int","int"}),
				 "spoken halfling"),
				"knowledge.language.halfling.written":
				(<Skill> 10, ({"int","int","int"}),
				 "written halfling"),
			"knowledge.language.mental":
				(<Skill> 20, ({"emp","emp","cha"}),
				 "the language of thoughts"),
			"knowledge.language.sign":
				(<Skill> 12, ({"dex","dex","cha"}),
				 "sign language"),
		"knowledge.navigation":
				(<Skill> 14, ({"int","int","int"}),
				 "knowledge of navigation"),
		"knowledge.science":
				(<Skill> 0, ({ }),
				 "sciences"),
			"knowledge.science.anthropology":
				(<Skill> 16, ({"int","int","emp"}),
				 "knowledge of ancient cultures"),
			"knowledge.science.astronomy":
				(<Skill> 15, ({"int","int","int"}),
				 "knowledge of the stars"),
			"knowledge.science.biology":
				(<Skill> 15, ({"int","int","emp"}),
				 "knowledge of animals"),
			"knowledge.science.botany":
				(<Skill> 17, ({"int","int","emp"}),
				 "knowledge of plants"),
			"knowledge.science.geology":
				(<Skill> 14, ({"int","int","int"}),
				 "knowledge of the earth"),
			"knowledge.science.mathematics":
				(<Skill> 15, ({"int","int","int"}),
				 "knowledge of numbers"),
		"knowledge.religion":
				(<Skill> 0, ({ }),
				 "knowledge of religion"),
	// Magic
	"magic":
				(<Skill> 0, ({ }),
				 "the art and science of twisting reality"),
		"magic.concentration":
				(<Skill> 20, ({"wil","wil","wil"}),
				 "keeping your focus"),
		"magic.intuition":
				(<Skill> 15, ({"emp","int","cha"}),
				 "recognizing spells"),
		"magic.item":
				(<Skill> 0, ({ }),
				 "using magical items"),
			"magic.item.misc":
				(<Skill> 18, ({"dex","emp","int"}),
				 "miscellaneous magical items"),
			"magic.item.scroll":
				(<Skill> 14, ({"int","int","dex"}),
				 "using written spells"),
			"magic.item.staff":
				(<Skill> 16, ({"dex","str","int"}),
				 "using magical staves"),
			"magic.item.talisman":
				(<Skill> 16, ({"dex","dex","emp"}),
				 "using magical talismans"),
			"magic.item.wand":
				(<Skill> 14, ({"int","int","dex"}),
				 "using magical wands"),
		"magic.faith":
				(<Skill> 0, ({ }),
				 "magic that depends on the gods"),
			"magic.faith.blessing":
				(<Skill> 15, ({"cha","cha","emp"}),
				 "granting blessings"),
			"magic.faith.devotion":
				(<Skill> 12, ({"con","cha","wil"}),
				 "devotion to the gods"),
			"magic.faith.healing":
				(<Skill> 15, ({"cha","emp","wil"}),
				 "healing magic"),
			"magic.faith.judgement":
				(<Skill> 17, ({"int","int","emp"}),
				 "imparting divine justice"),
			"magic.faith.prayer":
				// advanced prayers go here
				(<Skill> 0, ({ }),
				 "specific magical prayers"),
				// TODO: prayer skills go here
			"magic.faith.repentance":
				(<Skill> 18, ({"wil","wil","wil"}),
				 "correcting your errors"),
			"magic.faith.sacrifice":
				(<Skill> 18, ({"wil","wil","con"}),
				 "forgetting yourself"),
		"magic.mana":
				(<Skill> 0, ({ }),
				 "channeling mana"),
			"magic.mana.chaos":
				(<Skill> 20, ({"emp","int","con"}),
				 "using chaotic mana"),
			"magic.mana.dark":
				(<Skill> 18, ({"cha","cha","int"}),
				 "using darkness mana"),
			"magic.mana.earth":
				(<Skill> 12, ({"con","str","dex"}),
				 "using natural mana"),
			"magic.mana.lightning":
				(<Skill> 15, ({"int","spd","dex"}),
				 "using electrical mana"),
			"magic.mana.fire":
				(<Skill> 14, ({"int","int","dex"}),
				 "using fire mana"),
			"magic.mana.ice":
				(<Skill> 16, ({"int","con","dex"}),
				 "using ice mana"),
			"magic.mana.order":
				(<Skill> 18, ({"wil","wil","int"}),
				 "using order mana"),
			"magic.mana.spirit":
				(<Skill> 14, ({"int","emp","cha"}),
				 "using pure mana"),
			"magic.mana.water":
				(<Skill> 12, ({"emp","dex","spd"}),
				 "using water mana"),
			"magic.mana.wind":
				(<Skill> 14, ({"con","str","int"}),
				 "using wind mana"),
		"magic.meditation":
				(<Skill> 18, ({"emp","cha","int"}),
				 "meditation"),
		"magic.spell":
			// spell skills go here
				(<Skill> 0, ({ }),
				 "knowledge of individual spells"),
			// TODO: spell skills go here
			//       0th order - 10 difficulty
			//       1st order - 14 difficulty
			//       2nd order - 18 difficulty
			//       3rd order - 20 difficulty
		"magic.technique":
				(<Skill> 0, ({ }),
				 "special magical techniques"),
			"magic.technique.abjuring":
				(<Skill> 15, ({"str","wil","con"}),
				 "breaking existing magical effects"),
			"magic.technique.animating":
				(<Skill> 15, ({"dex","int","cha"}),
				 "infusing spirits into physical objects"),
			"magic.technique.binding":
				(<Skill> 15, ({"cha","emp","wil"}),
				 "coercing energies and spirits"),
			"magic.technique.brewing":
				(<Skill> 15, ({"dex","con","con"}),
				 "brewing magical potions"),
			"magic.technique.channeling":
				(<Skill> 15, ({"con","wil","int"}),
				 "directing mana flows"),
			"magic.technique.chanting":
				(<Skill> 15, ({"dex","int","cha"}),
				 "chanting spells"),
			"magic.technique.charming":
				(<Skill> 15, ({"cha","cha","cha"}),
				 "enhancing living things"),
			"magic.technique.conjuring":
				(<Skill> 15, ({"int","emp","str"}),
				 "creating objects with magic"),
			"magic.technique.cursing":
				(<Skill> 15, ({"wil","con","cha"}),
				 "laying curses"),
			"magic.technique.dancing":
				(<Skill> 15, ({"con","dex","dex"}),
				 "performing physical magic"),
			"magic.technique.divination":
				(<Skill> 15, ({"emp","emp","cha"}),
				 "communicating with spirits"),
			"magic.technique.enchanting":
				(<Skill> 15, ({"int","wil","dex"}),
				 "magically improving objects"),
			"magic.technique.evoking":
				(<Skill> 15, ({"str","int","wil"}),
				 "manifesting raw magical effects"),
			"magic.technique.necromancy":
				(<Skill> 15, ({"cha","cha","con"}),
				 "dealing with dark spirits"),
			"magic.technique.singing":
				(<Skill> 15, ({"cha","int","dex"}),
				 "performing musical magic"),
			"magic.technique.scribing":
				(<Skill> 15, ({"dex","dex","int"}),
				 "making scrolls"),
			"magic.technique.scrying":
				(<Skill> 15, ({"emp","int","int"}),
				 "far sight"),
			"magic.technique.warding":
				(<Skill> 15, ({"dex","str","int"}),
				 "making magical circles"),
	// Other
	"other":
				(<Skill> 0, ({ }),
				 "assorted other skills"),
		"other.acrobatics":
				(<Skill> 0, ({ }),
				 "acrobatic feats"),
			"other.acrobatics.balance":
				(<Skill> 0, ({"wil","dex","dex"}),
				 "maintaining balance"),
			"other.acrobatics.contortion":
				(<Skill> 15, ({"dex","dex","int"}),
				 "twisting your body"),
			"other.acrobatics.tumbling":
				(<Skill> 12, ({"dex","dex","str"}),
				 "controlling your falls"),
		"other.covert":
				(<Skill> 0, ({ }),
				 "sneaky stuff"),
			"other.covert.concealment":
				(<Skill> 14, ({"spd","dex","int"}),
				 "hiding objects"),
			"other.covert.disarming":
				(<Skill> 15, ({"spd","int","dex"}),
				 "disarming traps"),
			"other.covert.disguise":
				(<Skill> 13, ({"spd","int","wil"}),
				 "creating and using disguises"),
			"other.covert.forgery":
				(<Skill> 16, ({"int","int","dex"}),
				 "creating fake documents"),
			"other.covert.hiding":
				(<Skill> 13, ({"spd","dex","dex"}),
				 "remaining unseen"),
			"other.covert.manipulation":
				(<Skill> 14, ({"spd","cha","dex"}),
				 "manipulating objects"),
			"other.covert.stalking":
				(<Skill> 14, ({"spd","spd","dex"}),
				 "moving stealthily"),
			"other.covert.stealing":
				(<Skill> 15, ({"spd","spd","dex"}),
				 "reassigning ownership"),
		"other.dancing":
				(<Skill> 13, ({"cha","cha","dex"}),
				 "dancing"),
		"other.diplomacy":
				(<Skill> 14, ({"wil","int","cha"}),
				 "diplomacy"),
		"other.endurance":
				(<Skill> 20, ({"con","wil","wil"}),
				 "endurance"),
		"other.fishing":
				(<Skill> 12, ({"wil","dex","int"}),
				 "catching fish"),
		"other.haggling":
				(<Skill> 13, ({"cha","cha","wil"}),
				 "arguing prices"),
		"other.interrogation":
				(<Skill> 14, ({"wil","int","str"}),
				 "extracting answers"),
		"other.juggling":
				(<Skill> 11, ({"dex","dex","spd"}),
				 "juggling"),
		"other.medicine":
				(<Skill> 0, ({ }),
				 "medicine"),
			"other.medicine.first_aid":
				(<Skill> 14, ({"dex","int","int"}),
				 "basic injury treatment"),
			"other.medicine.holistic":
				(<Skill> 18, ({"wil","int","int"}),
				 "elven medicine"),
			"other.medicine.pharmacy":
				(<Skill> 15, ({"int","int","wil"}),
				 "mixing medicines"),
			"other.medicine.surgery":
				(<Skill> 17, ({"int","dex","dex"}),
				 "dwarven medicine"),
		"other.mentoring":
				(<Skill> 20, ({"emp","cha","cha"}),
				 "sharing experiences"),
		"other.movement":
				(<Skill> 0, ({ }),
				 "moving around"),
			"other.movement.climbing":
				(<Skill> 13, ({"dex","str","con"}),
				 "climbing"),
			"other.movement.jumping":
				(<Skill> 12, ({"dex","spd","con"}),
				 "jumping"),
			"other.movement.riding":
				(<Skill> 15, ({"emp","dex","wil"}),
				 "riding"),
			"other.movement.running":
				(<Skill> 11, ({"spd","spd","dex"}),
				 "running"),
			"other.movement.swimming":
				(<Skill> 12, ({"str","dex","con"}),
				 "swimming"),
		"other.music":
				(<Skill> 0, ({ }),
				 "music"),
			"other.music.drum":
				(<Skill> 12, ({"emp","dex","cha"}),
				 "playing drums"),
			"other.music.string":
				(<Skill> 12, ({"emp","dex","cha"}),
				 "playing string instruments"),
			"other.music.wind":
				(<Skill> 12, ({"emp","dex","cha"}),
				 "playing wind instruments"),
			"other.music.vocal":
				(<Skill> 13, ({"emp","emp","cha"}),
				 "singing"),
		"other.perception":
				(<Skill> 0, ({ }),
				 "noticing things"),
			"other.perception.aural":
				(<Skill> 12, ({"wil","wil","int"}),
				 "hearing things"),
			"other.perception.magical":
				(<Skill> 15, ({"int","int","emp"}),
				 "sensing magic"),
			"other.perception.spiritual":
				(<Skill> 18, ({"emp","emp","cha"}),
				 "sensing spirits"),
			"other.perception.visual":
				(<Skill> 12, ({"wil","wil","int"}),
				 "spotting things"),
		"other.survival":
				(<Skill> 0, ({ }),
				 "living off of the land"),
			"other.survival.desert":
				(<Skill> 15, ({"int","int","wil"}),
				 "desert survival"),
			"other.survival.forest":
				(<Skill> 10, ({"int","int","wil"}),
				 "forest survival"),
			"other.survival.mountain":
				(<Skill> 13, ({"int","int","wil"}),
				 "mountain survival"),
		"other.teaching":
			// subdivide somehow
			// base teaching skill - 13 - int, dex, cha
				(<Skill> 0, ({ }),
				 "teaching others"),
		"other.tracking":
				(<Skill> 13, ({"emp","wil","int"}),
				 "tracking prey"),
	]);

	debug("Help file generation in 2 seconds...");
	call_out("update_help_files", 2);

   return 1;
}

void update_help_files() {
	catch( "/help/skill/generator"->do_it() );
}

int skill_exists(string skill) {
   debug( "Should use query_skill_exists, not skill_exists (naming convention, poor usage is in " + as_string(previous_object()) + ")" );
   return member(skill_map,skill);
}

int query_skill_exists(string skill) {
   return member(skill_map,skill);
}

string query_skill_description(string skill) {
   return skill_map[skill]->desc;
}

string query_skill_help_description(string skill) {
   return skill_map[skill]->help_desc;
}

int query_skill_difficulty(string skill) {
   return skill_map[skill]->difficulty;
}

string* query_skill_stats(string skill) {
   return skill_map[skill]->stats;
}

string *query_skills() {
    string *list = ({}), tmp;
    foreach( tmp : m_indices(skill_map) ) {
		if( query_skill_difficulty(tmp) )
			list += ({tmp});
	}
	return sort_array(list,#'>);
}

/** multiply by stat modifier bonus thing for actual bonus
 * bonus increases by 5 every level for the first 5 levels, by 4 for the next 10,
 * by 3 for the next 10, by 2 for the next 10, and by 1 from then on out.
 *
 * L1  = 5    L30 = 120   L60 = 160   L90  = 190
 * L10 = 50   L40 = 140   L70 = 170   L100 = 200
 * L20 = 90   L50 = 150   L80 = 180   L150 = 250
 */
int query_base_skill_bonus(int level) {
   if (level <= 10)
      return 5 * level;
   else if (level <= 20)
      return 50 + 4*(level-10);
   else if (level <= 30)
      return 90 + 3*(level-20);
   else if (level <= 40)
      return 120 + 2*(level-30);
   else
      return 140 + (level-40);
}

/** multiply by base bonus for actual bonus
 * stats all count equally, so a skill that depends on str and dex would
 * calculate the bonus based on the average of str and dex.
 *
 * 5  = 0.666   12 = 1.133   16 = 1.400   20 = 1.666
 * 10 = 1.000   14 = 1.266   18 = 1.533   25 = 2.000
 */
float query_stat_skill_bonus(int *stat) {
   float x = 0.0;
   int k;
   foreach (k : stat)
      x += (float)k;
   x /= (float)sizeof(stat);
   return x/15.0 + 1.0/3.0;
}

string query_skill_string(int bonus) {
   if (bonus <= 1)
      return "unskilled";
   switch ((bonus / 10)) {
      case 0: return "very bad";
      case 1: return "bad";
      case 2: return "poor";
      case 3: return "fairly poor";
      case 4: return "fair";
      case 5: return "adequate";
      case 6: return "good";
      case 7: return "very good";
      case 8: return "excellent";
      case 9: return "superb";
      default: return "grandmaster";
   }
   return "error";
}

/// filter used by query_skill_name()
int skill_filter(string str,string key,int x) {
	string *arr = explode(str,".");
	if( sizeof(arr) > x ) {
		str = arr[x];
		return (str[0..strlen(key)-1] == key);
	} else {
		return 0;
	}
}

/// \return The canonical name of an abbreviated skill given
string query_skill_name(string abbr) {
	string *list = m_indices(skill_map);
	string *keys = explode(abbr,".");
	int x;
	for( x = 0; x < sizeof(keys); x++ )
		list = filter(list,#'skill_filter,keys[x],x);
	if( sizeof(list) )
		return list[0];
	else
		return 0;
}
