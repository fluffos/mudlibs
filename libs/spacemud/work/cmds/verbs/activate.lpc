inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``activate <something>``
//
// Active or start something that can be activated.
//
// .. TAGS: RST

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
