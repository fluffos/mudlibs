// Ene '02 Ogro version 1 by Tyrael

#define RECOMPENSA_HANDLER "/room/camino_avalon/handlers/recompensa.c"
//#define RABIA   "/d/gremios/comandos/go_berserk.c"
// no usamos el rabia, ya le metemos un tmp_damage de 25 ;)

inherit "/obj/monster";

object ob;

void event_enter(object ob, string mensaje, object donde)
{
if (!ob->query_hidden()) {
this_object()->attack_ob(ob);
  if(ob->query_alive() && ob == this_player())
  {
	if (!query_property("discurso_soltado")) {
		add_timed_property("discurso_soltado", 1, 5);
		do_command("say Wgrrroagh!!!\n");
	}
}
  ::event_enter(ob, mensaje, donde);
  }
}/*event_enter*/

void setup() {
  set_name("ogro");
  add_alias("ogro");
  set_al(10000);
  set_short("Ogro");
  set_race("ogro");
  set_language("common");
  set_level(70+random(5));
  set_max_hp(1200);
  set_max_gp(1000);
  set_random_stats(60, 68);
  set_ac(-400);
  set_thac0(-70);
  set_gender(1);
  set_long("Un enorme ogro de 3 metros de altura con una cara curtida en "
	"el terror y un cuerpo que maximiza todas las expresiones de "
	"fuerza que pudieras haber visto.\n");
  set_join_fight_mess("Un enorme Ogro defiende su morada de TI!\n");
  set_aggressive(3);
	//set_damage_bon(25); no existe
	adjust_tmp_damage_bon(25);
	add_clone("/room/camino_avalon/objs/tronco",1);
	init_equip();
} /* setup() */

void do_death(object ob)
{
	if (!ob) ob = this_player();
	RECOMPENSA_HANDLER->do_recompensa(ENV(TP), ob);
	// ::do_death(ob) debe ser lo ultimo en llamarse,
	// todos los call_outs() de este objeto seran destruidos
	// sin ejecutarse, asi que mejor hacerlos en un handler
	// que como es logico permanece una vez el npc (objeto) no existe.
	::do_death(ob);
}
