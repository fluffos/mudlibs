inherit "/std/item";

void setup()
{
   set_name("pierna de saurio");
   set_short("Pierna de saurio");
   set_main_plural("Piernas de saurio");
   add_plural("pies");
   set_long("Es un pie de algun tio de saurio, completamente sangrante, te da "
   "repelus verlo, no creiste golpear tan fuerte al pobre ser.\n");
   set_weight(20);
   set_size(1);
}

void init()
{
 ::init();
 add_action("comer_pierna","comer");
 add_action("comer_pierna","coger");
}

int comer_pierna(string str)
{
  if(str=="pierna de saurio")
  {
   write("Con asco te comes la pierna del desdichado ser y te das "
   "cuenta de que estas mas cerca de Oskuro.\n");
   say(this_player()->query_cap_name()+" se come la pierna dejandote "
   "totalmente asqueado.\n");
   TP->add_property("PiernaDeSaurio",1);
  TO->dest_me();
   return(1);
  }
  notify_fail("Comer que?.\n");
  return(0);
}
