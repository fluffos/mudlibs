inherit "/obj/armour";

void setup() {
	set_base_armour("cuero");
	set_name("armadura");
	add_alias("melodia");
	set_short("Armadura de %^BLACK%^BOLD%^La %^BLUE%^Me%^YELLOW%^lo%^MAGENTA%^di%^GREEN%^a%^RESET%^");
	set_long(query_short()+"\n Es una armadura de colores, hecha de cuero pero quiza con alguna propiedad magica, cubre los brazos y el torso y cuando se mueve parece brillar como el metal reflejado al sol, en multitud de tonos brillantes.\n");
	set_main_plural("Armaduras de %^BLACK%^BOLD%^La %^BLUE%^Me%^YELLOW%^lo%^MAGENTA%^di%^GREEN%^a%^RESET%^");
	add_plural("armaduras");
	add_plural("melodias");
	set_enchant(5);
	reset_drop();
	add_property("no_steal",1);
	}

void init() {
	::init();
	add_action("do_cancion","cante");
	}

int do_cancion(string str) {
	object *victimas;
	if (TP->query_cap_name()!="Maele") return notify_fail("Solo Maele puede usar apropiadamente esta armadura.\n");
	if (member_array(TO,TP->query_worn_ob())==-1) return notify_fail("Tienes que tener puesta la Armadura para poder usar su poder.\n");
	switch (str) {
		case "de muerte": 
		victimas=all_inventory(environment(TP));
		for (int a=0;a<sizeof(victimas);a++) {
			if(living(victimas[a])) {
				if(victimas[a]->query_name()!="maele") {
					tell_object(TP,"Tu armadura comienza a emitir un sonido y la cabeza de "+victimas[a]->query_cap_name()+", parece que va a estallar.\n");
					tell_object(victimas[a],"La armadura de "+TP->query_cap_name()+" comienza a emitir un cantico que se te mete en la cabeza y notas como si te fuera a estallar.\n");
					victimas[a]->do_death(TP);
					}
				if (sizeof(victimas)==0 && victimas[a]->query_name()=="maele") return notify_fail("Nadie a quien matar.\n");
			}
			}
			break;
		case "de vida":
		victimas=all_inventory(ENV(TP));
		for (int b=0;b<sizeof(victimas);b++) {
			if(living(victimas[b])){
				tell_object(TP,"Tu armadura emite un sonido tranquilizador y lleno de vida que te relaja a ti y atodos los presentes.\n");
				tell_object(victimas[b],"La armadura de "+TP->query_cap_name()+" emite un sonido tranquilizador y lleno de vida que te relaja.\n");
				victimas[b]->adjust_hp(victimas[b]->query_max_hp());
				
			}
			}
		break;
		}
	return 1;
	}
int set_in_use(int i,object amo) {
	if(amo->query_name()!="maele"){
		tell_object(TP,"La armadura rechaza tu cuerpo y no se deja poner.\n");
		i=0;
	}
	return ::set_in_use(i);
}
