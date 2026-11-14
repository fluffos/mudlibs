
#include "../directions.h"
 
#define P_INT_SHORT_KUHWEIDE                                            \
  SetProp(P_INT_SHORT, "Auf einer Kuhweide")

#define DET_KUHWEIDE                                                    \
  SetProp(P_LIGHT, 1);                                                  \
  AddDetail( ({"sonne", "himmel"}),                                     \
    "Vom Himmel lacht die Sonne herunter.");                            \
  AddDetail( ({"huegellandschaft", "landschaft"}),                      \
    QueryProp(P_INT_LONG) );                                            \
  AddDetail( ({"boden", "grund", "huegelboden"}),                       \
    "Der Huegelboden ist fruchtbar und saftiggruen. Die Wiese wird"     \
    " als Weide genutzt, tatsaechlich kannst Du in der Naehe einen"     \
    " Hirtenjungen mit seiner Kuhherde sehen.");                    \
  AddDetail( ({"weg", "pfad", "huegelweg", "huegelpfad"}),              \
    "Hier gibt es keinen Weg, denn Du stehst mitten auf der Weide.");\
  AddDetail( ({"kuhherde", "herde", "hirte", "junge", "hirtenjunge"}),  \
    "Da steht doch tatsaechlich ein Hirtenjunge und huetet eine"      \
    " Herde Kuehe, die friedlich auf der Wiese grasen.");             \
  AddDetail( ({"kuehe"}), \
    "Viele Kuehe sind auf dieser Weide.");\
  AddDetail( ({"kuh"}), \
    "Leider ist gerade keine Kuh in Deiner Naehe.");\
  AddDetail( ({"kuhweide", "weide", "wiese", "gras", "viehfutter"}), \
    "Das Gras waechst saftiggruen auf der Wiese, kraftstrotzend und"  \
    " vorzueglich als Viehfutter geeignet. Ab und zu wird das Gruen"  \
    " der Wiese vom Braun eines Kuhfladens unterbrochen.");           \
  AddDetail( ({"gruen", "braun"}),                                      \
    "Das Gruen ist das saftige Gras. Das Braun ist wohl etwas"        \
    " Anderes.");\
  AddDetail( ({"kuhfladen", "fladen",  "kot", "kothaufen"}),            \
    "Ganz normale Kuhfladen, wie man sie auf jeder Kuhweide findet.");  \
  AddDetail( ({"zaun"}),\
    "Die Weide ist duch einen Zaun abgegrenzt, damit die Kuehe die "\
    "Weide nicht verlassen koennen. Der Zaun besteht aus einfachen "\
    "Holzbrettern.");\
  AddDetail( ({"holzbretter", "bretter", "brett", "holzbrett"}),\
    "Die Holzbretter bilden - aneinandergereiht - den Zaun der Weide. "\
    "Teilweise sind die Bretter schon recht alt und morsch.");\
  AddSmell( ({DEFAULT_SMELL, "geruch", "duft", "luft", "landluft"}),    \
    "Es riecht nach Landluft... aber woher kommt dieser wuerzige "      \
    "Duft?");                                                           \
  AddSmell( ({"kuhfladen", "fladen", "kot", "haufen", "kothaufen"}), \
    "Uuuuuaaaaahhhhh.... konzentriert ist der Duft hier aber"         \
    " ungeniessbar!");                                                \

