#define QUESTNAME "Der vergessene Brief"

#define SAVEFILE "briefmaster"
#define BRIEFMASTER "/d/wueste/gwenshara/estadt/master/briefmaster"
#define DOORROOM "/d/wueste/gwenshara/estadt/room/stadt/2c2_post"

// Stati der Quest
#define Q_MAX_STATUS 11
#define Q_STATUS_STARTED 0 // Quest gerade begonnen
#define Q_STATUS_BINGO   1 // Brief bei Bingo abgeliefert
#define Q_STATUS_XELINDO 2 // Brief bei Xelindo abgeliefert
#define Q_STATUS_TARG    3 // Paket bei Targ abgeliefert
#define Q_STATUS_ZECHUS  4 // Paket bei Zechus abgeliefert
#define Q_STATUS_ARTANOK 5 // Brief bei Artanok abgeliefert
#define Q_STATUS_FEENKOE 6 // Brief an die Feenkoenigin
#define Q_STATUS_DELFENK 7 // Paket an die Dunkelelfenkoenigin
#define Q_STATUS_LANDAR  8 // Brief an Landar
#define Q_STATUS_GOUVERN 9 // Paket fuer den Gouverneur
#define Q_STATUS_MURGIN 10 // Brief an Murgin
#define Q_STATUS_END    11 // Quest abgeschlossen

#define BRIEFOBJ ({"bingo", "xelindo", "targ", "zechus", "artanok", "feenk",\
                   "delfenk", "landar", "gouverneur", "murgin"})