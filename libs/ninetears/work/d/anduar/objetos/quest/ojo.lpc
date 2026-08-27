inherit "/std/item";

void setup()
{
   set_name("ojo de elfo");
   set_short("Ojo de elfo");
   set_main_plural("Ojos de elfo");
   add_plural("ojos");
   set_long("Es un ojo de algun elfo, completamente sangrante, te da "
   "repelus verlo, no creiste golpear tan fuerte al pobre ser.\n");
   set_weight(20);
   set_size(1);
}

void init()
{
 ::init();
 add_action("comer_ojo","comer");
 add_action("comer_ojo","coger");
}

int comer_ojo(string str)
{
  if(str=="ojo de elfo")
  {
   write("Con asco te comes el ojo del desdichado ser y te das "
   "cuenta de que estas mas cerca de Oskuro.\n");
   say(this_player()->query_cap_name()+" se come el cerebro dejandote "
   "totalmente asqueado.\n");
   TP->add_property("OjoDeElfo",1);
  TO->dest_me();
   return(1);
  }
  notify_fail("Comer que?.\n");
  return(0);
}
