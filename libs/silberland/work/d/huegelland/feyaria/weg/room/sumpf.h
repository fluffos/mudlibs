// /d/gebirge/feyaria/weg/room/sumpf.h
// Allgemeine Details fuer den Sumpf
// 1996-12-27 Feyaria@SilberLand

#define  P_INT_SHORT_SUMPF 						\
  SetProp(P_INT_SHORT, "Mitten im Sumpf");

#define SUMPF_DETAILS							\
  AddDetail( "sumpf",							\
    "Der Sumpf ist wirklich sehr unangenehm. Deine Kleidung und vor "	\
    "allem Deine Schuhe und Deine Hose sind mit Schlammspritzern "	\
    "uebersaet. Aber das ist nur ein kleines Uebel, denn mit jedem "	\
    "Schritt steigt die Gefahr, im Boden zu versinken.");		\
  AddDetail( ({"boden", "schlamm"}),					\
    "Der Boden ist schlammig und sumpfig, aber was kann man anderes "	\
    "von einem Sumpf verlangen. Viel schlimmer ist, dass Du nie "	\
    "sicher weisst, wie tief Deine Beine einsinken, bis Du festen "	\
    "Boden erreichst.");						\
  AddDetail( ({"schlammspritzer", "spritzer", "kleidung"}),		\
    "Es ist fraglich, ob Du Deine Sachen jemals wieder richtig sauber "	\
    "bekommst, aber das ist Nebensache. Hauptsache ist, hier wieder "	\
    "raus zu kommen.");							\
  AddDetail( "weg",							\
    "Leider kannst Du den Weg nirgends sehen. Du weisst auch leider "	\
    "nicht mehr, in welcher Richtung der Weg ungefaehr liegt.");

#define SUMPF_DETAILS2							\
  AddDetail( ({"richtung", "richtungen"}),				\
    "Jede Richtung ist so gut wie jede andere.");			\
  AddDetail( ({"orientierungspunkt"}),					\
    "Hier ist kein Orientierungspunkt. Nur Schilf so weit das Auge "	\
    "reicht. Wenn Du doch nur den Weg sehen koenntest. :-(");		\
  AddDetail( ({"himmel"}),                                              \
    "Der Himmel ist ueber Dir, gibt Dir aber auch keinen "              \
    "Orientierungspunkt." );                                            \
  AddDetail( ({"schilf", "guertel", "schilfguertel"}),			\
    "Du stehst mitten in einem breiten Schilfguertel, hinter dem Du "	\
    "leise Wasser plaetschern hoerst. Das Schilf ist so hoch, dass Du "	\
    "nicht hinaussehen kannst.");					\
  AddDetail( ({"wasser", "plaetschern"}),				\
    "Du kannst von hier aus kein Wasser sehen, aber Du hoerst es "	\
    "deutlich im Schilf plaetschern. Weiter draussen muss wohl ein "	\
    "See sein.");							\
  AddDetail( ({"see"}),							\
    "Der See muss wohl weiter draussen sein, Du kannst nur das "	\
    "Plaetschern des Wassers hoeren.");

#define SUMPF_SENSE							\
  AddSound( DEFAULT_SOUND,						\
    "Du hoerst das Plaetschern des Wassers im Schilf.");		\
  AddSound( ({"wasser", "plaetschern"}),				\
    "Das Wasser plaetschert leise. Weiter draussen muss wohl ein "	\
    "See sein.");							\
  AddSmell( ({DEFAULT_SMELL, "sumpf", "moder"}),			\
    "Der Sumpf riecht etwas modrig.");
