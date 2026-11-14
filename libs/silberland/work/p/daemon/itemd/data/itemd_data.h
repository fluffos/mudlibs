
// Automatisch generiertes Header file
// itemd_data.h
// Generiert am 15. Jun 1999, 13:44:29 von Angrox
// (c) angrox@sl.mud.at, feyaria@sl.mud.at
//     nur zu Verwendung im Silberland bestimmt.

// Die Weitergabe dieser Informationen an Spieler und an
// Magier anderer MUDs ist lt. Magiervertrag VERBOTEN!!

#define LOW_PREFIX_WEAPON ({\
({  "wertvoll",  ([    "value_factor": 150,  ])}),\
({  "schaebig",  ([    "value_factor": 50,  ])}),\
({  "prunkvoll",  ([    "value_factor": 200,  ])}),\
({  "schwer",  ([    "weight_factor": 200,  ])}),\
({  "leicht",  ([    "weight_factor": 50,  ])}),\
({  "federleicht",  ([    "weight_factor": 1,  ])}),\
({  "widerstandsfaehig",  ([    "quality_decay_factor": 120,  ])}),\
({  "stabil",  ([    "quality_decay_factor": 150,  ])}),\
({  "geschaerft",  ([    "wc_factor": 105,  ])}),\
({  "verrueckt",  ([    "weight_factor": 150,    "wc_factor": 105,  ])}),\
({  "rubin glaenzend",  ([    "wc_factor": 105,  ])}),\
({  "bronze schimmernd",  ([    "wc_factor": 105,  ])}),\
({  "kupfern schimmernd",  ([    "wc_factor": 105,  "magic_health_modifier":(["hp":1]), ])}),\
({  "verziert",  ([    "value_factor": 125,  ])}),\
({  "plump",  ([    "weight_factor": 200,  ])}),\
({  "bleiern",  ([    "material": "Pb", "weight_factor": 300,  ])}),\
({  "weich",  ([    "quality_decay_factor": 40,  ])}),\
({  "gezackt",  ([    "wc_factor": 105,  ])}),\
({  "geschliffen",  ([    "wc_factor": 105,  ])}),\
({  "gekruemmt",  ([    "wc_fix_offset":  5,  ])}),\
({  "klein",  ([    "weight_factor": 70,    "wc_factor": 80,  ])}),\
({  "gross",  ([    "weight_factor": 130,    "wc_factor": 105,  ])}),\
({  "teur",  ([    "value_factor": 200,  ])}),\
({  "billig",  ([    "value_factor": 1,  ])}),\
({  "schmutzig",  ([    "value_factor": 1,  ])}),\
({  "breit",  ([    "wc_fix_offset": -10,    "wc_factor": 110,  ])}),\
({  "schmal",  ([    "wc_fix_offset": 10,    "wc_factor": 85,  ])}),\
({  "lang",  ([    "weight_factor": 120,    "wc_factor": 105,  ])}),\
({  "kurz",  ([    "weight_factor": 80,    "wc_factor": 90,  ])}),\
({  "veraltet",  ([    "value_factor": 80,    "wc_factor": 90,  ])}),\
({  "altertuemlich",  ([    "quality_decay_factor": 120,    "value_factor": 120,    "wc_factor": 95,  ])}),\
({  "uralt",  ([    "quality_decay_factor": 150,    "value_factor": 150,    "wc_factor": 105,  ])}),\
({  "ungewoehnlich",  ([    "value_factor": 120,    "wc_factor": 105,  ])}),\
({  "besonder",  ([    "value_factor": 150,    "wc_factor": 105,  ])}),\
({  "fremdartig",  ([    "quality_decay_factor": 200,    "wc_fix_offset": -20,    "value_factor": 150,  ])}),\
({  "haltbar",  ([    "quality_decay_factor": 130,  ])}),\
({  "bestaendig",  ([    "quality_decay_factor": 120,  ])}),\
({  "versilbert",  ([   "material": "Ag", "quality_decay_factor": 120,    "value_factor": 120,  ])}),\
({  "vergoldet",  ([    "material": "Au", "weight_factor": 150,    "quality_decay_factor": 120,    "value_factor": 150,  ])}),\
({  "verrottet",  ([    "quality_decay_factor": 30,    "value_factor": 10,  ])}),\
({  "verrostet",  ([    "quality_decay_factor": 50,    "value_factor": 30,  ])}),\
({  "bunt",  ([    "value_factor": 110,  ])}),\
({  "bemalt",  ([    "value_factor": 120,  ])}),\
({  "blumengeschmueckt",  ([    "value_factor": 130,  ])}),\
({  "federnverziert",  ([    "value_factor": 140,  ])}),\
({  "unglueckbringend",  ([    "cursed": 1,  ])}),\
({  "unheimlich",  ([    "cursed": 1,  ])}),\
({  "verflucht",  ([    "cursed": 1,  ])}),\
({  "minderwertig",  ([    "quality_decay_factor": 50,    "value_factor": 50,  ])}),\
({  "stinkend",  ([    "value_factor": 5,  ])}),\
({  "wohlduftend",  ([    "value_factor": 125,  ])}),\
({  "schoen",  ([    "value_factor": 120,  ])}),\
({  "haesslich",  ([    "value_factor": 80,  ])}),\
({  "perlenverziert",  ([    "value_factor": 135,  ])}),\
({  "sinnlos",  ([    "cursed": 1,    "wc_factor": 0,  ])}),\
({  "genoppt",  ([ "weight_factor": 110,    "wc_factor": 105,  ])}),\
})
#define LOW_PREFIX_WEAPON1 ({\
({  "kindlich",  ([    "wc_factor": 70, "weight_factor":50 ])}),\
({  "instabil",  ([    "wc_fix_offset": -70, ])}),\
({  "verchromt",  ([    "quality_decay_factor": 110,    "value_factor": 110,  ])}),\
({  "lustig",  ([    "quality_decay_factor": 90,    "value_factor": 110,  ])}),\
({  "schuechtern",  ([    "wc_factor": 50, ])}),\
({  "suendig",  ([    "value_factor": 110 ])}),\
({  "laecherlich",  ([    "value_factor": 10 , "wc_factor": 10])}),\
({  "alt",  ([    "quality_decay_factor": 90,    "value_factor": 90,    "wc_factor": 90,  ])}),\
({  "neu",  ([    "quality_decay_factor": 110,    "value_factor": 110,    "wc_factor": 105,  ])}),\
({  "einfach",  ([    "wc_factor": 80, ])}),\
({  "graviert",  ([    "value_factor": 110,  ])}),\
({  "unnuetz",  ([    "value_factor": 50,  ])}),\
({  "erdbeerig",  ([    "value_factor": 50,  ])}),\
({  "sauber",  ([    "value_factor": 120,  ])}),\
({  "grindig",  ([    "value_factor": 50, "wc_factor": 50, "quality_decay_factor":50,  ])}),\
})

#define MED_PREFIX_WEAPON ({\
({  "ausbalanciert",  ([    "wc_fix_offset": 10,  ])}),\
({  "juwelenverziert",  ([    "value_factor": 300,  ])}),\
({  "gefaehrlich",  ([    "wc_fix_offset": 10,  ])}),\
({  "bruchfest",  ([    "quality_decay_factor": 200,  ])}),\
({  "massiv",  ([    "quality_decay_factor": 250,  ])}),\
({  "scharf",  ([    "wc_factor": 110,  ])}),\
({  "smaragd glaenzend",  ([    "wc_factor": 110,  ])}),\
({  "staehlern schimmernd",  ([    "wc_factor": 110,  ])}),\
({  "",  ([    "name": "Dantes",    "cursed": 1,    "wc_factor": 20,  ])}),\
({  "hart",  ([    "quality_decay_factor": 200,  ])}),\
({  "butterweich",  ([    "quality_decay_factor": 10,  ])}),\
({  "dornenbespickt",  ([    "damage_type_add": "pierce",    "wc_factor": 110,  ])}),\
({  "stachelbewehrt",  ([    "damage_type_add": "pierce",    "wc_factor": 110,  ])}),\
({  "stumpf",  ([    "wc_fix_offset": -20,    "wc_factor": 80,  ])}),\
({  "geschwungen",  ([    "wc_fix_offset": 5,    "wc_factor": 110,  ])}),\
({  "geflammt",  ([    "wc_fix_offset": 10,  ])}),\
({  "onyxfarben",  ([    "quality_decay_factor": 150,    "value_factor": 150,  ])}),\
({  "bernsteinfarben",  ([   "quality_decay_factor": 30, "magic_health_modifier":(["hp":3,"sp":1]), ])}),\
({  "lapislazulifarben",  ([   "wc_fix_offset": -20, "magic_health_modifier":(["hp":2,"sp":2]), ])}),\
({  "zirkonfarben",  ([    "quality_decay_factor": 200,    "wc_factor": 110,  ])}),\
({  "unberechenbar",  ([    "wc_fix_offset": -100,    "wc_factor": 125,  ])}),\
({  "antik",  ([    "quality_decay_factor": 200,    "value_factor": 200,    "wc_factor": 110,  ])}),\
({  "aussergewoehnlich",  ([    "quality_decay_factor": 200,    "wc_fix_offset": 5,    "value_factor": 250,    "wc_factor": 105,  ])}),\
({  "wunderbar",  ([    "value_factor": 200,    "wc_factor": 110,  ])}),\
({  "zauberhaft",  ([    "value_factor": 300,    "wc_factor": 110, "magic_health_modifier":(["hp":-4,"sp":6]), ])}),\
({  "unheilbringend",  ([    "cursed": 1,  "magic_health_modifier":(["hp":-5,"sp":-5]), ])}),\
({  "edl",  ([    "value_factor": 250,  ])}),\
({  "hoelzern",  ([    "material": "misc_wood",    "weight_factor": 50,    "quality_decay_factor": 50,  ])}),\
({  "reissend",  ([    "damage_type_add": "rip",    "wc_factor": 105,  ])}),\
({  "stechend",  ([    "damage_type_add": "pierce",    "wc_factor": 105,  ])}),\
({  "quetschend",  ([    "damage_type_add": "squeeze",    "wc_factor": 105, "berserker_bonus": (["zertreten":20, ]), ])}),\
({  "stattlich",  ([    "wc_factor": 110,  ])}),\
({  "abgegriffen",  ([    "wc_fix_offset": -10,    "wc_factor": 90,  ])}),\
({  "uebelriechend",  ([    "value_factor": 20,  ])}),\
({  "bescheiden",  ([    "value_factor": 80,    "wc_factor": 80,  ])}),\
({  "begehrt",  ([    "value_factor": 150,    "wc_factor": 110,  ])}),\
})
#define MED_PREFIX_WEAPON1 ({\
({  "zweihaendig",  ([    "nr_hands_offset": 1,    "wc_factor": 110,  ])}),\
({  "einhaendig",  ([    "nr_hands_offset": -1,  ])}),\
({  "dick",  ([    "weight_factor": 120,    "wc_factor": 110, "wc_fix_offset":-5 ])}),\
({  "machtlos",  ([    "wc_factor": 80, "wc_fix_offset":-20 ])}),\
({  "schimmernd",  ([    "value_factor": 120,  ])}),\
({  "glaenzend",  ([    "value_factor": 130,  ])}),\
({  "glitzernd",  ([   "wc_factor": 105, "value_factor": 110,  ])}),\
({  "abenteuerlich",  ([   "wc_factor": 110, "quality_decay_factor": 10,  ])}),\
({  "geschliffen",  ([   "wc_factor": 110,   ])}),\
({  "gesund",  ([     "magic_health_modifier":(["hp":3,"sp":0]), ])}),\
({  "intelligent",  ([     "magic_health_modifier":(["hp":0,"sp":3]), ])}),\
({  "grauenhaft",  ([    "wc_factor": 95,  ])}),\
({  "gluecklich",  ([    "itemd_prob_change":5])}),\
({  "zufaellig",  ([    "itemd_prob_change":3])}),\
({  "listig",  ([    "itemd_prob_change":1,  "value_factor": 120])}),\
({  "komisch",  ([    "quality_decay_factor": 1,   "wc_factor": 170,  ])}),\
({  "lustigbunt",  ([    "value_factor": 130, "itemd_prob_change":2 ])}),\
({  "klug",  ([     "magic_health_modifier":(["hp":0,"sp":3]), ])}),\
({  "dumm",  ([     "magic_health_modifier":(["hp":0,"sp":-3]), ])}),\
({  "bruechig",  ([    "quality_decay_factor": 20,  ])}),\
({  "seltsam",  ([   "wc_factor": 150, "wc_fix_offset":-10, "quality_decay_factor": 20,  ])}),\
({  "schwebend",  ([   "itemd_prob_change":2, "quality_decay_factor": 110,    ])}),\
({  "betend",  ([    "paladin_spellcost": 3, ])}),\
({  "betoerend", ([    "amazonen_spellcost": 3, ])}),\
({  "elegant",  ([    "value_factor": 130, "weight_factor": 90, "wc_factor": 105, ])}),\
({  "",  ([    "name": "Rambos", "itemd_prob_change": 3 ])}),\
})

#define HIGH_PREFIX_WEAPON ({\
({  "toedlich",  ([    "wc_fix_offset": 15,  ])}),\
({  "stahlhart",  ([    "quality_decay_factor": 300,  ])}),\
({  "flammend",  ([    "damage_type_add": "fire", "barden_bonus": (["flamme bin ich": 20, "all": 5]), "paladin_bonus": (["eifer: 10"]) ])}),\
({  "heilig",  ([    "damage_type_add": "holy",  "paladin_spellcost": 5, "paladin_bonus": (["all": 5])])}),\
({  "daemonisch",  ([    "damage_type_add": "unholy",  "nekro_spellcost": 5, ])}),\
({  "amazonisch",  ([  "amazonen_spellcost": 5, "amazonen_bonus": (["all": 5])])}),\
({  "magisch",  ([    "damage_type_add": "magic",  ])}),\
({  "vergiftet",  ([    "damage_type_add": "poison", ])}),\
({  "erschuetternd",  ([    "damage_type_add": "explosion",  ])}),\
({  "giftig",  ([    "damage_type_add": "poison",  ])}),\
({  "singend",  ([    "damage_type_add": "sound",  "barden_spellcost": 5, "barden_bonus": (["all":5])])}),\
({  "schreiend",  ([    "damage_type_add": "sound",  "berserker_bonus": (["kampfschrei":20, "all":5]), "barden_bonus": (["schrei des verderbens": 20, "all": 5]) ])}),\
({  "eisig",  ([    "damage_type_add": "cold",  ])}),\
({  "beissend",  ([    "damage_type_add": "acid",  ])}),\
({  "aetzend",  ([    "damage_type_add": "acid",    "value_factor": 80,  ])}),\
({  "furchteinfloessend",  ([    "damage_type_add": "terror", "barden_bonus": (["des todes drei trommelschlaege": 20, "all": 5]), "nekro_bonus": (["schrecken der finsternis": 20, "all": 5]) ])}),\
({  "funkenspruehend",  ([    "damage_type_add": "electric",  ])}),\
({  "spitz",  ([    "wc_factor": 120,  ])}),\
({  "gesegnet",  ([    "damage_type_add": "holy", "paladin_spellcost": 3, ])}),\
({  "verzaubert",  ([    "damage_type_add": "magic",  ])}),\
({  "unbarmherzig",  ([    "wc_factor": 125,  ])}),\
({  "silbrig schimmernd",  ([    "wc_factor": 120,  ])}),\
({  "handlich",  ([    "wc_fix_offset": 10,  "nr_hands_offset": -1])}),\
({  "unhandlich",  ([    "wc_fix_offset": -10, "nr_hands_offset": 1 ])}),\
({  "maechtig",  ([    "wc_factor": 125,  ])}),\
({  "zerfetzend",  ([    "hit_func": 1,    "wc_factor": 110,  ])}),\
({  "knoechern",  ([    "material": "bone",    "weight_factor": 50,    "quality_decay_factor": 50,  ])}),\
({  "steinern",  ([    "material": "stone",    "weight_factor": 150,    "quality_decay_factor": 120,  ])}),\
({  "beruehmt",  ([    "quality_decay_factor": 200,    "wc_fix_offset": 10,    "value_factor": 300,    "wc_factor": 110,  ])}),\
({  "glueckbringend",  ([    "hit_func": 1,  "itemd_prob_change":3])}),\
({  "gefuerchtet",  ([    "hit_func": 1,    "wc_fix_offset": 10,    "wc_factor": 105,  ])}),\
({  "wunderschoen",  ([    "value_factor": 350,  ])}),\
({  "machtvoll",  ([    "wc_fix_offset": 10,    "wc_factor": 110,  ])}),\
({  "bemerkenswert",  ([    "value_factor": 150,    "wc_factor": 115,  ])}),\
({  "makellos",  ([    "wc_fix_offset": 5,    "value_factor": 130,    "wc_factor": 105,  ])}),\
({  "",  ([    "name":         "Cirions",    "quality_decay_factor": 150,    "wc_fix_offset": 10,    "wc_factor": 105,  "teleport_cost":1 ])}),\
({  "",  ([    "name": "Lamuertes",    "quality_decay_factor": 200,    "wc_fix_offset": 5, "teleport_cost":1   ])}),\
({  "",  ([    "name": "Eros'",    "value_factor": 150, "wc_factor": 120, "teleport_cost":1 ])}),\
})
#define HIGH_PREFIX_WEAPON1 ({\
({  "kriegerisch", ([ "wc_offset": 110, "wc_fix_offset": 10,])    }),\
({  "ultraleicht", ([ "weight_factor":10,])    }),\
({  "ultraschwer", ([ "weight_factor":300,])    }),\
({  "blitzend",  ([    "damage_type_add": "lightning", "amazonen_bonus": (["blitzschlag": 20, "all": 5]), "barden_bonus": (["das lied vom sturmvogel": 20, "all": 5])])}),\
({  "fuerstlich", ([ "wc_factor":110, "wc_fix_offset": 10, "quality_decay_factor": 130,  "value_factor": 150, ])}),\
({  "kalt",  ([    "damage_type_add": "cold", ])}),\
({  "heiss",  ([    "damage_type_add": "fire", ])}),\
({  "blutspendend",  ([     "magic_health_modifier":(["hp":4,"sp":0]), ])}),\
({  "magiebringend",  ([     "magic_health_modifier":(["hp":0,"sp":4]), "teleport_cost":1])}),\
({  "hinterlistig",  ([    "itemd_prob_change":3,  "value_factor": 120, "wc_fix_offset":5])}),\
({  "toll",  ([    "wc_factor": 110,  "quality_decay_factor": 120, "wc_fix_offset":5, "magic_health_modifier":(["hp":1,"sp":1]),])}),\
({  "gut",  ([    "wc_factor": 115,  "quality_decay_factor": 140, "wc_fix_offset":10, ])}),\
({  "boes",  ([    "nekro_bonus": (["all":10]), ])}),\
({  "boes",  ([    "nekro_bonus": (["all":10]), ])}),\
({  "ultraweich",  ([    "quality_decay_factor": 10, "wc_factor": 80])}),\
({  "superhart",  ([    "quality_decay_factor": 500, "wc_factor": 110])}),\
({  "beinhart",  ([    "material": "bone",    "quality_decay_factor": 150,  ])}),\
({  "silbern",  ([    "material": "Ag",    "weight_factor": 130,    "quality_decay_factor": 150, "wc_factor": 105, "magic_health_modifier":(["hp":1, "sp":1]), ])}),\
({  "braun",  ([  "damage_type_add": "lightning" ,   "magic_health_modifier":(["hp":1, "sp":1])])}),\
({  "grau",  ([   "damage_type_add": "sound",   "quality_decay_factor": 150  ])}),\
({  "schwarz",  ([   "damage_type_add": "terror" , "nekro_spellcost": 5, ])}),\
({  "gruen",  ([  "damage_type_add": "poison"   ,"wc_fix_offset":5  ])}),\
({  "rot",  ([   "damage_type_add": "fire" ,   "berserker_bonus": (["all":5]) ])}),\
({  "blau",  ([  "damage_type_add": "water", "wc_fix_offset":5, "magic_health_modifier":(["hp":2, ]), ])}),\
({  "gelb",  ([   "damage_type_add": "air" , "wc_factor":105 ])}),\
({  "violett",  ([  "damage_type_add": "magic", "magic_health_modifier":([ "sp":3])  ])}),\
({  "weiss",  ([     "damage_type_add": "cold", "paladin_spellcost":5 ])}),\
({  "schnell",  ([  "wc_factor": 80, "wc_fix_offset":35,  "teleport_cost":1, ])}),\
({  "wuetend",  ([   "wc_factor":110,   "berserker_bonus": (["all":5]) ])}),\
})

