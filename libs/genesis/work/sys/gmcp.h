/*
 * gmcp.h
 *
 * This file contains definitions related to the GMCP (Generic MUD Communication Protocol).
 */

#ifndef GMCP_DEF
#define GMCP_DEF

/* Package commands. */
#define GMCP_CORE_HELLO           "core.hello"
#define GMCP_CORE_CLIENT          "core.client"
#define GMCP_CORE_DEBUG           "core.debug"
#define GMCP_CORE_GOODBYE         "core.goodbye"
#define GMCP_CORE_OPTIONS         "core.options"
#define GMCP_CORE_PING            "core.ping"
#define GMCP_CORE_SUPPORTS_ADD    "core.supports.add"
#define GMCP_CORE_SUPPORTS_REMOVE "core.supports.remove"
#define GMCP_CORE_SUPPORTS_SET    "core.supports.set"
#define GMCP_CORE_TOKEN           "core.token"
#define GMCP_CHAR_LOGIN           "char.login"
#define GMCP_CHAR_CREATED         "char.created"
#define GMCP_CHAR_SKILLS_GET      "char.skills.get"
#define GMCP_CHAR_SKILLS_GROUPS   "char.skills.groups"
#define GMCP_CHAR_SKILLS_INFO     "char.skills.info"
#define GMCP_CHAR_SKILLS_LIST     "char.skills.list"
#define GMCP_CHAR_STATUS          "char.status"
#define GMCP_CHAR_STATUSVARS      "char.statusvars"
#define GMCP_CHAR_TEAM            "char.team"
#define GMCP_CHAR_VITALS          "char.vitals"
#define GMCP_CHAR_VITALS_GET      "char.vitals.get"
#define GMCP_CHAR_VITALS_LISTS    "char.vitals.lists"
#define GMCP_CHAR_VITALS_LEVELS   "char.vitals.levels"
#define GMCP_COMM_CHANNEL         "comm.channel"
#define GMCP_FILES_DIR_GET        "files.dir.get"
#define GMCP_FILES_DIR_LIST       "files.dir.list"
#define GMCP_FILES_READ           "files.read"
#define GMCP_FILES_WRITE          "files.write"
#define GMCP_ROOM_INFO            "room.info"
#define GMCP_ROOM_MAP             "room.map"

#define GMCP_EXTERNAL_DISCORD_HELLO     "external.discord.hello"
#define GMCP_EXTERNAL_DISCORD_GET       "external.discord.get"
#define GMCP_EXTERNAL_DISCORD_INFO      "External.Discord.Info"
#define GMCP_EXTERNAL_DISCORD_STATUS    "External.Discord.Status"

/* Package variable names */
#define GMCP_CHAR      "char"
#define GMCP_COMM      "comm"
#define GMCP_ROOM      "room"
/* General */
#define GMCP_CLIENT    "client"
#define GMCP_VERSION   "version"
/* Char.Login */
#define GMCP_NAME      "name"
#define GMCP_PASSWORD  "password"
#define GMCP_UID       "uid"
/* Char.Skills */
#define GMCP_GROUP     "group"
#define GMCP_INFO      "info"
#define GMCP_LIST      "list"
#define GMCP_SKILL     "skill"
#define GMCP_VALUE     "value"
/* Char.Status */
#define GMCP_ALIGN     "alignment"
#define GMCP_GENDER    "gender"
#define GMCP_LEVEL     "level"
#define GMCP_RANK      "rank"
#define GMCP_MAIL      "mail"
#define GMCP_RACE      "race"
/* Char.Team */
#define GMCP_FOLLOW    "follow"
#define GMCP_LEADER    "leader"
#define GMCP_MEMBERS   "members"
/* Char.Vitals */
#define GMCP_DRINK     "drink"
#define GMCP_ENCUMBER  "encumberance"
#define GMCP_FATIGUE   "fatigue"
#define GMCP_FOOD      "food"
#define GMCP_HEALTH    "health"
#define GMCP_INTOX     "intoxication"
#define GMCP_MANA      "mana"
#define GMCP_PANIC     "panic"
#define GMCP_PROGRESS  "progress"
#define GMCP_QPROGRESS "progress_quest"
/* Comm.Channel */
#define GMCP_LINE      "line"
#define GMCP_BODY      "body"
#define GMCP_MESSAGE   "message"
/* Core.Client */
#define GMCP_HEIGHT    "height"
#define GMCP_WIDTH     "width"
/* Core.Options */
#define GMCP_NPC_COMMS "npc_comms"
/* Room.Info */
#define GMCP_ID        "id"
#define GMCP_SHORT     "short"
#define GMCP_LONG      "long"
#define GMCP_DOORS     "doors"
#define GMCP_EXITS     "exits"
#define GMCP_MAP       "map"
#define GMCP_MAPX      "x"
#define GMCP_MAPY      "y"
#define GMCP_ZOOM      "zoom"
#define GMCP_ZOOMX     "zoomx"
#define GMCP_ZOOMY     "zoomy"
/* Files */
#define GMCP_DIRS      "dirs"
#define GMCP_FILES     "files"
#define GMCP_PATH      "path"
#define GMCP_SIZE      "size"
#define GMCP_TEXT      "text"
#define GMCP_TIME      "time"

/* Default options. */
#define GMCP_DEFAULT_OPTIONS ([ GMCP_NPC_COMMS : 1 ])

/* Interval for the alarm to run on players using GMCP. */
#define GMCP_INTERVAL  60.0

/* The token to identify a player with, based on his name and last login time. */
#define GMCP_PLAYER_TOKEN(name, login_time) (crypt((name), "$1$" + (login_time) + "$")[-8..])

/* No definitions beyond this line. */
#endif GMCP_DEF
