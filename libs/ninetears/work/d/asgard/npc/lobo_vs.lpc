inherit "/obj/monster";

void setup() {
  set_name("lobo");
  set_short("Lobo");
  set_main_plural("Lobos");
  set_random_stats(14,18);
  set_long(query_short()+"\n"+"Un temible lobo hambriento, es grande y fuerte y "
  "tiene una mirada fiera. Su piel es de color negra, anda sigiloso en busca de "
  "alguna presa que echarse a la boca, te mira fijamente parece como si ya hubiera " 
  "encontrado su presa.\n\n");
  set_aggressive(0);
  set_race("monster");
  set_level(10+random(10));
  set_gender(1);
  load_chat(10,
  ({
    1, ":grunye.",
	1, ":te mira fijamente.",
  }));
}
