/* Do not remove the headers from this file! see /USAGE for more info. */

inherit LIVING;
inherit M_CONVERSATION;

void check_card();
void give_new_list();
void do_game_command(string str);

string *given = ({});

int quest_status(object player_ob)
{
   return player_ob->check_quest("omega", "birthdaycard");
}

void setup()
{
   set_gender(1);
   set_name("Dr. Gerald Green");
   add_id("doctor", "doc", "gerald", "dr", "ger", "doc_green");
   set_proper_name("Dr. Green");
   set_in_room_desc("Dr. Green, a tall lanky man in a mostly white labcoat.");
   set_long("'Dr. Gerald Green' his name tag says, is a tall wirey man currently sitting on an office"
            " chair with a slight smile on his face.");

   set_options((["hello":"Hello, who are you again?",
                  "card":"I have been running around with the birthday card you gave me ...",
              "lostlist":"I have lost my list of people I needed to visit, can I have a new one?"]));
   set_responses((["hello":"Good to see you again!",
                    "card":({"Oh yes, let me see how you're doing ...", (
                                                                            : check_card:)}),
                "lostlist":({"Let me see...", (
                                                  : give_new_list:)})]));
}

// Birthday card check
void check_card()
{
   object card = present("birthday_card_quest", this_body());
   if (card->completed())
   {
      object tmp = new ("/domains/std/consumable/bandage");
      card->remove();
      tmp->move(this_body());
      tmp = present("birthday_list", this_body());
      tmp->remove();
      do_game_command("emote accepts the card.");
      do_game_command("say You got them all to sign it! Most excellent.");
      this_object()->targetted_action("$N $vhand $t a bandage.", this_body());
      do_game_command("say I had an extra bandage, thanks for helping with the card.");
      QUEST_D->grant_points(this_body(), "omega", "birthdaycard", "end", "begin");
   }
   else
   {
      do_game_command("say You seem to still be missing " + card->missing() + " signature" +
                      (card->missing() == 1 ? "." : "s."));
   }
}

// Handling of new lists, and people asking for more than 1 list.
void give_new_list()
{
   object list = present("birthday_list", this_body());

   if (list)
   {
      do_game_command("say Ahh, but I see it right there sticking out of your pocket?");
      do_game_command("grin");
   }
   else
   {
      object tmp;
      if (member_array(this_body()->query_name(), given) != -1)
      {
         do_game_command("say Sorry, I gave you my personal one last time, I don't have any more.");
         do_game_command("shrug");
         return;
      }

      tmp = new ("/domains/omega/item/birthday_todo")->move(this_body());
      this_object()->targetted_action("$N $vgive $t a new list.", this_body());
      given += ({this_body()->query_name()});
   }
}

void begin_conversation()
{
   object card = present("birthday_card_quest", this_body());
   if (objectp(card))
   {
      set_start(({"card", "lostlist"}), this_body());
   }
   else
      set_start(({"hello"}));
   ::begin_conversation();
}

string query_hint()
{
   object card = present("birthday_card_quest", this_body());
   if (objectp(card))
      if (card->completed())
      {
         return "Try talking to Dr. Green";
      }
      else
      {
         return "Check your list, you seem to be missing signatures.";
      }
}