/*
 * Mudlib configuration file
 *
 * - Rumplemintz
 */

#ifndef MUDLIB_H
#define MUDLIB_H

/* Standard Mudlib Files */

#define ROOT_UID               "root"
#define SIMUL_EFUN             "obj/simul_efun"
#define SPARE_SIMUL_EFUN_FILE  "obj/simul_efun2"
#define BASE                   "inherit/base/base_obj"
#define ACTIONS                "inherit/base/actions"
#define DEBUG                  "obj/debug"
#define PLAYER                 "obj/player"
#define WIZARDOB               "obj/wizard"
#define MASTER                 "obj/master"
#define INIT_ACCESS            "obj/access.ini"
#define INIT_WORKROOM          "obj/workroom.ini"
#define SHUTD                  "obj/shut"

#define DEAD_ED                ".dead_ed_files"


/* General Mudlib Objects */
#define ARMOR                  "obj/armor"
#define LIVING                 "obj/living"
#define MONSTER                "obj/monster"
#define ROOM                   "room/room"
#define TREASURE               "obj/treasure"
#define MONEY                  "obj/money"
#define WEAPON                 "obj/weapon"
#define CONTAINER              "inherit/container"
#define EDITOR                 "obj/editor"
#define PAGER                  "obj/pager"
#define BANK                   "room/bank"
#define VOID                   "room/void"
#define CHURCH                 "room/church"
#define GUILD                  "room/adv_guild"
#define INNER                  "room/adv_inner"
#define POST_OFFICE            "room/post"
#define MORE_OB                "obj/more"
#define PASTE_DIR              "open/paste"


#define DEBUG_LOG              "/debug.log"


#define DATE(T) ctime(T)[4..10] + ((ctime(T)[20..23] == ctime(time())[20..23])\
 ? ctime(T)[11..15] : ctime(T)[20..23])

#define NL \n

#endif /* MUDLIB_H */

