inherit "/std/receptacle";

#include <pl.h>
#include <stdproperties.h>

create_receptacle()
{
    ustaw_nazwe( ({ "skrzynia", "skrzyni", "skrzyni", "skrzynie", "skrzynia",
        "skrzyni", }), ({ "skrzynie", "skrzyni", "skrzyniom", "skrzynie",
        "skrzyniami", "skrzyniach" }), PL_ZENSKI);
        
    dodaj_przym( "drewniany", "drewniani" );
    
    set_long("Zwykla drewniana skrzynia, jakich wiele.\n");
    
    add_prop(CONT_I_RIGID, 1); /* Skrzynia jest sztywna, tzn jej objetosc */
    			       /* nie zmienia sie wraz z objetoscia zawartosci*/
    			       /* tak, jak by to bylo w przypadku np torby */

    add_prop(CONT_I_MAX_VOLUME, 250000); /* moze miec maksymalnie objetosc.
    					    Poniewaz ma propa CONT_I_RIGID
    					    zawsze zajmuje tyle miejsca */
    					 
    add_prop(CONT_I_MAX_WEIGHT, 500000); /* mozna wladowac do niej do pol
    					    tony */
    					 

    add_prop(CONT_I_VOLUME, 10000); /* pusta skrzynia zajmowala by 10 litrow, 
    				       gdyby nie miala propa CONT_I_RIGID. */
    				       
    add_prop(CONT_I_WEIGHT, 20000); /* pusta skrzynia wazy 20 kilo */

    set_key("235=;>gdf"); /* Klucz musi miec podany kod, zeby pasowal. */
}