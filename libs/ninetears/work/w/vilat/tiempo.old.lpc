inherit "std/object";

#define SPEED 5
#define FILE_NAME "/w/vilat/tiempo"

int noche,minuto,hora,dia,mes,anyo,luna_jb,luna,duracion_eclipse,eclipse;
string estacion;
void cambio();

void setup() {
	set_name("tiempo");
  	set_short("Controlador de ciclo dia-noche");
  	set_long("Esta cosa si fona controlara los dias y las noches.\n");
  	noche=0;
	minuto=0;
	hora=0;
	dia=1;
	mes=1;
	anyo=1;
	luna_jb=0;
	luna=0;
	estacion="Herm";
	restore_object(FILE_NAME);
  	call_out("cambio",SPEED);
  	}
	
void cambio() {
	minuto++;
	if (minuto>=60) {
		minuto=0;
		hora++;
		}
	if (hora>=20) {
		hora=0;
		dia++;
		luna_jb++;
		}
	if (dia>30) {
		dia=1;
		mes++;
		}
	if (mes>12) {
		mes=1;
		anyo++;
		}
	switch (estacion) {
		default:
		switch (hora) {
			case 0..6:
			case 17..19:
			noche=1;
			if (hora==17&&!minuto) event(users(), "player_echo_all", "La noche cae sobre Driade.\n");
			break;
		
			default:
			if (hora==7&&!minuto) event(users(), "player_echo_all", "El sol sale iluminando Driade con sus calidos rayos.\n");
			noche=0;
			}
		break;
		
		case "Saam":
		switch (hora) {
			case 0..5:
			case 18..19:
			noche=1;
			if (hora==18&&!minuto) event(users(), "player_echo_all", "La noche cae sobre Driade.\n");
			break;
		
			default:
			if (hora==6&&!minuto) event(users(), "player_echo_all", "El sol sale iluminando Driade con sus calidos rayos.\n");
			noche=0;
			}
		break;
		
		case "Herm":
		switch (hora) {
			case 0..7:
			case 16..19:
			noche=1;
			if (hora==16&&!minuto) event(users(), "player_echo_all", "La noche cae sobre Driade.\n");
			break;
		
			default:
			if (hora==8&&!minuto) event(users(), "player_echo_all", "El sol sale iluminando Driade con sus calidos rayos.\n");
			noche=0;
			}
		break;
		}
	switch (mes) {
	
		case 1..2:case 12:
		estacion="Herm";
		break;
		
		case 3..5:
		estacion="Ren";
		break;

		case 6..8:
		estacion="Saam";
		break;
		
		case 9..11:
		estacion="Durm";
		break;
		
		default:
		estacion="bug";
		}
	if (luna_jb>=15) {
		luna_jb=0;
		luna++;
		}
	if (luna>=12) luna=0;
	save_object(FILE_NAME);
	call_out("cambio",SPEED);
	}
	
int query_noche() { return noche; }
string query_estacion() { return capitalize(estacion); }
string query_hora() { 
	if (minuto<10) return (string)hora+":0"+(string)minuto;
	else return (string)hora+":"+(string)minuto;
	}
int query_dia() { return dia; }
int query_mes() { return mes; }
int query_anyo() { return anyo; }
int query_horas() { return hora; }
int query_minutos() { return minuto; }

void dest_me() {
  	save_object(FILE_NAME);
  	::dest_me();
	}
	
string query_mes_name() {
	switch (mes) {
		case 1:
		return "Aelmont";
		case 2:
		return "Rannmont";
		case 3:
		return "Mislamont";
		case 4:
		return "Chirlmont";
		case 5:
		return "Bran";
		case 6:
		return "Corij";
		case 7:
		return "Argaron";
		case 8:
		return "Sirrmont";
		case 9:
		return "Rargmont";
		case 10:
		return "Haddulont";
		case 11:
		return "Phanla";
		case 12:
		return "Enda";
		default:
		return "Bug";
		}
	}
	
