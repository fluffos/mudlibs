// Vilat 24.10.2002
// Via comentar este NPC para los cres nuevos. Es el primero que he pillao, pero no creo que al Hunther original le importe :P

// Los NPCS heredan /obj/monster.c , si bien hay especializaciones, entre ellas:
//  - /obj/productor.c : Para npcs productores (mineros, agricultores...)
//  - /obj/entskill.c : Npcs capaces de ensenyar skills a players
// Esos son los que yo he hecho, aunque hay mas como walking_npc.c y henchman.c pero no os los comento porque seguramente se cambiaran
inherit "/obj/monster";

void setup() {
	// set_name() dice como habremos de referirnos a este npc para interactuar con el
	set_name("hunther");
	// set_short() es el nombre que el Npc tendra en la room
      	set_short("Hunther");
	// set_long() es la descripcion que veremos al mirar al Npc
      	set_long(query_short()+"\nUno de los mejores clerigos que jamas han existido. Este famoso Duergar no es originario de Driade, sino que fue transferido magicamente por Leviathan desde otra Realidad donde sus talentos no eran bien apreciados.\n\n");
	// set_main_plural() es el nombre que veremos si hay varios de estos Npcs en la misma room
	set_main_plural("personas que se aparecen a Hunther");
	// add_alias() y add_plural() especifican otras formas de referirnos al Npc, o al grupo
	add_alias("duergar");
	add_alias("clerigo");
	add_plural("hunthers");
	add_plural("duergars");
	add_plural("clerigos");
	// set_gender() establece el genero del Npc: 0.- Asexual 1.- Masculino 2.- Femenino 3.- Bisexual (??? No seria hermafrodita? En fin...)
	set_gender(1);
	// Cuando comenzamos a poner las caracteristicas especiales del Npc es importante que lo primero sea el nivel, porque si no
	// algunas de las demas cosas no tendran efecto.
	// set_level() establece el nivel del Npc. En este caso tendra nivel de 41 a 45. random(X) nos da un numero al azar entre 0 y X-1
	// en este caso un numero entre 0 y 4
	set_level(41+random(5));
	// Esto genera las caracteristicas del Npc (fue,des,con...) Las caracteristicas van de X a Y
	// Este Npc por tanto tendra las caracteristicas de 18 a 20
	set_random_stats(18, 20);
	// set_race() pone la raza del Npc. Ya no existen los bonos raciales, pero aun asi vale para los lenguajes y cosas especiales de raza
      	set_race("duergar");
	// set_wimpy() vale para ver si el Npc huye cuando esta herido. Va como el wimpy de los players
	set_wimpy(0);
	// Reajustamos los puntos de vida (hp), mana (gp) y energia (ep)
	// Fijaos como primero ajustamos el maximo y luego los actuales
	// Es importante poner estas cosas despues del set_level()
      	set_max_hp(query_level() * 50);
      	set_hp(query_max_hp());
      	set_max_gp(query_level() * 60);
      	set_gp(query_max_gp());
	set_max_ep(query_level() * 20);
set_ep(query_max_ep());
	// query_level() da el nivel del Npc, y en general cualquier query_X() nos da el valor de X
	// Por eso query_max_hp() nos da el maximo de puntos de vida
	// set_cha() ajusta la carisma. Podeis hacerlo con str, dex, con, int, wis y cha. Es importante poner esto despues del set_random_stats()
	set_cha(8);
	// Ahora haremos que el Npc hable
	// load_chat son los mensajes cuando no esta en peleas y load_a_chat los del combate
	// El primer numero es la frecuencia con que hablara, lo otro son los mensajes. Los numeros de los mensajes son la prioridad de los mensajes.
	// A mayor numero mas posibilidad de que diga ese mensaje
      	load_chat(30,({
 		1, "'Esto no lo digo casi nunca.",
               	2, "'Esto lo digo a veces.",	// Fijaos que con ' lo que hace es decir la frase
               	3, "'Esto es lo que mas digo.",
               	4, ":hace esto muy a menudo.", // con : es un emote
          	}));
      	load_a_chat(100,({
               	1, "'Pagaras cara tu osadia!",
               	1, ":te mira con furia en sus ojos.",
               	1, "'No viviras para lamentarlo!",
               	}));
	// Tb le vamos a poner objetos. Esto se hace con add_clone. El primer parametro es el objeto, y el segundo el numero, como en las rooms
	add_clone("/w/vilat/espada_hielo_negro",1);
	add_clone("/baseobs/armours/fullplate",1);
	// y le decimos que se equipe
	init_equip();
	// Por ultimo le daremos algo de dinero pa que se compre pipas
	adjust_money(5,"oro");
	}

// Hay otras cosas que podemos poner en el setup() a los Npcs, como el set_agressive() que hara que el Npc ataque
