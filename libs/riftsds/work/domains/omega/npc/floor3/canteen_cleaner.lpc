/* Do not remove the headers from this file! see /USAGE for more info. */

inherit LIVING;
inherit M_ACTIONS;
inherit M_TRIGGERS;
inherit M_WANDER;
inherit M_SMARTMOVE;

void setup()
{
    ::mudlib_setup();
   set_gender(2);
   set_name("Eva");
   add_id("employee");
   set_proper_name("Eva Ramirez");
   set_in_room_desc("Eva Ramirez takes pride in her role as a table cleaner at the canteen.");
   set_long(
       "Eva is a diligent and attentive individual, ensuring that each table is impeccably clean and ready for the "
       "next diners. Eva has a warm and nurturing personality, often striking up conversations with customers while "
       "she tidies up. Her short, curly hair and friendly demeanor make her approachable and well-liked by everyone.");
   set_wander_area("canteen");
   set_wander_time(60);

   set_actions(
       65, ({"say Hello there! Mind if I clear your table for you? How was your meal?",
             "say Let me take care of these plates for you. If there's anything else you need, don't hesitate to ask!",
             "say Your table is now sparkling clean. Feel free to stay and enjoy the ambiance. Have a fantastic time "
             "on Omega Station!",
             "say I see you've finished your meal. Would you like a cosmic-themed dessert to sweeten your interstellar "
             "journey?",
             "say Tables are my canvas, and cleanliness is my art. Allow me to make your dining experience truly "
             "impeccable.",
             "say Did you know our salads are made with greens cultivated in an onboard hydroponic garden? Freshness "
             "is our priority!",
             "say If you have any recommendations or feedback on our canteen, please feel free to share. We're always "
             "looking to improve!",
             "say Excuse the stardust on your table. It's a side effect of the station's captivating cosmic ambiance.",
             "say While I tidy up, let me share a little secret: our chefs have been experimenting with a new "
             "nebula-infused sauce. It's out of this world!",
             "say Thank you for helping us keep the canteen tidy. Your cooperation ensures a pleasant dining "
             "experience for everyone aboard Omega Station.",
             "laugh", "sing", "ponder", "chuckle", "smile"}));
}

void notify_move()
{
   if (present("service_hatch", environment()) && present("service_hatch", environment())->is_open())
   {
      do_game_command("close hatch");
      do_game_command("say This hatch keeps opening.");
   }
   ::notify_move();
}