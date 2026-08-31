/* Do not remove the headers from this file! see /USAGE for more info. */

inherit LIVING;
inherit M_ACCOUNTANT;
inherit M_ACTIONS;

string query_hint(int level)
{
   if (level < 5)
      return "Alexia here provides access to the OBS bank - try 'talk to alex'.";
}

void setup()
{
   set_gender(2);
   set_name("Alexia Novak");
   add_id("alexia", "alexia novak", "employee", "financial advisor", "advisor", "alex");
   set_proper_name("Alexia");
   set_in_room_desc("Alexia Novak, a seasoned financial advisor.");
   set_long("Alexia is a dynamic professional with a commanding knowledge of interstellar finance. With a tailored "
            "uniform that seamlessly blends corporate elegance with futuristic flair, she exudes confidence and "
            "approachability. Alexia often engages clients with a warm, holographically enhanced smile, embodying the "
            "perfect fusion of human touch and technological efficiency.");
   set_bank_id("Omega Bank Services");
   set_bank_name("Omega Bank Services");
   set_currency_type("credit");
   set_exchange_fee(5);
   set_actions(120,
               ({"say Greetings, valued client. How may I assist you with your cosmic financial endeavors today?",
                 "say Our state-of-the-art security protocols ensure your assets are as safe as they are well-invested.",
                 "sayConsidering the fluctuations in the cosmic market, I'd recommend diversifying your interstellar "
                 "portfolio for optimal returns.",
                 "say Should you have any questions about our zero-gravity banking services, feel free to ask; I'm here to "
                 "guide you.",
                 "say Your financial journey is our priority; let's explore the best hyperspace investment options "
                 "tailored to your goals.",
                 "say Rest assured, our quantum encryption ensures the utmost confidentiality in your cosmic transactions.",
                 "say Space may be infinite, but your financial success doesn't have to be. Let's plan for your stellar "
                 "future together."}));
}
