inherit "/obj/monster";
void setup()
{
set_name("gutrinela");
add_plural("Gutrinela");
set_short("Gutrinelas");
set_long("La gutrinela es un extranyo animal. Tiene tres grandes zorotemas sobre su motinulo verdoso. "
	 "Tras las metidanas se estrecha sorprendentemente hasta el punto que los extremos de sus. "
	 "penocotelas parecen estar unidas al cuerpo por dos delgadas mifolezanas.\n");
//set_race("Jodiomutante");
set_random_stats(12,17);
set_level(3+random(50));
set_gender(1);
set_al(-100);
set_aggressive(0);
set_wimpy(0);

load_chat (100,
  ({
  1,"'Grrrrrnnnnyiiiiiccckkk\n",
  1," se lame desde la chuwimba hasta la metudesa.\n",
  }));
}
