// Tamedhon MUDlib
//
// sys/thing/material.h -- material handling header
//
// $Date: 2023/09/20 10:00:00 $
/* $Revision: 2.7 $
 * $Log: material.h,v $
 * Revision 2.7  2023/09/20 10:00:00  Gralkor
 * MAT_LUMINARA (Luminara-Holz (magisch zum Leuchten zu bringen)
 *
 * Revision 2.6  2004/01/28 17:10:00  Serii
 * MAT_RESIN (Harz)
 *
 * Revision 2.5  1998/01/20 15:42:37  Feyaria
 * neue materialien
 *
 * Revision 2.4  1997/09/25 15:37:22  Woody
 * Neues Materialsystem -> neue Properties, Konstanten, etc. :)
 *
 * Revision 2.3  1997/04/17 02:03:14  Feyaria
 * MAT_FUR (Pelz)
 *
 * Revision 2.2  1997/04/01 11:28:37  Feyaria
 * *** empty log message ***
 *
 * Revision 2.1  1997/04/01 11:18:55  Feyaria
 * MAT_BONE
 *
 * Revision 2.0  1997/03/31 15:58:55  Woody
 * prepared for revision control
 *
 */
 
#ifndef __THING_MATERIAL_H__
#define __THING_MATERIAL_H__

// properties
#define P_MATERIAL           "material"
#define P_MATERIAL_KNOWLEDGE "material_knowledge"
#define MATERIALDB           "/p/daemon/materialdb"
#define MATERIAL_SYMMETRIC_RECOGNIZABILITY "mat_sym_recoc"

// Feste Materialien, die nicht in andere Kategorien passen:
#define MAT_MISC_SOLID  "misc_solid"  // allg. Feststoffe
#define MAT_LEATHER     "leather"     // Leder
#define MAT_GLASS       "glass"       // Glas
#define MAT_CERAMIC     "ceramic"     // Keramic
#define MAT_ICE         "ice"         // Eis
#define MAT_PHOSPHORUS  "P"           // Phosphor
#define MAT_SALPETER    "salpeter"    // Salpeter
#define MAT_CARBON      "C"           // Kohlenstoff
#define MAT_PEARL       "pearl"       // Perlmutt
#define MAT_WAX         "wax"         // Wachs
#define MAT_TAR         "tar"         // Teer
#define MAT_CHALK       "chalk"       // Kreide
#define MAT_SHIT        "shit"        // Scheisse
#define MAT_FAT         "fat"         // Fett
#define MAT_RESIN	"resin"	      // Harz
#define MAT_PLASTIC     "plastic"     // Kunststoff

// Papier und Aehnliches:
#define MAT_PAPER       "paper"       // Papier
#define MAT_CARTON      "carton"      // Karton
#define MAT_PERGAMENT   "pergament"   // Pergament
#define MAT_PAPYRUS     "papyrus"     // Papyrus

// Stoffe:
#define MAT_CLOTH       "cloth"       // Stoff
#define MAT_SILK        "silk"        // Seide
#define MAT_VELVET      "velvet"      // Samt
#define MAT_COTTON      "cotton"      // Baumwolle
#define MAT_FELT        "felt"        // Filz
#define MAT_BAUSCH      "bausch"      // Bausch (Elfenseide)

// Erden und seltene Erden
#define MAT_EARTH       "earth"       // Erde
#define MAT_SAND        "sand"        // Sand
#define MAT_DUST        "dust"        // Staub
#define MAT_PLUTONIUM   "Pu"          // Plutonium

