/*
 * ss_types2.h
 *
 * This file defines the available stats and skills that are locally
 * configured. The only use of this file is that it should be included
 * by /sys/ss_types.h.
 */

#include <tasks.h>

/*Define this if you want skills to be limited by stats*/
#define STAT_LIMITED_SKILLS

/*
 * Limity dla poszczegolnych umiejetnosci sa zdefiniowane w mappingu
 * SS_SKILL_DESC.
 */

/* List of skills as is going to be used */
#define SS_WEP_FIRST               0   /* The first weapon index */

#define SS_WEP_SWORD            SS_WEP_FIRST + 0  /* W_SWORD */
#define SS_WEP_POLEARM          SS_WEP_FIRST + 1  /* W_POLEARM */
#define SS_WEP_AXE              SS_WEP_FIRST + 2  /* W_AXE */
#define SS_WEP_KNIFE            SS_WEP_FIRST + 3  /* W_KNIFE */
#define SS_WEP_CLUB             SS_WEP_FIRST + 4  /* W_CLUB */
#define SS_WEP_WARHAMMER        SS_WEP_FIRST + 5  /* W_WARHAMMER */
#define SS_WEP_MISSILE          SS_WEP_FIRST + 6  /* W_MISSILE */
#define SS_WEP_JAVELIN          SS_WEP_FIRST + 7  /* W_JAVELIN */

/*
 * Mapping jest indeksowany numerami poszczegolnych umiejetnosci. Jego pola
 * to odpowiednio: nazwa umiejetnosci, nazwa w bierniku (do komendy 'trenuj'),
 * dlugi opis w miejscowniku, wspolczynnik kosztu (0-100), limity z cech i
 * umiejetnosci, maksymalny poziom dostepny poza gildiami. Mapping limitow
 * jest indeksowany numerami cech i umiejetnosci, zgodnie z definicjami z
 * <tasks.h> i <ss_types.h>. Jego pola to odpowiednio: poziom limitujacej
 * cechy/umiejetnosci koniecznej do rozpoczecia szkolenia limitowanej
 * umiejetnosci (0) i poziom konieczny do wyszkolenia sie do maksymalnego
 * dostepnego poziomu (czyli 100). Jesli zamiast tablicy poda sie tylko ta
 * druga liczbe, przyjmuje sie, ze pierwsza wynosi 0.
 */

#define SS_SKILL_DESC ([ \
/* Bieglosci w poszczegolnych rodzajach broni */			\
    SS_WEP_SWORD:							\
        ({"miecze", "miecze", "walce mieczem",				\
          100, ([TS_DEX:60, TS_INT:30]), 30}),				\
    SS_WEP_POLEARM:							\
        ({"bronie drzewcowe", "bronie drzewcowe", "walce bronia drzewcowa",\
          80, ([TS_STR:45]), 30}),					\
    SS_WEP_AXE:								\
        ({"topory", "topory", "walce toporem",				\
          70, ([TS_STR:45]), 30}),					\
    SS_WEP_KNIFE:							\
        ({"sztylety", "sztylety", "walce sztyletem",			\
          46, ([TS_DEX:45, TS_INT:30]), 30}),				\
    SS_WEP_CLUB:							\
        ({"maczugi", "maczugi", "walce maczuga",			\
          50, ([TS_STR:60]), 30}),					\
    SS_WEP_WARHAMMER:							\
        ({"mloty", "mloty", "walce mlotem",				\
          80, ([TS_STR:60]), 30}),					\
    SS_WEP_MISSILE:							\
        ({"bronie strzeleckie", "bronie strzeleckie", "walce bronia strzelecka",\
          70, ([TS_DEX:45, TS_INT:30]), 30}),				\
    SS_WEP_JAVELIN:							\
        ({"bronie rzucane", "bronie rzucane", "walce bronia rzucana",	\
          70, ([TS_STR:30, TS_DEX:30, TS_INT:30]), 30}),		\