string query_dia_name() {
	switch (dia) {
		case 1:
		return "el primer Unher";
		case 7:
		return "el segundo Unher";
		case 13:
		return "el tercer Unher";
		case 19:
		return "el cuarto Unher";
		case 25:
		return "el ultimo Unher";
		case 2:
		return "la primera Damner";
		case 8:
		return "la segunda Damner";
		case 14:
		return "la tercera Damner";
		case 20:
		return "la cuarta Damner";
		case 26:
		return "la ultima Damner";
		case 3:
		return "el primer Irgan";
		case 9:
		return "el segundo Irgan";
		case 15:
		return "el tercer Irgan";
		case 21:
		return "el cuarto Irgan";
		case 27:
		return "el ultimo Irgan";
		case 4:
		return "la primera Morhen";
		case 10:
		return "la segunda Morhen";
		case 16:
		return "la tercera Morhen";
		case 22:
		return "la cuarta Morhen";
		case 28:
		return "la ultima Morhen";
		case 5:
		return "el primer Fadlur";
		case 11:
		return "el segundo Fadlur";
		case 17:
		return "el tercer Fadlur";
		case 23:
		return "el cuarto Fadlur";
		case 29:
		return "el ultimo Fadlur";
		case 6:
		return "la primera Sumden";
		case 12:
		return "la segunda Sumden";
		case 18:
		return "la tercera Sumden";
		case 24:
		return "la cuarta Sumden";
		case 30:
		return "la ultima Sumden";
		default:
		return "Bug";
		}
	}
		
		
string query_fecha() { return "Hoy es "+query_dia_name()+" de "+query_mes_name()+" de "+query_anyo()+" en Driade."; }
int query_luna() { return luna; }
string query_luna_name() {
	if (!query_noche()) return "Es de dia y no se ve la luna.";
	switch (luna) {
		case 0:
		return "que no hay luna";
		case 1:
		return "una rendija de luna creciente";
		case 2:
		return "un cuarto de luna creciente";
		case 3:
		return "la media luna creciente";
		case 4:
		return "tres cuartos de luna creciente";
		case 5:
		return "la luna creciente casi llena";
		case 6:
		return "la luna llena";
		case 7:
		return "la luna menguante casi llena";
		case 8:
		return "tres cuartos de luna menguante";
		case 9:
		return "la media luna menguante";
		case 10:
		return "un cuarto de luna menguante";
		case 11:
		return "una rendija de luna menguante";
		default:
		return "Bug";
		}
	}
string query_hora_name() {
	switch (estacion) {
		default:
		switch (hora) {
			case 0..5:
			case 17..19:
			return "Es de noche";
			case 6:
			return "Esta amaneciendo";
			case 7..15:
			return "Es de dia";
			case 16:
			return "Esta anocheciendo";
			default:
			return "Bug";
			}
		break;
		
		case "Saam":
		switch (hora) {
			case 0..4:
			case 18..19:
			return "Es de noche";
			case 5:
			return "Esta amaneciendo";
			case 6..16:
			return "Es de dia";
			case 17:
			return "Esta anocheciendo";
			default:
			return "Bug";
			}
		break;
		
		case "Herm":
		switch (hora) {
			case 0..6:
			case 16..19:
			return "Es de noche";
			case 7:
			return "Esta amaneciendo";
			case 8..14:
			return "Es de dia";
			case 15:
			return "Esta anocheciendo";
			default:
			return "Bug";
			}
		break;
		}
	}
	
void init_eclipse(int i) {
	duracion_eclipse=i;
	if (eclipse) return;
	event(users(), "player_echo_all", "De repente el sol comienza a oscurecerse, sientes como un miedo repentino comienza a llenar tu corazon cuando el cielo se vuelve rojo como la sangre.\n");
	call_out("eclipse1",5);
	eclipse=1;
	return;
	}
void eclipse1() {
	event(users(), "player_echo_all", "Parece que ha oscurecido antes de lo normal, debe ser cosa de brujeria por lo que deberias andar con cuidado.\n");
	call_out("eclipse2",duracion_eclipse);
	return;
	}
void eclipse2() {
	event(users(), "player_echo_all", "Poco a poco comienza a brillar de nuevo el Sol. Una sensacion de paz interior te inunda alejando todos tus miedos.\n");
	eclipse=0;
	return;
	}
	
int query_eclipse() { return eclipse; }
	
	