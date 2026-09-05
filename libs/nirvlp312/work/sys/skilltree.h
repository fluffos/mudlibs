/* ~Skills/inc/skilltree.h
 * The new skill tree, Skills Domain
 */

#ifndef _sys_skilltree_h
#define _sys_skilltree_h

#define S_PHYSICAL              "physical"
#define S_P_ART                 "physical|art"
#define S_P_GAMBLE              "physical|art|gamble"
#define S_P_MAGIC               "physical|art|magic"
#define S_MAGIC_CERNATUR        "physical|art|magic|cernatur"
#define S_MAGIC_FIAT            "physical|art|magic|fiat"
#define S_MAGIC_MUTETUR         "physical|art|magic|mutetur"
#define S_MAGIC_OBSEQUATUR      "physical|art|magic|obsequatur"
#define S_MAGIC_PEREAT          "physical|art|magic|pereat"
#define S_P_MUSIC               "physical|art|music"
#define S_P_DANCE               "physical|art|music|dance"
#define S_P_PLAY                "physical|art|music|play"
#define S_P_PLAY_BRASS          "physical|art|music|play|brass"
#define S_P_PLAY_DRUM           "physical|art|music|play|drum"
#define S_P_PLAY_FLUTE          "physical|art|music|play|flute"
#define S_P_PLAY_KEYBOARD       "physical|art|music|play|keyboard"
#define S_P_PLAY_PLUCK          "physical|art|music|play|pluck"
#define S_P_PLAY_STRINGED       "physical|art|music|play|stringed"
#define S_P_SING                "physical|art|music|sing"
#define S_P_STEALTH             "physical|art|stealth"
#define S_P_CAMOUFLAGE          "physical|art|stealth|camouflage"
#define S_P_DISGUISE            "physical|art|stealth|disguise"
#define S_P_HIDE                "physical|art|stealth|hide"
#define S_P_PICK_POCKET         "physical|art|stealth|pick_pocket"
#define S_P_SNEAK               "physical|art|stealth|sneak"
#define S_P_WRITE               "physical|art|write"
#define S_ATHLETICS             "physical|athletics"
#define S_ACROBATICS            "physical|athletics|acrobatics"
#define S_JUGGLE                "physical|athletics|acrobatics|juggle"
#define S_AMBIDEXTROUS          "physical|athletics|ambidextrous"
#define S_CLIMB                 "physical|athletics|climb"
#define S_JUMP                  "physical|athletics|jump"
#define S_RIDE                  "physical|athletics|ride"
#define S_SWIM                  "physical|athletics|swim"
#define S_THROW                 "physical|athletics|throw"
#define S_P_COMBAT              "physical|combat"
#define S_P_COMBAT_CLOSE        "physical|combat|close"
#define S_P_BRAWL               "physical|combat|close|brawl"
#define S_P_KICK                "physical|combat|close|brawl|kick"
#define S_P_PUNCH               "physical|combat|close|brawl|punch"
#define S_P_COMBAT_ONEHANDED    "physical|combat|close|onehanded"
#define S_P_BASH                "physical|combat|close|onehanded|bash"
#define S_P_LASH                "physical|combat|close|onehanded|lash"
#define S_P_SLASH               "physical|combat|close|onehanded|slash"
#define S_P_STAB                "physical|combat|close|onehanded|stab"
#define S_P_SWING               "physical|combat|close|onehanded|swing"
#define S_P_THRUST              "physical|combat|close|onehanded|thrust"
#define S_P_COMBAT_TWOHANDED    "physical|combat|close|twohanded"
#define S_P_TWOHANDED_BASH      "physical|combat|close|twohanded|bash"
#define S_P_TWOHANDED_SLASH     "physical|combat|close|twohanded|slash"
#define S_P_TWOHANDED_SWING     "physical|combat|close|twohanded|swing"
#define S_P_TWOHANDED_THRUST    "physical|combat|close|twohanded|thrust"
#define S_P_HARD_MARTIAL_ART    "physical|combat|close|martial_art|hard"
#define S_P_SOFT_MARTIAL_ART    "physical|combat|close|martial_art|soft"
#define S_P_DODGE               "physical|combat|dodge"
#define S_P_DODGE_CLOSE         "physical|combat|dodge|close"
#define S_P_DODGE_BRAWL         "physical|combat|dodge|close|brawl"
#define S_P_DODGE_WEAPON        "physical|combat|dodge|close|weapon"
#define S_P_DODGE_RANGE         "physical|combat|dodge|range"
#define S_P_PARRY               "physical|combat|parry"
#define S_P_PARRY_CLOSE         "physical|combat|parry|close"
#define S_P_PARRY_ARMED         "physical|combat|parry|close|armed"
#define S_P_PARRY_ARMED_BRAWL   "physical|combat|parry|close|armed|brawl"
#define S_P_PARRY_WEAPON        "physical|combat|parry|close|armed|weapon"
#define S_P_PARRY_UNARMED       "physical|combat|parry|close|unarmed"
#define S_P_PARRY_BRAWL         "physical|combat|parry|close|unarmed|brawl"
#define S_P_PARRY_UNARMED_WEAPON  "physical|combat|parry|close|unarmed|weapon"
#define S_P_PARRY_RANGE         "physical|combat|parry|range"
#define S_P_PARRY_RANGE_ARMED   "physical|combat|parry|range|armed"
#define S_P_PARRY_RANGE_UNARMED "physical|combat|parry|range|unarmed"
#define S_P_COMBAT_RANGE        "physical|combat|range"
#define S_P_SHOOT               "physical|combat|range|shoot"
#define S_P_SHOOT_FORCED        "physical|combat|range|shoot|forced"
#define S_P_SHOOT_UNFORCED      "physical|combat|range|shoot|unforced"
#define S_P_SLING               "physical|combat|range|sling"
#define S_P_THROW               "physical|combat|range|throw"
#define S_P_CRAFT               "physical|craft"
#define S_P_BREW                "physical|craft|brew"
#define S_P_COOK                "physical|craft|cook"
#define S_P_DISTIL              "physical|craft|distil"
#define S_P_PICK_LOCK           "physical|craft|pick_lock"
#define S_P_FIND_TRAPS          "physical|craft|find_traps"
#define S_P_SET_TRAPS           "physical|craft|set_traps"
#define S_P_CARPENTER           "physical|craft|carpenter"
#define S_P_SMITH               "physical|craft|smith"
#define S_P_TAILOR              "physical|craft|tailor"
#define S_P_FISH                "physical|craft|fish"
#define S_MENTAL                "mental"
#define S_M_COMBAT              "mental|combat"
#define S_M_BACKSTAB            "mental|combat|backstab"
#define S_M_BLIND_FIGHT         "mental|combat|blind_fight"
#define S_M_CLOSE               "mental|combat|close"
#define S_M_ARMED               "mental|combat|close|armed"
#define S_M_BRAWL               "mental|combat|close|brawl"
#define S_M_HARD_MARTIAL_ART    "mental|combat|close|martial_art|hard"
#define S_M_SOFT_MARTIAL_ART    "mental|combat|close|martial_art|soft"
#define S_M_DODGE               "mental|combat|dodge"
#define S_M_KILL                "mental|combat|kill"
#define S_M_PARRY               "mental|combat|parry"
#define S_M_RANGE               "mental|combat|range"
#define S_M_SHOOT               "mental|combat|range|shoot"
#define S_M_SLING               "mental|combat|range|sling"
#define S_M_THROW               "mental|combat|range|throw"
#define S_M_CRAFT               "mental|craft"
#define S_M_GAMBLE              "mental|craft|gamble"
#define S_M_STEALTH             "mental|craft|stealth"
#define S_M_DISGUISE            "mental|craft|stealth|disguise"
#define S_M_PICK_LOCK           "mental|craft|stealth|pick_lock"
#define S_M_SEDUCTION           "mental|craft|stealth|seduction"
#define S_M_FIND_TRAPS          "mental|craft|stealth|find_traps"
#define S_M_SET_TRAPS           "mental|craft|stealth|set_traps"
#define S_M_TRADE               "mental|craft|trade"
#define S_M_APPRAISE            "mental|craft|trade|appraise"
#define S_M_BARGAIN             "mental|craft|trade|bargain"
#define S_ESTIMATE              "mental|estimate"
#define S_ESTIMATE_ITEM         "mental|estimate|item"
#define S_ESTIMATE_VALUE        "mental|estimate|item|value"
#define S_ESTIMATE_ARMOR       "mental|estimate|item|armor"
#define S_ESTIMATE_WEAPON       "mental|estimate|item|weapon"
#define S_ESTIMATE_LIVING       "mental|estimate|living"
#define S_ESTIMATE_EQUIPMENT    "mental|estimate|living|equipment"
#define S_ESTIMATE_HEALTH       "mental|estimate|living|health"
#define S_ESTIMATE_SKILLS       "mental|estimate|living|skills"
#define S_ESTIMATE_STATS        "mental|estimate|living|stats"
#define S_LORE                  "mental|lore"
#define S_HERALDRY              "mental|lore|heraldry"
#define S_M_MAGIC               "mental|lore|magic"
#define S_MAGIC_AER             "mental|lore|magic|aer"
#define S_MAGIC_ANIMAL          "mental|lore|magic|animal"
#define S_MAGIC_AQUA            "mental|lore|magic|aqua"
#define S_MAGIC_CORPUS          "mental|lore|magic|corpus"
#define S_MAGIC_HERBA           "mental|lore|magic|herba"
#define S_MAGIC_IGNIS           "mental|lore|magic|ignis"
#define S_MAGIC_IMAGO           "mental|lore|magic|imago"
#define S_MAGIC_MENS            "mental|lore|magic|mens"
#define S_MAGIC_MORTUS          "mental|lore|magic|mortus"
#define S_MAGIC_TERRA           "mental|lore|magic|terra"
#define S_MAGIC_VIS             "mental|lore|magic|vis"
#define S_MECHANICS             "mental|lore|mechanics"
#define S_M_MEDICAL             "mental|lore|medical"
#define S_M_FIRST_AID           "mental|lore|medical|first_aid"
#define S_M_HERBALISM           "mental|lore|medical|herbalism"
#define S_M_MEDICINE            "mental|lore|medical|medicine"
#define S_M_MUSIC               "mental|lore|music"
#define S_PHONETIC              "mental|lore|phonetic"
#define S_COMMON                "mental|lore|phonetic|common"
#define S_DRACONIAN             "mental|lore|phonetic|draconian"
#define S_LIZTONGUE             "mental|lore|phonetic|liztongue"
#define S_ORCISH                "mental|lore|phonetic|orcish"
#define S_READ                  "mental|lore|read"
#define S_READ_COMMON           "mental|lore|read|common"
#define S_M_WRITE               "mental|lore|write"
#define S_M_WRITE_COMMON        "mental|lore|write|common"
#define S_TEACH                 "mental|lore|teach"
#define S_TRACK                 "mental|lore|track"
#define S_SENSE                 "mental|sense"
#define S_BALANCE               "mental|sense|balance"
#define S_FEEL                  "mental|sense|feel"
#define S_HEAR                  "mental|sense|hear"
#define S_SEARCH                "mental|sense|search"
#define S_SEE                   "mental|sense|see"
#define S_SMELL                 "mental|sense|smell"
#define S_TASTE                 "mental|sense|taste"
// the following are still in the making
#define S_SOCIAL                "social"
#define S_EMPATHY               "social|empathy"
#define S_BANTER                "social|empathy|banter"
#define S_CHARM                 "social|empathy|charm"
#define S_COMFORT               "social|empathy|comfort"
#define S_LISTEN                "social|empathy|listen"
#define S_TEASE                 "social|empathy|tease"
#define S_MANIPULATE            "social|manipulate"
#define S_BARGAIN               "social|manipulate|bargain"
#define S_FAST_TALK             "social|manipulate|fast_talk"
#define S_INTIMIDATE            "social|manipulate|intimidate"
#define S_LEADERSHIP            "social|manipulate|leadership"
#define S_PERSUADE              "social|manipulate|persuade"
#define S_SEDUCE                "social|manipulate|seduce"
#define S_SUBTERFUGE            "social|manipulate|subterfuge"
// other things to be thought of:
// sciences (alchemy, botany etc.)
// paranormal lores (occultism, soothsaying)
// uncommon arts (mathematics, conjuring, philosophy)

