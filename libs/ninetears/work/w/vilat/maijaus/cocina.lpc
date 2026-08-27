// Vilat 20.07.2002 (en realidad es importado de pusa, por entonces no sabia ni que era 9T xD) Joder... por entonces me estoy dando cuenta de que era un inutil hace 3 meses :P
// Remodelado en 29.10.2002 para testear las tabernas
// Los sitios donde se vende comida heredan /std/hostal.c
inherit "/std/hostal";

void setup() {
  	set_short("%^BOLD%^Despensa de Vilat%^RESET%^");
  	set_long("Esta habitacion es mas fria que las demas, y tiene toda la pinta de haber sido un almacen de comida, aunque actualmente Patric la ha habilitado como Taberna.\n");
  	add_item(({"pared","suelo","hielo"}),"La estancia esta construida en frio hielo negro.");
	// Las cosas especiales de las tabernas
  	set_salida("/w/vilat/maijaus/lvl-1"); // esto importantisimo, es la salida del establecimiento por donde no podemos llevarnos los platos
  	set_dependiente("/baseobs/guildmasters/patric"); // Patric es polivalente xD tendero, herrero, guildmaster, tabernero (el proximo sera Patric chuloputas)
  	add_cartel(); // Un cartel con los comandos basicos (ya sabeis la mecanica que uso con los carteles, si no miraos la tienda o la herreria
  	add_plato("/baseobs/platos/macarrones"); // con esto anyadimos platos (comida y bebida)
	add_plato("/baseobs/platos/antirresaca");
	add_plato("/baseobs/platos/chupito");
	set_calidad(5); // Los "tenedores" del local, de 0 (antro) a 5 (restaurant de lujo)
	// Los ajustes, prohibiciones y permisiones van igual que en las tiendas
	add_ajuste("raza","halfling",200);
	add_prohibido("raza","elfo");
	}
