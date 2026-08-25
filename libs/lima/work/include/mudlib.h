/* Do not remove the headers from this file! see /USAGE for more info. */

#ifndef __MUDLIB_H__
#define __MUDLIB_H__
#pragma no_warnings

#include "daemons.h"
#include "dirs.h"
#include "size.h"
#include "setbit.h"
#include "msgtypes.h"
#include "classes.h"
#include "custom_mudlib.h"

/*
** BODY            main player object (body)
** USER_OB         user's connection object
** USER_OB_BAK     user's connection object (backup version)
**
** SIMUL_OB	       the simul efun object
**
** BASE_ROOM       the room rooms are built from...
** INDOOR_ROOM     standard room (indoors)
** OUTDOOR_ROOM    an outdoor room/environment
** NON_ROOM	base   class for things like furniture
** WATER_ROOM      rooms full of water (e.g. a lake)
** GRID_SERVER     virtual server inheritable for grid-type rooms
**
** VOID_ROOM       where to put broken stuff
** WIZ_ROOM        a room for wizards
**
** BASE_OBJ        base class for objects
** OBJ             generic objects
** FURNITURE
** MOUNT	
** WEAPON          weapons
** ARMOUR          armour
** CONTAINER       obs that can hold things in/on/under/behind/etc.
** DOOR            doors to places
** SECRET_DOOR     secret doors.
** LIVING          can hold things and perform actions (no fighting)
** PAPER           paper .. WFW
** STOCK_MASTER    stock guildmaster for stock muds :)
** COINS           a bunch of coins
** SPELL           base class for spells
**
** M_GLOB          glob style regexp functions
** M_GRAMMAR       grammatical manipulation functions
** M_CMDIO         I/O functions for cmds
** M_PARSING       input parsing functions
** M_REGEX         regular expression functions
** M_INPUT         interface to the input system
** M_COMPLETE      name completion
** M_RECONNECT     functions for performing socket reconnects
** M_COLOURS       functions for using colours
** M_SAVE          functions to abstract saveing and restoring objects
**
** M_BODY_STATS	   statistics (characteristics) for a body (player/NPC)
** M_SMARTMOVE     living's movement with directions and enter/exit msgs
**
** M_WEARABLE      things that can be worn
** M_SWITCHABLE
** M_LIGHTABLE
** M_ITEMS         provides virtual/fake items for an object
** M_GETTABLE      objects that can be picked up
** M_THROWABLE     objects that can be thrown
** M_OPENABLE      objects that can be opened/closed
** M_LOCKABLE      openables that can be locked
** M_READABLE      something that can be read
** M_DAMAGE_SOURCE
** M_DAMAGE_SINK
** M_WIELDABLE     something that can be wielded (a weapon)
** M_MESSAGES      message generation
** M_ACTIONS
** M_TRIGGERS
** M_WRITING_SURFACE
** M_VENDOR
** M_DIGGER        items that can dig.
** M_DIGGABLE      items that you can dig in.
** M_BLOCKEXITS
** M_BLOCKABLE
** M_AGGRESSIVE
** M_KNOCKABLE
** M_MOUNTABLE
** M_ENTERABLE
** M_FLOW_ROOM
** M_GUILD_MASTER  act as a "guild master"
** M_GUILD_MEMBER  functions for guild members
** M_SIBLING       objects that exist in two rooms;
**
** M_LIB_LOCKABLE  arbitrates "locked" state of multiple instances
** M_LIB_OPENABLE  arbitrates "opened" state of multiple instances
**
** ED_SESSION      provides an 'ed' session for the user
** ADDTO_OB        object to add ines to a file
** WIZ_SHELL       a wizard's shell object
** TELNET_OB       a telnet tool
** ADMTOOL         administration tool's input menu object
** DATAEDIT        save file data editor
**
** ALIASMENU
** ANNO_MENU
** CORPSE
** HELPSYS         help system
** HINT_MENU
** IFTP_OB         command object to transfer files between muds via I3
** NEWSREADER      a basic newsreader
** NNTP_OB
** PLAYER_MENU
** PLAYER_SHELL    the player shell
** SIMPLE_OB       an object with simple responses to verbs
** TEMP_WORKROOM
** WATER           some water
**
** VERB_OB         basic functionality for parser-based verbs
** MENUS           generic menuing facility
**
** CMD             base inheritable for commands
** DAEMON          for daemons
** MAILBOX         mailbox to hold message references
** MAILER          generic "mailer" functionality
** SOCKET          object to manage a socket
**
** SHELL
** M_ALIAS         module for storing and expanding aliases
** M_GETOPT        functions for command processing
** M_HISTORY       module for handling command history
** M_PROMPT
** M_SCROLLBACK
** M_SHELLFUNCS	   ??
** M_SHELLVARS	   ??
**
** ACCOUNTANT
** SWORD
** BOOK
** LADDER
** STAIRS
** TORCH
** VEHICLE
** HOLE
*/

