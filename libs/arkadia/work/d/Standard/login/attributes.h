#define L_M_HUMAN		1
#define L_F_HUMAN		2
#define L_M_ELF			4
#define L_F_ELF			8
#define L_M_DWARF		16
#define L_F_DWARF		32
#define L_M_HALFLING		64
#define L_F_HALFLING		128
#define L_M_GNOME		256
#define L_F_GNOME		512
#define L_M_OGRE		1024
#define L_F_OGRE		2048

#define L_ALL			4095		/* 2^12 - 1 */

#define L_HUMAN			(L_M_HUMAN | L_F_HUMAN)
#define L_ELF			(L_M_ELF | L_F_ELF)
#define L_DWARF			(L_M_DWARF | L_F_DWARF)
#define L_HALFLING		(L_M_HALFLING | L_F_HALFLING)
#define L_GNOME			(L_M_GNOME | L_F_GNOME)
#define L_OGRE			(L_M_OGRE | L_F_OGRE)

#define L_MALE			(L_ALL / 3)
#define L_FEMALE		(2 * L_MALE)

#define L_BEARDED		(L_MALE & ~L_M_ELF | L_F_DWARF)

#define L_RACE2L_MAP		(["czlowiek":	L_HUMAN,	\
                                  "elf":	L_ELF,		\
                                  "krasnolud":	L_DWARF,	\
                                  "halfling":	L_HALFLING,	\
                                  "gnom":	L_GNOME,	\
                                  "ogr":	L_OGRE])

#define L_RACE(pl)		(L_RACE2L_MAP[(pl)->query_race()])
#define L_G_RACE(pl)		((pl)->query_gender() == G_FEMALE ? \
                                 2 * L_RACE(pl) / 3 : L_RACE(pl) / 3)

#define L_A_BRODA ({ 							\
        ({"bialobrody", "bialobrodzi", L_BEARDED}),			\
        ({"blekitnobrody", "blekitnobrodzi", L_DWARF}),			\
        ({"brodaty", "brodaci", L_BEARDED}),				\
        ({"ciemnobrody", "ciemnobrodzi", L_BEARDED}),			\
        ({"czarnobrody", "czarnobrodzi", L_BEARDED}),			\
        ({"czerwonobrody", "czerwonobrodzi", L_BEARDED}),		\
        ({"dlugobrody", "dlugobrodzi", L_BEARDED}),			\
        ({"jasnobrody", "jasnobrodzi", L_BEARDED}),			\
        ({"krotkobrody", "krotkobrodzi", L_BEARDED}),			\
        ({"ognistobrody", "ognistobrodzi", L_BEARDED & ~L_OGRE}),	\
        ({"ogolony", "ogoleni", L_BEARDED & ~L_DWARF & ~L_OGRE}),	\
        ({"plomiennobrody", "plomiennobrodzi", L_DWARF}),		\
        ({"pomaranczowobrody", "pomaranczowobrodzi", L_DWARF}),		\
        ({"rudobrody", "rudobrodzi", L_BEARDED}),			\
        ({"sinobrody", "sinobrodzi", L_BEARDED}),			\
        ({"siwobrody", "siwobrodzi", L_BEARDED}),			\
        ({"zarosniety", "zarosnieci", L_BEARDED & ~L_F_DWARF}),		\
        ({"zielonobrody", "zielonobrodzi", L_DWARF}),			\
        ({"zoltobrody", "zoltobrodzi", L_BEARDED}),			\
})

