inherit "/std/object";

void setup()
{
   set_name("pan");
   set_short("Pan de viaje");
   set_long("Es un pan de viaje de dimensiones reducidas, apto para viajes "
   "cortos.\n");
   set_main_plural("Panes de viaje");
   add_plural("panes");
   add_alias("pan de viaje");
   add_plural("panes de viaje");
  set_weight(200);
   set_value(1750);
   set_genero(1);
}

void init()
{
   ::init();
   add_action("do_comer", "com*er");
add_action("do_comer","coger");
add_action("do_comer","get");
}

void do_comer(string str)
{
   if (!str) return 0;
   if (str!=this_object()->query_name()) return 0;
   if (TP->query_timed_property("empachado") == 1)
   {
   write("Te das cuenta de que estas lleno y no puedes comer mas.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se intenta comer una barra de pan pero cambia de opinion.\n",
             ({this_player()}));
   return 1;
   }
	else
   {
   write("Te empiezas a comer la barra de pan. Hubiera estado mejor con "
         "algo dentro y un vinillo.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se come una barra de pan a palo seco.\n",
             ({this_player()}));
   this_player()->adjust_hp(50);
  TP->add_timed_property("empachado",1,1000);
   TO->dest_me();
   return 1;
   }
   return 1;
}
