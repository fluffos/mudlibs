//
// quests.h - quest name definitions
// 
#define QUEST_M2 	"M2"
#define QUEST_KALEVA_ISLAND "M2a"
#define QUEST_M3 	"M3"
#define QUEST_M4 	"M4"
#define QUEST_M5 	"M5"
#define QUEST_M6 	"M6"
#define QUEST_EAT_AT_JOES 	"M6a"
#define QUEST_M15 	"M15"
#define QUEST_HILL_GIANT   "hill_giant"
#define QUEST_MAGIC_MANSION  "8ball"
#define QUEST_M18 	"M18"
#define QUEST_M19 	"M19"
#define QUEST_M20 	"M20"
#define QUEST_BARNEY	"bharni"
#define QUEST_DROW_CITY "drow_city"
#define QUEST_SILVER_RING "sr"
#define QUEST_DE_PALACE "de_palace"
#define QUEST_ZOO 	"zooquest"
#define QUEST_ZILLGODS 	"zillgods"
#define QUEST_KITIARA 	"kill_kitiara"
#define QUEST_SAMPO 	"quest_for_sampo"
#define QUEST_ORC_SLAYER "orc_slayer"
#define QUEST_PIRATE	"pirate_quest"
#define QUEST_GOLEM 	"golem_quest"
#define QUEST_MARGARET 	"margaret"
#define QUEST_CLOAK 	"cloak_quest"
#define QUEST_GARGAMEL 	"gargamel"
#define QUEST_COIN 	"coin_quest"
#define QUEST_OGRE_SLAYER "ogre_slayer"
#define QUEST_GRENADE 	"holy_grenade"
#define QUEST_TERAPTUS	"FLEE_TERAPTUS"
#define QUEST_MAZE_OF_FAME "maze_of_fame"
#define QUEST_FOR_IMMORTALITY "Immortal"

// The order of the quests in the array should be
// proportional to the relative difficulty of the quest.

#define QUESTS_NONLORD ({ QUEST_M2, QUEST_KALEVA_ISLAND, \
  			QUEST_M3, QUEST_M4, QUEST_M5,\
			QUEST_M6, QUEST_EAT_AT_JOES, \
  			QUEST_ORC_SLAYER, QUEST_ZOO,\
			QUEST_SAMPO, QUEST_M15, QUEST_KITIARA,\
			QUEST_BARNEY, QUEST_HILL_GIANT,\
			QUEST_MAZE_OF_FAME,\
  			QUEST_DROW_CITY, QUEST_DE_PALACE, \
			QUEST_ZILLGODS, QUEST_PIRATE, QUEST_M20,\
			QUEST_M18, QUEST_M19, QUEST_SILVER_RING })

// not  QUEST_COIN or QUEST_CLOAK -- areas missing
#define QUESTS_LORD ({ QUEST_GOLEM, QUEST_MARGARET,\
                        QUEST_GARGAMEL, QUEST_GRENADE,\
                        QUEST_TERAPTUS, QUEST_OGRE_SLAYER, \
                        QUEST_FOR_IMMORTALITY })
