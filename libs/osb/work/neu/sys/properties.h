#ifndef _PROPERTIES_
#define _PROPERTIES_

// --- /std/combat ---

#define P_AP_PER_QP        "APperQP"
#define P_ARMOUR_TYPE      "ArmourType"
#define P_ATTACK_VERBS     "AttackVerbs"
#define P_CLASS            "Class"
#define P_DAMAGE           "Damage"
#define P_DEFENSE          "Defense"
#define P_WEAPON_TYPE      "WeaponType"
#define P_WP_PER_QP        "WPperQP"

// Not builtin in /std/combat

#define P_AC               "AC"
#define P_WC               "WC"

// --- /std/living ---
// See also /sys/attributes.h

#define P_ACTION_ROUND     "ActionRound"
#define P_ACHAT_CHANCE     "AChatChance"
#define P_ACHATS           "AChats"
#define P_BLIND            "Blind"
#define P_CHAT_CHANCE      "ChatChance"
#define P_CHATS            "Chats"
#define P_DESCRIPTION      "Description"
#define P_DEG_POISON       "DegPoison"
#define P_ENEMIES          "Enemies"
#define P_FRIEND_OBJ       "FriendObj"
#define P_FROG             "Frog"
#define P_GHOST            "Ghost"
#define P_HEALTH           "Health"
#define P_HEALTH_MSG       "HealthMsg"
#define P_HEART            "Heart"
#define P_HEART_USER       "HeartUser"
#define P_KILL_XP          "KillXP"
#define P_LOAD             "Load"
#define P_MAX_CONTENT      "MaxContent"
#define P_QUESTIONS        "Questions"
#define P_RACE_OBJ         "RaceObj"
#define P_REAL_NAME        "RealName"
#define P_REG_HP           "RegHP"
#define P_REG_SP           "RegSP"
#define P_SHRUG_MSG        "ShrugMsg"
#define P_TALK_DELAY       "TalkDelay"
#define P_TALK_FUN         "TalkFun"
#define P_TALK_MATCH       "TalkMatch"
#define P_TALK_OBJ         "TalkObj"
#define P_TALK_TYPE        "TalkType"

// Not builtin in /std/living

#define P_DESCRIPTION      "Description"

// Initialisation properties

#define P_INIT_LEVEL       "InitLevel"
#define P_DEFAULT          "Default"

// --- /std/npc ---
// See also <attributes.h>

// --- /std/npc/body
#define P_ALCOHOL       "Alcohol"
#define P_DEG_ALCOHOL   "DegAlcohol"
#define P_DEG_DRINK     "DegDrink"
#define P_DEG_FOOD      "DegFood"
#define P_DRINK         "Drink"
#define P_FOOD          "Food"
#define P_MAX_ALCOHOL   "MaxAlcohol"
#define P_MAX_DRINK     "MaxDrink"
#define P_MAX_FOOD      "MaxFood"
#define P_RATE_ALCOHOL  "RateAlcohol"

// --- /std/player ---

// --- /std/player/skills ---

#define P_SKILLSERVER      "SkillServer"
#define P_STAT_DATA        "StatData"
#define P_SKILL_DATA       "SkillData"

// --- /obj/armour, /obj/weapon ---

#define P_MIN_CLASS        "MinClass"
#define P_MAX_CLASS        "MaxClass"

// Initialisation properties

#define P_TYPE             "Type"
#define P_UP               "Up"

// --- Compatibility only

//******* External Properties *********

#include <magic.h>

// --- /std/base ---

#define P_CREATOR          "Creator"
#define P_INHERITED        "Inherited"
#define P_PROPERTIES       "Properties"

// Not builtin in /std/base

#define P_CLEAN_UP         "CleanUp"
#define P_CLEANUP          P_CLEAN_UP
#define P_RESET_INTERVAL   "ResetInterval"

// --- /std/corpse ---

#define P_DECAY            "Decay"
#define P_DECAY_TIME       "DecayTime"

// --- /std/container ---

#define P_TRANSPARENCY     "Transparency"
#define P_TRANSPARENT      P_TRANSPARENCY
#define P_WEIGHT_CHG       "WeightChg"

// --- /std/door ---

#ifndef P_DIRECTION

#define P_DIRECTION        "Direction"
#define P_DOORCODE         "DoorCode"
#define P_OTHERROOM        "OtherRoom"
#define P_DOORROOM         "DoorRoom"
#define P_HIDEDOOR         "HideDoor"
#define P_HIDEEXIT         "HideExit"

#endif

// --- /std/equipment ---

#define P_EQUIP_OBJ        "EquipObj"
#define P_USAGE_MODE       "UsageMode"
#define P_NUMBER_HANDS     "NumberHands"
#define P_QUALITY          "Quality"
#define P_QUALITY_MSG      "QualityMsg"
#define P_RESET_QUALITY    "ResetQuality"
#define P_USAGE            "Usage"
#define P_WIELDED          "Wielded"
#define P_WIELD_DATA       "WieldData"
#define P_WEAR_DATA        "WearData"
#define P_WORN             "Worn"

