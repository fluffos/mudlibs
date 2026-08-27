inherit "/std/armour";

#include <stdproperties.h>
#include <wa_types.h>
#include <formulas.h>
#include <macros.h>

void
create_armour()
{
    ustaw_nazwe( ({ "kolczuga", "kolczugi", "kolczudze", "kolczuge",
    	"kolczuga", "kolczudze" }), ({ "kolczugi", "kolczug", "kolczugom",
    	"kolczugi", "kolczugami", "kolczugach" }), PL_ZENSKI);

    dodaj_przym("czarny", "czarni");
    dodaj_przym("misterny","misterni");

    set_long("Jest to znakomita kolczuga wykonana z poczernianej stali " +
             "o drobnych oczkach zapewniajacych ochrone nawet przed " +
             "sztyletem.\n");
             
    set_ac(A_BODY, 18, 28, 20,
    	   A_ARMS, 16, 26, 18);


/* Cena i waga zostana standardowo ustawione przez mudlib, jesli ich
 *  nie podamy. A ten wylicza je raczej dobrze i rzetelnie.
 */
 
/* Objetosc ustawiamy jako wage / 6. Gestosc stali wynosi okolo 8g/cm3,
 * powinno byc wiec / 8, ale przeciez kolczugi nie da sie idealnie zlozyc.
 */
    add_prop(OBJ_I_VOLUME, query_default_weight() / 6);
}