#define VHIGH_PREFIX_WEAPON ({\
({  "moerderisch",  ([    "wc_fix_offset": 30,  ])}),\
({  "unzerstoerbar",  ([    "quality_decay_factor": 0,  ])}),\
({  "diamantern glaenzend",  ([    "wc_factor": 120,   "wc_fix_offset": 10,  ])}),\
({  "golden schimmernd",  ([    "wc_factor": 125,   "quality_decay_factor": 130,  ])}),\
({  "",  ([    "name": "Angrox'",    "hit_func": 1,    "quality_decay_factor": 150,    "wc_fix_offset": 10,    "wc_factor": 125, "teleport_cost":2  ])}),\
({  "",  ([    "name": "Feyarias",    "hit_func": 1,    "wc_fix_offset": 25,    "wc_factor": 130, "berserker_bonus": (["all":10]), "teleport_cost":2 ])}),\
({  "",  ([    "name": "Zordans",    "wc_factor": 110,  "hit_func": 1, "paladin_spellcost":5,  "teleport_cost":2])}),\
({  "",  ([    "name": "Creatives",    "wc_fix_offset": 10, "hit_func": 1, "weight_factor": 50, "teleport_cost":2 ])}),\
({  "gewaltig",  ([    "wc_fix_offset": 10,    "wc_factor": 125,  ])}),\
({  "beruechtigt",  ([    "quality_decay_factor": 300,    "wc_fix_offset": 15,    "value_factor": 500,    "wc_factor": 120,  ])}),\
({  "bedrohlich",  ([    "wc_factor": 110,    "damage_type_add": "terror",  ])}),\
({  "bestialisch",  ([    "hit_func": 1,    "wc_fix_offset": -20,    "wc_factor": 140,  ])}),\
({  "majestaetisch",  ([    "hit_func": 1,    "wc_fix_offset": 10,    "value_factor": 400,    "wc_factor": 120,  ])}),\
({  "",  ([    "name": "Elsurions",    "wc_fix_offset": 10,    "damage_type_add": "magic", ])}),\
({  "",  ([    "name": "Soordhins",    "wc_fix_offset": 20,    "wc_factor": 130, "berserker_bonus": (["all":20]), ])}),\
({  "",  ([    "name": "Grimows",    "wc_fix_offset": -30,    "wc_factor": 150, "berserker_bonus": (["all":10]) ])}),\
({  "",  ([    "name": "Tenobaals",    "wc_fix_offset": 40,    "wc_factor": 90, ])}),\
({  "",  ([    "name": "Mythars",    "wc_factor": 110,    "damage_type_add": "holy","paladin_spellcost": 5  ])}),\
({  "",  ([    "name": "Ardares",    "quality_decay_factor": 200,    "wc_factor": 120, "magic_health_modifier":(["hp":7,"sp":7]),"paladin_spellcost": 5, ])}),\
({  "sonnig",  ([      "damage_type_add": "light", "light":1, "wc_factor":110 ])}),\
({  "nebelig", ([     "damage_type_add": "air", "damage_type_add": "water", "wc_factor":110 ])}),\
({  "koeniglich", ([ "hit_func":1, "wc_factor":110, "wc_fix_offset": 10, "quality_decay_factor": 200,  "value_factor": 300, ])}),\
({  "eiskalt",  ([    "damage_type_add": "cold", "quality_decay_factor": 130 ])}),\
({  "frostig",  ([    "damage_type_add": "cold", "wc_factor": 110 ])}),\
({  "gluehend",  ([    "damage_type_add": "fire", "wc_fix_offset": 10 ])}),\
({  "zornig",  ([       "wc_fix_offset": -50,    "wc_factor": 170,  ])}),\
({  "fuerchterlich",  ([    "damage_type_add": "terror",    "wc_factor": 110,  ])}),\
({  "geheimnisvoll",  ([  "itemd_prob_change":20,   "damage_type_add": "magic", ])}),\
({  "sehrgut",  ([    "wc_factor": 125,  "quality_decay_factor": 150, "wc_fix_offset":15, ])}),\
({  "urboes",  ([    "damage_type_add": "unholy",  "wc_factor": 110, "nekro_bonus": (["all":15]), ])}),\
({  "gehaertet",  ([    "quality_decay_factor": 300, "wc_factor": 125])}),\
})
#define VHIGH_PREFIX_WEAPON1 ({\
({  "grausam",  ([    "damage_type_add": "terror",  "wc_factor": 110,  ])}),\
({  "laut",  ([    "damage_type_add": "sound",  "wc_factor": 110 ])}),\
({  "golden",  ([    "material": "Au",    "weight_factor": 200,    "quality_decay_factor": 250, "wc_factor": 115, "magic_health_modifier":(["hp":3, "sp":3]), ])}),\
({  "beeindruckend", ([ "wc_factor":110, "wc_fix_offset": 10, "quality_decay_factor": 200,  "value_factor": 200, ])}),\
({  "brutal",  ([   "hit_func": 1,  "wc_factor": 160,   "wc_fix_offset": -50,  ])}),\
({  "ultrahart",  ([    "quality_decay_factor": 800, "wc_factor": 120])}),\
({  "staehlern",  ([    "wc_factor": 115,  "material":"steel", "wc_fix_offset": 10, "quality_decay_factor": 200, "weight_factor": 120, ])}),\
({  "bronzen",  ([    "wc_factor": 110,  "material":"bronce", "wc_fix_offset": 5, "quality_decay_factor": 150, "weight_factor": 130, ])}),\
({  "leuchtend",  ([    "light": 1,  ])}),\
({  "dunkl",  ([    "light": -1,  ])}),\
({  "funkelnd",  ([    "light": 1,  ])}),\
({  "schattig",  ([    "light": -1,  ])}),\
({  "hervorragend", ([ "wc_factor":120, "quality_decay_factor": 200,  "weight_factor": 80,"magic_health_modifier":(["hp":3, "sp":3]), ])}),\
({  "rasend",  ([  "wc_factor": 80, "wc_fix_offset":40,  "teleport_cost":2  ])}),\
({  "satanisch",  ([    "nekro_bonus": (["all":20]), "nekro_spellcost":10, ])}),\
})


#define GODLY_PREFIX_WEAPON ({\
({  "",  ([    "name": "Kronangs",    "hit_func": 2,    "wc_fix_offset": 30,    "value_factor": 400,    "wc_factor": 150, "berserker_bonus": (["all":30]) ])}),\
({  "",  ([    "name": "Anvars",    "damage_type_add": "magic",    "value_factor": 400,    "wc_factor": 130, "itemd_elemental_value": (["all":10]),])}),\
({  "",  ([    "name": "Aylas",    "hit_func": 2,    "damage_type_add": "holy",    "wc_fix_offset": 40,    "value_factor": 400,    "wc_factor": 120, "paladin_spellcost": 10, ])}),\
({  "",  ([    "name": "Zechus'",    "quality_decay_factor": 0,    "value_factor": 400,    "wc_factor": 130,  "zechpreller_reduce_alc": 30, "zechpreller_bonus": (["all": 30]), "zechpreller_spellcost": 10, ])}),\
({  "",  ([    "name": "Woodys",    "quality_decay_factor": 0,    "damage_type_add": "fire",    "wc_fix_offset": 30,    "wc_factor": 135,  "value_factor": 2000, "teleport_cost":3 ])}),\
({  "",  ([    "name": "Dustys",    "hit_func": 2,    "quality_decay_factor": 0,    "damage_type_add": "holy",    "wc_factor": 155, "wc_fix_offset": 30,    "value_factor": 3000, "paladin_spellcost": 15, "teleport_cost":3 ])}),\
({  "",  ([    "name": "Lloths",    "quality_decay_factor": 200,    "damage_type_add": "unholy",    "wc_fix_offset": 30,    "wc_factor": 135,  ])}),\
({  "",  ([    "name": "Xarfais",    "quality_decay_factor": 200,    "damage_type_add": "unholy",    "wc_fix_offset": 30,    "wc_factor": 135, "nekro_spellcost": 15, ])}),\
({  "",  ([    "name": "Artyrians",    "quality_decay_factor": 200,    "damage_type_add": "sound",    "wc_fix_offset": 30,    "wc_factor": 135, "barden_spellcost": 15, ])}),\
({  "",  ([    "name": "Raziels",    "quality_decay_factor": 200,    "damage_type_add": "poison",    "wc_fix_offset": 30,    "wc_factor": 135, "ranger_spellcost": 15, "ranger_bonus": (["all": 10])])}),\
({  "einzigartig",  ([    "quality_decay_factor": 500,    "wc_fix_offset": 25,    "value_factor": 1000,    "wc_factor": 140,   "magic_health_modifier":(["hp":6, "sp":6]),])}),\
({  "ultimativ",  ([    "quality_decay_factor": 200,    "wc_fix_offset": 40,    "value_factor": 200,    "wc_factor": 120,   "magic_health_modifier":(["hp":8, "sp":8]),])}),\
({  "unglaublich",  ([    "hit_func": 2,    "quality_decay_factor": 200,    "wc_fix_offset": 60, "value_factor":150,  "magic_health_modifier":(["hp":6, "sp":6]),])}),\
({  "goettlich",  ([    "quality_decay_factor": 0,    "wc_fix_offset": 25,    "value_factor": 300,    "wc_factor": 140,  "magic_health_modifier":(["hp":7, "sp":7]), "teleport_cost":3 ])}),\
({  "meisterhaft",  ([    "quality_decay_factor": 300,    "wc_fix_offset": 15,    "value_factor": 200,    "wc_factor": 130,  "hit_func": 1,  "magic_health_modifier":(["hp":5, "sp":5]),])}),\
({  "kaiserlich", ([ "hit_func":2, "wc_factor":120, "wc_fix_offset": 20, "quality_decay_factor": 300, "value_factor": 500,  "magic_health_modifier":(["hp":5, "sp":5]),])}),\
({  "perfekt", ([ "wc_fix_offset": 60, "wc_factor":110, "quality_decay_factor": 300, "value_factor": 600, ])}),\
})
#define GODLY_PREFIX_WEAPON1 ({\
({  "ultramagisch",  ([   "hit_func":1, "wc_factor":125, "wc_fix_offset":20, "damage_type_add": "magic",  "magic_health_modifier":(["sp":23]), "teleport_cost":3])}),\
({  "gleissend",  ([    "light": 2,"wc_fix_offset": 20,  "magic_health_modifier":(["sp":9]), ])}),\
({  "finster",  ([    "light": -2, "wc_factor":110,  "magic_health_modifier":(["sp":9]),"nekro_bonus": (["schrecken der finsterniss":30, "all":5]), "nekro_spellcost":10 ])}),\
({  "strahlend",  ([    "light": 2, "damage_type_add": "light" ,  "magic_health_modifier":(["sp":19]),])}),\
({  "",  ([    "name": "Cains",    "hit_func": 1,   "wc_fix_offset": 20,    "value_factor": 300,    "wc_factor": 120,  "quality_decay_factor": 0, "itemd_prob_change": 30 ])}),\
({  "meisterlich",  ([    "quality_decay_factor": 200,  "value_factor": 200,    "wc_factor": 120, "wc_fix_offset": 20, "hit_func": 1,  "magic_health_modifier":(["hp":6, "sp":6]), "damage_type_add": "magic", ])}),\
})

#define LOW_SUFFIX_WEAPON ({\
({  "der Narren",  ([    "cursed": 1,    "wc_factor": 0,  ])}),\
({  "des Wolfes",  ([    "wc_factor": 105,  ])}),\
({  "des Baers",  ([    "wc_factor": 105,  ])}),\
({  "des Tigers",  ([    "wc_factor": 105,  ])}),\
({  "des Fraggles",  ([    "cursed": 1,    "wc_factor": -10,  ])}),\
({  "des Unbekannten",  ([  ])}),\
({  "des Bekannten",  ([  ])}),\
({  "des Dschungelwaechters",  ([    "weight_factor": 90,  ])}),\
({  "der Eitelkeit",  ([    "value_factor": 150,  ])}),\
({  "des Adlers",  ([    "wc_factor": 105,  ])}),\
({  "des Fuchses",  ([    "wc_factor": 105,  ])}),\
({  "der Qualitaet",  ([    "quality_decay_factor": 120,  ])}),\
({  "der Schaerfe",  ([    "wc_factor": 105,  ])}),\
({  "(Fraggletoeter)",  ([    "hit_func": "fraggle",  ])}),\
({  "(Vogeltoeter)",  ([    "hit_func": "bird",  ])}),\
({  "(Wurmtoeter)",  ([    "hit_func": "worm",  ])}),\
({  "(Insektentoeter)",  ([    "hit_func": "insect",  ])}),\
({  "(Fischtoeter)",  ([    "hit_func": "fish",  ])}),\
({  "(Spinnentoeter)",  ([    "hit_func": "spider",  ])}),\
({  "(Katzentoeter)",  ([    "hit_func": "cat",  ])}),\
({  "(Koboldtoeter)",  ([    "hit_func": "kobold",  ])}),\
({  "(Echsentoeter)",  ([    "hit_func": "lizard",  ])}),\
({  "(Froschtoeter)",  ([    "hit_func": "frog",  ])}),\
({  "(Geistervertreiber)",  ([    "hit_func": "ghost",  ])}),\
({  "des Landstreichers",  ([    "value_factor": 90,  ])}),\
({  "des Leopards",  ([    "wc_factor": 105,  ])}),\
({  "des Luchses",  ([    "wc_factor": 105,  ])}),\
({  "des Elefanten",  ([    "wc_factor": 105,  ])}),\
({  "der Kobra",  ([    "wc_fix_offset": 5,  ])}),\
({  "der Schlange",  ([    "wc_fix_offset": 5,  ])}),\
({  "des Stiers",  ([    "wc_fix_offset": 3,    "wc_factor": 103,  ])}),\
({  "des Hengstes",  ([    "wc_fix_offset": 3,    "wc_factor": 103,  ])}),\
({  "des Gorillas",  ([    "wc_factor": 105,  ])}),\
({  "des Schimpansen",  ([    "wc_factor": 105,  ])}),\
({  "der Peinlichkeit",  ([    "wc_factor": 70,  ])}),\
({  "des Krokodils",  ([    "wc_factor": 105,  ])}),\
({  "des Igels",  ([    "wc_factor": 105,  ])}),\
({  "des Tapirs",  ([    "wc_factor": 105,  ])}),\
({  "des Schroeters",  ([    "wc_fix_offset": 5,  ])}),\
({  "der Hornissen",  ([    "wc_fix_offset": 5,  ])}),\
({  "der Bienen",  ([    "wc_fix_offset": 5,  ])}),\
({  "der Wespen",  ([    "wc_fix_offset": 5,  ])}),\
({  "des Wildschweins",  ([    "wc_fix_offset": 5,  ])}),\
({  "(Funkenwerfer)",  ([    "charge_mod": ({"spark", 10, 100, 5}),  ])}),\
({  "der Verzauberung",  ([    "itemd_prob_change": 4,  ])}),\
})

#define LOW_SUFFIX_WEAPON1 ({\
({  "der Elfen",  ([    "quality_decay_factor": 120,  ])}),\
({  "der Zwerge",  ([    "quality_decay_factor": 120,  ])}),\
({  "(Beuteltierzerstueckler)",  ([  "wc_factor":110,  ])}),\
({  "des Hirtens",  ([   "value_factor": 90,  ])}),\
({  "des Erdbeerschleckers",  ([   "value_factor": 90,  ])}),\
({  "des Bibers",  ([    "wc_factor": 105,  ])}),\
({  "der Orks",  ([    "wc_factor": 105,  "quality_decay_factor": 90, "value_factor": 50, ])}),\
({  "der Trolle",  ([    "quality_decay_factor": 110, "weight_factor": 120 ])}),\
({  "der Feen",  ([    "quality_decay_factor": 110, "value_factor": 120, ])}),\
({  "der Hobbits",  ([    "quality_decay_factor": 110, "weight_factor": 80 ])}),\
({  "der Oger",  ([    "quality_decay_factor": 110, "value_factor": 80, ])}),\
({  "der Feenkraft",  ([    "cursed": 1,    "attr_mod": ([   "str": -2, ]),  ])}),\
({  "der Babykraft",  ([    "cursed": 1,    "attr_mod": ([   "str": -3, ]),  ])}),\
({  "der Ungeschicklichkeit",  ([    "cursed": 1,    "attr_mod": ([   "dex": -2, ]),  ])}),\
({  "der linken Haende",  ([    "cursed": 1,    "attr_mod": ([   "dex": -3, ]),  ])}),\
({  "der Krankheit",  ([    "cursed": 1,    "attr_mod": ([   "con": -2, ]),  ])}),\
({  "der Todesnaehe",  ([    "cursed": 1,    "attr_mod": ([   "con": -3, ]),  ])}),\
({  "der Ogerklugheit",  ([    "cursed": 1,    "attr_mod": ([   "int": -2, ]),  ])}),\
({  "der Trollweisheit",  ([    "cursed": 1,    "attr_mod": ([   "int": -3, ]),  ])}),\
    })

