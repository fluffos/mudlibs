inherit "/std/object";

void setup()
{
   set_name("Pan de viaje");
   set_short("Pan de viaje");
   set_long("Un pan redondo y con un tamanyo perfecto para llevar.\n");
   set_main_plural("Panes de viaje");
   add_plural("panes");
   add_alias("pan");
   set_weight(5);
   set_value(100);
   
}

void init()
{
   ::init();
   add_action("do_comer", "comer");
}

void do_comer(string str)
{
   if (!str) return 0;
   if (str!=this_object()->query_name()) return 0;
   
   write("Te comes una barra de pan.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se come una barra de pan.\n",
             ({this_player()}));
   this_player()->adjust_hp(50);
   this_object()->dest_me();
   return 1;
}
