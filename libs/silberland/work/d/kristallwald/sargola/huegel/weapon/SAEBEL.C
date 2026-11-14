/************************************************
** Krummsaebel der Grabunholde            *
** date: 25-01-97 by Sargola@Silberland     *
** Email: a9504778@unet.univie.ac.at         *
*************************************************
** Updates:       :      
** Updates:       :      
** Updates:       :      
** 
*/ 



inherit "std/weapon"; 
#include <properties.h> 
#include <combat.h> 
#include "../def.h"
 
create() 
{ 
  if (!is_clone(this_object())) return; 
  ::create(); 
  SetProp(P_SHORT,"Ein Krummsaebel"); 
  SetProp(P_LONG, 
        BS("Der wirklich krumme Saebel hat seinen Namen nicht umsonst. "
	+"Das Metall ist abgestumpft, genauso wie die Klinge. Der Griff "
	+"ist ziemlich abgenuetzt und schon an einigen Stellen abge"
	+"brochen.\n")); 

  AddDetail("metall",
	"Das muesste Eisen sein.");
  AddDetail("eisen",
	"Der Saebel besteht vermutlich aus Eisen.");
  AddDetail("klinge",
	"Sie ist schon oft benutzt worden, deswegen ist sei wahrschein"
	+"lich auch so abgenuetzt.");
  AddDetail(({"holz","griff"}),
	"Der Griff ist aus einem duenkleren Holz welches schon an einigen "
	+"Stellen abgesplittert ist.");
  AddDetail("stelle",
	"Du siehst, dass ein Spahn am Griff fehlt.");
  AddDetail("spahn",
	"Vor langer Zeit ist hier wohl einmal ein Spahn aus dem Griff "
	+"herausgebrochen. Nun ist nur mehr eine Rille, welche aber alle "
	+"scharfen Kanten verloren hat.");
  AddDetail("kanten",
	"Sie sind schon vom vielen Gebrauch abgenuetzt.");
  AddDetail("gebrauch",
	"Der Saebel wurde schon in vielen Kaempfen verwendet, da bist Du "
	+"Dir sicher."); 
  AddDetail("rille",
	"Die Rille im Griff stoert beim Kaempfen kaum.");

  SetProp(P_NAME, "Saebel"); 
  AddId( ({"saebel" })); 
  SetProp(P_ARTICLE, 1);
  SetProp(P_GENDER, MALE); 
  SetProp(P_WC, 115);
  SetProp(P_WEIGHT, 1300);      // in gramm 
  SetProp(P_VALUE, 500);       
 
  SetProp(P_DAM_TYPE, ({DT_SLASH}) );
  SetProp(P_WEAPON_TYPE, WT_SWORD); 
  SetProp(P_NR_HANDS, 1); 
}
 
