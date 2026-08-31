/* Do not remove the headers from this file! see /USAGE for more info. */

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``exit <something>``
//
// Exit, leave, or disembark something.
//
// .. TAGS: RST

void do_exit()
{
   string *exits;
   object env = environment(this_body());

   // This only works if env is an exit.
   if (env->is_exit())
   {
      env->do_verb_rule("exit");
      return;
   }

   // Alternatively, if there's only one exit, take it.
   exits = env->query_exit_directions();
   if (sizeof(exits) == 1)
   {
      write("(Taking the " + exits[0] + " exit out of here)");
      env->do_go_str(exits[0]);
   }
   else
   {
      write("Not sure what exit to take?");
   }
}

void do_exit_obj(object ob)
{
   environment(this_body())->do_verb_rule("exit", "OBJ", ob);
}

void create()
{
   add_rules(({"OBJ", ""}), ({"leave", "disembark"}));
}
