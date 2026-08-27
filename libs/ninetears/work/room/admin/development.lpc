inherit "std/room";

object board;

void reset() {
  	if(!board) {
    		board = clone_object("obj/misc/board");
    		board->set_datafile("development");
    		board->move(this_object());
  		}
	}

void setup() {
  	set_light(80);
  	set_short("Oficina de %^CYAN%^Desarrollo%^RESET%^ del Mud");
  	set_long(query_short()+"\nEsta es probablemente la sala mas importante del Paraiso. Aqui hay un tablon donde deben comentarse detalladamente tanto los avances de la Mudlib como los progresos de los Dominios, asi que todo Inmortal deberia leerlo asiduamente y de vez en cuando comentar como van sus proyectos. Se han dispuesto algunas sillas para la gente que idlee aqui, aunque nada comparado con los magnificos sillones de la sala comun.\n");
	add_exit("fuera","/d/heaven/admin2","door");
	}

void dest_me() {
  	if (board) board->dest_me();
  	::dest_me();
	}
