// /d/gebirge/feyaria/weg/room/schlucht.h
// Cheasy@AnderLand
// Feyaria@SilberLand

/** Schlucht **********************************************************/
#define CD_SCHLUCHT_WEIT						\
AddDetail( "schlucht",							\
  "Du erkennst eine Schlucht in der Ferne, die sich tief in den " 	\
  N_BERG "eingegraben hat, aber Du bist noch zu weit weg, um "		\
  "genaueres zu erkennen.");						\
AddDetail( ({"berg", N_BERG}),						\
  "Der " N_BERG "hat sehr zerklueftete Flanken. Eine Schlucht hat "	\
  "sich besonders tief in seine Flanken eingegraben, aber Du"		\
  " bist noch zu weit weg, um genaueres zu erkennen.");

#define CD_SCHLUCHT_OBEN						\
AddDetail( ({"schlucht", "abgrund", "grund"}),				\
  BS("Du stehst oberhalb einer tief in den Boden gegrabenen "		\
  "Schlucht. Du kannst den Grund nicht erkennen, aber es toent "	\
  "das Tosen tobender Wassermassen herauf.")+				\
  "Unbewusst trittst Du einen Schritt von der Kante zurueck.\n");	\
AddDetail( ({"wasser", "wassermassen"}),				\
  "Du kannst es nicht sehen, nur hoeren -- das allerdings laut"		\
  " und deutlich. Fuer Deinen Geschmack zu deutlich, der Abstieg"	\
  " koennte toedlich enden.");						\
AddDetail( "geschmack",							\
  "Na sowas -- seit 'ner Weile nix getrunken, aber immer noch"		\
  " dieser eklige Nachgeschmack im Mund. IGITTTT!");			\
AddDetail( ({"igit", "igitt", "igittt", "igitttt"}),			\
  "Dir ist speiuebel.\n");						\
AddDetail( ({"kante", "rand"}),						\
  "Jetzt erkennst Du, dass ein paar Spuren direkt zum Rand der "	\
  "Schlucht fuehren.");

#define CD_SCHLUCHT_ABSTIEG						\
AddDetail( ({"spuren", "spur"}),							\
  "Neben den ueblichen Schluchtgemsenspuren kannst Du auch "		\
  "undeutlich den Fussabdruck eines Hobbits erkennen.");

#define CD_SCHLUCHT_NIX							\
AddDetail( ({"spuren", "spur"}),							\
  BS("Du untersuchtst die Spuren sehr genau, findest allerdings nur"	\
     " ein paar Abdruecke der winzigen Hufe der Schluchtgemsen.")+	\
     "Entmutigt trittst Du vom Rand zurueck.\n");

#define CD_SCHLUCHT_UNTEN						\
AddDetail( ({"schlucht", "boden"}),					\
  BS("Es ist fast dunkel hier unten, nur ein schmaler Streifen"		\
     " Himmel ist ueber Dir zu erkennen. Unter Dir tost der Bach in"	\
     " seinem engen Bett. Du versuchst, nicht in die wilden"		\
     " Wassermassen zu fallen.\n"));					\
AddDetail( ({"streifen", "himmel"}),					\
  "Ueber Dir siehst Du hauptsaechlich steile Felswand. Zwischen "	\
  "diesen Waenden erkennst Du ein wenig Himmel, also befindest"		\
  " Du Dich nicht in einer Hoehle.");					\
AddDetail( ({"wasser", "wassermassen", "massen", "bach", "bett",	\
	     "bachbett"}),						\
  "Es ist schon erstaunlich, wie wild so ein kleiner Bach werden "	\
  "kann, wenn er nicht gemuetlich durch eine Ebene maeandrieren "	\
  "darf. Du faellst besser nicht hinein."));				\
AddDetail( "ebene",							\
  "ARGL. Du stehst in einer Schlucht. Von einer Ebene ist weit"		\
  " und breit nix zu sehen. Hast Du das jetzt verstanden, oder"		\
  " bist Du nur ein Script, das alles grossgeschriebene"		\
  " untersucht?"));

