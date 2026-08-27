// Vilat 17.09.2002
inherit "/std/object";

#define LOG "/w/vilat/multi.log"

mixed rooms_cargadas=({});
mixed ips_usadas=({});

void setup() {
 set_name("memoriah");
 set_short("Controlador de memoria");
 set_long("Cosa que controla de momento solo las rooms en memoria pero en el futuro se encargara de evitar el multi y kien sabe q mas... \n");
 }

mixed query_rooms_cargadas() { return rooms_cargadas; }

int cargar_room(object room) {
 if (!room || member_array(room,rooms_cargadas) != -1) return 0;
 rooms_cargadas += ({room});
 return 1;
 }

int descargar_room(object room) {
 if (!room || member_array(room,rooms_cargadas) == -1) return 0;
 for (int i=0;i<sizeof(rooms_cargadas);i++) if (rooms_cargadas[i]==room) rooms_cargadas=delete(rooms_cargadas,i,1);
 return 1;
 }

mixed query_ips_usadas() { return ips_usadas; }

int add_ip(string ip, string nombre, int nivel) {
	int i;
	string *nombres=({});

	if (i=member_array(ip,ips_usadas) == -1 ) ips_usadas+=({ip,({nombre}),nivel});
	else {
		for (i=0;i<sizeof(ips_usadas);i++) if (ips_usadas[i]==ip) break;
		nombres=ips_usadas[i+1];
		nombres+=({nombre});
		ips_usadas[i+1]=nombres;
		nivel+=ips_usadas[i+2];
		ips_usadas[i+2]=nivel;
		if (sizeof(nombres)>1) if (nivel<=0) for (i=0;i<sizeof(nombres);i++) write_file(LOG,"MULTI: "+nombres[i]+" desde la IP: "+ip+". ("+ctime(time())+")\n");
		}
	return 1;
	}

int remove_ip(string ip, string nombre, int nivel) {
	int i;
	string *nombres;

	i=member_array(ip,ips_usadas);
	if (i==-1) return 0;
	for (i=0;i<sizeof(ips_usadas);i++) if (ips_usadas[i]==ip) break;
	nombres=ips_usadas[i+1];
	if (sizeof(nombres)<=1) ips_usadas=delete(ips_usadas,i,3);
	else {
		nombres=delete(nombres,member_array(nombre,nombres),1);
		nivel=ips_usadas[i+2]-nivel;
		ips_usadas[i+1]=nombres;
		ips_usadas[i+2]=nivel;
		if (sizeof(nombres)>1) if (nivel<=0) for (i=0;i<sizeof(nombres);i++) write_file(LOG,"MULTI: "+nombres[i]+" desde la IP: "+ip+". ("+ctime(time())+")\n");
		}
	return 1;
	}

