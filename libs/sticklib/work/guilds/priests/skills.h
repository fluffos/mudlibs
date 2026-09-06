#define N_SKILLS 16

#define FIRST_SKILL 0
#define LAST_SKILL 15
#define FIRST_P_SKILL 0
#define LAST_P_SKILL 6
#define FIRST_A_SKILL 7
#define LAST_A_SKILL 15

#define SK_SERENITY 0 // ability to focus your mind
#define SK_LIFE 1 // knowledge of living beings
#define SK_NATURE 2 // knowledge of non-living things found in nature
#define SK_SPIRITS 3 // knowledge of "supernatural" beings
#define SK_FORCES 4 // knowledge of supernatural forces (non "living")
#define SK_ALCHEMY 5 // alchemy base skill
#define SK_STAFF 6 // fighting skill (with staff or other blunt weapon)

// potion skills
#define SK_LES_RES 7 // lesser restore mana
#define SK_GRE_RES 8 // greater restore mana
#define SK_HEAL_MIN 9 // heal minor wounds
#define SK_HEAL_MAJ 10 // heal major wounds
#define SK_INVIS 11 // invisibility
#define SK_INVULN 12 // invulnerability
#define SK_NEUTRL_POISON 13 // neutralize poison
#define SK_STUN_RES 14
#define SK_POISON 15

#define SKILL_NAMES ({ \
   "Serenity", \
   "Knowledge of Life", \
   "Knowledge of Nature", \
   "Spiritus", \
   "Way of the Force", \
   "Alchemy", \
   "Staff Mastery", \
   "Lesser Restore Mana", \
   "Greater Restore Mana", \
   "Heal Minor Wounds", \
   "Heal Major Wounds", \
   "Invisibility", \
   "Invulnerability", \
   "Neutralize Poison", \
    "Stun Resistance", \
   "Poison", \
})

#define ORDER_BONUSES ({ \
   0,20,40,-20,-40,10,-10, \
   0,0,0,0,0,0,0,0,0,0, \
})
// alchemy skills don't have any order bonuses... atm

/*
#define SKILL_RANKS ({ "pathetic", "bad", "poor", "average", \
    "moderate", "rather good", "good", "excellent", "superb", \
    "masterly", "perfect", "godly" })
*/

#define SKILL_RANKS ({"paltry", "ridiculous", "pathetic", "feeble", "meager", \
"bad", "poor", "crude", "average", "moderate", "rather good", "pretty good", \
"good", "respectable", "great", "excellent", "superb", "masterly","perfect", \
"supreme", "legendary", "fabled", "unearthly", "godly" })

// The amount of pex needed to get a "50% skill"
#define AVERAGE_COST 1500.0
// Amount of pexes needed to get a "bad" skill
// #define BASE_COST (3*AVERAGE_COST/16)
#define BASE_COST 93.75
#define PRIEST_TUNE 10
#define MAX_SKILL_RANK 23
