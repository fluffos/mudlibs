/*
***********************************************
** dorf.h               *
** Beschreibungs-File fuer das Dorf           *
** date: 20-03-97 by Sargola@Silberland     *
** Email: a9504778@unet.univie.ac.at         *
***********************************************
**
** Updates:       :      
** Updates:       :      
** Updates:       :      
** 
*/


#define STANDARD1							\
AddDetail( ({"baeume","baum"}),						\
	BS("Maechtige, sicherlich sehr alte Eichen wachsen um Dich "	\
	"herum. Besonders auffaellig sind die glitzernde Rinde und "	\
	"die Blaetter, die fast durchsichtig schimmern."));		\
									\
AddDetail("rinde",							\
	BS("Die Rinde ist uneben, rauh, laesst sich aber schwer "	\
	"abreiben. Sie glitzert im Schein der Sonne."));		\
									\
AddDetail("himmel",							\
	BS("Der Himmel schimmert durch die Baumkronen und mischt sich "	\
	"mit den silber-kristallenen Farben der Blaetter."));		\
									\
AddDetail( ({"farbe","farben"}),					\
	BS("Alles hier ist in milchig-weisses Licht getaucht. Die "	\
	"Blaetter glitzern im Schein der Sonne. Irgendwie ist es hier "	\
	"maerchenhaft schoen."));					\
									\
AddDetail( ({"licht","sonne","schein","sonnenschein","strahlen","sonnenstrahlen"}),	\
	BS("Einzelne Sonnenstrahlen dringen durch die Decke aus "	\
	"Aesten und verwandeln durch das hundertfache Brechen "		\
	"alles in eine unwirkliche glitzernde Umgebung."));		\
									\
AddDetail( ({"kronen","krone","baumkrone","baumkronen"}),		\
	BS("Weit ueber Dir schimmern die letzten und hoechsten Aeste "	\
	"der kristallenen Eichen."));					\
									\
AddDetail( ({"ast","aeste", "decke","astdecke","stamm"}),		\
	BS("Die Aeste treiben waagrecht aus dem Stamm, wachsen aber "	\
	"bald in den Himmel und bilden so eine schuetzende Kapsel."));	\
									\
AddDetail(({"kapseln","kapsel"}),					\
	BS("Die Kapsel wird durch die nach oben wachsenden Aeste "	\
	"gebildet."));							\
									\
AddDetail( ({"blaetterdach","blatt","blaetter"}),			\
	BS("Sie sehen genauso aus, wie die vielen anderen Blaetter "	\
	"von Eichen, die Du schon gesehen hast. Nur sind diese hier "	\
	"aus Kristall."));						\
									\
AddDetail("eichen",							\
	 BS("Der Kristallwald besteht aus uralten, gerade ge"		\
	 "wachsenen Eichen. Elfen verstehen es seit je her, auf "	\
	 "solchen Baeumen zu leben."));					\
									\
AddDetail("brechen",							\
	BS("An den Blaettern und Aesten brechen sich die Strahlen "	\
	"der Sonne und tauchen alles in diffuses Licht."));		\
									\
AddDetail("umgebung",							\
	BS("Um Dich herum siehst Du riesige Eichen aus denen "		\
	"ausladende Aeste wachsen. Die Sonne dringt durch das "		\
	"Blaetterdach und taucht die Umgebung in milchiges Licht."));	\
									\
AddDetail( ({"elessar","stadt","elfenstadt"}),				\
	BS("Du stehst in Elessar, der Stadt der Elfen."));


#define STANDARD2							\
AddDetail(({"talane","talan"}),						\
	BS("Die Holzplattform, auf der Du stehst, nennen die Elfen "	\
	"Talan."));							\
									\
AddDetail( ({"bruecke","bruecken","haengebruecken","seilbruecken"}),	\
	BS("Sie verbinden die einzelnen Baeume miteinander und sind "	\
	"vom Boden aus nicht zu erkennen. Zwei starke Straenge aus "	\
	"Seil halten die Bretter zusammen, ein weiteres Seil dient "	\
	"als Haltevorrichtung."));					\
									\
AddDetail(({"seile","seil"}),							\
	BS("Es ist ein vierfach verdrehtes Seil aus kraeftigem "	\
	"Hanf."));							\
									\
AddDetail(({"ausgangsmaterial","hanf"}),				\
	BS("Hanf ist das Ausgangsmaterial fuer Seile."));		\
									\
AddDetail( ({"strang","straenge"}),					\
	BS("Zwei fixieren die Bretter, auf denen man von Plattform "	\
	"zu Plattform geht, eines ist zum Festhalten. Obwohl die "	\
	"Elfen das meist nicht brauchen."));				\
									\
AddDetail( ({"holz","holzbretter","bretter"}),					\
	BS("Weissliche, grob zugeschnittene Holzbretter, auf denen "	\
	"die Elfen leichtfuessig umherlaufen."));			\
									\
