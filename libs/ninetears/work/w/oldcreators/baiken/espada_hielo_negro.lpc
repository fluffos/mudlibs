//Vhurkul 21.07.2002
inherit "/obj/weapon";

void setup()
{
	set_base_weapon("esp_corta");
	set_name("helada");
	set_short("Espada de %^BOLD%^BLACK%^Hielo Negro%^RESET%^");
	set_main_plural("espadas de %^BOLD%^BLACK%^Hielo Negro%^RESET%^");
	set_long("Una impresionante espada de hielo negro que arranca las almas de sus enemigos.\n");
	add_alias(({"espada","hielo"}));
	add_plural("espadas");
	set_enchant(1);
	reset_drop();
}

void write_message(string happen, int dam, string w_type, object me, object him)
{
	int muerto=0;
	if (dam>0) muerto=1;
	tell_room(ENV(me), me->QCN + " raja con su "+w_type+" a "+him->QCN+", arrancando su alma.\n", ({me,him}));
	tell_object(me, "Rajas con tu "+w_type+" a "+him->QCN+" arrancando su alma.\n");
	tell_object(him, me->QCN+" te raja con su "+w_type+". Tu alma te abandona.\n");
		
	if (muerto) him->do_death(me);

}