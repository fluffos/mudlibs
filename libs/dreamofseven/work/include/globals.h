//
// file: globals.h
//
// This file is #included in all objects automatically by the driver.
// (See config file of driver)

// Directories

#define COMMAND_DIR		"/cmds/"
#define CONFIG_DIR		"/adm/etc/"
#define DATA_DIR		"/data/"
#define HELP_DIR		"/doc/"
#define LOG_DIR			"/log/"
#define MOB_1			"/open/world1/mob/" //方便巫師使用.
#define MOB_2			"/open/world2/mob/" //方便巫師使用.
#define MOB_3			"/open/world3/mob/" //方便巫師使用.
#define OPEN_PATH		"/open/"
// Daemons
#define COMBINE_D		"/adm/daemons/combined.lpc" //add by Luky 協力技精靈
#define CLOCK_D			"/adm/daemons/clockd" //add by Luky 定時精靈
#define RECORD_D		"/adm/daemons/record.lpc" //add by Luky 紀錄精靈
#define LOTTERY_D		"/adm/daemons/lotteryd" //add by Luky 摸彩精靈
#define MAIL_D			"/adm/daemons/maild" //add by Luky 郵差
#define CLUB_D			"/adm/daemons/clubd" //add by Luky 幫會
#define LANGUAGE_D		"/adm/daemons/languaged" //add by Luky 轉GB碼
#define ROOM_D			"/adm/daemons/roomd" //add by Luky 房間產生精靈
#define QUEST_D			"/adm/daemons/questd" //add by Luky 任務整合精靈
#define NEWQUEST_D        "/adm/daemons/newquestd"
#define ITEM_D			"/adm/daemons/itemd" //add by Luky 物品主控台
#define BANK_D                  "/adm/daemons/bankd" //add by alickyuen 幫會銀行管理系統
#define ALIAS_D			"/adm/daemons/aliasd"
#define CHANNEL_D		"/adm/daemons/channeld"
#define CHAR_D			"/adm/daemons/chard"
#define CHINESE_D		"/adm/daemons/chinesed"
#define COMBAT_D		"/adm/daemons/combatd"
#define COMMAND_D		"/adm/daemons/cmd_d"
#define EMOTE_D			"/adm/daemons/emoted"
#define FINGER_D		"/adm/daemons/fingerd"
#define INQUIRY_D		"/adm/daemons/inquiryd"
#define LOGIN_D			"/adm/daemons/logind"
#define MOTD_D			"/adm/daemons/motd"
#define NATURE_D		"/adm/daemons/natured"
#define PROFILE_D		"/adm/daemons/profiled"
#define RANK_D			"/adm/daemons/rankd"
#define SECURITY_D		"/adm/daemons/securityd"
#define UPDATE_D		"/adm/daemons/updated"
#define VIRTUAL_D		"/adm/daemons/virtuald"
#define WEAPON_D		"/adm/daemons/weapond"
// Camp system - add by tmr
//luky
#define IDCHECK_D		"/adm/daemons/idcheckd"	//add by Luky
#define NEWS_D       "/adm/daemons/newsd" //add by Tmr 新聞廣播 2007/01/25
#define ENHANCE_D       "/adm/daemons/enhanced" //add by Tmr 武卷防卷 2007/04/26
#define WAR_D       "/adm/daemons/ward" //added by Tmr 戰爭精靈 2008/02/11
// cominging
#define IP_D               "/adm/daemons/ip_d" // add by cominging
#define COLOR_D    		"/adm/daemons/colord"
#define MATCH_D                 "/adm/daemons/matchd" // add by alickyuen,比武大會系統檔
#define CLASS_D(x)		("/daemon/class/" + x)
#define SKILL_D(x)		("/daemon/skill/" + x)
#define SPELL_D(x)		("/daemon/spell/" + x)	//add by Luky
#define RACE_D(x)		("/adm/daemons/race/" + x) //add by Luky
#define CONDITION_D(x)		("/daemon/condition/" + x)

// Clonable/Non-inheritable Standard Objects

#define COIN_OB			"/obj/money/coin"
#define CORPSE_OB		"/obj/corpse"
#define LOGIN_OB		"/obj/login"
#define MASTER_OB		"/adm/obj/master"
#define MAILBOX_OB		"/obj/mailbox"
#define NOTE_OB			"/obj/notebook"
#define SIMUL_EFUN_OB		"/adm/obj/simul_efun"
#define USER_OB			"/obj/user"
#define VOID_OB			"/obj/void"

