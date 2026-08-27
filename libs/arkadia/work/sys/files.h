/*
 * /sys/files.h
 *
 * This inclusion files contains the filenames of most mudlib modules in
 * definitions. If, except for #include or inherit, you ever need to make
 * a reference to a mudlib file, the name should be in here.
 */

#ifndef FILES_DEFINED
#define FILES_DEFINED

/* The section /cmd */

#define CMD_LIVE_INFO      ("/cmd/live/info")
#define CMD_LIVE_SOCIAL    ("/cmd/live/social")
#define CMD_LIVE_STATE     ("/cmd/live/state")
#define CMD_LIVE_THINGS    ("/cmd/live/things")

#define COMMAND_DRIVER     ("/cmd/std/command_driver")
#define SOUL_CMD           ("/cmd/std/soul_cmd")
#define TRACER_TOOL_SOUL   ("/cmd/std/tracer_tool")

#define WIZ_CMD_MORTAL     ("/cmd/wiz/mortal")
#define WIZ_CMD_APPRENTICE ("/cmd/wiz/apprentice")
#define WIZ_CMD_PILGRIM    ("/cmd/wiz/pilgrim")
#define WIZ_CMD_RETIRED    ("/cmd/wiz/retired")
#define WIZ_CMD_NORMAL     ("/cmd/wiz/normal")
#define WIZ_CMD_HELPER     ("/cmd/wiz/helper")
#define WIZ_CMD_MAGE       ("/cmd/wiz/mage")
#define WIZ_CMD_LORD       ("/cmd/wiz/lord")
#define WIZ_CMD_ARCH       ("/cmd/wiz/arch")
#define WIZ_CMD_KEEPER     ("/cmd/wiz/keeper")

#define JUNIOR_TOOL        ("/cmd/wiz/junior_tool)
#define JUNIOR_SHADOW      ("/cmd/wiz/junior_shadow")
#define MBS_SOUL           ("/cmd/wiz/mbs")

/* The section /lib */

#define BANK_LIBRARY       ("/lib/bank")
#define CACHE_LIBRARY      ("/lib/cache")
#define GUILD_LIBRARY      ("/lib/guild_support")
#define HERB_LIBRARY       ("/lib/herb_library")
#define NO_DECAY_LIBRARY   ("/lib/no_skill_decay")
#define PUB_LIBRARY        ("/lib/pub")
#define SHOP_LIBRARY       ("/lib/shop")
#define SKILL_LIBRARY      ("/lib/skill_raise")
#define STORE_LIBRARY      ("/lib/store_support")
#define TRADE_LIBRARY      ("/lib/trades")

/* The section /obj */

#define EDITOR_OBJECT      ("/obj/edit")
#define NAMETAG_OBJECT     ("/obj/know_me")
#define POSSESSION_OBJECT  ("/obj/possob")
#define REMOTE_NPC_OBJECT  ("/obj/remote_npc")

/* The section /secure */

#define APPLICATION_PLAYER ("/secure/application_player")
#define BOARD_CENTRAL      ("/secure/mbs_central")
#define DOCMAKER           ("/secure/docmake")
#define EDITOR_SECURITY    ("/secure/editor")
#define FINGER_PLAYER      ("/secure/finger_player")
#define GAMEINFO_OBJECT    ("/secure/gameinfo_player")
#define GARBAGE_COLLECTOR  ("/secure/master/mail_gc")
#define LOGIN_OBJECT       ("/secure/login")
#define MAIL_CHECKER       ("/secure/mail_checker")
#define MAIL_READER        ("/secure/mail_reader")
#define PLAYER_TOOL        ("/secure/player_tool")
#define PURGE_OBJECT       ("/secure/master/purge")
#define QUEUE              ("/secure/queue")
#define SECURITY           ("/secure/master")
#define SIMUL_EFUN         ("/secure/simul_efun")
#define SRCMAN             ("/secure/srcman")
#define VBFC_OBJECT        ("/secure/vbfc_object")

/* The section /std */

#define ARMOUR_OBJECT      ("/std/armour")
#define BECZULKA_OBJECT	   ("/std/beczulka")
#define BOARD_OBJECT       ("/std/board")
#define BOOK_OBJECT        ("/std/book")
#define COINS_OBJECT       ("/std/coins")
#define CONTAINER_OBJECT   ("/std/container")
#define CORPSE_OBJECT      ("/std/corpse")
#define CREATURE_OBJECT    ("/std/creature")
#define DOOR_OBJECT        ("/std/door")
#define DRINK_OBJECT       ("/std/drink")
#define FOOD_OBJECT        ("/std/food")
#define HEAP_OBJECT        ("/std/heap")
#define HERB_OBJECT        ("/std/herb")
#define KEY_OBJECT         ("/std/key")
#define LEFTOVER_OBJECT    ("/std/leftover")
#define LIVING_OBJECT      ("/std/living")
#define MOBILE_OBJECT      ("/std/mobile")
#define MONSTER_OBJECT     ("/std/monster")
#define OBJECT_OBJECT      ("/std/object")
#define PARALYZE_OBJECT    ("/std/paralyze")
#define PLAYER_PUB_OBJECT  ("/std/player_pub")
#define PLAYER_SEC_OBJECT  ("/std/player_sec")
#define POISON_OBJECT      ("/std/poison_effect")
#define POTION_OBJECT      ("/std/potion")
#define RECEPTACLE_OBJECT  ("/std/receptacle")
#define RESISTANCE_OBJECT  ("/std/resistance")
#define ROOM_OBJECT        ("/std/room")
#define ROPE_OBJECT        ("/std/rope")
#define SCROLL_OBJECT      ("/std/scroll")
#define SHADOW_OBJECT      ("/std/shadow")
#define SPELLS_OBJECT      ("/std/spells")
#define TORCH_OBJECT       ("/std/torch")
#define WEAPON_OBJECT      ("/std/weapon")
#define WORKROOM_OBJECT    ("/std/workroom")

