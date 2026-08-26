inherit VERB_OB;

void do_activate_obj(object thing)
{
   mixed result = default_checks(thing);

   if (stringp(result))
   {
      write(result);

      return;
   }

   thing->do_activate();
}

void do_activate()
{
   write("Activate what?\n");
}

mixed can_activate_obj()
{
   return 1;
}

mixed can_activate()
{
   return 1;
}

void create()
{
   add_rules( ({ "", "OBJ" }) );
}