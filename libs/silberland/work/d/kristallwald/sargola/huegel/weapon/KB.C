/*
************************************************* 
**  Klingenbrecher         			*	 
**						*
**						*
** Formel: (dex + str) / 5			*
**						*
** dex   str	%				*
** ===============				*
** 18    18     7				*
** 20    20     8				*
** 23    23     9				*
** 25    25    10				*
**						*
** date: 01-12-97 by Sargola@Silberland     	* 
** Email: a9504778@unet.univie.ac.at         	* 
************************************************* 
** Updates:       :       
** Updates:       :       
** Updates:       :       
**  
*/ 
 
 
inherit "std/weapon"; 
#include <properties.h> 
#include <combat.h> 
#include <language.h> 
#include "../def.h" 
 
create()       
{        if (!is_clone(this_object()))           return; 
        ::create(); 

        AddId (({"kb","brecher","klingenbrecher"})); 
 
        SetProp (P_SHORT, "Ein Klingenbrecher"); 
        SetProp (P_LONG, BS("Du hast eine der maechtigsten Waffen in der "
	+"Hand, die Du je gesehen hast - ein zweihaendiger Klingenbrecher. "
	+"Er hat eine aus Mithril gefertigte Klinge auf der einen Seite "
	+"und maechtige Zacken auf der anderen.")); 

	AddDetail(({"schneide","klinge"}),
	"Die Klinge ist aus Mithril und extrem widerstandsfaehig. Mit ihr "
	+"durchdringst Du jede Ruestung ...");

	AddDetail("mithril",
	"Ein zwergischer Werkstoff, aus dem die maechtigsten Waffen gefertigt "
	+"sind.");

	AddDetail("seite",
	"Der Klingenbrecher hat zwei: eine Klinge und eine mit Zacken.");

	AddDetail("zacken",
	"Die Zacken sind im Gegensatz zur Schneide aus schwarzem Metall. "
	+"Sie haben nur eine einzige Funktion: Verkeilt sich die Waffe "
	+"des Gegners in den Zacken kannst Du ihm damit entweder die Waffe "
	+"aushebeln oder gar deren Klinge brechen!");

	AddDetail("metall",
	"Du kannst Dir nicht vorstellen, aus welchem Material die Zacken "
	+"bestehen.");

	
        SetProp (P_NAME, "Klingenbrecher"); 
        SetProp (P_GENDER, MALE);  

        SetProp (P_WEIGHT, 850); 
        SetProp (P_VALUE, 14000); 
        SetProp (P_MATERIAL, ({MAT_IRON}) ); 
        SetProp (P_WEAPON_TYPE, WT_SWORD); 
        SetProp (P_DAM_TYPE, DT_SLASH); 
        SetProp (P_WC, 190); 
        SetProp (P_NR_HANDS, 2); 
	SetProp (P_HIT_FUNC, TO);
	SetProp (P_WIELD_RESTRICTIONS, ([A_DEX:18, A_STR:18]) );

}   


int HitFunc(object enemy)
{

	object weapon;
	string type;
	int dex, str, prz;
	if(!objectp(enemy)) return 0;

	weapon = enemy->QueryProp(P_WEAPON);
	if(!objectp(weapon)) return 0;

	type = weapon->QueryProp(P_WEAPON_TYPE);
	dex = TP->QueryAttribute(A_DEX);
	str = TP->QueryAttribute(A_STR);	
	prz = (dex+str) /5;
	
	if( (member( ({WT_KNIFE, WT_SWORD, WT_SPEAR}), type) != -1) && ( random(100) <= prz) )
	{
		tell_object(TP, "Du wehrst den Schlag des Gegners gekonnt "
		+"ab und brichst die Klinge!\n");
		weapon->remove(1);
		return 50+random(90);
	}
	return 100+random(90);
}