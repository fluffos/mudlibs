// /d/dschungel/feyaria/tijara/room/keller.h
// Allgemeine Details fuer den Keller
// 27-12-96  Feyaria@SilberLand
// KELLER_SENSE: 1 Detail, 4 Smells, 5 Sounds
// KELLER_DETAILS: 12 Details
// WEIN_DETAILS : 5 Details
// LAGER_DETAILS: 3 Details
// VORRAETE_DEETAILS: 7 Details

#define KELLER_SHORT							\
  SetProp( P_INT_SHORT, "In einem duesterem Keller");
#define WEIN_SHORT							\
  SetProp( P_INT_SHORT, "Im Weinkeller");
#define VORRAETE_SHORT							\
  SetProp( P_INT_SHORT, "In einem kleinen Vorratsraum im Keller");
#define LAGER_SHORT							\
  SetProp( P_INT_SHORT, "In einem Lagerraum im Keller"); 

#define KELLER_SENSE							\
AddSmell( ({DEFAULT_SMELL, "luft", "keller", "gestank"}),		\
  "Die Luft im Keller riecht stickig und abgestanden.");		\
AddSmell( ({"ratten", "ratte", "kellerratte", "kellerratten"}),		\
  "Die Ratten kannst Du nicht riechen, Du bist ja kein Spuerhund.");	\
AddDetail( ({"hund", "spuerhund"}),					\
  "Einen Spuerhund haettest Du jetzt wohl gerne. :)");			\
AddSmell( ({"hund", "spuerhund"}),					\
  "Einen Spuerhund haettest Du jetzt wohl gerne. :)");			\
AddSmell( ({"kot", "rattenkot"}),					\
  "Der Rattenkot riecht fast ueberhaupt nicht, dazu ist der viel zu "	\
  "klein.");								\
AddSound( ({DEFAULT_SOUND, "keller", "getrappel"}),			\
  "Du hoerst das Getrappel der Ratten. Etwas leiser kannst Du auch "	\
  "das Knabbern und Piepsen hoeren. Es sind sicher viele Ratten hier "	\
  "unten im Keller.");							\
AddSound( ({"ratte", "ratten", "geraeusche"}),				\
  "Du hoerst das Getrappel der Ratten aus allen Richtungen. In diesem "	\
  "Keller kannst Du leider nicht bestimmen, von wo genau die "		\
  "Geraeusche kommen.");						\
AddSound( ({"knabbern"}),						\
  "Es hoert sich an, als ob die Ratten alle Lebensmittel anknabbern "	\
  "wuerden.");								\
AddSound( ({"lebensmittel", "schreie", "schmerzensschreie",		\
            "schmerzen"}),						\
  "Obwohl die Lebensmittel staendig gebissen werden, kannst Du ihre "	\
  "Schmerzensschreie nicht hoeren.");					\
AddSound( ({"piepsen"}),						\
  "Die Ratten piepsen auch ziemlich. Vielleicht haben sie Dich ja "	\
  "schon erkannt und sind auf der Flucht.");

#define KELLER_DETAILS							\
SetProp(P_INDOORS,1);							\
SetProp(P_ENVIRONMENT,([ENV_TEMPERATURE: 25, ENV_TERRAIN: TT_CAVE]) ); 	\
AddDetail( ({"keller", "kellergewoelbe", "gewoelbe"}),			\
  "Du befindest Dich im Keller unter der Villa des Gouverneurs. "	\
  "Die Waende sind aus rohen Steinbloecken. Der Boden besteht aus "	\
  "festgestampftem Lehm. In dem duesteren Daemmerlicht kannst Du kaum "	\
  "mehr erkennen.");							\
AddDetail( ({"daemmerlicht", "licht"}),					\
  "Hier ist es sehr duester.");						\
AddDetail( ({"villa"}),							\
  "Die Villa des Gouverneurs ist genau ueber Dir.");			\
AddDetail( ({"gouverneur"}),                                            \
  "Dem Gouverneur gehoert dieser Keller.");                             \
AddDetail( ({"boden", "lehm"}),						\
  "Der Boden besteht aus festgestampftem Lehm. Hin und wieder liegt "	\
  "ein Stueck Rattenkot auf dem Boden.");				\
AddDetail( ({"kot", "stueck", "stuecke", "rattenkot"}),			\
  "Hier liegen nur wenige Stuecke Rattenkot herum. Trotzdem duerfte "	\
  "es eine ganze Menge Ratten in diesem Keller geben.");		\
AddDetail( ({"waende", "wand", "block", "stein", "bloecke", 		\
             "steinblock", "steinbloecke"}),				\
  "Die Waende sind aus rohen Steinbloecken gefertigt.");		\
AddDetail( ({"decke", "balken", "holzbalken"}),				\
  "Die Decke besteht aus Holzbalken.");					\
AddDetail( ({"holz"}),							\
  "Es handelt sich um ganz normales Holz von Dschungelbaeumen.");	\
AddDetail( ({"baeume", "baum", "dschungelbaum", "dschungelbaeume"}),	\
  "Die Dschungelbaeume wurden zu Holzbalken umgestaltet.");		\
AddDetail( ({"ratte", "kellerratte"}),					\
  "Es ist wohl gerade keine Ratte da, aber Du kannst ihr Getrappel "	\
  "und das Knabbern und Piepsen hoeren.");				\