#define BODY               "/std/body"
#define USER_OB            "/secure/user"
#define USER_OB_BAK        "/secure/user_bak"

#define SIMUL_OB           "/secure/simul_efun"

#define BASE_ROOM          "/std/base_room"
#define INDOOR_ROOM        "/std/indoor_room"
#define OUTDOOR_ROOM       "/std/outdoor_room"
#define NON_ROOM           "/std/non_room"
#define WATER_ROOM         "/std/water_room"
#define GRID_SERVER        "/std/grid_server"

#define VOID_ROOM          "/domains/std/Void"
#define WIZ_ROOM           "/domains/std/Wizroom"
#define HEAVEN             "/domains/std/Heaven"

#define ADVERSARY          "/std/adversary"
#define AGGRESSIVE_MONSTER "/std/aggressive_monster"
#define AMMUNITION         "/std/ammunition"
#define ARMOUR             "/std/armour"
#define BASE_OBJ           "/std/base_obj"
#define CHEST              "/std/chest"
#define COMBAT_SPELL       "/std/combat_spell"
#define CONTAINER          "/std/container"
#define CORPSE             "/std/corpse"
#define PELT               "/std/pelt"
#define EXIT_OBJ           "/std/complex_exit_obj"
#define DOOR               "/std/door"
#define SECRET_DOOR        "/std/secret_door"
#define CLIMB_CHALLENGE    "/std/climb_challenge"
#define FLAME              "/std/flame"
#define HIDDEN_DOOR        "/std/hidden_door"
#define HIDDEN_EXIT        "/std/hidden_exit"
#define FLUID              "/std/fluid"
#define FOOD               "/std/food"
#define FURNITURE          "/std/furniture"
#define GUILD_GUARD        "/std/guild_guard"
#define KEY                "/std/key"
#define LIGHT_OBJECT       "/std/light_object"
#define LIVING             "/std/living"
#define	MENUS              "/std/menu"
#define MOVING_ROOM        "/std/moving_room"
#define MOVING_MONSTER     "/std/moving_monster"
#define FOLLOWING_MONSTER  "/std/following_monster"
#define WANDERING_MONSTER  "/std/wandering_monster"
#define MOUNT              "/std/mount"
#define OBJ                "/std/object"
#define PAPER              "/std/paper"
#define PARAM_OBJ          "/std/param_obj"
#define RANGED_WEAPON      "/std/ranged_weapon"
#define SIGN               "/std/sign"
#define SPELL              "/std/spell"
#define STOCK_MASTER       "/std/stock_master"
#define VERB_OB            "/std/verb_ob"
#define NVERB_OB           "/std/nverb_ob"
#define WEAPON             "/std/weapon"

/* used by the OBJ object */

