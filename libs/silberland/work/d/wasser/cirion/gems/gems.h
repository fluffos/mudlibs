//gems.h

#include <defines.h>
#include <moredef.h>
#include <properties.h>
#include <combat.h>
#include <moving.h>
#include <new_skills.h>
#include <wizlevels.h>
#include <language.h>
#include <ansi.h>

#define KEEPER "cirion"

/////////////////////////////////////////////////////////////////////////////
//
//  Diese Konstanten beeinflussen die Spielstaerke der Ruestungen
//
#define DECHARGE_FACTOR 1.0  // Staerke/Haeufigkeit der Entladung
#define DEFEND_FACTOR 0.5   // Defensivwirkung gegen Element
#define AC_FACTOR 1.0       // P_WC
#define PRICE_FACTOR 1.0    // Preis
//
//  Diese Konstanten beeinflussen die Spielstaerke der Stargates
//
#define DURATION 20 // Wie viele resets haelt das Tor 
                    // (wird mit gemsize multipliziert)
#define MP_MARK 15  // Wieviel mp kostet markieren
#define MP_ACTIVATE 100 // Wieviel mp kostet aktivieren
#define MP_RESET 10 // Wieviel mp/hp kostet es im reset?
#define FREE_TPORT 5 // Wie oft umsonst?
#define FIXED_PARALYZE 5 // Wieviel Paralyse fix?
#define RANDOM_PARALYZE 5 // Wiviel Paralyse random?

/////////////////////////////////////////////////////////////////////////////

#ifdef DBME
#undef DBME
#endif
#define DBME(x) if (find_player(KEEPER)) tell_object(find_player(KEEPER),(break_string(ANSI_RED"Bug in STDER:"ANSI_NORMAL" "+x+"\n")))

#define GATEID "\nstargate\n"
#define MGEMID "\nmagic_gem\n"
#define STARGEMID "\nstargem\n"
#define FIREGEMID "\nfiregem\n"

#define GEM_HOME "/d/wasser/cirion/gems"
#define GEM_OBJ GEM_HOME"/obj"
#define GEM_ARMOUR GEM_HOME"/armour"
#define GEM_WEAPON GEM_HOME"/weapon"
#define GEM_LOG GEM_HOME"/log"
#define GEM_SAVE GEM_HOME"/save"
#define GEM_NPC GEM_HOME"/npc"
#define FANARI GEM_NPC"/fanari"
#define SCHMIEDE WHOME"/earost/room/rmnn"
#define LADEN WHOME"/earost/room/rmon"
#define GATEMASTER GEM_HOME"/stargatem"
#define STARGATE GEM_OBJ"/stargate"

#define GEM_ERRLOG GEM_LOG"/err.log"

#define DECHARGE to_int(50*DECHARGE_FACTOR)
#define PRICE(x,y) to_int((ARMSTAT[x]["weight"]+5000)*(VALID_ARMOUR_CLASS[x]+50)*0.1*(y/4*.5+.5)*PRICE_FACTOR)

#define NOBUGGER 1
#define NOLOG 2
#define NODB 4

#define GEMCOLORS (["amethyst"		:"blau"\
                   ,"aquamarin"		:"wasserblau"\
                   ,"bergkristall"	:"weiss"\
                   ,"bernstein"		:"gelb"\
                   ,"diamant"		:"weiss"\
                   ,"granat"		:"dunkelrot"\
                   ,"lapislazuli"	:"gruen"\
                   ,"onyx"		:"schwarz"\
                   ,"opal"		:"bunt"\
                   ,"perle"		:"weiss"\
                   ,"rubin"		:"rot"\
                   ,"saphir"		:"eisblau"\
                   ,"smaragd"		:"gruen"\
                   ,"topas"		:"gelb"\
                   ,"turmalin"		:"schwarzgruen"\
                   ,"zirkon"		:"braun"])

#define ARMSTAT ([AT_ARMOUR:ARMOURSTAT \
                 ,AT_HELMET:HELMETSTAT \
                 ,AT_BRACERS:BRACERSSTAT \
                 ,AT_TROUSERS:TROUSERSSTAT \
                 ,AT_SHIELD:SHIELDSTAT \
                 ,AT_GLOVE:GLOVESTAT \
                 ,AT_MISC:MISCSTAT])
                             
   /*
   ,"":\
   */

#define ARMOURSTAT\
  (["name":"panzer"\
   ,"short":"Ein "+CAP(gemtype)+"panzer"\
   ,"gender":MALE\
   ,"weight":3000\
   ,"long":\
    "Dies ist "+CAP(gemtype)+"panzer. Er ist voellig aus diesem "\
    "Edelstein gefertigt und aeusserst kunstvoll verziert. Der "\
    "Panzer bedeckt den gesamten Oberkoerper und bietet so exzellenten "\
    "Ruestungsschutz. Eine filigrane Gravur auf der Brust des Panzers "\
    "stellt "\
   ,"name_presay":""\
    ])                 
