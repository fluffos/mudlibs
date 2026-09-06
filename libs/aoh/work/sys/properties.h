/*--------------------------------------------------------------------------
 * /sys/properties.h -- Headerfile for system-wide properties
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 * CHANGES
 *  06/28/98 [Mica] added non builtin living property P_LOOKINGTO
 */

#ifndef _PROPERTIES_H_
#define _PROPERTIES_H_

#define PROPERTY_HEADER         "/sys/properties.h"

/* -------------------------------------------------------------------------
 * /std/base
 * -------------------------------------------------------------------------
 */

#define P_CREATOR          "Creator"
#define P_CREATION_TIME    "CreationTime"
#define P_ICREATOR         "ICreator"
#define P_INHERITED        "Inherited"
#define P_IS_VIRTUAL       "IsVirtual"
#define P_PROPERTIES       "Properties"
#define P_VMASTER          SP_VMASTER

/* - NOT BUILTIN - */

#define P_CLEAN_UP         "CleanUp"
#define P_CLEANUP          P_CLEAN_UP
#define P_LAST_RESET       SP_LAST_RESET
#define P_RESET_INTERVAL   SP_RESET_INTERVAL

/* -------------------------------------------------------------------------
 * /std/thing
 * -------------------------------------------------------------------------
 */

#define P_ADS              "Ads"
#define P_BRIGHT           "Bright"
#define P_CLASS_ADS        "ClassAds"
#define P_CLASS_IDS        "ClassIds"
#define P_CLASS_PATTERN    "ClassPattern"
#define P_EXTRA_DESC       "ExtraDesc"
#define P_FOLLOWERS        "Followers"
#define P_HELP_MSG         "HelpMsg"
#define P_IDS              "Ids"
#define P_ID_PATTERN       "IdPattern"
#define P_INFO             "Info"
#define P_LAST_ADS         "LastAds"
#define P_LAST_ID          "LastId"
#define P_LAST_PLAYER      "LastPlayer"
#define P_LAST_PREP        "LastPrep"
#define P_LAST_VERB        "LastVerb"
#define P_LIGHT            "Light"
#define P_LONG             "Long"
#define P_MAGIC            "Magic"
#define P_NOGET            "NoGet"
#define P_NOTAKE           P_NOGET
#define P_NODROP           "NoDrop"
#define P_NOGIVE           "NoGive"
#define P_NOISE            "Noise"
#define P_PREP_REQUIRED    "PrepRequired"
#define P_PREPS            "Preps"
#define P_QUEST_ITEM       "QuestItem"
#define P_READ_MSG         "ReadMsg"
#define P_SHORT            "Short"
#define P_SMELL            "Smell"
#define P_SUB_DETAILS      "SubDetails"
#define P_SUB_READMSGS     "SubReadMsgs"
#define P_VALUE            "Value"
#define P_WEIGHT           "Weight"

/* - NOT BUILTIN - */

#define P_AUTOOBJECT       "AutoObject"
#define P_EQUIPPED         "Equipped"
#define P_EXTRALOOK        "Extralook"
#define P_IS_FOLLOWER      "IsFollower"
#define P_NOBUY            "NoBuy"
#define P_NO_QUITDROP      "NoQuitDrop"
#define P_NOFOLLOW         "NoFollow"
#define P_NOSELL           "NoSell"
#define P_SIZE             "Size"
#define P_VERSION          "Version"

/* -------------------------------------------------------------------------
 * /std/unit
 * -------------------------------------------------------------------------
 */

#define P_AMOUNT           "Amount"
#define P_VALUE_PER_UNIT   "ValuePerUnit"
#define P_BRIGHT_PER_UNIT  "BrightPerUnit"
#define P_WEIGHT_PER_UNIT  "WeightPerUnit"
#define P_PLURAL_PATTERN   "PluralPattern"
#define P_PLURAL_IDS       "PluralIds"
#define P_PLURAL_SHORT     "PluralShort"
#define P_PLURAL_LONG      "PluralLong"
#define P_LAST_AMOUNT      "LastAmount"

/* -------------------------------------------------------------------------
 * /std/container
 * -------------------------------------------------------------------------
 */

