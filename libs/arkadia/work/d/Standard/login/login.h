/*
 *  Stale wykorzystywane przez procedure logowania sie postaci.
 *
 *  /d/Standard/login/login.h
 */

#include <pl.h>

/*
 * PATH
 *
 * The path in which the login rooms reside.
 */
#define PATH "/d/Standard/login/"

/* 
 * LOGIN_FILE_NEW_PLAYER_INFO
 *
 * This is the names of the files that are written to new users logging in.
 */
#define LOGIN_FILE_NEW_PLAYER_INFO "/d/Standard/doc/login/NEW_PLAYER_INFO"

/*
 * RACEMAP
 *
 * This mapping holds the names of the allowed player races in the game and
 * which player file to use for new characters of a given race.
 */
#define RACEMAP ([ \
	"czlowiek"	: "/d/Standard/race/czlowiek_std",	\
	"elf"		: "/d/Standard/race/elf_std",		\
	"krasnolud"	: "/d/Standard/race/krasnolud_std",	\
	"halfling"	: "/d/Standard/race/halfling_std",	\
	"gnom"		: "/d/Standard/race/gnom_std",		\
	"ogr"		: "/d/Standard/race/ogr_std",		\
                ])

/*
 * RACEATTR
 *
 * Mapping z atrybutami standardowych ras. Pierwszy element tablicy
 * odpowiada plci meskiej, drugi - zenskiej. Kolejne pola to:
 *	sredni wzrost		(cm)
 *	srednia waga		(kg)
 *      srednia gestosc liniowa	(g/cm) = srednia waga / sredni wzrost
 *
 * Przyjmujemy, ze ciezar wlasciwy wszystkich ras jest rowny ciezarowi
 * wlasciwemu wody.
 */
#define RACEATTR ([ \
	"czlowiek"	: ({({175,  75, 429}), ({165,  60, 364})}),	\
	"elf"		: ({({190,  60, 316}), ({185,  50, 270})}),	\
	"krasnolud"	: ({({140,  70, 500}), ({140,  60, 429})}),	\
	"halfling"	: ({({120,  55, 458}), ({115,  50, 435})}),	\
	"gnom"		: ({({120,  50, 417}), ({110,  45, 409})}),	\
	"ogr"		: ({({240, 180, 750}), ({220, 180, 818})}),	\
                ])

/*
 * RACESTATMOD
 *
 * This mapping holds the standard modifiers of each stat, i.e. a dwarf
 * should have it easier to raise con than other races, but get a harder
 * time raising its int.
 *
 *	race		:  str, dex, con, int, wis, dis, race, occ, lay
 */
#define RACESTATMOD ([ \
	"czlowiek"	: ({10,  10,  10,  10,  10,  10, 10, 10, 10}),	\
	"elf"		: ({ 7,  13,   8,  13,  12,   8, 10, 10, 10}),	\
	"krasnolud"	: ({12,   6,  13,   8,   9,  12, 10, 10, 10}),	\
	"halfling"	: ({ 7,  17,   8,  11,  10,   8, 10, 10, 10}),	\
	"gnom"		: ({ 8,  15,   7,  14,   9,   8, 10, 10, 10}),	\
	"ogr"		: ({16,   6,  14,   4,   5,  13, 10, 10, 10}),	\
                    ])

/*
 * Wartosci z Genesis, dla porownania.
 *
		"elf"    : ({ 7, 12, 8, 15, 14, 9, 10, 10, 10 }), \
                "dwarf"  : ({ 15, 5, 15, 8, 9, 13, 10, 10, 10 }), \
                "hobbit" : ({ 6, 22, 8, 10, 11, 9, 10, 10, 10 }), \
                "gnome"  : ({ 9, 14, 7, 19, 10, 8, 10, 10, 10 }), \
                "goblin" : ({ 18, 10, 16, 6, 10, 6, 10, 10, 10 }), \
 */

/*
 * Odmiana ras. (zmienic, by korzystac z <pl.h>.)
 */