AddDetail(({"haltevorrichtung","halt","vorrichtung"}),			\
	BS("Selbst die sicheren Elfen benoetigen hin und wieder "	\
	"ein Seil zum Halt."));						\
									\
AddDetail( ({"wald","kristallwald"}),					\
	BS("Du stehst doch im Kristallwald!"));				\
									\
AddDetail("kristall",							\
	BS("Alles hier ist aus Kristall..."));				\
									\
AddSound (DEFAULT_SOUND,						\
	BS("Du hoerst Voegel singen und irgendwo spielen Kinder."));	\
									\
AddSound ( ({"kinder"}),						\
	BS("Sie spielen und kreischen dabei."));			\
									\
AddSound ( "voegel",							\
	BS("Sie zwitschern ein gar lustig Lied..."));			\
									\
AddSound ("lied",							\
	BS("Zwitscher, Zwitsch.... Fieeep.... Zwitsch..."));		\
									\
AddDetail(({"elfen","elessar","elfenstadt","stadt"}),			\
	BS("Du bist in der Elfenstadt Elessar."));			\
									\
AddSmell(DEFAULT_SMELL,							\
	BS("Du kannst die frische, intensive Luft des Waldes "		\
	"riechen."));							\
									\
AddSmell( ({"eichel","luft"}),						\
	BS("Du ziehst verzueckt den Duft in Deine Nase und weisst "	\
	"ploetzlich, warum die Elfen immer im Wald lebten."));		\
	 								\
AddSmell("nase",							\
	BS("Das ist bisher noch niemandem geglueckt..."));		\
									\
AddSmell(({"baum","baeume","stamm","baum","rinde"}),			\
	BS("Du riechst duftendes, frisches Holz. Als Elf muss man "	\
	"sich hier wohlfuehlen."));					\
									\
AddDetail("rand",							\
	BS("Du solltest Dich nicht zu weit ueber den Rand wagen.")) ;	


//***************************************
//Raeume ueber dem Weg
//***************************************
#define BODEN_WEG							\
AddDetail ("boden",							\
	BS("Du stehst auf einer stabilen Holzplattform, welcher in "	\
	"Astverzweigungen gezimmert wurde. Du blickst ueber den Rand "	\
	"des Bodens und siehst weit unter Dir einen Waldweg."));	\
									\
AddDetail( ({"plattform","holzplattform","plateau","holzplateau"}),	\
	BS("Die Plattform besteht aus kristallinem Holz und ist ge"	\
	"schickt in den Baum gezimmert. Im Zentrum ragt der Stamm "	\
	"durch den Boden."));						\
									\
AddDetail(({"mitte","zentrum"}),					\
	BS("Meist in der Mitte ragt der Stamm durch den Talan."));	\
									\
AddDetail("astverzweigungen",						\
	BS("In jedem der Baeume findet sich irgendwo ein Boden aus "	\
	"Holz, auf dem groessere oder kleinere Huetten gebaut sind."));	\
									\
AddDetail( ({"huette","huetten"}),					\
	BS("Einfache, aber gemuetliche Huetten aus Holz. Auf fast "	\
	"allen Baeumen findest Du solche."));				\
									\
AddDetail ( ({"waldweg","weg"}),					\
	BS("Er fuehrt mal links, mal rechts durch die Baeume."));	

//********************************************
//Boden ohne Weg
//********************************************
#define BODEN_OHNE_WEG							\
									\
RemoveDetail("boden");							\
									\
AddDetail ("boden",							\
	BS("Du stehst auf einer stabilen Holzplattform, welcher in "	\
	"Astverzweigungen gezimmert wurde. Du blickst ueber den Rand "	\
	"des Bodens und siehst weit unter Dir dichten Wald."));		\
									\
AddDetail( ({"plattform","holzplattform","plateau","holzplateau"}),	\
	BS("Die Plattform besteht aus kristallinem Holz und ist ge"	\
	"schickt in den Baum gezimmert. Im Zentrum ragt der Stamm "	\
	"durch den Boden. Sie werden durch Bruecken verbunden."));	\
									\
AddDetail("zentrum",							\
	BS("Zumindest bei gerade gewachsenen Baeumen ist der Stamm "	\
	"in der Mitte der Plattform."));				\
									\
AddDetail("astverzweigungen",						\
	BS("In jedem der Baeume findet sich irgendwo ein Boden aus "	\
	"Holz, auf dem groessere oder kleinere Huetten gebaut sind."));	\
									\
AddDetail( ({"huette","huetten"}),					\
	BS("Einfache aber gemuetliche Huetten aus Holz. Auf jedem "	\
	"der Baeume findest Du solche."));				\
									\
AddDetail ( ({"wald"}),							\
	BS("Hier ist sicherlich noch kein Abenteurer durch..."));	\
									\
AddDetail("abenteurer",							\
	BS("Du siehst hier keine Abenteurer!"));