#define HELMETSTAT\
  (["name":"helm"\
   ,"short":"Ein "+CAP(gemtype)+"helm"\
   ,"gender":MALE\
   ,"weight":900\
   ,"long":\
    "Dies ist ein "+CAP(gemtype)+"helm. Er ist voellig aus diesem "\
    "Edelstein gefertigt und aeusserst kunstvoll verziert. Der Helm "\
    "Schuetzt den Kopf, ohne dabei die Sicht oder die Bewegung "\
    "zu behindern. Eine filigrane Gravur an der Stirnseite stellt "\
   ,"name_presay":""\
    ])                 
#define BRACERSSTAT\
  (["name":"armschienen"\
   ,"short":"Ein Paar "+CAP(gemtype)+"armschienen"\
   ,"gender":NEUTER\
   ,"weight":1200\
   ,"long":\
    "Dies ist ein Paar "+CAP(gemtype)+"armschienen. Es ist voellig aus "\
    "diesem Edelstein gefertigt und aeusserst kunstvoll verziert. Es schuetzt "\
    "die Arme vortrefflich, ohne dabei zu behindern. Eine filigrane Gravur "\
    "an der Seite der linken Schiene stellt "\
   ,"name_presay":"Paar "\
   ])                 
#define TROUSERSSTAT\
  (["name":"beinschienen"\
   ,"short":"Ein Paar "+CAP(gemtype)+"beinschienen"\
   ,"gender":NEUTER\
   ,"weight":1400\
   ,"long":\
    "Dies ist ein Paar "+CAP(gemtype)+"armschienen. Es ist voellig aus diesem "\
    "Edelstein gefertigt und aeusserst kunstvoll verziert. Trotz ihres "\
    "recht hohen Gewichts behindern die Beinschienen kaum und bieten einen "\
    "hervorragenden Schutz. Eine filigrane Gravur auf der linken Beinschiene "\
    "stellt "\
   ,"name_presay":"Paar "\
   ])                 
#define SHIELDSTAT\
  (["name":"schild"\
   ,"short":"Ein "+CAP(gemtype)+"schild"\
   ,"gender":NEUTER\
   ,"weight":2200\
   ,"long":\
    "Dies ist ein "+CAP(gemtype)+"schild. Es ist voellig aus diesem "\
    "Edelstein gefertigt und kunstvoll verziert. Durch seine "\
    "aussergewoehnliche Haerte bietet es hervorragenden Schutz. Eine grosse "\
    "aber filigrane Gravur auf der Aussenseite des Schildes stellt "\
   ,"name_presay":""\
   ])                 
#define GLOVESTAT\
  (["name":"handschuhe"\
   ,"short":"Ein Paar "+CAP(gemtype)+"handschuhe"\
   ,"gender":NEUTER\
   ,"weight":550\
   ,"long":\
    "Dies ist ein Paar "+CAP(gemtype)+"handschuhe. Es ist voellig aus diesem "\
    "Edelstein gefertigt und eine filigrane Arbeit von hoher Kunstfertigkeit, "\
    "denn obwohl der Edelstein starr ist, kann man mit diesen Handschuhen "\
    "ganz normal greifen, und sie bieten gleichzeitig einen hervorragenden "\
    "Schutz. Eine kleine Gravur auf dem Handruecken stellt "\
   ,"name_presay":"Paar "\
   ])                 
#define MISCSTAT\
  (["name":"ruestung"\
   ,"short":"Eine "+CAP(gemtype)+"ruestung"\
   ,"gender":FEMALE\
   ,"weight":10000\
   ,"long":\
    "Dies ist eine "+CAP(gemtype)+"ruestung. Er ist voellig aus diesem "\
    "Edelstein gefertigt. Aufgrund ihrer Haerte bietet sie zwar "\
    "groesstmoeglichen Schutz, ist aber dafuer schwer und unhandlich, "\
    "und kann aufgrund der geringen Flexibilitaet nur von Personen "\
    "gleichen Geschlechts getragen werden. \n"\
    "Als Du genauer hinsiehst, erkennst Du, dass vorne auf der Ruestung "\
   ,"name_presay":""\
   ])                 
                                
