/* Do not remove the headers from this file! see /USAGE for more info. */

//: COMMAND
// USAGE
//
//  |  ``whisper <player> <message>``
//  |  ``whisper <message> to <player>``
//  |  ``whisper to <player> <message>``
//
// This command is used to whisper a message to another player who is in the same
// room as you without other players being able to hear what you are saying.
//
// .. TAGS: RST

inherit VERB_OB;
inherit M_MESSAGES;
inherit M_GRAMMAR;

void whisper_it(object liv, string str)
{
   string *msgs;
   object *who = ({this_body(), liv});
   object *others;
#ifdef USE_INTRODUCTIONS
   string name, name2;

   others = all_inventory(environment(this_body())) - ({this_body(), liv});

   // Handle whisper names for others in the room.
   foreach (object player in others)
   {
      string msg;

      if (player->is_introduced(this_body()))
         name = this_body()->query_name();
      else
      {
         name = this_body()->physical_appearance();
         if (wizardp(player))
            name = "[" + this_body()->query_name() + "] " + name;
      }

      if (player->is_introduced(liv))
         name2 = liv->query_name();
      else
      {
         name2 = lower_case(liv->physical_appearance());
         if (wizardp(player))
            name2 = "[" + liv->query_name() + "] " + name2;
      }

      // Make sure wizards can see who is talking.
      msg = name + " whispers something to " + punctuate(name2) + "<res>";
      tell(player, msg);
   }
   tell(this_body(), "You whisper to " + liv->query_name() + ": " + punctuate(str) + "<res>");
   tell(liv, this_body()->query_name() + " whispers to you: " + punctuate(str) + "<res>");
#else
   msgs = action(who, "$N $vwhisper to $t: $o", str);
   // change other message
   msgs[2] = this_body()->query_name() + " whispers something to " + liv->query_name() + ".\n";
   inform(who, msgs, environment(this_body()));
#endif
}

void do_whisper_liv_str(object liv, string str)
{
   whisper_it(liv, str);
}

void do_whisper_str_to_liv(string str, object liv)
{
   whisper_it(liv, str);
}

void do_whisper_to_liv_str(object liv, string str)
{
   whisper_it(liv, str);
}

void create()
{
   add_rules(({"LIV STR", "STR to LIV", "to LIV STR"}));
}
