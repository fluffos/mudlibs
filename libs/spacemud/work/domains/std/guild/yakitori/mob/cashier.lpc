/* Do not remove the headers from this file! see /USAGE for more info. */

inherit LIVING;
inherit M_VENDOR;
inherit M_CONVERSATION;
inherit M_BLOCKEXITS;

object *people = ({});
object *solvers = ({});

string *member_actions =
    ({"$N $vnod at $t, \"Just put the warez out in the back.\"",
      "$N $vstep aside for $t, who $v1walk into the kitchen.", "$N $vsmile at $t and $vlet $t pass."});

void ignore_person()
{
   object body = this_body();
   people += ({body});
   continue_conversation(body, "q");
   TBUG(people);
}

void allow_person()
{
   solvers += ({this_body()});
}

object *solvers()
{
   return solvers;
}

void begin_conversation()
{
   TBUG("Begin convo");
   if (member_array(this_body(), people) != -1 && random(5))
   {
      this_object()->targetted_action("$N $vraise $p palm towards $p1 face. $N $vseem busy.", this_body());
      return;
   }
   if (sizeof(people) > 0)
      people -= ({choice(people)});
   if (member_array(this_body(), people) == -1)
      ::begin_conversation();
   else
      this_object()->targetted_action("$N $vseem too busy to talk to $t.", this_body());
}

object *ignored()
{
   return people;
}

private
mixed handle_blocks(string dir)
{
   /* is the player above the level restriction? */
   if (this_body()->query_member_guild("yakitori"))
   {
      this_object()->targetted_action(choice(member_actions), this_body());
      return 0;
   }
   if (member_array(this_body(), solvers) != -1)
   {
      this_object()->targetted_action("$N $vsmile and $vsay, \"Oh, you can see kitchen now!\"", this_body());
      return 0;
   }

   return ::handle_blocks(dir);
}

void setup()
{
   set_name("Fuyuko");
   add_id("cashier");
   set_gender(2);
   set_proper_name("Fuyuko");
   set_in_room_desc("Fuyuko, a Yakitori Chicken employee.");
   set_long("Fuyuko is in a red and white dress smiling at you. She points to a 'list' on the wall.");
   set_currency_type("dollar");
   set_for_sale(1);

   set_sell((["/domains/std/guild/yakitori/consumable/skewer_small":-1,
             "/domains/std/guild/yakitori/consumable/skewer_medium":-1,
              "/domains/std/guild/yakitori/consumable/skewer_large":-1, ]));
   set_will_buy(1);
   set_options((["good":"Hi? What's good?",
              "manager":"Can I see your manager?", "manager2":"Uh, I had a bad chicken skewer ... ?",
            "manager2c":"あなたは鶏に見えます?", "manager2b":"あなたは鶏肉が好きです?",
             "japanese":"Was my Japanese okay ...?",
             "manager3":"So, can I talk to your manager now? It's not about the chicken.",
              "riddle1":"Riddle? What? No?", "riddle2":"Okay, I'll do my best?", "riddle2a":"フライパン (A frying pan)",
             "riddle2b":"クッキー (A cookie)", "riddle2c":"ムーン (The moon)", ]));

   set_responses((["good":"Everything, sir. See the menu.",
                "manager":"Manager, why?@@manager2,manager2b,manager2c",
               "manager2":({"You lie! Not possible.", (
                                                          : ignore_person()
                                                          :)}),
              "manager2b":"Bangō@@japanese", "manager2c":({"Oh I do, do I?", (
                                                                                 : ignore_person()
                                                                                 :)}),
               "japanese":"A bit simple in your tonality, but I understood your question.@@manager3",
               "manager3":"If you can answer a riddle?@@riddle1,riddle2",
                "riddle1":({"Then go away.", (
                                                 : ignore_person()
                                                 :)}),
                "riddle2":"Okay then. Bread ( パン) is like bread, but what bread is not edible? "
                          "@@riddle2a,riddle2b,riddle2c@@manager2,riddle1",
               "riddle2a":({"Wow, you do understand our culture! You can go see him.@@@@riddle2b,riddle2c,manager2c",
                            (
                                : allow_person()
                                :)}),
               "riddle2b":({"You were pretending. Leave.", (
                                                               : ignore_person()
                                                               :)}),
               "riddle2b":({"You were pretending. Leave.", (
                                                               : ignore_person()
                                                               :)}),
               "riddle2c":({"You were pretending. Leave.", (
                                                               : ignore_person()
                                                               :)}),
   ]));
   set_start(({"good", "manager"}));
   add_block("west");
   set_block_action("$N $vstep out infront of $t.\n\"No visitors in kitchen!\", $n $vsnarl.");
}
