/* Do not remove the headers from this file! see /USAGE for more info. */

inherit LIVING;
inherit M_CONVERSATION;
inherit M_VENDOR;
inherit M_TRIGGERS;
inherit M_SMARTMOVE;
inherit M_NPCSCRIPT;

int ive_talked = 0;
int days_since_arrival = 28 + random(20);
int bag_given = 0;
int quest_given = 0;
void select_bag(int bag_num);
void begin_quest();

mixed check_buy(object ob)
{
   return base_name(ob) == "/domains/std/consumable/bandage" ||
          "%^SAY%^Dr. Williams says<res>: I only buy back unused bandages, sorry.";
}

void add_inventory()
{
   add_sell("^std/consumable/bandage", -1);
   add_sell("^std/consumable/chemo_satchel", -1);
   add_sell("^std/consumable/pain_killers", -1);
}

void handle_card()
{
   object card = present("birthday_card_quest", this_body());
   object list = present("birthday_list", this_body());
   if (!card)
      return;
   if (list)
   {
      list->remove_synonym("landing terminal");
      list->add_synonym("landing terminal (DONE)", "2");
   }
   this_object()->do_game_command("laugh " + this_body()->query_name());
   card->add_signer("Freddy");
   this_object()->targetted_action("$N $vgive $t back a birthday card.", this_body());
}

void begin_conversation()
{
   object card = present("birthday_card_quest", this_body());
   if (card && !card->signed_by("Freddy"))
   {
      set_start(({"card"}), this_body());
   }
   else
      set_start(({"hello"}));
   ::begin_conversation();
}

string gender_nick()
{
   if (!this_body())
      return "someone";
   switch (this_body()->query_gender())
   {
   case 0:
      return "girl";
   case 1:
      return "boy";
   case 2:
      return "person";
   }
}

private
void summon_muffin()
{
   object muffin = new ("/domains/common/consumable/chocolate_muffin");
   muffin->move(this_object());
}

void setup()
{
   set_gender(1);
   set_name("Dr. Fred Williams");
   add_id("doctor", "doc", "fred", "frederick", "williams", "doc_williams", "freddy");
   set_proper_name("Dr. Williams");
   set_in_room_desc("Dr. Williams, a short rotund man with only a few wisps of red hair remaining.");
   set_long("'Dr. Frederick Williams' his name tag says, is a short man in brown pants and a spotless labcoat.");
   set_currency_type("credit");

   set_for_sale(1);
   set_will_buy(( : check_buy:));

   add_inventory();
   set_clear_numbers(1);

   set_options((["hello":"Hello, doctor.",
              "whatsell":"So what do you sell?", "card":"Hello, Dr. Green asked me to get you to sign this birthday "
                                                        "card for your colleague Dr. Ellin ...",
            "giveithere":"Here you go (hand over the card)."]));
   set_responses((["hello":({"I am Dr. Fred, you may call me Freddy. Pleased to meet you. Let me know if you want to "
                             "buy medical supplies.@@whatsell"}),
                "whatsell":({"Bandages, pain killers and other things. Check my list above.",
                             "!point to the list on the wall."}),
                    "card":"Ah, yes! Give it to me and I'll sign it.@@giveithere",
              "giveithere":({"!emote accepts the card and signs it.",
                             "Thanks for being Gerald's errand " + gender_nick() + ".",
                             (
                                 : handle_card:)})]));
   create_script_from_file("lunch", "scripts/doc_williams_lunch.npcs");
   create_script_from_file("snack", "scripts/doc_williams_snack.npcs");
   EVENT_D->schedule_event("08 12 *", this_object(), "lunch");
   EVENT_D->schedule_event("30 10,14 *", this_object(), "snack");
   set_recovery_time(10);
}

void recover()
{
   object clinic_room = load_object("/domains/omega/room/floor8/w_clinic");
   if (environment(this_object()) == clinic_room)
      return;
   tell_from_outside(environment(this_object()), "Dr. Williams hurries back to the clinic.");
   this_object()->move(clinic_room);
   tell_from_outside(environment(this_object()), "Dr. Williams hurries into the room.");
   do_game_command("say Sorry, my lunch took a bit longer than normally.");
   set_for_sale(1);
}

string query_hint(int level)
{
   return query_for_sale() ? "This doctor sells medical supplies 'list'." : 0;
}
