#ifndef __GLOBAL_H__
#define __GLOBAL_H__

// std
#define STD_CHARACTER   "/std/character.lpc"
#define STD_CONSUMABLE  "/std/consumable.lpc"
#define STD_DATABASE    "/std/database.lpc"
#define STD_ITEM        "/std/item.lpc"
#define STD_LIVING      "/std/living.lpc"
#define STD_NPC         "/std/npc.lpc"
#define STD_OBJECT      "/std/object.lpc"
#define STD_ROOM        "/std/room.lpc"
#define STD_USER        "/std/user.lpc"

// std actions
#define STD_ABILITY     "/std/ability.lpc"
#define STD_COMMAND     "/std/command.lpc"
#define STD_VERB        "/std/verb.lpc"

// std item inheritables
#define STD_ARMOR       "/std/item/armor.lpc"
#define STD_COINS       "/std/item/coins.lpc"
#define STD_CORPSE      "/std/item/corpse.lpc"
#define STD_DRINK       "/std/item/drink.lpc"
#define STD_FOOD        "/std/item/food.lpc"
#define STD_INJECTABLE  "/std/item/injectable.lpc"
#define STD_KEY         "/std/item/key.lpc"
#define STD_STORAGE     "/std/item/storage.lpc"
#define STD_WEAPON      "/std/item/weapon.lpc"

// std npc inheritables
#define STD_VENDOR      "/std/npc/vendor.lpc"

// std resource inheritables
#define STD_RESOURCE    "/std/resource/resource.lpc"
#define STD_HARVESTABLE "/std/resource/harvestable.lpc"

// std modules
#define M_AUTOLOAD      "/std/module/autoload.lpc"
#define M_BONUS         "/std/module/bonus.lpc"
#define M_CLEAN         "/std/module/clean.lpc"
#define M_CONTAINER     "/std/module/container.lpc"
#define M_CURRENCY      "/std/module/currency.lpc"
#define M_DUSTABLE      "/std/module/dustable.lpc"
#define M_EXIT          "/std/module/exit.lpc"
#define M_LEVELABLE     "/std/module/levelable.lpc"
#define M_LOOK          "/std/module/look.lpc"
#define M_MOVE          "/std/module/move.lpc"
#define M_PARSE         "/std/module/parse.lpc"
#define M_PICKABLE      "/std/module/pickable.lpc"
#define M_PROPERTY      "/std/module/property.lpc"
#define M_RESET         "/std/module/reset.lpc"
#define M_SENSES        "/std/module/senses.lpc"
#define M_STORY         "/std/module/story.lpc"
#define M_TEST          "/std/module/test.lpc"

// secure modules
#define M_HTTP          "/secure/module/http.lpc"
#define M_SAVE          "/secure/module/save.lpc"

// daemons
#define D_ANSI          "/daemon/ansi.lpc"
#define D_ACHIEVEMENTS  "/daemon/achievements.lpc"
#define D_ASTRONOMY     "/daemon/astronomy.lpc"
#define D_CHANNEL       "/daemon/channel.lpc"
#define D_CLASS         "/daemon/class.lpc"
#define D_EXPERIENCE    "/daemon/experience.lpc"
#define D_LOG           "/daemon/log.lpc"
#define D_PLANET        "/daemon/planet.lpc"
#define D_SOUL          "/daemon/soul.lpc"
#define D_SPECIES       "/daemon/species.lpc"
#define D_WELCOME       "/daemon/welcome.lpc"

// secure daemons
#define D_ACCESS        "/secure/daemon/access.lpc"
#define D_ACCOUNT       "/secure/daemon/account.lpc"
#define D_BANK          "/secure/daemon/bank.lpc"
#define D_CHARACTER     "/secure/daemon/character.lpc"
#define D_COMMAND       "/secure/daemon/command.lpc"
#define D_IPC           "/secure/daemon/ipc.lpc"
#define D_TEST          "/secure/daemon/test.lpc"

#define MASTER          "/secure/daemon/master"
#define SEFUN           "/secure/sefun/sefun"

#endif /* __GLOBAL_H__ */