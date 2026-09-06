#ifndef SYS_CONFIG_H
#define SYS_CONFIG_H

// Mudspecific

#define MUDNAME  "Micro"      // The name of the mud
#define MUDDIR   "micro"      // name of the Mud-'domain' directory
#define MUDPATH  "/d/micro/"  // full path of the Mud-'domain' directory

#define LIBVERSION  0         // Version of the mudlib
#define LIBREVISION 2         // Revision of the mudlib

#define MICROMUD 1            // Mudspecific symbol

// Global objects

#define MASTER            "/secure/master"            // the master object
#define SIMUL_EFUN        "/secure/simul_efun"        // normal simul_efun file
#define SPARE_SIMUL_EFUN  "/secure/spare_simul_efun"  // reserve simul_efun file
#define LOGIN             "/secure/login"             // login object
#define SECUREINFO        "/secure/info"              // manager of passwords and levels
#define USERINFO          "/adm/svc/info"             // playerdata info server
#define ARMAGEDDON        "/adm/obj/armageddon"       // Shutdown object

// Basic uids - the leading '!' is mandatory!

#define ROOTID     "!1"        // Root objects
#define ADMINID    "!admin"    // Admin objects
#define ARCHID     "!arch"     // Archwiz objects
#define LORDID     "!lord"     // Domain lord objects
#define MEMBERID   "!member"   // Domain member objects
#define WIZARDID   "!wizard"   // Wizard objects
#define PLAYERID   "!player"   // Player objects
#define PRIVATEID  "!private"  // Private objects
#define BOTTOMID   "!0"        // Lowest objects

#define SHUTNAME   "armageddon"  // the living name of Armageddon

// Wizlevels - easier to handle than uids

#define PLAYER_LVL   0  // Player
#define LEARNER_LVL  1  // Apprentice wizards.
#define WIZARD_LVL   2  // Wizards
#define ARCH_LVL     3  // Archwizards and -vices
#define ADMIN_LVL    4  // Janitors

// Domainlevels - valid only in domain contextes

#define MEMBER_LVL  1  // Domainmembers
#define LORD_LVL    2  // Domainlords and -vices

#include "/i/sys/efun.h"

#endif