/* Ogolne umiejetnosci bojowe */					\
    SS_2H_COMBAT:							\
        ({"walka dwiema bronmi", "walke dwiema bronmi", "walce dwiema bronmi jednoczesnie",\
          100, ([TS_DEX:60, TS_INT:30]), 20}),				\
    SS_UNARM_COMBAT:							\
        ({"walka bez broni", "walke bez broni", "walce bez broni",	\
          90, ([TS_STR:45, TS_DEX:45, TS_WIS:30, TS_DIS:30]), 20}),	\
    SS_BLIND_COMBAT:							\
        ({"walka w ciemnosci", "walke w ciemnosci", "walce w ciemnosciach",\
          95, ([TS_INT:30, TS_WIS:30, TS_DIS:30, SS_AWARENESS:50]), 20}),\
    SS_PARRY:								\
        ({"parowanie", "parowanie", "parowaniu ciosow przeciwnika",	\
          80, ([TS_STR:50, TS_DEX:35, TS_INT:30]), 20}),		\
    SS_SHIELD_PARRY:							\
        ({"tarczownictwo", "tarczownictwo", "skutecznym uzywaniu tarczy",\
          80, ([TS_STR:45, TS_DEX:30, TS_INT:30]), 20}),		\
    SS_DEFENCE:								\
        ({"uniki", "uniki", "unikaniu ciosow przeciwnika",		\
          80, ([TS_DEX:60, TS_INT:30]), 20}),				\
    SS_MOUNTED_COMBAT:							\
        ({"walka konna", "walke konna", "walce z konskiego grzbietu",	\
          100, ([TS_STR:45, TS_DEX:60, TS_WIS:30, SS_ANI_HANDL:50, SS_RIDING:50]), 0}),\
/* Umiejetnosci magiczne */						\
    SS_SPELLCRAFT:							\
        ({"rzucanie czarow", "rzucanie czarow", "uzywaniu magii",	\
          70, ([TS_INT:60, TS_WIS:45, SS_HERBALISM:20]), 20}),		\
    SS_HERBALISM:							\
        ({"zielarstwo", "zielarstwo", "znajdowaniu i rozpoznawaniu ziol",\
          70, ([TS_INT:45, TS_WIS:45]), 20}),				\
    SS_ALCHEMY:								\
        ({"alchemia", "alchemie", "warzeniu i rozpoznawaniu mikstur",	\
          70, ([TS_INT:45, TS_WIS:60, SS_HERBALISM:40]), 20}),		\
/* Do zmiany, badz usuniecia...						\
    SS_FORM_TRANSMUTATION:({ "transmutation spells", 90, SS_INT, 110, 0 }),\
    SS_FORM_ILLUSION:    ({ "illusion spells",    70, SS_INT, 110, 0 }), \
    SS_FORM_DIVINATION:  ({ "divination spells",  70, SS_INT, 110, 0 }), \
    SS_FORM_ENCHANTMENT: ({ "enchantment spells", 80, SS_INT, 110, 0 }), \
    SS_FORM_CONJURATION: ({ "conjuration spells", 80, SS_INT, 110, 0 }), \
    SS_FORM_ABJURATION:  ({ "abjuration spells",  70, SS_INT, 110, 0 }), \
    SS_ELEMENT_FIRE:     ({ "fire spells",        70, SS_WIS, 110, 0 }), \
    SS_ELEMENT_AIR:      ({ "air spells",         70, SS_WIS, 110, 0 }), \
    SS_ELEMENT_EARTH:    ({ "earth spells",       70, SS_WIS, 110, 0 }), \
    SS_ELEMENT_WATER:    ({ "water spells",       70, SS_WIS, 110, 0 }), \
    SS_ELEMENT_LIFE:     ({ "life spells",        80, SS_WIS, 110, 0 }), \
    SS_ELEMENT_DEATH:    ({ "death spells",       90, SS_WIS, 110, 0 }), \
 */									\
