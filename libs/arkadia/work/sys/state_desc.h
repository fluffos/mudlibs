/*
   sys/state_desc.h

   Holds all textual descriptions of state descriptions of livings.
   
   Note that local changes to these arrays are done in
   /config/sys/state_desc2.h
*/

#ifndef SD_DEFINED
#include "/config/sys/state_desc2.h"
#endif

#ifndef SD_DEFINED
#define SD_DEFINED

#ifndef SD_AV_TITLES
#define SD_AV_TITLES 	({ "zoltodziob", "poczatkujacy", "", "", "", "" })
#endif

#define SD_STAT_NAMES 	({ "S", "Zr", "Wt", "Int", "Md", "Odw" })
#define SD_STAT_NAMES_MIA						\
			({ "sila", "zrecznosc", "wytrzymalosc",		\
        		   "inteligencja", "madrosc", "odwaga" })
#define SD_STAT_NAMES_BIE						\
			({ "sile", "zrecznosc", "wytrzymalosc",		\
			   "inteligencje", "madrosc", "odwage" })

#define SD_STATLEV_STR(x) ({ "slabiutk" + (x == "a" ? x : "i"),		\
			     "watl" + x, "slab" + x, "krzepk" +		\
			     (x == "a" ? x : "i"), "siln" + x,		\
			     "mocn" + x, "potezn" + x, "mocarn" + x })

#define SD_STATLEV_DEX(x) ({ "nieskoordynowan" + x, "niezreczn" + x,	\
			     "niezgrabn" + x, "sprawn" + x, "zwinn" + x,\
			     "zreczn" + x, "gibk" + (x == "a" ? x : "i"),\
			     "akrobatyczn" + x })
			   
#define SD_STATLEV_CON(x) ({ "cherlaw" + x, "rachityczn" + x,		\
			     "mizern" + x, "dobrze zbudowan" + x,	\
			     "wytrzymal" + x, "tward" + x,		\
			     "muskularn" + x, "atletyczn" + x })
			     
#define SD_STATLEV_INT(x) ({ "bezmysln" + x, "tep" + x,			\
			     "ograniczon" + x, "pojetn" + x,		\
			     "inteligentn" + x, "bystr" + x,		\
			     "blyskotliw" + x, "genialn" + x })

#define SD_STATLEV_WIS(x) ({ "glupi" + (x == "a" ? x : ""),		\
			     "zacofan" + x, "niewyksztalcon" + x,	\
			     "wyksztalcon" + x, "madr" + x,		\
			     "uczon" + x, "oswiecon" + x,		\
			     "wszechwiedzac" + x })

#define SD_STATLEV_DIS(x) ({ "tchorzliw" + x, "strachliw" + x,		\
			     "niepewn" + x, "zdecydowan" + x,		\
			     "odwazn" + x, "dzieln" + x,		\
			     "nieugiet" + x, "nieustraszon" + x })

/* Observe that the denominators below are reversed for the first two
   of the statlev descs above.
*/
#define SD_STAT_DENOM	({ "", "bardzo " })

#define SD_BRUTE_FACT(x) ({ "pacyfist" + (x == "a" ? "ka" : "a"),	\
			    "bardzo potuln" + x, "potuln" + x,		\
			    "bardzo lagodn" + x, "lagodn" + x,		\
			    "spokojn" + x, "agresywn" + x,		\
			    "bojow" + x, "bardzo bojow" + x, 		\
			    "brutaln" + x, "bardzo brutaln" + x, 	\
			    "zadn" + x + " krwi" })

#define SD_HEALTH(x)	({ "ledwo zyw" + x, "ciezko rann" + x,		\
			   "w zlej kondycji", "rann" + x,		\
			   "lekko rann" + x, "w dobrym stanie",		\
			   "w swietnej kondycji" })
			   
#define SD_MANA(x)	({ "u kresu sil", "wykonczon" + x,		\
			   "wyczerpan" + x, "w zlej kondycji",		\
			   "bardzo zmeczon" + x, "zmeczon" + x,		\
			   "oslabion" + x, "lekko oslabion" + x,	\
			   "w pelni sil" })				\

#define SD_COMPARE_STR(x)  						\
			({ "rownie siln" + x + " jak",			\
			   "troszeczke silniejsz" + x + " niz",		\
			   "silniejsz" + x + " niz",			\
			   "duzo silniejsz" + x + " niz" })
#define SD_COMPARE_DEX(x)						\
			({ ("rownie zreczn" + x + " jak"),		\
			   ("troszeczke zreczniejsz" + x + " niz"),	\
			   ("zreczniejsz" + x + " niz"),			\
			   ("duzo zreczniejsz" + x + " niz") })
#define SD_COMPARE_CON(x)						\
			({ ("rownie dobrze zbudowan" + x + " jak"),	\
			   ("troszeczke lepiej zbudowan" + x + " niz"),	\
			   ("lepiej zbudowan" + x + " niz"),		\
			   ("duzo lepiej zbudowan" + x + " niz") })
#define SD_COMPARE_DIS(x)						\
			({ ("rownie odwazn" + x + " jak"),		\
			   ("troszeczke odwazniejsz" + x + " niz"),	\
			   ("odwazniejsz" + x + " niz"),		\
			   ("duzo odwazniejsz" + x + " niz") })

