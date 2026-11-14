// itemd_socketed_data.h
// (c) angrox@sl.mud.at, feyaria@sl.mud.at
//     nur zu Verwendung im Silberland bestimmt.

// Die Weitergabe dieser Informationen an Spieler und an
// Magier anderer MUDs ist lt. Magiervertrag VERBOTEN!!

#define OLD_GEMS ({"diamant", "rubin", "aquamarin", "amethyst",\
      "bergkristall", "bernstein", "diamant", "granat", "onyx",\
      "opal","saphir", "smaragd",\
      "topas", "turmalin", "zirkon", "lapislazuli"})

// gem: ({ weapon_array, armour_array})
#define GGEMS ([\
    "diamant"    :({\
        ({"",(["damage_type_add": "explosion","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["explosion":2]),"ac_factor": 110,])}),\
        }),\
    "rubin"    :({\
        ({"",(["damage_type_add": "fire","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["fire":2]),"ac_factor": 110,])}),\
        }),\
    "aquamarin"  :({\
        ({"",(["damage_type_add": "water","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["water":2]),"ac_factor": 110,])}),\
        }),\
    "topas"      :({\
        ({"",(["damage_type_add": "air","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["air":2]),"ac_factor": 110,])}),\
        }),\
    "smaragd"    :({\
        ({"",(["damage_type_add": "poison","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["poison":2]),"ac_factor": 110,])}),\
        }),\
    "saphir"     :({\
        ({"",(["damage_type_add": "cold","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["cold":2]),"ac_factor": 110,])}),\
        }),\
    "opal"       :({\
        ({"",(["damage_type_add": "magic","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["magic":2]),"ac_factor": 110,])}),\
        }),\
    "lapislazuli":({\
        ({"",(["damage_type_add": "acid","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["acid":2]),"ac_factor": 110,])}),\
        }),\
    "onyx"       :({\
        ({"",(["damage_type_add": "terror","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["terror":2]),"ac_factor": 110,])}),\
        }),\
    "bernstein"  :({\
        ({"",(["damage_type_add": "light","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["light":2]),"ac_factor": 110,])}),\
        }),\
    "granat"     :({\
        ({"",(["damage_type_add": "lightning","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["lightning":2]),"ac_factor": 110,])}),\
        }),\
    "zirkon"     :({\
        ({"",(["damage_type_add": "electric","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["electric":2]),"ac_factor": 110,])}),\
        }),\
    "turmalin"   :({\
        ({"",(["damage_type_add": "unholy","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["unholy":2]),"ac_factor": 110,])}),\
        }),\
    "amethyst"   :({\
        ({"",(["damage_type_add": "sound","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["sound":2]),"ac_factor": 110,])}),\
        }),\
    "tigerauge"   :({\
        ({"",(["damage_type_add": "mind","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["mind":2]),"ac_factor": 110,])}),\
        }),\
    "bergkristall"   :({\
        ({"",(["damage_type_add": "holy","wc_factor": 110,])}),\
        ({"",(["dam_prot": (["holy":2]),"ac_factor": 110,])}),\
        }),\
    "oktarin":({\
        ({"",(["wc_fix_offset": 10, "itemd_prob_change":10,])}),\
        ({"",(["ac_factor": 110,"itemd_prob_change":10,])}),\
        }),\
    "default":({\
        ({"",(["wc_fix_offset": 5, "wc_factor": 105,"quality_decay_factor": 150])}),\
        ({"",(["ac_factor": 110,"quality_decay_factor": 150,])}),\
        }),\
    ])



//

#define RUNES1 ([\
    "Dom": ({\
      ({"",(["magic_health_modifier": (["hp": 7])])}),\
      ({"",(["defend_func": "heal",])}),\
      ({"gibt sie mehr Lebenspunkte","verwandelt sie Schaden in Heilung" }),\
      }),\
    "Ael": ({\
      ({"",(["hit_func": "1"])}),\
      ({"",(["defend_func": "1","light": 1])}),\
      ({"macht sie mehr Schaden","verteidigt sie besser und leuchtet" }),\
      }),\
    "Ezs": ({\
      ({"",(["dam_type": "sound", "hit_func": "1"])}),\
      ({"",(["defend_func": "nodeaf1","dam_prot": (["sound": 2])])}),\
      ({"ist besonders laut","schuetzt vor Laerm" }),\
    }),\
    "Gul": ({\
      ({"",(["hit_func": "spider", "wc_factor": 110,])}),\
      ({"",(["dam_prot": (["poison": 2]), "defend_func": "poison"])}),\
      ({"macht sie mehr Schaden gegen Spinnen", "schuetzt gegen Giftschaden"}),\
        }),\
    "Inc": ({\
      ({"",(["itemd_prob_change": 15,])}),\
      ({"",(["itemd_prob_change": 15,])}),\
      ({"laesst sie Dich mehr magische Gegenstaende finden", "laesst sie Dich mehr magische Gegenstaende finden"}),\
        }),\
    "Lea": ({\
      ({"",(["hit_func": "money",])}),\
      ({"",(["defend_func": "money",])}),\
      ({"vermehrt sie im Kampf Deinen Reichtum", "vermehrt sie im Kampf Deinen Reichtum"}),\
        }),\
    "Los": ({\
      ({"",(["magic_health_modifier": (["sp": 7]),])}),\
      ({"",(["defend_func": "manaheal",])}),\
      ({"erhoeht sie Deine magische Kraft", "verwandelt Schaden in magische Kraft"}),\
        }),\
    "Mon": ({\
      ({"",(["magic_health_modifier": (["hp": 4, "sp": 4]),])}),\
      ({"",(["magic_health_modifier": (["hp": 4, "sp": 4]),])}),\
      ({"erhoeht sie Deine Lebenskraft und Deine Magie", "erhoeht sie Deine Lebenskraft und Deine Magie"}),\
        }),\
    "Nec": ({\
      ({"",(["hit_func": "elf", "light": -1])}),\
      ({"",(["defend_func": "1", "light": 1])}),\
      ({"macht sie mehr Schaden auf Elfen und verdunkelt die Umgebung", "schuetzt sie besser und erhellt die Umgebung"}),\
        }),\
    "Quod": ({\
      ({"",(["quality_decay_factor": 350])}),\
      ({"",(["quality_decay_factor": 350])}),\
      ({"erhoeht sie die Haltbarkeit der Waffe", "erhoeht sie die Haltbarkeit der Ruestung"}),\
        }),\
    "Xen": ({\
      ({"",(["hit_func": "human", "quality_decay_factor": 150])}),\
      ({"",(["defend_func": "1", "quality_decay_factor": 150])}),\
      ({"macht sie mehr Schaden auf Menschen und verringert die Abnuetzung", "schuetzt sie besser und verringert die Abnuetzung"}),\
        }),\
    ])

#define RUNES2 ([\
    "Cham": ({\
      ({"",(["hit_func": "hobbit", "damage_type_add": "acid", "wc_factor": 120])}),\
      ({"",(["dam_prot": (["acid": 2]),"ac_factor": 120])}),\
      ({"verursacht sie Saeureschaden und macht mehr Schaden gegen Hobbits", "schuetzt sie vor Saeureschaden und generell besser"}),\
      }),\
    "Eon": ({\
      ({"",(["hit_func": "undead1", "wc_factor": 120])}),\
      ({"",(["defend_func": "1", "ac_factor": 120])}),\
      ({"macht sie viel mehr Schaden gegen Untote", "verteidigt sie viel besser"}),\
     }),\
    "Ex": ({\
      ({"",(["itemd_prob_change": 20,])}),\
      ({"",(["itemd_prob_change": 20,])}),\
      ({"laesst sie Dich mehr magische Gegenstaende finden", "laesst sie Dich mehr magische Gegenstaende finden"}),\
        }),\
    "Hym": ({\
      ({"",(["hit_func": "ogre", "damage_type_add": "air","wc_factor": 120])}),\
      ({"",(["dam_prot": (["air": 2]),"ac_factor": 120])}),\
      ({"verursacht sie Luftschaden und macht mehr Schaden gegen Oger", "schuetzt sie vor Luftschaden und generell besser"}),\
        }),\
    "Ir": ({\
      ({"",(["magic_health_modifier": (["hp": 10]),])}),\
      ({"",(["magic_health_modifier": (["hp": 10]),])}),\
      ({"erhoeht sie Deine Lebenskraft", "erhoeht sie Deine Lebenskraft"}),\
        }),\
    "Ker": ({\
      ({"",(["hit_func": "blutrausch",])}),\
      ({"",(["dam_prot": (["fire": 2]), "ac_factor": 130])}),\
      ({"versetzt sie Dich in Blutrausch", "schuetzt sie vor Feuer" }),\
        }),\
    "Orc": ({\
      ({"",(["hit_func": "orc", "damage_type_add": "lightning","wc_factor": 120])}),\
      ({"",(["dam_prot": (["lightning": 2]), "ac_factor": 120])}),\
      ({"verursacht sie Blitzschaden und macht mehr Schaden gegen Orks", "schuetzt gegen Blitzschaden und schuetzt generell besser"}),\
        }),\
    "Ven": ({\
      ({"",(["hit_func": "fairy", "damage_type_add": "poison","wc_factor": 120])}),\
      ({"",(["dam_prot": (["poison": 2]),"ac_factor": 120])}),\
      ({"verursacht sie Giftschaden und macht mehr Schaden gegen Feen", "schuetzt sie vor Giftschaden und generell besser"}),\
        }),\
    "Um": ({\
      ({"",(["hit_func": "random", "wc_factor": 120])}),\
      ({"",(["defend_func": "1", "ac_factor": 120])}),\
      ({"macht sie zufaelligen Schaden", "schuetzt sie besser"}),\
        }),\
    "Wig": ({\
      ({"",(["hit_func": "dwarf", "damage_type_add": "water","wc_factor": 120])}),\
      ({"",(["dam_prot": (["water": 2]),"ac_factor": 120])}),\
      ({"verursacht sie Wasserschaden und macht mehr Schaden gegen Zwerge", "schuetzt sie vor Wasserschaden und generell besser"}),\
        }),\
    "Ad": ({\
      ({"",(["hit_func": "undead", "wc_factor": 120])}),\
      ({"",(["defend_func": "1", "ac_factor": 120])}),\
      ({"macht sie mehr Schaden gegen Untote", "schuetzt sie besser"}),\
        }),\
    ])

#define RUNES3 ([\
    "Ber": ({\
      ({"",(["hit_func": "verwuestung1", "wc_factor": 130])}),\
      ({"",(["defend_func": "2", "ac_factor": 130])}),\
      ({"vervielfacht sie den Schaden", "schuetzt sie besser" }),\
      }),\
    "Bal": ({\
      ({"",(["hit_func": "demon1", "wc_factor": 130])}),\
      ({"",(["defend_func": "1", "ac_factor": 130])}),\
      ({"macht sie mehr Schaden gegen Daemonen", "verteidigt sie viel besser"}),\
     }),\
    "Hed": ({\
      ({"",(["quality_decay_factor": 700, "hit_func": "2" ])}),\
      ({"",(["quality_decay_factor": 700, "defend_func": "2" ])}),\
      ({"macht sie viel mehr Schaden und nutzt sich viel langsamer ab", "verteidigt sie viel mehr und nutzt sich viel langsamer ab"}),\
        }),\
    "Bro": ({\
      ({"",(["hit_func": "giant1",])}),\
      ({"",(["defend_func": "manaheal1",])}),\
      ({"macht sie mehr Schaden gegen Riesen", "verwandelt Schaden in magische Energie"}),\
        }),\
    "Red": ({\
      ({"",(["hit_func": "speed1",])}),\
      ({"",(["dam_prot": (["lightning": 2]),])}),\
      ({"laesst sie Dich schneller kaempfen", "schuetzt sie gegen Blitzschaden"}),\
        }),\
    "Nal": ({\
      ({"",(["hit_func": "maertyrer1", "wc_factor": 130])}),\
      ({"",(["defend_func": "1", "ac_factor": 130])}),\
      ({"verstaerkt sie den Schaden durch Dein Blut", "schuetzt sie viel besser"}),\
        }),\
    "Rog": ({\
      ({"",(["damage_type_add": "fire", "hit_func": "troll1", "wc_factor": 130])}),\
      ({"",(["dam_prot": (["fire": 2]),"ac_factor": 130,  "temperature_protection": ([1: 2, ]), ])}),\
      ({"macht sie Feuerschaden und macht mehr Schaden gegen Trolle", "schuetzt sie gegen Feuerschaden und vor Hitze"}),\
        }),\
    "Ser": ({\
      ({"",(["wc_fix_offset": 30,])}),\
      ({"",([ "defend_func": "paralyse"])}),\
      ({"macht sie die Waffe leichter fuehrbar", "schuetzt sie Dich vor Versteinerung"}),\
        }),\
    "Sar": ({\
      ({"",(["hit_func": "blood"])}),\
      ({"",(["defend_func": "heal", "ac_factor": 130])}),\
      ({"saugt sie vom Gegner Lebensenergie ab", "verwandelt sie Schaden in Lebensenergie und schuetzt besser"}),\
        }),\
    "Vex": ({\
      ({"",(["hit_func": "vampire",])}),\
      ({"",(["defend_func": "manaheal1",])}),\
      ({"saugt sie magische Energie", "verwandelt sie Schaden in magische Energie"}),\
        }),\
    "Nek": ({\
      ({"",(["nekro_spellcost":10])}),\
      ({"",(["nekro_bonus": (["all":5])])}),\
      ({"verringert die Spruchkosten eines Nekromanten", "verbessert die Fertigkeiten eines Nekromanten"}),\
        }),\
    "Pal": ({\
      ({"",(["paladin_spellcost": 10,"wc_factor": 110])}),\
      ({"",(["paladin_spellcost": 10])}),\
      ({"verringert die Spruchkosten eines Paladins", "verringert die Spruchkosten eines Paladins"}),\
        }),\
    ])

