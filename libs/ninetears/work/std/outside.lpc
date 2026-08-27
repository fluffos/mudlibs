// Let's comentar a sako!
// Vilat 12.10.2002 (5:17 am - La noche me confunde)
#include <tiempo.h>
inherit "/std/room";
inherit "/std/basic/extra_look";

// Definicion de variables
nosave string night_long;
nosave string dark_long;

// Definicion de funciones y acciones (aki solo acciones)
void do_noche();
void do_dia();
void do_amanecer();
void do_anochecer();
void do_eclipse();
void init_luz();

// Esto es pa establecer el darklong y pa pedirselo al arxivo
void set_dark_long(string s) { dark_long = s; }
string query_dark_long() { return dark_long; }

// Lo mismo pal nightlong
void set_night_long(string s) { night_long = s; }
string query_night_long() { return night_long; }

// No se si algo usara esto... via mirarlo... Hay 21 archivos q lo usan :( de tos modos iwal es inutil asi q mirare si se puede kitar
mixed *query_init_data() { return extra_look::query_init_data()+room::query_init_data(); }

// Una accion muy importante no?
void create() {
	// Esto es pq siempre necesitaremos un darklong aunq no se defina en el setup, el nightlong no es necesario especificar uno por defecto pq si no lo hay usaremos el long normal
   	dark_long = "Esta oscuro.\n";
  	// Pos eso, si hemos puesto a nuestra room un set_dark_long() pos lo cambiara ahora (room::create() llama al setup() )
  	room::create();
  	// Pensaba q room ya llamaba por si sola al extra_look::create() pero vete a saber... via mirar
  	// Pos no, no lo llama... a ver q hace el extra_look...
  	// Pos no parece ser muy util pa una room pero weno, supongo q los add_item van con eso o algo...
  	extra_look::create();
  	// Esta linea como que es obvia no?
  	add_property("location", "outside");
  	// Esta otra accion la meti io pa q iniciase la luz segun el CICLO actual (dia, noche...)
	init_luz();
	}

// El short tb me parece bastante obvio...
string short(int dark) {
	// Viene a ser q si esta muy oscuro o hay demasiada luz lo pone ademas del short y si no, pasa solo el short
	// Si al final cegamos a los players, habria q tocar el query_dark_mess() q creo q esta en room
  	if (dark) return query_dark_mess(dark) + ::short(dark);
  	else return ::short();
	}

// A ver q podemos hacer con el long :)
string long(string str, int dark) {
	string s, ret="";

	// Uy uy uy lo q acabo de encontrar gracias al check_dark: Los players muertos se pueden cegar :) al menos en cuanto al long
	// Si nos interesa, habria q tocar el check_dark() en player.c pa q dewelva 69
    	if (TP) dark = (int)TP->check_dark(query_light());
  	if (!str) {
      		if(CICLO_HANDLER->query_noche()) {
      			// ret es el string de TIEMPO, en este caso de la noche
      			ret = CICLO_HANDLER->query_hora_name()+" y ves "+CICLO_HANDLER->query_luna_name()+" en el cielo.\n";
      			// Vamos a acoplarle el clima
      			ret+= CLIMA->query_clima_name(TO->query_ajuste_humedad(),TO->query_ajuste_temperatura(),TO->query_ajuste_humedad(),TO->query_no_llover());

      			// Ahora comprobamos el nivel de luz
      			switch(dark) {
      				// Por defecto se supone que vemos, asi q devolveria el nightlong si lo hay (y si no, el long normal) anyadiendole a todo eso el CICLO y el CLIMA
        			default:
          			if( night_long ) ret = night_long + ret;
          			else ret = query_long() +"\n"+ret;
        			break;

        			// Esto es si esta oscuro, en ese caso devolvemos el mensaje segun el nivel de oscuridad mas CICLO&CLIMA
        			case 1..3:
      				if(dark_long) return dark_long+ret;
           			return ::query_dark_mess(dark)+"\n"+ret;

        			// Esto sin embargo es si hay demasiada luz...
        			case 4..6:
           			return ::query_dark_mess(dark)+ "\nParece ser de noche, que extranyo...\n"+ret;

           			// Si keremos cegar a los players
           			case 69:
           			return "\nTu espiritu ha abandonado el mundo material y solo puedes percibir el plano etereo.\n";
      				}
   			}
		// Y ahora si es de dia
   		else {
   			// Calculamos el ret, mas el clima
   			ret = CICLO_HANDLER->query_hora_name()+".\n";
   			ret+= CLIMA->query_clima_name(TO->query_ajuste_clima());
   			// Comprobamos la luz
      			switch(dark) {
      				// Si vemos:
        			default:
            			ret = query_long()+ret;
        			break;

        			// Si esta oscuro
        			case 1..3:
            			return ::query_dark_mess(dark)+"\nParece ser de dia, que extranyo...\n"+ret;

        			// Si hay demasiada luz
        			case 4..6:
		            	return ::query_dark_mess(dark)+"\n"+ret;
      				}
    			}
    		// Esto la verdad es q ni idea de cuando saldria :P supongo q es si no hay string, pero el caso es q como lo otro da returns...
    		// Ya lo he pillao, esto sale si no hay problemas con la luz :)
    		s = calc_extra_look(TO);
    		if (s && s != "") ret += s;
   		if(!exit_string) exit_string=query_dirs_string();
   		ret+= exit_string+"\n";
		return ret+query_contents("");
  		}
  	// Y esto sale si se le ha pasao algun argumento al long, supongo :P
  	str = expand_alias(str);
  	return items[str];
	}

// Una funcion util q nos permite comprobar si la room es de interior o de exterior
int query_outside() { return 1; }

// Esta accion nos permite arrancar la luz correctamente al cargar la room
void init_luz() {
	int luz;
	switch (CICLO_HANDLER->query_hora_name()) {
		case "Es de noche":
		do_noche();
		break;
		case "Esta amaneciendo":
		do_amanecer();
		break;
		case "Es de dia":
		do_dia();
		break;
		case "Esta anocheciendo":
		do_anochecer();
		break;
		default:
		}
	if(CICLO_HANDLER->query_eclipse()) do_eclipse();
	// Ajustes de luz segun tipo de terreno y properties
	luz=TO->query_light();
	luz+=TO->query_ajuste_luz();
	if (luz<0) luz=0;
	TO->set_light(luz);
	// Esto vale pa la luz real
	if (TO->query_property("luz_real")) TO->set_light(TO->query_property("luz_real"));
	}

// Los ajustes de la luz
void do_amanecer() { TO->set_light(40); }
void do_dia() { TO->set_light(60); }
void do_anochecer() { TO->set_light(40); }
void do_noche() {
	int luz=0;
	switch(CICLO_HANDLER->query_luna()) {
  		default:
  		break;
  		case 6:
  		luz+=5;
  		case 5:case 7:
  		luz+=5;
  		case 4:case 8:
  		luz+=5;
  		case 3:case 9:
  		luz+=5;
  		case 2:case 10:
  		luz+=5;
  		case 1:case 11:
  		luz+=4;
		case 0:
		luz+=1;
 		break;
 		}
	TO->set_light(luz);
	}

void do_eclipse() { TO->set_light(0); }

int query_ajuste_humedad() { return TO->query_property("ajuste_humedad"); }
int query_ajuste_temperatura() { return TO->query_property("ajuste_temperatura"); }
int query_ajuste_viento() { return TO->query_property("ajuste_viento"); }
int query_no_llover() { return TO->query_property("no_llover"); }