#define SD_PANIC(x)  	({ "bezpiecznie", "spokojnie", "nieswojo",	\
				"nerwowo", "przerazon" + x })

#define SD_FATIGUE(x)	({ "w pelni wypoczet" + x, "wypoczet" + x,	\
			   "troche zmeczon" + x, "zmeczon" + x,		\
			   "bardzo zmeczon" + x, "nieco wyczerpan" + x,	\
			   "wyczerpan" + x, "bardzo wyczerpan" + x, 	\
			   "wycienczon" + x, "calkowicie wycienczon" + x })

#define SD_SOAK  	({ "chce ci sie bardzo pic", "chce ci sie pic",	\
		    	   "troche chce ci sie pic", 			\
		    	   "nie chce ci sie pic" })

#define SD_STUFF(x)	({ "glodn" + x, "najedzon" + x })
    
#define SD_INTOX(x)	({ "podchmielon" + x, "podpit" + x,		\
			   "wstawion" + x, "pijan" + x, "schlan" + x,	\
			   "nawalon" + x })
    
#define SD_HEADACHE	({ "lekkiego", "niemilego", "drazniacego",	\
			   "niezlego", "straszliwego", "potwornego" })

#define SD_IMPROVE_MIN  ( 50000)
#define SD_IMPROVE_MAX  (750000)
#define SD_IMPROVE	({ "nieznaczne", "male", "nieduze", "znaczne",	\
			   "duze", "bardzo duze", "wspaniale", "ogromne" })

#define SD_GOOD_ALIGN	({ "neutral", "agreeable", "trustworthy",	  \
			   "sympathetic", "nice", "sweet", "good",	  \
			   "devout", "blessed", "saintly", "holy" })

#define SD_EVIL_ALIGN	({ "neutral", "disagreeable", "untrustworthy",    \
			   "unsympathetic", "sinister", "wicked", "nasty",\
			   "foul", "evil", "malevolent", "beastly",	  \
			   "demonic", "damned" })

#define SD_ARMOUR	({ "w znakomitym stanie", "lekko podniszczona",	\
			   "w kiepskim stanie", "w oplakanym stanie",	\
			   "gotowa rozpasc sie w kazdej chwili" })

#define SD_WEAPON_RUST	({ "brak komentarza", "spostrzegasz slady rdzy",\
			   "spostrzegasz liczne slady rdzy", 		\
			   "jest cala pokryta rdza", "wyglada jak " +	\
			   "po kapieli w kwasie", "jest tak " +		\
			   "skorodowowana, ze moze rozpasc sie w " +	\
			   "kazdej chwili" })

#define SD_WEAPON_COND	({ "w znakomitym stanie", "w dobrym stanie",	\
			   "liczne walki wyryly na niej swoje pietno",	\
			   "w zlym stanie", 				\
			   "w bardzo zlym stanie",			\
			   "wymga natychmiastowej konserwacji",		\
			   "moze peknac w kazdej chwili" })

#define SD_ENC_WEIGHT   ({ "ciezar twego ekwipunku wadzi ci troche",	\
			   "ciezar twego ekwipunku daje ci sie we znaki",\
			   "ciezar twego ekwipunku jest dosyc klopotliwy",\
			   "twoj ekwipunek jest wyjatkowo ciezki",	\
			   "twoj ekwipunek jest niemilosiernie ciezki",	\
			   "twoj ekwipunek prawie przygniata cie do ziemi" })

#define SD_SKILLEV	({ "ledwo", "troche", "pobieznie",		\
			   "zadowalajaco", "niezle", "dobrze",		\
			   "znakomicie", "doskonale", "perfekcyjnie",	\
			   "mistrzowsko" })

#define SD_LEVEL_MAP 	([						\
			  "postepow" : SD_IMPROVE,			\
			  "kaca" : SD_HEADACHE,				\
			  "pijanstwa" : SD_INTOX("y"),			\
			  "sytosci" : SD_STUFF("y"),			\
			  "pragnienia" : SD_SOAK,			\
			  "zmeczenia" : SD_FATIGUE("y"),		\
			  "strachu" : SD_PANIC("y"),			\
			  "many" : SD_MANA("y"),			\
			  "kondycji" : SD_HEALTH("y"),			\
			  "brutalnosci" : SD_BRUTE_FACT("y"),		\
			  "porownania sily": SD_COMPARE_STR("y"),	\
			  "porownania zrecznosci": SD_COMPARE_DEX("y"),	\
			  "porownania wytrzymalosci": SD_COMPARE_CON("y"),\
			  "sily" : SD_STATLEV_STR("y"),			\
			  "zrecznosci" : SD_STATLEV_DEX("y"),		\
			  "wytrzymalosci" : SD_STATLEV_CON("y"),	\
			  "inteligencji" : SD_STATLEV_INT("y"),		\
			  "madrosci" : SD_STATLEV_WIS("y"),		\
			  "odwagi" : SD_STATLEV_DIS("y"),		\
			  "graczy" : SD_AV_TITLES,		     	\
			  "jakosci zbroi" : SD_ARMOUR,			\
			  "zardzewienia" : SD_WEAPON_RUST,		\
			  "jakosci broni" : SD_WEAPON_COND,		\
			  "przeciazenia": SD_ENC_WEIGHT,		\
			  "umiejetnosci": SD_SKILLEV,			\
		       ])
#endif
