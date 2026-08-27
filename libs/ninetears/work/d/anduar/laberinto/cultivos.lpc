#include "../path.h"
inherit "/std/outside";
int n, init=0;

void long_desc()
{
 string *descripciones = ({"trigo", "cebada", "patatas", "naranjos",
 "limoneros", "sandias", "manzanos", "melones", "cerezos", "tilos"});
 string descripcion;
 string *descripciones2 = ({"un anciano humano", "un joven humano",
 "un maduro humano", "una anciana humana", "una joven humana",
 "una madura humana", "un joven elfo", "un anciano elfo", "un maduro elfo",
 "una joven elfa", "una madura elfa", "una anciana elfa", "un joven enano",
 "un maduro enano", "un anciano enano", "una enana"});
 string descripcion2;
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion=descripciones[random(sizeof(descripciones))];
 set_long("Caminas por una de las multiples sendas que hicieron los labradores de Anduar, que residen en una pequenya aldea en la zona norte de los mismos, para ir sus cultivos, por todas direcciones observas pequenyas acequias destinadas a regar los mismos, este en concreto es de "+descripcion+" el cual esta cuidado por "+descripcion2+" el cual trabaja afanosamente para procurar que las cosechas sean optimas, ya que estos cultivos son una fuente muy importante de la alimentacion de la gran urbe.\n");

add_item("trigo","es un campo de dorado trigo, una de las principales fuentes alimenticias de anduar.\n");
add_item("cebada","es un campo cebada, la verdad parece que la cosecha este anyo no ha sido buena.\n");
add_item("patatas","una gran extension de patatas, de aqui deven de provenir las famosas patatas de comellas.\n");
add_item("naranjos","unos hermosos naranjos, con sus flores en todo su explendor.\n");
add_item("limoneros","unos hermosos limoneros, con los limones listos para ser recogidos.\n");
add_item("sandias","una amplia extension de sandias que dicen comeme.\n");
add_item("manzanos","unos manzanos de los cuales se obtiene la sidra.\n");
add_item("melones","un campo repleto de melones listos para ser vendidos.\n");
add_item("cerezos","unos hermosos cerezos en flor.\n");
add_item("tilos","un campo de tilos del cual obtienen unos buenos calmantes.\n");
add_item("anciano humano","un humano de avanzada edad.\n");
add_item("joven humano","un humano entrando en la madurez.\n");
add_item("maduro humano","un humano plenamente desaroyado.\n");
add_item("anciana humana","una humana de avanzada edad.\n");
add_item("joven humana","una humana entrando en la flor de la vida.\n");
add_item("madura humana","una humana plenamente desarroyada.\n");
add_item("anciano elfo","un elfo de avanzada edad, con su tersa cara mostrando las primeras arrugas.\n");
add_item("joven elfo","un elfo entrando aprendiendo las viscisitudes de la vida.\n");
add_item("maduro elfo","un elfo plenamente desaroyado.\n");
add_item("anciana elfa","una elfa de avanzada edad pero conservando casi toda su belleza.\n");
add_item("joven elfa","una elfa entrando en la flor de la vida de una hermosura indescriptible.\n");
add_item("madura elfa","una elfa plenamente desarroyada.\n");
add_item("anciano enano","un enano con una piel parecida a la piedra.\n");
add_item("joven enano","un enano con una piel muy dura.\n");
add_item("maduro enano","un enano plenamente desaroyado.\n");
add_item("enana","una humana de avanzada edad.\n");
set_light(50);
}

void crea_bichos()
{
   int tipo, i;
   n=random(6);
   for (i=0; i<n; i++)
   {
      tipo=random(7);
      switch (tipo)
      {
         case 0: add_clone(ANDUAR+"npcs/perro", 1);
                 break;
         case 1: add_clone(ANDUAR+"npcs/agricultor", 1);
                 break;
         case 2: add_clone(ANDUAR+"npcs/agricultora", 1);
                 break;
         case 3: add_clone(ANDUAR+"npcs/pajaro", 1);
                 break;
         case 4: add_clone(ANDUAR+"npcs/perro", 1);
                 break;
         case 5: add_clone(ANDUAR+"npcs/gato", 1);
                 break;
         case 6: add_clone(ANDUAR+"npcs/gato", 1);
                 break;
      }
   }
}

void destruye_bichos()
{
}