/* The section /sys */
#define MANCTRL            ("/sys/global/manpath")

#define SLOWNIK		   ("/d/Standard/slownik/slownik")
#define BANK_CENTRAL	   ("/d/Standard/obj/bank_central")


/* Some macros for determining the type of an object based on its constructors 
 */
#define IS_ARMOUR_OBJECT(ob) \
    (function_exists("create_object", ob) == ARMOUR_OBJECT)

#define IS_BECZULKA_OBJECT(ob) \
    (function_exists("create_beczulka", ob) == BECZULKA_OBJECT)

#define IS_BOARD_OBJECT(ob) \
    (function_exists("create_object", ob) == BOARD_OBJECT)

#define IS_BOOK_OBJECT(ob) \
    (function_exists("create_object", ob) == BOOK_OBJECT)

#define IS_COINS_OBJECT(ob) \
    (function_exists("create_heap", ob) == COINS_OBJECT)

#define IS_CONTAINER_OBJECT(ob) \
    (function_exists("create_object", ob) == CONTAINER_OBJECT)

#define IS_CORPSE_OBJECT(ob) \
    (function_exists("create_container", ob) == CORPSE_OBJECT)

#define IS_CREATURE_OBJECT(ob) \
    (function_exists("create_mobile", ob) == CREATURE_OBJECT)

#define IS_DOOR_OBJECT(ob) \
    (function_exists("create_object", ob) == DOOR_OBJECT)

#define IS_FOOD_OBJECT(ob) \
    (function_exists("create_heap", ob) == FOOD_OBJECT)

#define IS_HEAP_OBJECT(ob) \
    (function_exists("create_object", ob) == HEAP_OBJECT)

#define IS_HERB_OBJECT(ob) \
    (function_exists("create_object", ob) == HERB_OBJECT)

#define IS_KEY_OBJECT(ob) \
    (function_exists("create_object", ob) == KEY_OBJECT)

#define IS_LEFTOVER_OBJECT(ob) \
    (function_exists("create_object", ob) == LEFTOVER_OBJECT)

#define IS_LIVING_OBJECT(ob) \
    (function_exists("create_container", ob) == LIVING_OBJECT)

#define IS_MOBILE_OBJECT(ob) \
    (function_exists("create_living", ob) == MOBILE_OBJECT)

#define IS_MONSTER_OBJECT(ob) \
    (function_exists("create_npc", ob) == MONSTER_OBJECT)

#define IS_OBJECT_OBJECT(ob) \
    (function_exists("create", ob) == OBJECT_OBJECT)

#define IS_PARALYZE_OBJECT(ob) \
    (function_exists("create_object", ob) == PARALYZE_OBJECT)

#define IS_PLAYER_OBJECT(ob) \
    (function_exists("create_living", ob) == PLAYER_SEC)

#define IS_POISON_OBJECT(ob) \
    (function_exists("create_object", ob) == POISON_OBJECT)

#define IS_POTION_OBJECT(ob) \
    (function_exists("create_object", ob) == POTION_OBJECT)

#define IS_RECEPTACLE_OBJECT(ob) \
    (function_exists("create_container", ob) == RECEPTACLE_OBJECT)

#define IS_RESISTANCE_OBJECT(ob) \
    (function_exists("create_object", ob) == RESISTANCE_OBJECT)

#define IS_ROOM_OBJECT(ob) \
    (function_exists("create_container", ob) == ROOM_OBJECT)

#define IS_ROPE_OBJECT(ob) \
    (function_exists("create_object", ob) == ROPE_OBJECT)

#define IS_SCROLL_OBJECT(ob) \
    (function_exists("create_object", ob) == SCROLL_OBJECT)

#define IS_SPELLS_OBJECT(ob) \
    (function_exists("create_object", ob) == SPELLS_OBJECT)

#define IS_TORCH_OBJECT(ob) \
    (function_exists("create_object", ob) == TORCH_OBJECT)

#define IS_WEAPON_OBJECT(ob) \
    (function_exists("create_object", ob) == WEAPON_OBJECT)

#define IS_WORKROOM_OBJECT(ob) \
    (function_exists("create_room", ob) == WORKROOM_OBJECT)


/* No definitions beyond this line. */
#endif FILES_DEFINED