// Inheritable Standard Objects

#define BANK			"/std/room/bank"
#define BULLETIN_BOARD		"/std/bboard"
#define CHARACTER		"/std/char"
#define CLASS_GUILD		"/std/room/class_guild"
#define CLUB_BANK               "/std/room/club_bank"
#define COMBINED_ITEM		"/std/item/combined"
#define EQUIP			"/std/equip"
#define FORCE			"/std/force"
#define HOCKSHOP		"/std/room/hockshop"
#define HOUSE			"/std/house"		// By Luky
#define ITEM			"/std/item"
#define BOX			"/std/box"
#define BOX_LOG                 "/std/item/box_log" // add by Cominging
#define LIQUID			"/std/liquid"
#define MONEY			"/std/money"
#define NPC			"/std/char/npc"
#define POWDER			"/std/medicine/powder"
#define ROOM			"/std/room"
#define DOOR			"/std/door"
#define SKILL			"/std/skill"
#define SSERVER			"/std/sserver"

#define BANKMAN			"/std/char/bankman"	//add by Luky
#define SELLMAN			"/std/char/sellman"	//add by Luky
#define SHOPMAN			"/std/char/shopman"	//add by Luky
#define MOBROOM			"/std/room/mobroom"	//add by Luky
#define LOTTERYMAN		"/std/char/lottery_npc"	//add by Luky
#define TICKET 			"/open/always/ticket"	//add by luky
//#define SHOP_STD                "/std/std-shop"
#define GUILDMASTER		"/std/char/guildmaster"
#define RIDE			"/std/char/ride"
#define VEHICLE			"/std/vehicle"		// add by Shengsan
#define GAME_GIFT               "/std/item/game_gift"
#define	MARRY			"/std/char/marry"	// add by Shengsan

// User IDs

#define ROOT_UID		"Root"
#define BACKBONE_UID		"Backbone"

// Features

#define F_ACTION		"/feature/action.lpc"
#define F_ALIAS			"/feature/alias.lpc"
#define F_APPRENTICE		"/feature/apprentice.lpc"
#define F_ATTACK		"/feature/attack.lpc"
#define F_ATTRIBUTE		"/feature/attribute.lpc"
#define F_AUTOLOAD		"/feature/autoload.lpc"
#define F_BULLET		"/feature/bullet.lpc"	//add by Luky
#define F_BUILDING              "/feature/building.lpc"	//add by Luky
#define F_CLEAN_UP		"/feature/clean_up.lpc"
#define F_COMMAND		"/feature/command.lpc"
#define F_CONDITION		"/feature/condition.lpc"
#define F_DAMAGE		"/feature/damage.lpc"
#define F_DBASE			"/feature/dbase.lpc"
#define F_EDIT			"/feature/edit.lpc"
#define F_EQUIP			"/feature/equip.lpc"
#define F_FINANCE		"/feature/finance.lpc"
#define F_FOOD			"/feature/food.lpc"	//add by Luky
#define F_PILL			"/feature/pill.lpc"	//add by Luky
#define F_WATER			"/feature/water.lpc"	//add by Luky
//#define F_LIQUID		"/feature/liquid.lpc"
#define F_MASTER		"/std/char/master.lpc"
#define F_MESSAGE		"/feature/message.lpc"
#define F_MATERIAL		"/feature/material.lpc"	// by Shengsan
#define F_MORE			"/feature/more.lpc"
#define F_MOVE			"/feature/move.lpc"
#define F_NAME			"/feature/name.lpc"
#define F_SAVE			"/feature/save.lpc"
#define F_SKILL			"/feature/skill.lpc"
#define F_SPELL			"/feature/spell.lpc"	//add by Luky
#define F_TEAM			"/feature/team.lpc"
#define F_TREEMAP		"/feature/treemap.lpc"
#define F_VENDOR		"/feature/vendor.lpc"
#define F_UNIQUE                "/feature/unique.lpc"	//add by Luky
#define F_HORSE       "/feature/horse.lpc" // add by tmr 2006/12/08 馬
#define F_QUEST        "/feature/quest.lpc"
#define F_DEPOT        "/feature/depot.lpc"  // add by tmr 2007/04/29 玩家個人倉庫
// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it 
// in effect.

#undef PROFILE_COMMANDS
