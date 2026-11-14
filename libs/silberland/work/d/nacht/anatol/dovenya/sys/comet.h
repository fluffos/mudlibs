

#ifndef __CASINO_COMET_H__
#define __CASINO_COMET_H__

// referenzierte ID der Jetons

#define JETONID "casino_comet_je\to\n"
#define VIPID "casino_comet_vip_je\to\n"
#define CROUPIERID "casino_comet_croupier_o\n_du\ty"

#define ADD_JETONS(player,jetons) \
    call_other(DOVENYA_ROOM "comet_roulette", "AddJetons", player, jetons)
#define HAS_JETONS(player,jetons) \
    call_other(DOVENYA_ROOM "comet_roulette", "HasJetons", player, jetons)
#define RECALC_VIP(player) \
    call_other(DOVENYA_ROOM "comet_roulette", "RecalcVip", player)

#define IS_VIP(player) \
    call_other(DOVENYA_ROOM "comet_roulette", "IsVip", player)

// Spielerkonfiguration (Property im Spieler)

#define P_COMET "comet"
#define COMET_ROULETTE "roulette"
#define COMET_LANG 0           // Sprache
#define COMET_GFX  1           // ASCII-Grafik?
#define COMET_AUTOCOLLECT  2   // Gewinne automatisch einziehen


#define BET_TIME            0 // int Zeitstempel
#define BET_CHANCE          1 // Pointer in die Struktur.
#define BET_STAKE           2 // int
#define BET_OWNER           4 // /magier:anatol (file_name)
#define BET_STATUS          5 // Prison
#define BET_CHANCE_NAME     6 // String, um nicht jedesmal rumsuchen zu muessen
#define BET_OWNER_UUID      7 // UUID, ... falls spieler
#define BET_TEST_ONLY       8 // Testspieler, Magier, NPCs ... Whatever!
#define BET_LOCKED          9 // Announcierte Wetten bleiben 1 runde liegen.


#define STATISTIC_SUMMARY 0
// Do not use 1, 2 .. 35.

// Information je Quote und einmal zusammengefasst:
#define WON                 0  // Array-Element 0
#define LOST                1  // Array-Element 1

#define STATISTICS_NUMBERS  0
#define STATISTICS_BALANCE  1
#define STATISTICS_PLAYERS  2
#define STATISTICS_SPECIAL  100

#define STC_BALANCE         0  // Plusminus fuer die Wettquote
#define STC_AVERAGE         1  // Mittlere Wetthoehe fuer die Wettquote
#define STC_COUNTS          2  // Anzahl gewonnener und verlorener Wetten
#define STC_MAX             3  // Hoechste Gewonnene/Verlorene Wette (Einsatz)
#define STC_TOP             4  // Berechnbar, nur im Summary


#define VIP_BASIC           1
#define VIP_SILVER          2
#define VIP_GOLD            3
#define VIP_PLATINUM        4
#define VIP_OCTARINE        5

#define SPECIAL_VIP         0
#define SPECIAL_HIDE        1

#endif

