inherit "/std/object";

void setup()
{
   set_name("pera");
   set_short("Pera");
   set_long("Es una pera recien cogida del arbol.\n");
   set_main_plural("Peras");
   add_plural("peras");
   add_alias("pera");
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
   
   write("Te comes una sabrosa pera de agua.\n");
   tell_room(environment(this_player()), this_player()->query_cap_name()+
             " se come una pera.\n",
             ({this_player()}));
   this_player()->adjust_hp(1);
   this_object()->dest_me();
   return 1;
}
