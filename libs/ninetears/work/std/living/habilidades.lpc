// Vilat 03.10.2002
// Sistema de Skills :) A q mola
mapping habil=([]);
int disp_sp=0;
int max_sp=0;
int sp=0;

void arrancar_habilidades() {
	add_action("mostrar_habilidades","skills");
	}

int query_habilidad(string habilidad) {
	if(!habilidad) return 0;
	habilidad=lower_case(habilidad);
	return habil[habilidad];
	}

int set_habilidad(string habilidad,int valor) {
	if(!habilidad||valor<0||valor>100) return 0;
	habilidad=lower_case(habilidad);
	if(!valor) habil=m_delete(habil,habilidad);
	else habil[habilidad]=valor;
	return valor;
	}

int remove_habilidad(string habilidad) {
	habil=m_delete(habil,habilidad);
	return 0;
	}

int adjust_habilidad(string habilidad,int valor) {
	int i;
	i=habil[habilidad]+valor;
	if(i<0) i=0;
	else if(i>100) i=100;
	return set_habilidad(habilidad,i);
	}

mapping query_habilidades() { return habil; }

int mostrar_habilidades(string str) {
	int i,a;
	string mensaje="Informacion de Skills:\n";
	if(!sizeof(habil)) return notify_fail("No tienes habilidades.\nTienes "+(string)disp_sp+" puntos de Skill disponibles.\n");
	mensaje+="%^BOLD%^Habilidad                     Nivel%^RESET%^\n";
	for(a=0;a<sizeof(habil);a++) {
		mensaje+=capitalize(keys(habil)[a]);
		for(i=strlen(keys(habil)[a]);i<30;i++) mensaje+=" ";
		mensaje+=(string)habil[keys(habil)[a]]+"\n";
		}
	mensaje+="\nTienes "+(string)disp_sp+" puntos de Skill disponibles.\n\n";
	tell_object(TO,mensaje);
	return 1;
	}

int query_sp() { return sp; }
int query_max_sp() { return max_sp; }
int query_disp_sp() { return disp_sp; }

int set_sp(int i) {
	if(i<0) return sp=0;
	if(i>max_sp) return sp=max_sp;
	return sp=i;
	}

int set_max_sp(int i) {
	if(i<0) return max_sp=0;
	return max_sp=i;
	}

int set_disp_sp(int i) {
	if(i<0) return disp_sp=0;
	return disp_sp=i;
	}

int adjust_sp(int i) {
	if(sp+i<0) return sp=0;
	if(sp+i>max_sp) return sp=max_sp;
	return sp+=i;
	}

int adjust_max_sp(int i) {
	if(max_sp+i<0) return max_sp=0;
	return max_sp+=i;
	}

int adjust_disp_sp(int i) {
	if(disp_sp+i<0) return disp_sp=0;
	return disp_sp+=i;
	}