// Hoelzer
#define MAT_MISC_WOOD           "misc_wood"           // allg. Holz
#define MAT_MISC_DECIDUOUS_WOOD "misc_deciduous_wood" // allg. Laubholz
#define MAT_MISC_CONIFER_WOOD   "misc_conifer_wood"   // allg. Nadelholz
#define MAT_MISC_TROPICAL_WOOD  "misc_tropical_wood"  // allg. Tropenholz
#define MAT_PEAR_WOOD           "pear_wood"           // Birnbaumholz
#define MAT_OAK                 "oak"                 // Eiche
#define MAT_BEECH               "beech"               // Buche
#define MAT_EBONY               "ebony"               // Ebenholz
#define MAT_FIR                 "fir"                 // Tanne
#define MAT_TEAK                "teak"                // Teak
#define MAT_CORK                "cork"                // Kork
#define MAT_BALSA               "balsa"               // Balsa
#define MAT_ELM_WOOD            "elm_wood"            // Ulmenholz
#define MAT_YEW_WOOD            "yew_wood"            // Eibenholz
#define MAT_ASH_WOOD            "ash_wood"            // Eschenholz
#define MAT_TICTOC_WOOD         "tictoc_wood"         // Tic-toc-holz
#define MAT_BIRCH_WOOD          "birch_wood"          // Birkenholz
#define MAT_LUMINARA_WOOD	"luminara_wood"	      // Luminara-Holz

// Steine
#define MAT_MISC_STONE "misc_stone"   // allg. Gestein
#define MAT_GRANITE    "granite"      // Granit
#define MAT_SLATE      "slate"        // Schiefer
#define MAT_MARBLE     "marble"       // Marmor
#define MAT_CONCRETE   "concrete"     // Beton
#define MAT_ASPHALT    "asphalt"      // Asphalt
#define MAT_LIME       "lime"         // Kalk

// Metalle
#define MAT_MISC_METAL "misc_metal"   // allg. Metall
#define MAT_IRON       "Fe"           // Eisen
#define MAT_STEEL      "steel"        // Stahl
#define MAT_COPPER     "Cu"           // Kupfer
#define MAT_BRONCE     "bronce"       // Bronze
#define MAT_BRASS      "brass"        // Messing
#define MAT_TIN        "Sn"           // Zinn
#define MAT_LEAD       "Pb"           // Blei
#define MAT_TITANIUM   "Ti"           // Titan
#define MAT_MERCURY    "Hg"           // Quecksilber
#define MAT_ALUMINIUM  "Al"           // Aluminium
#define MAT_TUNGSTEN   "W"            // Wolfram
#define MAT_COBALT     "Co"           // Kobalt
#define MAT_IRIDIUM    "Ir"           // Iridium
#define MAT_CHROMIUM   "Cr"           // Chrom
// Edelmetalle:
#define MAT_SILVER     "Ag"           // Silber
#define MAT_GOLD       "Au"           // Gold
#define MAT_PLATINUM   "Pt"           // Platin
#define MAT_MITHRIL    "mithril"      // Mithril
#define MAT_ADAMANT    "adamant"      // Adamant

// Fluessigkeiten
#define MAT_MISC_FLUID "misc_fluid"   // allg. Fluessigkeit
#define MAT_WATER      "water"        // Wasser
#define MAT_MILK       "milk"         // Milch
#define MAT_ALCOHOL    "alcohol"      // Alkohol
#define MAT_OIL        "oil"          // Oel
#define MAT_BLOOD      "blood"        // Blut
#define MAT_PARFUM     "parfum"       // Parfuem
#define MAT_INK        "ink"          // Tinte
#define MAT_SLIME      "slime"        // Schleim
#define MAT_MISC_ACID  "misc_acid"    // allg. Saeure

// Gase:
#define MAT_MISC_GAS     "misc_gas"       // allg. Gas
#define MAT_AIR          "air"            // Luft
#define MAT_METHANE      "methane"        // Methan
#define MAT_HELIUM       "He"             // Helium
#define MAT_LAUGHING_GAS "laughing_gas"   // Lachgas

// Edelsteine
#define MAT_MISC_JEWEL "misc_jewel"   // allg. Edelstein
#define MAT_OCTARINE   "octarine"     // Oktarin
#define MAT_DIAMOND    "diamond"      // Diamant
#define MAT_RUBY       "ruby"         // Rubin
#define MAT_SAPPHIRE   "sapphire"     // Saphir
#define MAT_AQUAMARINE "aquamarine"   // Aquamarin
#define MAT_EMERALD    "emerald"      // Smaragd
#define MAT_JADE       "jade"         // Jade
#define MAT_QUARTZ     "quartz"       // Quarz
#define MAT_AMETHYST   "amethyst"     // Amethyst
#define MAT_TOPAZ      "topaz"        // Topaz
#define MAT_AMBER      "amber"        // Bernstein
#define MAT_OPAL       "opal"         // Opal

