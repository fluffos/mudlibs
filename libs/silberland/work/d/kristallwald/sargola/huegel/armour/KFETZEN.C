/*
***********************************************
** Ein Fetzen fuer den Untoten		*
** 				            *
** date: 12-06-97 by Sargola@Silberland        *
** Email: a9504778@unet.univie.ac.at         *
***********************************************
**
** Updates:       :      
** Updates:       :      
** Updates:       :      
** 
*/

#define P_WEAR_FUNC "do_wear"

inherit "std/armour";
#include <properties.h>
#include <combat.h>
#include <armour.h>
#include <language.h>
#include "../def.h"

ohnmacht();		//man faellt in ohnmacht
regain();		//man erholt sich wieder
get_ill();			//man zieht den fetzen an und wird eventuell krank
string *messages;


void create()
{
   if (!is_clone(this_object())) return;   ::create();
  

   messages= 
	({	"Deine Haut faengt fuerchterlich zu jucken an.",
		"Rote Flecken breiten sich am ganzen Koerper aus.",
		"Kleine und groessere Hautfetzen loesen sich ab.",
		"Du beginnst Dich hektisch zu kratzen.",
		"Du denktst . o 0 (ob das an dem Fetzen lag?)",
		"Du erkennst, dass Du die Kretze haben musst.",
		"Du kratzt Dir mit den Naegeln Deine Arme auf.",
		"Du kratzt Dich, die Reizung wird dadurch jedoch nur schlimmer."});

   SetProp(P_SHORT, "Ein Fetzen");
   SetProp(P_LONG,
      "Ein ausgerissenener, dreckiger, abgeschnuddelter, zerfetzter Fetzen, den man "
	+"sich zur Not um den Oberkoerper wickeln kann. Ein seltsam strenger Geruch "
	+"geht von ihm aus. Er hat schon viele dunkle und gelbliche Flecken. Was das "
	+"wohl war...\n");

  AddDetail("flecken",
	"Eine Menge eingetrocknete Flecken sind auf dem Fetzen verteilt. Du kannst "
	+"roetliche bis braune Flecken entdecken, das muss wohl Blut sein. Die "
	+"duenkleren bis schwarzen Flecken kannst Du nicht zuordnen, die gelblichen "
	+"scheinen von Eiter oder aehnlichen Substanzen zu stammen.");

  AddDetail(({"stelle","menge"}),
	"Du findest kaum eine Stelle an dem Fetzen, wo nicht ein Fleck waere.");

  AddDetail("blut",
	"Es hat eine braun-roetliche Faerbung, ist aber schon lange vertrocknet.");

  AddDetail(({"farbe","faerbung"}),	
	"Die Flecken sind schon sehr eintegrocknet und von dunkelroter bis brauner "
	+"Farbe");

  AddDetail("eiter",
	"Sicher bist Du Dir nicht, aber woher koennten sonst so gelbliche Flecken "
	+"kommen?");

  AddDetail("substanzen",
	"Sei lieber vorsichtig mit dem Fetzen, wer weiss, welche Krankheiten er aus"
	+"loesen kann...");

  AddDetail("krankheiten",
	"Pass auf, dass Du Dir keine holst..");

  AddDetail("geruch",
	"Vielleicht solltest Du daran riechen...");

  SetProp(DEFAULT_SMELL, #'ohnmacht);
  //AddSmell(DEFAULT_SMELL,#'ohnmacht);

   SetProp(P_NAME, "Fetzen");
   AddId(({ "fetzen"}));
   SetProp(P_WEIGHT, 300);
   SetProp(P_VALUE, 100);
   SetProp(P_MATERIAL, MAT_CLOTH);
   SetProp(P_ARMOUR_TYPE, AT_ARMOUR );
   SetProp(P_GENDER, MALE);
   SetProp(P_AC, 2);  
   SetProp(P_WEAR_FUNC, TO);
}

ohnmacht()
{
	tell_object(TP, "Du riechst an dem Fetzen und erkennst schnell Deinen Fehler..."
	+"Dir wird schwarz vor den Augen...");
	(clone_object(OBJ+"ohnmacht"))->move(TP);
	if(find_call_out("regain")==-1)
		call_out("regain",5);
}

regain()
{
	tell_object(TP, "Langsam kommst Du wieder zu Dir...noch immer den stechenden "
		+"Geruch in der Nase");
	(present("\nohnmacht",TP))->remove();
	return "";
}

int do_wear(string str, int silent)
{
	::do_wear(str, 1);
	if(!present("\nkretze",TP))
		(clone_object(OBJ+"kretze"))->move(TP);

	return 1;
}
