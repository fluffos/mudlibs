// Yebarcles

// habria k cancelar la entrega del objeto si estamos en peleas...

#define OGROS "/room/camino_avalon/objs/brazalete_ogro"

inherit "/obj/monster";

int haciendo_objeto = 0;

void setup() {
      set_name("yebarcles");
      set_short("Yebarcles");
      set_al(60);
      set_main_plural("Yebarcles");
      set_race("human");
	set_gender(1);
      set_level(31+random(10));
      set_wimpy(0);
	set_max_hp(query_level() * 10);
	set_hp(query_max_hp());
	set_max_gp(query_level() * 20);
	set_gp(query_max_gp());
      set_random_stats(20, 22);
      set_long("Yebarcles, druida del camino\n\n"
		"Yebarcles es un humano ya algo viejo, que en sus "
		"andanzas con los elfos aprendio a amar la naturaleza "
		"y sacarle el maximo provecho.\n\n");
      adjust_money(random(30), "gold");
//      set_aggressive(0);
      load_chat(50,
         ({
               1, "'La naturaleza nos da poder... Cuidala.",
               1, ":se rasca su larga barba.",
//               1, "@grin evilly $lname$",
               3, "'Dice la leyenda que en el camino existia una gran bestia devoradora de hombres y animales.",
               2, "'Estoy intentando completar un hechizo, si dieras muerte y me entregaras la piel de un ser extremadamente fuerte te recompensaria.",
          }));
      load_a_chat(30,
         ({
               1, "'Que los dioses se apiaden de ti!",
               1, ":parece compasivo contigo.",
//               1, "@grin evilly $lname$",
          }));
	add_attack_spell(50, "tormenta acida", ({"/d/gremios/hechizos/mago/tormenta_acida", "cast_spell",1,0}));
	add_attack_spell(50, "proyectil magico mayor",
	({"/d/gremios/hechizos/mago/proyectil_magico_mayor", "cast_spell",1,0}));
}

void init()
{
	::init();
	add_action("entregar", "entregar");
	haciendo_objeto = 0;
}

void empezar_show(object myp)
{
	do_command("decir Piel de Ogro! Por todos los dioses!");
	call_out("show0", 2, myp);
}

void show0(object myp)
{
	do_command("decir Esto sera perfecto para mi experimento.");
	call_out("show1", 3, myp);
}

void show1(object myp)
{
	tell_room(ENV(TO), QCN + " comienza a formular un hechizo.\n");
	call_out("show2", 4, myp);
}

void show2(object myp)
{
	tell_room(ENV(TO), QCN + " pronuncia el cantico 'natura fuere impregnus'.\nYebarcles termina de formular un hechizo sobre un objeto.\n");
	call_out("show3", 3, myp);
}

void show3(object myp)
{
	do_command("decir Eureka!\n");
	call_out("show4", 6, myp);
}

void show4(object myp)
{
	do_command("decir Ah! Ya casi me olvidaba, aqui tienes tu recompensa!");
	call_out("show5", 2, myp);
}

void show5(object myp)
{
	object ogros;

	ogros = clone_object(OGROS);
	ogros->move(TO);
	ogros->set_owner(myp);
	// esto es fuente de bugs a szako
	//do_command("dar brazalete a "+myp->query_name());
	do_command("dejar brazalete");
	haciendo_objeto = 0;
}

int entregar(string str)
{
	int i;
	object myp = TP;
	object *obs;

	if (haciendo_objeto) {
		do_command("say Un momento, por favor.");
		notify_fail("");
		return 0;
	}

	if (str != "piel") {
		do_command("decir Que desea vuesa merced entregar?");
		notify_fail("");
		return 0;
	}
	obs = all_inventory(myp);
	for (i=0; i<sizeof(obs); i++) {
		if (obs[i]->query_name() == "piel de ogro") {
			if (obs[i]->query_property("duenyo") == myp->QCN) {
				obs[i]->dest_me();
				haciendo_objeto = 1;
				empezar_show(myp);
				return 1;
			}
			else {
				obs[i]->dest_me();
				do_command("decir Entregarme el trofeo de otro no te ayudara a enganyarme, consiguelo por tus propios medios.");
				notify_fail("");
				return 0;
			}
		}
	}
	do_command("decir Se refiere usted a entregarme su propio pellejo?");
	notify_fail("");
	return 0;
}
