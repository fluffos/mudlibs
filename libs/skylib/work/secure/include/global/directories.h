#ifndef __DIRECTORIES_H
#define __DIRECTORIES_H

#define BANISH_DIR           "/banish"
#define COMMAND_DIR          "/cmds"
#define CREATOR_DIR          "/w"
#define DOMAIN_DIR           "/d"
#define HANDLER_DIR          "/handlers"
#define HELP_DIR             "/autodoc"
#define LOG_DIR              "/log"
#define OBJ_DIR              "/obj"
#define OPEN_DIR             "/open"
#define PROJECT_DIR          "/p"
#define SAVE_DIR             "/save"
#define SECURE_DIR           "/secure"
#define STANDARD_DIR         "/std"
#define TMP_DIR              "/tmp"
#define WWW_DIR              "/www"

#define INSTRUMENTS_DIR      OBJ_DIR "/instruments"
#define MISC_DIR             OBJ_DIR "/misc"
#define TOYS_DIR             OBJ_DIR "/toys"
#define FLOWERS_DIR          OBJ_DIR "/flowers"

#define GUILD_DIR            STANDARD_DIR "/guilds"
#define STD_BASIC_DIR        STANDARD_DIR "/basic"
#define STD_OBJECT_DIR       STANDARD_DIR "/objects"
#define STD_STATIONERY_DIR   STANDARD_DIR "/stationery"
#define MODULE_DIR           STANDARD_DIR "/modules"
#define LIVING_DIR           STANDARD_DIR "/living"
#define NPC_DIR              STANDARD_DIR "/npcs"
#define RACE_DIR             STANDARD_DIR "/races"
#define ROOM_DIR             STANDARD_DIR "/room"
#define SHADOWS_DIR          STANDARD_DIR "/shadows"
#define EFFECTS_DIR          STANDARD_DIR "/effects"
#define SHOP_DIR             STANDARD_DIR "/shops"
#define PSHOP_DIR            SHOP_DIR "/player_shop"

#define SECURE_ETC_DIR       SECURE_DIR "/config"
#define SECURE_HANDLER_DIR   SECURE_DIR HANDLER_DIR
#define SECURE_MODULE_DIR    SECURE_DIR MODULE_DIR
#define SECURE_LOG_DIR       SECURE_DIR LOG_DIR
#define QUEST_DIR            SECURE_DIR "/quests"

#define CREATOR_COMMAND_DIR  COMMAND_DIR "/creator"
#define LEADER_COMMAND_DIR   COMMAND_DIR "/leader"
#define ADMIN_COMMAND_DIR    COMMAND_DIR "/admin"
#define LIVING_COMMAND_DIR   COMMAND_DIR "/living"
#define PLAYER_COMMAND_DIR   COMMAND_DIR "/player"

#define BANISH_SAVE_DIR      SAVE_DIR BANISH_DIR
#define HANDLER_SAVE_DIR     SAVE_DIR HANDLER_DIR
#define USER_SAVE_DIR        SAVE_DIR "/players"

#endif /* __DIRECTORIES_H */
