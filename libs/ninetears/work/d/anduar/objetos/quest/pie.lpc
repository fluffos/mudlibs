inherit "/std/item";

void setup()
{
   set_name("pie de soldado");
   set_short("Pie de soldado");
   set_main_plural("Pies de soldado");
   add_plural("pies");
   set_long("Es un pie de un soldado, completamente sangrante, te da "
   "repelus verlo, no creiste golpear tan fuerte al pobre ser.\n");
   set_weight(20);
   set_size(1);
}

void init()
{
 ::init();
 add_action("comer_pie","comer");
 add_action("comer_pie","coger");
}

int comer_pie(string str)
{
  if(str=="pie de soldado")
  {
   write("Con asco te comes el pie del desdichado hombre y te das "
   "cuenta de que estas mas cerca de Oskuro.\n");
   say(this_player()->query_cap_name()+" se come el pie dejandote "
   "totalmente asqueado.\n");
   TP->add_property("PieDeSoldado",1);
  TO->dest_me();
   return(1);
  }
  notify_fail("Comer que?.\n");
  return(0);
}
