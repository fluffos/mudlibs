inherit "/std/inframundo";

object vilat;

void setup() {
	set_short("%^RED%^BOLD%^Interior de la Torre de Vilat%^RESET%^");
	set_long(query_short()+"\nTe encuentras es el interior de una magnifica torre de Hielo Negro, que refulge emitiendo misteriosos brillos bajo la tenue luz de las antorchas. Curiosamente el fuego de las antorchas no parece normal, pues es de color indigo... Aunque no es lo unico extranyo aqui. Las paredes rezuman sangre y en una de ellas hay abierta una inmensa claraboya a traves de la cual se ve un panorama terrorifico. Por ultimo un espejo enmarcado con antiguas runas se encuentra apoyado en una de las paredes, pero no capta ninguna imagen...\n");
	if(!vilat) vilat=clone_object("/d/inframundo/npcs/vilat");
	if(vilat) vilat->move(TO);
	add_exit("espejo","/room/entryroom");
	add_exit("fuera","/d/inframundo/rooms/torre");
	modify_exit("espejo",({"function","espejo"}));
	}

int espejo() {
	string ret="El espejo te devuelve tu cuerpo mortal";
	if(!TP->query_dead()) return notify_fail("Chocas contra la pulida superficie del espejo.\n");
	TP->remove_ghost();
	if(TP->query_level()>9) {
		TP->adjust_con(-1);
		ret+=", pero por alguna razon te sientes mas debil";
		}
	tell_object(TP,ret+".\n");
	return 1;
	}