#define RUNES4 ([\
    "An": ({\
      ({"",(["hit_func": "blood1",])}),\
      ({"",(["defend_func": "stacheln1",])}),\
      ({"saugt sie Lebenspunkte der Gegner ab","verletzt es die Gegner"}),\
      }),\
    "Zen": ({\
      ({"",(["hit_func": "3",])}),\
      ({"",(["magic_health_modifier": (["sp": 19]),])}),\
      ({"macht sie viel mehr Schaden", "verstaerkt sie Deine magische Kraft"}),\
      }),\
    "Jux": ({\
      ({"",(["attr_mod": (["str": 3]),])}),\
      ({"",(["attr_mod": (["str": 3]),])}),\
      ({"erhoeht sie Deine Kraft", "erhoeht sie Deine Kraft"}),\
        }),\
    "Ful": ({\
      ({"",(["attr_mod": (["int": 3]),])}),\
      ({"",(["attr_mod": (["int": 3]),])}),\
      ({"erhoeht sie Deine Intelligenz", "erhoeht sie Deine Intelligenz"}),\
        }),\
    "Myth": ({\
      ({"",(["magic_health_modifier": (["hp": 9, "sp": 9]),])}),\
      ({"",(["magic_health_modifier": (["hp": 9, "sp": 9]),])}),\
      ({"erhoeht sie Deine Lebenskraft und Deine Magie", "erhoeht sie Deine Lebenskraft und Deine Magie"}),\
        }),\
    "Kath": ({\
      ({"",(["attr_mod": (["dex": 3]),])}),\
      ({"",(["attr_mod": (["dex": 3]),])}),\
      ({"erhoeht sie Dein Geschick ", "erhoeht sie Dein Geschick"}),\
        }),\
    "Ohm": ({\
      ({"",(["hit_func": "2","weight_factor": 1])}),\
      ({"",(["dam_prot": (["magic": 3]), "ac_factor": 140])}),\
      ({"macht sie viel mehr Schaden und laesst die Waffe fast nichts mehr wiegen", "schuetzt sie gegen magischen Schaden und schuetzt generell besser"}),\
        }),\
    "Por": ({\
      ({"",(["hit_func": "speed2","wc_factor": 140])}),\
      ({"",(["defend_func": "heal1", "ac_factor": 140])}),\
      ({"laesst sie Dich schneller kaempfen und macht mehr Schaden", "verwandelt sie im Kampf Schaden zu magischer Energie und schuetzt besser"}),\
        }),\
    "Tir": ({\
      ({"",(["hit_func": "vampire1",])}),\
      ({"",(["defend_func": "manaheal2",])}),\
      ({"saugt sie sehr viel magische Energie", "verwandelt sie Schaden in sehr viel magische Energie"}),\
        }),\
    "Zak": ({\
      ({"",(["attr_mod": (["con": 3]),])}),\
      ({"",(["attr_mod": (["con": 3]),])}),\
      ({"erhoeht sie Deine Ausdauer", "erhoeht sie Deine Ausdauer"}),\
        }),\
    "In": ({\
      ({"",(["hit_func": "undead2","weight_factor": 1, "paladin_bonus":5])}),\
      ({"",(["dam_prot": (["unholy": 3]), "ac_factor": 140, "paladin_bonus":5])}),\
      ({"macht sie mehr Schaden gegen Untote, verbessert alle Fertigkeiten eines Paladins und laesst die Waffe fast nichts mehr wiegen", "schuetzt sie gegen unheiligen Schaden, verbessert alle Fertigkeiten eines Paladins und schuetzt generell besser"}),\
        }),\
    ])

