// This define all the skills, and who gets what.

// This section lists all the weapon skills known. They are set up
// as a macro so that we can give all of the to a class at any
// level we like.

#define SKS_WP_MODERN(XX) ([ "Small Arms":XX, "Long Arms" : XX,     \
    "Machine Weapons":XX, "Heavy Weapons":XX ])
#define SKS_WP_ANCIENT(XX) ([ "Long Blades":XX, "Short Blades":XX,  \
    "Axes":XX , "Staves":XX, "Whips":XX , "Clubbing Weapons":XX,    \
    "Polearms":XX, "Unarmed":XX ])
#define SKS_WP_STYLES(XX) ([ "One Weapon Style":XX, "Shield Style"  \
    : XX , "Two Handed Style":XX, "Two Weapon Style":XX ])


// This section defines all the non-weapon skills a player may
// learn.
#define SK_GENERAL ([ "Animal Lore":1 , "Awareness":2 ,     \
    "Monster Lore":1 , "Demon Lore":2 , "Undead Lore":2,    \
    "Writing":1 , "Signature Item":2, "Tracking":2 ])
#define SK_FIGHTER ([ "Ambidexterity":1, "Blind Fighting" : 2,      \
    "Iron Will":2, "All Around Attack":1 , "Death Blow":2 ])
#define SK_CLERIC ([ "Healing":2, "Iron Will":2,            \
    "Eminence":1 , "Loan Health":1 , 		                \
    "Talisman":2 , "Smite":2 ])
#define SK_MAGE ([ "Arcanology" : 1, "Herbalism":2,         \
    "Thaumaturgy":1 , "Talisman":2, "Signature Spell":2,    \
    "Spellcraft" : 2 ])
#define SK_THIEF ([ "Ambidexterity":1 , "Blind Fighting":2 ,\
    "Read Lips":2 , "Ventriloquism":1 , "Evasion":1 , 		\
    "Nondetection":2 ])

// This section defines who gets what weapon skills.
#define SK_WP_DRAGON ([ "Unarmed" : 5 ])   
#define SK_WP_MAGE ([ "Short Blades":2 , "Staves":2 , "Whips":2 ,   \
    "Ambidexterity":1 , "One Weapon Style":2, "Two Handed Style":2  \
    ])
#define SK_WP_CLERIC ([ "Staves":2, "Whips":2, "Unarmed":2,         \
    "Clubbing Weapons":2, "Polearms":2, "Ambidexterity":1 ,         \
    "Shield Style" : 2, "Two Handed Style":2 , "One Weapon Style":2 \
    ])
#define SK_WP_THIEF ([ "Small Arms":2, "Long Arms":2,               \
    "Long Blades":2 , "Short Blades":2 , "Axes":2 , "Whips":2 ,     \
    "Clubbing Weapons":2, "Ambidexterity":1 , "One Weapon Style":2, \
    "Two Weapon Style":2 ]) 
#define SK_WP_ASSASSIN SK_WP_THIEF + ([ "Long Blades" : 3 ])
#define SK_WP_FIGHTER SKS_WP_MODERN(5) + SKS_WP_ANCIENT(5) +        \
    SKS_WP_STYLES(5) + ([ "Ambidexterity":1 ])
#define SK_WP_BARBARIAN SKS_WP_ANCIENT(4) + SKS_WP_STYLES(2) +      \
    ([ "Ambidexterity":1  ])
#define SK_WP_KNIGHT ([ "Long Blades":4, "Short Blades":3 ,         \
    "Axes":3 , "Staves":3 , "Unarmed":3, "Whips":3 , 		        \
    "Clubbing Weapons":4, "Polearms":5 , "Ambidexterity":1 ,        \
    "One Weapon Style":2 , "Shield Style":2 , 				        \
    "Two Handed Style":2 , "Two Weapon Style":2 ])
#define SK_WP_PSIONIC ([ "Small Arms" : 2, "Short Blades":2 ,       \
    "Axes":2 , "Whips" : 2, "Ambidexterity":1 ])
#define SK_WP_BARD ([ "Long Blades":3, "Short Blades":3, "Staves":3,\
    "One Weapon Style":2, "Ambidexterity":2, "Axes":2, "Whips":2,   \
    "Clubbing Weapons":2, "Polearms":2, "Two Weapon Style":2 ])
