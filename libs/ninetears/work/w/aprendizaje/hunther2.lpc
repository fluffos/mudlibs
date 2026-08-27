// Vilat 24.10.2002
// Via comentar este NPC para los cres nuevos. Es el primero que he pillao, pero no creo que al Hunther original le importe :P

// Ahora vamos a meterle a Hunther hechizos y hacer que odie a los enanos y les ataque al entrar en su room
inherit "/obj/monster";

void setup() {
	set_name("hunther");
      	set_short("Hunther");
     	set_long(query_short()+"\nUno de los mejores clerigos que jamas han existido. Este famoso Duergar no es originario de Driade, sino que fue transferido magicamente por Leviathan desde otra Realidad donde sus talentos no eran bien apreciados.\n\n");
	set_main_plural("personas que se aparecen a Hunther");
	add_alias("duergar");
	add_alias("clerigo");
	add_plural("hunthers");
	add_plural("duergars");
	add_plural("clerigos");
	set_gender(1);
	set_level(41+random(5));
	set_random_stats(18, 20);
      	set_race("duergar");
	set_wimpy(0);
      	set_max_hp(query_level() * 50);
      	set_hp(query_max_hp());
      	set_max_gp(query_level() * 60);
      	set_gp(query_max_gp());
	set_max_ep(query_level() * 20);
set_ep(query_max_ep());
	set_cha(8);
      	load_chat(30,({
 		1, "'Esto no lo digo casi nunca.",
               	2, "'Esto lo digo a veces.",
               	3, "'Esto es lo que mas digo.",
               	4, ":hace esto muy a menudo.",
          	}));
      	load_a_chat(100,({
               	1, "'Pagaras cara tu osadia!",
               	1, ":te mira con furia en sus ojos.",
               	1, "'No viviras para lamentarlo!",
               	}));
	add_clone("/w/vilat/espada_hielo_negro",1);
	add_clone("/baseobs/armours/fullplate",1);
	init_equip();
	adjust_money(5,"oro");
	}

// Para ensenyarle comandos hay que enmascarar el init:
void init() {
	::init(); // Esto que no se olvide
	// Para saber como usar el add_attack_command y el add_attack_spell preguntadle a alguien que lo entienda :P
	// A Hunther le meto los comandos de Espartaco porque no tengo ganas de buscar otros y porque esto se cambiara pronto asi
	// que no merece la pena detallarlo mucho
	add_attack_command(20, "aplastar", "/d/gremios/comandos/aplastar","aplastar",4);
	// Sus explico masomeno: el primer numero es la probabilidad de hacer ese comando cada turno
	// Los tres siguientes vienen a ser la forma de identificar el comando que queremos que se ejecute
	// el ultimo numero es un 4 que significa que queremos que haga el comando sobre el rival mas debil
	add_attack_command(25, "cazar", "/d/gremios/comandos/hunt","hunt",4);
	// Aqui si queremos tambien podemos ponerles add_action() como a las rooms
	}

// Ahora haremos que ataque a un enano que entre en su room:
// esta funcion se llama ejecuta cada vez que alguien entra en la room del npc
void event_enter(object ob, string message) {
	// Comprobamos que la raza de ob (el objeto que entra) sea "enano" y en ese caso le atacamos
	// Espero que ya entendais lo de las flechas: son llamadas sobre otros objetos
	// ob->query_race() : dame la raza de 'ob'
	// ob->attack_by(TO) : que 'ob' sea atacado por 'TO'
	if (ob->query_race()=="enano") ob->attack_by(TO);
	::event_enter(ob,message); // Esto que no se olvide al final
	}