#define RUNES5 ([\
    "Gor": ({\
      ({"",(["hit_func": "verwuestung2", "wc_factor": 150])}),\
      ({"",(["magic_health_modifier": (["hp": 50]), "ac_factor": 150])}),\
      ({"macht sie extrem viel Schaden", "erhoeht Deine Lebenskraft und schuetzt besser"}),\
        }),\
    "Arc": ({\
      ({"",(["hit_func": "dragon2", "wc_factor": 150])}),\
      ({"",(["defend_func": 3, "ac_factor": 150])}),\
      ({"macht sie gegen Drachen extrem viel Schaden", "schuetzt sie extrem besser"}),\
        }),\
    "Tar": ({\
      ({"",(["damage_type_add": "cold", "hit_func": "paralyze2", "wc_factor": 150])}),\
      ({"",(["defend_func": "noparalyze2", "dam_prot": (["cold": 4]),"ac_factor": 150,  "temperature_protection": ([0: 5,]), ])}),\
      ({"verursacht sie Kaelteschaden und paralysiert den Gegner", "schuetzt sie vor Kaelteschaden und Paralyse, waermt Dich und schuetzt besser"}),\
        }),\
    "Ylem": ({\
      ({"",(["hit_func": "money2","itemd_prob_change": 35,])}),\
      ({"",(["defend_func": "money2","itemd_prob_change": 35,])}),\
      ({"vermehrt sie im Kampf Deinen Reichtum und laesst sie Dich mehr magische Gegenstaende finden", "vermehrt sie im Kampf Deinen Reichtum und laesst sie Dich mehr magische Gegenstaende finden"}),\
        }),\
    "Zod": ({\
      ({"",(["autoload": 365, "quality_decay_factor": 0])}),\
      ({"",(["autoload": 365, "quality_decay_factor": 0])}),\
      ({"bindet sie eine Waffe fuer ein Jahr fix an Dich", "bindet sie eine Ruestung fuer ein Jahr fix an Dich"}),\
        }),\
    ])


