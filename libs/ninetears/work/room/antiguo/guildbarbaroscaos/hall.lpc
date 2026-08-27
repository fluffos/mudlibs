inherit "/std/room";
#include "definepage.h"
object board;

void setup () {
	set_short (GUILDHALL);
	set_long (GUILDHALL+"En esta sala es donde los Barbaros del Caos cuentan sus cosas a sus companyeros de gremio. Una puerta lleva a la Sala del Consejo, donde se toman las decisiones del Gremio y quedan recogidos en una lista negra los enemigos del gremio.\n\n");
	set_light(LUZ);

	add_exit(O,GUILDDIR"barracks", "standard");
	add_exit(DE,GUILDDIR"meeting","door"); 
        add_exit(E,GUILDDIR"armory","standard");
	}

void reset () {
	if (!board) {
		board=clone_object("/obj/misc/board");
		board->move(TO);
		board->set_datafile(DATAFILE);
		}
	}

void dest_me () {
	if (board) board-> dest_me ();
	::dest_me ();
	}
