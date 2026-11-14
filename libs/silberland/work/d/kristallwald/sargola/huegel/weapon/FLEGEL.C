/************************************************ 
**  Dreschflegel         * 
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
        AddId (({"dreschflegel","flegel"})); 
 
        SetProp (P_SHORT, "Ein Dreschflegel"); 
        SetProp (P_LONG, BS("Ein gewoehnlicher Dreschflegel, wie viele "
		+"Bauern ihn verwenden, um das Getreide zu loesen. Sicher "
		+"kann man auch gut Monster damit plaetten.")); 
        SetProp (P_NAME, "Dreschflegel"); 
        SetProp (P_GENDER, MALE);  

        SetProp (P_WEIGHT, 550); 
        SetProp (P_VALUE, 80); 
        SetProp (P_MATERIAL, ({MAT_IRON, MAT_WOOD}) ); 
        SetProp (P_WEAPON_TYPE, WT_SPEAR); 
        SetProp(P_DAM_TYPE, DT_PIERCE); 
        SetProp(P_WC, 80+random(20)); 
        SetProp(P_NR_HANDS, 1); 
}   
 