#define P_TRANSPARENCY     "Transparency"
#define P_TRANSPARENT      P_TRANSPARENCY
#define P_WEIGHT_CHG       "WeightChg"

/* -------------------------------------------------------------------------
 * /std/equipment
 * -------------------------------------------------------------------------
 */

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

/* - NOT BUILTIN - */

#define P_NOWEAR           "NoWear"
#define P_NOWIELD          "NoWield"
#define P_NOUNWEAR         "NoUnwear"
#define P_NOUNWIELD        "NoUnwield"

/* -------------------------------------------------------------------------
 * /std/armour
 * -------------------------------------------------------------------------
 */

#define P_AC               "AC"
#define P_AP_PER_QP        "APperQP"
#define P_ARMOUR_TYPE      "ArmourType"

/* -------------------------------------------------------------------------
 * /std/weapon
 * -------------------------------------------------------------------------
 */

#define P_DAM_TYPE         "DamType"
#define P_WC               "WC"
#define P_WEAPON_HANDS     "WeaponHands"
#define P_WEAPON_TYPE      "WeaponType"
#define P_WP_PER_QP        "WPperQP"
#define P_HIT_OBJ          "HitObj"

/* -------------------------------------------------------------------------
 * /std/living
 * -------------------------------------------------------------------------
 * NOTE: see also /sys/attribues.h
 */

/* - NOT BUILTIN - */

#define P_FLYING           "Flying"
#define P_SEE_INVIS        "SeeInvis"
#define P_SEE_INVIS_CHANCE "SeeInvisChance"
#define P_WATERBREATHING   "WaterBreathing"
#define P_LOOKINGTO        "LookingTo"

/* -------------------------------------------------------------------------
 * /std/living/attributes
 * -------------------------------------------------------------------------
 */

#define P_ATTRIBUTES       "Attributes"
#define P_ATTRS            "Attrs"
#define P_BONI             "Boni"
#define P_STATS            "Stats"

/* -------------------------------------------------------------------------
 * /std/living/body
 * -------------------------------------------------------------------------
 */

#define P_CORPSE            "Corpse"
#define P_DEG_POISON        "DegPoison"
#define P_HP                "HP"
#define P_KILL_XP           "KillXP"
#define P_MAX_HP            "MaxHP"
#define P_MAX_POISON        "MaxPoison"
#define P_MAX_SP            "MaxSP"
#define P_POISON            "Poison"
#define P_RATE_HP           "RateHP"
#define P_RATE_POISON       "RatePoison"
#define P_RATE_SP           "RateSP"
#define P_REG_HP            "RegHP"
#define P_REG_SP            "RegSP"
#define P_SP                "SP"
#define P_XP                "XP"
#define P_WIMPY             "Wimpy"

/* - NOT BUILTIN - */

#define P_HEALTH            "Health"
#define P_HEALTH_MSG        "HealthMsg"
#define P_RESISTANCE        "Resistance"

/* -------------------------------------------------------------------------
 * /std/living/chat
 * -------------------------------------------------------------------------
 */

#define P_ACHAT_CHANCE     "AChatChance"
#define P_ACHATS           "AChats"
#define P_CHAT_CHANCE      "ChatChance"
#define P_CHATS            "Chats"
#define P_QUESTIONS        "Questions"
#define P_SHRUG_MSG        "ShrugMsg"
#define P_TALK_DELAY       "TalkDelay"
#define P_TALK_FUN         "TalkFun"
#define P_TALK_MATCH       "TalkMatch"
#define P_TALK_OBJ         "TalkObj"
#define P_TALK_TYPE        "TalkType"

/* -------------------------------------------------------------------------
 * /std/living/combat
 * -------------------------------------------------------------------------
 */

#define P_AGGRESSIVE       "Aggressive"
#define P_ARMOURS          "Armours"
#define P_ATTACK_CHANCE    "AttackChance"
#define P_CAST_OBJ         "CastObj"
#define P_COMBAT_DELAY     "CombatDelay"
#define P_COMBAT_DELAY_MSG "CombatDelayMsg"
#define P_DEFENCES         "Defences"
#define P_ENEMIES          "Enemies"
#define P_FRIEND_OBJ       "FriendObj"
#define P_HANDS            "Hands"
#define P_LEGS             "Legs"
#define P_HUNTERS          "Hunters"
#define P_TOTAL_AC         "TotalAC"
#define P_TOTAL_WC         "TotalWC"
#define P_WEAPONS          "Weapons"

