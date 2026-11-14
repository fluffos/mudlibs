//=========================================================================
//
// File:    def.h
// Created by Speedy
//
// Project: Sarumans Quest (Finde die verlorene Schriftrolle)
//
//=========================================================================

//#pragma strong_types

#define REGION     "gebirge"
#define MAGIERNAME "speedy"
#define GEBIET     "laby"

#define NPC     "/d/" REGION "/" MAGIERNAME "/" GEBIET "/npc/"
#define OBJ     "/d/" REGION "/" MAGIERNAME "/" GEBIET "/obj/"
#define ROOM    "/d/" REGION "/" MAGIERNAME "/" GEBIET "/room/"
#define LOG     "/d/" REGION "/" MAGIERNAME "/" GEBIET "/log/"
#define SAVEDIR "/d/" REGION "/" MAGIERNAME "/" GEBIET "/save/"
#define ARMOUR  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/armour/"
#define WEAPON  "/d/" REGION "/" MAGIERNAME "/" GEBIET "/weapon/"
#define SMASTER "/d/" REGION "/" MAGIERNAME "/" GEBIET "/master/smaster"

#define DB(x) if (find_player("ronja")) tell_object(find_player("ronja"),("XXX " + x))

#include <defines.h>
#include <moredef.h>
#include <properties.h>
#include <moving.h>
#include <combat.h>
#include <wizlevels.h>
#include <new_skills.h>
#include <class.h>
#include <mnpc.h>

#include <verben.h>
#include <guard.h>

#define QUEST_ITEM "\nspeedy_quest_laby"
#define SPEEDYLABYQUEST "Finde die verlorene Schriftrolle"
#define SPEEDYLABYQUESTLOG "/log/quests/sarumans_schriftrolle"

#define GETEXIT(x) ROOM "dung_"+x

#define ANSCHLUSS "/d/gebirge/dusty/weg/j22"

#define TELLPLAYER(x) tell_object(TP,x)
#define TELLOTHERS(x) tell_room(ENV(TP),x,({TP}))

#define TPUID getuuid(this_player())
#define UID(x) capitalize(getuid(x))
#define BSI(x,y) break_string(x,78,y,1)
#define CTPN capitalize(this_player()->name())

#define SARUMANID "\nspy_general"
#define NICHTDA "Sowas siehst Du da nicht!\n"
#define QUESTTIME 3*3600
#define DOOROPENED              "opened"
#define DOORCLOSED              "closed"

#define F_START                 0
#define F_KASTEN_AUF            1
#define F_TUER_B_OFFEN          2
#define F_ERDE_WEG              3
#define F_STEIN_GELOCKERT       4
#define F_KETTE_REPARIERT       5
#define F_TUER_F_OFFEN          6
#define F_TUER_G_OFFEN          7
#define F_TUER_H_OFFEN          8
#define F_KETTE_ANHAENGEN       9
#define F_TUER_K_OFFEN         10
#define F_MUENZE_WERFEN        11
#define F_KERZE_ZUENDEN        12
#define F_BETEN                13
#define F_GET_LOEFFEL          14
#define F_GET_SCHAUFEL         15
#define F_GET_KETTE            16
#define F_GET_ZETTEL           17
#define F_GET_HOLZ             18
#define F_GET_GUMMI            19
#define F_GET_MUENZE_R         20
#define F_GET_MUENZE_B         21
#define F_GET_MUENZE_G         22
#define F_GET_AMULETT          23
#define F_GET_SEIL             24
#define F_GET_STEIN            25
#define F_HEBEL_OK             26
#define F_KRAFTFELD            27
#define F_READ_TAFEL           28
#define F_GET_ROLLE            29
#define F_BRICH_SCHAEDEL       30
#define F_BIEGE_DRAHT          31
#define F_BEFESTIGE_HAKEN      32
#define F_BEFESTIGE_GUMMI      33
#define F_ROT_DRINNEN          34
#define F_BLAU_DRINNEN         35
#define F_GRUEN_DRINNEN        36
#define F_AMULETT_GEFUNDEN     37
#define F_AMULETT_REINGESTECKT 38
#define F_HEBELKISTE_WEG       39
#define F_HEBELKISTE_AUF       40
#define F_STEIN_DRAUSSEN       41
#define F_PLATTE_AUF           42
#define F_PLATTE_GEFUNDEN      43
#define F_LOCH_AUF             44
#define F_STAUB                45
#define F_KISTE_OFFEN          46
#define F_BODEN                47
#define F_KETTE_GEFUNDEN       48
#define N_FLAGS 49

#define S_KRAFTFELD          1000
#define S_KERZEN_AN          1001
#define S_KUPPEL_AUF         1002
#define S_KETTE_INHAND       1003
#define S_KISTE_WEG          1004
#define N_STATUS 5

