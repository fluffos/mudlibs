inherit "/obj/monster";

int relatando = 0;

void setup() {
      set_name("ogro");
      set_short("Ogro %^BLACK%^BOLD%^ciego%^RESET%^");
      add_adjective("ciego");      
      set_al(60);
      set_main_plural("Ogros ciego");
      set_race("ogre");
      set_gender(1);
      set_level(31+random(10));
      set_wimpy(0);
      set_max_hp(query_level() * 20);
      set_hp(query_max_hp());
      set_max_gp(query_level() * 10);
      set_gp(query_max_gp());
      set_random_stats(20, 22);
      set_long("El Ogro %^BLACK%^BOLD%^Ciego%^RESET%^\n\n"
		"Una inmensa criatura, de casi tres metros de altura, y "
		"la fuerza de decenas de seres humanos, que ha perdido toda "
		"su fiereza. Lo deduces cuando la ves, confundida, alterada, "
		"y asustada. Parece haber sufrido mucho, tanto que ha perdido "
		"las ganas de vivir y de matar. Te preguntas que le ha "
		"podido ocurrir para llegar a este estado.\n");
      adjust_money(random(20), "gold");
      load_chat(50,
         ({
               1, ":grunye: Nadie cree mi... mi historia...",
               1, ":se palpa las cuevas oculares con sus bastas manos.",
               3, "'Groargh... el shaman... la luz...",
               2, ":susurra entre grunyidos: Escuchame... la luz...",
          }));
          
} /* setup */

void init()
{
	::init();
	add_action("escuchar", "escuchar");
	relatando = 0;
} /* init */

void cuenta_historia(object myp)
{
	do_command("decir Gran tropa... luchar contra gran espectro de J'Zhadra... mi senyor J'Zhadra muerto por locura...");
	call_out("cuenta0", 2, myp);
} /* cuenta_historia */

void cuenta0(object myp)
{
	do_command("decir Morir todos... morir por la luz de sus ojos... su luz quemar nuestros ojos... derretir nuestra sesera...");
	call_out("cuenta1", 3, myp);
} /* cuenta0 */

void cuenta1(object myp)
{
	tell_room(ENV(TO), QCN + " comienza a lloriquear entre grunyidos y lamentos.\n");
	call_out("cuenta2", 4, myp);
} /* cuenta1 */	

void cuenta2(object myp)
{
	do_command("decir Solo yo sobrevivir... perder ojos... no entrar... no llamar al gran espectro...");
      relatando = 0;
} /* cuenta2 */	


int escuchar(string str)
{
	object myp = TP;

	if (relatando) {
		do_command("say Argh... espera... a que termine...");
		notify_fail("");
		return 0;
	}

	if (str == "ogro") {
		cuenta_historia(myp);
		relatando = 1;
		return 1;
	} else {
		notify_fail("Escuchar a quien?\n");
		return 0;
	}
} /* entregar */