/* -------------------------------------------------------------------------
 * /std/living/description
 * -------------------------------------------------------------------------
 */

#define P_ACTIONS          "Actions"
#define P_ALIGN            "Align"
#define P_FROG             "Frog"
#define P_GENDER           "Gender"
#define P_GHOST            "Ghost"
#define P_INVIS            "Invis"
#define P_IS_LIVING        "IsLiving"
#define P_IS_NPC           "IsNPC"
#define P_IS_PET           "IsPet"
#define P_IS_PLAYER        "IsPlayer"
#define P_IVISION          "IVision"
#define P_LEVEL            "Level"
#define P_LSTATE           "LState"
#define P_MAGIC_DEFENCE    "MagicDefence"
#define P_MSGIN            "MsgIn"
#define P_MSGOUT           "MsgOut"
#define P_MMSGIN           "MMsgIn"
#define P_MMSGOUT          "MMsgOut"
#define P_NAME             "Name"
#define P_RACE             "Race"
#define P_RACE_OBJ         "RaceObj"
#define P_REALNAME         "RealName"
#define P_UVISION          "UVision"

/* - NOT BUILTIN - */

#define P_BLIND            "Blind"
#define P_DESCRIPTION      "Description"

/* -------------------------------------------------------------------------
 * /std/living/heart
 * -------------------------------------------------------------------------
 */

#define P_HEART            "Heart"
#define P_HBHOOKS          "HbHooks"

/* -------------------------------------------------------------------------
 * /std/living/moving
 * -------------------------------------------------------------------------
 */

#define P_GO_CHANCE        "GoChance"
#define P_ALLOWED_REGIONS  "AllowedRegions"

/* -------------------------------------------------------------------------
 * /std/living/stats
 * -------------------------------------------------------------------------
 */

#define P_CON              "Con"
#define P_DEX              "Dex"
#define P_INT              "Int"
#define P_STR              "Str"
#define P_CHA              "Cha"
#define P_WIS              "Wis"
#define P_AGI              "Agi"
#define P_QUI              "Qui"

/* -------------------------------------------------------------------------
 * /std/living/restrictions
 * -------------------------------------------------------------------------
 */

#define P_LOAD             "Load"
#define P_MAX_CONTENT      "MaxContent"

/* -------------------------------------------------------------------------
 * /std/lock
 * -------------------------------------------------------------------------
 */

#ifndef P_KEYCODE
#define P_KEYCODE     "KeyCode"
#define P_KEYIDS      "KeyIds"
#define P_LOCKSTATE   "LockState"
#define P_PICK_CHANCE "PickChance"
#define P_NOLOCK      "NoLock"
#define P_NOUNLOCK    "NoUnlock"
#endif

/* -------------------------------------------------------------------------
 * /std/npc
 * -------------------------------------------------------------------------
 * NOTE: See also attributes.h
 */

/* -------------------------------------------------------------------------
 * /std/npc/body
 * -------------------------------------------------------------------------
 */

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

/* -------------------------------------------------------------------------
 * /std/npc/view
 * -------------------------------------------------------------------------
 */

#define P_BRIEF            "Brief"
#define P_OBVIOUS          "Obvious"

/* -------------------------------------------------------------------------
 * /std/player
 * -------------------------------------------------------------------------
 */

