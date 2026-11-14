// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/apps.h
// Description: Enthaelt defines fuer Pfade von base mudlib tools
// Author:	Garthan (24.05.94)
//
// $Log: apps.h,v $
// Revision 1.12  2013-03-16 16:08:17  gnomi
// Twitter und Achievements eingebaut.
//
// Revision 1.11  2003/10/11 11:21:12  sissi
// NPC_FINGER aufgenommen.
//
// Revision 1.10  2003/05/06 02:40:37  gnomi
// DOMAIN_INFOS eingefuehrt. STARTRAUM_SERVER verweist auf DOMAIN_INFOS.
//
// Revision 1.9  2002/01/12 21:19:46  gnomi
// Define fuer LOG_AL rausgenommen, da es diesen Master nicht mehr gibt.
//
// Revision 1.8  2001/04/19 23:40:34  freaky
// ROOM_AUTOLOAD eingefuehrt.
//
// Revision 1.7  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef APPS_H
#define APPS_H 1

#define TELE_MASTER	     "/apps/tele_master"
#define TOWN_MASTER	     "/apps/town"
#define HELP_TOOL	     "/apps/help_tool"
#define HLP_ORTE	     "/apps/hlp_orte"
#define GOETTER_REGISTER     "/apps/goetter_register"
#define CLOSURE_CONTAINER    "/apps/closure_container"
#define STORE_MASTER         "/apps/store_master"
#define BANISHD              "/apps/banishd"
#define FILED                "/apps/filed"
#define SECOND               "/apps/second"
#define FAILD                "/apps/faild"
#define IP_FILTER	     "/apps/ip_filter"
#define STATISTIK            "/apps/statistik"
#define WAHLEN		     "/apps/wahlen"
#define OBJECT_STATS         "/apps/object_stats"
#define SPIELERRAT           "/apps/spielerrat"
#define SPIELERRATSARCHIV    "/apps/spielerratsarchiv"
#define MONSTER_MASTER	     "/apps/monster_master"
#define SKILL_CHECKER        "/apps/skill_checker"
#define GROUP_MASTER         "/apps/groups"
#define GILDENSKILL_OB       "/apps/gildenskills"
#define WISSEN_MASTER        "/apps/wissen_master"
#define CONTROL              "/apps/control"
#define PLUGIN_MASTER        "/apps/plugin"
#define KOORDINATEN_MASTER   "/apps/koordinaten"
#define TIPS_MASTER          "/apps/tips"
#define ROOM_AUTOLOAD        "/apps/room_autoload"
#define DOMAIN_INFOS	     "/apps/domains"
#define NPC_FINGER           "/apps/npcfinger"
#define STARTRAUM_SERVER     DOMAIN_INFOS
#define TWITTERD             "/apps/twitterd"
#define ACHIEVEMENTS         "/apps/achievements"

#endif // APPS_H
