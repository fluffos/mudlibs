inherit "/std/item";

void setup()
{
   set_name("cerebro de enano");
   set_short("Cerebro de enano");
   set_main_plural("Cerebros de enano");
   add_plural("pies");
   set_long("Es un cerebro de algun enano, completamente sangrante, te da "
   "repelus verlo, no creiste golpear tan fuerte al pobre ser.\n");
   set_weight(20);
   set_size(1);
}

void init()
{
 ::init();
 add_action("comer_cerebro","comer");
 add_action("comer_cerebro","coger");
}

int comer_cerebro(string str)
{
  if(str=="cerebro de enano")
  {
   write("Con asco te comes el cerebro del desdichado ser y te das "
   "cuenta de que estas mas cerca de Oskuro.\n");
   say(this_player()->query_cap_name()+" se come el cerebro dejandote "
   "totalmente asqueado.\n");
   TP->add_property("CerebroDeEnano",1);
  TO->dest_me();
   return(1);
  }
  notify_fail("Comer que?.\n");
  return(0);
}
