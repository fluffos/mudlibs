/* Do not remove the headers from this file! see /USAGE for more info. */

#include <npcscript.h>

inherit LIVING;
inherit M_VENDOR;
inherit M_TRIGGERS;
inherit M_CONVERSATION;
inherit M_SMARTMOVE;
inherit M_NPCSCRIPT;

void setup()
{
   set_gender(1);
   set_name("Liam");
   add_id("employee");
   set_proper_name("Liam Johnson");
   set_in_room_desc("Liam Johnson, the canteen cashier looks bored behind the counter.");
   set_long("Liam Johnson is a friendly and efficient staff member who mans the till at the canteen. With his warm "
            "smile and quick wit, he ensures smooth transactions and assists customers with their orders. Liam has a "
            "youthful charm, and his energetic nature makes him a favorite among the station's visitors. He wears a "
            "neat uniform and is always ready to provide assistance with a touch-screen menu.\n\n"
            "Liam wears a small pin on his shirt with the head of a goblin.");
   add_pattern("%s says: I am your manager%s.", ( : "say Are you Mr. Stevens?" :));
   add_pattern("%s says: I am your boss%s.", ( : "say Are you Mr. Stevens?" :));

   /* Determines what type of currency we'll use */
   set_currency_type("credit");

   /* Tells vendor we will sell things */
   set_for_sale(1);

   set_sell((["^common/consumable/astro_wrap":-1,
         "^common/consumable/penne_arrabiata":-1, "^common/consumable/cosmic_burger":10, "^std/consumable/beer":-1,
          "^common/consumable/nebula_noodles":-1, "^common/consumable/nebula_nectar":-1,
                    "^std/consumable/peanuts":20]));
   set_clear_numbers(1);
   set_actions(
       120,
       ({"say Good day! What can I ring up for you today? Our holographic menu offers an array of stellar options!",
         "say Do you need any extra toppings or a refreshing beverage to go with your meal? Just let me know, and "
         "I'll make it happen!",
         "say Thank you for dining with us! Your total comes to " + (random(10) + random(10) + 5) +
             " credits. Payment options include credits, crypto, "
             "or a gravity-defying dance routine!",
         "sing Brip to brap, brap you talk crap, and most of all you cant rap", "whistle",
         "Do you want peas with that??"}));

   // The below is a huge tribute to Eddie Izzard's Death Star Canteen bit.
   set_start(({"penne"}));
   set_options((["penne":"I will have the penne a la arrabiata.",
                 "doyou":"Do you know who I am? I can kill you with a single thought![cha>20]",
                  "tray":"No, I will not need a tray. I do not need a tray to kill you. I can kill you without a tray, "
                         "with the power of the Force - which is strong within me - even though I could kill you with "
                         "a tray if I so wished. For I would hack at your neck with the thin bit until the blood "
                         "flowed across the canteen floor...",
               "hotfood":"Oh, I see, the food is hot. I'm sorry, I, I did not realize. Hah! Hah! I thought you were "
                         "challenging me to a fight to the death.",
                "oktray":"Okay, I'll get a tray then.",
             "deathstar":
                 "Yes, but I am Vader, I am Lord Vader. Everyone challenges me to a fight to the death. Lord Vader. "
                 "Darth Vader, I am Dart Vader, Lord Vader. Sir Lord Vader, Sir Lord Darth Vader. Lord Darth Sir Lord "
                 "Vader of Cheam. Sir Lord Baron von Vaderham. The Death Star. I run the Death Star.",
            "deathstar2":"This is the Death Star. You're in the Death Star. I run this star. I'm your boss.",
                   "mrs":"No, I'm... who is Mr. Stephens?",
              "catering":"I'm not head of catering! I am Vader. I can kill catering with a thought.",
             "catering2":"I can kill you all. I can kill me with a thought. Just... I'll get a tray, fuck it!..."]));
   set_responses((["penne":"You'll need a tray.@@doyou,oktray",
                   "doyou":"You'll still need a tray.@@tray@@oktray", "oktray":"Great!@@@@doyou",
                    "tray":"No, the food is hot. You'll need a tray to put the food on.@@hotfood",
                 "hotfood":"Fight to the death? This is canteen, I am Liam and I work here.@@deathstar",
               "deathstar":"What's the Death Star? Isn't this the Omega Station?@@deathstar2",
              "deathstar2":"You're Mr. Stevens?@@mrs", "mrs":"He's head of catering.@@catering",
                "catering":"What?@@catering2",
               "catering2":"Here's your tray. Now what would you like to order, Jeff Vader?"]));

   create_script("lunch");
   add_steps(
       "lunch",
       ({
           step(SCRIPT_ACTION, (: set_for_sale, 0:)),
           step(SCRIPT_DESC, "Liam Johnson, the canteen cashier is standing here."),
           step(SCRIPT_ACTION, "say Well, time for some lunch."),
           step(SCRIPT_ACTION, "go south@@go south@@go south@@hum"),
           step(SCRIPT_WAIT, 5),
           step(SCRIPT_ACTION, "push button"),
           step(SCRIPT_TRIGGER, "The elevator door opens.", "go northwest"),
           step(SCRIPT_DESC, "Liam Johnson, leaning against the elevator panel."),
           step(SCRIPT_TRIGGER, "The elevator door closes.", "push 8"),
           step(SCRIPT_TRIGGER, "Elevator speaker says, \"You have arrived at Landing Terminal\".", "go southeast"),
           step(SCRIPT_DESC, "Liam Johnson, the canteen cashier is standing here."),
           step(SCRIPT_ACTION, "go east@@go north@@hum"),
           step(SCRIPT_WAIT, 10),
           step(SCRIPT_ACTION, "say I'd like to order the Stellar Sandwich with extra mayo, please.@@emote sits down."),
           step(SCRIPT_DESC, "Liam Johnson, the canteen cashier is sitting here."),
           step(SCRIPT_WAIT, 20),
           step(SCRIPT_ACTION, "emote eats a sandwich.@@emote stands up."),
           step(SCRIPT_DESC, "Liam Johnson, the canteen cashier is standing here."),
           step(SCRIPT_ACTION, "say That was delicious! Back to the work!@@go south@@go west@@push button"),
           step(SCRIPT_TRIGGER, "The elevator door opens.", "go northwest"),
           step(SCRIPT_DESC, "Liam Johnson, leaning against the elevator panel."),
           step(SCRIPT_TRIGGER, "The elevator door closes.", "push 3"),
           step(SCRIPT_TRIGGER, "Elevator speaker says, \"You have arrived at cafeteria\".", "go southeast"),
           step(SCRIPT_DESC, "Liam Johnson, the canteen cashier is standing here."),
           step(SCRIPT_WAIT, 10),
           step(SCRIPT_ACTION, "go north@@go north@@go north@@hum"),
           step(SCRIPT_ACTION, "say That was a great lunch, now back to work."),
           step(SCRIPT_ACTION, (: set_for_sale, 1:)),
           step(SCRIPT_DESC, "Liam Johnson, the canteen cashier looks bored behind the counter."),
           step(SCRIPT_ACTION, "grin@@emote sits down behind the counter."),
       }));
}
