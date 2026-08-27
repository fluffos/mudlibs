inherit "/obj/monster";

void setup () {

   set_name("viajero");
   set_short("Viajero");
   set_long("Ante ti esta una persona de complexion media y de cara cansada por la larga jornada de viaje que ya lleva a sus espaldas. Es una persona que se encuentra de viaje por unos motivos por ti desconocidos y que no hace caso de las personas a las que encuentra. Sus ojos muestran a la vez seguridad y sabiduria; seguridad de que llegara a su destino y sabiduria adquirida de las muchas maravillas que sus ojos han contemplado a lo largo de este mundo.
");
   set_main_plural("viajeros");
   add_plural("viajeros");
   add_plural("humanos");
   add_alias("humano");
   set_gender(1);
   set_level(15+random(6));
   set_random_stats(14,18);
   set_race("humano");
   set_wimpy(0);
   set_max_hp(query_level() * 50);
   set_hp(query_max_hp());
   set_max_gp(query_level() * 50);
   set_gp(query_max_gp());
   set_max_ep(query_level() * 30);
   set_ep(query_max_ep());
   set_cha(12);
   load_chat(30,({
     1, ":busca entre su equipaje una hogaza de pan para comer.",
     2, "'Solo los necios suenyan con lo que nunca tendran.",
     3, "'La mejor arma es la mano del que la empunya.",
     4, "'El camino es mi hogar y mi vida.",
   }));
   load_a_chat(100,({
     1, "'De acuerdo, veamos quien es mas diestro en el combate",
     2, ":te mira desafiante observando todos tus movimientos",
     3, "'No seras el primero al que mate por su insensatez",
   }));
   add_clone("/baseobs/armaduras/capa",1);
   add_clone("/baseobs/armaduras/zapatillas",1);
   add_clone("/baseobs/armas/espada_ancha",2);
   init_equip ();
   adjust_money(random(15),"plata");
   }
