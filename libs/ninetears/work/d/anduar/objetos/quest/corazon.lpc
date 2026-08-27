inherit "/std/item";

void setup()
{
   set_name("corazon de halfling");
   set_short("Corazon de halfling");
   set_main_plural("Corazones de halfling");
   add_plural("corazones");
   set_long("Es un corazon de un halfling, completamente sangrante, te da "
   "repelus verlo, un liquido de color verde gotea, deduces que es "
   "la ingestion de la nigromante.\n");
   set_weight(20);
   set_size(1);
}

void init()
{
 ::init();
 add_action("comer_corazon","comer");
 add_action("comer_corazon","coger");
}

int comer_corazon(string str)
{
  if(str=="corazon de halfling")
  {
   write("Con asco te comes el corazon del desdichado halfling y te das "
   "cuenta de que estas mas cerca de Oskuro.\n");
   say(this_player()->query_cap_name()+" se come el corazon dejandote "
   "totalmente asqueado.\n");
   TP->add_property("CorazonDeHalfling",1);
  TO->dest_me();
   return(1);
  }
  notify_fail("Comer que?.\n");
  return(0);
}