// Mineralien:
#define MAT_MISC_MINERAL "misc_mineral"   // allg. Mineralien
#define MAT_AGATE        "agate"          // Achat
#define MAT_SULFUR       "S"              // Schwefel
#define MAT_LAZURITE     "lazurite"       // Lasurit
#define MAT_CRYSTAL      "crystal"        // Kristall
#define MAT_OBSIDIAN     "obsidian"       // Obsidian
#define MAT_ASBESTOS     "asbestos"       // Asbest

// Pflanzliche Dinge
#define MAT_MISC_HERBAL  "misc_herbal"    // allg. planzliches Material
#define MAT_MISC_PLANT   "misc_plant"     // Pflanze
#define MAT_WOODEN_PLANT "wooden_plant"   // Baeume
#define MAT_STRAW        "straw"          // Stroh

// Drogen und Arzneimittel
#define MAT_MISC_DRUG "misc_drug"     // allg. Drogen
#define MAT_CANNABIS  "cannabis"      // Hanf/Cannabis
#define MAT_HEAL      "heal"          // Heilmittel

// Essbares
#define MAT_MISC_FOOD   "misc_food"   // allg. Nahrungsmittel
#define MAT_FRUIT       "fruit"       // Fruechte
#define MAT_BREAD       "bread"       // Brot
#define MAT_SUGAR       "sugar"       // Zucker
#define MAT_MUSHROOM    "mushroom"    // Pilze
#define MAT_MISC_SPICE  "misc_spice"  // Gewuerz
#define MAT_PEPPER      "pepper"      // Pfeffer
#define MAT_SALT        "salt"        // Salz

// Ueberreste von Lebewesen:
#define MAT_MISC_DEAD   "misc_dead"   // allg. totes Material
#define MAT_HORN        "horn"        // Horn
#define MAT_HAIR        "hair"        // Haare
#define MAT_BONE        "bone"        // Knochen
#define MAT_CHITIN      "chitin"      // Chitin
#define MAT_GHOST       "ghost"       // Geist
#define MAT_SKIN        "skin"        // Haut
#define MAT_FEATHER     "feather"     // Federn
#define MAT_PELT        "pelt"        // Fell
#define MAT_IVORY       "ivory"       // Elfenbein
#define MAT_WOOL        "wool"        // Wolle
#define MAT_FLESH       "flesh"       // Fleisch

// Sprengstoffe:
#define MAT_MISC_EXPLOSIVE "misc_explosive"  // allg. Sprengstoffe
#define MAT_GUNPOWDER      "gunpowder"       // Schiesspulver
#define MAT_NITROGLYCERINE "nitroglycerine"  // Nitroglyzerin
#define MAT_TNT            "tnt"             // Dynamit

// Verschiedenes
#define MAT_MISC           "misc"            // allg. Material (default)
#define MAT_MISC_MAGIC     "misc_magic"      // allg. magisches Material
#define MAT_MISC_HOLY      "misc_holy"       // allg. heiliges Material
#define MAT_MISC_UNHOLY    "misc_unholy"     // allg. unheiliges Material
#define MAT_MISC_LIVING    "misc_living"     // allg. lebendes Material
#define MAT_MISC_POISON    "misc_poison"     // allg. giftiges Material
#define MAT_MISC_INVIS     "misc_invis"      // allg. unsichtbares Material
#define MAT_MISC_FLEXIBLE  "misc_flexible"   // allg. biegsames Material
#define MAT_MISC_MAGNETIC  "misc_magnetic"   // allg. magnetisches Material
#define MAT_FIRE           "fire"            // Feuer
#define MAT_LIGHTNING      "lightning"       // Blitz
#define MAT_SHADOW         "shadow"          // Schatten

// Materialgruppen
#define MATGROUP_SOLID          "mg_solid"         // Feststoffe
#define MATGROUP_FLUID          "mg_fluid"         // Fluessigkeiten
#define MATGROUP_GAS            "mg_gas"           // Gase

