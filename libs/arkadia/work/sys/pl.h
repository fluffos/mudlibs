#ifndef PL_DEFS
#define PL_DEFS

/* Przypadki */
#define PL_MIA  0
#define PL_DOP  1
#define PL_CEL  2
#define PL_BIE  3
#define PL_NAR  4
#define PL_MIE  5

/* Rodzaje gramatyczne */

#define PL_MESKI_OS             0
#define PL_MESKI_NOS_ZYW        1
#define PL_MESKI_NOS_NZYW       2
#define PL_MESKI_NZYW           2

#define PL_ZENSKI               3

#define PL_NIJAKI_OS            4
#define PL_NIJAKI_NOS           5

#define QRODZAJ(ob)     (ob->query_rodzaj())

/* Makra ulatwiajace ustawienie odmian */

/* Dla graczy (choc nie tylko) */
#define PL_CZLOWIEK     ({"czlowiek", "czlowieka", "czlowiekowi",           \
                          "czlowieka", "czlowiekiem", "czlowieku"}),        \
                        ({"ludzie", "ludzi", "ludziom", "ludzi", "ludzmi",  \
                          "ludziach"}), PL_MESKI_OS, 1
#define PL_MEZCZYZNA    ({"mezczyzna", "mezczyzny", "mezczyznie",           \
                          "mezczyzne", "mezczyzna", "mezczyznie"}),         \
                        ({"mezczyzni", "mezczyzn", "mezczyznom",            \
                          "mezczyzn", "mezczyznami", "mezczyznach"}),       \
                        PL_MESKI_OS
#define PL_KOBIETA      ({"kobieta", "kobiety", "kobiecie", "kobiete",      \
                          "kobieta", "kobiecie"}),                          \
                        ({"kobiety", "kobiet", "kobietom", "kobiety",       \
                          "kobietami", "kobietach"}), PL_ZENSKI
#define PL_ELF          ({"elf", "elfa", "elfowi", "elfa", "elfem",         \
                          "elfie"}),                                        \
                        ({"elfy", "elfow", "elfom", "elfy", "elfami",       \
                          "elfach"}), PL_MESKI_NOS_ZYW
#define PL_ELFKA        ({"elfka", "elfki", "elfce", "elfke", "elfka",      \
                          "elfce"}),                                        \
                        ({"elfki", "elfek", "elfkom", "elfki", "elfkami",   \
                          "elfkach"}), PL_ZENSKI
#define PL_KRASNOLUD    ({"krasnolud", "krasnoluda", "krasnoludowi",        \
                          "krasnoluda", "krasnoludem", "krasnoludzie"}),    \
                        ({"krasnoludy", "krasnoludow", "krasnoludom",       \
                          "krasnoludy", "krasnoludami", "krasnoludach"}),   \
                        PL_MESKI_NOS_ZYW
#define PL_KRASNOLUDKA  ({"krasnoludka", "krasnoludki", "krasnoludce",      \
                          "krasnoludke", "krasnoludka", "krasnoludce"}),    \
                        ({"krasnoludki", "krasnoludek", "krasnoludkom",     \
                          "krasnoludki", "krasnoludkami",                   \
                          "krasnoludkach"}), PL_ZENSKI
#define PL_HOBBIT       ({"hobbit", "hobbita", "hobbitowi", "hobbita",      \
                          "hobbitem", "hobbicie"}),                         \
                        ({"hobbici", "hobbitow", "hobbitom", "hobbitow",    \
                          "hobbitami", "hobbitach"}), PL_MESKI_OS
#define PL_HOBBITKA     ({"hobbitka", "hobbitki", "hobbitce", "hobbitke",   \
                          "hobbitka", "hobbitce"}),                         \
                        ({"hobbitki", "hobbitek", "hobbitkom", "hobbitki",  \
                          "hobbitkami", "hobbitkach"}), PL_ZENSKI
#define PL_GNOM         ({"gnom", "gnoma", "gnomowi", "gnoma", "gnomem",    \
                          "gnomie"}),                                       \
                        ({"gnomy", "gnomow", "gnomom", "gnomy", "gnomami",  \
                          "gnomach"}), PL_MESKI_NOS_ZYW
#define PL_GNOMKA       ({"gnomka", "gnomki", "gnomce", "gnomke", "gnomka", \
                          "gnomce"}),                                       \
                        ({"gnomki", "gnomek", "gnomkom", "gnomki",          \
                          "gnomkami", "gnomkach"}), PL_ZENSKI
#define PL_GOBLIN       ({"goblin", "goblina", "goblinowi", "goblina",      \
                          "goblinem", "goblinie"}),                         \
                        ({"gobliny", "goblinow", "goblinom", "gobliny",     \
                          "goblinami", "goblinach"}), PL_MESKI_NOS_ZYW
#define PL_GOBLINKA     ({"goblinka", "goblinki", "goblince", "goblinke",   \
                          "goblinka", "goblince"}),                         \
                        ({"goblinki", "goblinek", "goblinkom", "goblinki",  \
                          "goblinkami", "goblinkach"}), PL_ZENSKI

/* Inne */
#define PL_HALFLING     ({"halfling", "halflinga", "halflingowi",           \
                          "halflinga", "halflingiem", "halflingu"}),        \
                        ({"halflingi", "halflingow", "halflingom",          \
                          "halflingi", "halflingami", "halflingach"}),      \
                        PL_MESKI_NOS_ZYW
#define PL_HALFLINKA    ({"halflinka", "halflinki", "halflince",            \
                          "halflinke", "halflinka", "halflince"}),          \
                        ({"halflinki", "halflinek", "halflinkom",           \
                          "halflinki", "halflinkami", "halflinkach"}),      \
                        PL_ZENSKI
#define PL_OGR          ({"ogr", "ogra", "ogrowi", "ogra", "ogrem",         \
                          "ogrze"}),                                        \
                        ({"ogry", "ogrow", "ogrom", "ogry", "ogrami",       \
                          "ograch"}), PL_MESKI_NOS_ZYW
#define PL_OGRZYCA      ({"ogrzyca", "ogrzycy", "ogrzycy", "ogrzyce",       \
                          "ogrzyca", "ogrzycy"}),                           \
                        ({"ogrzyce", "ogrzyc", "ogrzycom", "ogrzyce",       \
                          "ogrzycami", "ogrzycach"}), PL_ZENSKI
#define PL_ORK          ({"ork", "orka", "orkowi", "orka", "orkiem",        \
                          "orku"}),                                         \
                        ({"orki", "orkow", "orkom", "orki", "orkami",       \
                          "orkach"}), PL_MESKI_NOS_ZYW
#define PL_ORCZYCA      ({"orczyca", "orczycy", "orczycy", "orczyce",       \
                          "orczyca", "orczycy"}),                           \
                        ({"orczyce", "orczyc", "orczycom", "orczyce",       \
                          "orczycami", "orczycach"}), PL_ZENSKI

#endif PL_DEFS