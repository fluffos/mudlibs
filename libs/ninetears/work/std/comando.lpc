// Vilat 18.11.2002 - Comando base

string ayuda;
string argumento;
object objeto;
int retardo,gps,eps;
string mov;
object envinicio;

int precondiciones() {
	if(objeto->query_gp()<gps) {
		tell_object(objeto,"No tienes suficiente mana.\n");
		return 0;
		}
	if(objeto->query_ep()<eps) {
		tell_object(objeto,"Estas agotad"+(objeto->query_gender()-1?"a":"o")+".\n");
		return 0;
		}
	return 1;
	}
void mostrar_mensajes(int r) { return; }
int condiciones() {
	if(mov&&mov!="") if(ENV(objeto)!=envinicio) {
		tell_object(objeto,mov+"\n");
		return 0;
		}
	return 1;
	}

object query_ejecutor() { return objeto; }
string query_argumento() { return argumento; }

int efecto(string str,object x) {
	if(gps) x->adjust_gp(-gps);
	if(eps) x->adjust_ep(-eps);
	return 1;
	}

void inicio(string str, object x) {
	TO->setup();
	argumento=str;
	if(!x) x=TP;
	objeto=x;
	notify_fail("");
	if(!precondiciones()) return 0;
	envinicio=ENV(objeto);
	if(!retardo) efecto(argumento,objeto);
	else call_out("retardar",0);
	}

void poner_ayuda(string str) { ayuda=str; }
string help() { return ayuda; }

void retardar() {
	if(!condiciones()) return;
	if(!retardo) efecto(argumento,objeto);
	else {
		mostrar_mensajes(retardo);
		retardo--;
		call_out("retardar",1);
		}
	}

void poner_retardo(int jb) { retardo=jb; }

varargs void impedir_movimiento(string mensaje) {
	if(!mensaje) mov="El movimiento te impide llevar a cabo el comando.\n";
	else mov=mensaje;
	}

void gasta_energia(int i) { eps=i; }
void gasta_mana(int i) { gps=i; }