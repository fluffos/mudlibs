inherit "std/room";

object board;

void reset() {
  	if(!board) {
    		board = clone_object("obj/misc/board");
    		board->set_datafile("quests");
    		board->move(this_object());
  		}
	}

void setup() {
  	set_light(80);
  	set_short("Oficina de %^CYAN%^Quests%^RESET%^");
  	set_long(query_short()+"\nEn esta sala los creadores pueden dejar documentacion sobre las quests que incluyan en sus dominios, si bien aquellos creadores que jueguen activamente a Ninetears no deberian leer nunca este tablon xD.\n");
	add_exit("fuera","/d/heaven/admin1","door");
	}

void dest_me() {
  	if (board) board->dest_me();
  	::dest_me();
	}
