// Arturin

inherit "/obj/monster";

void setup() {
      set_name("korn");
      set_short("Korn, el %^BLUE%^Chico del Maiz%^RESET%^");
      set_al(60);
      set_main_plural("Korns");
      add_alias("maiz");
      set_race("drow");
	set_gender(1);
      set_level(81+random(10));
      set_wimpy(0);
	set_max_hp(query_level() * 10 + 1000);
	set_hp(query_max_hp());
	set_max_gp(1000);
	set_gp(1000);
      set_random_stats(20, 22);
      set_long("Korn.\n\n"
                "Guildmaster MagoLadron.\n\n");
      adjust_money(random(300), "gold");
//      set_aggressive(0);
        new("/d/driade/items/aspid")->move(this_object());
        new("/d/driade/items/aspid")->move(this_object());
	this_object()->init_equip();
      load_chat(20,
         ({
               1, "'Hay mucho Freak suelto.",
               1, ":te mira pensativamente.",
//               1, "@grin evilly $lname$",
               1, ":pasa su lengua por el filo de su poderosa arma.",
               1, "'Sexo, Drogas y Rockn'roll, y si eso no es posible, Muerte!",
               1, "'Emboscar es un placer...",
          }));
      load_a_chat(40,
         ({
               1, "'Ahora veras como me las gasto!",
		1, "'Te voy a abollar la cabeza!",
               1, ":te mira con los ojos inyectados en sangre.",
//               1, "@grin evilly $lname$",
          }));
        set_guild("misc/wizthief");
        set_guild_ob("/d/gremios/misc/wizthief");
}
/*
void init() {
	::init();
	add_action("do_bow", "bow");
}

int do_bow()
{
	tell_object(this_player(), "Patric te dice: aqui tienes tu simbolo sagrado.");
	clone_object("/d/gremios/hechizos/items/medallon_aranya")->move(this_player());
}
*/
int already_attacking(object me,object victim);

void event_enter(object enterer, string message)
{
	string msg;
	int lvl, luchando = 0;

	if (!enterer) // la documentacion dice q hay q mirar esto
		return;

	if (enterer->query_dead())
		return;

	if (already_attacking(this_object(), enterer)) {
		if (!this_object()->query_dead()) {
			if (!random(2))
				command("say Pagaras tu osadia con tu SANGRE!\n");
			else
				command("say Maldito bastardo, ahora moriras!\n");
		}
		return;
	}

	// hay q hacer de alguna forma q no salude a su CUERPO cuando muera, aunque
	// lo de comprobar el gremio rula, pero como hariamos si saludase a tol mundo?

	if (enterer->query_guild_name() != "ladron")
		return;

	// buscar propiedad o fun q me diga si esta en peleas pa no saludar XD

	if (query_fighting()) { // no saludamos y advertimos al que entra
		tell_object(enterer, "Sternad esta nervioso, algun enemigo ha osado atacarlo.\n");
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
