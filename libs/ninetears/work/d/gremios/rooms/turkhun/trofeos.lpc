//Gareth 9.12.02

#include "/d/gremios/path.h"
#define CABEZAS "/d/gremios/rooms/khurgars/cabezas.txt"
inherit "/std/room";

void setup() {
	set_short("%^RED%^%^BOLD%^Gremio de los Guerreros Turkhun: %^WHITE%^%^BOLD%^Sala de Trofeos%^RESET%^");
	set_long(query_short()+"\n\n    Te encuentras en la sala mas profunda de las "
					"cavernas del gremio. Aqui los Guerreros Turkhun "
					"almacenan todos sus trofeos, normalmente cabezas"
					" de sus mas duros combates. Largas estanterias"
					" con vitrinas cubren todo el gran espacio de la"
					" sala, con cabezas dentro. Estan decapitadas "
					"limpiamente, y el gesto de algunas de ellas te "
					"produce escalofrios al imaginarte como pudo morir.\n");
	
	add_item("estanterias","Unas largas y grandes estanterias que ocupan toda la sala\n");
	add_item("cabezas","Cabezas de seres de diferentes razas, aunque predominan las cabezas de orcos y enanos.\n");
	
	add_sign("Un tablon clavado en la pared.\n","Depositar cabeza -> deposita una cabeza que poseas en las vitrinas\nVer              -> lista todas las cabezas depositadas\n","tablon","tablon");
	
	add_exit("arriba",GUILD_TURKHUN+"herreria","corridor");
}

void init()
{
	::init();
	add_action("dep_cabeza", "depositar");
	add_action("ver_cabezas", "ver");
}

int dep_cabeza(string str)
{
	object me = TP;
	object *obs;
	
	
	obs = find_match(str,me);
	if(sizeof(obs) && obs[0]->query_cabeza())
	{
		write_file(CABEZAS,"\n - "+obs[0]->query_short()+" depositada por "+me->query_cap_name()+".");
		tell_object(TP, "Depositas la cabeza en una de las vitrinas vacias de la sala.\n");
		tell_room(environment(me), ""+me->query_cap_name()+" deposita "+obs[0]->query_short()+" en las vitrinas.\n", me);
		obs[0]->dest_me();
		return 1;
	}
	else
	{
		return notify_fail("No tienes ninguna cabeza llamada asi en tu inventario.\n");
	}
}


int ver_cabezas() {
	tell_object(TP, read_file(CABEZAS));
	return 1;
}