#define INFRAMUNDO "/d/inframundo/rooms/juicio"

object my_player,esc_muerte;
int reloj,movimientos;

int test_add() { return 0; }
void attack() {
}

void adjust_hp() {
}

void set_hp() {
}
 
void do_death() {
/* He`s allready dead...  sheeze.  */
}
 
void setup_shadow(object ob) {
  shadow(ob,1);
  my_player = ob;
  esc_muerte=ENV(ob);
  reloj=ob->query_con()*20;
  call_out("cuenta_atras",0);
}

int attack_by(object ob) {
  tell_object(ob, my_player->QCN+" es una forma distorsionada e intangible, no puedes hacerle nada.\n");
  ob->stop_fight(my_player);
  return 1;
}

int attack_ob(object ob) {
  write("Eres demasiado... etere"+(my_player->query_gender()-1?"a":"o")+" como para interferir en el Plano Material.\n");
  return 0;
}

string short() {
  if (!my_player) return "Death shadow";
  return "Espiritu de "+my_player->short();
}

string query_short() {
  if ( !my_player) return "Death shadow";
  return "Espiritu de "+my_player->query_short();
}

string combat_short() {
  if (!my_player) return "Death shadow";
  return "Espiritu de "+my_player->combat_short();
}

void dest_death_shadow() {
  destruct(this_object());
}

int cast() {
  write("A pesar de que puedes ver las delgadas lineas del entramado magico de la Realidad con gran nitidez, te sientes impotente para manejar tanto poder.\n");
  return 1;
}

int do_shout() {
  write("Tratas coger aire para emitir un berrido fantasmagorico... pero entonces es inutil.\n");
  return 1;
}

void second_life() {
} /* second_life() */

void cuenta_atras() {
	if(ENV(my_player)->query_inframundo()) return;
	reloj--;
	if(!reloj) {
		tell_object(my_player,"El delgado vinculo que mantenia tu alma en el Plano Material acaba por desvanecerse. La oscuridad rodea tu ser y te precipitas en un pozo sin fondo de negrura.\n");
		my_player->move(INFRAMUNDO,"El alma de "+my_player->QCN+" empieza a formarse en la sala.\n","La borrosa imagen que era "+my_player->QCN+" acaba por desvanecerse.\n");
		return;
		}
	call_out("cuenta_atras",1);
	}

varargs mixed move_player(string dir, mixed dest, mixed message,object followee, mixed enter) {
	mixed ret;
	ret=my_player->move_player(dir,dest,message,followee,enter);
	movimientos++;
	if(ENV(my_player)->query_inframundo()||ENV(my_player)==esc_muerte) movimientos=0;
	if(movimientos>=2) {
		tell_object(my_player,"Te has alejado demasiado del escenario de tu muerte. Tu alma se desvanece al debilitarse el vinculo que la mantenia unida al plano material. La oscuridad rodea tu ser.\n");
		my_player->move(INFRAMUNDO,"El alma de "+my_player->QCN+" empieza a formarse en la sala.\n","La borrosa imagen que era "+my_player->QCN+" acaba por desvanecerse.\n");
		return notify_fail("");
		}
	return ret;
	}