/* for mudlib objects */
#define _MODULES           "/std/modules/"
#define M_COLOURS          _MODULES "m_colours"
#define M_FRAME            _MODULES "m_frame"
#define M_BODY_STATS       _MODULES "m_bodystats"
#define M_COMPLETE         _MODULES "m_complete"
#define M_GLOB             _MODULES "m_glob"
#define M_GRAMMAR          _MODULES "m_grammar"
#define M_ITEMS            _MODULES "m_items"
#define M_PARSING          _MODULES "m_parsing"
#define M_RECONNECT        _MODULES "m_reconnect"
#define M_REGEX            _MODULES "m_regex"
#define M_SMARTMOVE        _MODULES "m_smartmove"
#define M_EDIBLE           _MODULES "m_edible"
#define M_DRINKABLE        _MODULES "m_drinkable"
#define M_DURABILITY       _MODULES "m_durability"
#define M_DRINK_CONTAINER  _MODULES "m_drink_container"
#define M_DRINK_SOURCE     _MODULES "m_drink_source"
#define M_FLUID_SOURCE     _MODULES "m_fluid_source"
#define M_FLUID_CONTAINER  _MODULES "m_fluid_container"
#define M_CONVERSATION     _MODULES "m_conversation"
#define M_WIDGETS          _MODULES "m_widgets"
#define M_STATEFUL         _MODULES "m_stateful"

/* for area objects */ 
#define M_ACCOUNTANT       _MODULES "m_accountant"
#define M_TRAINER          _MODULES "m_trainer"
#define M_ACTIONS          _MODULES "m_actions"
#define M_NPCSCRIPT        _MODULES "m_npcscript"
#define M_BLOCKEXITS       _MODULES "m_blockexits"
#define M_AGGRESSIVE       _MODULES "m_aggressive"
#define M_DAMAGE_SINK      _MODULES "m_damage_sink"
#define M_DAMAGE_SOURCE    _MODULES "m_damage_source"
#define M_CRAFTING         _MODULES "m_crafting"
#define M_DIGGABLE         _MODULES "m_diggable"
#define M_DECAY            _MODULES "m_decay"
#define M_DIGGER           _MODULES "m_digger"
#define M_FLOW_ROOM        _MODULES "m_flow_room"
#define M_FOLLOW           _MODULES "m_follow"
#define M_GETTABLE         _MODULES "m_gettable"
#define M_GUILD_MASTER     _MODULES "m_guild_master"
#define M_GUILD_MEMBER     _MODULES "m_guild_member"
#define M_KNOCKABLE        _MODULES "m_knockable"
#define M_LIGHT_SOURCE     _MODULES "m_light_source"
#define M_LIGHTABLE        _MODULES "m_lightable"
#define M_LOCKABLE         _MODULES "m_lockable"
#define M_SEARCHABLE       _MODULES "m_searchable"
#define M_MESSAGES         _MODULES "m_messages"
#define M_MOUNTABLE        _MODULES "m_mountable"
#define M_OPENABLE         _MODULES "m_openable"
#define M_READABLE         _MODULES "m_readable"
#define M_REACT            _MODULES "m_react"
#define M_READY            _MODULES "m_ready"
#define M_SIBLING          _MODULES "m_sibling"
#define M_SWITCHABLE       _MODULES "m_switchable"
#define M_THROWABLE        _MODULES "m_throwable"
#define M_ASSISTANCE       _MODULES "m_assistance"
#define M_COMPANION        _MODULES "m_companion"
#define M_TRIGGERS         _MODULES "m_triggers"
#define M_VENDOR           _MODULES "m_vendor"
#define M_WANDER           _MODULES "m_wander"
#define M_WANDER_OLD       _MODULES "m_wander_old"
#define M_BOSS             _MODULES "m_boss"
#define M_WEARABLE         _MODULES "m_wearable"
#define M_WIELDABLE        _MODULES "m_wieldable"
#define M_WRITING_SURFACE  _MODULES "m_writing_surface"
#define M_EXIT             _MODULES "m_exit"
#define M_COMPLEX_EXIT     _MODULES "m_complex_exit"
#define M_DICE             _MODULES "m_dice"
#define M_POWER            _MODULES "m_power"
#define M_LOCKPICK         _MODULES "m_lockpick"
#define M_SALVAGEABLE      _MODULES "m_salvageable"
#define M_HEALING          _MODULES "m_healing"
#define M_SPECIAL_WEAPON   _MODULES "m_special_weapon"
 
/* secure _MODULES */
#define _SEC_MODULES       "/secure/modules/"
#define M_ACCESS           _SEC_MODULES "m_access"
#define M_FILE             _SEC_MODULES "m_file"
#define M_DAEMON_DATA      _SEC_MODULES "m_daemon_data"
#define M_INPUT            _SEC_MODULES "m_input"
#define M_SAVE             _SEC_MODULES "m_save"
#define M_SET              _SEC_MODULES "m_set"

