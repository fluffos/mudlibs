//Kryger 2003//
inherit "/obj/monster";

void setup() 
	{
  set_name("oso");
  set_short("Oso");
  set_main_plural("Osos");
  set_random_stats(14,18);
  set_long(query_short()+"\n"+"Es un gran oso, gigante, mide por lo menos 2 metros  "
  "de alto y otro metro y medio de ancho, su pelaje es marron oscuro, y tiene una  "
  "pose atemorizadora, parece que va a atacarte de un momento a otro, asi que yo  " 
  "tendria cuidado con el.\n");
  set_aggressive(0);
  set_race("monster");
  set_level(10+random(10));
  set_gender(1);
  load_chat(10,
  ({
    1, ":te grunye amenazadoramente.",
	1, ":se levanta sobre sus patas.",
  }));
}