#define RUNE_MIGHT ([\
    1:({"Dom", "Ael", "Gul", "Inc", "Lea", "Los", "Mon", "Nec", "Quod", "Xen", "Ezs"}),\
    2:({"Cham","Eon", "Ex", "Hym", "Ir", "Ker", "Orc", "Ven", "Wig", "Ad"}),\
    3:({"An","Bal", "Bro", "Hed", "Nal", "Red", "Rog", "Ser", "Vex","Um",\
      "Nek", "Pal"}),\
    4:({"Ber", "Zen", "Jux", "Ful", "Myth", "Kath", "Ohm", "Por", "Tir", \
      "Zak","Sar", "In"}),\
    5:({"Arc", "Gor", "Tar", "Ylem", "Zod"}),\
    ])

#define REVERSE_RUNE_MIGHT ([\
    "Dom":1, "Ael":1, "Ezs": 1, "Gul":1, "Inc":1, "Lea":1, "Los":1, "Mon":1, "Nec":1,\
    "Quod":1, "Xen":1,\
    "Cham":2, "Eon":2, "Ex":2, "Hym":2, "Ir":2, "Ker":2, "Orc":2, "Ven":2,\
    "Wig":2,"Ad":2,\
    "An":3, "Bal":3, "Bro":3, "Hed":3, "Nal":3, "Red":3, "Rog":3, "Ser":3,\
    "Vex":3, "Um":3, "Nek":3, "Pal":3,\
    "Ber":4, "Zen":4, "Jux":4, "Ful":4, "Myth":4, "Kath":4, "Ohm":4, "Por":4,\
    "Tir":4,"Zak":4,"Sar":4,"In":4,\
    "Arc":5, "Gor":5, "Tar":5, "Ylem":5, "Zod":5,\
    ])