#define ODMIANA_RASY ([ \
	"czlowiek"  : 	({ ({ "czlowiek", "czlowieka", "czlowiekowi",\
			"czlowieka", "czlowiekiem", "czlowieku" }),\
			({ "czlowiek", "czlowieka", "czlowiekowi",\
			"czlowieka", "czlowiekiem", "czlowieku" }) }),\
	"elf"       :	({ ({ "elf", "elfa", "elfowi", "elfa", "elfem",\
			"elfie" }), ({ "elfka", "elfki", "elfce", "elfke",\
			"elfka", "elfce" }) }),\
	"krasnolud" :	({ ({ "krasnolud", "krasnoluda", "krasnoludowi",\
			"krasnoluda", "krasnoludem", "krasnoludzie" }),\
			({ "krasnoludka", "krasnoludki", "krasnoludce",\
			"krasnoludke", "krasnoludka", "krasnoludce" }) }),\
	"halfling"    : ({ ({ "halfling", "halflinga", "halflingowi",	\
			"halflinga", "halflingiem", "halflingu" }),	\
			({ "halflinka", "halflinki", "halflince",	\
			"halflinke", "halflinka", "halflince" }) }),	\
	"ogr"       :   ({ ({ "ogr", "ogra", "ogrowi", "ogra", "ogrem", \
			"ogrze" }), ({ "ogrzyca", "ogrzycy", "ogrzycy",	\
			"ogrzyce", "ogrzyca", "ogrzycy" }) })		\
			])
			
#define ODMIANA_PRASY  ([\
	"czlowiek"  :	({ ({ "ludzie", "ludzi", "ludziom", "ludzi",\
			"ludzmi", "ludziach" }), ({ "ludzie", "ludzi",\
			"ludziom", "ludzi", "ludzmi", "ludziach" }) }),\
	"elf"       :	({ ({ "elfy", "elfow", "elfom", "elfy", "elfami",\
			"elfach" }), ({ "elfki", "elfek", "elfkom", "elfki",\
			"elfkami", "elfkach" }) }),\
	"krasnolud" :	({ ({ "krasnoludy", "krasnoludow", "krasnoludom",\
			"krasnoludy", "krasnoludami", "krasnoludach" }),\
			({ "krasnoludki", "krasnoludek", "krasnoludkom",\
			"krasnoludki", "krasnoludkami", "krasnoludkach" }) }),\
	"halfling"    :	({ ({ "halflingi", "halflingow", "halflingom",	\
			"halflingi", "halflingami", "halflingach" }),	\
			({ "halflinki", "halflinek", "halflinkom",	\
			"halflinki", "halflinkami", "halflinkach" }) }),\
	"ogr"       :   ({ ({ "ogry", "ogrow", "ogrom", "ogry",		\
			"ogrami", "ograch" }), ({ "ogrzyce", "ogrzyc",	\
			"ogrzycom", "ogrzyce", "ogrzycami", "ogrzycach" }) })\
			])
#define ODMIANA_RASY_OSOBNO ([\
			"czlowiek"  :	1,\
			"elf"	    :	0,\
			"krasnolud" :	0,\
			"halfling"  :   0,\
			"ogr"       :   0,\
			])
#define ODMIANA_RASY_RODZAJ ([\
			"czlowiek" 	: ({ PL_MESKI_OS, PL_ZENSKI }),	\
			"elf"		: ({ PL_MESKI_NOS_ZYW, PL_ZENSKI }),\
			"krasnolud"	: ({ PL_MESKI_NOS_ZYW, PL_ZENSKI }),\
			"halfling"	: ({ PL_MESKI_NOS_ZYW, PL_ZENSKI }),\
			"ogr"		: ({ PL_MESKI_NOS_ZYW, PL_ZENSKI }),\
			"duch"		: ({ PL_MESKI_NOS_ZYW, PL_MESKI_NOS_ZYW }),\
			])

/*
 * when m_indicex work on constants: m_indices(RACEMAP)
 */
#define RACES ({"czlowiek", "elf", "krasnolud", "halfling", /* "gnom", */\
                "ogr"})

#define RACES_SHORT ([ \
	"czlowiek"	: "czl",	\
	"elf"		: "elf",	\
	"krasnolud"	: "kra",	\
	"halfling"	: "hal",	\
	"gnom"		: "gno",	\
	"ogr"		: "ogr",	\
                    ])

/*
 * RACESTART
 *
 * This mapping holds the files of the starting locations for each race.
 */
#define RACESTART ([ \
	"czlowiek"	: ({ "/d/Standard/start/church", }),	\
	"elf"		: ({ "/d/Standard/start/church", }),	\
	"krasnolud"	: ({ "/d/Standard/start/church", }),	\
	"halfling"	: ({ "/d/Standard/start/church", }),	\
	"gnom"		: ({ "/d/Standard/start/church", }),	\
	"ogr"		: ({ "/d/Standard/start/church", }),	\
                  ])

/*
 * RACEPOST
 *
 * This mapping holds the files of the post offices locations for each race.
 */
#define RACEPOST ([ \
	"czlowiek"	: "/d/Standard/start/mailroom",	\
	"elf"		: "/d/Standard/start/mailroom",	\
	"krasnolud"	: "/d/Standard/start/mailroom",	\
	"halfling"	: "/d/Standard/start/mailroom",	\
	"gnom"		: "/d/Standard/start/mailroom",	\
	"ogr"		: "/d/Standard/start/mailroom",	\
                 ])