#define MATGROUP_WOOD           "mg_wood"          // Hoelzer
#define MATGROUP_DECIDUOUS_WOOD "mg_deciduous_wood"  // Laubhoelzer
#define MATGROUP_CONIFER_WOOD   "mg_conifer_wood"  // Nadelhoelzer
#define MATGROUP_TROPICAL_WOOD  "mg_tropical_wood" // Tropenhoelzer
#define MATGROUP_STONE          "mg_stone"         // Gestein
#define MATGROUP_METAL          "mg_metal"         // Metalle
#define MATGROUP_PRECIOUS_METAL "mg_precious_metal"  // Edelmetalle
#define MATGROUP_JEWEL          "mg_jewel"         // Edelsteine
#define MATGROUP_MINERAL        "mg_mineral"       // Mineralien
#define MATGROUP_PAPER          "mg_paper"         // Papier
#define MATGROUP_CLOTH          "mg_cloth"         // Stoffe

#define MATGROUP_ELEMENTAL      "mg_elemental"     // Elemente (altertuemlich)
#define MATGROUP_BIO            "mg_bio"           // biologisches Material
#define MATGROUP_LIVING         "mg_living"        // lebendiges Material
#define MATGROUP_HERBAL         "mg_herbal"        // pflanzliches Material
#define MATGROUP_DEAD           "mg_dead"          // totes Material
#define MATGROUP_DRUG           "mg_drug"          // Drogen

#define MATGROUP_SWIMABLE       "mg_swimable"      // schwimmbares Material
#define MATGROUP_INFLAMMABLE    "mg_inflammable"   // brennbares Material
#define MATGROUP_EXPLOSIVE      "mg_explosive"     // explosives Material
#define MATGROUP_POISONOUS      "mg_poisonous"     // Gifte
#define MATGROUP_MAGIC          "mg_magic"         // magisches Material
#define MATGROUP_RADIOACTIVE    "mg_radioactive"   // radioaktives Material
#define MATGROUP_ELECTRICAL     "mg_electrical"    // geladenes Material
#define MATGROUP_ACIDIC         "mg_acidic"        // Saeuren
#define MATGROUP_EATABLE        "mg_eatable"       // essbares Material
#define MATGROUP_FLEXIBLE       "mg_flexible"      // biegsames Material
#define MATGROUP_INVIS          "mg_invis"         // unsichtbares Material
#define MATGROUP_MAGNETIC       "mg_magnetic"      // magnetisches Material
#define MATGROUP_HOLY           "mg_holy"          // heiliges Material
#define MATGROUP_UNHOLY         "mg_unholy"        // unheiliges Material

// So, und nun die alten AL-Konstanten, um kompatibel zu sein...
// -------------------------------------------------------------------------
#define MAT_WOOD           MAT_MISC_WOOD         // allg. Holz
#define MAT_METAL          MAT_MISC_METAL        // allg. Metall
#define MAT_JEWEL          MAT_MISC_JEWEL        // allg. Edelstein
#define MAT_MAGIC          MAT_MISC_MAGIC        // allg. magisches Material
#define MAT_ANIMAL         MAT_MISC_LIVING       // allg. lebendes Material
#define MAT_PLANT          MAT_MISC_PLANT        // Pflanze
#define MAT_FOOD           MAT_MISC_FOOD         // allg. Nahrungsmittel
#define MAT_FUR            MAT_PELT              // Fell
#define MAT_STONE          MAT_MISC_STONE        // allg. Gestein
#define MAT_GUM            MAT_PLASTIC           // Kunststoff
// -------------------------------------------------------------------------

#ifdef NEED_PROTOTYPES

#ifndef __THING_MATERIAL_H_PROTO__
#define __THING_MATERIAL_H_PROTO__

// prototypes

int QueryMaterial(string mat);
int QueryMaterialGroup(string matgroup);
string MaterialList(int casus, mixed idinf);

// Kompatibilitaetsfunktionen:
string MatToString(string mat, int casus);
// wandelt eine Materialkonstante in einen lesbaren String, also
// z.B. MatToString(MAT_WOOD, WESSEN) == "Holzes"
string MatList(int casus);
// erstellt eine Liste der Materialien des Objektes

#endif // __THING_MATERIAL_H_PROTO__

#endif // NEED_PROTOYPES

#endif // __THING_MATERIAL_H__