//  Cham_Ael_Eon 2 1 2
//  Gul_Orc_Um 1 2 3
//  Ber_Ser_Ker 4 3 2
//  Pal_Ad_In 3 2 4
//  Ful_Myth_Zak 4 4 4
//  Mon_Sar_Vex 1 4 3
//  Bal_Rog_Lea 3 3 1
//  Nec_Ohm_An 1 4 3
//  Kath_Bro_Xen_ 4 3 1
//  Los_Por_Quod_Red 1 4 1 3
//  Dom_Wig_Nal_Jux 1 2 3 4
//  Inc_Ir_Hed_Tir 1 2 3 4
//  Ex_Hym_Ven_Zen 2 2 2 4
//  OrcEzsTar 2 1 5
#define RUNEWORDTALISMAN ({\
 "ChamAelEon", "GulOrcUm", "BerSerKer", "FulMythZak", "MonSarVex", "BalRogLea", "NecOhmAn",\
 "KathBroXen", "LosPorQuodRed", "DomWigNalJux", "IncIrHedTir", "ExHymVenZen", "ArcGorTarYlemZod",\
    "PalAdIn", "OrcEzsTar"})



#define RUNE_WORDS ([\
"Cham_Ael_Eon_":({\
  ({ "",(["hit_func": ({"random2"}),\
     "magic_health_modifier": (["hp": 3, "sp": 3]),\
     "wc_factor": 140,\
     "wc_fix_offset": 35,\
     "light": 1,\
     "quality_decay_factor": 400,\
     "value_factor": 10000,\
     "autoload": 100,])\
  }),\
  ({"",([ "defend_func": ({"random2"}),\
     "magic_health_modifier": (["hp": 3, "sp": 3]),\
     "ac_factor": 200,\
     "light": 1,\
     "quality_decay_factor": 400,\
     "value_factor": 10000,\
     "temperature_protection": ([0: 1, 1: 1]),\
     "autoload": 100,]) \
   }), ({"", ""}),\
}),\
"Gul_Orc_Um_":({\
  ({ "", (["hit_func":({"spider1", "orc1", "bird1", "fish1", "frog1", "insect1"}),\
     "magic_health_modifier": (["hp": 4, "sp": 4]),\
     "wc_factor": 150,\
     "wc_fix_offset": 20,\
     "quality_decay_factor": 500,\
     "value_factor": 10000,\
     "autoload":100,])\
   }),\
  ({"",([ "defend_func": ({"nopoison1", "nofrog1", "2"}),\
     "magic_health_modifier": (["hp": 4, "sp": 4]),\
     "ac_factor": 200,\
     "quality_decay_factor": 500,\
     "dam_prot": (["acid": 3, "poison": 3, "lightning": 3]),\
     "value_factor": 10000,\
     "autoload": 100,]) \
   }), ({"", ""}),\
}),\
"Ber_Ser_Ker_":({\
   ({"", (["hit_func": ({"verwuestung1", "blutrausch1"}),\
     "magic_health_modifier": (["hp": 9, "sp": 3]),\
     "wc_factor": 160,\
     "wc_fix_offset": 10,\
     "quality_decay_factor": 500,\
     "berserker_bonus": (["all": 20]),\
     "value_factor": 10000,\
     "autoload": 100,])\
   }),\
   ({"",([  "defend_func": ({"paralyze1", "deaf1", "blind1"}),\
     "magic_health_modifier": (["hp": 9, "sp": 3]),\
     "ac_factor": 200,\
     "quality_decay_factor": 500,\
     "dam_prot": (["fire": 3]),\
     "berserker_bonus": (["all": 20]),\
     "effective_wc": 150,\
     "value_factor": 10000,\
     "autoload": 100,])\
   }), ({"", ""}),\
}),\
"Ful_Myth_Zak_": ({\
   ({"", ([ "magic_health_modifier": (["hp": 33, "sp": 33]),\
     "wc_factor": 150,\
     "wc_fix_offset": 15,\
     "quality_decay_factor": 500,\
     "value_factor": 10000,\
     "autoload": 100, ])\
   }),\
   ({"", (["magic_health_modifier": (["hp": 33, "sp": 33]),\
     "ac_factor": 130,\
     "quality_decay_factor": 500,\
     "value_factor": 10000,\
     "autoload": 100, ])\
   }), ({"", ""}),\
}),\
"Mon_Sar_Vex_": ({\
   ({"", ([ "hit_func": ({"blood1", "vampire1"}),\
     "magic_health_modifier": (["hp": 9, "sp": 9]),\
     "wc_factor": 150,\
     "wc_fix_offset": 15,\
     "quality_decay_factor": 500,\
     "amazonen_spellcost": 12,\
     "amazonen_bonus": (["all": 25]),\
     "value_factor": 10000,\
     "autoload": 100,])\
   }),\
   ({"", ([ "defend_func": ({"heal1", "manaheal1"}),\
     "magic_health_modifier": (["hp": 9, "sp": 9]),\
     "ac_factor": 200,\
     "quality_decay_factor": 500,\
     "amazonen_spellcost": 12,\
     "amazonen_bonus": (["all": 25]),\
     "value_factor": 10000,\
     "autoload": 100,]),\
   }), ({"", ""}),\
}),\
"Bal_Rog_Lea_": ({\
   ({"", ([ "hit_func": ({"demon1", "blood1", "money1"}),\
     "magic_health_modifier": (["hp": 5, "sp": 5]),\
     "wc_factor": 140,\
     "wc_fix_offset": 25,\
     "quality_decay_factor": 300,\
     "damage_type_add": "fire",\
     "paladin_spellcost": 12,\
     "value_factor": 10000,\
     "autoload": 100, ])\
   }),\
   ({"", (["defend_func": ({"paralyze1", "blind1", "nofrog1", "money1"}),\
     "magic_health_modifier": (["hp": 5, "sp": 5]),\
     "ac_factor": 150,\
     "quality_decay_factor": 300,\
     "dam_prot": (["fire": 3]),\
     "paladin_spellcost": 12,\
     "value_factor": 10000,\
     "autoload": 100, ])\
   }), ({"", ""}),\
}),\
"Nec_Ohm_An_": ({\
   ({"", ([ "hit_func": ({"unholy1", "vampire1"}),\
     "magic_health_modifier": (["hp": 7, "sp": 7]),\
     "wc_factor": 140,\
     "wc_fix_offset": 20,\
     "quality_decay_factor": 600,\
     "damage_type_add": "unholy",\
     "nekro_spellcost": 12,\
     "nekro_bonus": (["all": 25]),\
     "value_factor": 10000,\
     "autoload": 100, ])\
   }),\
   ({"", (["defend_func": ({"heal1", "manaheal1"}),\
     "magic_health_modifier": (["hp": 7, "sp": 7]),\
     "ac_factor": 150,\
     "quality_decay_factor": 600,\
     "dam_prot": (["holy": 3]),\
     "nekro_spellcost": 12,\
     "nekro_bonus": (["all": 25]),\
     "value_factor": 10000,\
     "autoload": 100, ])\
   }), ({"", ""}),\
  }),\
])

