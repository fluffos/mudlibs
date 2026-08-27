#include <formulas.h>
                   /* Blethrop */
                   /* 20.X.97  */
                   
inherit "/std/armour";

#include <wa_types.h>
#include <stdproperties.h>
#include <pl.h>

void
create_armour()
{
    ustaw_nazwe(({ "plaszcz", "plaszcza", "plaszczowi", "plaszcz", 
                   "plaszczem", "plaszczu" }),
               ({ "plaszcze", "plaszczy", "plaszczom", "plaszcze", 
                  "plaszczami", "plaszczach" }), PL_MESKI_NOS_NZYW);

    dodaj_przym("dlugi","dludzy");
    dodaj_przym( "czarny", "czarni" );

    set_long("Jest to dlugi czarny plaszcz ze zlota sprzaczka, wykonany z "+
    	     "drogiego materialu. Masz pewnosc, ze gdy go nalozysz bedzie "+
    	     "znakomicie sie prezentowal.\n");

    set_ac(A_BODY, 4, 4, 4,
    	   A_ARMS, 4, 4, 4,
    	   A_LEGS, 4, 4, 4);

/* Poniewaz plaszcz zaklada sie na co innego, niz chroni, musimy mu
 * wiec ustawic jeszcze sloty - na co sie go zaklada.
 */
    set_slots(A_ROBE);
             
/* Plaszcz jest wiecej warty, niz by to wskazywalo jego AC 
 */
    add_prop(OBJ_I_VALUE, 100);

    
    add_prop(OBJ_I_VOLUME, 400);
}