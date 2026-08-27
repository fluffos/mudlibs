inherit "/std/room";

void setup()
{
	set_short("%^ORANGE%^Arckium Krash%^RESET%^: Gremio de los Khazad Dum Uzbad\n");
	set_long("%^ORANGE%^Arckium Krash%^RESET%^: Gremio de los Khazad Dum Uzbad\n\n"
	"	En este maravilloso lugar los enanos con espiritu guerrero del"
	" Arckium Krash entrenan para ser los mas poderosos newbies de la historia"
	" con una dopez comparable a la mafia de inmortales de otros muds.\n\n");
	set_light(50);
	add_sign("Un gran signo con letras plateadas.\n", "Alistate aqui para pertenecer a este gremio.\n");
	add_exit("sur", "/room/camino_avalon/camino08", "door");
}

void init()
{
	::init();
	add_action("alist", "alist*arse");
	add_action("alist", "unir*se");
	add_action("alist", "join");
}

int alist(string str)
{
	if (TP->query_guild_ob()) {
		notify_fail("Ya perteneces a otro gremio.\n");
		return 0;
	}
	tell_object(TP, "Tirando fuerza extrema.\nAhora eres un nuevo miembro del gremio Khazad Dum Uzbad.\n\n");
	tell_room(ENV(TP), TP->QCN + " se une al gremio.\n", TP);
	tell_object(TP, "\nDe pronto Tyrael aparece ante ti y diriges tu mirada sumisamente a el.\n\n");
	tell_room(ENV(TP), "Tyrael aparece de pronto atraido por la accion de "+TP->QCN+".\n", TP);
	tell_room(ENV(TP), "Tyrael pregunta: %^BOLD%^CYAN%^COMO OSAS HACER ESO, ACASO TE CREES QUE ESTAS EN PUSA??%^RESET%^\n\n"
	"Tyrael exclama: %^BOLD%^CYAN%^Esta afrenta no quedara impune, MUERE "+TP->QCN+"!%^RESET%^\n");
	TP->do_death();
	tell_room(ENV(TP), "Tyrael desaparece hablando y gritando en un idioma que no conoces.\n");
	return 1;
}