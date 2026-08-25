/*
 * sys/state_desc.h
 *
 * Holds all textual descriptions of state descriptions of livings.
 * 
 * Note that local changes to these arrays are done in
 * /config/sys/state_desc2.h
 */

#ifndef SD_DEFINED
#define SD_DEFINED 

#define SD_LANG_FILE "/sys/global/language"

/*
 * SD_AV_TITLES - the titles themselves.
 * SD_AV_LEVELS - the stat level from which you get a title.
 * SD_NUM_AV_LEVELS - the number of titles and levels.
 *
 * The mortal 'level' titles.
 */

#define SD_NUM_AV_LEVELS 16
#define SD_AV_TITLES ({ "novice",           \
			"greenhorne",       \
			"beginner",         \
			"apprentice",       \
			"wanderer",         \
			"adventurer",       \
			"adept",            \
			"great adventurer", \
			"veteran",          \
			"expert",           \
			"rising hero",      \
			"hero",             \
			"titan",            \
			"champion",         \
			"legend",           \
			"myth" })

#define SD_AV_LEVELS ({   7, \
			 15, \
			 24, \
			 33, \
			 43, \
			 53, \
			 64, \
			 75, \
			 87, \
			 99, \
			112, \
			125, \
			140, \
			155, \
			170, \
			190 })

/*
 * SD_AV_NOVICE - The maximum stat average at which you're a novice.
 *  ...
 * SD_AV_LEGEND - The maximum stat average at which you're a legend.
 * SD_AV_NEWBIE - The maximum stat average at which you may be considered a
 *                   newbie for game purposes. 
 */
#define SD_AV_NOVICE           14
#define SD_AV_GREENHORNE       23
#define SD_AV_BEGINNER         32
#define SD_AV_APPRENTICE       42
#define SD_AV_WANDERER         52
#define SD_AV_ADVENTURER       63
#define SD_AV_ADEPT            74
#define SD_AV_GREAT_ADVENTURER 86
#define SD_AV_VETERAN          98
#define SD_AV_EXPERT          111
#define SD_AV_RISING_HERO     124
#define SD_AV_HERO            139
#define SD_AV_TITAN           154
#define SD_AV_CHAMPION        169
#define SD_AV_LEGEND          189
#define SD_AV_NEWBIE          SD_AV_GREAT_ADVENTURER

#define SD_AV_ADVANCE_DESCS ({ "just beginning on the path to", \
                               "very far from",                 \
                               "a long distance from",          \
                               "a fair distance from",          \
                               "just under halfway to",         \
                               "just over halfway to",          \
                               "getting closer to",             \
                               "fairly close to",               \
                               "very close to",                 \
                               "on the verge of",               \
                            })

/* May this player be considered a newbie? */
#define SD_IS_NEWBIE(player) ((player)->query_average_stat() <= SD_AV_NEWBIE)

#define SD_STAT_NAMES 	({ "STR", "DEX", "CON", "INT", "WIS", "DIS" })
#define SD_STAT_DESC ({ "str", "dex", "con", "int", "wis", "dis", "race", \
    "occup", "layman", "craft" })
#define SD_LONG_STAT_DESC ({ "strength", "dexterity", "constitution", \
    "intelligence", "wisdom", "discipline", "racial", "occupational", \
    "layman", "craft" })

#define SD_STATLEV_STR ({ "puny", "feeble", "flimsy", "weak", "well built", \
                          "muscular", "hefty", "strong", "powerful", \
                          "musclebound", "ironlike", "forceful", "crushing", \
                          "mighty", "titanic", "epic strength", \
                          "immortal strength", "supreme strength", \
                          "extraordinary strength", "incredible strength", \
                          "unbelievable strength", "miraculous strength", \
                          "impossible strength" })
#define SD_STATLEV_DEX ({ "stiff", "lumbering", "clumsy", "deft", "flexible", \
                          "nimble", "lithe", "supple", "agile", "swift", \
                          "quick", "graceful", "athletic", "gymnastic", \
                          "acrobatic", "epic dexterity", \
                          "immortal dexterity", "supreme dexterity", \
                          "extraordinary dexterity", "incredible dexterity", \
                          "unbelievable dexterity", "miraculous dexterity", \
                          "impossible dexterity" })