#define P_PRESAY           "Presay"
#define P_TITLE            "Title"
#define P_PROMPT           "Prompt"
#define P_NEWBIE_HELPER    "NewbieHelper"
#define P_EDITING          "Editing"
#define P_ALIASES          "Aliases"
#define P_AWAY             "Away"
#ifndef P_BONI
#define P_BONI             "Boni"
#endif
#define P_CHANNELS         "Channels"
#define P_CHANNELS_ON      "ChannelsOn"
#define P_CURRENTDIR       "CurrentDir"
#define P_FACTIVE          "FActive"
#define P_FALIASES         "FAliases"
#define P_GUILD            "Guild"
#define P_HOME             "Home"
#ifndef P_INVIS
#define P_INVIS            "Invis"
#endif
#define P_LAST_SAVE        "LastSave"
#define P_PAGESIZE         "PageSize"
#define P_PAGEWIDTH        "PageWidth"
#define P_REAL_LEVEL       "RealLevel"
#define P_QUESTS           "Quests"
#define P_SEER_QP          "SeerQP"
#define P_TTY              "TTY"
#define P_WIZ_QP           "WizQP"
#define P_CALLED_FROM_IP   "CalledFromIp"
#define P_CALLED_FROM_IPNAME "CalledFromIpName"
#define P_FIRST_LOGIN      "FirstLogin"
#define P_LAST_LOGIN       "LastLogin"
#define P_MAILADDR         "MailAddr"
#define P_ECHOMODE         "EchoMode"
#define P_AGE              "Age"
#define P_NETDEAD          "Netdead"
#define P_NETDEAD_ROOM     "NetdeadRoom"
#define P_PRONOUN          "Pronoun"
#define P_OBJECTIVE        "Objective"
#define P_POSSESSIVE       "Possessive"
#define P_EXPLORED         "Explored"
#define P_LAST_STATS       "LastStats"
#define P_LAST_XP          "LastXP"
#define P_KILLS            "Kills"
#define P_LAST_KILLS       "LastKills"
#define P_GUEST            "Guest"
#define P_DEAD_OB          "DeadOb"
#define P_INFORM_OBJS      "InformObjs"
#define P_PLAYER_STARTED   "PlayerStarted"
#define P_LAST_NEWSID      "LastNewsId"
#define P_CLASS_COLORS     "ClassColors"
#define P_CLASS_HISTORY    "ClassHistory"
#define P_TIME_OPTIONS     "TimeOptions"

#define TIME_OSB           "osb"
#define TIME_RL            "rl"
#define TIME_ALL           "all"

/* - NOT BUILTIN -*/

#define P_WEAR_OBJ         "WearObj"
#define P_WIELD_OBJ        "WieldObj"
#define P_NOWIZ            "NoWiz"
#define P_TELL_RECIPIENTS  "TellRecipients"
#define P_TELL_REPLYTO     "TellReplyTo"
#define P_MSG_HISTORY      "MsgHistory"

/* -------------------------------------------------------------------------
 * /std/player/misc
 * -------------------------------------------------------------------------
 */

#define P_TARGETS       "Targets"

/* -------------------------------------------------------------------------
 * /std/player/skills
 * -------------------------------------------------------------------------
 */

#define P_SKILLSERVER      "SkillServer"
#define P_STAT_DATA        "StatData"
#define P_SKILL_DATA       "SkillData"

/* -------------------------------------------------------------------------
 * /std/corpse
 * -------------------------------------------------------------------------
 */

#define P_DECAY            "Decay"
#define P_DECAY_TIME       "DecayTime"

/* -------------------------------------------------------------------------
 * /std/door
 * -------------------------------------------------------------------------
 */

#ifndef P_DIRECTION
#define P_CHECKDOOR        "CheckDoor"
#define P_DIRECTION        "Direction"
#define P_DOORCODE         "DoorCode"
#define P_DOORROOM         "DoorRoom"
#define P_OTHERROOM        "OtherRoom"
#define P_HIDEDOOR         "HideDoor"
#define P_HIDEEXIT         "HideExit"

#define P_CHECKOBJ         "CheckObj"
#define P_CHECKNOTIFY      "CheckNotify"
#endif

/* -------------------------------------------------------------------------
 * /std/room
 * -------------------------------------------------------------------------
 * NOTE: P_KILL_ZONE must be defined builtin, i.e. QueryKillZone()
 */

