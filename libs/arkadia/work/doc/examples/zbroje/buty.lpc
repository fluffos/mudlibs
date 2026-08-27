/* zbroja dowodczyni strazy (/doc/examples/npce/dowodczyni.c)
 * Napisal Rasputin
 */

inherit "/std/armour";

#include <wa_types.h>
#include <stdproperties.h>
#include <pl.h>

void
create_armour() 
{
/* 
 * Nazwa 'buty' wystepuje tylko w liczbie mnogiej, wiec nie podajemy
 * odmiany w liczbie pojedynczej.
 */
    dodaj_nazwy(({ "buty", "butow", "butom", "buty", "butami", "butach" }),
                PL_MESKI_NOS_NZYW);

    ustaw_nazwe(({ "para butow", "pary butow", "parze butow",
        "pare butow", "para butow", "parze butow" }), ({ "pary butow", 
        "par butow", "parom butow", "pary butow", "parami butow",
        "parach butow" }), PL_ZENSKI);
        
    ustaw_shorty(({ "para wysokich butow", "pary wysokich butow", 
        "parze wysokich butow", "pare wysokich butow", 
        "para wysokich butow", "parze wysokich butow" }), 
        ({ "pary wysokich butow", "par wysokich butow", 
        "parom wysokich butow", "pary wysokich butow", 
        "parami wysokich butow", "parach wysokich butow" }), PL_ZENSKI);
                
    dodaj_przym( "wysoki", "wysocy" );
            
    set_long("Sa ta wysokie skorzane buty. Wygladaja porzadnie, wewnatrz "+
             "bowiem maja dodatkowe metalowe wzmocnienia.\n");

//    add_prop(OBJ_I_WEIGHT, 1000);
//    add_prop(OBJ_I_VALUE, 300);
    set_ac(A_FEET, 5, 5, 5); /* ochrona jaka zapewniaja */
}
