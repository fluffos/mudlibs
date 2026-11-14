/*  Mudlib Configuration File */

#ifndef MUDLIB_H
#define MUDLIB_H

#define MUD_VERSION "v2.07"  /* Version of Heaven7 mudlib */

/********************************************************************/
/* Define One of the following Lpmud Driver Types                   */

/* Notes:  Although the mudlib will run in native mode, its natural */
/*         configuration is COMPAT.  So security is not base upon   */
/*         euid, and uid.                                           */
/*                                                                  */
/*         Mudlib will autoconfig for MUDOS, AMYLAAR and            */
/*         NATIVE_MODE. Define OK312 for the old msdos driver       */
/*                                                                  */

/* #define OK312          ok312 msdos driver           */


/***********************************************************************/
/* Things that will change from site to site */

#ifndef MUD_NAME
#define MUD_NAME        "Heaven7"
#endif
#define INTERMUD_NAME   "Hvn7"


/***********************************************************************/
/* You don't need to alter anything below here                         */
/***********************************************************************/
/* Auto-config some stuff */

#ifndef COMPAT_FLAG
#define NATIVE_MODE
#define UID_ROOT     "Root"
#define UID_BACKBONE "Backbone"
#define UID_TYPE string
#else
#define UID_ROOT     1
#define UID_TYPE int
#endif /* COMPAT_FLAG */


#ifdef MUDOS       

#define MUDOS_DR
#define HAVE_WIZLIST 2

#else /* !MUDOS */

#ifdef __VERSION__

#if __VERSION__ > "03.02.1@0" && __VERSION__ < "03.02.1@999"
#define AMYLAAR321
#endif

#if __VERSION__ > "03.02@0" && __VERSION__ < "03.02@999"
#define AMYLAAR
#endif

#ifdef AMYLAAR321
#define AMYLAAR
#endif

#else /* !__VERSION__ */

#if !defined(OK312)
#define DR312
#endif /* !OK312 */

#define HAVE_WIZLIST 1

#endif /* !__VERSION__ */

#endif /* !MUDOS */


/***********************************************************************/
/* Driver Configuration */

#undef VERSION
#define DEBUG_LOG   "/"+ query_host_name() +".debug.log"



	/*************************************/
	/* configure for MSDOS 3.1.2 version */
	/*************************************/

#if defined(OK312)          

#define MASTER312   
#define MSDOS
#define OLD_EXPLODE

#ifdef NATIVE_MODE
#define VERSION "3.1.2 MS-DOS Native"
#else
#define VERSION "3.1.2 MS-DOS Compat"
#endif
#undef DEBUG_LOG
#define DEBUG_LOG              "/debug.log"

#endif /* OK312 */


	/***********************/
	/* configure for 3.1.2 */
	/***********************/

#if defined(DR312)            

#define MASTER312
#define OLD_EXPLODE

#ifdef NATIVE_MODE
#define VERSION "3.1.2 Native"
#else
#define VERSION "3.1.2 Compat"
#endif

#endif /* 3.1.2 */


	/********************************/
	/* configure for 0.9.1.93 MUDOS */
	/********************************/
	
#if defined(MUDOS_DR)         

#ifdef MSDOS
#define VERSION "OK09193c MS-DOS mudOS"
#undef DEBUG_LOG
#define DEBUG_LOG              "/log/debug.log"
#else
#define VERSION "mudOS"
#endif

#endif /* ok09193 msdos mudos */


	/********************************/
	/* configure for Amylaar Driver */
	/********************************/
	
#if defined(AMYLAAR)

#if defined(AMYLAAR321) || __VERSION__ > "03.02@156"
#define HAVE_WIZLIST 0
#else
#define HAVE_WIZLIST 1
#endif 

#ifdef NATIVE_MODE
#define VERSION "Amylaar "+ __VERSION__ +" Native"
#else
#define VERSION "Amylaar "+ __VERSION__ +" Compat"
#endif
#ifdef MSDOS
#undef DEBUG_LOG
#define DEBUG_LOG "/debug.log"
#endif /* MSDOS */
#endif /* AMYLAAR */

