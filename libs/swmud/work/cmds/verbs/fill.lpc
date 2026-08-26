// Last edited by deforce on 03-10-2010
#include <mudlib.h>
#include <setbit.h>

inherit VERB_OB;

void do_fill_obj(object ob)
{
   object source = present("syringe_bottle", this_body());

   if (present(ob, this_body()) && source)
   {
      ob->fill_with(source);
   }
   else
   {
      write("\nFill " + ob->the_short() + " with what?\n");
   }
}

void do_fill_obj_with_obj(object ob1, object ob2)
{
   if (present(ob1, this_body()) && present(ob2, this_body()))
   {
      ob1->fill_with(ob2);
   }
   else
   {
      write("\nYou'll need to hold both " + ob1->the_short() + " and " + ob2->the_short() + " in order to fill " + ob1->the_short() + " with " + ob2->the_short() + ".\n");
   }
}

void do_fill()
{
   write("\nFill what with what?\n");
}

void create()
{
   add_rules ( ({ "", "OBJ", "OBJ with OBJ" }) );
}