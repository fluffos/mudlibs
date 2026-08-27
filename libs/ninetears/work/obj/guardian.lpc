// Vilat 09.11.2002
// NPC guardia

inherit "/obj/monster";

object cuerpo;

void set_cuerpo(object ob) { cuerpo=ob; }
object query_cuerpo() { return cuerpo; }

void create() {
	set_heart_beat(1);
	::create();
	set_move_after(1,10);
	}

void do_death(object ob) {
	if (cuerpo) cuerpo->he_muerto(file_name(TO));
	::do_death(ob);
	}

void attack_by(object ob) {
	object *players;
	if(!TO->query_timed_property("informado")) {
		players=users();
		for (int i=0;i<sizeof(players);i++) if(lower_case(players[i]->query_ciudadania())==lower_case(TO->query_ciudadania())) tell_object(players[i],TO->query_short()+" informa: "+ob->QCN+" me esta atacando en "+ENV(TO)->query_short()+".\n");
		TO->add_timed_property("informado",1,100);
		}
	::attack_by(ob);
	}

void heart_beat() {
	object *gentuza=all_inventory(ENV(TO));
	for (int i=0;i<sizeof(gentuza);i++) if(gentuza[i]->query_alive()) if(TO->query_relacion(gentuza[i])<0&&member_array(gentuza[i],query_attacker_list())==-1) {
		do_command("decir Aqui no queremos a gentuza como tu, "+gentuza[i]->QCN+". Fuera!!!");
		gentuza[i]->attack_by(TO);
		}
	::heart_beat();
	}