#define MED_SUFFIX_WEAPON ({\
({  "des Loewen",  ([    "wc_factor": 110,  ])}),\
({  "des Roks",  ([    "wc_fix_offset": 5,    "wc_factor": 110,  ])}),\
({  "des Offiziers",  ([    "wc_fix_offset": 10,  ])}),\
({  "der Zerstoerung",  ([    "hit_func": 1,  ])}),\
({  "der Aggression",  ([    "aggressive": 1,  ])}),\
({  "der Macht",  ([    "wc_factor": 110,  ])}),\
({  "der Energie",  ([    "wc_factor": 110,  ])}),\
({  "des Sieges",  ([    "hit_func": 1,  ])}),\
({  "(Menschentoeter)",  ([    "hit_func": "human",  ])}),\
({  "(Zwergentoeter)",  ([    "hit_func": "dwarf",  ])}),\
({  "(Elfentoeter)",  ([    "hit_func": "elf",  ])}),\
({  "(Hobbittoeter)",  ([    "hit_func": "hobbit",  ])}),\
({  "(Dunkelelftoeter)",  ([    "hit_func": "darkelf",  ])}),\
({  "(Ogertoeter)",  ([    "hit_func": "ogre",  ])}),\
({  "(Trolltoeter)",  ([    "hit_func": "troll",  ])}),\
({  "(Feentoeter)",  ([    "hit_func": "fairy",  ])}),\
({  "(Wolfstoeter)",  ([    "hit_func": "wolf",  ])}),\
({  "(Baerentoeter)",  ([    "hit_func": "bear",  ])}),\
({  "(Elementartoeter)",  ([    "hit_func": "elemental",  ])}),\
({  "(Zombietoeter)",  ([    "hit_func": "zombie",  ])}),\
({  "(Skelettoeter)",  ([    "hit_func": "skeleton",  ])}),\
({  "(Gaffotoeter)",  ([    "hit_func": "gaffo",  ])}),\
({  "(Goblintoeter)",  ([    "hit_func": "goblin",  ])}),\
({  "(Orktoeter)",  ([    "hit_func": "orc",  ])}),\
({  "(Gnomtoeter)",  ([    "hit_func": "gnom",  ])}),\
({  "(Vampirtoeter)",  ([    "hit_func": "vampir",  ])}),\
({  "der Sinnlosigkeit",  ([    "cursed": 1,    "wc_factor": 0,  ])}),\
({  "der Ritter",  ([    "wc_factor": 110, "paladin_spellcost":3,  ])}),\
({  "des Kaempfers",  ([    "hit_func": 1,  ])}),\
({  "der Soeldner",  ([    "hit_func": 1,  ])}),\
({  "der Landwehr",  ([    "hit_func": 1,    "quality_decay_factor": 80,  ])}),\
({  "der Krieger",  ([    "hit_func": 1,    "quality_decay_factor": 110,  ])}),\
({  "des Krieges",  ([    "aggressive": 2,    "hit_func": 1,  ])}),\
({  "des Jaguars",  ([    "wc_factor": 110,  ])}),\
({  "des Pumas",  ([    "wc_factor": 110,  ])}),\
({  "der Liebe",  ([    "wc_fix_offset": 15,    "wc_factor": 85,  ])}),\
({  "der Bosheit",  ([    "wc_fix_offset": -20,    "wc_factor": 125, "nekro_spellcost": 3, ])}),\
({  "des Unerwarteten",  ([    "hit_func": "random",    "cursed": 1,    "quality_decay_factor": 20,  ])}),\
({  "(Vogelausrotter)",  ([    "hit_func": "bird",    "wc_fix_offset": 5,    "wc_factor": 110,  ])}),\
({  "(Wurmausrotter)",  ([    "hit_func": "worm",    "wc_fix_offset": 5,    "wc_factor": 110,  ])}),\
({  "(Insektenausrotter)",  ([    "hit_func": "insect",    "wc_fix_offset": 5,    "wc_factor": 110,  ])}),\
({  "(Fischausrotter)",  ([    "hit_func": "fish",    "wc_fix_offset": 5,    "wc_factor": 110,  ])}),\
({  "(Spinnenausrotter)",  ([    "hit_func": "spider",    "wc_fix_offset": 5,    "wc_factor": 110,  ])}),\
({  "(Katzenausrotter)",  ([    "hit_func": "cat",    "wc_fix_offset": 5,    "wc_factor": 110,  ])}),\
({  "(Koboldausrotter)",  ([    "hit_func": "kobold",    "wc_fix_offset": 5,    "wc_factor": 110,  ])}),\
({  "(Echsenausrotter)",  ([    "hit_func": "lizard",    "wc_fix_offset": 5,    "wc_factor": 110,  ])}),\
({  "(Froschausrotter)",  ([    "hit_func": "frog",    "wc_fix_offset": 5,    "wc_factor": 110,  ])}),\
({  "(Geistervertilger)",  ([    "hit_func": "ghost",    "wc_fix_offset": 5,    "wc_factor": 110,  ])}),\
({  "(Funkenwerfer)",  ([    "charge_mod": ({"spark", 5, 300, 5}),  ])}),\
})
#define MED_SUFFIX_WEAPON1 ({\
({  "des Gluecks",  ([   "itemd_prob_change":7  ])}),\
({  "des Lebenspunkts",  ([     "magic_health_modifier":(["hp":1,"sp":0]), ])}),\
({  "des Magiepunkts",  ([     "magic_health_modifier":(["hp":0,"sp":1]), ])}),\
({  "der Seuche",  ([     "magic_health_modifier":(["hp":-10,"sp":0]), ])}),\
({  "des Hais",  ([    "hit_func": "fish",    "wc_factor": 110,  ])}),\
({  "des Rammens",  ([    "berserker_bonus": (["rammen":20]),  ])}),\
({  "des Zertretens",  ([    "berserker_bonus": (["zertreten":20]),  ])}),\
({  "des Kopfstosses",  ([    "berserker_bonus": (["kopfstoss":20]),  ])}),\
({  "des Kampfschreis",  ([    "berserker_bonus": (["kampfschrei":20]),  ])}),\
({  "der Willenskraft",  ([    "berserker_bonus": (["willenskraft":20]),  ])}),\
({  "der Regeneration",  ([    "berserker_bonus": (["regeneration":20]),  ])}),\
({  "des Spaltens",  ([    "berserker_bonus": (["spalten":20]),  ])}),\
({  "des Schlachtrufes",  ([    "berserker_bonus": (["schlachtruf":20]),  ])}),\
({  "des Gebetes",  ([    "paladin_spellcost": 5, ])}),\
({  "des Moenchs",  ([    "paladin_spellcost": 5, ])}),\
({  "des Sarnaks",  ([     "aggressive": 1, "wc_factor": 110,   ])}),\
({  "(Sarnaktoeter)",  ([    "hit_func": "sarnak",  ])}),\
({  "der Niederlage",  ([    "wc_factor": 50, "wc_fix_offset": -30, "cursed":1])}),\
({  "des Zombies",  ([    "nekro_bonus": (["anrufung des kharr-zzteth":15]), "nekro_spellcost":3  ])}),\
({  "der Toten",  ([    "nekro_bonus": (["unterwerfung der toten":15]), "nekro_spellcost":3  ])}),\
({  "der Untoten",  ([    "nekro_bonus": (["unterwerfung der toten":15]), "nekro_spellcost":3  ])}),\
({  "des Vampirbisses",  ([    "nekro_bonus": (["biss des vampirs":15]), "nekro_spellcost":3  ])}),\
({  "des Fluches",  ([    "nekro_bonus": (["fluch der klinge":15]), "nekro_spellcost":3  ])}),\
({  "der Verwesung",  ([    "nekro_bonus": (["hauch der verwesung":15]), "nekro_spellcost":3  ])}),\
({  "des Schreckens",  ([    "nekro_bonus": (["schrecken der finsterniss":15]), "nekro_spellcost":3  ])}),\
({  "des Skelettes",  ([    "nekro_bonus": (["all":5]), "nekro_spellcost":3  ])}),\
({  "des Pilgers",  ([    "value_factor": 10, "paladin_spellcost":3,  ])}),\
({  "des Bettelmoenchs",  ([ "value_factor": 1,   "paladin_spellcost": 4, ])}),\
({  "der Elfenkraft",  ([    "cursed": 1,    "attr_mod": ([   "str": -1, ]),  ])}),\
({  "der Faulheit",  ([    "cursed": 1,    "attr_mod": ([   "dex": -1, ]),  ])}),\
({  "der Erschoepfung",  ([    "cursed": 1,    "attr_mod": ([   "con": -1, ]),  ])}),\
({  "des Schwachsinns",  ([    "cursed": 1,    "attr_mod": ([   "int": -1, ]),  ])}),\
({  "des Bieres",  ([  "zechpreller_reduce_alc": 20])}),\
({  "des Weines",  ([  "zechpreller_bonus": (["all": 10])])}),\
({  "des Schnapses",  ([ "zechpreller_spellcost": 5])}),\
({  "der Eleganz",  ([    "value_factor": 130, "weight_factor": 90, "wc_factor": 105, ])}),\
({  "der Musik",  ([    "barden_bonus": (["all": 5]), "barden_spellcost": 3 ])}),\
})


