inherit "/std/vaults/vault_room";

void setup()
{
	::setup();
	set_group_owner(({"%^BOLD%^Bright %^RESET%^FIC Lords"}));
	set_saqueable(1);

	// ESTO ESTA PUESTO AKI SOLO COMO EJEMPLO, EN CADA FUNCION HACEIS
	// LAS COMPROBACIONES QUE QUERAIS Y DEVOLVEREIS 1 SI SE PERMITE LA OPERACION
	// Y 0 SI NO SE PERMITE.
	set_depositar_fn("dep_fn");
	set_recuperar_fn("rec_fn");
	set_saquear_fn("saq_fn");

	// ESTA FUNCION DEVUELVE IWAL QUE LAS OTRAS, PERO LO QUE DIGA ESTA FUNCION VA A
	// MISA EN EL SENTIDO DE QUE SI DEWELVE 1, NINGUNA OTRA RESTRICCION HABRA PARA
	// PARA PERMITIR DEPOSITAR EL OBJETO, POR LO Q SE DEPOSITARA SIN PROBLEMAS.
	// ESTA FUNCION NO LLEGA A SER LLAMADA SI HAY UNA DEPOSITAR_FN QUE DEWELVE 0.
	set_allow_fn("all_fn");

	set_short("Clan %^BOLD%^Bright %^RESET%^FIC Lords: Baul");
	set_long("Clan %^BOLD%^Bright %^RESET%^FIC Lords: Baul\n\n"
			"\tEn esta estancia los miembros del clan depositan cuantos objetos preciados, "
			"encuentran en los reinos y cuantas armas y material de guerra les puede ser "
			"para mantener la supremacia del bien en los Reinos. En este lugar Haggard se "
			"pasa grandes cantidades de tiempo, mirando el baul y teniendo pensamientos "
			"impuros relativos a dinero, equipo y humanas o elfas.\n\n");

	add_item("baul", "Un bello baul preside la sala, en el los miembros del gremio guardan "
				"sus preciadas pertenencias.\n");
	add_exit("este", "/room/clanes/ficlords_main", "corridor");
}

int dep_fn(object myp, string que)
{
	return 1;
}

int rec_fn(object myp, string que)
{
	return 1;
}

int saq_fn(object myp, string que)
{
	if (myp->query_race_name() == "drow") {
		tell_object(myp, "Tu acto sera recordado por los FIC Lords y tu oscura piel sera "
				"purificada\ny palidecida porque ellos te enviaran a ti y a los tuyos "
				"de cabeza al infierno.\n");
	}
	return 1;
}

int all_fn(object myp, object obj)
{
	return 1;
}