// Not builtin in /std/equipment

#define P_NOWEAR           "NoWear"
#define P_NOWIELD          "NoWield"

// --- /std/living ---
// See also /sys/attributes.h

#define P_ACHAT_CHANCE     "AChatChance"
#define P_ACHATS           "AChats"
#define P_ATTRS            "Attrs"
#define P_ATTRIBUTES       "Attributes"
#define P_BLIND            "Blind"
#define P_CHAT_CHANCE      "ChatChance"
#define P_CHATS            "Chats"
#define P_QUESTIONS        "Questions"
#define P_SHRUG_MSG        "ShrugMsg"
#define P_STATS            "Stats"
#define P_TALK_DELAY       "TalkDelay"
#define P_TALK_FUN         "TalkFun"
#define P_TALK_MATCH       "TalkMatch"
#define P_TALK_OBJ         "TalkObj"
#define P_TALK_TYPE        "TalkType"

// --- /std/lock ---
#ifndef P_KEYCODE

#define P_KEYCODE    "KeyCode"
#define P_KEYIDS     "KeyIds"
#define P_LOCKSTATE  "LockState"

#define P_NOLOCK   "NoLock"
#define P_NOUNLOCK "NoUnlock"

#endif

// --- /std/thing ---

#define P_ADS              "Ads"
#define P_BRIGHT           "Bright"
#define P_FOLLOWERS        "Followers"
#define P_IDS              "Ids"
#define P_INFO             "Info"
#define P_LAST_ID          "LastId"
#define P_LAST_PLAYER      "LastPlayer"
#define P_LAST_VERB        "LastVerb"
#define P_LIGHT            "Light"
#define P_LONG             "Long"
#define P_NOGET            "NoGet"
#define P_NOTAKE           P_NOGET
#define P_NODROP           "NoDrop"
#define P_NOGIVE           "NoGive"
#define P_NOISE            "Noise"
#define P_READ_MSG         "ReadMsg"
#define P_SHORT            "Short"
#define P_SMELL            "Smell"
#define P_VALUE            "Value"
#define P_WEIGHT           "Weight"

// Not builtin in /std/thing:

#define P_AUTOOBJECT       "AutoObject"
#define P_EXTRALOOK        "Extralook"
#define P_MAGIC            "Magic"
#define P_NOBUY            "NoBuy"
#define P_NOSELL           "NoSell"
#define P_SIZE             "Size"
#define P_VERSION          "Version"

// Values of P_SIZE

#define PSIZE_GENERIC  0
#define PSIZE_SMALL    1
#define PSIZE_NORMAL   2
#define PSIZE_LARGE    3

// --- /std/room ---

#define P_COMMANDS         "Commands"
#define P_DETAILS          "Details"
#define P_DOORS            "Doors"
#define P_EXIT_STRINGS     "ExitStrings"
#define P_EXITS            "Exits"
#define P_EXITS_DEST       "ExitsDest"
#define P_EXITS_DATA       "ExitsData"
#define P_INDOORS          "Indoors"
#define P_INT_SHORT        "IntShort"
#define P_INT_LONG         "IntLong"
#define P_INT_NOISE        "IntNoise"
#define P_INT_SMELL        "IntSmell"
#define P_INT_LIGHT        "IntLight"
#define P_ITEMS            "Items"
#define P_ITEMS_REFRESH    "ItemsRefresh"
#define P_MAGIC_PROTECTION "MagicProtection"
#define P_MAX_INV          "MaxInv"
#define P_MAX_WEIGHT       "MaxWeight"
#define P_NOISES           "Noises"
#define P_NOWAY_MSG        "NowayMsg"
#define P_OUTDOORS         "Outdoors"
#define P_PRECONTENT       "PreContent"
#define P_SERVER           "Server"
#define P_SMELLS           "Smells"
#define P_SUNBRIGHT        "SunBright"
#define P_TPORT            "TPort"
#define P_WEIGHT_CONTENT   "WeightContent"

// Not builtin in /std/room

#define P_KILLZONE         "KillZone"     // must be hardcoded !
#define P_TPORT_REASON     "TPortReason"

// --- /std/weather

#define P_CLIENTS          "Clients"
#define P_CHANGEDESC       "ChangeDesc"
#define P_STATELENGTH      "StateLength"
#define P_SUNLIGHT         "SunLight"
#define P_STATEDATA        "StateData"
#define P_STATEDESC        "StateDesc"

// --- /std/weather with numberable set of states

#define P_STATE           "State"
#define P_STATES          "States"

// --- /std/unit

