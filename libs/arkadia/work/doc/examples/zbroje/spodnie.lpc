inherit "/std/armour";

#include <pl.h>
#include <wa_types.h>
#include <stdproperties.h>

void
create_armour() 
{
/* Poniewaz slowo 'spodnie' nie ma formy w liczbie pojedynczej,
 * podajemy odmiane tylko w mnogiej. Mudlib domysli sie dlaczego.
 */
      ustaw_nazwe( ({ "spodnie", "spodni", "spodniom", "spodnie",
      		      "spodniami", "spodniach" }), PL_MESKI_NOS_ZYW);

      dodaj_nazwy(({ "para spodni", "parze spodni", "parze spodni",
		     "pare spodni", "para spodni", "parze spodni" }), 
		     ({ "pary spodni", "par spodni", "parom spodni", 
		     "pary spodni", "parami spodni", "parach spodni" }),
		     PL_ZENSKI);

      ustaw_shorty(({ "para dlugich spodni", "parze dlugich spodni", 
      		      "parze dlugich spodni", "pare dlugich spodni", 
      		      "para dlugich spodni", "parze dlugich spodni" }),
      		      ({ "pary dlugich spodni", "par dlugich spodni", 
      		      "parom dlugich spodni", "pary dlugich spodni", 
      		      "parami dlugich spodni", "parach dlugich spodni" }), 
      		      PL_ZENSKI);

     dodaj_przym("dlugi", "dludzy" );
      
     set_long("Sa ta dlugie, brazowe skorzane spodnie.");

     set_ac(A_LEGS, 2, 2, 2);

      
/* Cena i waga zostana standardowo ustawione przez mudlib, jesli ich
 *  nie podamy. A ten wylicza je raczej dobrze i rzetelnie.
 */

     add_prop(OBJ_I_VOLUME, 500);
}
 
