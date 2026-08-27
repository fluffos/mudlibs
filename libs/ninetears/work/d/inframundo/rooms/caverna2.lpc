//Gareth 21.11.02

#include "/d/inframundo/path.h"
inherit "/std/inframundo";

void setup() {
	set_short("%^WHITE%^%^BOLD%^Caverna del %^RESET%^%^ORANGE%^Yeti%^RESET%^");
	set_long(query_short()+"\n Pasas por la entrada, y entras en una estancia casi a oscuras. Colgadas en lo que parece ser la pared, hay unas argollas sujetando antorchas con llamas azules, que dan una pequenya iluminacion a la caverna. Del techo cuelgan telaranyas de diferentes tamanyos, y mucha suciedad. La cueva no tiene ningun mobiliario, excepto un rincon que parece estar lleno de comida.\n\n");
   	add_item("telaranyas","Blancas telaranyas cuelgan del techo de la gruta, llegando algunas a tocar el suelo\n");
   	add_item("comida","Trozos de carne seca y pescados, amontonados en un rincon de la cueva.\n");
   	add_sound(({"habitacion","sala","aire"}),"De alguna parte de la caverna te llega el sonido de unos berridos incoherentes que te ponen los pelos de punta.\n");
   	add_exit("fuera",ROOMS+"caverna1","door");
}