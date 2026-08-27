// Vhurkul 27.10.2002 - Libro
// Basado en la version original de FR, pero adaptado muy libremente
// - Introducido sistema de Titulo
// - Introducido sistema de Idiomas
// - Incluida la posibilidad de llamar a una funcion

inherit "/std/item";

int abierto; // capitulo por el que esta abierto
string archivo; // archivo que contiene el texto
string idioma; // Guarda el idioma en que esta escrito el libro

void event_leido(object player, int pagina) { return; }

string *recuperar_capitulos() {
	string buf=read_file(archivo);
	if (buf) return explode(buf,"<CAPITULO>");
	else return ({"Probablemente te han timado porque el libro esta en blanco..."});
	}

string calcular_titulo() {
	string *t;
	string tmp;
	t=explode(archivo,"/");
	tmp=t[sizeof(t)-1];
	t=explode(tmp,".");
	tmp=t[0];
	return replace_string(tmp,"_"," ");
	}

void fijar_archivo_lectura(string str) { archivo=str; }
string dame_archivo_lectura() { return archivo; }
void fijar_idioma(string str) { idioma=str; }
string dame_idioma() { return idioma; }

void create() {
	abierto=-1; // inicialmente cerrado
	::create();
	set_holdable(1);
	if (!idioma) idioma="comun";
	}

void init() {
  	::init();
  	add_action ("abrir","abrir");
  	add_action ("cerrar","cerrar");
  	add_action ("capitulo","capitulo");
  	add_action ("indice","indice");
	add_action ("leer","leer");
	}

int abrir(string str) {
  	if ( member_array(str,TO->query_alias()+({TO->query_name()}))!=-1 && abierto==-1 ) {
    		tell_object(TP,"Abres tu "+TO->query_short()+".\n");
    		abierto = 0; // Abrimos el libro por el indice
    		return 1;
  		}
  	if (member_array( str , TO->query_alias()+ ({ TO->query_name() }) ) !=-1 ) {
		tell_object(TP,"Tu "+TO->query_short()+" ya esta abiert"+TO->query_vocal()+(!abierto? " por el indice" : " por el capitulo "+(string)abierto)+".\n"); //Para los colores
		return notify_fail("");
		}
  	return 0;
	}

int cerrar(string str) {
  	if ( member_array(str,TO->query_alias()+({TO->query_name()}))!=-1 && abierto!=-1 ) {
    		tell_object(TP,"Cierras tu "+TO->query_short()+".\n");
    		abierto = -1; // Libro cerrado
    		return 1;
  		}
	if ( member_array(str,TO->query_alias()+({TO->query_name()}))!=-1 ) {
		tell_object(TP,"Tu "+TO->query_short()+" ya esta cerrad"+TO->query_vocal()+".\n");
		return notify_fail("");
		}
  	return 0;
	}

int capitulo(string str) {
  	int i;

	if(abierto==-1) {
		tell_object(TP,"Deberias abrir tu "+TO->query_short()+" antes de buscar un capitulo.\n");
		return notify_fail("");
		}
  	if (!str || str == "") return notify_fail("Uso: capitulo <numero>.\n");

  	sscanf(str, "%d", i);
  	if ( i > 0 && i < sizeof(recuperar_capitulos()) ) {
		tell_object(TP,"Pasas las paginas hasta el capitulo "+(string)i+".\n");
     		abierto = i; // Cambiamos la pagina
     		return 1;
  		}
  	return notify_fail("Ese capitulo no existe.\n");
	}

int indice() {
	if(abierto==-1) {
		tell_object(TP,"Deberias abrir tu "+TO->query_short()+" antes de buscar el indice.\n");
		return notify_fail("");
		}
	tell_object(TP,"Pasas las paginas hasta el indice.\n");
 	abierto = 0;
	return 1;
	}

int leer(string str) {
	if ( member_array(str,TO->query_alias()+({TO->query_name()}))!=-1 ) {
		if(member_array(TO,TP->query_held_ob())==-1) return notify_fail("La letra es pequenya asi que tendras que sujetar el escrito cerca de tu cara para poder leerlo.\n");
		if(member_array(idioma,TP->query_languages()) == -1 ) {
			if(random(TP->query_int()+TP->query_wis())>random(40)) {
				tell_object(TP,"No puedes leer tu "+TO->query_short()+" porque esta escrito en "+CAP(idioma)+".\n");
				return notify_fail("");
				}
			tell_object(TP,"No puedes leer tu "+TO->query_short()+" porque esta escrito en un idioma que no aciertas a reconocer.\n");
			return notify_fail("");
			}
		if (abierto==-1) {
			tell_object(TP,"Un escrito titulado \""+calcular_titulo()+"\". Deberias abrirlo para poder leerlo.\n");
			return 1;
			}
		TP->more_string(recuperar_capitulos()[abierto]);
		if(abierto==0) tell_object (TP,"Usa 'capitulo <numero>' para ver otro capitulo o 'indice' para volver a esta pagina.\n");
		event_leido(TP,abierto);
		return 1;
		}
	return 0;
	}