#define HIGH_SUFFIX_WEAPON ({\
({  "der Unbrauchbarkeit",  ([    "weapon_type": "misc",    "wc_factor": -300,  ])}),\
({  "der Drachen",  ([    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "der Vernichtung",  ([    "hit_func": 2,  ])}),\
({  "des Wahnsinns",  ([    "aggressive": 2,    "cursed": 1,  ])}),\
({  "der Harmonie",  ([    "wc_fix_offset": 15,  ])}),\
({  "des Mondes",  ([    "damage_type_add": "magic",  ])}),\
({  "des Blitzes",  ([    "damage_type_add": "lightning",  ])}),\
({  "des Donners",  ([    "damage_type_add": "sound",  ])}),\
({  "der Sturmflut",  ([    "damage_type_add": "water",  ])}),\
({  "des Triumphes",  ([    "hit_func": 2,  ])}),\
({  "(Golemzerschmetterer)",  ([    "hit_func": "golem",  ])}),\
({  "(Daemonenbezwinger)",  ([    "hit_func": "demon", "paladin_spellcost": 3 ])}),\
({  "(Untotenvernichter)",  ([    "hit_func": "undead", "paladin_spellcost": 3 ])}),\
({  "(Riesentoeter)",  ([    "hit_func": "giant",  ])}),\
({  "(Berserkertoeter)",  ([    "hit_func": "berserker",  ])}),\
({  "(Paladintoeter)",  ([    "hit_func": "paladin",  "nekro_spellcost": 3])}),\
({  "(Druidentoeter)",  ([    "hit_func": "druide",  ])}),\
({  "(Nekromantentoeter)",  ([    "hit_func": "necromant", "paladin_spellcost": 3 ])}),\
({  "gegen das Boese",  ([    "hit_func": "holy",  "paladin_spellcost": 5])}),\
({  "gegen das Gute",  ([    "hit_func": "unholy", "nekro_spellcost": 5 ])}),\
({  "der Brutalitaet",  ([    "aggressive": 2,    "hit_func": 3, "berserker_bonus": (["all":3]) ])}),\
({  "der Wucht",  ([    "hit_func": 2,    "wc_fix_offset": -100,    "wc_factor": 115,  ])}),\
({  "des Geldes",  ([    "hit_func": "money",  ])}),\
({  "der Maertyrer",  ([    "hit_func": "maertyrer", "wc_factor": 120,])}),\
({  "des Zufalls",  ([    "hit_func": "random", "itemd_prob_change":15 ])}),\
({  "des Blutrausches",  ([    "hit_func": "blutrausch",  "berserker_bonus": (["blutrausch":20, "all":2]),  ])}),\
({  "des Selbstmordes",  ([    "aggressive": 2,    "cursed": 1,  ])}),\
({  "(Menschenausrotter)",  ([    "hit_func": "human",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Zwergenausrotter)",  ([    "hit_func": "dwarf",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Elfenausrotter)",  ([    "hit_func": "elf",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Hobbitausrotter)",  ([    "hit_func": "hobbit",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Dunkelelfausrotter)",  ([    "hit_func": "darkelf",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Ogerausrotter)",  ([    "hit_func": "ogre",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Trollausrotter)",  ([    "hit_func": "troll",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Feenausrotter)",  ([    "hit_func": "fairy",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Wolfsausrotter)",  ([    "hit_func": "wolf",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Baerenausrotter)",  ([    "hit_func": "bear",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Gaffoausrotter)",  ([    "hit_func": "gaffo",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Goblinausrotter)",  ([    "hit_func": "goblin",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Orkausrotter)",  ([    "hit_func": "orc",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Gnomausrotter)",  ([    "hit_func": "gnom",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "(Funkenwerfer)",  ([    "charge_mod": ({"spark", 10, 500, 15}),  ])}),\
({  "des Feuerballs",  ([    "charge_mod": ({"fireball", 5, 800, 30}),  ])}),\
({  "(Vampirvertilger)",  ([    "hit_func": "vampir",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
})
#define HIGH_SUFFIX_WEAPON1 ({\
({  "des Giftpfeils",  ([    "charge_mod": ({"std_arrow_item", 10, 500, 15, "giftpfeil", "dt_poison"}),  ])}),\
({  "des Feuerpfeils",  ([    "charge_mod": ({"std_arrow_item", 10, 500, 15, "feuerpfeil", "dt_fire"}),  ])}),\
({  "des Eispfeils",  ([    "charge_mod": ({"std_arrow_item", 10, 500, 15, "eispfeil", "dt_cold"}),  ])}),\
({  "des Saeurepfeils",  ([    "charge_mod": ({"std_arrow_item", 10, 500, 15, "saeurepfeil", "dt_acid"}),  ])}),\
({  "der Lebenspunkte",  ([     "magic_health_modifier":(["hp":4,"sp":0]), ])}),\
({  "der Magiepunkte",  ([     "magic_health_modifier":(["hp":0,"sp":4]), ])}),\
({  "der Meditation",  ([     "magic_health_modifier":(["hp":-10,"sp":12]), ])}),\
({  "der Verschiebung",  ([     "magic_health_modifier":(["hp":12,"sp":-10]), ])}),\
({  "des Zorns",  ([    "aggressive": 1,    "wc_factor": 125,  ])}),\
({  "des Grauens",  ([    "damage_type_add": "terror",    "wc_factor": 105,  ])}),\
({  "des Alterns",  ([   "magic_health_modifier":(["hp":-20,"sp":15]), ])}),\
({  "der Sterne",  ([     "magic_health_modifier":(["hp":3,"sp":3]) ])}),\
({  "des Fruehlings",  ([    "damage_type_add": "sound",    "value_factor": 150,  ])}),\
({  "des Sommers",  ([    "damage_type_add": "air",     ])}),\
({  "des Herbstes",  ([    "damage_type_add": "water",    "value_factor": 150,   ])}),\
({  "des Winters",  ([    "damage_type_add": "cold",     ])}),\
({  "des Feuers",  ([    "damage_type_add": "fire",      ])}),\
({  "des Eises",  ([    "damage_type_add": "cold",   "quality_decay_factor": 110,    ])}),\
({  "der Saeure",  ([    "damage_type_add": "acid",    "wc_fix_offset": 10, ])}),\
({  "des Wassers",  ([    "damage_type_add": "water",  "weight_factor":80  ])}),\
({  "des Unheils",  ([    "damage_type_add": "unholy",  "wc_factor": 105  ])}),\
({  "der Austreibung",  ([    "damage_type_add": "holy", "wc_factor": 105   ])}),\
({  "der Furcht",  ([    "damage_type_add": "terror",  "wc_fix_offset": 5,  ])}),\
({  "des Giftes",  ([    "damage_type_add": "poison",   "wc_factor": 105,   ])}),\
({  "der Luft",  ([    "damage_type_add": "air",  "weight_factor":50   ])}),\
({  "der Psikraft",  ([    "damage_type_add": "mind", "magic_health_modifier":(["sp":3])   ])}),\
({  "des Zaubers",  ([    "damage_type_add": "magic", "magic_health_modifier":(["sp":3])   ])}),\
({  "des Laerms",  ([    "damage_type_add": "sound", "wc_factor": 105, "berserker_bonus": (["kampfschrei":25, "all":3])   ])}),\
({  "der Explosion",  ([    "damage_type_add": "explosion",   "wc_factor": 105,  ])}),\
({  "(Sarnakausrotter)",  ([    "hit_func": "sarnak",    "wc_fix_offset": 10,    "wc_factor": 115,  ])}),\
({  "des Teleports",  ([   "teleport_cost":2  ])}),\
({  "des Sehertors",  ([   "teleport_cost":2  ])}),\
({  "der Reise",  ([   "teleport_cost":2  ])}),\
({  "des Ghouls",  ([  "value_factor": 50,   "nekro_bonus": (["ruf_der_ghoule":20, "all":5]), "nekro_spellcost":5  ])}),\
({  "der Geister",  ([  "damage_type_add": "mind", "nekro_spellcost":5  ])}),\
({  "der Mumie",  ([   "magic_health_modifier":(["hp":1,"sp":1]), "nekro_bonus": (["all":10]), "nekro_spellcost":5  ])}),\
({  "des Daemons",  ([    "wc_factor": 115,  "damage_type_add": "unholy", "nekro_spellcost":5  ])}),\
({  "des Saeufers",  ([  "zechpreller_reduce_alc": 20, "zechpreller_bonus": (["all": 10])])}),\
({  "des Trinkers",  ([  "zechpreller_bonus": (["all": 10]), "zechpreller_spellcost": 5])}),\
({  "des Betrunkenen",  ([ "zechpreller_spellcost": 5, "zechpreller_reduce_alc": 20])}),\
({  "des Waldes",  ([ "ranger_spellcost": 5 ])}),\
})


#define VHIGH_SUFFIX_WEAPON ({\
({  "des Todes",  ([    "hit_func": 3,  ])}),\
({  "der Ogerkraft",  ([    "attr_mod": ([   "str": 2, ]),  ])}),\
({  "der Diebe",  ([    "attr_mod": ([   "dex": 2, ]),  ])}),\
({  "der Ausdauer",  ([    "attr_mod": ([   "con": 1, ]),  ])}),\
({  "der Intelligenz",  ([    "attr_mod": ([   "int": 1, ]),  ])}),\
({  "des Berserkertums",  ([    "hit_func": "blutrausch",    "wc_factor": 110,   "berserker_bonus": (["blutrausch":25, "all":5]) ,  ])}),\
({  "der Raserei",  ([    "aggressive": 3,    "wc_fix_offset": 20,    "wc_factor": 130,   "berserker_bonus": (["blutrausch":20, "all":5]),  ])}),\
({  "der Zeitalter",  ([    "quality_decay_factor": 0,  ])}),\
({  "des Blutes",  ([    "hit_func": "blood",  ])}),\
({  "des Vampirs",  ([    "hit_func": "vampire", "nekro_bonus": (["biss des vampirs":25, "all":2]), "nekro_spellcost":3 ])}),\
({  "des Schlaechters",  ([    "wc_factor": 135,   "berserker_bonus": (["spalten":20, "all":2]),  ])}),\
({  "des Reichtums",  ([    "hit_func": "money",    "value_factor": 800,  ])}),\
({  "(Drachentoeter)",  ([    "hit_func": "dragon",  ])}),\
({  "der Staerke",  ([    "attr_mod": ([   "str": 2, ]),  ])}),\
({  "der Flinkheit",  ([    "attr_mod": ([   "dex": 2, ]),  ])}),\
({  "der Konstitution",  ([    "attr_mod": ([   "con": 2, ]),  ])}),\
({  "der Erleuchtung",  ([    "attr_mod": ([   "int": 2, ]),  ])}),\
({  "des Golems",  ([    "attr_mod": ([   "int": -1,   "con": 3, ]),  ])}),\
({  "der Rafinesse",  ([    "attr_mod": ([   "str": -1,   "dex": 3, ]),  ])}),\
({  "des Berserkers",  ([    "attr_mod": ([   "str": 3,   "dex": -1, ]),   "berserker_bonus": (["all":5]),  ])}),\
({  "des Druiden",  ([    "material": "misc_wood", "attr_mod": ([   "int": 3,   "con": -1, "itemd_elemental_value": (["all": 3]), ]),])}),\
({  "des Philosophs",  ([    "attr_mod": ([   "int": 4,   "str": -1,   "con": -1, ]),  ])}),\
({  "des Wueterichs",  ([    "attr_mod": ([   "int": -1,   "str": 4,   "dex": -1, ]),   "berserker_bonus":(["blutrausch":25, "all":3])  ])}),\
({  "des Riesen",  ([    "attr_mod": ([   "int": -1,   "con": 4,   "dex": -1, ]), "berserker_bonus":(["riesenkraft":25, "all":2]) ])}),\
({  "der Schnelligkeit",  ([    "attr_mod": ([   "int": -1,   "str": -1,   "dex": 4, ]),  ])}),\
({  "des Kobolds",  ([    "hit_func": "random",    "wc_fix_offset": 15,  ])}),\
({  "(Golemzerbroeseler)",  ([    "hit_func": "golem",    "wc_fix_offset": 15,    "wc_factor": 120,])}),\
({  "(Daemonenvertilger)",  ([    "hit_func": "demon",    "wc_fix_offset": 15,    "wc_factor": 120, "paladin_spellcost": 5 ])}),\
({  "(Untotenvertilger)",  ([    "hit_func": "undead",    "wc_fix_offset": 15,    "wc_factor": 120, "paladin_spellcost": 5 ])}),\
({  "(Riesenausrotter)",  ([    "hit_func": "giant",    "wc_fix_offset": 15,    "wc_factor": 120,  ])}),\
({  "(Berserkerausrotter)",  ([    "hit_func": "berserker",    "wc_fix_offset": 15,    "wc_factor": 120,  ])}),\
({  "(Paladinausrotter)",  ([    "hit_func": "paladin",    "wc_fix_offset": 15,    "wc_factor": 120, "nekro_spellcost": 5 ])}),\
({  "(Druidenausrotter)",  ([    "hit_func": "druide",    "wc_fix_offset": 15,    "wc_factor": 120,  ])}),\
({  "(Nekromantenausrotter)",  ([    "hit_func": "necromant",    "wc_fix_offset": 15,    "wc_factor": 120,  "paladin_spellcost": 5])}),\
({  "(Funkenwerfer)",  ([    "charge_mod": ({"spark", 10, 1000, 5}),  ])}),\
({  "des Todesvortex'",  ([    "charge_mod": ({"vortex", 10, 600, 20}),  ])}),\
({  "des grossen Feuerballs",  ([    "charge_mod": ({"fireball", 5, 1300, 30}),  ])}),\
({  "des gluecklichen Zufalls",  ([    "itemd_prob_change": 20,  ])}),\
({  "des Mutes",  ([    "attr_mod": ([   "str": 1,  "con": 1]),  "paladin_spellcost": 5])}),\
({  "der Schoenheit",  ([    "attr_mod": ([   "int": 1,  "dex": 1]),  ])}),\
({  "der Muskeln",  ([    "attr_mod": ([   "str": 1,  "dex": 1]), "berserker_bonus":(["riesenkraft":25, "all":3]) ])}),\
({  "der Ueberlegenheit",  ([    "attr_mod": ([   "str": 1,  "int": 1]),  ])}),\
({  "der Weisheit",  ([    "attr_mod": ([   "con": 1,  "int": 1]), ])}),\
({  "des Akrobaten",  ([    "attr_mod": ([   "dex": 1,  "con": 1]),  ])}),\
})
#define VHIGH_SUFFIX_WEAPON1 ({\
({  "der Geschwindigkeit",  ([    "hit_func": "speed",  ])}),\
({  "der Ruhe",  ([     "magic_health_modifier":(["hp":0,"sp":5]), ])}),\
({  "der Unruhe",  ([     "magic_health_modifier":(["hp":0,"sp":-5]), ])}),\
({  "des Gurus",  ([     "magic_health_modifier":(["hp":-5,"sp":11]), ])}),\
({  "der Lebenskraft",  ([     "magic_health_modifier":(["hp":6,"sp":0]), ])}),\
({  "der Magiekraft",  ([     "magic_health_modifier":(["hp":0,"sp":6]), ])}),\
({  "des Jaehzorns",  ([    "aggressive": 2,    "wc_factor": 140,  "berserker_bonus": (["blutrausch":25, "all":2]) ])}),\
({  "der Magiespaehre",  ([   "magic_health_modifier":(["hp":-25,"sp":33]), ])}),\
({  "der Heiligkeit",  ([    "hit_func": "unholy",   "damage_type_add": "holy",  "paladin_spellcost": 10,  ])}),\
({  "der Unheiligkeit",  ([    "hit_func": "holy",   "damage_type_add": "unholy",  "nekro_spellcost":10  ])}),\
({  "des Paladins",  ([    "paladin_spellcost": 5,  "wc_factor": 110, ])}),\
({  "des Heiligen",  ([    "paladin_spellcost": 10,  ])}),\
({  "des Kreuzritters",  ([    "paladin_spellcost": 5,  "wc_factor": 110, "damage_type_add": "holy"])}),\
({  "(Maennertoeter)",  ([    "hit_func": "male",  ])}),\
({  "(Frauentoeter)",  ([    "hit_func": "female",  ])}),\
({  "der Amazonen",  ([    "hit_func": "male",  "wc_factor": 105, "wc_fix_offset":5])}),\
({  "der Sonne",  ([     "light":1,  "damage_type_add": "light",  ])}),\
({  "der Schatten",  ([    "damage_type_add": "unholy","light": -1,   ])}),\
({  "des Lichtes",  ([    "damage_type_add": "light", "light": 1,   ])}),\
({  "der Helligkeit",  ([    "light": 1,  "paladine_spellcost": 10])}),\
({  "der Dunkelheit",  ([    "light": -1, "nekro_bonus": (["strahlen der dunkelheit":30, "all":5]), "nekro_spellcost":5 ])}),\
({  "des Tages",  ([    "light": 1, "wc_factor": 120 ])}),\
({  "der Nacht",  ([    "light": -1, "wc_factor": 120 ])}),\
({  "des Kampfes",  ([   "wc_factor": 120,  "hit_func": 1,  "paladin_spellcost": 10, "berserker_bonus": (["all":5]) ])}),\
({  "des heiligen Kampfes",  ([  "wc_factor": 120, "wc_fix_offset":10,  "paladin_spellcost": 10, ])}),\
({  "der Teleportation",  ([   "teleport_cost":4  ])}),\
({  "der Weltreise",  ([   "teleport_cost":3  ])}),\
({  "des Nekromanten",  ([    "wc_factor": 120,  "nekro_bonus": (["all":10]), "nekro_spellcost":10  ])}),\
({  "der Daemonen",  ([    "wc_factor": 120,  "damage_type_add": "unholy", "nekro_spellcost":7  ])}),\
({  "des Meistersaeufers",  ([  "zechpreller_spellcost": 10, "zechpreller_reduce_alc": 20, "zechpreller_bonus": (["all": 10])])}),\
({  "des Zechprellers",  ([  "zechpreller_pellcost": 8, "zechpreller_reduce_alc": 15, "zechpreller_bonus": (["all": 12])])}),\
({  "des Barden",  ([    "wc_factor": 120,  "barden_bonus": (["all":10]), "barden_spellcost":10  ])}),\
({  "des Waldlaeufers",  ([    "wc_factor": 120,  "ranger_bonus": (["all":10]), "ranger_spellcost":10  ])}),\
})


#define GODLY_SUFFIX_WEAPON ({\
({  "der ultimativen Vernichtung",  ([    "hit_func": 4,  ])}),\
({  "der Trollkraft",  (["attr_mod": ([   "str": 3, ]),  "berserker_bonus": (["riesenkraft":25, "all":8]) ,"wc_factor": 135 ])}),\
({  "der Riesenkraft",  (["attr_mod": ([   "str": 4, ]), "berserker_bonus": (["riesenkraft":30, "all":10]) ,"wc_factor": 135 ])}),\
({  "der Titanenkraft",  (["attr_mod": ([   "str": 5, ]), "berserker_bonus": (["riesenkraft":30, "all":10]) ,"wc_factor": 135 ])}),\
({  "des Meisterdiebes",  (["attr_mod": ([   "dex": 3, ]), "wc_factor": 135 ])}),\
({  "des Diebesgottes",  (["attr_mod": ([   "dex": 4, ]),  "wc_factor": 135 ])}),\
({  "der ultimativen Geschicklichkeit",  ([    "attr_mod": ([   "dex": 5, ]), "wc_factor": 135  ])}),\
({  "der Gesundheit",  (["attr_mod": ([   "con": 3, ]), "wc_factor": 135  ])}),\
({  "der Unbeugsamkeit",  ([ "attr_mod": ([   "con": 4, ]), "wc_factor": 135  ])}),\
({  "der ultimativen Ausdauer",  ([  "attr_mod": ([   "con": 5, ]), "wc_factor": 135  ])}),\
({  "der Magie",  ([    "attr_mod": ([   "int": 3, ]), "teleport_cost":3, "wc_factor": 135 ])}),\
({  "des Magiemeisters",  ([    "attr_mod": ([   "int": 4, ]),"teleport_cost":4, "wc_factor": 135 ])}),\
({  "des absoluten Magiemeisters",  ([    "attr_mod": ([   "int": 5, ]), "teleport_cost":5, "wc_factor": 135   ])}),\
({  "der Verwuestung",  ([    "hit_func": "verwuestung", "wc_factor": 135  ])}),\
({  "der Goetter",  ([    "attr_mod": ([   "int": 2,   "str": 2,   "con": 2,   "dex": 2, ]), "teleport_cost":3, "wc_factor": 135  ])}),\
({  "des Gladiators",  ([    "attr_mod": ([   "str": 2,   "con": 2,   "dex": 1, ]),  "berserker_bonus": (["rammen":25, "all":10]), "wc_factor": 135 ])}),\
({  "des Kriegers",  ([    "attr_mod": ([   "str": 3,   "con": 2, ]), "wc_factor": 135  ])}),\
({  "des Koenigs",  ([    "attr_mod": ([   "int": 3,   "str": 2,   "dex": 1, ]), "wc_factor": 135  ])}),\
({  "des Einhorns",  ([    "attr_mod": ([   "int": 3,   "con": 2, ]), "paladin_spellcost": 10, "wc_factor": 135  ])}),\
({  "des Greifen",  ([    "attr_mod": ([   "int": 2,   "dex": 3, ]),  "wc_factor": 135 ])}),\
({  "des Fuersten",  ([    "attr_mod": ([   "str": 2,   "con": 3, ]),   "paladin_spellcost": 10, "wc_factor": 135 ])}),\
({  "des Herzogs",  ([    "attr_mod": ([   "int": 2,   "str": 3, ]),   "paladin_spellcost": 15, "wc_factor": 135 ])}),\
({  "des Haeuptlings",  ([    "attr_mod": ([   "int": 1,   "str": 3,   "con": 2, ]), "berserker_bonus": (["schlachtruf":30, "all":10]), "wc_factor": 135 ])}),\
({  "der Koenigin",  ([    "attr_mod": ([   "int": 3,   "con": 1,   "dex": 1, ]),  "wc_factor": 135 ])}),\
({  "der Magiequelle",  ([    "itemd_prob_change": 30, "magic_health_modifier":(["hp":0,"sp":22]), "wc_factor": 135  ])}),\
({  "der Apocalypse",  ([    "hit_func": 3, "wc_factor": 140, "wc_fix_offset": 10, ])}),\
({  "der Unsterblichkeit",  ([   "magic_health_modifier":(["hp":100,"sp":-60]), "wc_factor": 135 ])}),\
({  "des Astralleibs ",  ([   "magic_health_modifier":(["hp":-60,"sp":100]), "wc_factor": 135 ])}),\
({  "des Lebens",  ([    "magic_health_modifier":(["hp":60,"sp":-20]), "wc_factor": 135 ])}),\
({  "der Astralkraft",  ([    "magic_health_modifier":(["hp":-20,"sp":60]), "wc_factor": 135 ])}),\
})
#define GODLY_SUFFIX_WEAPON1 ({\
({  "der Paralyse",  ([    "hit_func": "paralyze", "wc_factor": 135  ])}),\
({  "(Drachenvernichter)",  ([    "hit_func": "dragon",    "wc_fix_offset": 30,    "wc_factor": 150,  ])}),\
({  "der grosse Funkenwerfer",  ([    "charge_mod": ({"spark", 5, 2000, 5}),  ])}),\
({  "des Todesvortex'",  ([    "charge_mod": ({"vortex", 10, 1200, 20}),  ])}),\
({  "des gigantischen Feuerballs",  ([    "charge_mod": ({"fireball", 5, 2500, 30}),  ])}),\
({  "(Maennervernichter)",  ([    "hit_func": "male", "wc_fix_offset": 30,    "wc_factor": 150,   ])}),\
({  "(Frauenvernichter)",  ([    "hit_func": "female","wc_fix_offset": 30,    "wc_factor": 150,   ])}),\
({  "der Strahlung",  ([    "light": 2, "wc_fix_offset": 20, "wc_factor": 135  ])}),\
({  "der Finsternis",  ([    "light": -2, "wc_factor": 130, "nekro_bonus": (["schrecken der finsterniss":30, "all":10]), "nekro_spellcost":10 ])}),\
({  "des Meisters",  ([    "quality_decay_factor": 200,  "value_factor": 200,    "wc_factor": 120, "wc_fix_offset": 20, "hit_func": 1,  "magic_health_modifier":(["hp":5, "sp":5]), "damage_type_add": "magic", ])}),\
({  "der ewigen Teleportation",  ([   "teleport_cost":10, "wc_factor": 135  ])}),\
({  "der Uebergilde",  ([  "ranger_bonus": (["all": 20]), "ranger_spellcost": 20, "barden_bonus": (["all": 20]), "barden_spellcost": 20, "berserker_bonus": (["all":30]), "itemd_elemental_value": (["all": 20]), "paladin_spellcost": 20, "nekro_spellcost": 20, "nekro_bonus": (["all":30]), "zechpreller_reduce_alc": 30, "zechpreller_bonus": (["all": 30]), "zechpreller_spellcost": 10, "magic_health_modifier":(["hp":7,"sp":3]),  "wc_factor": 135  ])}),\
({  "der Nekromantie",  ([    "nekro_bonus": (["all":30]), "nekro_spellcost":15, "magic_health_modifier":(["sp":10]) ])}),\
({  "des Meisternaehers",  ([    "skill_mod": (["sk_sewing":2500]),  ])}),\
({  "des Meistergerbers",  ([    "skill_mod": (["sk_tanning":2500]),  ])}),\
({  "des Meisterstollenbauers",  ([    "skill_mod": (["sk_digging":2500]),  ])}),\
({  "des Meisterbergmanns",  ([    "skill_mod": (["sk_prospect":2500]),  ])}),\
({  "des Meisterjuweliers",  ([    "skill_mod": (["sk_jewelry":2500]),  ])}),\
({  "des Meisterschmelzers",  ([    "skill_mod": (["sk_metallurgy":2500]),  ])}),\
({  "des Meisterwaffenschmieds",  ([    "skill_mod": (["sk_weaponsmithing":2500]),  ])}),\
({  "des Meisterruestungsschmieds",  ([    "skill_mod": (["sk_armoursmithing":2500]),  ])}),\
({  "des Meisterkochs",  ([    "skill_mod": (["sk_baking":2500]),  ])}),\
({  "des Meisterbrauers",  ([    "skill_mod": (["sk_brewing":2500]),  ])}),\
})

