/************************************************ 
**  Schlegel         * 
**                   * 
** date: 04-02-97 by Sargola@Silberland     * 
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
#include <language.h> 
#include "../def.h" 
 
      create()       
{        if (!is_clone(this_object()))           return; 
        ::create(); 
        AddId (({"schlegel"})); 
        SetProp (P_SHORT, "Ein Schlegel"); 
        SetProp (P_LONG, BS("Ein wuchtiger Schlegel, mit dem man sicher "
		+"gut auf Koepfe knallen kann.")); 
        SetProp (P_NAME, "Schlegel"); 
        SetProp (P_GENDER, MALE);  

        SetProp (P_WEIGHT, 5000); 
        SetProp (P_VALUE, 800); 
        SetProp (P_MATERIAL, ({MAT_IRON, MAT_WOOD}) ); 
        SetProp (P_WEAPON_TYPE, WT_HAMMER); 
        SetProp(P_DAM_TYPE, DT_BLUDGEON); 
        SetProp(P_WC, 120+random(30)); 
        SetProp(P_NR_HANDS, 1); 
       
	SetProp(P_WIELD_RESTRICTIONS, ([A_DEX:15; A_STR:15])   );
}   