#define GEMSTAT (["edelstein":EDELSTEINSTAT\
                 ,"rubin":RUBINSTAT\
                 ,"aquamarin":AQUAMARINSTAT\
                 ,"topas":TOPASSTAT\
                 ,"smaragd":SMARAGDSTAT\
                 ,"saphir":SAPHIRSTAT\
                 ,"opal":OPALSTAT\
                 ,"lapislazuli":LAPISSTAT\
                 ,"onyx":ONYXSTAT\
                 ,"perlen":PERLENSTAT\
                 ,"bernstein":BERNSTEINSTAT\
                 ,"granat":GRANATSTAT\
                 ,"bergkristall":BERGSTAT\
                 ,"diamant":DIAMANTSTAT\
                 ,"amethyst":AMETHYSTSTAT\
                 ,"zirkon":ZIRKONSTAT\
                 ,"turmalin":TURMALINSTAT])

#define EDELSTEINSTAT (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Angriffe."\
                       ,"defend_factor":1.0\
                       ,"dam_type":DT_SLASH\
                       ,"plural":"edelsteine"\
                       ,"material":MAT_MISC_JEWEL])
#define RUBINSTAT     (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Feuer."\
                       ,"defend_factor":2.0\
                       ,"dam_type":DT_FIRE\
                       ,"plural":"rubine"\
                       ,"material":MAT_RUBY])
#define AQUAMARINSTAT (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Wasser."\
                       ,"defend_factor":2.0\
                       ,"dam_type":DT_WATER\
                       ,"plural":"aquamarine"\
                       ,"material":MAT_AQUAMARINE])
#define TOPASSTAT     (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Luft."\
                       ,"defend_factor":2.0\
                       ,"dam_type":DT_AIR\
                       ,"plural":"topase"\
                       ,"material":MAT_TOPAZ])
#define SMARAGDSTAT   (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Gift."\
                       ,"defend_factor":2.0\
                       ,"dam_type":DT_POISON\
                       ,"plural":"smaragde"\
                       ,"material":MAT_EMERALD])
#define SAPHIRSTAT    (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Kaelte."\
                       ,"defend_factor":2.0\
                       ,"dam_type":DT_COLD\
                       ,"plural":"saphire"\
                       ,"material":MAT_SAPPHIRE])
#define OPALSTAT      (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Magie."\
                       ,"defend_factor":1.5\
                       ,"dam_type":DT_MAGIC\
                       ,"plural":"opale"\
                       ,"material":MAT_OPAL])
#define LAPISSTAT     (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Saeure."\
                       ,"defend_factor":2.0\
                       ,"dam_type":DT_ACID\
                       ,"plural":"lapislazulis"\
                       ,"material":MAT_MISC_JEWEL])
#define ONYXSTAT      (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Angst und Schrecken."\
                       ,"defend_factor":2.0\
                       ,"dam_type":DT_TERROR\
                       ,"plural":"onyxe"\
                       ,"material":MAT_MISC_JEWEL])
#define PERLENSTAT    (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Laerm."\
                       ,"defend_factor":2.0\
                       ,"dam_type":DT_SOUND\
                       ,"plural":"perlen"\
                       ,"material":MAT_PEARL])
#define BERNSTEINSTAT (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Licht."\
                       ,"defend_factor":2.0\
                       ,"dam_type":DT_LIGHT\
                       ,"plural":"bernsteine"\
                       ,"material":MAT_AMBER])
#define GRANATSTAT    (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Gewitter."\
                       ,"defend_factor":2.0\
                       ,"dam_type":DT_LIGHTNING\
                       ,"plural":"granate"\
                       ,"material":MAT_MISC_JEWEL])
#define BERGSTAT      (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen das Boese."\
                       ,"defend_factor":1.5\
                       ,"dam_type":DT_UNHOLY\
                       ,"plural":"bergkristalle"\
                       ,"material":MAT_QUARTZ])
#define DIAMANTSTAT   (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Explosionen."\
                       ,"defend_factor":2.0\
                       ,"dam_type":DT_EXPLOSION\
                       ,"plural":"diamanten"\
                       ,"material":MAT_DIAMOND])
#define AMETHYSTSTAT  (["info":"Diese Ruestung verleiht einen besonderen Schutz"\
                        "."\
                       ,"defend_factor":1.0\
                       ,"dam_type":DT_SLASH\
                       ,"plural":"amethyste"\
                       ,"material":MAT_AMETHYST])
#define ZIRKONSTAT    (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen Elektrizitaet."\
                       ,"defend_factor":2.0\
                       ,"dam_type":DT_ELECTRIC\
                       ,"plural":"zirkone"\
                       ,"material":MAT_MISC_JEWEL])
#define TURMALINSTAT  (["info":"Diese Ruestung verleiht einen besonderen Schutz "\
                        "gegen das Gute."\
                       ,"defend_factor":1.5\
                       ,"dam_type":DT_HOLY\
                       ,"plural":"turmaline"\
                       ,"material":MAT_MISC_JEWEL])
/*#define STAT (["info":""\
                       ,"defend_factor":\
                       ,"dam_type":\
                       ,"plural":""\
                       ,"material":MAT_])*/