/*
 * RACESTAT
 *
 * This mapping holds the stats that each race has on start
 */
#define RACESTAT ([ \
	"czlowiek"	: ({10,  10,  10,  10,  10,  10, 10, 10, 10}),	\
	"elf"		: ({ 7,  13,   8,  13,  12,   8, 10, 10, 10}),	\
	"krasnolud"	: ({12,   6,  13,   8,   9,  12, 10, 10, 10}),	\
	"halfling"	: ({ 7,  17,   8,  11,  10,   8, 10, 10, 10}),	\
	"gnom"		: ({ 8,  15,   7,  14,   9,   8, 10, 10, 10}),	\
	"ogr"		: ({16,   6,  14,   4,   5,  13, 10, 10, 10}),	\
                    ])
#if 0
#define RACESTAT ([      /* str, dex, con, int, wis, dis */	\
	"czlowiek"	: ({  9,   9,   9,   9,   9,   9}),	\
	"elf"		: ({  6,  11,   7,  12,  11,   7}),	\
	"krasnolud"	: ({ 11,   5,  12,   7,   8,  11}),	\
	"halfling"	: ({  6,  15,   7,  10,   9,   7}),	\
	"gnom"		: ({  7,  13,   6,  13,   8,   7}),	\
	"ogr"		: ({ 15,   5,  13,   3,   4,  12}),	\
                 ])
#endif

/*
 * RACESKILL
 *
 * Poczatkowe umiejetnosci roznych ras.
 */
#define RACESKILL ([ \
	"czlowiek"	: ([		\
		SS_WEP_SWORD	: 4,	\
		SS_PARRY	: 4,	\
		SS_APPR_VAL	: 3,	\
		SS_SWIM		: 3,	\
		SS_TRADING	: 5,	\
		/* 64 + 51 + 13 + 13 + 62 = 203 cc */\
                          ]),		\
	"elf"		: ([		\
		SS_WEP_KNIFE	: 3,	\
		SS_DEFENCE	: 5,	\
		SS_HERBALISM	: 3,	\
		SS_SNEAK	: 3,	\
		SS_LOC_SENSE	: 3,	\
		SS_TRACKING	: 3,	\
		/* 29 + 100 + 18 + 18 + 13 + 13 = 201 cc */\
                          ]),		\
	"krasnolud"	: ([		\
		SS_WEP_AXE	: 5,	\
		SS_PARRY	: 4,	\
		SS_APPR_MON	: 4,	\
		SS_APPR_VAL	: 4,	\
		/* 87 + 51 + 32 + 32 = 202 cc */\
                          ]),		\
	"halfling"	: ([		\
		SS_WEP_KNIFE	: 4,	\
		SS_DEFENCE	: 4,	\
		SS_HERBALISM	: 5,	\
		SS_HIDE		: 3,	\
		SS_ANI_HANDL	: 3,	\
		/* 29 + 51 + 87 + 18 + 13 = 198 cc */\
                          ]),		\
	"gnom"		: ([		\
		SS_WEP_KNIFE	: 3,	\
		SS_DEFENCE	: 3,	\
		SS_OPEN_LOCK	: 3,	\
		SS_APPR_OBJ	: 3,	\
		SS_APPR_VAL	: 3,	\
		SS_CLIMB	: 3,	\
		SS_TRADING	: 5,	\
		/* Nie zbalansowane jeszcze. Zrobi sie pozniej. */\
                          ]),		\
	"ogr"		: ([		\
		SS_WEP_CLUB	: 5,	\
		SS_DEFENCE	: 3,	\
		SS_UNARM_COMBAT	: 5,	\
		SS_APPR_MON	: 2,	\
		/* 62 + 21 + 112 + 4 = 199 cc */\
                          ]),		\
                  ])
/*
 * RACEMISCCMD
 *
 * This mapping holds the files of the souls that should be used as
 * misc command soul for each race
 */
#define RACEMISCCMD ([ \
	"czlowiek"	: "/d/Standard/cmd/misc_cmd_czlowiek",	\
	"elf"		: "/d/Standard/cmd/misc_cmd_elf",	\
	"krasnolud"	: "/d/Standard/cmd/misc_cmd_krasnolud",	\
	"halfling"	: "/d/Standard/cmd/misc_cmd_halfling",	\
	"gnom"		: "/d/Standard/cmd/misc_cmd_gnom",	\
	"ogr"		: "/d/Standard/cmd/misc_cmd_ogr",	\
                    ])

