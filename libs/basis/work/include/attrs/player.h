// player_attrs.h
// owns attribs 650-689
//
// This file defines attributes used by all players in an AD&D setting.
// It uses the 2nd edition rules, and the optional non-weapon proficiencies
// therein.
// Both of these are mappings where the key is the proficiency name
// and the value is an the person's ability score.
#define a_weapon_proficiency 650
#define a_non_weapon_proficiency 651
// The THAC0 is the number needed "To Hit Armor Class 0".  The number
// needed to hit another AC is computed by subtracting the AC from
// the THAC0.  Wether a hit occurs or not is determined if a random
// number between 1 and 20 (traditionally from a die roll) is equal
// to or above the computed number.  If using the THAC0 attribute, please
// note that it is a_thac0, and not a_thaco.
#define a_thac0 652
// A player character in AD&D has six stats which determine his strength,
// intelligence and so forth.  The total possible range is from 1 to 25,
// although most adventurers haves attributes in the 3-18 range unless
// they have been magically altered.  The average value for each attribute
// for normal humans is 9 or 10.
#define a_strength 653
#define a_dexterity 654
#define a_constitution 655
#define a_intelligence 656
#define a_wisdom 657
#define a_charisma 658
// A player character in AD&D has a sort of profession - the things they
// do best.  This is called their class.  Normal options include
// fighter, cleric, mage, and thief.  AD&D 2nd edition allows for some
// specialties in each class, for example a fighter could be a paladin,
// or a ranger.  There are also "kits", which allow you a player to
// personalize their character a bit more, and give them options not
// normally available to the standard character classes.  The a_class
// attribute is an array of strings of the form "major_class:sub_class:kit".
// The "sub_class" and "kit" string can be blank, but the colons are
// required.  If a sub-class or kit is given, it must be different
// than the main one, e.g. no strings like "fight:fighter:fighter".
// The class names are: "warrior" (subclasses - "fighter", "paladin", and
// "ranger"), "wizard" (subclasses - "mage", "abjurer", "conjurer",
// "diviner", "enchanter", "illusionist", "invoker", "necromancer",
// "transmuter"), "priest" (subclasses - "cleric" and "druid"), and "rogue"
// (subclasses - "thief" and "bard").  If the character is multi-classed,
// the a_class attribute will be an array of strings of the above format,
// otherwise, it's an array of one string.
// Note that official rules say one cannot be multi-classed and still use
// a kit.
#define a_class 659
// Every character has an alignment, a way he/she looks at the world
// and how they act on it.  Alignment has two components in AD&D, law vs.
// chaos, and good vs. evil.  The persons position on law vs. chaos deals
// with how they view authority, laws, and cooperation.  Thus a lawful
// person will obey all laws even if they don't like them.  People with
// a neutral stand on law vs. chaos will break laws generally only if they
// can get away with it, and even then not very often.  A chaotic person
// will break laws on a whim, although if they are intelligent enough,
// only when they can't get caught (or punished).  The definition of
// good vs. evil is the standard definition.  A good person will try
// to save a girl trapped in a fire.  A neutral person would only do it
// if they could without being harmed.  An evil person would do it only
// if they saw profit in it for themself.  Thusly (I love that word ;),
// there are nine possible alignments: lawful good, neutral good, chaotic
// good, lawful neutral, true neutral, chaotic neutral, lawful evil,
// neutral evil, and chaotic evil.  The alignment attribute will be
// an array of value of the two components, first law vs. chaos, and then
// good vs. evil.  The scale will be such that -500 or less means chaotic,
// -499 to 499 means neutral, and 500 or more means lawful on the law vs.
// chaos component.  The same numbers will apply to evil, neutral, and
// good respectively on the good vs. evil component.  When players create
// their characters, they will start with -1000, 0, or 1000 in each
// component dependent on which alignment they choose.  When they perform
// actions that lean heavily to one direction or the other, their
// scores will change, and they could change alignments by this process.
// Alignment changes can have heavy consequences, especially to clerics or
// priests, as their deity might be very strict on such matters.
// Alignment changes, however, should be very slow to occur, and few
// actions should make much change at all.
// Any questions? ;)
#define a_alignment 660
// Every character in the game is assumed to speak the common language
// of whatever world they're on.  This language is conveniently called
// "common".  Many characters, however, can speak other languages, and
// many monsters speak thier own language.  Non-human characters
// generally speak their own language in addition to common.  Characters
// can also learn other languages if they can find a teacher for it.
// Non-human characters know their own language automatically, but
// for any characters to learn another language, they must spend a non-
// weapon proficiency slot (each character has a limited number of
// slots, which determine how many skills they can learn), after they
// find a teacher, of course.  Players can skip the teacher part if
// they create the character already knowing a language (it's assumed
// they found one).  Players should not be able to learn very unusual
// languages (like red dragon-speak) when they are created though.
// The number of languages that a person can learn is limited by their
// intelligence as well as proficiency slots.  The a_language attribute
// is an array of strings (lowercase), naming the laguages they can speak.
// Included in languages (though not an official language) is a "sign
// language" used mostly by the drow (evil elves - very nasty people).
// All languages should be listed here with thier official name, so
// nobody uses the wrong thing, e.g. "elven" instead of "elvish", etc.
// For simplicity, languages of a specific race will just be called
// bye the race's name, "elf" for example.
// Languages: "elf", "dwarf", "gnome", "halfling", "common", "goblin",
//   "orc", "hobgoblin", "gnoll", "kobold", "dragon" (dragons, I believe
//   speak one common language, and then each specific type has it's own
//   "sub-language", e.g. "red dragon", but I won't list them all).
// If you have any more, please add them (or mail to me to add them).
#define a_languages 661
#define a_hit_points 662
#define a_max_hit_points 663
#define a_experience 664
// Certain limits have to be enforced on what a player can wear, hold, etc.
// For one, players can only hold one thing in each hand, and some things
// need to be held in two hands (2-handed weapons and extremely large
// objects, for example).  The other places of concern are: the head
// (helmets and crowns), the feet (boots), the body (armor), gloves
// (or gauntlets), the neck (necklaces/amulets), the waist (belts).
// There is also a limit on things (rings) that can be worn on finger,
// but we won't worry about it.
// Thus, the a_carry_at attribute will be an array of 8 objects.
// The first two are objects help in the hands, primary hand first.
// The rest will be: head, feet, body, gloves, neck, waist.  One
// note though: the 4th member (feet) may also be an array of
// two objects in the unusal case that the there are 2 seperate objects
// worn - one to a foot.
#define a_carry_at 665
// Also, players are limited to wearing only 2 magical rings, 1 neck
// piece/necklace/amulet, 1 set of boots, and 1 set of gloves.
// Thus, a_magic_items will be an 5 element array of strings in that
// order saying what they're wearing.
#define a_magic_items 666
// Sometimes characters get in deep trouble, like get stung by a poisonous
// monster, get breathed on by a dragon, that sort of thing.  To help
// keep them alive, they're allowed to make saving throws, which give them
// a chance to resist the damage, dodge the shot, etc.  They have to roll
// higher than their modified saving throw number to do this.  The base
// number is defined by class and level.  Modifiers usually come from
// magic items, high wisdom, and a few other things.  The attribute
// a_saving_throws is an array of 6 things: the first five are the base
// saving throw numbers for paralyzation/poison/death magic, rod/staff/wand,
// petrification/polymorph, breath weapon, and spell.  The 6th member is
// a mapping where the keys are objects, and the values are functions in
// those objects that will return modifiers to a saving throw.  So if
// you have an object that modifies a saving throw, you should add it
// to this array.  The function will be called with a value from one to
// five corresponding to the order of saving throws above.  The interface
// to this may need some work, as sometimes you need more info than just
// what type of saving throw it is to determine the modifier, for example,
// some objects give bonuses to anything having to do with fire.  I'll
// look at this later.
#define a_saving_throws 667
// Of course, money is as important in AD&D as in the real world
// (relatively speaking).  The attribute a_money is an array of numbers
// of each type of coin available in AD&D.  The types are: "platinum",
// "gold", "electrum", "silver", and "copper".  1 platinum coin (PP) is
// worth 5 gold peices (GP), 1 GP is worth 2 electrum (EP), 1 EP is worth
// 5 silver coins (SP), and 1 SP is worth 10 copper (CP).
// The a_money attribute is an array in that order.
#define a_money 668
// Of course, every character has a race.  The most common creature
// in the campaign world should be human, but usually there is a very
// high ratio of elves when considering player characters.  The
// a_race attribute defines which one the player is.  To avoid
// confusion, only the types listed below are to be used.
// Races: "human", "elf", "dwarf", "gnome", "halfling", "half-elf".
// Non-player characters (monsters or NPCs) should have a race attribute
// set the same way (singular, lower-case).
#define a_race 669
// Every character has a level that defines how experienced a player is
// in their main class.  The level determines the players hit points,
// THAC0, saving throws, and some other stuff.  The players level
// is determined by the amount of experience, although it can be
// altered in special cases (e.g. undead monsters can drain levels -
// nasty, huh?).  To allow for multi-classed characters, the a_level
// attribute is an array of integers.  Single classes characters,
// of course, have only one member in that array, double-classed
// characters have two memebers, etc.
#define a_level 670
// Every character class has some special abilities.  Some, like the
// fighters, are just very good fighting and special weapon proficiencies.
// Others, like spell casting need to be kept track of.  The
// a_special_abilities attribute keeps track of these.  It is an array, but
// the form is dictated by class.  The structure of this will be detailed
// later (when I decide how I want to do it).
#define a_special_ability 671