#define L_A_BUDOWA ({ 							\
        ({"barczysty", "barczysci", L_M_HUMAN | L_DWARF}),		\
        ({"barylkowaty", "barylkowaci", ~L_ELF}),			\
        ({"beczkowaty", "beczkowaci", ~L_ELF}),				\
        ({"brzuchaty", "brzuchaci", L_MALE & ~L_M_ELF}),		\
        ({"chudy", "chudzi", ~L_DWARF & ~L_HALFLING}),			\
        ({"ciezki", "ciezcy", L_HUMAN | L_DWARF | L_OGRE}),		\
        ({"dlugonogi", "dlugonodzy", L_HUMAN | L_ELF}),			\
        ({"dlugoreki", "dlugorecy", L_HUMAN | L_OGRE}),			\
        ({"garbaty", "garbaci", ~L_ELF & ~L_HALFLING}),			\
        ({"grubonogi", "grubonodzy", L_HUMAN | L_OGRE}),		\
        ({"gruby", "grubi", ~L_ELF & ~L_GNOME}),			\
        ({"kablakonogi", "kablakonodzy", ~L_ELF & ~L_HALFLING}),	\
        ({"koscisty", "koscisci", ~L_HALFLING}),			\
        ({"koslawy", "koslawi", ~L_ELF & ~L_HALFLING}),			\
        ({"krepy", "krepi", L_MALE & ~L_M_ELF | L_F_DWARF}),		\
        ({"krotkonogi", "krotkonodzy", ~L_ELF}),			\
        ({"krzywonogi", "krzywonodzy", ~L_ELF & ~L_HALFLING}),		\
        ({"kulawy", "kulawi", ~L_ELF & ~L_HALFLING}),			\
        ({"lekki", "lekcy", ~L_DWARF & ~L_OGRE}),			\
        ({"maly", "maly", L_GNOME | L_OGRE}),				\
        ({"masywny", "masywni", L_M_HUMAN | L_DWARF | L_OGRE}),		\
        ({"muskularny", "muskularni", L_M_HUMAN | L_DWARF | L_OGRE}),	\
        ({"niepozorny", "niepozorni", L_HUMAN | L_HALFLING | L_GNOME}),	\
        ({"niewysoki", "niewysocy", ~L_OGRE}),				\
        ({"niski", "niscy",  ~L_ELF & ~L_OGRE}),			\
        ({"pekaty", "pekaci", ~L_ELF & ~L_GNOME}),			\
        ({"piersiasty", "piersiasci", L_F_HUMAN, L_F_DWARF, L_F_OGRE}),	\
        ({"przygarbiony", "przygarbieni", ~L_ELF}),			\
        ({"pulchny", "pulchni", ~L_ELF & ~L_M_DWARF & ~L_OGRE}),	\
        ({"smukly", "smukli", L_HUMAN | L_ELF}),			\
        ({"szczuply", "szczupli", ~L_OGRE}),				\
        ({"szpotawy", "szpotawi", ~L_ELF & ~L_HALFLING}),		\
        ({"tlusciutki", "tlusciutcy", ~L_OGRE}),			\
        ({"tlusty", "tlusci", L_HUMAN | L_OGRE}),			\
        ({"umiesniony", "umiesnieni", L_M_HUMAN | L_DWARF | L_OGRE}),	\
        ({"watly", "watli", ~L_DWARF}),					\
        ({"wielki", "wielcy", L_HUMAN | L_OGRE}),			\
        ({"wysoki", "wysocy", L_HUMAN | L_ELF | L_OGRE}),		\
        ({"zwalisty", "zwalisci", L_HUMAN | L_OGRE}),			\
})

#define L_A_OCZY ({ 							\
        ({"blekitnooki", "blekitnoocy", ~L_OGRE}),			\
        ({"brazowooki", "brazowoocy", L_ALL}),				\
        ({"ciemnooki", "ciemnoocy", L_ALL}),				\
        ({"czarnooki", "czarnoocy", L_ALL}),				\
        ({"czerwonooki", "czerwonoocy", ~L_ELF & ~L_HALFLING}),		\
        ({"fiolkowooki", "fiolkowoocy", L_F_HUMAN | L_ELF | L_F_HALFLING}),\
        ({"jasnooki", "jasnoocy", ~L_OGRE}),				\
        ({"jednooki", "jednoocy", L_ALL}),				\
        ({"kociooki", "kocioocy", L_F_HUMAN | L_ELF | L_F_HALFLING}),	\
        ({"migdalowooki", "migdalowoocy", L_F_HUMAN | L_F_ELF | L_F_HALFLING}),\
        ({"modrooki", "modroocy", L_HUMAN | L_ELF | L_HALFLING}),	\
        ({"niebieskooki", "niebieskoocy", ~L_OGRE}),			\
        ({"piwnooki", "piwnoocy", L_HUMAN | L_DWARF | L_HALFLING}),	\
        ({"plomiennooki", "plomiennoocy", L_HUMAN | L_ELF}),		\
        ({"promiennooki", "promiennoocy", L_F_HUMAN | L_ELF | L_F_HALFLING}),\
        ({"rybiooki", "rybioocy", ~L_ELF & ~L_HALFLING}),		\
        ({"skosnooki", "skosnoocy", ~L_DWARF & ~L_HALFLING}),		\
        ({"srebrnooki", "srebrnoocy", L_ELF}),				\
        ({"szarooki", "szaroocy", ~L_OGRE}),				\
        ({"wylupiastooki", "wylupiastoocy", ~L_ELF & ~L_HALFLING}),	\
        ({"zezowaty", "zezowaci", ~L_ELF & ~L_HALFLING}),		\
        ({"zielonooki", "zielonoocy", ~L_OGRE}),			\
        ({"zlotooki", "zlotoocy", L_HUMAN | L_ELF | L_HALFLING}),	\
        ({"zoltooki", "zoltoocy", ~L_ELF & ~L_HALFLING}),		\
})