#define LOW_PREFIX_ARMOUR ({\
({  "prunkvoll",  ([    "value_factor": 200,  ])}),\
({  "schwer",  ([    "weight_factor": 200,  ])}),\
({  "leicht",  ([    "weight_factor": 50,  ])}),\
({  "federleicht",  ([    "weight_factor": 1,  ])}),\
({  "widerstandsfaehig",  ([    "quality_decay_factor": 120,  ])}),\
({  "stabil",  ([    "quality_decay_factor": 150,  ])}),\
({  "verrueckt",  ([    "ac_factor": 80,  ])}),\
({  "rubin glaenzend",  ([    "ac_factor": 110,  ])}),\
({  "bronze schimmernd",  ([    "ac_factor": 110,  ])}),\
({  "kupfern schimmernd",  ([    "ac_factor": 110, "magic_health_modifier":(["hp":1]), ])}),\
({  "verstaerkt",  ([    "ac_factor": 110,  ])}),\
({  "verflucht",  ([    "cursed": 1,  ])}),\
({  "schaebig",  ([    "value_factor": 50,  ])}),\
({  "wertvoll",  ([    "value_factor": 150,  ])}),\
({  "verziert",  ([    "value_factor": 125,  ])}),\
({  "plump",  ([    "weight_factor": 200,  ])}),\
({  "bleiern",  ([    "weight_factor": 300,  ])}),\
({  "weich",  ([    "quality_decay_factor": 40,  ])}),\
({  "klein",  ([    "weight_factor": 70,    "ac_factor": 70,  ])}),\
({  "gross",  ([    "weight_factor": 130,    "ac_factor": 110,  ])}),\
({  "teur",  ([    "value_factor": 200,  ])}),\
({  "billig",  ([    "value_factor": 1,  ])}),\
({  "schmutzig",  ([    "value_factor": 1,  ])}),\
({  "dick",  ([    "weight_factor": 120,    "ac_factor": 110,  ])}),\
({  "duenn",  ([    "weight_factor": 80,    "ac_factor": 90,  ])}),\
({  "veraltert",  ([    "weight_factor": 80,    "ac_factor": 90,  ])}),\
({  "altertuemlich",  ([    "quality_decay_factor": 120,    "value_factor": 120,    "ac_factor": 80,  ])}),\
({  "uralt",  ([    "quality_decay_factor": 150,    "value_factor": 150,    "ac_factor": 110,  ])}),\
({  "besonder",  ([    "weight_factor": 80,    "ac_factor": 90,  ])}),\
({  "ungewoehnlich",  ([    "quality_decay_factor": 130,    "value_factor": 180,    "ac_factor": 110,  ])}),\
({  "fremdartig",  ([    "quality_decay_factor": 200,    "value_factor": 150,    "ac_factor": 90,  ])}),\
({  "haltbar",  ([    "quality_decay_factor": 130,  ])}),\
({  "bestaendig",  ([    "quality_decay_factor": 120,  ])}),\
({  "versilbert",  ([   "material": "Ag", "quality_decay_factor": 120,    "value_factor": 120,  ])}),\
({  "vergoldet",  ([    "material": "Au","weight_factor": 150,    "quality_decay_factor": 120,    "value_factor": 150,  ])}),\
({  "verrottet",  ([    "quality_decay_factor": 30,    "value_factor": 10,  ])}),\
({  "verrostet",  ([    "quality_decay_factor": 50,    "value_factor": 30,  ])}),\
({  "bunt",  ([    "value_factor": 110,  ])}),\
({  "bemalt",  ([    "value_factor": 120,  ])}),\
({  "blumengeschmueckt",  ([    "value_factor": 130,  ])}),\
({  "federnverziert",  ([    "value_factor": 140,  ])}),\
({  "unglueckbringend",  ([    "cursed": 1,  ])}),\
({  "unheimlich",  ([    "cursed": 1,  ])}),\
({  "abgetragen",  ([    "quality_decay_factor": 70,    "value_factor": 70,  ])}),\
({  "rissig",  ([    "quality_decay_factor": 50,    "ac_factor": 70,  ])}),\
({  "bequem",  ([    "weight_factor": 80,    "ac_factor": 110,  ])}),\
({  "unbequem",  ([    "weight_factor": 120,    "ac_factor": 90,  ])}),\
({  "minderwertig",  ([    "quality_decay_factor": 20,    "ac_factor": 20,  ])}),\
({  "stinkend",  ([    "value_factor": 5,  ])}),\
({  "wohlduftend",  ([    "value_factor": 125,  ])}),\
({  "schoen",  ([    "value_factor": 120,  ])}),\
({  "haesslich",  ([    "value_factor": 80,  ])}),\
({  "perlenverziert",  ([    "value_factor": 135,  ])}),\
({  "sinnlos",  ([    "cursed": 1,    "ac_factor": 0,  ])}),\
({  "waermend",  ([    "temperature_protection": ([   0: 1, ]),  ])}),\
({  "kuehlend",  ([    "temperature_protection": ([   1: 1, ]),  ])}),\
({  "gefroren",  ([    "temperature_protection": ([   0: -1, ]),  ])}),\
({  "erhitzt",  ([    "temperature_protection": ([   1: -1, ]),  ])}),\
({  "warm",  ([    "temperature_protection": ([   0: 1, ]),  ])}),\
({  "kuehl",  ([    "temperature_protection": ([   1: 1, ]),  ])}),\
({  "genoppt",  ([ "weight_factor": 110,    "ac_factor": 105,  ])}),\
})
#define LOW_PREFIX_ARMOUR1 ({\
({  "machtlos",  ([    "ac_factor": 80, "quality_decay_factor": 80, ])}),\
({  "kindlich",  ([    "ac_factor": 70, "weight_factor":50 ])}),\
({  "instabil",  ([    "ac_factor": 70, ])}),\
({  "verchromt",  ([    "quality_decay_factor": 110,    "value_factor": 110,  ])}),\
({  "lustig",  ([    "quality_decay_factor": 90,    "value_factor": 110,  ])}),\
({  "schuechtern",  ([    "ac_factor": 50, ])}),\
({  "suendig",  ([    "value_factor": 110 ])}),\
({  "laecherlich",  ([    "value_factor": 10 , "ac_factor": 10])}),\
({  "alt",  ([    "quality_decay_factor": 90,    "value_factor": 90,    "ac_factor": 90,  ])}),\
({  "neu",  ([    "quality_decay_factor": 110,    "value_factor": 110,    "ac_factor": 105,  ])}),\
({  "einfach",  ([    "ac_factor": 80, ])}),\
({  "graviert",  ([    "value_factor": 110,  ])}),\
({  "unnuetz",  ([    "value_factor": 50,  ])}),\
({  "verfault",  ([    "value_factor": 10,   "ac_factor": 50])}),\
({  "erdbeerig",  ([    "value_factor": 50,  ])}),\
({  "sauber",  ([    "value_factor": 120,  ])}),\
({  "grindig",  ([    "value_factor": 50, "ac_factor": 50, "quality_decay_factor":50,  ])}),\
})

#define MED_PREFIX_ARMOUR ({\
({  "juwelenverziert",  ([    "value_factor": 300,  ])}),\
({  "bruchfest",  ([    "quality_decay_factor": 200,  ])}),\
({  "massiv",  ([    "quality_decay_factor": 250,  ])}),\
({  "stark",  ([    "wc_factor": 120,  ])}),\
({  "smaragd glaenzend",  ([    "ac_factor": 120,  ])}),\
({  "staehlern schimmernd",  ([    "ac_factor": 120,  ])}),\
({  "hart",  ([    "quality_decay_factor": 200,  ])}),\
({  "butterweich",  ([    "quality_decay_factor": 10,    "ac_factor": 50,  ])}),\
({  "onyxfarben",  ([    "quality_decay_factor": 150,    "value_factor": 150,  ])}),\
({  "bernsteinfarben",  ([    "quality_decay_factor": 30, "magic_health_modifier":(["hp":3,"sp":1]), ])}),\
({  "lapislazulifarben",  ([    "dam_prot": ([   "magic": 1, ]), "magic_health_modifier":(["hp":2,"sp":2]), ])}),\
({  "zirkonfarben",  ([    "quality_decay_factor": 200,  ])}),\
({  "antik",  ([    "quality_decay_factor": 200,    "value_factor": 200,    "ac_factor": 120,  ])}),\
({  "aussergewoehnlich",  ([    "quality_decay_factor": 150,    "value_factor": 250,    "ac_factor": 120,  ])}),\
({  "wunderbar",  ([    "value_factor": 200,    "ac_factor": 120,  ])}),\
({  "verzaubert",  ([    "dam_prot": ([   "magic": 1, ]),  ])}),\
({  "zauberhaft",  ([    "dam_prot": ([   "magic": 1, ]),    "value_factor": 200, "magic_health_modifier":(["hp":-5,"sp":5]), ])}),\
({  "unheilbringend",  ([    "cursed": 1, "magic_health_modifier":(["hp":-5,"sp":-5]),  ])}),\
({  "edl",  ([    "value_factor": 250,  ])}),\
({  "hoelzern",  ([    "material": "misc_wood",    "weight_factor": 50,    "quality_decay_factor": 50,  ])}),\
({  "fest",  ([    "weight_factor": 120,    "ac_factor": 120,  ])}),\
({  "schwach",  ([    "weight_factor": 80,    "ac_factor": 80,  ])}),\
({  "uebelriechend",  ([    "value_factor": 20,  ])}),\
({  "bescheiden",  ([    "value_factor": 80,    "ac_factor": 80,  ])}),\
({  "begehrt",  ([    "value_factor": 150,    "ac_factor": 120,  ])}),\
({  "glatt",  ([    "quality_decay_factor": 110,    "ac_factor": 115,  ])}),\
({  "rauh",  ([    "quality_decay_factor": 70,    "ac_factor": 115,  ])}),\
({  "hitzebestaendig",  ([    "temperature_protection": ([   1: 1, ]),    "dam_prot": ([   "fire": 1, ]),  ])}),\
({  "kaeltebestaendig",  ([    "temperature_protection": ([   0: 1, ]),    "dam_prot": ([   "cold": 1, ]),  ])}),\
({  "heiss",  ([    "temperature_protection": ([   0: 2, ]), "material": "fire",  "itemd_elemental_value": (["feuer":3]) ])}),\
({  "eiskalt",  ([    "temperature_protection": ([   1: 2, ]), "material": "ice",  "itemd_elemental_value": (["eis":3]) ])}),\
({  "kalt",  ([    "temperature_protection": ([   1: 1, ]),  ])}),\
})
#define MED_PREFIX_ARMOUR1 ({\
({  "schimmernd",  ([    "value_factor": 120,  ])}),\
({  "glaenzend",  ([    "value_factor": 130,  ])}),\
({  "glitzernd",  ([    "ac_factor": 115, "value_factor": 120,  ])}),\
({  "abenteuerlich",  ([   "ac_factor": 130, "quality_decay_factor": 10,  ])}),\
({  "gesund",  ([     "magic_health_modifier":(["hp":3,"sp":0]), ])}),\
({  "intelligent",  ([     "magic_health_modifier":(["hp":0,"sp":3]), ])}),\
({  "grauenhaft",  ([    "ac_factor": 95,  ])}),\
({  "gluecklich",  ([    "itemd_prob_change":5])}),\
({  "zufaellig",  ([    "itemd_prob_change":3])}),\
({  "listig",  ([    "itemd_prob_change":3,  "value_factor": 120])}),\
({  "komisch",  ([    "quality_decay_factor": 10,   "ac_factor": 200,  ])}),\
({  "lustigbunt",  ([    "value_factor": 130, "itemd_prob_change":2 ])}),\
({  "zitternd",  ([    "temperature_protection": ([   1: 1, ]),  ])}),\
({  "klug",  ([     "magic_health_modifier":(["hp":0,"sp":3]), ])}),\
({  "dumm",  ([     "magic_health_modifier":(["hp":0,"sp":-3]), ])}),\
({  "bruechig",  ([    "quality_decay_factor": 20,  ])}),\
({  "seltsam",  ([   "ac_factor": 120, "quality_decay_factor": 20,  ])}),\
({  "betend",  ([    "paladin_spellcost": 3, ])}),\
({  "hitzig",  ([    "temperature_protection": ([   0: 1, ]),  ])}),\
({  "loechrig",  ([   "weight_factor":50 , "ac_factor": 90, "temperature_protection": ([   1: 2, ]), ])}),\
({  "luftig",  ([  "dam_prot": ([   "air": 1, ]), "weight_factor":50, "itemd_elemental_value": (["luft":3]), "material": "air" ])}),\
({  "feurig",  ([  "dam_prot": ([   "fire": 1, ]),  "itemd_elemental_value": (["feuer":3]), "temperature_protection": ([   0: 1, ]), "material": "fire" ])}),\
({  "waessrig",  ([  "dam_prot": ([   "water": 1, ]),  "itemd_elemental_value": (["wasser":3]), "quality_decay_factor": 110, "material": "water" ])}),\
({  "dornenbespickt",  ([    "effective_wc": 60,    "ac_factor": 115, "berserker_bonus": (["all":5]) ])}),\
({  "elegant",  ([    "value_factor": 130, "weight_factor": 90, "ac_factor": 115, ])}),\
})

#define HIGH_PREFIX_ARMOUR ({\
({  "stahlhart",  ([    "quality_decay_factor": 300,  ])}),\
({  "flammend",  ([    "temperature_protection": ([   0: 2, ]),    "dam_prot": ([   "water": 2, ]),  ])}),\
({  "heilig",  ([    "dam_prot": ([   "unholy": 2, ]),  "paladin_spellcost": 5, ])}),\
({  "daemonisch",  ([    "dam_prot": ([   "holy": 2, ]), "magic_health_modifier":(["sp":5]),  "nekro_spellcost": 4,])}),\
({  "magisch",  ([    "dam_prot": ([   "magic": 2, ]),  ])}),\
({  "silbrig schimmernd",  ([    "ac_factor": 130,  ])}),\
({  "gepanzert",  ([    "ac_factor": 130,  ])}),\
({  "unberechenbar",  ([    "ac_factor": 130,  ])}),\
({  "berechenbar",  ([    "ac_factor": 130,  ])}),\
({  "selten",  ([    "weight_factor": 80,    "quality_decay_factor": 70,    "ac_factor": 130,  ])}),\
({  "knoechern",  ([    "material": "bone",    "weight_factor": 50,    "quality_decay_factor": 50,  ])}),\
({  "steinern",  ([    "material": "stone",    "weight_factor": 150,    "quality_decay_factor": 120,  ])}),\
({  "beruehmt",  ([    "quality_decay_factor": 200,    "value_factor": 300,    "ac_factor": 150,  ])}),\
({  "glueckbringend",  ([   "itemd_prob_change":15 ])}),\
({  "wunderschoen",  ([    "value_factor": 350,  ])}),\
({  "makellos",  ([    "value_factor": 130,    "ac_factor": 125,  ])}),\
({  "eisig",  ([    "temperature_protection": ([   1: 2, ]),    "dam_prot": ([   "cold": 1, ]),  ])}),\
({  "gluehend",  ([    "temperature_protection": ([   0: 3, ]), "material": "fire",  "itemd_elemental_value": (["feuer":5]) ])}),\
({  "frostig",  ([    "temperature_protection": ([   1: 3, ]), "material": "ice", "itemd_elemental_value": (["eis":5]) ])}),\
({  "",  ([    "name": "Cirions",    "quality_decay_factor": 150, "ac_factor": 125, "teleport_cost":1 ])}),\
({  "",  ([    "name": "Lamuertes",    "quality_decay_factor": 200, "ac_factor": 130, "teleport_cost":1])}),\
({  "geschuppt", ([ "weight_factor":110, "quality_decay_factor": 150,"ac_factor": 125,])    }),\
({  "beinhart",  ([    "material": "bone",    "quality_decay_factor": 150,  ])}),\
({  "ultraleicht", ([ "weight_factor":10,])    }),\
({  "ultraschwer", ([ "weight_factor":300,])    }),\
({  "blitzend",  ([    "dam_prot": ([   "lightning": 2, ]),  ])}),\
})

#define HIGH_PREFIX_ARMOUR1 ({\
({  "fuerstlich",  ([    "ac_factor": 125,  "quality_decay_factor": 150, "value_factor": 150 ])}),\
({  "blutspendend",  ([     "magic_health_modifier":(["hp":5,"sp":0]), ])}),\
({  "magiebringend",  ([     "magic_health_modifier":(["hp":0,"sp":5]), "teleport_cost":1 ])}),\
({  "hinterlistig",  ([    "itemd_prob_change":3,  "value_factor": 120, "ac_factor":125])}),\
({  "toll",  ([    "ac_factor": 135,  "quality_decay_factor": 130,  "magic_health_modifier":(["hp":1,"sp":1]),])}),\
({  "gut",  ([    "ac_factor": 125,  "quality_decay_factor": 120, "weight_factor":80, ])}),\
({  "boes",  ([    "dam_prot":([ "holy":2]), "nekro_spellcost": 4, ])}),\
({  "giftig",  ([    "dam_prot": ([   "poison": 2, ]), "itemd_elemental_value": (["humus":5]), "material": "earth" ])}),\
({  "singend",  ([    "dam_prot": ([   "sound": 2, ]),  ])}),\
({  "aetzend",  ([    "dam_prot": ([   "acid": 2, ]),  ])}),\
({  "furchteinfloessend",  ([    "dam_prot": ([   "terror": 2, ]), "nekro_spellcost": 4, ])}),\
({  "funkendspruehend",  ([    "dam_prot": ([   "electric": 2, ]),  ])}),\
({  "gesegnet",  ([    "dam_prot": ([   "unholy": 2, ]), "ac_factor": 120, "paladin_spellcost":4 ])}),\
({  "maechtig",  ([    "ac_factor": 145,  ])}),\
({  "bemerkenswert",  ([    "ac_factor": 135, "value_factor": 150, ])}),\
({  "ultraweich",  ([    "quality_decay_factor": 10, "ac_factor": 80])}),\
({  "superhart",  ([    "quality_decay_factor": 500, "ac_factor": 120])}),\
({  "silbern",  ([    "material": "Ag",    "weight_factor": 130,    "quality_decay_factor": 150, "ac_factor": 125, "magic_health_modifier":(["hp":1, "sp":1]), ])}),\
({  "gruen",  ([    "dam_prot": ([   "poison": 1, ]), "itemd_elemental_value": (["humus":5]), "material": "earth" ])}),\
({  "rot",  ([    "dam_prot": ([   "fire": 1, ]), "itemd_elemental_value": (["feuer":5]), "berserker_bonus": (["all":5]), "material": "fire" ])}),\
({  "blau",  ([    "dam_prot": ([   "water": 1, ]), "itemd_elemental_value": (["wasser":5]), "material": "ice" ])}),\
({  "gelb",  ([    "dam_prot": ([   "air": 1, ]), "itemd_elemental_value": (["luft":5]), "material": "air" ])}),\
({  "violett",  ([    "dam_prot": ([   "magic": 1, ]), "itemd_elemental_value": (["erz":5]), "material": "misc_magic" ])}),\
({  "weiss",  ([    "dam_prot": ([   "cold": 1, ]), "itemd_elemental_value": (["eis":5]), "paladin_spellcost":4, "material": "ice"])}),\
({  "braun",  ([    "dam_prot": ([   "lightning": 1, ]), "ac_factor": 120, "magic_health_modifier":(["hp":1, "sp":1])])}),\
({  "grau",  ([    "dam_prot": ([   "sound": 1, ]), "quality_decay_factor": 150  ])}),\
({  "schwarz",  ([    "dam_prot": ([   "terror": 1, ]), "nekro_spellcost": 4, ])}),\
({  "schnell",  ([ "ac_factor": 130,  "teleport_cost":1, "amazonen_bonus": (["all": 5]) ])}),\
({  "stachelbewehrt",  ([    "effective_wc": 80,    "ac_factor": 125, "berserker_bonus": (["all":5]) ])}),\
})


