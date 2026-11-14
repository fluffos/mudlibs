// race_guild_armour.h
// Defines fuer Rassen und Gilden spezifische Ruestungen
// 08.05.2002 Feyaria@SilberLand

#define X1 ({1,4,5,9,11,13,14,15,16,17,40,43})

#define X2 ({0,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,27,36,37,38,39,40,41,42,43})

#define RACE_GUILD_NAMES ({\
 ({"Mensch", "berserker", "Kriegsherrn"}),\
 ({"Zwerg", "berserker", "Schlachtenwueter"}),\
 ({"Elf", "berserker", "Axtschwinger"}),\
 ({"Hobbit", "berserker", "Axtkaempfer"}),\
 ({"Oger", "berserker", "Menschenfresser"}),\
 ({"Troll", "berserker", "Schlaechter"}),\
 ({"Dunkelelf", "berserker", "Blutrausch"}),\
 ({"Gaffo", "berserker", "Rotaugen"}),\
 \
 ({"Mensch", "druidenzirkel", "Elementaristen"}),\
 ({"Zwerg", "druidenzirkel", "Erzbeschwoerer"}),\
 ({"Elf", "druidenzirkel", "Luftbeschwoerer"}),\
 ({"Hobbit", "druidenzirkel", "Feuerbeschwoerer"}),\
 ({"Dunkelelf", "druidenzirkel", "Eisbeschwoerer"}),\
 ({"Oger", "druidenzirkel", "Wasserbeschwoerer"}),\
 ({"Fee", "druidenzirkel", "Humusbeschwoerer"}),\
 ({"Gaffo", "druidenzirkel", "Brennaugen"}),\
 \
 ({"Mensch", "paladine", "Templer"}),\
 ({"Zwerg", "paladine", "Staubanbeter"}),\
 ({"Elf", "paladine", "Schwertschwinger"}),\
 ({"Hobbit", "paladine", "Schwertkaempfer"}),\
 ({"Troll", "paladine", "Schwertfresser"}),\
 ({"Fee", "paladine", "Engels"}),\
 ({"Gaffo", "paladine", "Sonnenstarrer"}),\
 \
 ({"Mensch", "abenteurer", "Abenteurer"}),\
 ({"Zwerg", "abenteurer", "Stollenbauer"}),\
 ({"Elf", "abenteurer", "Waldlaeufer"}),\
 ({"Hobbit", "abenteurer", "Pelzfuss"}),\
 ({"Oger", "abenteurer", "Fresssack"}),\
 ({"Troll", "abenteurer", "Steinschaedel"}),\
 ({"Fee", "abenteurer", "Schmetterlings"}),\
 ({"Dunkelelf", "dunkelelfen", "Dunkelheits"}),\
 ({"Gaffo", "abenteurer", "Grossaugen"}),\
 \
 ({"Mensch", "zechpreller", "Saeufer"}),\
 ({"Zwerg", "zechpreller", "Biertrinker"}),\
 ({"Elf", "zechpreller", "Likoertrinker"}),\
 ({"Hobbit", "zechpreller", "Weintrinker"}),\
 ({"Dunkelelf", "zechpreller", "Schwarztrinker"}),\
 ({"Oger", "zechpreller", "Blutsaeufer"}),\
 ({"Troll", "zechpreller", "Schnapstrinker"}),\
 ({"Fee", "zechpreller", "Troepfchentrinker"}),\
 ({"Gaffo", "zechpreller", "Obstgaerer"}),\
 \
 ({"Mensch", "nekromanten", "Skelettbeschwoerer"}),\
 ({"Zwerg", "nekromanten", "Zombiebeschwoerer"}),\
 ({"Elf", "nekromanten", "Ghoulbeschwoerer"}),\
 ({"Hobbit", "nekromanten", "Mumienbeschwoerer"}),\
 ({"Dunkelelf", "nekromanten", "Untotenbeschwoerer"}),\
 ({"Oger", "nekromanten", "Leichenfresser"}),\
 ({"Troll", "nekromanten", "Geistbeschwoerer"}),\
 ({"Untoter", "nekromanten", "Nekromanten"}),\
 ({"Gaffo", "nekromanten", "Starrblicker"}),\
 \
 ({"Mensch", "waldlaeufer", "Wildhueter"}),\
 ({"Zwerg", "waldlaeufer", "Baerenringer"}),\
 ({"Elf", "waldlaeufer", "Wipfellaeufer"}),\
 ({"Hobbit", "waldlaeufer", "Kraeutersammler"}),\
 ({"Oger", "waldlaeufer", "Baumreisser"}),\
 ({"Troll", "waldlaeufer", "Bestienzwinger"}),\
 ({"Fee", "waldlaeufer", "Libellenreiter"}),\
 ({"Dunkelelf", "waldlaeufer", "Dunkelpirscher"}),\
 ({"Gaffo", "waldlaeufer", "Dickichtgaffer"}),\
\
 ({"Mensch", "bardengilde", "Trommelwirbler"}),\
 ({"Zwerg", "bardengilde", "Hornblaeser"}),\
 ({"Elf", "bardengilde", "Floetenspieler"}),\
 ({"Hobbit", "bardengilde", "Pfeifenpuster"}),\
 ({"Oger", "bardengilde", "Gonghauer"}),\
 ({"Troll", "bardengilde", "Paukenschlaeger"}),\
 ({"Fee", "bardengilde", "Harfenstreichler"}),\
 ({"Dunkelelf", "bardengilde", "Lautenzupfer"}),\
 ({"Gaffo", "bardengilde", "Schunkelsaenger"}),\
\
 ({"Mensch", "amazonen", "Kriegerinnen"}),\
 ({"Zwerg", "amazonen", "Steinkaempferinnen"}),\
 ({"Elf", "amazonen", "Valkyren"}),\
 ({"Hobbit", "amazonen", "Speerkaempferinnen"}),\
 ({"Dunkelelf", "amazonen", "Nachtkaempferinnen"}),\
 ({"Oger", "amazonen", "Maennerfresserinnen"}),\
 ({"Troll", "amazonen", "Furien"}),\
 ({"Fee", "amazonen", "Speerstecherinnen"}),\
 ({"Gaffo", "amazonen", "Augenstecher"}),\
})

// ARMOUR_TYPE, NAME,
#define RACE_GUILD_ARMOUR_TYPES  ({\
    ({AT_ARMOUR, "panzer",}),\
    ({AT_HELMET, "helm",}),\
    ({AT_BRACERS, "armschienen", }),\
    ({AT_GLOVE, "handschuhe",}),\
    ({AT_BOOT, "stiefel",}),\
    ({AT_TROUSERS, "beinschienen",}),\
    ({AT_CLOAK, "umhang", }),\
})

#define ALLOWED_UIDS ({"gwenshara", "feyaria", "d.dschungel.feyaria", "GUILD.berserker", "d.astral.feyaria" })
