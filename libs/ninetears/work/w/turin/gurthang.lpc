#define DANYO 600

inherit "/obj/weapon";

void setup () {
	set_base_weapon ("esp_dosmanos");
	set_name ("gurthang, la espada legendaria");
	add_alias ("gurthang");
	add_alias ("legendaria");
	set_short ("%^BLUE%^%^BOLD%^ Gurthang, %^YELLOW%^ la Espada Legendaria %^RESET%^");
	set_long ("La grandiosa e invencible Gurthang, la espada del gran heroe humano Turin Turambar, con la que acabo con la vida de Glaurung, el padre de los Drgaones Antiguos, y con la que mas tarde se suicido, haciendo que esta se quebrara en pedazos. Al hacerse inmortal, Turin la forjo de nuevo para demostrar a los incredulos que los que siguen el camino recto tienen mayores beneficios.
");
set_main_plural ("%^BLUE%^%^BOLD%^ Gurthang, %^YELLOW%^ la Espada Legendaria %^RESET%^");
	add_plural ("espadas");
	add_plural ("legendarias");
	set_enchant (25);
	reset_drop();
}

void init () {
	::init ();
	add_action ("absorcion","absorver");
}

int absorcion (string str) {
	object objetivo;
	if (TO->query_timed_property("absorviendo")) return notify_fail ("Aun estoy absorviendo el alma anterior.
");
	if (!str) return notify_fail ("Dime que alma quieres que absorva, mi gran Senyor.
");
	objetivo=find_living( lower_case(str) );
	if (!objetivo) return notify_fail(CAP(str)+"debe de estar ante mi para que le absorva el alma.
");
	if (ENV(objetivo)!=ENV(TP)) return notify_fail (objetivo->query_cap_name()+"esta fuera de mi alcance, por ahora.
");
	tell_object (TP,"La espada"+TO->query_short()+ "profiere un grito aterrador mientras separa el alma de " +objetivo->query_cap_name()+" de su cuerpo.
");
	tell_object (objetivo,TP->query_cap_name()+"da la orden a"+TO->query_short()+"de que consuma tu alma, lo que esta hace con gran placer.
");
	tell_room (ENV(TP),objetivo->query_cap_name()+ " grita de dolor, pero el grito de "+TO->query_short()+" no deja oir nada mas.
");
	objetivo->do_death(TP);
	TO->add_timed_property ("absorviendo",1,30);
	

		return 1;

}
