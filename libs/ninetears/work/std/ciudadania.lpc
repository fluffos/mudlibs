// Vilat 17.11.2002
// Economia y Sociedad de Ciudadanias

#define SFILE file_name(TO)
#define MAX_DESC 15000 // Puede aguantar 3 meses a 10 platinos per capita si no mueren ciudadanos (el impuesto civil no deberia sobrepasar los 25 oros per capita... 6 meses = 24 dias de juego)
#define TIEMPO_COBRO 324000 // 1 mes del mud, unos 4 dias de juego

inherit "/std/object";

int descontento;
int *impuestos;
int civilesmuertos;
int civiles;
string comandante;
string *consejeros;
string *milicianos;
int ultimocobro;
int tesoro;
int gasto;
nosave int ciclojb;
mapping relaciones;
string inicio;

void create() {
	descontento=0;
	impuestos=({0,0});
	civilesmuertos=0;
	civiles=0;
	ultimocobro=0;
	tesoro=3000*5*100;
	gasto=0;
	comandante="";
	consejeros=({});
	milicianos=({});
	ciclojb=0;
	relaciones=([]);
	inicio=0;
	::create();
	restore_object(SFILE,1);
	call_out("ciclo",0);
	}

int query_tesoro() { return tesoro; }
void ajustar_tesoro(int i) {
	tesoro+=i;
	save_object(SFILE,1);
	}
int query_gasto() { return gasto; }
void poner_gasto(int i) {
	gasto=i;
	save_object(SFILE,1);
	}

int query_descontento() { return descontento; }
int ajustar_descontento(int i) {
	descontento+=i;
	if(descontento<0) descontento=0;
	if(descontento>MAX_DESC) descontento=MAX_DESC;
	save_object(SFILE,1);
	return descontento;
	}

string query_descontento_name() {
	switch(descontento*10/MAX_DESC) {
		case 0:return "El pueblo apoya a los gobernantes incondicionalmente.";
		case 1:return "El pueblo esta contento.";
		case 2:return "El pueblo esta satisfecho.";
		case 3:return "El pueblo se muestra indiferente ante el gobierno.";
		case 4:return "El pueblo tolera el gobierno.";
		case 5:return "El pueblo no esta satisfecho por el gobierno";
		case 6:return "El pueblo esta descontento.";
		case 7:return "El pueblo esta en contra del gobierno.";
		case 8:return "El pueblo se muestra violento ante el gobierno.";
		case 9:return "El pueblo esta al borde de la sublevacion.";
		default:return "El pueblo se ha sublevado!";
		}
	return "Ha ocurrido un error, notificalo con el comando BUG.";
	}

int query_impuesto_civil() { return impuestos[0]; }
int query_impuesto_ventas() { return impuestos[1]; }
void poner_impuesto_civil(int i) {
	impuestos[0]=i;
	save_object(SFILE,1);
	}
void poner_impuesto_ventas(int i) {
	impuestos[1]=i;
	save_object(SFILE,1);
	}

void civil_muerto() { civilesmuertos++; }

void dest_me() {
	save_object(SFILE,1);
	::dest_me();
	}

void ciclo() {
	ciclojb++;
	if(ciclojb>72) {
		ciclojb=0;
		ajustar_descontento(civilesmuertos*1000/civiles);
		civilesmuertos=0;
		}
	if(time()-ultimocobro>=TIEMPO_COBRO) {
		ultimocobro=time();
		tesoro+=civiles*impuestos[0];
		tesoro-=gasto;
		ajustar_descontento(impuestos[0]);
		}
	call_out("ciclo",100);
	}

int query_relacion(object ob) {
	if(member_array(lower_case(ob->query_ciudadania()),keys(relaciones))==-1) {
	    log_file("ciudadanias","La ciudadania "+SFILE+" no tiene definida relacion con "+ob->query_ciudadania()+" o bien "+ob->QCN+" tiene una ciudadania inexistente.\n");
	    return 0;
	    }
	else return relaciones[lower_case(ob->query_ciudadania())];
	}

void establecer_relacion(string str,int r) {
	if(!str||r<-2||r>2) {
	    log_file("ciudadanias","La ciudadania "+SFILE+" tiene definida una relacion invalida con "+CAP(str)+".\n");
	    return;
	    }
	str=lower_case(str);
	relaciones[str]=r;
	}

void establecer_inicio(string str) {
	inicio=lower_case(str);
	save_object(SFILE,1);
	}
string query_inicio() { return inicio; }

void poner_civiles(int i) {
	if(i>0) civiles=i;
	save_object(SFILE,1);
	}

int query_civiles() { return civiles; }
string query_titulo(string name) {
	name=lower_case(name);
	if(name=="/d/ciudades/master"->query_regente(file_name(TO)[12..]))return "Regente";
	if(name==comandante) return "Comandante";
	if(member_array(name,consejeros)!=-1) return "Consejer"+(find_living(name)->query_gender()-1?"a":"o");
	if(member_array(name,milicianos)!=-1) return "Milician"+(find_living(name)->query_gender()-1?"a":"o");
	return "Ciudadan"+(find_living(name)->query_gender()-1?"a":"o");
	}

void poner_comandante(string name) {
	comandante=lower_case(name);
	save_object(SFILE,1);
	}
void poner_consejero(string name) {
	consejeros+=({lower_case(name)});
	save_object(SFILE,1);
	}
void poner_miliciano(string name) {
	milicianos+=({lower_case(name)});
	save_object(SFILE,1);
	}
void quitar_comandante() {
	comandante="";
	save_object(SFILE,1);
	}
void quitar_consejero(string name) {
	consejeros-=({lower_case(name)});
	save_object(SFILE,1);
	}
void quitar_miliciano(string name) {
	milicianos-=({lower_case(name)});
	save_object(SFILE,1);
	}