AddDetail( ({"ratten", "kellerratten"}),				\
  "Die Kellerratten sind hier ueberall. Aber vielleicht kannst Du ja "	\
  "dieser Plage Herr werden.");						\
AddDetail( ({"plage"}),							\
  "So viele Ratten sind wirklich eine Plage.");
			
#define WEIN_DETAILS							\
AddDetail( ({"weinkeller", "teil"}),					\
  "Dieser Teil des Kellers ist der Weinkeller. Hier stehen ueberall "	\
  "Weinfaesser und Regale mit Weinflaschen herum. Der Gouverneur "	\
  "ist scheinbar ein Liebhaber von guten Weinen.");			\
AddDetail( ({"wein", "weine"}),						\
  "Der Wein wird hier in Flaschen und in Faessern gelagert.");		\
AddDetail( ({"faesser", "fass", "weinfass", "weinfaesser"}),		\
  "Die Faesser enthalten wohl die billigeren Weine.");			\
AddDetail( ({"flaschen", "flasche", "weinflaschen", "weinflasche"}),	\
  "In den Flaschen werden wohl die teuren Weine gelagert.");		\
AddDetail( ({"regal", "regale"}),					\
  "In den Regalen lagern viele Weinflaschen.");

#define LAGER_DETAILS							\
AddDetail( ({"kiste", "kisten", "truhe", "truhen"}),			\
  "In den Kisten und Truhen lagert der Gouverneur die wertvollen "	\
  "Gueter, die er als Steuer fuer sich behaelt. Daher ist er wohl "	\
  "so reich geworden. Einige der Kisten haben aber Loecher und sind "	\
  "angenagt. Vielleicht kann man ja eine der Kisten oeffnen.");		\
AddDetail( ({"loch", "loecher"}),					\
  "Die Loecher sind eindeutig durch die Ratten entstanden. Diese "	\
  "Ratten sind eine echte Plage.");					\
AddDetail( ({"gueter", "steuer", "steuern", "reichtum", "einnahmen"}),	\
  "Der Reichtum des Gouverneurs begruendet sich wohl auf die "		\
  "Einnahmen aus den Steuern, die auf die ein- und ausgefuehrten "	\
  "Gueter eingehoben werden.");

#define VORRAETE_DETAILS						\
AddDetail( ({"lebensmittel", "vorraete", "vorrat", 			\
             "lebensmittelvorrat", "lebensmittelvorraete"}),		\
  "Hier lagern viele Lebensmittel. Oel in Tonkruegen, gesalzener "	\
  "Fisch in grossen Tonnen, getrocknete Fruechte in Steigen und Mehl "	\
  "in Saecken. Die Ratten haben hier am wildesten gewuetet, denn "	\
  "fast alles ist angeknabbert.");					\
AddDetail( ({"oel", "krug", "kruege", "tonkrug", "tonkruege"}),		\
  "Viele Tonkruege sind umgestuerzt und an den Verschluessen "		\
  "angeknabbert.");							\
AddDetail( ({"verschluss", "verschluesse"}),				\
  "Die Verschluesse wurde von den Ratten angeknabbert.");		\
AddDetail( ({"tonne", "tonnen", "fisch", "fische", "salzfisch"}),	\
  "Auch die eingesalzenen Fische in den Tonnen wurden von den Ratten "	\
  "nicht verschont.");							\
AddDetail( ({"fruechte", "frucht", "steige", "steigen"}),		\
  "Die Steigen haben die Ratten schon fast bis auf die letzte Frucht "	\
  "leergefressen. Nur noch vereinzelt liegt eine angeknabberte Frucht "	\
  "einsam in einer Steige.");						\
AddDetail( ({"saecke", "sack", "mehl", "mehlsack", "mehlsaecke"}),	\
  "Bei den Mehlsaecken haben die Ratten am allerschlimmsten gewuetet. "	\
  "Fast alle Saecke sind durchloechert und das Mehl ist voellig "	\
  "aufgefressen. Nur einige weisse Flecken erinnern noch daran, dass "	\
  "hier frueher einmal Mehl gelagert wurde.");				\
AddDetail( ({"fleck", "flecken"}),					\
  "Die weissen Flecken erinnern noch daran, dass hier frueher einmal "	\
  "Mehl gelagert wurde.");

#define SCRIPT_DETAILS							\
AddSpecialDetails( ({"obwohl", "vielleicht", "gouverneurs", 		\
	"hier", "trotzdem",  "steinbloecken", "aber", "so", "solche",	\
        "details", "untersuch", "dieser", "kellers", "einige", 		\
        "tonkruegen", "saecken", "viele", "nur", "auch", "mehlsaecken"	\
         }),								\
   "NoScript");

#define WEIN_STEHLEN							\
int wein( string str)							\
{									\
  if( member( ({"wein", "flasche", "flaschen", "weinflasche", 		\
                "weinflaschen", "fass", "faesser", "weinfass",		\
                "weinfaesser"}), str) !=-1)				\
  {									\
    write("Du willst doch dem Gouverneur nicht seinen Wein stehlen?\n");\
    return 1;								\
  }									\
  return 0;								\
}
