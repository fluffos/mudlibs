/* Do not remove the headers from this file! see /USAGE for more info. */

inherit CHEST;

void setup()
{
   set_adj("metal","rusty");
   set_id("cabinet","rusty_cabinet");
   remove_id("chest");
   set_long("The metal cabinet above is a weathered relic, bearing the scars of time with rusted surfaces and "
            "pockmarks, standing as a testament to years of neglect and lack of maintenance. Its once-shiny exterior "
            "has faded, mirroring the worn and dirty state of the recovery room itself.");
   set_gettable("#It's way too big to move.\n");
}

//Allow direct gets from this object.
mixed direct_get_obj(object ob)
{
   if (environment(ob)==this_object())
      {
         write("(From the "+this_object()->short()+")");
         return 1;
      }
}