#define L_A_OGOLNE ({							\
        ({"brudny", "brudni", ~L_ELF & ~L_HALFLING}),			\
        ({"dumny", "dumni", ~L_ALL}),					\
        ({"energiczny", "energiczni", L_ALL}),				\
        ({"hardy", "hardzi", ~L_HALFLING}),				\
        ({"malomowny", "malomowni", L_ALL}),				\
        ({"melancholijny", "melancholijni", L_ALL}),			\
        ({"nerwowy", "nerwowi", L_ALL}),				\
        ({"niesmialy", "niesmiali", ~L_DWARF & ~L_OGRE}),		\
        ({"opanowany", "opanowani", L_ALL}),				\
        ({"przyjacielski", "przyjacielscy", L_ALL}),			\
        ({"rozmowny", "rozmowni", L_ALL}),				\
        ({"smierdzacy", "smierdzacy", ~L_ELF & ~L_HALFLING}),		\
        ({"spokojny", "spokojni", L_ALL}),				\
        ({"tepy", "tepi", ~L_ELF}),					\
        ({"wesoly", "weseli", L_ALL}),					\
        ({"wyniosly", "wyniosli", ~L_HALFLING}),			\
})

#define L_A_SKORA ({ 							\
        ({"bladoskory", "bladoskorzy", L_ALL}),				\
        ({"ciemnoskory", "ciemnoskorzy", ~L_HALFLING}),			\
        ({"czarnoskory", "czarnoskorzy", L_HUMAN}),			\
        ({"czerwonoskory", "czerwonoskorzy", L_HUMAN}),			\
        ({"jasnoskory", "jasnoskorzy", ~L_ELF}),			\
        ({"kosmaty", "kosmaci", L_M_HALFLING | L_OGRE}),		\
        ({"laciaty", "laciaci", L_OGRE}),				\
        ({"oliwkowy", "oliwkowi", L_HUMAN | L_GNOME}),			\
        ({"opalony", "opaleni", L_ALL}),				\
        ({"plamiasty", "plamiasci", L_OGRE}),				\
        ({"rozowiutki", "rozowiutcy", L_HUMAN | L_HALFLING}),		\
        ({"smagly", "smagli", L_HUMAN | L_ELF | L_HALFLING}),		\
        ({"sniady", "sniadzi", ~L_ELF}),				\
        ({"szarawy", "szarawi", L_OGRE}),				\
        ({"szczeciniasty", "szczeciniasci", L_OGRE}),			\
        ({"wlochaty", "wlochaci", L_M_HUMAN, L_M_HALFLING, L_OGRE}),	\
        ({"wylenialy", "wyleniali", L_M_GNOME | L_OGRE}),		\
        ({"zielonkawy", "zielonkawi", L_OGRE}),				\
        ({"zolty", "zolci", L_HUMAN}),					\
})