/*****************************************************************/

#ifdef MSDOS
#define DEAD_ED      "dead_ed"
#define ED_SAVE      "_edrc"
#endif

#ifndef DEAD_ED
#define DEAD_ED      ".dead_ed_files"
#endif

#ifndef ED_SAVE
#define ED_SAVE      ".edrc"
#endif


/**********************************************************************/
/* Main Mudlib Files  */

#define SIMUL_EFUN             "obj/sim_ef_1"
#define SPARE_SIMUL_EFUN_FILE  "obj/sim_ef_2"  /* Not used in MUDos */
#define BASE                   "inherit/base/base_obj"
#define ACTIONS                "inherit/base/actions"
#define PLAYER                 "obj/player"
#define WIZARD                 "obj/wizard"
#define MASTER                 "obj/master"
#define DOMAIN_DIR             "/d/"
#define WIZARD_DIR             "/players/"


/****************************************************************/
/* Intermud */

#if defined(AMYLAAR) && !defined(MSDOS)
#define INTERMUD          1
#endif
#define UDP_CMD_DIR       "secure/UDP_CMD_DIR/"
#define INETD             "secure/inetd"

/***********************************************************************/
/* General Mudlib  */

#define ARMOUR            "inherit/armour"
#define CLOTHING          "inherit/clothing"
#define LIVING            "inherit/base/living"
#define MONSTER           "inherit/monster"
#define ROOM              "inherit/room2"
#define TREASURE          "inherit/treasure"
#define MONEY             "obj/money"
#define WEAPON            "inherit/weapon"
#define CONTAINER         "inherit/contain"
#define BANK              "inherit/std_bank"
#define PUB               "inherit/std_pub"
#define VOID              "room/void"
#define CHURCH            "room/city/cleric/hall4"
#define GUILD             "inherit/guild"
#define INNER             "room/city/creator/inner1"
#define POST_OFFICE       "room/city/post"
#define MAIL_DIR          "room/post/"
#define PASTE_DIR         "open/paste"
#define MORE_OB           "obj/more"
#define MAGIC_WAND        "objects/wand"
#define MAGIC_WEAPON      "inherit/m_weapon"
#define MAGIC_ARMOUR      "inherit/m_armour"
#define MAGIC_SCROLL      "objects/scroll"
#define MAGIC_POTION      "objects/potion"
#define UNDEAD            "inherit/undead"
#define BULLETIN          "obj/bulletin"
#define BULLETIN_BOARD    BULLETIN
#define SIGN              "inherit/sign"
#define WAND              "inherit/wand"
#define SHUTD             "obj/shut"
#define FOOD              "inherit/food"
#define DRINK             "inherit/drink"
#define STORE             "inherit/store"



/**********************************************************/
/* template files used by create_wizard() ('promote' cmd) */

#define INIT_ACCESS            "obj/access.ini"
#define INIT_WORKROOM          "obj/workroom.ini"

#if defined(AMYLAAR321)
#define INIT_FILE              "/room/init_file"
#endif

/*****************************************************************/
/* If the following are not defined, the relavent object will be */
/* removed from usuage in player objects.                        */   

#define PARTY_DAEMON      "obj/party/party_d"
#define MAIL_FIELD_LOADER "obj/mail_ldr"
#define MAILER            "obj/mail_rdr"
#define EDITOR            "obj/editor"
#define PAGER             "obj/pager"
#define DEBUG             "obj/debug"
#define SOUL              "obj/soul"
#define SOUL_FUNC_FILE    "/obj/soul_fcn.lpc"
#define QUEST_ROOM        "room/registry/quest_registry"
/*
#define USE_DEBUG */ /* force use of obj/debug as interactive object */


/******************************************************************/
/* a shorter time string */

#define DATE(T) ctime(T)[4..10]+((ctime(T)[20..23] == ctime(time())[20..23])\
 ? ctime(T)[11..15] : ctime(T)[20..23])


#endif /* MUDLIB_H */
