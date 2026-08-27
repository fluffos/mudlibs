// Xerxes '02

inherit "/obj/monster";

string *colores = ({"oscuro","gris","negro","beige","marron"});

#define AN attacker->query_cap_name()
#define DN defender->query_cap_name()

void setup() {
  int i;
  i = random(sizeof(colores));

  set_name("galeb-dhur");
  set_short("Galeb-D'hur");
  set_main_plural("Galeb-D'hurs");
  add_alias("galeb");
  add_alias("dhur");
  add_plural("galebs");
  add_plural("d'hurs");
  set_random_stats(13,14);
  set_long("Galeb-D'hur\n\nLos Galeb-D'hur son unos parientes lejanos de las "
	     "cabras de monte. Posee un denso pelaje "+colores[i]+" y unos enormes "
	     "cuernos, que parecen peligrosos.\n");
  set_aggressive(0);
  set_race("monster");
  set_level(8+random(2));
  set_gender(1);
} /* setup() */

mapping valid_attack () {
  int three;
  three=random(3);

  return ([
    "punch"   :({ AN+" "+({"muerde","cornea","desgarra",})[three]+" a "+DN+".\n",
                 "Golpeas a "+DN+".\n",
                  AN+" te "+({"muerde con fuerza","embiste con sus enormes cuernos","desgarra con sus pezunyas",})[three]+".\n"}),
    "kick"    :({ AN+" "+({"muerde","cornea","desgarra",})[three]+" a "+DN+".\n",
                 "Golpeas a "+DN+".\n",
                  AN+" te "+({"muerde con fuerza","embiste con sus enormes cuernos","desgarra con sus pezunyas",})[three]+".\n"}),
    "knee"    :({ AN+" "+({"muerde","cornea","desgarra",})[three]+" a "+DN+".\n",
                 "Golpeas a "+DN+".\n",
                  AN+" te "+({"muerde con fuerza","embiste con sus enormes cuernos","desgarra con sus pezunyas",})[three]+".\n"}),
    "headbutt":({ AN+" "+({"muerde","cornea","desgarra",})[three]+" a "+DN+".\n",
                 "Golpeas a "+DN+".\n",
                  AN+" te "+({"muerde con fuerza","embiste con sus enormes cuernos","desgarra con sus pezunyas",})[three]+".\n"}),
  ]);}
