inherit "/std/room";

void setup()
{
	set_light(70);
	set_short("Entrada al Clan %^BOLD%^Bright %^RESET%^FIC Lords");
	set_long("Entrada al Clan %^BOLD%^Bright %^RESET%^FIC Lords\n\n"
			"Te encuentras ante un portal hecho en marmol, reluciente y brillante, "
			"como los miembros de este clan. El clan fue fundado por Ghejed hace muchos "
			"anyos, junto con Barthleby y Haggard, fueron la estirpe colonizadora de los "
			"reinos proviniente de otra dimension llamada Fuckin' FIC.\n\n");
	add_item(({"portal","marmol"}), "Un enorme portal blanco hecho de puro marmol reluciente "
				"da la bienvenida a los miembros de este clan.\n");

	add_exit("sur","/room/camino_avalon/camino15","door");
	add_exit("noroeste", "/room/clanes/ficlords_main", "door");
	modify_exit("noroeste", ({"function", "go_in"}));
}

int go_in(string str, object ob, string special_mess)
{
	if (ob->query_group_name() == "%^BOLD%^Bright %^RESET%^FIC Lords")
		return 1;
	notify_fail("Aun no es hora de entrar aqui, espera a que los clanes sean asaltables.\n");
	return 0;
}