#define CD_SCHLUCHT_WAND						\
AddDetail( ({"schlucht", "wand", "fels", "felswand"}),			\
  "Du klammerst Dich verzweifelt an die Felswand. Ueber Dir geht"	\
  " es senkrecht nach oben, senkrecht unter Dir tost ein Bach."		\
  " Im Daemmerlicht kannst Du gerade noch so den naechsten Griff "	\
  "erkennen.");								\
AddDetail( ({"licht", "daemmerlicht"}),					\
  "Hier in halber Hoehe der Schluchtwand herrscht ein angenehmes "	\
  "Daemmerlicht. Nur Schade, dass hier nirgendwo genug Platz"		\
  " ist, um ein Bett aufzustellen, in dem Du ein wenig ausruhen "	\
  "koenntest.");							\
AddDetail( ({"bach", "baechlein"}),					\
  "Mit Mueh und Not kannst Du gerade noch weisse Gischt unter Dir "	\
  "ausmachen. Dort ist aus dem friedlichen Baechlein ein "		\
  "lebensgefaehrlich tosendes Gewaesser geworden. ");

#define CD_STEILWAND							\
AddDetail( ({"wand", "felswand"}),					\
  "An der senkrechten Felswand windet sich der Pfad in die Tiefe."	\
  " Dir graust bei der Vorstellung, dort hinunterzufallen. Du"		\
  " nimmst Dir vor, diesen Weg extrem vorsichtig zu benutzen.");	\
AddDetail( ({"pfad", "weg"}),						\
  "Der Weg hat hier gerade noch Ochsenkarrenbreite. Er windet"		\
  " sich entlang einer senkrechten Felswand nach unten. Beim"		\
  " Anblick des Wegs graust Dir: Er ist teils in die Wand"		\
  " gehauen, teils auf hoelzernen Pfaehlen auf Vorspruengen"		\
  " verankert. Gelaender oder andere Sicherheitsvorkehrungen"		\
  " fehlen voellig. Auf der einen Seite des Wegs ist die"		\
  " Felswand, auf der Anderen gaehnt der Abgrund.");			\
AddDetail( ({"karren", "wagen", "ochsen", "ochsenkarren"}),		\
  "Sei froh, dass Du keinen siehst! Wuerde Dir so etwas"		\
  " entgegenkommen, muesstest Du den ganzen Weg zuruecklaufen,"		\
  " weil hier kein Platz zum Ausweichen ist.");				\
AddDetail( ({"pfad", "weg"}),						\
  "Oh-oh... Du fuehlst Dich ueberhaupt nicht wohl hier. Auf der"	\
  " einen Seite eine glitschige, senkrechte, broeselige Fels- "		\
  "(???) wand, auf der anderen droht ein Abgrund. Du denkst,"		\
  " dass der kleinste Laut die Massen ueber Dir erschuettern"		\
  " koennte, und beschliesst sehr vorsichtig zu sein.");		\
AddDetail( ({"spuren", "karrenspuren", "kuhfladen", "fladen", \
             "spur", "karrenspur"}),		\
  "Auf dem Weg finden sich zwei parallel laufende Spuren der"		\
  " Raeder der Ochenkarren, dazwischen liegen hin und wieder mehr"	\
  " oder weniger frische Kuhfladen.");					\
AddDetail( ({"wand", "fels", "felswand"}),				\
  "Die Felswand besteht aus feuchtem, broeckeligem Buntsandstein."	\
  " Es sieht nicht sehr vertrauenerweckend aus. Du erinnerst Dich"	\
  " an das Warnschild am Wegrand und denkst, dass es voellig zu"	\
  " recht aufgestellt wurde. Hier koennte jeden Augenblick eine"	\
  " Geroellawine niedergehen.");					\
AddDetail( ({"geroell", "felsen", "brocken", "felsbrocken"}),		\
  "Ueber Dir haengen riesige felsbrocken und Geroell sehr instabil"	\
  " in der Felswand. Eine hastige Bewegung oder ein lauter Ruf"		\
  " koennte schon die Geroell-Lawine ausloesen.");			\
AddDetail( ({"abgrund", "tiefe"}),					\
  "Der Abrund gaehnt direkt neben dem Weg. Ein falscher Tritt, und"	\
  " Du stuerzt Dich zu Tode. Du solltest besser sehr vorsichtig"	\
  " sein auf diesem Pfad.");
