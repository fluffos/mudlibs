inherit "/obj/monster";

void setup() {
      set_name("nephilim");
      set_short("%^GREEN%^Neph%^BLACK%^BOLD%^ilim%^RESET%^");
      set_al(60);
      set_race("goblin");
      set_gender(1);
      set_level(128);
      set_wimpy(0);
      set_max_hp(query_level() * 5000);
      set_hp(query_max_hp());
      set_max_gp(query_level() * 8000);
      set_gp(query_max_gp());
      set_random_stats(90, 98);
      set_long("%^GREEN%^Neph%^BLACK%^BOLD%^ilim%^RESET%^\n\n"
      		"Nephilim J'Zhadra es un pequenyo goblin, de apenas unos pies de altura, y su "
		"fibrosa delgadez te llama la atencion. En su cara, dos globos oculares negros "
		"como el ebano te analizan con la mirada perdida en el infinito, a la par que "
		"irradian un aura grisacea que te pone los pelos de punta. Una larga cabellera "
		"grisacea esconde la joven cara de este goblin, trenzada en sus extremos y "
		"decorada con motivos shamanicos. Los fibrosos brazos de Nephilim estan tatuados "
		"a su vez con motivos semejantes a los de su cabellera, pero uno de ellos, que "
		"representa el esqueleto de un lobo, te llama la atencion sobre los demas, "
		"puesto que emite una leve aura plateada. La enfermedad y el dolor rodean el "
		"espiritu de este misterioso goblin, parte de su cuerpo parece estar en avanzado "
		"estado de descomposicion. Seguramente es el precio que ha tenido que pagar por "
		"haber alcanzado vastos conocimientos de shamaneria y brujeria.\n"
		"Pertenece al Clan Senyores del Abismo.\n"
		"Esta buscado por la guardia de Dendara.\n"
		"Esta desterrado de Takome.\n"
		"Sus ojos recuerdan a los de un felino.\n");          
} /* setup */

void init()
{
	::init();
	add_action("prohibido", ({"call","goto","kill","matar","formular","trans","dest","cre","say","'","quit","golpear","bash","rabia","berserk","cargar","carga"}));
} /* init */

void prohibido()
{
	notify_fail("Nephilim susurra a tu oido: Tu poder no sirve de nada bajo mi presencia...\n");
        this_player()->do_death();
}