/* Umiejetnosci zlodziejskie */						\
    SS_OPEN_LOCK:							\
        ({"otwieranie zamkow", "otwieranie zamkow", "otwieraniu zamkow bez wlasciwego klucza",\
          70, ([TS_DEX:45, TS_INT:30]), 20}),				\
    SS_PICK_POCKET:							\
        ({"kieszonkowstwo", "kieszonkowstwo", "opiekowaniu sie rzeczami nalezacymi do kogos innego",\
          70, ([TS_DEX:60, TS_DIS:30]), 20}),				\
    SS_ACROBAT:								\
        ({"akrobatyka", "akrobatyke", "akrobatyce",			\
          70, ([TS_DEX:60]), 20}),					\
    SS_FR_TRAP:								\
        ({"wykrywanie pulapek", "wykrywanie pulapek", "wykrywaniu pulapek",\
          70, ([TS_DEX:45, TS_INT:30, TS_WIS:45]), 30}),		\
    SS_SNEAK:								\
        ({"skradanie sie", "skradanie sie", "przemykaniu sie ukradkiem",\
          70, ([TS_DEX:60]), 30}),					\
    SS_HIDE:								\
        ({"ukrywanie sie", "ukrywanie sie", "ukrywaniu siebie i przedmiotow",\
          70, ([TS_DEX:45]), 30}),					\
/* Umiejetnosci ogolnego przeznaczenia */				\
    SS_APPR_MON:							\
        ({"ocena przeciwnika", "ocene przeciwnika", "ocenianiu cech i stanow osob",\
          50, ([TS_WIS:45]), 30}),					\
    SS_APPR_OBJ:							\
        ({"ocena obiektu", "ocene obiektu", "ocenianiu wlasnosci przedmiotow",\
          50, ([TS_WIS:45]), 30}),					\
    SS_APPR_VAL:							\
        ({"szacowanie", "szacowanie", "szacowaniu wartosci przedmiotow",\
          50, ([TS_WIS:45]), 30}),					\
    SS_SWIM:								\
        ({"plywanie", "plywanie", "plywaniu i nurkowaniu",		\
          50, ([TS_STR:30, TS_DEX:30, TS_CON:45]), 50}),		\
    SS_CLIMB:								\
        ({"wspinaczka", "wspinaczke", "wspinaniu sie",			\
          50, ([TS_STR:45, TS_DEX:45, TS_CON:30, TS_DIS:30]), 50}),	\
    SS_ANI_HANDL:							\
        ({"opieka nad zwierzetami", "opieke nad zwierzetami", "opiekowaniu sie zwierzetami i wzbudzaniu ich zaufania",\
          50, ([TS_WIS:45]), 30}),					\
    SS_LOC_SENSE:							\
        ({"wyczucie kierunku", "wyczucie kierunku", "rozpoznawaniu kierunkow i znajdowaniu sciezek",\
          50, ([TS_INT:30, TS_WIS:60]), 30}),				\
    SS_TRACKING:							\
        ({"tropienie", "tropienie", "znajdowaniu i rozpoznawaniu sladow",\
          50, ([TS_INT:30, TS_WIS:60]), 30}),				\
    SS_HUNTING:								\
        ({"lowiectwo", "lowiectwo", "lowieniu dzikich zwierzat",	\
          50, ([TS_INT:30, TS_WIS:30, SS_TRACKING:50, SS_AWARENESS:50]), 30}),\
    SS_LANGUAGE:							\
        ({"znajomosc jezykow", "znajomosc jezykow", "identyfikacji starozytnych i wspolczesnych jezykow i pism",\
          50, ([TS_INT:60, TS_WIS:60]), 40}),				\
    SS_AWARENESS:							\
        ({"spostrzegawczosc", "spostrzegawczosc", "zauwazaniu tego, co ukryte",\
          50, ([TS_INT:30, TS_WIS:45]), 50}),				\
    SS_TRADING:								\
        ({"targowanie sie", "targowanie sie", "zawieraniu korzystnych transakcji handlowych",\
          50, ([TS_INT:45]), 30}),					\
    SS_RIDING:								\
        ({"jezdziectwo", "jezdziectwo", "jezdzie konnej",		\
          75, ([TS_DEX:60, TS_WIS:45]), 0}),				\
])