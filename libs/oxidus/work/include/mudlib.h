/* mudlib.h

 Tacitus @ LPUniversity
 19-OCT-05
 LPUniversity Macro File

*/

/* Last updated: August 10th, 2006 by Parthenon */

/* Redefinition warnings protection */

#ifndef __MUDLIB_H__
#define __MUDLIB_H__

#include <dirs.h>

/* Standard Inheritables */

#define STD_ABILITY         DIR_STD "cmd/ability"
#define STD_ACT             DIR_STD "cmd/act"
#define STD_ARMOUR          DIR_STD "equip/armour"
#define STD_BODY            DIR_STD_LIVING "body"
#define STD_CLOTHING        DIR_STD "equip/clothing"
#define STD_CMD             DIR_STD "cmd/cmd"
#define STD_CONTAINER       DIR_STD_OBJECT "container"
#define STD_DAEMON          DIR_STD "daemon/daemon"
#define STD_DECISION        DIR_STD "living/decision"
#define STD_DISCORD_BOT     DIR_STD "daemon/discord_bot"
#define STD_DRINK           DIR_STD "consume/drink"
#define STD_EQUIP           DIR_STD "equip/equip"
#define STD_FOOD            DIR_STD "consume/food"
#define STD_GHOST           DIR_STD "living/ghost"
#define STD_HTTP_CLIENT     DIR_STD "daemon/http_client"
#define STD_HTTP_SERVER     DIR_STD "daemon/http_server"
#define STD_ITEM            DIR_STD "object/item"
#define STD_MODULE_BASE     DIR_STD "module_base"
#define STD_LIVING          DIR_STD_LIVING "living"
#define STD_NPC             DIR_STD_LIVING "npc"
#define STD_NPC_PROC        DIR_STD_LIVING "proc"
#define STD_OB_E            DIR_STD "object/ob_prop"
#define STD_OBJECT          DIR_STD "object/object"
#define STD_PLAYER          DIR_STD_LIVING "player"
#define STD_REPORTER        DIR_STD "cmd/reporter"
#define STD_ROOM            DIR_STD "room/room"
#define STD_SPELL           DIR_STD "cmd/spell"
#define STD_STORAGE_OBJECT  DIR_STD "container/storage_object"
#define STD_STORAGE_ROOM    DIR_STD "room/storage"
#define STD_TEST            DIR_STD_TEST "test"
#define STD_TEST_RUNNER     DIR_STD_TEST "runner"
#define STD_VALUE           DIR_STD "object/value"
#define STD_VIRTUAL_MAP     DIR_STD "daemon/virtual_map"
#define STD_VIRTUAL_OBJECT  DIR_STD_OBJECT "virtual"
#define STD_VIRTUAL_SERVER  DIR_STD "daemon/virtual_server"
#define STD_WEAPON          DIR_STD "equip/weapon"
#define STD_WS_CLIENT       DIR_STD "daemon/websocket_client"
#define STD_ZONE            DIR_STD "zones/zone"

/* Mudlib Objects */

#define ANNOUNCE_CHDMOD    "/adm/daemons/modules/channel/announce"

#endif // __MUDLIB_H__
