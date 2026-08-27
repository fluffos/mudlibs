inherit "/std/item";

void setup()
{
   set_name("estomago de gnomo");
   set_short("Estomago de gnomo");
   set_main_plural("Estomagos de gnomo");
   add_plural("estomagos");
   set_long("Es un estomago de algun gnomo, completamente sangrante, te da "
   "repelus verlo, no creiste golpear tan fuerte al pobre ser.\n");
   set_weight(20);
   set_size(1);
}

void init()
{
 ::init();
 add_action("comer_estomago","comer");
 add_action("comer_estomago","coger");
}

int comer_estomago(string str)
{
  if(str=="estomago de gnomo")
  {
   write("Con asco te comes el estomago del desdichado ser y te das "
   "cuenta de que estas mas cerca de Oskuro.\n");
   say(this_player()->query_cap_name()+" se come el cerebro dejandote "
   "totalmente asqueado.\n");
   TP->add_property("EstomagoDeGnomo",1);
  TO->dest_me();
   return(1);
  }
  notify_fail("Comer que?.\n");
  return(0);
}
