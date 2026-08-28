#ifndef __MUDLIB_H__
#define __MUDLIB_H__

#define BASE            "/inherit/base/base"    /* base object */
#define LIVING          "/inherit/base/living"  /* object for living thing */
#define ROOM            "/inherit/base/room"    /* room object             */
#define MONSTER         "/inherit/base/monster" /* monster object          */
#define KEY             "/inherit/key"          /* key object              */
#define DOOR            "/inherit/door"         /* door object             */
#define ITEM            "/inherit/base/item"    /* item object             */
#define BOARD           "/inherit/board"        /* board object */
#define GUILD           "/inherit/guild"
#define WEAPON          "/inherit/weapon"       /* weapon object           */
#define ARMOUR          "/inherit/armour"       /* armour object           */
#define SHOP            "/inherit/shop"
#define BANK            "/inherit/bank"
#define LIGHT           "/inherit/light"
#define LIQUID          "/inherit/liquid"

#define TIME_D          "/daemon/time"
#define TERMINAL_D      "/daemon/terminal"
#define SOUL_D          "/daemon/soul"
#define WEATHER_D       "/daemon/weather"
#define WORLD_D         "/daemon/world"
#define EXPLORE_D       "/daemon/explore"
#define CHANNEL_D       "/daemon/channel"
#define MATERIAL_D      "/daemon/material"
#define PROTECTION_D    "/daemon/protection"
#define LANG_D            "/daemon/lang"
#define SPELL		"/inherit/spell"

#define MONEY_POUCH	"/home/mordoc/money/pouch"

#define THIS            this_player()
#define THOB            this_object()
#define ENV(p)          environment((p))

#define SOCKET          "secure/socket"
#define LOG_D           "/home/namhas/workroom"

#define POS_DEAD	0
#define POS_UNCONS	1
#define POS_STUNNED	2
#define POS_SLEEPING	3
#define POS_RESTING	4
#define POS_SITTING	5
#define POS_FIGHTING	6
#define POS_STANDING	7

#endif /* __MUDLIB_H__ */
