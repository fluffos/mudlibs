// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/money.h
// Description:	Defines fuer Geld
//
// $Log: money.h,v $
// Revision 1.7  2016/09/11 02:26:51  myonara
// neue Defines ZB_BANK_FILE_PATTERN und ZB_BANK_DATA_CACHE
//
// Revision 1.6  2016/09/03 14:44:47  myonara
// Erweiterung fuer SChliessfaecher, intialer Mudlibstand.
//
// Revision 1.5  2008-04-02 08:42:11  gnomi
// Defines fuer Kompatibilitaets-IDs.
//
// Revision 1.4  2006/01/13 08:23:31  gnomi
// Defines fuer den Verkaeufer.
//
// Revision 1.3  2003/01/26 03:52:29  gnomi
// Defines fuer Waehrungflags.
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef MONEY_H
#define MONEY_H 1

#define ZENTRALBANK "/apps/zentralbank"

#define PATH_ROOM_BANK "/room/bank/"
#define ZB_SCHLIESSFAECHER  PATH_ROOM_BANK "obj/schliessfaecher"
#define ZB_SCHLIESSFACH     PATH_ROOM_BANK "obj/schliessfach"
#define ZB_ANLEITUNG_SF     PATH_ROOM_BANK "Anleitung"
#define ZB_KRITERIEN        PATH_ROOM_BANK "Kriterien"
#define ZB_BANKENAUFSICHT   PATH_ROOM_BANK "bankenaufsicht"
#define ZB_TEST_FACTORY     PATH_ROOM_BANK "test_factory"

#define ZB_DEBUGLOG(m,s,u,c) (ZENTRALBANK->debuglog(m,s,u,c))

#define ZB_SCHLIESSFACH_ID      "zentralbank # schliess # fach"
#define ZB_SCHLIESSFAECHER_ID   "zentralbank # schliess # faecher"
#define ZB_ARMATESTER_ID        "zentralbank # arma # tester"

#define ARMA_FACTORY     "Root:Arma:Factory:File"
#define ARMA_FACTORY_ID  "Root:Arma:Factory:Indentifier"
#define ARMA_OBJECT_DATA "Root:Arma:Data:Object"
#define ARMA_SHADOW_DATA "Root:Arma:Data:Shadow"
#define ARMA_MUDLIB_DATA "Root:Arma:Data:Mudlib"
#define ARMA_CONTENT_DATA "Root:Arma:Data:Content"
#define ARMA_LOAD_FILE   "Root:Arma:LoadFile"
#define ARMA_SPECIAL_ID  "Root:Arma:Special:ID"
#define ARMA_ORIGIN_INFO "Root:Arma:Origin:Info"
#define ARMA_FILE_COUNTER "Root:Arma:File:Counter"

// Bankenflags
#define ZB_BANK_CLASSIC         0x1000
#define ZB_BANK_ENVIRONMENT     0x2000
#define ZB_BANK_PANTHEON        0x4000
#define ZB_BANK_SAFEROOM        0x8000
#define ZB_F_SAFE_LOCKED        0x0001
#define ZB_F_SAFE_TROPHY        0x0002
#define ZB_BANK_ACTIVE          0x0010
#define ZB_F_WAREHOUSE_STORE    0x0020
#define ZB_F_VALID_CONTAINER    0x0040
#define ZB_F_VALID_IN_CONTAINER 0x0080
#define ZB_F_SPECIAL_CONTAINER  0x0100
// Mappingkeys fuer Bankeninfo
#define ZB_BANK_ID              "zentralbank:bank:id"       // String
#define ZB_BANK_TITLE           "zentralbank:bank:title"    // String
#define ZB_BANK_FLAGS           "zentralbank:bank:flags"    // int
#define ZB_BANK_WIZARD          "zentralbank:bank:wizard"   // Object
#define ZB_BANK_WITH_ERROR      "zentralbank:bank:error"    // 0/1
#define ZB_BANK_OWNER           "zentralbank:bank:owner"    // string
#define ZB_BANK_FILE            "zentralbank:bank:file"     // string
#define ZB_BANK_FILE_PATTERN    "zentralbank:bank:file:pattern"// string
#define ZB_BANK_ITEMID          "zentralbank:bank:itemid"   // string
#define ZB_BANK_OUTPUT          "zentralbank:bank:output"   // string
#define ZB_BANK_SORTBY          "zentralbank:bank:sortby"   // string
#define ZB_BANK_CURRENCY        "zentralbank:bank:currency" // string
#define ZB_DATA_CACHE           "zentralbank:data:cache"  // internes mapping
#define ZB_BANK_REPLACE_WITH    "zentralbank:bank:replace_with" // string

// Flags fuer Banken-NPCs
#define ZB_NPC_BANKIER              0x0001
#define ZB_NPC_GELD_WECHSLER        0x0002
#define ZB_NPC_BANKIER_WECHSLER     0x0003

// Rueckgabewerte von query_money_info
#define MONEY_VALUTA  0
#define MONEY_VALUTAS 1
#define MONEY_GENDER  2
#define MONEY_KURS    3
//freiwillige Angaben:
#define MONEY_FLAGS   4
#define MONEY_SG_IDS  5
#define MONEY_PL_IDS  6

// Flags:
#define MONEY_NOT_DEKLIN	0x01

// Gruende fuer deliver()
#define VD_NORMAL	0
#define VD_RECP_FULL	1
#define VD_RECP_UNAVAIL	2

#endif // MONEY_H
