/* Do not remove the headers from this file! see /USAGE for more info. */

inherit VERB_OB;

//: COMMAND
// USAGE
//
//  |  ``enter``
//  |  ``enter <something>``
//
// Enter something in your environment, a door, a car, a portal, an airlock.
//
// .. TAGS: RST

void do_enter()
{
   string *doors;
   object env = environment(this_body());

   // Alternatively, if there's only one exit, take it.
   doors = filter(all_inventory(env), ( : $1->is_exit() :));
   if (sizeof(doors) == 1 && doors[0])
   {
      string cannot_go = doors[0]->direct_verb_rule("go", "OBJ", doors[0]);
      if (cannot_go && stringp(cannot_go))
      {
         write(cannot_go);
         return;
      }

      write("(You enter through " + doors[0]->the_short() + ")");
      doors[0]->do_verb_rule("go");
   }
   else
      write("Not sure what to enter?");
}

void do_enter_obj(object ob)
{
   ob->do_verb_rule("enter", "OBJ", ob);
}

void create()
{
   add_rules(({"OBJ", ""}), ({}));
}