#define SD_STATLEV_CON ({ "sickly", "fragile", "frail", "skinny", "lean", \
                          "healthy", "firm", "hearty", "hardy", "hale", \
                          "robust", "staunch", "tough", "sturdy", "vigorous", \
                          "epic constitution", "immortal constitution", \
                          "supreme constitution", \
                          "extraordinary constitution", "incredible constitution", \
                          "unbelievable constitution", "miraculous constitution", \
                          "impossible constitution" })
#define SD_STATLEV_INT ({ "moronic", "dimwitted", "simple", "dense", "slow", \
                          "limited", "keen", "clever", "quick minded", \
                          "intelligent", "sharp", "bright", "inventive", \
                          "ingenious", "brilliant", "epic intelligence", \
                          "immortal intelligence", "supreme intelligence", \
                          "extraordinary intelligence", "incredible intelligence", \
                          "unbelievable intelligence", "miraculous intelligence", \
                          "impossible intelligence" })
#define SD_STATLEV_WIS ({ "inane", "stupid", "idiotic", "foolish", "uneducated", \
                          "literate", "educated", "learned", "scholarly", \
                          "cultivated", "knowledgeable", "erudite", "wise", \
                          "sage", "enlightened", "epic wisdom", \
                          "immortal wisdom", "supreme wisdom", \
                          "extraordinary wisdom", "incredible wisdom", \
                          "unbelievable wisdom", "miraculous wisdom", \
                          "impossible wisdom" })
#define SD_STATLEV_DIS ({ "gutless", "frightened", "spineless", "fearful", \
                          "cowardly", "insecure", "timid", "sound", "bold", \
                          "brave", "courageous", "fearless", "valiant", \
                          "heroic", "lionhearted", "epic discipline", \
                          "immortal discipline", "supreme discipline", \
                          "extraordinary discipline", "incredible discipline", \
                          "unbelievable discipline", "miraculous discipline", \
                          "impossible discipline" })
                          
#define SD_STATLEV_EPIC "epic"
#define SD_STATLEV_IMM  "immortal"
#define SD_STATLEV_SUP  "supreme"
#define SD_STATLEV_EXT  "extraordinary"
#define SD_STATLEV_INC  "incredible"
#define SD_STATLEV_UNB  "unbelievable"
#define SD_STATLEV_MIR  "miraculous"
#define SD_STATLEV_IMP  "impossible"

#define SD_NUM_STATLEVS 23
                      /* Lowest possible level is probably 7. But just to be safe. */
#define SD_STATLEVELS ({ 1, 14, 22, 30, 39, 48, 58, 68, 79, 90, 102, 114, 126, 138, 150, 165, 185, 210, \
                            245, 295, 365, 460, 600 })
#define SD_STATLEVEL_EPIC 165 
#define SD_STATLEVEL_IMM  185 
#define SD_STATLEVEL_SUP  210 
#define SD_STATLEVEL_EXT  245
#define SD_STATLEVEL_INC  295
#define SD_STATLEVEL_UNB  365
#define SD_STATLEVEL_MIR  460
#define SD_STATLEVEL_IMP  600

#define SD_NUM_GUILDS       4
#define SD_GUILD_EXTENSIONS ({ "race", "occ", "lay", "craft" })
#define SD_GUILD_FULL_NAMES ({ "racial", "occupational", "layman", "craftsman" })

#define SD_SIZEOF_ADVANCE_DESCS   5
#define SD_ADVANCE_DESCS    ({ "very far from", "far from", "halfway to", \
    "close to", "very close to" })
#define SD_PROGRESS_DESCS   ({ "advancing to", "developing", "improving to", "progressing to", "rising to" })

#define GET_STAT_LEVEL_DESC(stat, level)  ((string)SD_LANG_FILE->get_stat_level_desc((stat), (level)))
#define GET_STAT_INDEX_DESC(stat, index)  ((string)SD_LANG_FILE->get_stat_index_desc((stat), (index)))
#define GET_EXP_LEVEL_DESC(level, gender) ((string)SD_LANG_FILE->get_exp_level_desc((level), (gender)))

/* Observe that the denominators below are reversed for the first two
   of the statlev descs above.
*/
#define SD_STAT_DENOM	({ "slightly ", "somewhat ", "", "very ", "extremely " })

