//seepferde.h

#include "/d/wasser/cirion/water.h"

#ifndef SEEPFERDEHOME
#define SEEPFERDEHOME WHOME"/seepferde"
#endif
#ifndef OBJ
#define OBJ SEEPFERDEHOME"/obj"
#endif
#ifndef ROOM
#define ROOM SEEPFERDEHOME"/room"
#endif
#ifndef NPC
#define NPC SEEPFERDEHOME"/npc"
#endif
#define SEQ SEEPFERDEHOME"/seq"
#define WIZNAME "cirion"
#define SEEPFERD NPC"/seepferd"

#define LOOP ROOM"/loop"

#define ARGAUF {"auf seepferd"\
                }
#define ARGAB  {"von seepferd","von seepferd heruntet","von seepferd runter",\
                "runter","herunter","hinab"}
        
#define LOCATIONS (["earost":ROOM"/earost_rmhn","riff":ROOM"/riffd3-1","workroom":"/players/cirion/workroom"])        
#define FILE_NAMES ([ROOM"/earost_rmhn":"earost",ROOM"/riffd3-1":"riff","/players/cirion/workroom":"workroom"])
#define DOCKED -1!=member(m_indices(FILE_NAMES),file_name(MENV))

#define CHANGEROOM "CHR"
#define CHANGETEMP "CHT"
#define MESSAGE "MSG"
#define SPECIALEVENT "SPE"

#define ALL_EVENTS ({CHANGEROOM,CHANGETEMP,MESSAGE,SPECIALEVENT})

#define SEEPFERDID "\nciseseepferd"
#define K *1000

#define RANDOM_MESSAGES \
  ({"In einiger Entfernung schwimmt ein riesiger Wal vorbei."\
   ,"In der Ferne glaubst Du einige Haie erkennen zu koennen."\
   ,"Du glaubst in der Ferne die Lichter einer Stadt zu erkennen."\
   ,"Das Seepferd schwimmt an einem seltsam geformten Felsen vorbei."\
   ,"Ihr schwimmt mitten durch einen Schwarm bunter Fische."\
   ,"Ein Schwarm von Walen schwimmt ganz nah an Euch vorbei."\
   ,"Du kannst ueber Dir einen Schwarm Delphine erkennen, die eine Zeitlang mit Euch schwimmen."\
   ,"Ein seltsamer, kugelfoermiger Fisch schwimmt an Dir vorbei."\
   ,"Eine riesige Qualle kommt von oben herabgesunken."\
   ,"Ein Schwarm, kleiner leuchtender Fische verfolgt Euch."\
   ,"Ihr schwimmt mitten durch einen Schwarm kleiner, feuerroter Quallen."\
   ,"Du erkennst ein seltsames, blaeuliches Leuchten in der Ferne, doch bald ist es wieder verschwunden."\
   ,"Du erkennst in der Ferne ein seltsames Blitzen."\
   ,"Du hoerst einen seltsamen, tiefen Klang, aehnlich einem Horn, der aus der Ferne kommt und langsam verhallt."\
   ,"Du meinst den wundersamen Klang von Instrumenten zu hoeren, kannst aber nichts davon sehen."\
   ,"Euch kommt ein anderes, unberittenes Seepferd entgegen."\
   ,"Ihr schwimmt mitten durch einen Schwarm kleiner Seepferdchen."\
   ,"Ein anderes, berittenes Seepferd schwimmt in einiger Entfernung vorbei."\
   ,"Ein seltsames, schwarzes Seepferd schwimmt in der Ferne vorueber."\
   ,"Ein kleiner, leuchtender Fisch schwimmt unter Dir vorbei."\
   ,"Ein Schwarm kleiner Fische mit seltsamen, langen Fuehlern schwimmt vorueber."\
   ,"Du glaubst, in der Ferne die Ruine eines Gebaeudes zu erkennen."\
   ,"Einige, seltsame Wasserpflanzen treiben vorbei."\
   ,"Eine Wolke von Plankton treibt vorbei."\
   ,"Einige bunte Blueten von seltsamen Wasserpflanzen treiben vorbei."\
   ,"Ein Tintenfisch schwimmt in der Ferne vorueber."\
   ,"Du kannst in der Ferne einen grossen Oktopus erkennen."\
   ,"Ein kleiner Oktopus kommt euch entgegengeschwommen."\
   ,"Eine Krake schwimmt in einiger Entfernung vorueber."\
   ,"Du glaubst in der Ferne eine riesengrosse Krake zu erkennen."\
   ,"Ihr schwimmt durch einen Bereich, in dem das Wasser eine dunklere Farbe zu haben scheint."\
   ,"Ihr schwimmt durch einen Bereich, in dem das Wasser eine hellere Farbe zu haben scheint."\
   ,"Von oben faellt ein heller Lichtstrahl herab, doch im naechsten Moment ist er wieder verschwunden."\
   ,"In der Naehe treibt eine seltsame Wolke hellgruen leuchtender kleiner Punkte vorbei."\
   ,"Ein grosser Raubfisch jagt in der Naehe einem Schwarm kleiner Fische hinterher."\
   ,"Weit ueber Dir schwimmt traege eine grosse Meeresschildkroete."\
   ,"In der Ferne kannst Du einen messingfarbenen Wasserdrachen durch das Wasser gleiten sehen."\
   ,"Eine gewaltige Seeschlange schwimmt in der Ferne vorueber."\
   ,"Ein seltsames, helles Leuchten schwimmt eine Zeitlang vor Euch her."\
    })