#define VHIGH_PREFIX_ARMOUR ({\
({  "unzerstoerbar",  ([    "quality_decay_factor": 0,  ])}),\
({  "diamant glaenzend",  ([    "ac_factor": 140,  ])}),\
({  "golden schimmernd",  ([    "ac_factor": 140,  ])}),\
({  "",  ([    "name": "Angrox'",    "defend_func": 1,    "quality_decay_factor": 200,    "ac_factor": 140, "itemd_elemental_value": (["all": 6]),  "material": "leather", "teleport_cost":2 ])}),\
({  "",  ([    "name": "Feyarias",    "defend_func": 1,    "quality_decay_factor": 200,    "ac_factor": 140, "berserker_bonus": (["all":25]), "teleport_cost":2,  "effective_wc": 150 ])}),\
({  "",  ([    "name": "Creatives",    "dam_prot": ([   "holy": 2, ]),    "ac_factor": 140, "teleport_cost":2 ])}),\
({  "",  ([    "name": "Zordans",    "ac_factor": 140, "defend_func": 1, "teleport_cost":2 ])}),\
({  "beruechtigt",  ([    "quality_decay_factor": 300,    "value_factor": 500,    "ac_factor": 170,  ])}),\
({  "machtvoll",  ([    "defend_func": 1,    "ac_factor": 150,  ])}),\
({  "majestaetisch",  ([    "defend_func": 1,    "value_factor": 400,    "ac_factor": 150,  ])}),\
({  "",  ([    "name": "Elsurions",    "dam_prot": ([   "magic": 2, ]),    "defend_func": 1,    "quality_decay_factor": 200, "itemd_elemental_value": (["all": 4]), "material": "misc_magic"  ])}),\
({  "",  ([    "name": "Soordhins",    "defend_func": 1,    "quality_decay_factor": 150,    "ac_factor": 150, "berserker_bonus": (["all":20]),  ])}),\
({  "",  ([    "name": "Grimows",    "defend_func": 1,    "ac_factor": 170, "berserker_bonus": (["all":15]), ])}),\
({  "",  ([    "name": "Tenobaals",    "defend_func": 1,    "ac_factor": 140, "itemd_elemental_value": (["all":4]), "material": "feather", "weight_factor": 50 ])}),\
({  "",  ([    "name": "Mythars",    "dam_prot": ([   "unholy": 3, ]),    "ac_factor": 150, "paladin_spellcost":5, ])}),\
({  "",  ([    "name": "Ardares",    "quality_decay_factor": 200,    "ac_factor": 140, "magic_health_modifier":(["hp":7,"sp":7]),"paladin_spellcost":5, ])}),\
({  "thermoverstaerkt",  ([    "temperature_protection": ([   0: 2,   1: 2, ]),    "dam_prot": ([   "cold": 2,   "fire": 2, ]),  ])}),\
({  "sonnig",  ([    "light": 1, "temperature_protection": ([   0: 1, ]),    "dam_prot": ([   "light": 2, ]),  ])}),\
({  "koeniglich",  ([    "ac_factor": 175,  "quality_decay_factor": 200, "value_factor": 300 ,    "defend_func": 1,])}),\
({  "neblich",  ([    "dam_prot": ([   "water": 2, "air":2,]),   "quality_decay_factor": 50, "ac_factor":140 ])}),\
({  "zornig",  ([       "ac_factor": 140,  ])}),\
({  "fuerchterlich",  ([    "dam_prot": (["terror":2]),    "ac_factor": 145,  ])}),\
({  "geheimnisvoll",  ([  "itemd_prob_change":20,   "dam_prot": (["magic":2]), ])}),\
({  "sehrgut",  ([    "ac_factor": 140,  "quality_decay_factor": 140, "weight_factor":70, ])}),\
({  "urboes",  ([    "dam_prot":([ "holy":2]), "quality_decay_factor": 120, "nekro_bonus": (["all":20]), ])}),\
({  "gehaertet",  ([    "quality_decay_factor": 300, "ac_factor": 150])}),\
})
#define VHIGH_PREFIX_ARMOUR1 ({\
   ({  "golden",  ([    "material": "Au",    "weight_factor": 200,    "quality_decay_factor": 250, "ac_factor": 150, "magic_health_modifier":(["hp":3, "sp":3]), ])}),\
({  "laut",  ([    "dam_prot": ([   "sound": 2, ]),  "barden_bonus": (["all": 15]), "barden_spellcost": 3])}),\
({  "beeindruckend", ([ "ac_factor":150, "quality_decay_factor": 200,  "value_factor": 200, ])}),\
({  "brutal",  ([   "defend_func": 2,  "ac_factor": 80,   ])}),\
({  "elementar",  ([  "material": "misc_magic", "itemd_elemental_value": (["all":5]),  "dam_prot": (["cold":1, "fire":1, "water":1, "air":1])  ])}),\
({  "ultrahart",  ([    "quality_decay_factor": 800, "ac_factor": 190])}),\
({  "staehlern",  ([    "ac_factor": 155,  "material":"steel", "quality_decay_factor": 200,"weight_factor": 120,  ])}),\
({  "bronzen",  ([    "ac_factor": 140,  "material":"bronce", "quality_decay_factor": 150,"weight_factor": 130,  ])}),\
({  "anschmiegsam",  ([  "ac_factor": 145,"weight_factor": 70,"magic_health_modifier":(["hp":2, "sp":2])])}),\
({  "leuchtend",  ([    "light": 1,  ])}),\
({  "dunkl",  ([    "light": -1,  ])}),\
({  "schattig",  ([    "light": -1,  ])}),\
({  "funkelnd",  ([    "light": 1,  ])}),\
({  "hervorragend", ([ "ac_factor":150, "quality_decay_factor": 200,  "weight_factor": 80,"magic_health_modifier":(["hp":3, "sp":3]), ])}),\
({  "rasend",  ([ "ac_factor": 150,  "teleport_cost":2  ])}),\
({  "satanisch",  ([    "nekro_bonus": (["all":15]), "nekro_spellcost":5, ])}),\
({  "stachelig",  ([    "effective_wc": 140,    "ac_factor": 145, "weight_factor": 150, "berserker_bonus": (["all":10]) ])}),\
({  "waldig",  ([    "ranger_bonus": (["all": 15]), "ranger_spellcost": 3])}),\
({  "amazonenhaft",  ([    "amazonen_bonus": (["all": 15]), "amazonen_spellcost": 3])}),\
})

#define GODLY_PREFIX_ARMOUR ({\
({  "",  ([    "name": "Zechus'",    "defend_func": 2,   "value_factor": 200,  "ac_factor":240, "zechpreller_reduce_alc": 30, "zechpreller_bonus": (["all": 30]), "zechpreller_spellcost": 10])}),\
({  "",  ([    "name": "Woodys",    "defend_func": 2,    "quality_decay_factor": 0,    "ac_factor": 260,   "value_factor": 2000, "teleport_cost":3 ])}),\
({  "",  ([    "name": "Dustys",    "dam_prot": ([   "holy": 4,   "magic": 4,   "unholy": 4, ]),    "defend_func": 3,    "ac_factor": 250,   "value_factor": 3000, "paladin_spellcost": 15, "teleport_cost":3 ])}),\
({  "",  ([    "name": "Anvars",    "dam_prot": ([   "magic": 4,   "water": 4,   "cold": 4,   "fire": 4,   "air": 4, ]),    "ac_factor": 250,   "value_factor": 300, "magic_health_modifier":(["sp":25]), "itemd_elemental_value": (["all":15]), "material": "misc_magic" ])}),\
({  "",  ([    "name": "Aylas",    "dam_prot": ([   "unholy": 4, ]),    "defend_func": 2,    "ac_factor": 250,    "value_factor": 500, "magic_health_modifier":(["hp":25]), "paladin_spellcost": 15,])}),\
({  "",  ([    "name": "Lloths",    "dam_prot": ([   "holy": 4, ]),    "defend_func": 2,    "ac_factor": 240,  ])}),\
({  "",  ([    "name": "Xarfais",    "dam_prot": ([   "holy": 2, "light":2 ]),    "defend_func": 1,    "ac_factor": 240, "nekro_spellcost": 15, "nekro_bonus": (["all":30]), ])}),\
({  "",  ([    "name": "Kronangs",    "defend_func": 1,  "magic_health_modifier":(["hp":20]), "ac_factor":240, "temperature_protection": ([   0: 1,   1: 1, ]), "berserker_bonus": (["all":30]), "effective_wc": 200])}),\
({  "",  ([    "name": "Artyrians",    "dam_prot": ([   "sound":4 ]),    "defend_func": 2,    "ac_factor": 240, "barden_spellcost": 15, "barden_bonus": (["all":30]), ])}),\
({  "",  ([    "name": "Raziels",    "dam_prot": ([   "poison":4 ]),    "defend_func": 2,    "ac_factor": 240, "ranger_spellcost": 15, "ranger_bonus": (["all":30]), ])}),\
({  "",  ([    "name": "Hippolytes",     "magic_health_modifier":(["hp":20]),    "defend_func": 2,    "ac_factor": 240, "amazonen_spellcost": 15, "amazonen_bonus": (["all":30]), ])}),\
({  "einzigartig",  ([    "quality_decay_factor": 500,    "value_factor": 1000,    "ac_factor": 200,  "magic_health_modifier":(["hp":9, "sp":9]),])}),\
({  "ultimativ",  ([    "temperature_protection": ([   0: 1,   1: 1, ]),    "quality_decay_factor": 200,    "ac_factor": 280, "value_factor": 700,  "magic_health_modifier":(["hp":11, "sp":11]),])}),\
({  "unglaublich",  ([    "quality_decay_factor": 0,    "defend_func": 2,    "ac_factor": 250, "value_factor": 800,  "magic_health_modifier":(["hp":6, "sp":6]),])}),\
({  "goettlich",  ([    "temperature_protection": ([   0: 2,   1: 2, ]),    "defend_func": 2,    "quality_decay_factor": 0,    "value_factor": 300,    "ac_factor": 240,   "magic_health_modifier":(["hp":7, "sp":7, "teleport_cost":3 ]),])}),\
({  "meisterhaft",  ([    "quality_decay_factor": 300,  "value_factor": 200,    "ac_factor": 260,  "defend_func": 1,  "magic_health_modifier":(["hp":6, "sp":6]),])}),\
({  "kaiserlich",  ([    "ac_factor": 250,  "quality_decay_factor": 300, "value_factor": 400,    "defend_func": 2,  "magic_health_modifier":(["hp":5, "sp":5]),])}),\
({  "perfekt",  ([    "ac_factor": 500,  "quality_decay_factor": 300, "value_factor": 600,    "magic_health_modifier":(["hp":8, "sp":8]), ])}),\
})

#define GODLY_PREFIX_ARMOUR1 ({\
({  "ultramagisch",  ([   "defend_func":1, "ac_factor":175, "temperature_protection": ([   0: 1,   1: 1, ]) ,  "magic_health_modifier":(["sp":23]),])}),\
({  "strahlend",  ([    "amazonen_spellcost": 20, "amazonen_bonus": (["all": 10]), "light": 2, "ac_factor":240, "dam_prot": (["light":2]),  "magic_health_modifier":(["sp":13]),])}),\
({  "gleissend",  ([    "light": 3, "ac_factor":240,  "magic_health_modifier":(["sp":13]),])}),\
({  "finster",  ([    "light": -2, "ac_factor":240,  "magic_health_modifier":(["sp":13]), "nekro_bonus": (["schrecken der finsterniss":30, "all": 10]), "nekro_spellcost":10])}),\
({  "",  ([    "name": "Cains",    "defend_func": 1,  "value_factor": 300, "temperature_protection": ([ 0: 1, 1: 1, ]) ,  "ac_factor": 250,  "quality_decay_factor": 0, "itemd_prob_change": 30 ])}),\
({  "meisterlich",  ([    "quality_decay_factor": 200,  "value_factor": 200,    "ac_factor": 270,  "defend_func": 1,  "magic_health_modifier":(["hp":6, "sp":6]), "temperature_protection": ([   0: 2,   1: 2, ]), "dam_prot": (["magic":2]) ])}),\
})

#define LOW_SUFFIX_ARMOUR ({\
({  "der Narren",  ([    "cursed": 1,    "ac_factor": 50,  ])}),\
({  "des Wolfes",  ([    "ac_factor": 110,  ])}),\
({  "des Baers",  ([    "ac_factor": 110,  ])}),\
({  "des Tigers",  ([    "ac_factor": 110,  ])}),\
({  "des Fraggles",  ([    "cursed": 1,    "ac_factor": 20,  ])}),\
({  "des Unbekannten",  ([  ])}),\
({  "des Bekannten",  ([  ])}),\
({  "des Dschungelwaechters",  ([    "weight_factor": 90,  ])}),\
({  "der Verwundbarkeit",  ([    "defend_func": -1,    "cursed": 1,  ])}),\
({  "der Eitelkeit",  ([    "value_factor": 150,  ])}),\
({  "des Adlers",  ([    "ac_factor": 110,  ])}),\
({  "des Fuchses",  ([    "ac_factor": 105,  ])}),\
({  "der Qualitaet",  ([    "quality_decay_factor": 110,  ])}),\
({  "der Traenen",  ([  ])}),\
({  "der Elfen",  ([    "quality_decay_factor": 120,  ])}),\
({  "der Zwerge",  ([    "quality_decay_factor": 120,  ])}),\
({  "des Lachens",  ([    "value_factor": 120,  ])}),\
({  "der Verziertheit",  ([    "value_factor": 120,  ])}),\
({  "des Luchses",  ([    "ac_factor": 110,  ])}),\
({  "des Elefanten",  ([    "ac_factor": 110,  ])}),\
({  "der Kobra",  ([    "ac_factor": 110,  ])}),\
({  "der Schlange",  ([    "ac_factor": 110,  ])}),\
({  "des Stiers",  ([    "quality_decay_factor": 110,    "ac_factor": 105, "effective_wc": 50, ])}),\
({  "des Hengstes",  ([    "quality_decay_factor": 110,    "ac_factor": 105,  ])}),\
({  "des Gorillas",  ([    "ac_factor": 110,  ])}),\
({  "des Schimpansen",  ([    "ac_factor": 110,  ])}),\
({  "der Peinlichkeit",  ([    "ac_factor": 70,  ])}),\
({  "des Krokodils",  ([    "ac_factor": 110,  "effective_wc": 50])}),\
({  "des Igels",  ([    "ac_factor": 105,  "effective_wc": 60])}),\
({  "des Tapirs",  ([    "ac_factor": 105,  ])}),\
({  "des Schroeters",  ([    "ac_factor": 105,  ])}),\
({  "der Hornissen",  ([    "ac_factor": 105,  ])}),\
({  "der Bienen",  ([    "ac_factor": 105,  ])}),\
({  "der Wespen",  ([    "ac_factor": 105,  ])}),\
({  "des Wildschweins",  ([    "ac_factor": 105,  ])}),\
({  "der Wunden",  ([    "defend_func": -1,  ])}),\
({  "des Schwitzens",  ([    "temperature_protection": ([   1: -1, ]),  ])}),\
({  "des Frierens",  ([    "temperature_protection": ([   0: -1, ]),  ])}),\
({  "der Kaelte",  ([    "temperature_protection": ([   0: 1, ]),  ])}),\
({  "der Waerme",  ([    "temperature_protection": ([   1: 1, ]),  ])}),\
({  "des Frostes",  ([    "temperature_protection": ([   0: 2, ]),  ])}),\
({  "der Hitze",  ([    "temperature_protection": ([   1: 2, ]),  ])}),\
({  "des Temperaturschutzes",  ([    "temperature_protection": ([   0: 1,   1: 1, ]),  ])}),\
({  "(Funkenwerfer)",  ([    "charge_mod": ({"spark", 10, 100, 5}),  ])}),\
({  "der Verzauberung",  ([    "itemd_prob_change": 3,  ])}),\
})
#define LOW_SUFFIX_ARMOUR1 ({\
({  "des Hirtens",  ([   "value_factor": 90,   ])}),\
({  "des Erdbeerschleckers",  ([   "value_factor": 90,  ])}),\
({  "des Bibers",  ([    "ac_factor": 105,  ])}),\
({  "der Orks",  ([    "ac_factor": 105,  "quality_decay_factor": 90, "value_factor": 50, ])}),\
({  "der Sauna",  ([    "temperature_protection": ([   0: 2,   1: -1, ]),  ])}),\
({  "der Trolle",  ([    "quality_decay_factor": 110, "weight_factor": 120 ])}),\
({  "der Feen",  ([    "quality_decay_factor": 110, "value_factor": 120, ])}),\
({  "der Hobbits",  ([    "quality_decay_factor": 110, "weight_factor": 80 ])}),\
({  "der Oger",  ([    "quality_decay_factor": 110, "value_factor": 80, ])}),\
({  "der Feenkraft",  ([    "cursed": 1,    "attr_mod": ([   "str": -2, ]),  ])}),\
({  "der Babykraft",  ([    "cursed": 1,    "attr_mod": ([   "str": -3, ]),  ])}),\
({  "der Ungeschicklichkeit",  ([    "cursed": 1,    "attr_mod": ([   "dex": -2, ]),  ])}),\
({  "der linken Haende",  ([    "cursed": 1,    "attr_mod": ([   "dex": -3, ]),  ])}),\
({  "der Krankheit",  ([    "cursed": 1,    "attr_mod": ([   "con": -2, ]),  ])}),\
({  "der Todesnaehe",  ([    "cursed": 1,    "attr_mod": ([   "con": -3, ]),  ])}),\
({  "der Ogerklugheit",  ([    "cursed": 1,    "attr_mod": ([   "int": -2, ]),  ])}),\
({  "der Trollweisheit",  ([    "cursed": 1,    "attr_mod": ([   "int": -3, ]),  ])}),\
})

