inherit VERB_OB;

void do_use_obj_on_liv(object thing, object living)
{
   mixed result = default_checks(thing);

   if (stringp(result))
   {
      write(result);

      return;
   }

   thing->do_use_on_liv(living);
}

void do_use_obj(object thing)
{
   mixed result = default_checks(thing);

   if (stringp(result))
   {
      write(result);

      return;
   }

   thing->do_use();
}

void do_use()
{
   write("What do you want to use?\n");
}

mixed can_use_obj()
{
   return 1;
}

mixed can_use()
{
   return 1;
}

void create()
{
   add_rules( ({ "", "OBJ", "OBJ on LIV" }) );
}