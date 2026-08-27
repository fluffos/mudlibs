//No rula, no se la bebe. puta ostia!!!
inherit "/std/object";

void setup()
{
   set_name("Pocion roja");
   set_short("Pocion roja");
   set_long("Es un frasco de cristal trasparente que en el interior contiene un liquido de color rojo.\n");
   set_main_plural("Pociones rojas");
   add_plural("rojas");
   add_alias("roja");
   set_weight(15);
   set_value(100);
   
}

void init()
{
   ::init();
   add_action("do_beber", "beber");
}

void do_beber(string str)
{
   if (!str) return 0;
   if (str!=this_object()->query_name()) return 0;
   
   write("Te tomas una pocion roja, sientendote rejuvenecido.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se toma una pocion roja, parece rejuvenecer.\n",
             ({this_player()}));
   this_player()->adjust_hp(150);
   this_object()->dest_me();
   return 1;
}