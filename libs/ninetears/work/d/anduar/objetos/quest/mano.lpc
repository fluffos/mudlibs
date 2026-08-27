inherit "/std/item";

void setup()
{
   set_name("mano de noble");
   set_short("Mano de noble");
   set_main_plural("Manos de noble");
   add_plural("manos");
   set_long("Es una mano de un noble, completamente sangrante, te da "
   "repelus verlo, no creiste golpear tan fuerte al pobre ser.\n");
   set_weight(20);
   set_size(1);
}

void init()
{
 ::init();
 add_action("comer_mano","comer");
 add_action("comer_mano","coger");
}

int comer_mano(string str)
{
  if(str=="mano de noble")
  {
   write("Con asco te comes la mano del desdichado hombre y te das "
   "cuenta de que estas mas cerca de Oskuro.\n");
   say(this_player()->query_cap_name()+" se come la mano dejandote "
   "totalmente asqueado.\n");
   TP->add_property("ManoDeNoble",1);
  TO->dest_me();
   return(1);
  }
  notify_fail("Comer que?.\n");
  return(0);
}