#define RUNE_WORDS2 ([\
"Kath_Bro_Xen_": ({\
   ({"", ([ "hit_func": ({"giant1", "human1"}),\
     "magic_health_modifier": (["hp": 4, "sp": 4]),\
     "attr_mod": (["dex": 5]),\
     "wc_factor": 155,\
     "wc_fix_offset": 20,\
     "quality_decay_factor": 200,\
     "value_factor": 10000,\
     "autoload": 100, ])\
   }),\
   ({"", (["defend_func": ({"heal1", "manaheal1"}),\
     "magic_health_modifier": (["hp": 6, "sp": 9]),\
     "ac_factor": 150,\
     "quality_decay_factor": 200,\
     "dam_prot": (["fire": 2, "cold": 2, "water": 2, "magic": 2, "air": 2, "poison": 2]),\
     "itemd_elemental_value": 12,\
     "material": "misc_wood",\
     "temperature_protection": ([0: 2, 1: 2]),\
     "value_factor": 10000,\
     "autoload": 100, ])\
   }), ({"", ""}),\
}),\
"Los_Por_Quod_Red_": ({\
   ({"", ([ "hit_func": ({"speed2", "blood2"}),\
     "magic_health_modifier": (["hp": 14, "sp": 14]),\
     "attr_mod": (["dex": 1, "int": 1, "con": 1, "str": 1]),\
     "wc_factor": 160,\
     "wc_fix_offset": 20,\
     "damage_type_add": "acid",\
     "quality_decay_factor": 800,\
     "value_factor": 10000,\
     "autoload": 120, ])\
   }),\
   ({"", (["defend_func": ({"heal2", "manaheal2"}),\
     "magic_health_modifier": (["hp": 14, "sp": 14]),\
     "attr_mod": (["dex": 1, "int": 1, "con": 1, "str": 1]),\
     "ac_factor": 200,\
     "quality_decay_factor": 800,\
     "temperature_protection": ([0: 3, 1: 3]),\
     "value_factor": 10000,\
     "autoload": 120, ])\
   }), ({"", ""}),\
}),\
"Dom_Wig_Nal_Jux_": ({\
  ({ "", ([ "hit_func": ({"dwarf2"}),\
     "magic_health_modifier": (["hp": 11, "sp": 11]),\
     "attr_mod": (["str": 5]),\
     "damage_type_add": "water",\
     "wc_factor": 165,\
     "wc_fix_offset": 25,\
     "quality_decay_factor": 400,\
     "value_factor": 10000,\
     "autoload": 120, ])\
   }),\
   ({"", (["defend_func": ({"heal2"}),\
     "magic_health_modifier": (["hp": 11, "sp": 11]),\
     "attr_mod": (["str": 5]),\
     "ac_factor": 200,\
     "quality_decay_factor": 400,\
     "temperature_protection": ([0: 1, 1: 1]),\
     "dam_prot": (["water": 4]),\
     "value_factor": 10000,\
     "autoload": 120, ])\
   }), ({"", ""}),\
}),\
"Inc_Ir_Hed_Tir_": ({\
   ({"", ([ "hit_func": ({"undead2", "vampire2"}),\
     "magic_health_modifier": (["hp": 13, "sp": 13]),\
     "attr_mod": (["dex": 5]),\
     "damage_type_add": "holy",\
     "itemd_prob_change": 50,\
     "wc_factor": 170,\
     "wc_fix_offset": 20,\
     "quality_decay_factor": 700,\
     "value_factor": 10000,\
     "autoload":120, ])\
   }),\
   ({"", (["defend_func": ({"manaheal2", "3"}),\
     "magic_health_modifier": (["hp": 13, "sp": 13]),\
     "attr_mod": (["dex": 5]),\
     "ac_factor": 200,\
     "quality_decay_factor": 700,\
     "temperature_protection": ([0: 3, 1: 0]),\
     "itemd_prob_change": 50,\
     "dam_prot": (["unholy": 4]),\
     "value_factor": 10000,\
     "autoload": 120, ])\
   }), ({"", ""}),\
}),\
"Ex_Hym_Ven_Zen_": ({\
   ({"", ([ "hit_func": ({"ogre2", "fairy2"}),\
     "magic_health_modifier": (["hp": 15]),\
     "attr_mod": (["int": 5]),\
     "damage_type_add": ({"poison", "air"}),\
     "itemd_prob_change": 50,\
     "wc_factor": 170,\
     "wc_fix_offset": 20,\
     "quality_decay_factor": 300,\
     "value_factor": 10000,\
     "autoload": 120, ])\
   }),\
   ({"", (["defend_func": ({"nopoison2", "3"}),\
     "magic_health_modifier": (["hp": 15]),\
     "attr_mod": (["int": 5]),\
     "ac_factor": 200,\
     "quality_decay_factor": 300,\
     "temperature_protection": ([0: 0, 1: 5]),\
     "itemd_prob_change": 50,\
     "dam_prot": (["air": 4, "poison": 4]),\
     "value_factor": 10000,\
     "autoload": 120, ])\
   }), ({"", ""}),\
}),\
])

