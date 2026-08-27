// Patric

#define MURO "/d/gremios/hechizos/mg/muro_ilusorio"

inherit "/obj/monster";

void setup() {
      set_name("patric");
      set_short("Patric");
      set_al(60);
      set_main_plural("patrics");
      add_alias("patricio");
      set_race("human");
	set_gender(1);
      set_level(71+random(10));
      set_wimpy(0);
	set_max_hp(query_level() * 20 + 1000);
	set_hp(query_max_hp());
	set_max_gp(1000);
	set_gp(1000);
      set_random_stats(20, 22);
      set_long("Patric, el guardian del gremio de los Caballeros de la %^BOLD%^YELLOW%^Luz%^RESET%^.\n\n"
		"Es un crack, yo de ti no me meteria con el.\n\n");
      adjust_money(random(300), "gold");
      set_aggressive(55555);
	new("/baseobs/guildmasters/obj/patric/luzdelamanecer")->move(this_object());
	new("/baseobs/guildmasters/obj/patric/desplazadordealmas")->move(this_object());
	new("/baseobs/guildmasters/obj/patric/armaduradeluz")->move(this_object());
        new("/baseobs/armours/amulet")->move(this_object());
        new("/baseobs/armours/bracers")->move(this_object());
        new("/baseobs/armours/ring")->move(this_object());
        new("/baseobs/armours/helmet")->move(this_object());
	this_object()->init_equip();
      load_chat(20,
         ({
               1, "'yo de ti no me meteria en problemas... grrrr.",
               1, ":te mira pensativamente.",
//               1, "@grin evilly $lname$",
               1, ":pasa su lengua por el filo de su poderosa arma.",
               1, "'Sexo, Drogas y Rockn'roll, y si eso no es posible, Muerte!",
               1, "'Que vengan los drows, que vengan...",
          }));
      load_a_chat(40,
         ({
               1, "'nadie osa perturbar la paz de un paladin!",
		1, "'muerte a todos los enemigos del bien!",
               1, ":te mira con los ojos inyectados en sangre.",
          }));
	set_guild("paladin");
	set_guild_ob("/d/gremios/guerreros/paladin");
	add_attack_spell(80, "cargar", ({"/d/gremios/comandos/carga", "carga",0,1}));
	add_property("NO_BUDGE", 1); // para q ningun hechizo lo haga marcharse de aki
}

void init() {
	::init();
	add_action("do_bow", "bow");
}

int do_bow()
{
if (this_player()->query_guild_ob()!="/d/gremios/guerreros/paladin")
        return 0;


if (this_player()->query_property("simbolopaladin"))
{
	tell_object(this_player(), "Los simbolos no son para malgastarlos.. espera un poco.\n");
	return 0;
}
tell_object(this_player(), "Patric te dice: aqui tienes tu simbolo sagrado.\n");
clone_object("/d/gremios/hechizos/items/paltf_sy")->move(this_player());
this_player()->add_timed_property("simbolopaladin",1,1000);
}

void attack_by(object ob)
{
	object *g = find_match("caballero", ETO);
	
	if (sizeof(g)) {
		TO->set_protector(g[0]);
		g[0]->attack_ob(ob);
		g[0]->murito();
	}
	::attack_by(ob);
}

int already_attacking(object me,object victim);

void event_enter(object enterer, string message)
{
	string msg;
	int lvl, luchando = 0;
	object *ob;

	if (!enterer) // la documentacion dice q hay q mirar esto
		return;
		
	//command("say "+enterer->QCN+" ha llegado.");

	if (enterer->query_dead())
		return;

	if (already_attacking(this_object(), enterer) || enterer->query_guild_name() == "caballero de jade") {
		if (!this_object()->query_dead()) {
				command("say Pagaras tu osadia con tu SANGRE!\n");
				command("guild on");
			        command("guild %^BOLD%^RED%^Me ataca "+enterer->query_cap_name()+"!!!!! Mueroh!%^YELLOW%^ VENID A AYUDARMEEEEEEEEEEE!!!!!!!!%^RESET%^");
				command("say Maldito bastardo, ahora moriras!\n");
			ob = find_match("caballero", ETO);
			if (sizeof(ob)) {
				TO->set_protector(ob[0]);
				ob[0]->attack_ob(enterer);
			}
			TO->attack_ob(enterer);
		}
		return;
	}

	// hay q hacer de alguna forma q no salude a su CUERPO cuando muera, aunque
	// lo de comprobar el gremio rula, pero como hariamos si saludase a tol mundo?

	if (enterer->query_guild_name() != "paladin")
		return;

	// buscar propiedad o fun q me diga si esta en peleas pa no saludar XD

	if (query_fighting()) { // no saludamos y advertimos al que entra
		tell_object(enterer, "Observas a Patric cabreado, alguna deshonra anda cerca.\n");
		return;
	}

	lvl = enterer->query_level();
	switch(lvl) {
		case 0..10:
			msg = "discipulo";
			break;
		case 11..20:
			msg = "soldado";
			break;
		case 21..25:
			msg = "sargento";
			break;
		case 26..30:
			msg = "capitan";
			break;
		case 31..35:
			msg = "teniente";
			break;
		case 36..40:
			msg = "coronel";
			break;
		case 41..45:
			msg = "teniente coronel";
			break;
		case 46..50:
			msg = "general";
			break;
		case 51..55:
			msg = "lord";
			break;
		case 56..60:
			msg = "gran lord";
			break;
		default:
			msg = "mi senyor";
	}
	command("say Saludos, "+ msg + " " + enterer->query_short() + ".\n");
}

// sacado de /d/gremios/comandos/base_command.c y modificado

int already_attacking(object me,object victim){
   if(member_array(me,victim->query_attacker_list()) != -1)
      return 1;
   if(member_array(me,victim->query_call_outed()) != -1) 
      return 1;
   return 0;
}


                                                         