#define M_LIB_LOCKABLE	  "/domains/std/lockable"
#define M_LIB_OPENABLE    "/domains/std/openable"

#define ED_SESSION        "/trans/obj/ed_session"
#define ADDTO_OB          "/trans/obj/addto_ob"
#define WIZ_SHELL         "/trans/obj/wish"
#define TELNET_OB         "/trans/obj/telnet_ob"
#define CONFIG_EDITOR     "/trans/obj/config_editor"
#define USER_MENU         "/obj/usermenu/usermenu"
#define ADMTOOL           "/obj/admtool/admtool2"
#define TASKTOOL          "/obj/tasktool/tasktool"
#define DATAEDIT          "/trans/obj/dataedit"

#define ALIASMENU         "/obj/mudlib/aliasmenu"
#define ANNO_MENU         "/obj/mudlib/annotationmenu"
#define HELPSYS           "/obj/mudlib/helpsys"
#define HINT_MENU         "/obj/mudlib/hintmenu"
#define IFTP_OB           "/obj/mudlib/iftp_ob"
#define NEWSREADER        "/obj/mudlib/newsreader"
#define NNTP_OB           "/obj/mudlib/nntp"
#define PLAYER_MENU       "/obj/mudlib/plmenu"
#define PLAYER_SHELL      "/obj/mudlib/pshell"
#define SIMPLE_OB         "/obj/mudlib/simple_ob"
#define PARTY_MENU        "/obj/mudlib/party_menu"
#define TEMP_WORKROOM     "/obj/mudlib/TWorkroom"
#define WATER             "/std/water"

#define CMD               "/obj/secure/cmd"
#define MAILBOX           "/obj/secure/mailbox"
#define MAILER_DIR        "/obj/secure/mailers"
#define MAILER            MAILER_DIR "/mailer"
#define SOCKET            "/obj/secure/socket"
#define BEHAVIOUR_TREE    "/std/behaviour/behaviour_tree"

#define SHELL             "/obj/secure/shell"
#define M_ALIAS           "/obj/secure/shell/alias"
#define M_HISTORY         "/obj/secure/shell/history"
#define M_SCROLLBACK      "/obj/secure/shell/scrollback"
#define M_SHELLFUNCS      "/obj/secure/shell/shellfuncs"

/* used by 'wish';  M_GETOPT also used in CMD_D */
#define M_GETOPT          "/obj/secure/shell/getopt"
#define M_PROMPT          "/obj/secure/shell/prompt"
#define M_SHELLVARS       "/obj/secure/shell/shellvars"

// These next few are 'high level' inheritables and probably should have
// their own dir.
#define ACCOUNTANT        "/std/accountant"
#define MEAT              "/std/meat"
#define TRANSIENT         "/std/transient"
#define SLOWHEAL          "/std/slowheal"
#define DRINK             "/std/drink"
#define JUNK              "/std/junk"
#define BED               "/std/bed"
#define MONEY             "/std/money"
#define BOOK              "/std/book"
#define COINS             "/std/coins"
#define ELEVATOR          "/std/elevator"
#define BANDAGE           "/std/bandage"
#define HOLE              "/std/hole"
#define LOOT_CHEST        "/std/loot_chest"
#define MATERIAL          "/std/material"
#define MATERIAL_SPAWNER  "/std/material_spawner"
#define LADDER            "/std/ladder"
#define LANTERN           "/std/lantern"
#define GEM               "/std/gem"
#define CRAFTING_STATION  "/std/crafting_station"
#define PELT              "/std/pelt"
#define ART_OBJECT        "/std/art_object"
#define TAMING_COLLAR     "/std/taming_collar"
#define PORTAL            "/std/portal"
#define STAIRS            "/std/stairs"
#define BATTERY           "/std/battery"
#define SWORD             "/std/sword"
#define TORCH             "/std/torch"
#define VEHICLE           "/std/vehicle"
#define INF_SUPPLY        "/std/inf_supply"

#endif /* __MUDLIB_H__ */