#define SD_BRUTE_FACT   ({ "pacifistic", "meek", "touchy", "brutal", "violent"})

#define SD_HEALTH 	({ "at death's door", "barely alive", "terribly hurt", \
    "in a very bad shape", "in agony", "in a bad shape", "very hurt", \
    "suffering", "hurt", "aching", "somewhat hurt", "slightly hurt", \
    "sore", "feeling well", "feeling very well" })
    
#define SD_MANA		({ "in a vegetable state", "exhausted", "worn down", \
    "indisposed", "in a bad shape", "very degraded", "rather degraded", \
    "degraded", "somewhat degraded", "slightly degraded", "in full vigour" })

#define SD_COMPARE_STR  ({ "about the same strength as", 		  \
			   "a bit stronger than", "stronger than", 	  \
			   "much stronger than"})
#define SD_COMPARE_DEX  ({ "about as agile as", 			  \
			   "a bit better coordinated than", 		  \
			   "more agile than", "much more agile than" })
#define SD_COMPARE_CON  ({ "about as healthy as", "a bit healthier than", \
			   "healthier than", "much healthier than"})
#define SD_COMPARE_INT  ({ "about as smart as", "a bit smarter than",     \
			   "smarter than", "much smarter than"})
#define SD_COMPARE_WIS  ({ "about as wise as", "a bit wiser than",        \
			   "wiser than", "much wiser than"})
#define SD_COMPARE_DIS  ({ "about as brave as", "a bit braver than",      \
			   "braver than", "much braver than"})
#define SD_COMPARE_AC   ({ "about the same protection as",                \
                           "a bit more protection than",                  \
                           "more protection than",                        \
                           "a whole lot more protection than" })
#define SD_COMPARE_HIT  ({ "about as difficult as", "a bit easier than",  \
                           "easier than", "a lot easier than" })
#define SD_COMPARE_PEN  ({ "largely comparable to", "a bit more than",    \
                           "somewhat more than", "a lot more than" })

#define SD_BEAUTY_FEMALE ({ "like the image of perfection", "gorgeous",   \
			    "fine", "attractive", "beautiful", "pretty",  \
			    "nice", "plain", "more than usually plain",   \
			    "repulsive", "ugly", "hideous" })

#define SD_BEAUTY_MALE  ({ "like the image of perfection", "wonderful",   \
			   "handsome", "attractive", "fine", "pleasant",  \
			   "nice", "coarse", "unpleasant", "repulsive",   \
			   "ugly", "hideous" })

#define SD_PANIC  	({ "secure", "calm", "uneasy", "worried", "panicky"})

#define SD_FATIGUE	({ "alert", "weary", "tired", "exhausted" })

#define SD_SOAK  	({ "drink quite a lot more", "drink a lot more",  \
		    	   "drink some more", "drink a little more",	  \
		    	   "barely drink more" })

#define SD_STUFF    	({ "eat quite a lot more", "eat a lot more",	  \
		     	   "eat some more", "eat a little more",	  \
		     	   "barely eat more" })

#define SD_INTOX_SOBER  "sober"
#define SD_INTOX	({ "tipsy", "intoxicated", "drunk", "tanked", 	  \
			   "blitzed", "wasted", "toasted", "pissed",	  \
			   "stoned", "obliviated" })

#define SD_HEADACHE	({ "mild", "uncomfortable", "bad", "serious",     \
			   "intense", "pounding", "burning", "extreme" })

#define SD_IMPROVE_MIN  (  75000)
#define SD_IMPROVE_MAX  (1000000)
#define SD_PROGRESS	({ "insignificant", "a tiny amount of", "minimal", \
    "slight", "low", "a little", "some", "modest", "decent", "nice", \
    "good", "very good", "major", "great", "extremely good", "awesome", \
    "immense", "tremendous", "fantastic" })
#define SD_NO_PROGRESS  "no measurable"

#define SD_GOOD_ALIGN	({ "neutral", "agreeable", "trustworthy",	  \
			   "sympathetic", "nice", "sweet", "good",	  \
			   "devout", "blessed", "saintly", "holy" })

#define SD_EVIL_ALIGN	({ "neutral", "disagreeable", "untrustworthy",    \
			   "unsympathetic", "sinister", "wicked", "nasty",\
			   "foul", "evil", "malevolent", "beastly",	  \
			   "demonic", "damned" })