#define MED_SUFFIX_ARMOUR ({\
({  "des Loewen",  ([    "ac_factor": 120,  ])}),\
({  "des Roks",  ([    "ac_factor": 120,  ])}),\
({  "der Sinnlosigkeit",  ([    "cursed": 1,    "ac_factor": 0,  ])}),\
({  "der Aggression",  ([    "aggressive": 1,  ])}),\
({  "der Abwehr",  ([    "defend_func": 1,  ])}),\
({  "der Todessehnsucht",  ([    "defend_func": -2,    "cursed": 1,  ])}),\
({  "der Pein",  ([    "defend_func": -2,    "ac_factor": 50,  ])}),\
({  "der Macht",  ([    "ac_factor": 120,  ])}),\
({  "des Sieges",  ([    "defend_func": 1,  ])}),\
({  "des Leopards",  ([    "defend_func": 1,  ])}),\
({  "der Moewen",  ([    "defend_func": 1,    "ac_factor": 80,  ])}),\
({  "der Ritter",  ([    "defend_func": 1,    "ac_factor": 115, "paladin_spellcost": 3, ])}),\
({  "der Amazone",  ([    "defend_func": 1,    "ac_factor": 115, "amazonen_spellcost": 3, ])}),\
({  "des Kaempfers",  ([    "defend_func": 1,  ])}),\
({  "der Soeldner",  ([    "defend_func": 1,  ])}),\
({  "der Landwehr",  ([    "defend_func": 1,    "quality_decay_factor": 80,  ])}),\
({  "der Krieger",  ([    "defend_func": 1,    "quality_decay_factor": 110, "paladin_spellcost": 3, ])}),\
({  "des Krieges",  ([    "aggressive": 2,    "defend_func": 1,  ])}),\
({  "des Schildes",  ([    "defend_func": 1,    "ac_factor": 115,  ])}),\
({  "der eitrigen Wunden",  ([    "defend_func": -2,  ])}),\
({  "des Pumas",  ([    "ac_factor": 115,  ])}),\
({  "der Liebe",  ([    "defend_func": 1,    "ac_factor": 90, "amazonen_spellcost": 3, ])}),\
({  "der Bosheit",  ([    "ac_factor": 115, "nekro_spellcost": 3, ])}),\
({  "des Eisbaeren",  ([    "temperature_protection": ([   0: 3, ]), "material": "pelt", "itemd_elemental_value": (["eis":4]), ])}),\
({  "der Lava",  ([    "temperature_protection": ([   1: 3, ]), "material": "fire", "itemd_elemental_value": (["feuer":4]), ])}),\
({  "des Klimas",  ([    "temperature_protection": ([   0: 2,   1: 2, ]),  ])}),\
({  "der Gaensehaut",  ([    "temperature_protection": ([   0: -5,   1: 3, ]),  ])}),\
({  "(Funkenwerfer)",  ([    "charge_mod": ({"spark", 10, 125, 5}),  ])}),\
({  "des Gluecks",  ([   "itemd_prob_change":7  ])}),\
({  "des Lebenspunkts",  ([     "magic_health_modifier":(["hp":1,"sp":0]), ])}),\
({  "des Magiepunkts",  ([     "magic_health_modifier":(["hp":0,"sp":1]), ])}),\
({  "der Seuche",  ([     "magic_health_modifier":(["hp":-10,"sp":0]), ])}),\
({  "der Heiligkeit",  ([     "dam_prot":([ "holy": 1]),  "paladin_spellcost": 3,  ])}),\
({  "der Unheiligkeit",  ([   "dam_prot":([ "unholy":1]),   ])}),\
({  "des Unerwarteten",  ([    "defend_func": "random",    "quality_decay_factor": 20,  ])}),\
({  "der Kreativitaet", ([ "barden_spellcost": 3, "dam_prot": ([ "mind": 1 ])]) }), \
({  "des Waldschrats", ([ "ranger_spellcost": 3, "dam_prot": ([ "poison": 1 ])]) }), \
})
#define MED_SUFFIX_ARMOUR1 ({\
({  "des Hais",  ([    "defend_func": 1,    "ac_factor": 115,  ])}),\
({  "der Unbrauchbarkeit",  ([    "cursed": 1,    "ac_factor": 0,  ])}),\
({  "des Selbstmordes",  ([    "defend_func": -3,    "cursed": 1,  ])}),\
({  "des Zertretens",  ([    "berserker_bonus": (["zertreten":15]),  ])}),\
({  "des Kopfstosses",  ([    "berserker_bonus": (["kopfstoss":15]),  ])}),\
({  "des Kampfschreis",  ([    "berserker_bonus": (["kampfschrei":15]),  ])}),\
({  "der Willenskraft",  ([    "berserker_bonus": (["willenskraft":15]),  ])}),\
({  "der Regeneration",  ([    "berserker_bonus": (["regeneration":15]),  ])}),\
({  "des Spaltens",  ([    "berserker_bonus": (["spalten":15]),  ])}),\
({  "des Schlachtrufes",  ([    "berserker_bonus": (["schlachtruf":15]),  ])}),\
({  "des Gebetes",  ([    "paladin_spellcost": 5, ])}),\
({  "des Moenchs",  ([    "paladin_spellcost": 5, ])}),\
({  "des Elementaristen",  ([    "itemd_elemental_value": (["all":3]), "material": "leather" ])}),\
({  "der Temperatur",  ([    "temperature_protection": ([   0: 2,   1: 1, ]),  ])}),\
({  "des Sarnaks",  ([     "aggressive": 1, "ac_factor": 115,   ])}),\
({  "der Niederlage",  ([    "ac_factor": 50, "temperature_protection": ([   0: -2,   1: -2, ]), "cursed":1])}),\
({  "des Sturmes",  ([     "dam_prot": (["air":1]), "itemd_elemental_value": (["luft":5]), "material": "air"    ])}),\
({  "der Wellen",  ([     "dam_prot": (["water":1]), "itemd_elemental_value": (["wasser":5]), "material": "water"    ])}),\
({  "der Erde",  ([      "ac_factor": 115, "itemd_elemental_value": (["humus":5]), "material": "earth"    ])}),\
({  "des Zombies",  ([    "nekro_bonus": (["anrufung des kharr-zzteth":10]), "nekro_spellcost":3  ])}),\
({  "der Toten",  ([    "nekro_bonus": (["unterwerfung der toten":10]), "nekro_spellcost":3  ])}),\
({  "der Untoten",  ([    "nekro_bonus": (["unterwerfung der toten":10]), "nekro_spellcost":3  ])}),\
({  "des Vampirs",  ([    "nekro_bonus": (["biss des vampirs":10]), "nekro_spellcost":3  ])}),\
({  "des Vampirbisses",  ([    "nekro_bonus": (["biss des vampirs":10]), "nekro_spellcost":3  ])}),\
({  "des Fluches",  ([    "nekro_bonus": (["fluch der klinge":10]), "nekro_spellcost":3  ])}),\
({  "der Verwesung",  ([    "nekro_bonus": (["hauch der verwesung":10]), "nekro_spellcost":3  ])}),\
({  "des Schreckens",  ([    "nekro_bonus": (["schrecken der finsterniss":10]), "nekro_spellcost":3  ])}),\
({  "des Skelettes",  ([    "nekro_bonus": (["all":5]), "nekro_spellcost":3  ])}),\
({  "des Pilgers",  ([    "value_factor": 10, "paladin_spellcost":3,  ])}),\
({  "des Bettelmoenchs",  ([ "value_factor": 1,   "paladin_spellcost": 4, ])}),\
({  "der Elfenkraft",  ([    "cursed": 1,    "attr_mod": ([   "str": -1, ]),  ])}),\
({  "der Faulheit",  ([    "cursed": 1,    "attr_mod": ([   "dex": -1, ]),  ])}),\
({  "der Erschoepfung",  ([    "cursed": 1,    "attr_mod": ([   "con": -1, ]),  ])}),\
({  "des Schwachsinns",  ([    "cursed": 1,    "attr_mod": ([   "int": -1, ]),  ])}),\
({  "des Wahnsinns",  ([    "aggressive": 2,    "cursed": 1,  ])}),\
({  "des Bieres",  ([  "zechpreller_reduce_alc": 20])}),\
({  "des Weines",  ([  "zechpreller_bonus": (["all": 10])])}),\
({  "des Schnapses",  ([ "zechpreller_spellcost": 5])}),\
({  "der Eleganz",  ([    "value_factor": 130, "weight_factor": 90, "ac_factor": 115, ])}),\
({  "des Singens",  ([ "barden_spellcost": 5])}),\
({  "der Musik",  ([ "barden_bonus": (["all": 10])])}),\
({  "des Wildhueters",  ([ "ranger_spellcost": 5])}),\
({  "der Naturkundigen",  ([ "ranger_bonus": (["all": 10])])}),\
({  "der Furie",  ([ "amazonen_bonus": (["all": 10])])}),\
({  "der Anmutigen",  ([ "amazonen_spellcost": 5])}),\
})


#define HIGH_SUFFIX_ARMOUR ({\
({  "der Drachen",  ([    "ac_factor": 150,  "temperature_protection": ([   0: 1,   1: 1, ]) ])}),\
({  "des Schutzes",  ([    "defend_func": 2, "ac_factor": 130,  ])}),\
({  "des Mondes",  ([    "dam_prot": ([   "magic": 1, ]), "ac_factor": 130,  ])}),\
({  "des Blitzes",  ([    "dam_prot": ([   "lightning": 1, ]), "ac_factor": 130,  ])}),\
({  "des Donners",  ([    "dam_prot": ([   "sound": 1, ]), "ac_factor": 130,  ])}),\
({  "des Triumphes",  ([    "defend_func": 2,  ])}),\
({  "der Entgiftung",  ([    "defend_func": "poison", "ac_factor": 130,  ])}),\
({  "der Enttaubung",  ([    "defend_func": "deaf",  "ac_factor": 130, ])}),\
({  "der Entblindung",  ([    "defend_func": "blind", "ac_factor": 130,  ])}),\
({  "der Schwerelosigkeit",  ([    "weight_factor": 1,  ])}),\
({  "der Helligkeit",  ([    "light": 1, "paladin_spellcost": 5,  ])}),\
({  "der Dunkelheit",  ([    "light": -1, "nekro_bonus": (["strahlen der dunkelheit":30, "all":5]), "nekro_spellcost":5 ])}),\
({  "des Giftschutzes",  ([    "dam_prot": ([   "poison": 1, ]),    "defend_func": "poison",  ])}),\
({  "des Ohrenschutzes",  ([    "dam_prot": ([   "sound": 1, ]),    "defend_func": "deaf",  ])}),\
({  "des Augenschutzes",  ([    "dam_prot": ([   "light": 1, ]),    "defend_func": "blind",  ])}),\
({  "des Kaelteschutzes",  ([    "temperature_protection": ([   0: 4, ]), "ac_factor": 125,  ])}),\
({  "des Hitzeschutzes",  ([    "temperature_protection": ([   1: 4, ]),  "ac_factor": 125,])}),\
({  "der Gluthitze",  ([    "temperature_protection": ([   0: 5,   1: -3, ]),  "ac_factor": 125,])}),\
({  "der Eiseskaelte",  ([    "temperature_protection": ([   0: -3,   1: 5, ]), "ac_factor": 125, ])}),\
({  "des Wohlbefindens",  ([    "temperature_protection": ([   0: 3,   1: 3, ]), "ac_factor": 125, ])}),\
({  "(Funkenwerfer)",  ([    "charge_mod": ({"spark", 10, 500, 5}),  ])}),\
({  "des Feuerballs",  ([    "charge_mod": ({"fireball", 5, 800, 30}),  ])}),\
({  "des Giftpfeils",  ([    "charge_mod": ({"std_arrow_item", 10, 500, 15, "giftpfeil", "dt_poison"}),  ])}),\
({  "des Feuerpfeils",  ([    "charge_mod": ({"std_arrow_item", 10, 500, 15, "feuerpfeil", "dt_fire"}),  ])}),\
({  "des Zufalls",  ([    "defend_func": "random", "itemd_prob_change":15 ])}),\
({  "des Saeufers",  ([  "zechpreller_reduce_alc": 20, "zechpreller_bonus": (["all": 10])])}),\
({  "des Trinkers",  ([  "zechpreller_bonus": (["all": 10]), "zechpreller_spellcost": 5])}),\
({  "des Betrunkenen",  ([ "zechpreller_spellcost": 5, "zechpreller_reduce_alc": 20])}),\
({  "des Saengers",  ([ "barden_spellcost": 5, "barden_bonus": (["all": 10])])}),\
({  "der Stacheln",  ([    "weight_facor": 130,    "ac_factor": 125, "effective_wc": 80, "berserker_bonus": (["all":5])])}),\
({  "des Naturschuetzers",  ([ "ranger_spellcost": 5, "ranger_bonus": (["all": 10]) ])}),\
({  "der Speertaenzerin",  ([ "amazonen_spellcost": 5, "amazonen_bonus": (["all": 10]) ])}),\
})
#define HIGH_SUFFIX_ARMOUR1 ({\
({  "des Eispfeils",  ([    "charge_mod": ({"std_arrow_item", 10, 500, 15, "eispfeil", "dt_cold"}),  ])}),\
({  "des Saeurepfeils",  ([    "charge_mod": ({"std_arrow_item", 10, 500, 15, "saeurepfeil", "dt_acid"}),  ])}),\
({  "der Elemente",  ([    "itemd_elemental_value": (["all":5]), "material": "misc_magic" ])}),\
({  "der Lebenspunkte",  ([     "magic_health_modifier":(["hp":5,"sp":0]), ])}),\
({  "der Magiepunkte",  ([     "magic_health_modifier":(["hp":0,"sp":5]), "teleport_cost":1 ])}),\
({  "der Meditation",  ([     "magic_health_modifier":(["hp":-10,"sp":12]), ])}),\
({  "der Verschiebung",  ([     "magic_health_modifier":(["hp":12,"sp":-10]), ])}),\
({  "des Zorns",  ([    "aggressive": 1,    "ac_factor": 130,  ])}),\
({  "des Grauens",  ([    "dam_prot": ([ "terror": 1, ]),    "ac_factor": 125,  ])}),\
({  "des Alterns",  ([   "magic_health_modifier":(["hp":-20,"sp":15]), ])}),\
({  "der Sterne",  ([    "magic_health_modifier":(["hp":3,"sp":3]) ])}),\
({  "des Fruehlings",  ([    "dam_prot": (["sound":1]),    "value_factor": 150, "itemd_elemental_value": (["luft":7]), "material": "air", "ranger_spellcost": 10 ])}),\
({  "des Sommers",  ([    "dam_prot": (["air":1]),     "value_factor": 150, "itemd_elemental_value": (["feuer":7]), "material": "fire" ])}),\
({  "des Herbstes",  ([    "dam_prot": (["water":1]),    "value_factor": 150, "itemd_elemental_value": (["wasser":7]), "material": "water"  ])}),\
({  "des Winters",  ([    "dam_prot": (["cold":1]),   "value_factor": 150,  "itemd_elemental_value": (["eis":7]), "material": "ice"  ])}),\
({  "des Feuers",  ([   "dam_prot": (["fire":1]) ,   "itemd_elemental_value": (["feuer":7]), "material": "fire" ])}),\
({  "des Eises",  ([     "dam_prot": (["cold":1]),   "quality_decay_factor": 110,  "itemd_elemental_value": (["eis":7]), "material": "ice"   ])}),\
({  "der Saeure",  ([     "dam_prot": (["acid":1]),    "ac_factor": 130, ])}),\
({  "des Wassers",  ([     "dam_prot": (["water":1]),  "weight_factor":80, "itemd_elemental_value": (["wasser":7]), "material": "water"   ])}),\
({  "des Lichtes",  ([    "dam_prot": (["light":1]), "light": 1,  "paladin_spellcost": 5 ])}),\
({  "des Unheils",  ([     "dam_prot": (["unholy":1]), "nekro_spellcost": 5 ])}),\
({  "der Austreibung",  ([    "dam_prot": (["holy":1]),  "paladin_spellcost": 5   ])}),\
({  "der Furcht",  ([     "dam_prot": (["terror":1]),  "nekro_spellcost": 5  ])}),\
({  "des Giftes",  ([    "dam_prot": (["poison":1]),   "ac_factor": 125, "itemd_elemental_value": (["humus":7]), "material": "misc_poison"  ])}),\
({  "der Luft",  ([     "dam_prot": (["air":1]),  "weight_factor":50,  "itemd_elemental_value": (["luft":7]), "material": "air"    ])}),\
({  "der Psikraft",  ([    "dam_prot": (["mind":1]), "magic_health_modifier":(["sp":4])   ])}),\
({  "des Zaubers",  ([     "dam_prot": (["magic":1]), "magic_health_modifier":(["sp":3]) ,  "itemd_elemental_value": (["erz":7]), "material": "misc_magic"    ])}),\
({  "des Laerms",  ([     "dam_prot": (["sound":1]),  "berserker_bonus": (["kampfschrei":20, "all":5]), "barden_spellcost": 5  ])}),\
({  "der Explosion",  ([     "dam_prot": (["explosion":1]),   "ac_factor": 130,  ])}),\
({  "des Teleports",  ([   "teleport_cost":2,  "magic_health_modifier":(["sp":3]) ])}),\
({  "des Sehertors",  ([   "teleport_cost":2, "ac_factor": 125, ])}),\
({  "der Reise",  ([   "teleport_cost":2, "weight_factor": 75, ])}),\
({  "des Ghouls",  ([  "value_factor": 50,   "nekro_bonus": (["ruf_der_ghoule":20, "all":5]), "nekro_spellcost":5  ])}),\
({  "der Geister",  ([  "dam_prot": (["mind":1]), "nekro_spellcost":5  ])}),\
({  "der Mumie",  ([   "magic_health_modifier":(["hp":1,"sp":1]), "nekro_bonus": (["all":10]), "nekro_spellcost":5  ])}),\
({  "des Daemons",  ([    "ac_factor": 125,  "dam_prot": (["unholy":1]), "nekro_spellcost":5  ])}),\
({  "der Borke",  ([    "ac_factor": 125,  "dam_prot": (["buldgeon":3]), "ranger_spellcost":5  ])}),\
({  "der Valkyre",  ([    "ac_factor": 125,  "dam_prot": (["air":1]), "amazonen_spellcost":5  ])}),\
});