#define L_A_TWARZ ({ 							\
        ({"bezzebny", "bezzebni", ~L_ELF}),				\
        ({"blady", "bladzi", L_ALL}),					\
        ({"czerwononosy", "czerwononosi", ~L_ELF & ~L_F_HALFLING}),	\
        ({"czerwony", "czerwoni", ~L_ELF & ~L_GNOME}),			\
        ({"dlugonosy", "dlugonosi", L_ALL}),				\
        ({"dlugouchy", "dlugousi", L_ALL}),				\
        ({"dziobaty", "dziobaci", L_ALL}),				\
        ({"klapouchy", "klapousi", L_GNOME | L_OGRE}),			\
        ({"kostropaty", "kostropaci", ~L_ELF & ~L_HALFLING}),		\
        ({"krostowaty", "krostowaci", ~L_ELF & ~L_HALFLING}),		\
        ({"krotkonosy", "krotkonosi", L_ALL}),				\
        ({"krotkouchy", "krotkousi", ~L_ELF & ~L_HALFLING}),		\
        ({"krzywonosy", "krzywonosi", L_ALL}),				\
        ({"ogorzaly", "ogorzali", ~L_OGRE}),				\
        ({"ospowaty", "ospowaci", L_ALL}),				\
        ({"ostronosy", "ostronosi", L_ALL}),				\
        ({"ostrouchy", "ostrousi", L_ELF | L_HALFLING | L_GNOME}),	\
        ({"piegowaty", "piegowaci", L_ALL}),				\
        ({"plaskonosy", "plaskonosi", ~L_ELF}),				\
        ({"pomarszczony", "pomarszczeni", ~L_ELF}),			\
        ({"pryszczaty", "pryszczaci", L_ALL}),				\
        ({"puculowaty", "puculowaci", ~L_ELF}),				\
        ({"pyzaty", "pyzaty", ~L_ELF & ~L_DWARF}),			\
        ({"rumiany", "rumiani", ~L_ELF}),				\
        ({"spiczastouchy", "spiczastousi", L_ELF | L_HALFLING | L_GNOME}),\
        ({"szczerbaty", "szczerbaci", L_ALL}),				\
        ({"wasaty", "wasaci", L_BEARDED}),				\
        ({"wielkonosy", "wielkonosi", L_ALL}),				\
        ({"wielkouchy", "wielkousi", L_ALL}),				\
})

#define L_A_WIEK ({ 							\
        ({"bardzo mlody", "bardzo mlodzi", L_ALL}),			\
        ({"bardzo stary", "bardzo starzy", L_ALL}),			\
        ({"dojrzaly", "dojrzali", ~L_OGRE}),				\
        ({"leciwy", "leciwi", ~L_ELF & ~L_OGRE}),			\
        ({"mlody", "mlodzi", L_ALL}),					\
        ({"podstarzaly", "podstarzali", ~L_ELF}),			\
        ({"stary", "starzy", L_ALL}),					\
        ({"wiekowy", "wiekowi", L_ALL}),				\
})

#define L_A_WLOSY ({							\
        ({"bialowlosy", "bialowlosi", ~L_OGRE}),			\
        ({"czarnowlosy", "czarnowlosi", L_ALL}),			\
        ({"ciemnowlosy", "ciemnowlosi", L_ALL}),			\
        ({"czerwonowlosy", "czerwonowlosi", L_ALL}),			\
        ({"dlugowlosy", "dlugowlosi", L_ALL}),				\
        ({"jasnowlosy", "jasnowlosi", ~L_OGRE}),			\
        ({"kasztanowowlosy", "kasztanowowlosi", L_F_HUMAN | L_ELF | L_HALFLING}),\
        ({"kedzierzawy",  "kedzierzawi", L_ALL}),			\
        ({"krotkowlosy", "krotkowlosi", L_ALL}),			\
        ({"kruczowlosy", "kruczowlosi", L_HUMAN, L_ELF}),		\
        ({"kudlaty", "kudlaci", L_ALL}),				\
        ({"lysiejacy", "lysiejacy", ~L_ELF}),				\
        ({"lysy", "lysi", ~L_ELF}),					\
        ({"ognistowlosy", "ognistowlosi", ~L_OGRE}),			\
        ({"pomaranczowowlosy", "pomaranczowowlosi", L_DWARF}),		\
        ({"rudowlosy", "rudowlosi", L_ALL}),				\
        ({"rudy", "rudzi", L_ALL}),					\
        ({"ryzy", "ryzy", ~L_ELF & ~L_HALFLING}),			\
        ({"siwy", "siwi", ~L_ELF}),					\
        ({"srebrnowlosy", "srebrnowlosi", L_ELF}),			\
        ({"szpakowaty", "szpakowaci", ~L_ELF}),				\
        ({"zielonowlosy", "zielonowlosi", L_ELF}),			\
        ({"zlotowlosy", "zlotowlosi", L_HUMAN | L_ELF | L_HALFLING}),	\
})

#define L_ATTRIBUTES ([ 	\
        "broda"	: L_A_BRODA,	\
        "budowa": L_A_BUDOWA,	\
        "ogolne": L_A_OGOLNE,	\
        "oczy"	: L_A_OCZY,	\
        "skora"	: L_A_SKORA,	\
        "twarz"	: L_A_TWARZ,	\
        "wiek"	: L_A_WIEK,	\
        "wlosy"	: L_A_WLOSY,	\
])