/*
 * RACESOULCMD
 *
 * This mapping holds the files of the souls that should be used as
 * standard command soul for each race
 */
#define RACESOULCMD ([ \
	"czlowiek"	: "/d/Standard/cmd/soul_cmd_czlowiek",	\
	"elf"		: "/d/Standard/cmd/soul_cmd_elf",	\
	"krasnolud"	: "/d/Standard/cmd/soul_cmd_krasnolud",	\
	"halfling"	: "/d/Standard/cmd/soul_cmd_halfling",	\
	"gnom"		: "/d/Standard/cmd/soul_cmd_gnom",	\
	"ogr"		: "/d/Standard/cmd/soul_cmd_ogr",	\
                    ])

/*
 * RACESOUND
 *
 * What sound do mainindex-race hear when subindex race speaks
 */
#define RACESOUND ([ \
	"czlowiek"	: ([			\
		"czlowiek"	: "mowi",	\
		"elf"		: "mowi",	\
		"krasnolud"	: "szepce",	\
		"halfling"	: "mowi",	\
		"gnom"		: "syczy",	\
		"ogr"		: "marudzi",	\
                          ]),			\
	"elf"		: ([			\
		"czlowiek"	: "spiewa",	\
		"elf"		: "mowi",	\
		"krasnolud"	: "nuci",	\
		"halfling"	: "spiewa",	\
		"gnom"		: "nuci",	\
		"ogr"		: "zawodzi",	\
                          ]),			\
	"krasnolud"	: ([			\
		"czlowiek"	: "dudni",	\
		"elf"		: "mruczy",	\
		"krasnolud"	: "mowi",	\
		"halfling"	: "dudni",	\
		"gnom"		: "huczy",	\
		"ogr"		: "brzeczy",	\
                          ]),			\
	"halfling"	: ([			\
		"czlowiek"	: "nuci",	\
		"elf"		: "nuci",	\
		"krasnolud"	: "spiewa",	\
		"halfling"	: "mowi",	\
		"gnom"		: "mowi",	\
		"ogr"		: "piszczy",	\
                          ]),			\
	"gnom"		: ([			\
		"czlowiek"	: "mowi",	\
		"elf"		: "skrzypi",	\
		"krasnolud"	: "syczy",	\
		"halfling"	: "skrzypi",	\
		"gnom"		: "mowi",	\
		"ogr"		: "skrzeczy",	\
                          ]),			\
	"ogr"		: ([			\
		"czlowiek"	: "burczy",	\
		"elf"		: "dudni",	\
		"krasnolud"	: "bulgocze",	\
		"halfling"	: "grzmi",	\
		"gnom"		: "grzmi",	\
		"ogr"		: "mowi",	\
                          ]),			\
                  ])

/*
 * HEIGHTDESC
 */
#define HEIGHTDESC(x)	({ "niespotykanie nisk" + x, "bardzo nisk" + x,	\
			   "nisk" + x, "przecietnego wzrostu",		\
			   "wysok" + x, "bardzo wysok" + x,		\
			   "niespotykanie wysok" + x })

/*
 * WIDTHDESC
 */
#define WIDTHDESC(x)	({ "bardzo chud" + x, "chud" + x,		\
			   "szczupl" + x, "przecietnej wagi",		\
			   "lekko otyl" + x, "otyl" + x,		\
			   "bardzo otyl" + x })

/*
 * HEIGHTPROC
 * WIDTHPROC
 *
 * Kazdy gracz powinien miec wzrost i wage (procentowo, w stosunku do
 * standardowego wzrostu i standardowej dla wzrostu gracza wagi) nie
 * mniejsza od pierwszego elementu tablicy i mniejsza od ostatniego.
 * Kolejne przedzialy odpowiadaja kolejnym opisom z HEIGHTDESC i
 * WIDTHDESC. Oznacza to zmiennosc wzrostu +/- 17% i wagi +/- 31%.
 */
#define HEIGHTPROC	({83, 88, 93, 98, 103, 108, 113, 118})
#define WEIGHTPROC	({69, 78, 87, 96, 105, 114, 123, 132})

#define LOGIN_NO_NEW	"/d/Standard/login/no_new_players"
#define CONVERT_OLD	"/d/Standard/login/convert_old_players"

/*
 * This is the current state of this ghost (uses set_ghost() / query_ghost())
 */
#define GP_INTRO        1
#define GP_BODY		2
#define GP_EMAIL	4
#define GP_FEATURES	8
#define GP_SKILLS       16
#define GP_NEW          (GP_BODY | GP_EMAIL | GP_FEATURES | GP_SKILLS)
#define GP_CONVERT      32
#define GP_DEAD         64
