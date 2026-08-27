#include "../path.h"
inherit "/std/outside";

int n, init=0;

void base_desc()
{
   set_dark_long("Lo unico que sabes es que estas en Anduar.\n\n");
   add_item("suelo", "El suelo esta formado por adoquines. Parece perfecto"
                     " para hacerse un esguince.\n");                    
   set_light(65);
   set_zone("anduar");
}

void long_desc()
{
 string *descripciones = ({"un grupo de casas echas de piedra",
 "un grupo de casas hechas de adobe",
 "unas casas de clara manufactura enana",
 "chabolas",
 "unas viviendas de disenyo estrambotico",
 "una casa muy cuidada",
 "una construccion de claro origen gnomico",
 "una casa con unos amplios ventanales",
 "una casa de madera",
 "una zona residencial"});
 string descripcion;
 string *descripciones2 = ({"un alamo",
 "un roble",
 "un sauce",
 "un cerezo",
 "un pino",
 "un alcornoque",
 "un abedul",
 "un castanyo",
 "un abeto",
 "un manzano",
 "una sequoya",
 "un fresno",
 "un peral",
 "un haya",
 "un ciruelo",
 "una higuera"});
 string descripcion2;
 string *descripciones3 = ({"un gorrion",
 "un jilguero",
 "un canario",
 "un mirlo",
 "un petirrojo",
 "un periquito",
 "un aguila",
 "un halcon",
 "un azor",
 "un cuervo",
 "una cacatua",
 "un loro"});
 string descripcion3;
 string *descripciones4 = ({"un enano",
 "un elfo",
 "un jardinero",
 "un perro",
 "un noble",
 "un ninyo",
 "una ninya",
 "una mujer",
 "un hombre",
 "una noble",
 "un senyor calvo",
 "un senyor gordo",
 "un senyor flaco",
 "un individuo encapuchado",
 "un gnomo"});
 string descripcion4;
 string *descripciones5 = ({"una alta verja",
 "un hermoso seto",
 "un pequenyo muro de piedra",
 "una cerca de madera",
 "una curiosa planta",
 "un muro con tiestos",
 "una verja con enredaderas"});
 string descripcion5;  
 string *descripciones6 = ({"rosales",
 "petunias",
 "narcisos",
 "tulipanes",
 "pasionarias",
 "dalias",
 "amapolas",
 "margaritas",
 "azucenas",
 "lilas",
 "ortensias",
 "claveles",
 "violetas"});
 string descripcion6;
 descripcion6=descripciones6[random(sizeof(descripciones6))];
 descripcion5=descripciones5[random(sizeof(descripciones5))];
 descripcion4=descripciones4[random(sizeof(descripciones4))];
 descripcion3=descripciones3[random(sizeof(descripciones3))];
 descripcion2=descripciones2[random(sizeof(descripciones2))];
 descripcion=descripciones[random(sizeof(descripciones))];
set_long("Estas en la ancestral ciudad de Anduar, a ambos lados de la calzada observas "+descripcion+". En la parte delantera "+descripcion2+" decora el jardin, en el cual "+descripcion3+" esta posado en una rama mientras es observado por "+descripcion4+" que pasea por el mismo entre "+descripcion6+". A salvo gracias a "+descripcion5+" que rodea la propiedad.");
}

void crea_bichos()
{
   int tipo, i;

   n=random(4);
   for (i=0; i<n; i++)
   {
      tipo=random(12);
      switch (tipo)
      {
         case 0: add_clone(ANDUAR+"npcs/guardian", 1);
                 break;
         case 1: add_clone(ANDUAR+"npcs/ciudadano", 1);
                 break;
         case 2: add_clone(ANDUAR+"npcs/mercader", 1);
                 break;
         case 3: add_clone(BASEMONSTER+"mercenary", 1);
                 break;
         case 4: add_clone(ANDUAR+"npcs/pajaro", 1);
                 break;
         case 5: add_clone(ANDUAR+"npcs/perro", 1);
                 break;
         case 6: add_clone(ANDUAR+"npcs/pobre", 1);
                 break;
         case 7: add_clone(ANDUAR+"npcs/gato", 1);
                 break;
         case 8: add_clone(ANDUAR+"npcs/caballo", 1);
                 break;
         case 9: add_clone(ANDUAR+"npcs/pobre", 1);
                 break;
         case 10: add_clone(ANDUAR+"npcs/nomada", 1);
                 break;
         case 11: add_clone(ANDUAR+"npcs/ciudadana", 1);
                 break;
      }
   }
}

void destruye_bichos()
{
}

