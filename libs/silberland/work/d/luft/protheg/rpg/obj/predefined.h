// Rooms
#define RPG_RLIGHT 0
#define RPG_RINDOORS 1
#define RPG_RTERRAIN 2
#define RPG_RSTDSMELL 3
#define RPG_RSTDSOUND 4
#define RPG_RSHORT 5
#define RPG_RLONG 6

// Weapons
#define RPG_WTYPE 0
#define RPG_WNAME 1
#define RPG_WGENDER 2
#define RPG_WSHORT 3
#define RPG_WLONG 4

// Armours
#define RPG_ATYPE 0
#define RPG_ANAME 1
#define RPG_AGENDER 2
#define RPG_ASHORT 3
#define RPG_ALONG 4

// NPCs
#define RPG_NNAME 0
#define RPG_NGENDER 1
#define RPG_NRACE 2
#define RPG_NSIZE 3
#define RPG_NALIGN 4
#define RPG_NSHORT 5
#define RPG_NLONG 6

#define PD_EXITS (["norden":"sueden","osten":"westen", \
  "sueden":"norden","westen":"osten", \
  "nordoben":"suedunten","suedoben":"nordunten", \
  "suedoben":"nordunten","nordoben":"suedunten", \
  "nordunten":"suedoben","suedunten":"nordoben", \
  "suedunten":"nordoben","nordunten":"suedoben", \
  "nordosten":"suedwesten","suedosten":"nordwesten", \
  "suedwesten":"nordosten","nordwesten":"suedosten", \
  "nordostoben":"suedwestunten","suedostoben":"nordwestunten", \
  "suedwestoben":"nordostunten","nordwestoben":"suedostunten", \
  "nordostunten":"suedwestoben","suedostunten":"nordwestoben", \
  "suedwestunten":"nordostoben","nordwestunten":"suedostoben", \
  "vorne":"hinten","hinten":"vorne","rauf":"runter", \
  "runter":"rauf","oben":"unten", "unten":"oben", \
  "links":"rechts","rechts":"links","rein":"raus", \
  "raus":"rein" ])


#define PD_OBJECTS (["dokument": "rpgdocument", \
     "behaelter": "rpgcontainer",	\
     "fackel": "rpgtorch",	\
     "geld": "rpgmoney"])
		     
#define PD_NPCS (["dunkelelfe": "Dunkelelfe"; FEMALE; "Dunkelelf"; 205; -1000; "Eine Dunkelelfe steht hier herum"; "Eine wunderschoene, jedoch boesartig dreinblickende Dunkelelfe", \
  "zwerg": "Zwerg"; MALE; "Zwerg"; 105; -50; "Ein Zwerg steht hier herum"; "Ein staemmiger Zwerg mit einem gigantischen Bart.", \
  "elf": "Elf"; MALE; "Elf"; 205; 500; "Ein Elf steht hier herum"; "Ein graziler Elf.", \
  "fee": "Fee"; FEMALE; "Fee"; 65; 1000; "Eine Fee flattert hier herum"; "Eine winzige Fee flattert mit ihren Fluegeln vor Dir herum.", \
  "hobbit": "Hobbit"; MALE; "Hobbit"; 105; 100; "Ein Hobbit steht hier herum"; "Ein kleiner Hobbit laechelt Dich an. Du hoerst seinen Magen knurren.", \
  "mensch": "Mensch"; MALE; "Mensch"; 160; 0; "Ein Mensch steht hier herum"; "Ein einfacher Mensch.", \
  "oger": "Oger"; MALE; "Oger"; 270; -200; "Ein Oger stampft hier herum"; "Ein stinkender Oger.", \
  "troll": "Troll"; MALE; "Troll"; 330; -500; "Ein Troll grummelt hier herum"; "Ein grosser Troll sabbert vor sich hin."])
		  
#define PD_ARMOURS (["panzer": AT_ARMOUR; "Panzer"; MALE; "Ein Panzer"; "Ein schwerer, eiserner Panzer", \
     "helm": AT_HELMET; "Helm"; MALE; "Ein Helm"; "Ein eiserner Helm.", \
     "ring": AT_RING; "Ring"; MALE; "Ein Ring"; "Ein goldener Ring", \
     "umhang": AT_CLOAK; "Umhang"; MALE; "Ein Umhang"; "Ein simpler Umhang aus Leinen", \
     "schild": AT_SHIELD; "Holzschild"; NEUTER; "Ein Holzschild"; "Ein kleiner, runder Holzschild.", \
     "amulett": AT_AMULET; "Amulett"; NEUTER; "Ein goldenes Amulett"; "Ein teuer aussehendes Amulett aus purem Gold.", \
     "guertel": AT_BELT; "Guertel"; MALE; "Ein lederner Guertel"; "Ein langer Guertel aus Leder."])

#define PD_WEAPONS (["schwert": WT_SWORD; "Schwert"; NEUTER; "Ein Schwert"; "Ein langes und ziemlich scharfes Schwert.", \
     "axt": WT_AXE; "Axt"; FEMALE; "Eine Axt"; "Eine grosse Axt mit einem hoelzernen Axtstiel.", \
     "keule": WT_CLUB; "Keule"; FEMALE; "Eine schwere Keule"; "Eine grosse, schwere Keule aus Holz.", \
     "speer": WT_SPEAR; "Speer"; MALE; "Ein langer Speer"; "Ein langer hoelzerner Speer.", \
     "messer": WT_KNIFE; "Messer"; NEUTER; "Ein Messer"; "Ein kurzes, jedoch sehr scharfes Messer.", \
     "peitsche": WT_WHIP; "Peitsche"; FEMALE; "Eine Peitsche"; "Eine lange, lederne Peitsche."])
		     
#define PD_ROOMS (["hoehle": 0; 1; TT_CAVE; "Hier riecht es modrig.\n"; "Hier ist es ziemlich ruhig.\n";"In einer dunklen Hoehle";"Du befindest Dich hier in einer dunklen Hoehle.\n", \
   "haus": 1; 1; TT_HOUSE; "Die Luft hier riecht ziemlich abgestanden.\n"; "Es ist relativ ruhig hier.\n"; "In einem alten Haus"; "Du befindest Dich hier in einem alten Haus. Alles rund um Dich herum wirkt etwas schaebig und abgestanden.\n", \
   "wald": 1; 0; TT_FOREST; "Ein frischer Waldgeruch steigt Dir in die Nase.\n"; "Rund um Dich herum ertoenen die typischen Geraeusche des Waldes.\n"; "Mitten im Wald"; "Du befindest Dich mitten im Wald. Rund um Dich herum ragen die Baeume in die Hoehe.\n", \
   "dschungel": 1; 0; TT_JUNGLE; "Es riecht stark nach frischer Dschungelerde.\n"; "Rund um Dich herum ertoenen die typischen Geraeusche des Dschungels.\n"; "Mitten im Dschungel"; "Du befindest Dich mitten im Dschungel. Rund um Dich herum ragen die Baeume in die Hoehe.\n", \
   "ebene": 1; 0; TT_PLAIN; "Es riecht nach dem Gras der Ebene.\n"; "Der Wind pfeift Dir um die Ohren.\n"; "In der grossen, weiten Ebene"; "Du befindest Dich mitten in der grossen, weiten Ebene.\n", \
   "strasse": 1; 0; TT_ROAD; "Es riecht nach trockener, staubiger Strasse.\n"; "Die Strasse ist relativ ruhig.\n"; "An einer Strasse"; "Du befindest Dich mitten auf einer langen Strasse. Sie scheint ziemlich verlassen zu sein.\n"])

