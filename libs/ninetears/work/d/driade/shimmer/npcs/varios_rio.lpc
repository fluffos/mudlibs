/* By Shimmer */


inherit "/obj/monster";

string ataque1,ataque2,ataque3;

void setup()
  {
  set_race("monster");
  switch(random(4))
  {
    case 0:
      set_name("rana");
      set_short("rana");
      set_long("Es una pequenya rana de color verde situada sobre una hoja sobre el agua, "+
		      " intentando cazar alguna de las mosquitos que revolotean por aqui.\n");
      add_alias("rana");
      set_main_plural("ranas");
      add_plural("ranas");
      set_gender(2);
      ataque1="te escupe una sustancia pegajosa";
      ataque2="te muerde en un dedo";
      ataque3="sube por tu cuerpo y te muerde en el cuello";
      set_level(5);
      break;
    case 1:
      set_name("mosquito");
      set_short("mosquito");
      set_long("Es una mosquito gordo como un punyo, su picadura a veces "
               "llega a ser mortal, debido a las numerosas enfermedades que te podria contagiar. Son muy abundantes "
               "en zonas pantanosas como esta.\n");
      add_alias("mosquito");
      set_main_plural("mosquitos");
      add_plural("mosquitos");
      set_gender(1);
      ataque1="revolotea a tu alrededor y te pica";
      ataque2="se te mete en un ojo";
      ataque3="te pica";
      set_level(5+random(2));
      break;
    case 2:
      set_name("rana");
      set_short("rana roja");
      set_long("Una pequenya rana roja venenosa que sisea por el camino buscando algo"
	"para comer.\n");
      set_main_plural("ranas");
	add_plural("ranas");
      set_gender(2);
      ataque1="se lanza hacia ti e inyecta su veneno en la pierna";
      ataque2="te lanza su veneno a la cara ";
      ataque3="te golpea debilmente";
      set_level(10+random(5));
      break;
  }
  set_random_stats(6,17); 
  set_al(0);
  set_wimpy(20);
}