#define VHIGH_SUFFIX_ARMOUR ({\
({  "der Ogerkraft",  ([    "attr_mod": ([   "str": 2, ]), "ac_factor": 140,  ])}),\
({  "der Diebe",  ([    "attr_mod": ([   "dex": 2, ]), "ac_factor": 140,  ])}),\
({  "der Ausdauer",  ([    "attr_mod": ([   "con": 1, ]), "ac_factor": 140,  ])}),\
({  "der Intelligenz",  ([    "attr_mod": ([   "int": 1, ]), "ac_factor": 140,  ])}),\
({  "des Berserkertums",  ([    "berserker_bonus": (["all":10]),    "ac_factor": 140,  ])}),\
({  "der Raserei",  ([    "aggressive": 3,    "ac_factor": 130,  "berserker_bonus": (["blutrausch":20, "all":5]) ])}),\
({  "der Verteidigung",  ([    "defend_func": 3,  ])}),\
({  "der Absorption",  ([    "defend_func": 2,    "ac_factor": 140,  ])}),\
({  "der Zeitalter",  ([    "quality_decay_factor": 0,  ])}),\
({  "des Reichtums",  ([    "value_factor": 300, "ac_factor": 140,  ])}),\
({  "der Beweglichkeit",  ([    "defend_func": "paralyze",  ])}),\
({  "der Staerke",  ([    "attr_mod": ([   "str": 2, ]), "ac_factor": 140,  ])}),\
({  "der Flinkheit",  ([    "attr_mod": ([   "dex": 2, ]), "ac_factor": 140,  ])}),\
({  "der Konstitution",  ([    "attr_mod": ([   "con": 2, ]), "ac_factor": 140,  ])}),\
({  "der Erleuchtung",  ([    "attr_mod": ([   "int": 2, ]), "ac_factor": 140,  ])}),\
({  "des Golems",  ([    "attr_mod": ([   "int": -1,   "con": 3, ]), "ac_factor": 140,  ])}),\
({  "der Rafinesse",  ([    "attr_mod": ([   "str": -1,   "dex": 3, ]), "ac_factor": 140,  ])}),\
({  "des Berserkers",  ([    "attr_mod": ([   "str": 3,   "dex": -1, ]), "berserker_bonus": (["all":10]) ])}),\
({  "des Druiden",  ([    "attr_mod": ([   "int": 3,   "con": -1, ]), "itemd_elemental_value": (["all":5]), "material": "leather" ])}),\
({  "des Philosophs",  ([    "attr_mod": ([   "int": 4,   "str": -1,   "con": -1, ]), "ac_factor": 140,  ])}),\
({  "des Wueterichs",  ([    "attr_mod": ([   "int": -1,   "str": 4,   "dex": -1, ]), "ac_factor": 140,  ])}),\
({  "des Riesen",  ([    "attr_mod": ([   "int": -1,   "con": 4,   "dex": -1, ]), "ac_factor": 140,  ])}),\
({  "der Schnelligkeit",  ([    "attr_mod": ([   "int": -1,   "str": -1,   "dex": 4, ]), "ac_factor": 140,  ])}),\
({  "des Gegengiftes",  ([    "defend_func": "nopoison",  ])}),\
({  "der Sehkraft",  ([    "defend_func": "noblind",  ])}),\
({  "des Hoerens",  ([    "defend_func": "nodeaf",  ])}),\
({  "der Entfroschung",  ([    "defend_func": "nofrog",  ])}),\
({  "(Funkenwerfer)",  ([    "charge_mod": ({"spark", 10, 1000, 5}),  ])}),\
({  "des Todesvortex'",  ([    "charge_mod": ({"vortex", 10, 600, 20}),  ])}),\
({  "des grossen Feuerballs",  ([    "charge_mod": ({"fireball", 5, 1300, 30}),  ])}),\
({  "des gluecklichen Zufalls",  ([    "itemd_prob_change": 20,  ])}),\
({  "der Elementarmagie",  ([    "itemd_elemental_value": (["all":10]), "material": "misc_magic"  ])}),\
({  "der Dornen",  ([    "weight_facor": 140,    "ac_factor": 135, "effective_wc": 120, "berserker_bonus": (["all":5])])}),\
({  "des Mutes",  ([    "attr_mod": ([   "str": 1,  "con": 1]), "ac_factor": 140,  ])}),\
({  "der Schoenheit",  ([    "attr_mod": ([   "int": 1,  "dex": 1]), "ac_factor": 140,  ])}),\
({  "der Muskeln",  ([    "attr_mod": ([   "str": 1,  "dex": 1]), "ac_factor": 140,  ])}),\
({  "der Ueberlegenheit",  ([    "attr_mod": ([   "str": 1,  "int": 1]), "ac_factor": 140,  ])}),\
({  "der Weisheit",  ([    "attr_mod": ([   "con": 1,  "int": 1]), "ac_factor": 140,  ])}),\
({  "des Akrobaten",  ([    "attr_mod": ([   "dex": 1,  "con": 1]), "ac_factor": 140, "ranger_bonus": (["all": 5]) ])}),\
})
#define VHIGH_SUFFIX_ARMOUR1 ({\
({  "der Ruhe",  ([     "magic_health_modifier":(["hp":0,"sp":5]),"ac_factor": 140,  "ranger_bonus": (["melodie der ruhe": 25])])}),\
({  "der Unruhe",  ([     "magic_health_modifier":(["hp":0,"sp":-5]),"ac_factor": 140,  ])}),\
({  "des Gurus",  ([     "magic_health_modifier":(["hp":-5,"sp":11]),"ac_factor": 140,  ])}),\
({  "der Lebenskraft",  ([     "magic_health_modifier":(["hp":6,"sp":0]),"ac_factor": 140,  ])}),\
({  "der Magiekraft",  ([     "magic_health_modifier":(["hp":0,"sp":6]), "teleport_cost":1 ])}),\
({  "des Jaehzorns",  ([    "aggressive": 2,    "ac_factor": 150,  ])}),\
({  "der Magiespaehre",  ([   "magic_health_modifier":(["hp":-25,"sp":33]), "ac_factor": 140, ])}),\
({  "des Vulkans",  ([   "dam_prot": (["fire":2]) ,   "itemd_elemental_value": (["feuer":10]), "material": "fire" ])}),\
({  "des Schnees",  ([     "dam_prot": (["cold":2]),   "quality_decay_factor": 110,  "itemd_elemental_value": (["eis":10]), "material": "ice"   ])}),\
({  "der Sturmflut",  ([     "dam_prot": (["water":2]),  "weight_factor":80, "itemd_elemental_value": (["wasser":10]), "material": "wasser"   ])}),\
({  "des Humus",  ([    "dam_prot": (["poison":2]),   "ac_factor": 145, "itemd_elemental_value": (["humus":10]), "material": "earth"  ])}),\
({  "des Orkans",  ([     "dam_prot": (["air":2]),  "weight_factor":50,  "itemd_elemental_value": (["luft":10]), "material": "air"    ])}),\
({  "des Erzes",  ([     "dam_prot": (["magic":2]),  "quality_decay_factor":150,  "itemd_elemental_value": (["erz":10]), "material": "misc_magic"    ])}),\
({  "des Paladins",  ([    "paladin_spellcost": 5, "ac_factor":140, ])}),\
({  "des Heiligen",  ([    "paladin_spellcost": 10,  ])}),\
({  "des Kreuzritters",  ([    "paladin_spellcost": 7,  "ac_factor": 130, "dam_prot": (["holy":2]), ])}),\
({  "der Schatten",  ([    "light": -1,    "dam_prot": ([   "holy": 1, ]),  ])}),\
({  "der Sonne",  ([    "light": 1,    "dam_prot": ([   "light": 1, ]),  ])}),\
({  "des Tages",  ([    "light": 1, "ac_factor": 150 ])}),\
({  "der Nacht",  ([    "light": -1, "ac_factor": 150 ])}),\
({  "des Gletschers",  ([     "dam_prot": (["cold":1]),   "quality_decay_factor": 110,  "itemd_elemental_value": (["eis":10]),  "temperature_protection": ([   0: 4,   1: -1, ]), "material": "ice" ])}),\
({  "der Wueste",  ([     "dam_prot": (["fire":1]),   "quality_decay_factor": 110,  "itemd_elemental_value": (["feuer":10]),  "temperature_protection": ([   0: -1,   1: 4, ]),"material": "fire"  ])}),\
({  "des Dschungels",  ([     "dam_prot": (["poison":1]),   "quality_decay_factor": 110,  "itemd_elemental_value": (["humus":10]),  "temperature_protection": ([   0: 1,   1: 2, ]), "material": "earth"  ])}),\
({  "des Meeres",  ([     "dam_prot": (["water":1]),   "quality_decay_factor": 110,  "itemd_elemental_value": (["wasser":10]),  "temperature_protection": ([   0: 2,   1: 1, ]), "material": "water"  ])}),\
({  "der Wolken",  ([     "dam_prot": (["air":1]),   "quality_decay_factor": 110,  "itemd_elemental_value": (["luft":10]),  "weight_factor":10, "material": "air"  ])}),\
({  "des Gebirges",  ([     "dam_prot": (["magic":1]),   "quality_decay_factor": 110,  "itemd_elemental_value": (["erz":10]),  "ac_factor": 150 , "material": "misc_magic" ])}),\
({  "des Kampfes",  ([   "ac_factor": 150,  "defend_func": 1,  "paladin_spellcost": 8, "berserker_bonus": (["all":15]) ])}),\
({  "des heiligen Kampfes",  ([  "ac_factor": 140, "magic_health_modifier":(["hp":1,"sp":1]), "paladin_spellcost": 8, ])}),\
({  "der Koenigin", ([  "amazonen_spellcost": 10, "amazonen_bonus": (["all": 10]),])}),\
({  "des Nekromanten",  ([   "ac_factor": 145,  "nekro_bonus": (["all":15]), "nekro_spellcost":5  ])}),\
({  "der Daemonen",  ([    "ac_factor": 150,  "dam_prot": (["unholy":1]), "nekro_spellcost":8  ])}),\
({  "des Meistersaeufers",  ([  "zechpreller_spellcost": 10, "zechpreller_reduce_alc": 20, "zechpreller_bonus": (["all": 10])])}),\
({  "des Meisterbarden",  ([  "barden_spellcost": 10, "barden_bonus": (["all": 10])])}),\
({  "des Waldmeisters",  ([  "ranger_spellcost": 10, "ranger_bonus": (["all": 10])])}),\
})

#define GODLY_SUFFIX_ARMOUR ({\
({  "der Trollkraft",  ([    "attr_mod": ([   "str": 3, ]), "berserker_bonus": (["riesenkraft":20, "all":10]), "ac_factor":200 ])}),\
({  "der Riesenkraft",  ([    "attr_mod": ([   "str": 4, ]), "berserker_bonus": (["riesenkraft":25, "all":10]), "ac_factor":200 ])}),\
({  "der Titanenkraft",  ([    "attr_mod": ([   "str": 5, ]), "berserker_bonus": (["riesenkraft":30, "all":10]), "ac_factor":200 ])}),\
({  "des Meisterdiebes",  ([    "attr_mod": ([   "dex": 3, ]),  "ac_factor":200 ])}),\
({  "des Diebesgottes",  ([    "attr_mod": ([   "dex": 4, ]),  "ac_factor":200 ])}),\
({  "der ultimativen Geschicklichkeit",  ([    "attr_mod": ([   "dex": 5, ]), "ac_factor":200 ])}),\
({  "der Gesundheit",  ([    "attr_mod": ([   "con": 3, ]),   "ac_factor":200 ])}),\
({  "der Unbeugsamkeit",  ([    "attr_mod": ([   "con": 4, ]),  "ac_factor":200 ])}),\
({  "der ultimativen Ausdauer",  ([    "attr_mod": ([   "con": 5, ]), "ac_factor":200 ])}),\
({  "der Magie",  ([    "attr_mod": ([   "int": 3, ]), "teleport_cost":3, "ac_factor":200 ])}),\
({  "des Magiemeisters",  ([    "attr_mod": ([   "int": 4, ]), "teleport_cost":4, "ac_factor":200  ])}),\
({  "des absoluten Magiemeisters",  ([    "attr_mod": ([   "int": 5, ]), "teleport_cost":5, "ac_factor":200  ])}),\
({  "der Goetter",  ([    "attr_mod": ([   "int": 2,   "str": 2,   "con": 2,   "dex": 2, ]), "teleport_cost":3, "ac_factor":200 ])}),\
({  "des Gladiators",  ([    "attr_mod": ([   "str": 2,   "con": 2,   "dex": 1, ]),  "berserker_bonus": (["rammen":30, "all":10]), "ac_factor":200 ])}),\
({  "des Kriegers",  ([    "attr_mod": ([   "str": 3,   "con": 2, ]),  "ac_factor":200])}),\
({  "des Koenigs",  ([    "attr_mod": ([   "int": 3,   "str": 2,   "dex": 1, ]), "ac_factor":200 ])}),\
({  "des Einhorns",  ([    "attr_mod": ([   "int": 3,   "con": 2, ]), "ac_factor":200 ])}),\
({  "des Greifen",  ([    "attr_mod": ([   "int": 2,   "dex": 3, ]),  "ac_factor":200])}),\
({  "des Fuersten",  ([    "attr_mod": ([   "str": 2,   "con": 3, ]),   "paladin_spellcost": 10, "ac_factor":200 ])}),\
({  "des Herzogs",  ([    "attr_mod": ([   "int": 2,   "str": 3, ]),   "paladin_spellcost": 15, "ac_factor":200 ])}),\
({  "des Haeuptlings",  ([    "attr_mod": ([   "int": 1,   "str": 3,   "con": 2, ]),  "berserker_bonus": (["schlachtruf":30, "all":10]), "ac_factor":200 ])}),\
({  "der Koenigin",  ([    "attr_mod": ([   "int": 3,   "con": 1,   "dex": 1, ]),  "ac_factor":200])}),\
({  "des gigantischen Feuerballs",  ([    "charge_mod": ({"fireball", 5, 2500, 30}), ])}),\
({  "der Magiequelle",  ([    "itemd_prob_change": 30, "magic_health_modifier":(["hp":0,"sp":22]), "itemd_elemental_value":(["all":10]), "ac_factor":200, "material": "misc_magic"])}),\
({  "der Unsterblichkeit",  ([   "magic_health_modifier":(["hp":100,"sp":-60]), "ac_factor":200])}),\
({  "des Astralleibs",  ([   "magic_health_modifier":(["hp":-60,"sp":100]), "ac_factor":200])}),\
({  "des Lebens",  ([    "magic_health_modifier":(["hp":60,"sp":-20]), "ac_factor":200])}),\
({  "der Astralkraft",  ([    "magic_health_modifier":(["hp":-20,"sp":60]), "ac_factor":200])}),\
})
#define GODLY_SUFFIX_ARMOUR1 ({\
({  "der Bewegungsfreiheit",  ([    "defend_func": "noparalyze", "ac_factor":200 ])}),\
({  "der grosse Funkenwerfer",  ([    "charge_mod": ({"spark", 5, 2000, 5}),  ])}),\
({  "des Todesvortex'",  ([    "charge_mod": ({"vortex", 10, 1200, 20}),  ])}),\
({  "der Unverwundbarkeit",  ([  "defend_func": "3", "ac_factor":300, "magic_health_modifier":(["hp":7]),    ])}),\
({  "der Uebergilde",  ([  "barden_bonus": (["all": 30]), "barden_spellcost": 10, "berserker_bonus": (["all":30]), "itemd_elemental_value": (["all":20]), "paladin_spellcost": 20, "nekro_spellcost": 20, "nekro_bonus": (["all":30]),  "zechpreller_reduce_alc": 30, "zechpreller_bonus": (["all": 30]), "zechpreller_spellcost": 10, "ac_factor":200, "material": "misc_magic" ])}),\
({  "der Strahlung",  ([    "light": 2,  "ac_factor":200,  ])}),\
({  "der Finsternis",  ([    "light": -2,  "ac_factor":200, "nekro_bonus": (["schrecken der finsterniss":30, "all":10]), "nekro_spellcost":10 ])}),\
({  "des Meisternaehers",  ([    "skill_mod": (["sk_sewing":2500]),  ])}),\
({  "des Meistergerbers",  ([    "skill_mod": (["sk_tanning":2500]),  ])}),\
({  "des Meisterstollenbauers",  ([    "skill_mod": (["sk_digging":2500]),  ])}),\
({  "des Meisterbergmanns",  ([    "skill_mod": (["sk_prospect":2500]),  ])}),\
({  "des Meisterjuweliers",  ([    "skill_mod": (["sk_jewelry":2500]),  ])}),\
({  "des Meisterschmelzers",  ([    "skill_mod": (["sk_metallurgy":2500]),  ])}),\
({  "des Meisterwaffenschmieds",  ([    "skill_mod": (["sk_weaponsmithing":2500]),  ])}),\
({  "des Meisterruestungsschmieds",  ([    "skill_mod": (["sk_armoursmithing":2500]),  ])}),\
({  "des Meisterkochs",  ([    "skill_mod": (["sk_baking":2500]),  ])}),\
({  "des Meisterbrauers",  ([    "skill_mod": (["sk_brewing":2500]),  ])}),\
({  "des Meisters",  ([    "quality_decay_factor": 200,  "value_factor": 200,    "ac_factor": 175,  "defend_func": 1,  "magic_health_modifier":(["hp":5, "sp":5]), "temperature_protection": ([   0: 2,   1: 2, ]), "dam_prot": (["magic":2]) ])}),\
({  "der ewigen Teleportation",  ([   "teleport_cost":10, "ac_factor":200  ])}),\
({  "der Nekromantie",  ([    "nekro_bonus": (["all":30]), "nekro_spellcost":15, "magic_health_modifier":(["sp":10]), "ac_factor":200 ])}),\
({  "des Elementarschutzes",  ([    "itemd_elemental_value": (["all":15]), "dam_prot": (["fire":1, "cold":1, "air":1, "water":1, "magic":1, "poison":1]), "ac_factor":200, "material": "misc_magic"])}),\
({  "der goettlichen Inspiration",  ([    "barden_bonus": (["all":30]), "barden_spellcost":15, "magic_health_modifier":(["sp":10]), "ac_factor":200 ])}),\
({  "der ungezaehmten Wildnis",  ([    "ranger_bonus": (["all":30]), "ranger_spellcost":15, "magic_health_modifier":(["hp":10]), "ac_factor":200 ])}),\
({  "der Amazonenmutter",  ([ "amazonen_bonus": (["all":30]), "amazonen_spellcost":15, "magic_health_modifier":(["hp":10]), "ac_factor":200 ])}),\
})
