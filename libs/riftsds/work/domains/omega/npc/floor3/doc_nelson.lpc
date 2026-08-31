/* Do not remove the headers from this file! see /USAGE for more info. */

inherit LIVING;
inherit M_CONVERSATION;

int ive_talked = 0;
int days_since_arrival = 28 + random(20);
int bag_given = 0;
int quest_given = 0;
void select_bag(int bag_num);
void begin_quest();

void handle_card()
{
   object card = present("birthday_card_quest", this_body());
   object list = present("birthday_list", this_body());
   if (!card)
      return;
   if (list)
   {
      list->remove_synonym("canteen");
      list->add_synonym("canteen (DONE)", "1");
   }
   card->add_signer("Nelson");
   this_object()->targetted_action("$N $vgive $t back a birthday card.", this_body());
}

void begin_conversation()
{
   object card = present("birthday_card_quest", this_body());
   if (card && !card->signed_by("Lenady"))
   {
      set_start(({"card"}), this_body());
   }
   else
      set_start(({"hello"}));
   ::begin_conversation();
}

void setup()
{
   set_gender(2);
   set_name("Dr. Lena Nelson");
   add_id("doctor", "doc", "lena", "nelson", "doc_nelson", "lenakovich");
   set_proper_name("Dr. Nelson");
   set_in_room_desc("Dr. Nelson, a skinny woman in a labcoat is sitting here, eating.");
   set_long("'Dr. Lena Nelson' her name tag says, is a skinny woman in green pants and a spotless labcoat.");

   set_options((["hello":"Hello, doctor.",
               "howhelp":"So what do you do here?", "card":"Hello, Dr. Green asked me to get you to sign this birthday "
                                                           "card for your colleague Dr. Ellin ...",
                 "roach":"Strange sounds? Where?", "giveithere":"Here you go (hand over the card)."]));
   set_responses(
       (["hello":"Hey sir, how can I help?@@howhelp",
              "howhelp":({"I'm eating currently, the food here is quite delicious! Go ask for the menu with Liam.",
                          "Although, I did hear some strange sounds... @@roach"}),
                 "card":"Ah, yes! Give it to me and I'll sign it.@@giveithere",
           "giveithere":({"!emote accepts the card and signs it.", "Thanks for helping out!",
                          (
                              : handle_card:)}),
                "roach":
                    ({"I had the distinct feeling that there were space roaches under the floors here in the canteen.",
                      "I heard there's a service hatch north of here?"}),
   ]));
}
