inherit "/std/item";

void setup ()
 {
 	set_name("Pan envasado");
 	add_alias("pan");
 	add_alias("Pan"); 
 	set_long("Un trozo de pan envasado.\n");
 	set_main_plural("panes envasados");
 	add_plural("panes");
 	set_short("Pan envasado");
 	set_weight(10);
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
   write("Nah... El pan envasado no es muy sabroso.\n");
   return 1;
}
               