#define P_COMMANDS         "Commands"
#define P_ROOM_SECRETS     "RoomSecrets"
#define P_COORDINATES      "Coordinates"
#define P_TEMPERATURE      "Temperature"
#define P_DAY_DATA         "DayData"
#define P_DAY_DESC         "DayDesc"
#define P_DAY_STATE        "DayState"
#define P_DETAILS          "Details"
#define P_VITEMS           "VItems"
#define P_VITEM_COUNTER    "VItemCounter"
#define P_DOORS            "Doors"
#define P_EXIT_STRINGS     "ExitStrings"
#define P_EXITS            "Exits"
#define P_EXITS_DEST       "ExitsDest"
#define P_EXITS_DATA       "ExitsData"
#define P_EXPLORABLE       "Explorable"
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
#define P_MONEY            "Money"
#define P_NOISES           "Noises"
#define P_NOWAY_MSG        "NowayMsg"
#define P_NOWAY_MSGS       "NowayMsgs"
#define P_OUTDOORS         "Outdoors"
#define P_PRECONTENT       "PreContent"
#define P_READ_MSGS        "ReadMsgs"
#define P_SERVER           "Server"
#define P_SMELLS           "Smells"
#define P_SUNBRIGHT        "SunBright"
#define P_TPORT            "TPort"
#define P_WEIGHT_CONTENT   "WeightContent"

/* - NOT BUILTIN - */

#define P_CANSEE           "CanSee"
#define P_KILLZONE         "KillZone"
#define P_PREOUTSIDE       "PreOutside"
#define P_OUTSIDE          "Outside"
#define P_TPORT_REASON     "TPortReason"
#define P_REGION           "Region"

/*-------------------------------------------------------------------------
 * vitem-enhancement
-------------------------------------------------------------------------*/
#define PV_ITEM_LOCATION   "PVItemLocation"
#define P_MAX_AMOUNT       "MaxAmount"
#define PV_SILENT_GET      "PVSilentGet"
#define PV_NONE_LEFT       "PVNoneLeft"

/* -------------------------------------------------------------------------
 * /std/shop
 * -------------------------------------------------------------------------
 */

#define P_VALUTA           "Valuta"
#define P_SECURITY         "Security"
#define P_SIGN_DESC        "SignDesc"
#define P_MARKET           "Market"
#define P_ARTICLES         "Articles"
#define P_ARTICLES_REFRESH "ArticlesRefresh"
#define P_BUY_FACTOR       "BuyFactor"
#define P_DYNAMIC          "Dynamic"
#define P_MIN_CASH         "MinCash"
#define P_LIST             "List"
#define P_IDENTIFY         "Identify"
#define P_APPRAISE         "Appraise"
#define P_SHOW             "Show"
#define P_SELL             "Sell"
#define P_BUY              "Buy"
#define P_LIVING_TRADE     "LivingTrade"

/* -------------------------------------------------------------------------
 * /std/weather
 * -------------------------------------------------------------------------
 */

#define P_CLIENTS          "Clients"
#define P_CHANGEDESC       "ChangeDesc"
#define P_STATELENGTH      "StateLength"
#define P_SUNLIGHT         "SunLight"
#define P_STATEDATA        "StateData"
#define P_STATEDESC        "StateDesc"
#define P_STATE            "State"
#define P_STATES           "States"

/* -------------------------------------------------------------------------
 * /std/disease
 * -------------------------------------------------------------------------
 */

#define P_DISEASE_SHORT           "DiseaseShort"
#define P_DISEASE_LONG            "DiseaseLong"
#define P_DISEASE_SEVERENESS      "DiseaseSevereness"
#define P_DISEASE_OWNER           "DiseaseOwner"
#define P_DISEASE_TYPE            "DiseaseType"
#define P_DISEASE_SUBTYPE         "DiseaseSubtype"
#define P_DISEASE_TIME_HEAL       "DiseaseTimeHeal"
#define P_DISEASE_TIME_ACTION     "DiseaseTimeAction"
#define P_DISEASE_CURE_MSG        "DiseaseCureMsg"

/* -------------------------------------------------------------------------
 * /std/food
 * -------------------------------------------------------------------------
 */

#define P_DRINK_REFILL  "DrinkRefill"
#define P_REFILL  P_DRINK_REFILL

#define P_FOOD_KIND       "FoodKind"
#define P_FOOD_SOAK       "FoodSoak"
#define P_FOOD_STUFF      "FoodStuff"
#define P_FOOD_ALC        "FoodAlc"
#define P_FOOD_HEAL       "FoodHeal"
#define P_FOOD_MSGS       "FoodMsgs"

