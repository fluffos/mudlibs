/* eine einfache Spitzhacke, generic to use.
 * Tue Jun 13 14:16:19 2000, Samtpfote@Tamedhon
 */
#include <properties.h>
#include <combat.h>

inherit "std/weapon";

void create()
{
    if(!clonep(this_object())) return 0;
    ::create();
    
    AddId(({"\nspitzhacke","hacke","spitzhacke"}));
    SetProp(P_GENDER, FEMALE);
    SetProp(P_NAME, "Spitzhacke");
    SetProp(P_SHORT, "Eine Spitzhacke");
    SetProp(P_LONG, break_string(	
	"Das ist eine ganz normale Spitzhacke aus soliden Eichenholz "+
	"und Stahl. Wirklich eine Qualitätsarbeit!"));
    SetProp(P_VALUE, 250);
    SetProp(P_WEIGHT, 1300);
    SetProp(P_WEAPON_TYPE, WT_CLUB);
    SetProp(P_WC, 70);
    SetProp(P_NR_HANDS, 2);
    SetProp(P_DAM_TYPE, ({DT_BLUDGEON, DT_RIP}));
}