#define P_AMOUNT           "Amount"
#define P_VALUE_PER_UNIT   "ValuePerUnit"
#define P_BRIGHT_PER_UNIT  "BrightPerUnit"
#define P_WEIGHT_PER_UNIT  "WeightPerUnit"
#define P_PLURAL_SHORT     "PluralShort"
#define P_LAST_AMOUNT      "LastAmount"

// --- /obj/inroom

#define P_USE_LOCK         "UseLock"

// --- Compatibility only

// /std/room

#define P_SPECIAL_DETAILS  "SpecialDetails"
#define P_SPECIAL_NOISES   "SpecialNoises"
#define P_SPECIAL_SMELLS   "SpecialSmells"

//====================================================
// Old properties following

/*
 * some predefined properties
 */

/* Builtins of livings (NOT /std/living!) */

#define P_AGGRESSIVE       "Aggressive"
#define P_ALCOHOL          "Alcohol"
#define P_ALIGN            "Align"
#define P_ARMOURS          "Armours"
#define P_ATTACK_CHANCE    "AttackChance"
#define P_ATTRIBUTES       "Attributes"
#define P_CAST_OBJ         "CastObj"
#define P_COMBAT_DELAY     "CombatDelay"
#define P_COMBAT_DELAY_MSG "CombatDelayMsg"
#define P_CON              "Con"
#define P_CORPSE           "Corpse"
#define P_DEFENCES         "Defences"
#define P_DEX              "Dex"
#define P_DRINK            "Drink"
#define P_ENEMIES          "Enemies"
#define P_FOOD             "Food"
#define P_FRIEND_OBJ       "FriendObj"
#define P_GENDER           "Gender"
#define P_GO_CHANCE        "GoChance"
#define P_HANDS            "Hands"
#define P_HP               "HP"
#define P_HUNTERS          "Hunters"
#define P_INT              "Int"
#define P_MAX_ALCOHOL      "MaxAlcohol"
#define P_MAX_DRINK        "MaxDrink"
#define P_MAX_FOOD         "MaxFood"
#define P_MAX_HP           "MaxHP"
#define P_MAX_SP           "MaxSP"
#define P_MMSGIN           "MMsgIn"
#define P_MMSGOUT          "MMsgOut"
#define P_MSGIN            "MsgIn"
#define P_MSGOUT           "MsgOut"
#define P_NAME             "Name"
#define P_IS_NPC           "IsNpc"
#define P_IS_PLAYER        "IsPlayer"
#define P_PRESAY           "Presay"
#define P_RACE             "Race"
#define P_REALNAME         "RealName"
#define P_SP               "SP"
#define P_STATS            "Stats"
#define P_STR              "Str"
#define P_TITLE            "Title"
#define P_TOTAL_AC         "TotalAC"
#define P_TOTAL_WC         "TotalWC"
#define P_WEAPONS          "Weapons"
#define P_WHIMPY           "Whimpy"
#define P_XP               "XP"

// Not builtin in /std/living

#define P_DESCRIPTION      "Description"

/* Builtins of /std/npc: */

#define P_ACHATS           "AChats"
#define P_ACHAT_CHANCE     "AChatChance"
#define P_CHATS            "Chats"
#define P_CHAT_CHANCE      "ChatChance"
#define P_SHRUG_MSG        "ShrugMsg"

/* Builtins of /std/player: */

#define P_ALIASES          "Aliases"
#define P_BONI             "Boni"
#define P_CHANNELS         "Channels"
#define P_CITIZEN          "Citizen"
#define P_CURRENTDIR       "CurrentDir"
#define P_FACTIVE          "FActive"
#define P_FALIASES         "FAliases"
#define P_GUILD            "Guild"
#define P_HOME             "Home"
#define P_INVIS            "Invis"
#define P_LAST_SAVE        "LastSave"
#define P_LEVEL            "Level"
#define P_PAGESIZE         "PageSize"
#define P_REAL_LEVEL       "RealLevel"
#define P_QUESTS           "Quests"
#define P_TTY              "TTY"

/* Not builtin of /std/player */

#define P_WEAR_OBJ         "WearObj"
#define P_WIELD_OBJ        "WieldObj"
#define P_NOWIZ            "NoWiz"

/* Builtins of /std/food and /std/drink
 * (bert nase && organimedes && pepel)
 */

#define P_FD_KIND       "FoodKind"
#define P_FD_SOAK       "FoodSoak"
#define P_FD_STUFF      "FoodStuff"
#define P_FD_ALC        "FoodAlc"
#define P_FD_HEAL       "FoodHeal"
#define P_FD_MSG1       "FoodMsg1"
#define P_FD_MSG2       "FoodMsg2"

// /std/room

#define P_SPECIAL_DETAILS  "SpecialDetails"
#define P_SPECIAL_NOISES   "SpecialNoises"
#define P_SPECIAL_SMELLS   "SpecialSmells"

#endif