#define ENV_MESSAGES \
  ([\
  "wald":\
  ({"Zwischen den Baeumen meinst Du ein kleines Haus zu erkennen."\
   ,"Zwischen den Baeumen tummeln sich einige kleine Fische."\
   ,"Hier scheinen einige der Baeume gefaellt worden zu sein."\
   ,"Ihr schwimmt unter einigen sehr niedrigen Baeumen durch."\
   ,"Beinahe haettest Du grade einen tief haengenden Ast ins Gesicht bekommen."\
   ,"Zwischen den Baeumen erkennst Du eine kleine Lichtung."\
   ,"Zwischen den Baeumen weiden einige kleinere Seepferdchen."\
   ,"Auf einem besonderns grossen Baum erkennst Du eine kleine Baumhuette."\
   ,"Zwischen den Baeumen windet sich in einiger Entfernung ein kleiner Weg."\
   ,"Ihr schwimmt durch einen schmalen Durchlass zwischen hohen, dunkelgruenen Baeumen."\
    })\
 ,"tiefsee":\
  ({"Tief unten aus der Dunkelheit hoerst Du ein Droehnen."\
   ,"Tief unter Dir meinst Du in der Dunkelheit eine Riesenkrake zu erkennen."\
   ,"Aus der Tiefe steigt ein riesiger Blauwal auf und verschwindet in Richtung der Wasseroberflaeche."\
   ,"Weit unter Dir erkennst Du einen Schwarm riesiger Fische."\
   ,"Weit unter Dir erkennst Du ein schwaches Leuchten."\
    })\
 ,"krater":\
  ({"Am Boden des Kraters bildet sich ein Loch, aus dem ein wenig Lava stroemt, die jedoch rasch wieder erkaltet."\
   ,"Einige Blaeschen steigen vom Grund des Kraters auf."\
   ,"Eine riesengrosse Blase steigt vom Grund des Kraters auf."\
   ,"Du erkennst einige kleine Fische, die sich im warmen Wasser am Grund des Kraters tummeln."\
    })\
 ,"felsspalte":\
  ({"Am oberen Rand der Spalte meinst Du eine Gestalt auszumachen."\
   ,"Tief unten in der Spalte meinst Du ein schwaches Licht zu erkennen."\
   ,"Vor euch kommt eine Stelle in Sicht, an der die Waende ueber euch zusammentreffen und so eine Art Torbogen bilden, unter dem ihr durchschwimmt."\
   ,"Ihr kommt durch eine etwas breitere Stelle innerhalb der Spalte."\
   ,"Ihr schwimmt durch eine sehr schmale Passage der Spalte."\
   ,"Ihr schwimmt so nah an die eine Felswand heran, dass Du sie mit den Haenden beruehren koenntest."\
    })\
 ,"wiese":\
  ({"Ein ganzer Schwarm kleiner Fische schwimmt durch die Wiese."\
   ,"Die Seegraeser wiegen sich sanft in der Stroemung."\
   ,"Einige Seepferde grasen seitlich von euch."\
   ,"Ihr kommt ueber ein Feld mit riesigen Blueten."\
   ,"Eine Bluete reisst vom Boden ab und beginnt nach oben zu steigen."\
   ,"Ein grosser Krebs krabbelt durch die Wiese unter Euch."\
    })\
 ,"gebirge":\
  ({"In einem schmalen Seitental meinst Du eine kleine Huette zu erkennen."\
   ,"Auf einem der Berge meinst Du einen kleinen Schrein zu erkennen."\
   ,"Ihr schwimmt ueber einen kleinen Gebirgskamm."\
   ,"Ihr schwimmt durch ein kleines Gebirgstal."\
   ,"Rechts taucht ein voellig bewaldeter Berg auf."\
   ,"Aus einem Seitental schwimmt ein riesiger Schwarm kleiner bunter Fische."\
    })\
    ])