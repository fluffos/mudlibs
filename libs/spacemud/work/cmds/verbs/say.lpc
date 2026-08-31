/* Do not remove the headers from this file! see /USAGE for more info. */

/* Do not remove headers from this file! see /USAGE for more info. */

/*
 * Converted from command to verb 05052000 -- Tigran
 */

inherit VERB_OB;
inherit M_GRAMMAR;

//: COMMAND
// USAGE
//
//  |  ``say <something>``
//
//  Say something.
//
// .. TAGS: RST

mixed can_say_str()
{
   return 1;
}

mixed do_say_str(string str)
{
   string *msgs;
   object *others = ({});
   object ob;

   // Collect speech recipients upwards through environments,
   // where proper. Not possible to use normal message propagation
   // if you want to save say history in the body object.
   // -- Marroc
   ob = this_body();
   while (ob && ob->environment_can_hear())
   {
      others += all_inventory(environment(ob)) - ({ob});
      ob = environment(ob);
   }

   switch (explode(str, " ")[0])
   {
      string *out = ({});
   case "/last":
   case "/history":
      out = ({"History of says:"});
      msgs = this_body()->list_say_history();
      if (sizeof(msgs))
         out += msgs;
      else
         out += ({"\t<none>"});
      more(out);
      break;
   default:
#ifdef USE_INTRODUCTIONS
      foreach (object player in others)
      {
         string name;
         string msg;

         if (!this_body()->is_body())
            name = this_body()->query_name();
         else if (player->is_introduced(this_body()))
            name = this_body()->query_name();
         else
         {
            name = this_body()->physical_appearance();
            if (wizardp(player))
               name = "[" + this_body()->query_name() + "] " + name;
         }

         // Make sure wizards can see who is talking.
         msg = "%^SAY%^" + name + " says:%^RESET%^ " + punctuate(str) + "<res>";
         tell(player, msg);
         player->add_say_history(msg);
      }
      tell(this_body(), "%^SAY%^You say:%^RESET%^ " + punctuate(str) + "<res>");
#else
      msgs = this_body()->action(({this_body()}), "%^SAY%^$N $vsay:%^RESET%^ $o<res>", punctuate(str));
      this_body()->inform(({this_body()}), msgs, others);
      this_body()->add_say_history(msgs[0]);
      others->add_say_history(msgs[1]);
#endif
   }
}

void create(mixed args...)
{
   add_rules(({"STR"}), ({}));
}

/*
 * Converse compatability stuff
 */
nomask int valid_resend(string ob)
{
   return ob == "/cmds/player/converse";
}

nomask void do_resend(mixed arg1, mixed arg2)
{
   do_say_str(arg1);
}
