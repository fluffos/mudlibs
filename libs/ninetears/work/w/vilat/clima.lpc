// Vilat 08.10.2002
// Porque ya iba siendo hora y porque io lo valgo xDDD
inherit "/std/object";
// Velocidad de cambio de clima (9 minutos reales, una hora del mud)
#define VELOCITY 360 // xDDD a q mola mi ingles?
// El archivo del objeto
#define SFILE "/save/environ/clima"
// Variables globales
int humedad=0;
int temperatura=0;
int viento=0;
int lluvia;

void notificar_clima(string str);
void cambio_lluvia(int ant, int pos);

void setup() {
	set_name("clima");
	set_short("Controlador Climatico Global");
	// Let's recuperar los valores anteriores
	restore_object(SFILE);
	// Aki a iniciar el bucle climatico
	call_out("clima",0);
	call_out("chequeo",0);
	}

void clima() {
	int lluvia0=lluvia;
	// La temperatura puede empeorar, mejorar o mantenerse igual
	temperatura=temperatura+random(3)-1;
	// La humedad lo mismo
	humedad=humedad+random(3)-1;
	// Y el viento tambien
	viento=viento+random(3)-1;
	// Mantenemos las variables dentro de unos limites
	if (humedad<-2) humedad=-2;
	if (humedad>4) humedad =4;
	if (viento<0) viento=0;
	if (viento>4) viento=4;
	if (temperatura<-3) temperatura=-3;
	if (temperatura>3) temperatura=3;
	// La lluvia dependera de los demas factores
	if ( humedad>0 && random(2) ) switch (temperatura) {
		case -3: // Granizo
		lluvia=-2;
		break;
		case -2: // Nieve
		lluvia=-1;
		break;
		case -1..1: // Lluvia
		lluvia=1;
		break;
		case 2: // Niebla
		lluvia=2;
		break;
		case 3: // Tormenta
		lluvia=3;
		break;
		default:
		lluvia=0;
		}
	else if (random(2)) lluvia=0;
	// Comprobamos si ha cambiado la lluvia y en ese caso se lo notificamos a los players
	if (lluvia0!=lluvia) cambio_lluvia(lluvia0,lluvia);
	// Reiniciamos el bucle climatico (segun el velocity cada hora del mud)
	call_out("clima",VELOCITY);
	}

// No keremos q el tiempo se pierda no?
void dest_me() {
	save_object(SFILE);
	::dest_me();
	}

int query_humedad() { return humedad; }
int query_temperatura() { return temperatura; }
int query_viento() { return viento; }
int query_lluvia() { return lluvia; }

void cambio_lluvia(int ant, int pos) {
	string s1,s2;
	if (!ant) {
		s1="Ha comenzado a ";
		switch (pos) {
			case -2:s2="granizar.\n";break;
			case -1:s2="nevar.\n";break;
			case 1:s2="llover.\n";break;
			case 2:
			s1="La zona se esta nublando";
			s2=".\n";
			break;
			case 3:
			s1="Ha estallado subitamente una tormenta";
			s2=".\n";
			break;
			default:
			return;
			}
		notificar_clima(s1+s2);
		return;
		}
	else if (!pos) {
		s1="Ha dejado de ";
		switch (ant) {
			case -2:s2="granizar.\n";break;
			case -1:s2="nevar.\n";break;
			case 1:s2="llover.\n";break;
			case 2:
			s1="La niebla se disipa lentamente";
			s2=".\n";
			break;
			case 3:
			s1="Poco a poco la tormenta amaina";
			s2=".\n";
			break;
			default:
			return;
			}
		notificar_clima(s1+s2);
		return;
		}
	else {
		s1="Ha dejado de ";
		switch (ant) {
			case -2:s1+="granizar ";break;
			case -1:s1+="nevar ";break;
			case 1:s1+="llover ";break;
			case 2:s1="La niebla se ha disipado ";break;
			case 3:s1="La tormenta ha amainado ";break;
			default:return;
			}
		s2="y se ha puesto ";
		switch (pos) {
			case -2:s2+="a granizar.\n";break;
			case -1:s2+="a nevar.\n";break;
			case 1:s2+="a llover.\n";break;
			case 2:s2="y la niebla ha cubierto la zona.\n";break;
			case 3:s2="para dar paso a una tormenta.\n";break;
			default:return;
			}
		notificar_clima(s1+s2);
		return;
		}
	return;
	}

void notificar_clima(string str) {
	object *pls=users();
	for (int i=0;i<sizeof(pls);i++) if (environment(pls[i])->query_outside()) tell_object(pls[i],str);
	}

void chequeo() {
	object *pls=users();
	for (int i=0;i<sizeof(pls);i++) pls[i]->check_it();
	call_out("chequeo",25);
	return;
	}

string query_clima_name(int ahum, int atem, int avie, int noll) {
	int hum=humedad+ahum;
	int tem=temperatura+atem;
	int vie=viento+avie;
	string svie;
	string stem;
	string shum;
	string sllu;

	if (hum<-2) hum=-2;
	if (hum>4) hum =4;
	if (vie<0) vie=0;
	if (vie>4) vie=4;
	if (tem<-3) tem=-3;
	if (tem>3) tem=3;

	switch (vie) {
		case 1:svie="vientecillo";break;
		case 2:svie="viento";break;
		case 3:svie="vendaval";break;
		case 4:svie="torbellino";break;
		default:svie="tiempo";break;
		}

	switch (tem) {
		case -3:stem="gelido";break;
		case -2:stem="frio";break;
		case -1:stem="fresco";break;
		case 0:stem="templado";break;
		case 1:stem="calido";break;
		case 2:stem="muy calido";break;
		case 3:stem="ardiente";break;
		default:stem="raro";break;
		}

	switch (hum) {
		case -2:shum="un clima muy seco";break;
		case -1:shum="un clima seco";break;
		case 0:shum="el cielo despejado";break;
		case 1:shum="algunas nubes en el cielo";break;
		case 2:shum="el cielo nublado";break;
		case 3:shum="el cielo muy cubierto";break;
		case 4:shum="densos nubarrones";break;
		default:shum="un cielo %^MAGENTA%^morado%^RESET%^";break;
		}

	switch (lluvia) {
		case -2:sllu="graniza";break;
		case -1:sllu="nieva";break;
		case 1:sllu="llueve";break;
		case 2:sllu="hay "+({"poca","bastante","mucha"})[random(3)]+" niebla";break;
		case 3:sllu="hay una fuerte tormenta";break;
		}

	if (noll||!lluvia) {
		if(!vie) return CAP(svie)+" "+stem+" con "+shum+".\n";
		return "Sopla un "+svie+" "+stem+" con "+shum+".\n";
		}
	if (!vie) return CAP(sllu)+" y el "+svie+" es "+stem+" con "+shum+".\n";
	return CAP(sllu)+" y sopla un "+svie+" "+stem+" con "+shum+".\n";
	}
