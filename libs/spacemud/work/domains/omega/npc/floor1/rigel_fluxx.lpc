/* Do not remove the headers from this file! see /USAGE for more info. */

inherit LIVING;
inherit M_CONVERSATION;
inherit M_VENDOR;

string *bodies = ({});
mapping codes = ([]);

void do_game_command(string);

string query_hint(int level)
{
   switch (level)
   {
   case 0..4:
      return "Rigel Fluxx can help you if you're broke, and in need of basic equipment. He also runs a shop.";
   }
}
void add_inventory()
{
   add_sell("^common/weapon/screwdriver", -1);
   add_sell("^common/weapon/wrench", -1);
   add_sell("^common/weapon/fan_blade", -1);
   add_sell("^std/armour/leather_jacket", 2);
   add_sell("^std/consumable/beer", 10);
   add_sell("^std/consumable/cig", -1);
}

string gen_code()
{
   return (1 + random(9)) + "" + random(10) + "" + random(10) + "" + random(10) + "";
}

void begin_quest()
{
   object b = this_body();
   string code = gen_code();
   if (b->quest_task("omega", "commsrep") != "None")
   {
      do_game_command("emote punches the communication terminal a few times.");
      do_game_command("say Let ol' Rig here reset the code for you, here's a new one: " + code);
      do_game_command("say Find tha 4 panels and set them, then come back and talk to me. Ya can see the current codes "
                      "on the terminal standing here.");
      codes[b->query_name()] = code;
      return;
   }

   do_game_command("say Okay, find tha 4 panels and set them to communication code: " + code);
   codes[b->query_name()] = code;
   QUEST_D->begin_quest(b, "omega", "commsrep");
   do_game_command("say Then come back here and talk to me. Ya can see the current codes "
                   "on the terminal standing here.");
}

int quest_completed()
{
   object b = this_body();
   string *panelcodes = present("terminal", environment())->quest_codes();
   string code = b ? codes[b->query_name()] : "99999999";
   panelcodes -= ({code});
   return sizeof(panelcodes) ? 0 : 1;
}

void end_quest()
{
   object b = this_body();
   if (quest_completed())
   {
      do_game_command("say You're right! All set. Thank ya so much.");
      QUEST_D->grant_points(this_body(), "omega", "commsrep", "end", "begin");
      return;
   }
   do_game_command("say Something is not right, look at the terminal.");
}

void free_gear()
{
   object b = this_body();
   object tmp;
   if (member_array(b->query_name(), bodies) != -1)
   {
      do_game_command("say I've given ya stuff before, use that.");
      return;
   }

   if (b->query_level() > 1 || sizeof(keys(ACCOUNT_D->query_accounts(b))) || sizeof(keys(b->query_money())))
   {
      do_game_command("say Ya seem to me like a person who would have a few credits lying around? Look at my list for "
                      "a few useful items I sell.");
      return;
   }
   do_game_command("Lemme see what I have lyin' 'round.");
   tmp = new ("/domains/common/weapon/wrench");
   tmp->move(this_object());
   do_game_command("give wrench to " + b->query_name());
   tmp = new ("/domains/common/weapon/fan_blade");
   tmp->move(this_object());
   do_game_command("give blade to " + b->query_name());
   tmp = new ("/domains/std/consumable/cig");
   tmp->move(this_object());
   do_game_command("give cig to " + b->query_name());
   bodies += ({b->query_name()});
}

void set_code(object ob, string code)
{
   codes[ob->query_name()] = code;
}

mixed direct_talk_to_liv()
{
   if (quest_completed())
      set_start(({"endquest"}), this_body());
   else if (this_body()->check_quest("omega", "commsrep") == 2)
      set_start(({"stillsuffer"}), this_body());
   return 1;
}

