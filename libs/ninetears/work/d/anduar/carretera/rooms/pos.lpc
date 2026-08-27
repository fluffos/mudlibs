//Hostal Comellas (Recuerdo de nuestro viaje a Sabadell :)
//Gestur'97

inherit "std/OSO";
#include "pub.h"
#include "path.h"

object comellas, globo, tablon;

//nombre.tipo.coste.heal.volumen.intox

void setup()
{
   add_menu_item("Licor de raices", ALCOHOL, 160, 7, 30, 30,
      "bebes un licor con un extranyo sabor", "se bebe con cara de asco un "+
      "licor");
   add_menu_item("Vino tinto", ALCOHOL, 90, 3, 10, 10,
      "bebes un chato de vino tinto", "se bebe un chato de vino tinto");

   add_menu_item("Mosto", SOFTDRINK, 110, 3, 30, 0,
     "bebes un delicioso vaso de mosto","se bebe un vaso de mosto");

   add_menu_item("Patatas fritas", FOOD, 300, 6, 100, 0,
     "comes un plato lleno hasta arriba de patatas fritas",
     "se come un gran plato lleno de patatas fritas");
   add_menu_item("Fabada", FOOD, 600, 12, 80, 0,
     "comes un sabroso plato de fabada asturiana",
     "se come plato de fabada");
   add_menu_item("Bravas", FOOD, 400, 8, 110, 0,
     "comes un plato de patatas bravas picantes",
     "se come un plato de bravas");
   add_menu_item("Salpicon", FOOD, 1000, 20, 140, 0,
      "comes una bandeja de salpicon. Delicioso!",
      "se come delante de ti una bandeja de salpicon sin ofrecerte nada");
    
   add_menu_alias("raices", "Licor de raices");
   add_menu_alias("licor", "Licor de raices");
   add_menu_alias("vino", "Vino tinto");
   add_menu_alias("mosto", "Mosto");
   add_menu_alias("patatas fritas", "Patatas fritas");
   add_menu_alias("patatas", "Patatas fritas");
   add_menu_alias("fabada", "Fabada");
   add_menu_alias("bravas", "Bravas");
   add_menu_alias("salpicon", "Salpicon");
   
   set_short("%^YELLOW%^Hostal Comellas%^RESET%^");
   set_long("Estas en el Hostal Comellas. Un agradable lugar donde puedes "
            "descansar en tu camino hacia Anduar o Dendara y tomar algo "
            "si quieres. Puedes ver una larga barra donde se sirve la "
            "comida/bebida. Tambien ves unas enormes estanterias repletas "
            "por completo de botellas con bebidas de todas clases.\n");
   
   add_exit("out",       CARRETERA+"c10");
   add_exit("norte",     CARRETERA+"pos4");
   add_exit("noroeste",  CARRETERA+"pos3");
   add_exit("oeste",     CARRETERA+"pos2");
   add_exit("southwest", CARRETERA+"pos1");
    set_light(45);
   
   add_item("barra", "Es una larga barra por la cual se sirven las bebidas "+
                     "o comidas que los clientes piden.\n");	
  
  set_open_condition("BARMAN");
}

int BARMAN()
{
  object *lista;
  int i;
  if (!comellas) return 0;
  else{
      lista=comellas->query_attacker_list();
      for(i=0;i<sizeof(lista);i++)
      { if (environment(lista[i])==this_object()) return 0; }
      }
  return 1;
}       
   
void reset()
{
   if (!comellas)
   {
      comellas=new(NPC+"comellas");
      comellas->move(this_object());
   } 
   if(!globo)
   {
      globo=new("/obj/misc/globe");
      globo->move(this_object());
   }
   if(!tablon)
   {
      tablon=new("/obj/misc/board");
      tablon->set_datafile("hostal_comellas");
      tablon->move(this_object());
   }  
   ::reset();
}

void dest_me()
{
   if (comellas) 
      comellas->dest_me();
   if (globo) 
      globo->dest_me();
   if (tablon)
      tablon->dest_me();
   ::dest_me();
}

