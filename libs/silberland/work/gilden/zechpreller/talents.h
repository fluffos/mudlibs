#ifndef _ZECHPRELLER_TALENTS_H_
#define _ZECHPRELLER_TALENTS_H_

#define ZT_SCHWIPS 0
#define ZT_IRON_STOMACH 1
#define ZT_BARREL_BASH 2
#define ZT_BEER_FIST 3
#define ZT_BOUNCER_DODGE 4
#define ZT_THIRST_FOR_MORE 5
#define ZT_HARD_DRINKER 6
#define ZT_SMELLY_BREATH 7
#define ZT_BARRELWALZ 8
#define ZT_TACKLE 9
#define ZT_STAGGER 10
#define ZT_BARRELSTORM 11
#define ZT_HUMPKING 12
#define ZT_BARRELSAINT 13
#define ZT_PUREBRAND 14
#define ZT_FAST_FERMENTATION 15
#define ZT_BREWER_SWEAT 16
#define ZT_BEER_TAP 17
#define ZT_POISON_CLOUD 18
#define ZT_MINI_GHOST 19
#define ZT_WARMUP 20
#define ZT_HEALING_CLOUD 21
#define ZT_LIVER_DAMAGE 22
#define ZT_METHANOL 23
#define ZT_YEAST_SMELL 24
#define ZT_EMERGENCY_BARREL 25
#define ZT_CELLAR_MASTER 26
#define ZT_ENLIGHTENED 27
#define MAX_TALENT_NR 28

#define ZT_TALENT_NAMES ({ \
    "Schwips", "Eisener Magen", "Fasshieb", "Bierfaust", "Deckung", "Durst nach Mehr", "Harter Trinker", "Mundgeruch", "Fasswalze", "Rempeln", "Schwanken", "Sturmfass", "Humpenkoenig", "Fassheiliger",\
    "Reinbrand", "Schnellgaehrung", "Brauerschweiss", "Zapfhahn", "Giftwolke", "Schnapsgeist", "Vorgluehen", "Heilwolke", "Leberschaden", "Methanol", "Hefedunst", "Reservefass", "Kellermeister", "Vollrausch"\
})

#define ZT_TALENT_DESCR ({\
    "Wenn du hochalkoholisiert bist wird der Schaden des Ruelpsers erhoeht.",\
    "Beim Uebergeben werden bis negative Zustaende gleich mit ausgekotzt.",\
    "Mit dem Fasshieb haust du Einem so in die Fratze, dass er nix mehr tun kann.",\
    "Du nutzt das Aufstossen nach einem gscheiten Hieb gleich zum Ruelpsen.",\
    "Du gehst beim Anhauchen und Rumkugeln in Deckung.",\
    "Wenn du betrunken bist kann der Alkohol ein bisserl Magie ersetzen.",\
    "Dein Koerper wird haerter, wenn du mehr g'soffen hast.",\
    "Ein Ruelpser kann Mundgeruch machen. Anhauchen nach ist dann besser!",\
    "Mit deinem Hammer haust fest ueber die, die grad nur bloed dreinschaun.",\
    "Du rumkugelst deinen Gegner so an, dass er herumstolpert.",\
    "Mit dem richtigen Schwanken wird die Dauer deines Torkelns verlaengert.",\
    "Ab und zu haust du schnell hintereinander auf deinen Gegner ein.",\
    "Zwischen deinen Schlaegen kippst du einen und erhaltst Magie zurueck.",\
    "So lang du im Vollsuff bist triffst du besser und haeltst mehr aus!",\
    "Deine Zauber werden teilkoerperlich und weniger abwehrbar.",\
    "Durch schnelles Gaehren wird dein Destillieren alkoholischer.",\
    "Immer, wenn du Allohol verbrennst wird ein bisserl davon zu Magie.",\
    "Mit dem richt'gen Dreh werden Destillieren und Alokoholwolke billiger.",\
    "Deine Alloholwolge macht Gegner anfaellig gegen Bier und Schnaps.",\
    "Wenn du Allohol verbrauchst, kann ein kleiner Schnapsgeist kommen.",\
    "Nach dem Genuss von Alk ist dein Zauberschaden eine Zeit lang hoeher.",\
    "Die Wolke enthaelt nicht nur Alk, sondern bekommt auch eine Heilwirkung.",\
    "Nach dem Alkoholisieren leidet die Leber deines Gegners noch etwas.",\
    "Der Alkohol beim Alkoholisieren wird zu blendendem Methanol.",\
    "Dein Dunstpanzer wird hefehaltig und seine Daempfe verlangsamen Gegner.",\
    "Wenn dein Allohol ausgeht, dann nimmst du einen Schluck und bekomst was nach.",\
    "Dein Wissen ueber Keller und Lagerung verbessert deinen Weingeist.",\
    "Solang du komplett dicht bist, sind deine Zauber billiger und staerker.",\
})

#define ZT_TREES ([\
    "Fasspruegler": ({ ({ZT_SCHWIPS, ZT_IRON_STOMACH, ZT_BARREL_BASH}),\
                       ({ZT_BEER_FIST, ZT_BOUNCER_DODGE, ZT_THIRST_FOR_MORE}), \
                       ({ZT_HARD_DRINKER, ZT_SMELLY_BREATH, ZT_BARRELWALZ}),\
                       ({ZT_TACKLE, ZT_STAGGER, ZT_BARRELSTORM}),\
                       ({ZT_BARRELSAINT, ZT_HUMPKING}) \
    }),\
    "Braumeister": ({ ({ZT_PUREBRAND, ZT_FAST_FERMENTATION, ZT_BREWER_SWEAT}),\
                       ({ZT_BEER_TAP, ZT_WARMUP, ZT_MINI_GHOST}), \
                       ({ZT_LIVER_DAMAGE, ZT_METHANOL, ZT_YEAST_SMELL}),\
                       ({ZT_POISON_CLOUD, ZT_HEALING_CLOUD, ZT_EMERGENCY_BARREL}),\
                       ({ZT_CELLAR_MASTER, ZT_ENLIGHTENED}) \
    }),\
])

#define ZTMASTER "/gilden/zechpreller/master/talentmaster"

#define P_ZECHPRELLER_FREE_BURP "tmp_zechpreller_free_burp"
#define P_ZECHPRELLER_ENHANCED_BREATH "tmp_zechpreller_enhanced_breath"
#define P_ZECHPRELLER_LAST_BARRELWALZ "tmp_zechpreller_last_walzed"
#define P_ZECHPRELLER_LAST_EMERGENCY_BARREL "tmp_zechpreller_last_emergency_barrel"

#endif