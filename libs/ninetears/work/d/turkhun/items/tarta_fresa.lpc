inherit "/std/object";

void setup()
{
   set_name("tarta");
   set_short("%^MAGENTA%^Tarta de fresa%^RESET%^");
   add_alias("tarta de fresa");
   set_long("Es una suculenta tarta de fresa. Seguro que te la quieres "
            "'comer'.\n");
   set_main_plural("%^MAGENTA%^Tartas de fresa%^RESET%^");
   add_plural("tartas");
   add_plural("tartas de fresa");
   add_alias("fresa");
   add_plural("fresas");
   set_weight(25);
   set_value(3750);
   set_genero(2);
}

void init()
{
   ::init();
   add_action("do_comer", "com*er");
}

void do_comer(string str)
{
   if (!str) return 0;
   if (str!=this_object()->query_name()) return 0;
   
   write("Te zampas la tarta entera a mordiscos. Estaba muy buena.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se zampa de forma avariciosa una suculenta tarta.\n",
             ({this_player()}));
   this_player()->adjust_hp(15);
   this_object()->dest_me();
   return 1;
}