#define VALID_SKILLS ({ \
S_PHYSICAL, S_P_ART, S_P_CRAFT, S_ATHLETICS, S_ACROBATICS, S_JUGGLE, \
S_AMBIDEXTROUS, S_CLIMB, S_JUMP, S_RIDE, S_SWIM, S_THROW, S_P_COMBAT, \
S_P_COMBAT_CLOSE, S_P_BRAWL, S_P_PUNCH, S_P_KICK, S_P_DODGE, S_P_PARRY, \
S_P_HARD_MARTIAL_ART, S_P_SOFT_MARTIAL_ART, S_P_COMBAT_ONEHANDED, S_P_BASH, \
S_P_STAB, S_P_LASH, S_P_SLASH, S_P_SWING, S_P_THRUST, S_P_COMBAT_TWOHANDED, \
S_P_TWOHANDED_BASH, S_P_TWOHANDED_SLASH, S_P_TWOHANDED_SWING, \
S_P_TWOHANDED_THRUST, S_P_COMBAT_RANGE, S_P_SHOOT, S_P_SHOOT_FORCED, \
S_P_SHOOT_UNFORCED, S_P_SLING, S_P_THROW, S_P_BREW, S_P_COOK, S_P_DISTIL, \
S_P_PICK_LOCK, S_P_FIND_TRAPS, S_P_SET_TRAPS, S_P_CARPENTER, S_P_SMITH, \
S_P_TAILOR, S_P_MUSIC, S_P_DANCE, S_P_PLAY, S_P_PLAY_BRASS, S_P_PLAY_DRUM, \
S_P_PLAY_FLUTE, S_P_PLAY_KEYBOARD, S_P_PLAY_PLUCK, S_P_PLAY_STRINGED, \
S_P_SING, S_P_STEALTH, S_P_CAMOUFLAGE, S_P_DISGUISE, S_P_HIDE, \
S_P_PICK_POCKET, S_P_SNEAK, S_P_FISH, S_P_GAMBLE, S_MENTAL, S_M_CRAFT, \
S_M_COMBAT, S_M_BACKSTAB, S_M_BLIND_FIGHT, S_M_CLOSE, S_M_ARMED, S_M_BRAWL, \
S_M_HARD_MARTIAL_ART, S_M_SOFT_MARTIAL_ART, S_M_KILL, S_M_RANGE, S_M_SHOOT, \
S_M_SLING, S_M_THROW, S_M_MEDICAL, S_M_FIRST_AID, S_M_HERBALISM, \
S_M_MEDICINE, S_M_MUSIC, S_M_STEALTH, S_M_DISGUISE, S_M_PICK_LOCK, \
S_M_SEDUCTION, S_M_FIND_TRAPS, S_M_SET_TRAPS, S_M_TRADE, S_M_APPRAISE, \
S_M_BARGAIN, S_LORE, S_ESTIMATE, S_ESTIMATE_ITEM, S_ESTIMATE_VALUE, \
S_ESTIMATE_ARMOR, S_ESTIMATE_WEAPON, S_ESTIMATE_LIVING, S_ESTIMATE_EQUIPMENT, \
S_ESTIMATE_HEALTH, S_ESTIMATE_SKILLS, S_ESTIMATE_STATS, S_HERALDRY, \
S_MECHANICS, S_PHONETIC, S_COMMON, S_DRACONIAN, S_LIZTONGUE, S_ORCISH, \
S_READ, S_READ_COMMON, S_TEACH, S_TRACK, S_P_WRITE, S_M_WRITE, \
S_M_WRITE_COMMON, S_M_GAMBLE, S_SENSE, S_BALANCE, S_FEEL, S_HEAR, S_SEARCH, \
S_SEE, S_SMELL, S_TASTE, S_P_MAGIC, S_MAGIC_AER, S_MAGIC_IMAGO, S_MAGIC_MENS, \
S_MAGIC_MORTUS, S_MAGIC_TERRA, S_MAGIC_VIS, S_M_MAGIC, S_MAGIC_CERNATUR, \
S_MAGIC_FIAT, S_MAGIC_MUTETUR, S_MAGIC_OBSEQUATUR, S_MAGIC_PEREAT, \
})

#endif /* _sys_skilltree_h */

