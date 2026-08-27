//Gareth 23.11.02

inherit "obj/monster";

void setup()
{	set_name("asesino");
  	set_short("Asesino");
  	set_long("Un espiritu vestido con unos harapos viejos y rotos, que empunya un cuchillo lleno de sangre seca.\n");
	set_main_plural("asesinos");
	add_alias("asesino");
	set_random_stats(16,18);
  	set_level(50);
  	set_gender(roll(1,2));
  	add_clone("/baseobs/weapons/cuchillo",1);
  	init_equip();
  	
  	load_chat(15,({
 		1, ":se acerca a la llama, y en ese momento una sombra se acerca por su espalda y lo estrangula.",
 		1, ":intenta liberarse de las garras de la Sombra, pero no lo consigue.",
 		}));  	
}