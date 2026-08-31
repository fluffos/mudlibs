/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** score.c -- print out player stats
**
** Tsath, created.
*/

//: PLAYERCOMMAND
//$$ see: stats
// USAGE
//
//  |  ``score``
//  |  ``score -t theme``
//
// Shows you various details about yourself.
// Themes can be seem using the frames command, i.e. ``frames themes``.
//
// .. TAGS: RST

#include <hooks.h>

inherit CMD;
inherit M_WIDGETS;
inherit M_FRAME;

#define FC "<bld>%-10.10s<res>"

private
string stats_string(object body, int width)
{
   string content = "";
   content = body->show_stats();
   content += "Spare stat points: " + body->spare_points() + "\n\n";
   content += sprintf("XP Buff: %-10.10s  Party: %s\n\n",
                      (body->query_guild_xp_buff() ? body->query_guild_xp_buff() + "%" : "None"),
                      (PARTY_D->locate_user(body->short()) || "None"));

   return content;
}

private
string capacity_string(object body, int width)
{
   string content = "";
   float capa = body->query_capacity();
   float enc_capa = body->query_encumbered_capacity();
   float enc_heavy_capa = body->query_heavy_capacity();
   float no_move = body->query_no_move_capacity();
   float max = body->query_max_capacity();
   string capa_string;
   mapping colours =
       ([0.0 + enc_capa:"113", 0.0 + ((enc_heavy_capa * 0.8)):"119", 0.0 + ((enc_heavy_capa * 0.9)):"155", 0.0 +
           enc_heavy_capa:"149", (1.0 * no_move):"143", (0.9 * no_move):"137", 0.0 + no_move:"131", 0.0 + max:"125"]);

   if (capa < enc_capa)
      capa_string = "Unencumbered";
   else if (capa < enc_heavy_capa)
      capa_string = "Encumbered";
   else if (capa < max)
      capa_string = "Heavily encumbered";
   else
      capa_string = "Unable to move";

   //"058","064","070","076","076","082","190","226","220","214","208","202","196",
   content = slider_colours_sum(0.0 + capa, colours, width - 2) + "\n";
   content += "Carrying " + weight_to_string(capa, get_user_variable("metric") != 1) + " / " +
              weight_to_string(max, get_user_variable("metric") != 1) + " - " + capa_string + ".";
   return content;
}

private
string karma_string(object body, int width)
{
   string content = "";
   int karma = body->query_karma();
   string status = "";
   int marker = 65 * ((karma + 1000) / 2000.0);
   int marker2 = 0;

   if (!i_simplify())
      content = slider_red_green(karma, 2000, width - 3) + "\n";

   switch (karma)
   {
   case 1000:
      status = "Goodness incarnate.";
      break;
   case 901..999:
      status = "Fantastic karma. <3 <3";
      break;
   case 501..900:
      status = "Great karma. Everybody loves you.";
      break;
   case 201..500:
      status = "Good karma. Flowers sprout where you walk.";
      break;
   case 0..200:
      status = "Slightly good karma.";
      break;
   case -200.. - 1:
      status = "Slightly bad karma.";
      break;
   case -500.. - 201:
      status = "Quite Bad karma. You will soon provoke attacks from good people.";
      break;
   case -900.. - 501:
      status = "Very Bad karma. You will likely provoke attacks.";
      break;
   case -999.. - 901:
      status = "Extremely bad karma. You will be attacked on sight.";
      break;
   case -1000:
      status = "Evil incarnate.";
      break;
   }

   if (wizardp(this_body()))
      content += sprintf("%s (%d score)\n\n", status, karma);
   else
      content += sprintf("%s\n\n", status);
   return content;
}

private
string score_cmd(object body, int width)
{
   string content = "";
   string name;
   //   mapping accounts;
   int xp = 1;
   xp = body->query_experience();

#ifdef USE_TITLES
   name = body->query_title();
#else
   name = body->query_name();
#endif
   content =
       sprintf("%s  (%s) - Level %d\n", name, wizardp(body->query_link()) ? "Wizard" : "Mortal", body->query_level());

   content += green_bar(xp - body->query_xp_for_level(body->query_level()),
                        body->query_next_xp() - body->query_xp_for_level(body->query_level()), width - 3) +
              "\n";
   if (body->query_next_xp() - body->query_experience() > 0)
      content += sprintf("%d XP - Level %d in %d more points.\n", body->query_experience(), (body->query_level() + 1),
                         (body->query_next_xp() - body->query_experience()));
   else
      content += sprintf("%d XP - You could be level %d.\n", body->query_experience(), body->query_could_be_level());
   content += "\n";
   content += MONEY_D->money_string(body) + "\n";
   content += stats_string(body, width) +
#ifdef USE_KARMA
              karma_string(body, width) +
#endif
              capacity_string(body, width);
   return content;
}

private
void main(mixed *args)
{
   object body;
   string content;
   string arg;
   int num_cur;
   int width = default_user_width() - 11; // Size of left header and space between.
   body = this_body();

   frame_init_user();
   set_frame_left_header(); // This frame will use left header
   if (args && arrayp(args))
      args -= ({0});

   if (sizeof(args) == 2 && wizardp(this_user()))
   {
      if (valid_theme(args[0]))
         set_theme(args[0]);
      body = present(args[1], environment(this_body()));
      if (body && body->is_living())
         set_frame_title("Score for " + body->short()); // Title of frame for other people
      else
      {
         out("Score: Cannot find '" + args[1] + "'.\n"); // Sorry ...
         return;
      }
   }
   else if (sizeof(args) == 1 && wizardp(this_user()))
   {
      if (valid_theme(args[0]))
         set_theme(args[0]);
      else
      {
         body = present(args[0], environment(this_body()));
         if (body && body->is_living())
            set_frame_title("Score for " + body->short()); // Title of frame for other people
         else
         {
            out("Score: Cannot find '" + args[0] + "'.\n"); // Sorry ...
            return;
         }
      }
   }
   else
      set_frame_title("Score"); // Title of frame

   if (!body->is_adversary())
   {
      out("Not an adversary, no score available.");
      return;
   }

   if (!wizardp(this_body()) && sizeof(args) == 1 && valid_theme(args[0]))
      set_theme(args[0]);

   content = score_cmd(body, width);

   num_cur = sizeof(keys(body->query_money() || ([])));
   set_frame_header(" \nExp\n\n\nMoney" + repeat_string("\n", num_cur || 1) +
                    /* This line dynamically figures out height of stats section */
                    "\nStats" + repeat_string("\n", sizeof(explode(this_body()->show_stats(), "\n"))) +
                    /* ... */
                    "\n\nOther\n\n" +
#ifdef USE_KARMA
                    "Karma\n\n" +
#endif
                    "\nWeight");
   set_frame_content(content);
   write(frame_render());
}
