// Vilat 25.08.2002

inherit "/obj/entskill";

void setup() {
      	set_name("espartaco");
      	set_short("Espartaco");
      	set_al(10000);
      	set_main_plural("personas que se parecen a Espartaco");
      	set_race("human");
	set_gender(1);
      	set_level(65+random(11));
	add_clone("/baseobs/guildmasters/obj/cetro",1);
	init_equip();
      	set_wimpy(0);
	set_max_hp(2000);
	set_hp(query_max_hp());
	set_max_gp(1000);
	set_gp(query_max_gp());
	set_max_ep(2000);
      	set_random_stats(20, 22);
      	set_long("Espartaco, jefe del Gremio de Barbaros del Caos.\nEste es el famoso barbaro Espartaco, a pesar de medir tan solo 1.40 m es el barbaro mas poderoso de la historia. Nadie en su sano juicio le plantaria cara.\n\n");
      	adjust_money(random(5)+1, "oro");
      	load_chat(30,
         ({
               1, "'Arrodillate ante mi cetro de poder!",
               1, "'Soy tan bajito porque de pequenyo no tomaba leche, asi que ya sabes.",
               1, ":blande ante ti su cetro de poder.",
               1, "'No te fies de las apariencias, una vez extermine a una manada de osos con mis propias manos.",
          }));
      	load_a_chat(100,
         ({
               1, "'Pagaras cara tu osadia!",
               1, ":te mira furioso.",
               1, "'No viviras para lamentarlo!",
               }));
	set_habilidad("furia",100);
	set_habilidad("aplastar",100);
	set_habilidad("cazar",100);
	add_skill_entrenable("furia",0,100,"guerrero");
	add_skill_entrenable("aplastar",0,100,"guerrero");
	add_skill_entrenable("cazar",0,100,"general");
	add_skill_entrenable("despellejar",0,100,"general");
	add_skill_entrenable("curtir",0,100,"general");
	set_coste(random(5)+1);
	}
	
void init() {
	::init();
	add_attack_command(15, "furia", "/comandos/barbarocaos/furia","furia",0);
	add_attack_command(20, "aplastar", "/comandos/barbarocaos/aplastar","aplastar",4);
	add_attack_command(25, "cazar", "/comandos/barbarocaos/cazar","hunt",4);
	}		
	
int already_attacking(object me,object victim);

void event_enter(object ob, string message, mixed lala) {
	if (!ob) return;

	if (ob->query_dead()) return;
	
	if (ob->query_property("repudiado_barbaroscaos") && !ob->query_creator() && !ob->query_hidden()) TO->attack_by(ob);

	if (already_attacking(TO, ob) && !TO->query_dead()) {
		tell_object(ob,"Espartaco te dice: Estupido, acabare contigo!\n");
		return;
		}
	if (ob->query_guild_name() != "barbarocaos") return;

	if (query_fighting()) {
		tell_object(ob, "Observas a Espartaco altamente excitado. %^BOLD%^%^RED%^Podria atacarte a ti inmerso en su furia!%^RESET%^\n");
		return;
		}
	tell_room(environment(TO),"Espartaco saluda a "+ob->query_cap_name()+".\n",ob);
	tell_object(ob,"Espartaco te da la bienvenida.\n");
	}

int already_attacking(object me,object victim) {
   	if(member_array(me,victim->query_attacker_list()) != -1) return 1;
   	if(member_array(me,victim->query_call_outed()) != -1) return 1;
   	return 0;
	}

void attack_by(object ob) {
	if (!ob->query_property("repudiado_barbaroscaos") && ob->query_guild_name() != "barbarocaos" && !ob->query_creator()) {
		ob->add_property("repudiado_barbaroscaos",1);
		write_file("/room/guildbarbaroscaos/list.txt","%^BOLD%^WHITE%^MATAR A:  %^BOLD%^RED%^"+ob->query_cap_name()+"\t%^WHITE%^REPUDIADO POR: %^GREEN%^Espartaco.\n");
		}
	::attack_by(ob);	
	}

int lista() {
	if(already_attacking(TO,TP)) return 0;
	return ::lista();
	}

int entrenamiento(string str) {
	if(already_attacking(TO,TP)) return 0;
	return ::entrenamiento(str);
	}
