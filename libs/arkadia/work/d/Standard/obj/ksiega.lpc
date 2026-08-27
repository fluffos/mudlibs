/* Ksiega z informacjami dla poczatkujacych graczy
 * Lewy 31.12.1997
 */

inherit "/std/scroll";

#include <stdproperties.h>
#include <macros.h>


void
create_scroll()
{

    ustaw_nazwe(({"ksiega","ksiegi","ksiedze","ksiege","ksiega","ksiedze"}),
      ({"ksiegi","ksiag","ksiegom","ksiegi","ksiegami","ksiegach"}),PL_ZENSKI);

    set_long("\nJest to gruba ksiega oprawiona w skore. Na jej okladce zlotymi "+
	"literami wytloczono napis PORADNIK POCZATKUJACEGO ODKRYWCY. "+
	"Ksiega jest tak popularna ze przymocowano ja lancuchem aby nikt "+
	"jej nie ukradl.\n");

    add_prop(OBJ_I_VALUE, 0);
    add_prop(OBJ_I_WEIGHT, 0);
    add_prop(OBJ_I_VOLUME, 0);
    add_prop(OBJ_M_NO_GET, "Ksiega jest przymocowana lancuchem do stolu.\n");
    
    set_file("/d/Standard/obj/gracz_FAQ");
}

