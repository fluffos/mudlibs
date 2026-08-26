// This is a bunch of odds and ends that have to do with spellcasting
// as we know it...


// These are the magic radiance levels...
#define DIM 1
#define FAINT 2
#define MODERATE 3
#define STRONG 4
#define OVERWHELMING 5

// Applicable casting classes/sub-classes
#define MAGE_TYPES ({ "wizard", "bard", "dragon" })
#define PRIEST_TYPES ({ "priest", "ranger", "paladin" })

// These are the spellcasting return types. Generally, they're only
// useful for objects and shit.
#define SAVED -4
#define MAGIC_RESISTANCE -3
#define INVALID_TARGET -2
#define NO_STRENGTH -1
#define NO_TARGET 0
#define SPELL_CAST 1

// If this is set, spells have maximums.
#define MAX_TO_SPELLS 1

// This is the standard multiplier
// Right now its set to x2.33. 
#define SPELL_MULT(x) (x)