#define SD_ARMOUR	({ "in prime condition", "a little worn down", 	 \
                           "in a very bad shape", "in urgent need of repair", \
			   "going to break any second" })

#define SD_WEAPON_RUST	({ "no comment", "find some rust marks",	\
			   "spot some rust", "full of rust", 		\
			   "bathing in acid", "falling apart from corrosion" })

#define SD_WEAPON_COND	({ "in prime condition", "in a fine condition",	\
			   "touched by battle", "scarred by battle", 	\
			   "very scarred by battle",                    \
			   "in big need of a smith", \
			   "going to break any second" })

#define SD_ENC_WEIGHT	({ "unencumbered", "lightly burdened", "burdened", \
    "encumbered", "loaded", "heavily loaded", "over taxed", \
    "collapsing under your load" })

#define SD_CONTAINER_FILLED ({ "about empty", "relatively empty", \
    "nearly half full", "half full", "moderately full", "quite full", \
    "very full" })

#define SD_QUEST_PROGRESS ({ "absolutely nothing yet",       \
                             "little as of yet",             \
                             "a few things",                 \
                             "a growing list of things",     \
                             "numerous things",              \
                             "a wide range of things",       \
                             "an impressive list of things", \
                             "many and great things",        \
                             "an amazing number of things",  \
                             "countless legendary feats",    \
                             "enough to retire", })

#define SD_QUICKNESS    ({ "catatonic", "completely lethargic", \
                            "extremely dulled", "dulled", "very relaxed",     \
                            "slightly relaxed", "normal", "slightly elevated",\
                            "elevated", "rapid", "extremely rapid",           \
                            "dangerously rapid", "frenzied" })

#define SD_DRINK_ALCO_DESCS ({ "a little", "a low amount of", "some", \
    "moderate", "a lot of", "a high level of", "very high levels of" })
#define SD_DRINK_ALCO_LEVELS ({ 1, 5, 10, 15, 20, 32, 45 })

#define SD_LEVEL_MAP 	([ \
			  "good-align" : SD_GOOD_ALIGN,			\
			  "evil-align" : SD_EVIL_ALIGN,			\
			  "progress" : SD_PROGRESS,			\
			  "headache" : SD_HEADACHE,			\
			  "intox" : SD_INTOX,				\
			  "stuffed" : SD_STUFF,				\
			  "soaked" : SD_SOAK,				\
			  "fatigue" : SD_FATIGUE,			\
			  "panic" : SD_PANIC,				\
			  "male-beauty" : SD_BEAUTY_MALE,		\
			  "female-beauty" : SD_BEAUTY_FEMALE,		\
			  "mana" : SD_MANA,				\
			  "health" : SD_HEALTH,				\
			  "brutality" : SD_BRUTE_FACT,			\
              "quest-progress" : SD_QUEST_PROGRESS,         \
			  "compare-strength" : SD_COMPARE_STR,		\
			  "compare-dexterity" : SD_COMPARE_DEX,		\
			  "compare-constitution" : SD_COMPARE_CON,	\
			  "compare-intelligence" : SD_COMPARE_INT,	\
			  "compare-wisdom" : SD_COMPARE_WIS,		\
			  "compare-discipline" : SD_COMPARE_DIS,	\
			  "stat-strength" : SD_STATLEV_STR,		\
			  "stat-dexterity" : SD_STATLEV_DEX,		\
			  "stat-constitution" : SD_STATLEV_CON,		\
			  "stat-intelligence" : SD_STATLEV_INT,		\
			  "stat-wisdom" : SD_STATLEV_WIS,		\
			  "stat-discipline" : SD_STATLEV_DIS,		\
			  "mortal" : SD_AV_TITLES,			\
			  "mortal-improve" : SD_AV_ADVANCE_DESCS,	\
			  "armour" : SD_ARMOUR,				\
			  "weapon-rust" : SD_WEAPON_RUST,		\
			  "weapon-condition" : SD_WEAPON_COND,		\
			  "encumbrance": SD_ENC_WEIGHT,			\
              "quickness": SD_QUICKNESS                     \
		       ])

/* No definitions beyond this line. */
#endif