void setup()
{
   set_gender(1);
   set_name("Rigel Fluxx");
   add_id("engineer", "rigel", "rig");
   set_for_sale(1);
   set_will_buy(1);
   add_inventory();

   set_proper_name("Rigel");
   set_in_room_desc("Rigel Fluxx, a frazzled maintenance engineer");
   set_long("Rigel is a wiry, bespectacled individual with a perpetual grease stain on his jumpsuit, a testament to "
            "his ceaseless battle against entropy at the bottom of the Omega Station. His frazzled hair and energetic "
            "demeanor reflect the perpetual challenge of keeping the maintenance floor in order.");

   set_options((["hello":"Why are you looking so frazzled?",
             "barricade":"What is up with this barricade?", "tg":"TechGremlins? Uh.. what is that?",
               "lurkers":"Wait, there are 'lurkers' as well?", "tgfight":"How do you best fight the TechGremlins?",
           "lurkerfight":"How do you best fight the lurkers?", "morebarri":"How do I get past the barricade?",
                  "free":"You have any gear that can help me clear these things out?",
             "dualwield":"Any hints about the weapons?", "tgdo":"So ... got any good stories about the gremlins?",
              "commpans":"Can I reset the communication panels for you while I'm in there? [quest]",
              "endquest":"I've done all the panels, what now?",
           "stillsuffer":"So how are the TechGoblins and Lunar lurkers?"]));

   set_responses(
       (["hello":"Blasted TechGremlins! They're like hyperactive circuit imps, always up to something. They screwed up "
                 "all the communication panels again, I need them all reset.@@tg,commpans",
              "commpans":({"Ya sure can! I'll generate a new code, and you go an set 'em.", (
                                                                                                : begin_quest:)}),
              "endquest":({"Let me check the terminal here ...", (
                                                                     : end_quest:)}),
           "stillsuffer":
               "Better, but still a plague. Thanks for helping with the communication panels though, that was a treat.",
             "barricade":"To keep the critters out! And the Lurkers!@@lurkers,free,morebarri",
             "morebarri":"Well, just climb up the barricade to get over it. And don't fall, ya hear?",
                    "tg":"Aye, maintenance bots that has malfunctioned. I swear, these little troublemakers are a "
                         "menace to my sanity. And my tools!@@tgfight,tgdo",
                  "tgdo":
                      ({"Oi, listen to this one!",
                        "So, there I was, doin' routine repairs in the outer docking bay. "
                        "Suddenly, a bunch of TechGremlins decide it's the perfect time for a joyride on a maintenance "
                        "drone.",
                        "Picture this – tiny gremlins, zipping around on a drone like it's a hoverboard at a "
                        "space amusement park. I'm chasin' after 'em, yelling like a space banshee, but those little "
                        "rascals are dodgin' and gigglin' like there's no tomorrow.",
                        "Next thing I know, they "
                        "accidentally activate the drone's emergency alarms, and the whole station thinks we're under "
                        "attack. Chaos, I tell ya!",
                        "Turns out, it was just a bunch of mischievous TechGremlins treatin' "
                        "a drone like their own cosmic carousel.",
                        "Never a dull day with these critters around."}),
               "lurkers":"Ah, those Lunar Lurkers, right peculiar critters they are. Got this glow about 'em, like "
                         "tiny living dust bunnies. Always tinkerin' with things, rearrangin' stuff like they're "
                         "redecoratin' the entire station.@@lurkerfight",
               "tgfight":
                   "Well, being basically small robots, a good strong knock over the case will demolish most of 'em "
                   "bots with a few blows. Blades won't do damage to 'em due to their hard shells.",
           "lurkerfight":"The lurkers are squishy, and blunt force will glance off 'em. Here ya need a good blade "
                         "to cut them in two.",
                  "free":({(
                               : free_gear:),
                           "A wrench will work for the TechGremlins, and any blade should be ideal for them "
                           "lurkers.@@dualwield",
                           "!grumble"}),
             "dualwield":({"Both weapons can be dual-wielded for that extra punch. They will do more damage "
                           "that way. You can also wield one weapon in each of your hands, but chances are you won't "
                           "damage the lil' critters half the time.",
                           "Use the 'equip' command to see how versatile weapons can give different bonuses."})]));

   set_start(({"hello", "barricade"}));
}
