#define DOM_TITLE "dominio de Heaven"
#define DOM_LORD "Tyrael"
#define DOMAIN "heaven"
/* PLEASE re-describe me */
inherit "/std/dom/cmn_mas";
object board;

void setup() {
	set_dom(DOMAIN);
	set_light(100);

	set_short("Habitacion comun del dominio de "+capitalize(DOMAIN));
  	set_long(query_short()+"\nLa sala comun del "+DOM_TITLE+" esta compuesta por una gran mesa donde sus miembros se reunen a debatir el destino de este dominio. Un tablon adorna una de las paredes, y en la opuesta hay un retrato de "+DOM_LORD+", Thane de este dominio.\n");
	add_exit("mapamundi","/room/admin/mapamundi","plain");
  	board = clone_object("/obj/misc/board");
  	board->set_datafile(DOMAIN);
  	board->move(this_object());
	}

void dest_me() {
  	if(board) board->dest_me();
  	::dest_me();
	}