#define P_FD_KIND       P_FOOD_KIND
#define P_FD_SOAK       P_FOOD_SOAK
#define P_FD_STUFF      P_FOOD_STUFF
#define P_FD_ALC        P_FOOD_ALC
#define P_FD_HEAL       P_FOOD_HEAL

/* ###################################################################### */

/* -------------------------------------------------------------------------
 * /obj/monster/spellmonster
 * -------------------------------------------------------------------------
 */

#define P_SPELLS           "Spells"
#define P_SPELL_CHANCE     "SpellChance"
#define P_CAST_CHANCE      "CastChance"

/* -------------------------------------------------------------------------
 * /obj/mazemaster
 * /obj/mazedoor
 * -------------------------------------------------------------------------
 */

#define P_MASTER           "Master"
#define P_LABEL            "Label"
#define P_COOR             "Coordinates"

/* -------------------------------------------------------------------------
 * /obj/lib/ship
 * -------------------------------------------------------------------------
 */

#define P_HARBOUR          "Harbour"
#define P_PORTS            "Ports"
#define P_SHIP_ENTER_MSGS  "ShipEnterMsgs"
#define P_SHIP_LEAVE_MSGS  "ShipLeaveMsgs"
#define P_ROOMS            "Rooms"
#define P_DECKS            "Decks"
#define P_MOVE_SCENES      "MoveScenes"
#define P_MOVE_MSGS        "MoveMsgs"
#define P_ENTER_MSGS       "EnterMsgs"
#define P_LEAVE_MSGS       "LeaveMsgs"

/* -------------------------------------------------------------------------
 * /obj/inroom
 * -------------------------------------------------------------------------
 */

#define P_USE_LOCK         "UseLock"

/* -------------------------------------------------------------------------
 * /obj/vmaster
 * -------------------------------------------------------------------------
 */

#define P_OBJECTS          "Objects"

/* ###################################################################### */

/* -------------------------------------------------------------------------
 * /room/port
 * -------------------------------------------------------------------------
 */

#define P_SHIPS            "Ships"
#define P_AUTOCALL         "Autocall"

/* -------------------------------------------------------------------------
 * /room/smithy
 * -------------------------------------------------------------------------
 */

#define P_FIX              "Fix"
#define P_RESIZE           "Resize"
#define P_SMITHY           "Smithy"
#define P_NO_SHOP          "NoShop"
#define P_REPAIR_FACTOR    "RepairFactor"
#define P_RESIZE_FACTOR    "ResizeFactor"
#define P_MAX_REPAIR       "MaxRepair"
#define P_MAX_QUALITY      "MaxQuality"
#define P_WEAPON_DECAY     "WeaponDecay"
#define P_ARMOUR_DECAY     "ArmourDecay"

/* ###################################################################### */

/* -------------------------------------------------------------------------
 * miscellanous properties, used in many objects
 * -------------------------------------------------------------------------
 */

#define P_STANDARD "Standard"

/* -------------------------------------------------------------------------
 * TODO: unidentified defines :)
 * -------------------------------------------------------------------------
 */

#define P_COMBAT_STYLE     "CombatStyle"
#define P_FREE_HANDS       "FreeHands"
#define P_DEFENSE          "Defense"

/* ###################################################################### */

/* -------------------------------------------------------------------------
 * miscellaneous value defines
 * -------------------------------------------------------------------------
 * TODO: move those non P_-defines outta here*
 */

#ifndef LSTATE_NORMAL
#define LSTATE_NORMAL  0
#define LSTATE_GHOST   1
#define LSTATE_FROG    2
#endif

#ifndef PSIZE_GENERIC
#define PSIZE_GENERIC  0
#define PSIZE_SMALL    1
#define PSIZE_NORMAL   2
#define PSIZE_LARGE    3
#endif

#ifndef GENDER_OTHER
#define GENDER_UNSET   0
#define GENDER_MALE    1
#define GENDER_FEMALE  2
#define GENDER_OTHER   3
#define GENDER_NEUTER  GENDER_OTHER
#endif

/* ###################################################################### */

#endif

/* ********************************************************************** */
