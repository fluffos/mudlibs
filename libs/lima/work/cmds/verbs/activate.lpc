inherit VERB_OB;

void do_activate_obj(object ob)
{
   if (!try_to_acquire(ob))
      return;

   ob->do_activate();
}

void create()
{
   add_rules(({"OBJ"}));
}
