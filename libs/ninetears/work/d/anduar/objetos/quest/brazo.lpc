inherit "/std/item";

void setup()
{
   set_name("brazo de mercader");
   set_short("Brazo de mercader");
   set_main_plural("Brazos de mercader");
   add_plural("brazos");
   set_long("Es un brazo de un mercader, completamente sangrante, te da "
   "repelus verlo, no creiste golpear tan fuerte al pobre ser.\n");
   set_weight(20);
   set_size(1);
}

void init()
{
 ::init();
 add_action("comer_brazo","comer");
 add_action("comer_brazo","coger");
}

int comer_brazo(string str)
{
  if(str=="brazo de mercader")
  {
   write("Con asco te comes el brazo del desdichado hombre y te das "
   "cuenta de que estas mas cerca de Oskuro.\n");
   say(this_player()->query_cap_name()+" se come el brazo dejandote "
   "totalmente asqueado.\n");
   TP->add_property("BrazoDeMercader",1);
    TO->dest_me();
   return(1);
  }
  notify_fail("Comer que?.\n");
  return(0);
}
