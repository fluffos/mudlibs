/*      Standard header-file for priest-guild. First version by Doomdark
 *      28-sep-93.
 */

#ifndef H_PRIEST
#define H_PRIEST

#include <guild.h>
#include <daemons.h>
#include <driver.h>

#pragma combine_strings

#define MK_DAMAGE_RATE 5.7
#define PK_DAMAGE_RATE 3.3

#define PRIEST_DIR "/guilds/priests/"
#define PRIEST_GARDENS  PRIEST_DIR "gardens/"
#define PRIEST_ALC_DIR  PRIEST_DIR "alchemy/"
#define PRIEST_ROOM_DIR PRIEST_DIR "rooms/"
#define PRIEST_MON_DIR  PRIEST_DIR "monsies/"
#define PRIEST_SAVE_DIR PRIEST_DIR "save/"
#define PRIEST_LOG_DIR  PRIEST_DIR "log/"
#define PRIEST_OBJ_DIR  PRIEST_DIR "obj/"
#define PRIEST_SP_DIR   PRIEST_DIR "spells/"
#define PRIEST_HELP_DIR PRIEST_DIR "help/"
#define PRIEST_LIB_DIR  PRIEST_DIR "lib/"
#define PRIEST_DAEMONS  PRIEST_DIR "daemons/"
#define CRYPT_DIR       PRIEST_DIR "crypt/"

#define COMMUNELOG      PRIEST_DIR "log/PRIEST_CHANNEL"
#define CASHLOG         PRIEST_DIR "log/cash_log"
#define SHOPLOG         PRIEST_DIR "log/shoplog"
#define RAIDLOG         PRIEST_DIR "log/raiders"
#define DISEASELOG      PRIEST_DIR "log/disease"
#define PEXLOG          PRIEST_DIR "log/PEXRATE"
#define DRAINLOG        PRIEST_DIR "log/drain"

#define ERRORLOG        PRIEST_DIR "log/errors"
#define RESTORELOG      PRIEST_DIR "log/restore_stat"
#define JOINLOG         PRIEST_DIR "log/new_priests"
#define NEWSFILE        PRIEST_DIR "PRIEST_NEWS"

#define EXCOM_D         PRIEST_DAEMONS "excom_d"
#define OFFICER_D       PRIEST_DAEMONS "officer_d"
#define BOOKKEEPER      PRIEST_DAEMONS "bookkeeper"
#define SERVER          PRIEST_DAEMONS "informer"
#define INFORMER        PRIEST_DAEMONS "informer"
#define TARGET_D        PRIEST_DAEMONS "target_d"
#define SPELL_D         PRIEST_DAEMONS "spell_d"
#define ALCHEMY_D       PRIEST_DAEMONS "alchemy_d"
#define CASH_D          PRIEST_DAEMONS "cash_d"
#define GUEST_D         PRIEST_DAEMONS "guest_d"
#define RAID_LOGGER     PRIEST_DAEMONS "raid_logger"
#define VOTING_D        PRIEST_DAEMONS "voting_d"
#define SKILL_CONVERTER PRIEST_DAEMONS "skill_converter"
#define SLAVE_D         PRIEST_DAEMONS "slave_d"
#define DELAY_D         PRIEST_DAEMONS "delay_d"
#define SKILL_SAVER     PRIEST_DAEMONS "skill_saver"
#define SPELL_LOADER    PRIEST_DAEMONS "spell_loader"
#define SHIELD_D        PRIEST_DAEMONS "shield_d"
#define ATTACK_D        PRIEST_DAEMONS "attack_d"
#define STAFF_D         PRIEST_DAEMONS "staff_d"
#define VESPER_D        PRIEST_DAEMONS "vesper_d"
#define ORDER_CHANGE_D  PRIEST_DAEMONS "order_change_d"

#define PRIEST_SYMBOL   PRIEST_DIR "symbol"
#define PSKILLS         PRIEST_DIR "lib/skills"
#define GEN_SPELL       PRIEST_DIR "lib/gen_spell"
#define GEN_POTION      PRIEST_DIR "lib/gen_potion"
#define GEN_SK_OBJ      PRIEST_DIR "lib/gen_skill_object"

#define GOD_NAME        "Boccob"
#define LONG_GOD_NAME   "Boccob the Uncaring"
#define FORCE_DEMIGOD_NAME "Caine"
#define LONG_FORCE_DGOD_NAME "Caine of the Forces"
#define NATURE_DEMIGOD_NAME "Seth"
#define LONG_NATURE_DGOD_NAME "Seth the Wise"

#define GUILD_ID        "holy symbol of Boccob"
#define PRIEST_ENTRANCE PRIEST_ROOM_DIR "entrance"

#define STAFF_NAME      PRIEST_OBJ_DIR "staff"
#define STAFF_ID        "__priest_staff"
#define SP_NAMES ({"spell points","points","spell point","sp","sps"})
#define STAFF_LEVEL     10

#define IS_PRIEST(x)    (objectp(x)&&(string)x->query_guild()==GN_PRIEST)

#define GA_RANK 15
#define GC_RANK 10
#define VG_RANK 8
#define PH_RANK 6
#define PT_RANK 5
#define ES_RANK 4
#define EM_RANK 3
#define IG_RANK 2
#define AE_RANK 1

// shield types:
#define ST_BARKSKIN 1
#define ST_NORMAL 2
#define ST_FIRE 3

// delay types:
#define DELAY_TYPE_SUMMON 1
#define SUMMON_DELAY 30
#define ANGEL_DIED_DELAY 180
#define DELAY_TYPE_PRAY 2
#define PRAY_DELAY 200
#define DELAY_TYPE_VESPER 3
#define VESPER_DELAY 600 // faith increases only once per church service
#define DELAY_TYPE_FAITH_DECR 4
#define FAITH_DECR_DELAY 600

/* maximum pex, dunno if this is really needed */
#define K_MAX_PEX 2147483647 // 2^31-1

#define ORDERS ({"Caine", "Boccob", "Seth"})
//#define ORDERS ({"Caine", "Abel", "Seth"})
//#define ORDERS ({"Black", "Gray", "White"})

#define SP_OFFENSIVE 1
#define SP_DEFENSIVE 2
#define SP_HEALING 3
#define SP_SPECIAL 4

#define BADDIES 0
#define GOOD_GUYS 1

#define PRIEST_ERROR(who,msg) write_file(ERRORLOG,sprintf("%s %s: %s", \
   ctime(time()), who->query_real_name(), msg))

// Pick level of the locks in shops' doors
#define SHOP_PICK_LVL 250
#define SHOP_DOOR PRIEST_OBJ_DIR "shop_door"

#define LOG_STEALS 1
#define STEAL_LOG PRIEST_LOG_DIR "steals_from_shops"

#define MILLER_TIME // let them booze and carouse a bit
#endif