#define RUNE_WORDS3 ([\
"Pal_Ad_In_":({\
   ({"", (["hit_func": ({"undead2", "necromant2", "darkelf2"}),\
     "magic_health_modifier": (["hp": 20, "sp": 10]),\
     "wc_factor": 150,\
     "wc_fix_offset": 10,\
     "light": 2,\
     "quality_decay_factor": 500,\
     "paladin_bonus": (["all": 15]),\
     "paladin_spellcost": 10,\
     "value_factor": 10000,\
     "autoload": 100,])\
   }),\
   ({"",([  "defend_func": ({"heal2", "blind1"}),\
     "magic_health_modifier": (["hp": 20, "sp": 10]),\
     "ac_factor": 200,\
     "light": 2,\
     "quality_decay_factor": 500,\
     "dam_prot": (["unholy": 3]),\
     "paladin_bonus": (["all": 15]),\
     "paladin_spellcost": 10,\
     "effective_wc": 150,\
     "value_factor": 10000,\
     "autoload": 100,])\
   }), ({"", ""}),\
}),\
"Arc_Gor_Tar_Ylem_Zod_": ({\
   ({"", ([ "hit_func": ({"verwuestung2", "dragon2", "paralyze2", "money2", 6}),\
     "magic_health_modifier": (["hp": 50, "sp": 50]),\
     "attr_mod": (["str": 1, "int":1, "dex": 1, "con": 1]),\
     "itemd_prob_change": 50,\
     "berserker_bonus": (["all": 30]),\
     "paladin_spellcost": 20,\
     "nekro_spellcost": 20,\
     "nekro_bonus": (["all": 30]),\
     "wc_factor": 200,\
     "wc_fix_offset": 50,\
     "quality_decay_factor": 0,\
     "value_factor": 100000,\
     "autoload": 500, ])\
   }),\
   ({"", (["defend_func": ({"heal2", "manaheal2", "noparalyze2", "nofrog2", "noblind2", "nodeaf2"}),\
     "magic_health_modifier": (["hp": 50, "sp": 50]),\
     "attr_mod": (["str": 1, "int":1, "dex": 1, "con": 1]),\
     "itemd_prob_change": 50,\
     "ac_factor": 250,\
     "quality_decay_factor": 0,\
     "dam_prot": (["fire": 1, "cold": 1, "water": 1, "magic": 1, "air": 1, "poison": 1, "lightning": 1, "acid": 1, "holy": 1, "unholy": 1, "mind": 1, "light": 1, "sound": 1, "terror": 1, "electric": 1, "explosion": 1]),\
     "itemd_elemental_value": 20,\
     "berserker_bonus": (["all": 30]),\
     "paladin_spellcost": 20,\
     "nekro_spellcost": 20,\
     "nekro_bonus": (["all": 30]),\
     "temperature_protection": ([0: 4, 1: 4]),\
     "value_factor": 100000,\
     "autoload": 500, ])\
   }), ({"", ""}),\
}),\
"Orc_Ezs_Tar_": ({\
  ({"", ([ "hit_func": ({"2"}),\
    "magic_health_modifier": (["hp": 10, "sp": 10]),\
    "wc_factor": 120,\
    "wc_fix_offset": 40,\
    "quality_decay_factor": 600,\
    "damage_type_add": "sound",\
    "bard_spellcost": 15,\
    "bard_bonus": (["all": 25]),\
    "value_factor": 10000,\
    "autoload": 100, ])\
  }),\
  ({"", (["defend_func": ({"nodeaf1", "manaheal1"}),\
    "magic_health_modifier": (["hp": 10, "sp": 10]),\
    "ac_factor": 150,\
    "quality_decay_factor": 600,\
    "dam_prot": (["sound": 3]),\
    "bard_spellcost": 12,\
    "bard_bonus": (["all": 25]),\
    "value_factor": 10000,\
    "autoload": 100, ])\
  }), ({"", ""}),\
}),\
])
