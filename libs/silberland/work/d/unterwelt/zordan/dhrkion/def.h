//=========================================================================
//
// File:    def.h
// Created by ZORDAN@SL
//
// Project: DHRKION
//
//=========================================================================

#define GEBIET "dhrkion"

#include "../def.h"

#define DHRKIONMASTER "/d/" REGION "/" MAGIERNAME "/" GEBIET "/master/dhrkion"
#define DMASTER       "/d/" REGION "/" MAGIERNAME "/" GEBIET "/master/dhrkionmaster"
#define RUNENMASTER   "/d/" REGION "/" MAGIERNAME "/" GEBIET "/master/runenmaster"
#define JUWELENMASTER "/d/" REGION "/" MAGIERNAME "/" GEBIET "/master/juwelenmaster"
#define RWQMASTER     "/d/" REGION "/" MAGIERNAME "/" GEBIET "/master/rwqmaster"

#define DBR(x) if(find_player("ronja")) tell_object(find_player("ronja"),(x))

#define DHRKIONLOG    LOG "dhrkion.log"

#define RWQ_NAME "Das Schweigen der Rumpelwichte"

#define QUESTRUNE     "\n_runenquest_rune"
#define QUESTNAME     "Runen der Priesterin"
#define QUESTLOG      "/d/unterwelt/zordan/runenquest/log/"

#define QUESTJUWELID  "\n_juwel_der_quest"
#define QUESTJUWELNAME "Finde das Juwel"

#define BSI(x,y) break_string(x,78,y,1)

#define ADD_DROW_DETAIL( k, x, y) \
        AddDetail( (k), ([ 0 : (x), "dunkelelf" : (y) ]) )

