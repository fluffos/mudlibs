/* Do not remove the headers from this file! see /USAGE for more info. */

/*
** score.c -- print out player stats
**
** Tsath, created.
*/

//: PLAYERCOMMAND
//$$ see: stats
// USAGE score
//
// Shows you various details about yourself.

#include <config.h>
#include <hooks.h>

inherit CMD;
inherit M_WIDGETS;
inherit M_FRAME;

#define FC "<bld>%-10.10s<res>"

// Always returns a strlen 6.
string pretty_bonus(int b)
{
   string out = "      ";
   if (b > 0)
      out = "(<002>+" + b + "<res>)";
   else if (b < 0)
      out = "(<001>" + b + "<res>)";

   if (colour_strlen(out) < 6)
      out += repeat_string(" ", 6 - colour_strlen(out));

   return out;
}

private
string stats_string(object body, int width)
{
   string content;
   content = sprintf("BASE SCORES: Str %-4d%s  Agi %-4d%s  Int %-4d%s  Wil  %-4d%s\n" +
                         "DERIVED    : Con %-4d%s  Wis %-4d%s  Cha %-4d%s  Mana %-4d%s\n",
                     body->query_str(), (pretty_bonus(body->query_str() - body->query_str_pure())), body->query_agi(),
                     (pretty_bonus(body->query_agi() - body->query_agi_pure())), body->query_int(),
                     (pretty_bonus(body->query_int() - body->query_int_pure())), body->query_wil(),
                     (pretty_bonus(body->query_wil() - body->query_wil_pure())), body->query_con(),
                     (pretty_bonus(body->query_con() - body->query_con_pure())), body->query_wis(),
                     (pretty_bonus(body->query_wis() - body->query_wis_pure())), body->query_cha(),
                     (pretty_bonus(body->query_cha() - body->query_cha_pure())), body->query_man(),
                     (pretty_bonus(body->query_man() - body->query_man_pure()))) +
             "\n";

   content += "Spare stat points: " + body->spare_points() + "\n\n";
   content += sprintf("XP Buff: %s\n\n",
                      (body->query_guild_xp_buff() ? "Guild buff " + body->query_guild_xp_buff() + "%" : "None"));

   return content;
}

private
string money_string(object body, int width)
{
   string money_info = "";
   string *curr;
   int i;
   curr = body->query_currencies();
   if (!sizeof(curr))
   {
      money_info += "You are carrying no money.\n";
   }
   else
   {
      for (i = 0; i < sizeof(curr); i++)
      {
         mapping money = MONEY_D->calculate_denominations(body->query_amt_money(curr[i]), curr[i]);
         string *denom_order = MONEY_D->query_denominations(curr[i]);
         string *money_str = ({});
         int j = 0;
         while (j < sizeof(denom_order))
         {
            string denom = denom_order[j];
            int count = money[denom];
            if (count)
               money_str += ({count + " " + denom + (count == 1 ? "" : "s")});
            j++;
         }
         if (sizeof(curr) > 1)
            money_info += sprintf("%s: %s", accent(capitalize(curr[i])), format_list(money_str) + "\n");
         else
            money_info += sprintf("%s", format_list(money_str) + "\n");
      }
   }
   return money_info;
}

private
string capacity_string(object body, int width)
{
   string content;
   int capa = body->query_capacity();
   int enc_capa = body->query_encumbered_capacity();
   int enc_heavy_capa = body->query_heavy_capacity();
   int no_move = body->query_no_move_capacity();
   int max = body->query_max_capacity();
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
              weight_to_string(enc_capa, get_user_variable("metric") != 1) + " - " + capa_string + ".";
   return content;
}

private
string karma_string(object body, int width)
{
   string content;
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
   string content;
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
                        body->query_next_xp() - body->query_xp_for_level(body->query_level()), width - 2) +
              "\n";
   if (body->query_next_xp() - body->query_experience() > 0)
      content += sprintf("%d XP - Level %d in %d more points.\n", body->query_experience(), (body->query_level() + 1),
                         (body->query_next_xp() - body->query_experience()));
   else
      content += sprintf("%d XP - You could be level %d.\n", body->query_experience(), body->query_could_be_level());
   /*
   money_info = "";
   accounts = ACCOUNT_D->query_accounts(body);
   if (!sizeof(accounts))
   {
       money_info += "";
   }
   else
   {
       i = 0;
       foreach (string bank, float val in accounts)
       {
           money_info += sprintf("%d (in %s Bank)\n",
                             to_int(val),
                             capitalize(bank));
           i++;
       }
   }
   if (strlen(money_info))
       content += money_info;
*/
   content += "\n";
   content += money_string(body, width) + "\n";
   content += stats_string(body, width) +
#ifdef USE_KARMA
              karma_string(body, width) +
#endif
              capacity_string(body, width);
   return content;
}

private
void main(string arg)
{
   object body;
   string content;
   int num_cur;
   int width = default_user_width() - 11; // Size of left header and space between.
   body = this_body();

   // Frame initializations
   frame_init_user();
   set_frame_left_header(); // This frame will use left header

   if (strlen(arg) > 0 && wizardp(this_user()))
   {
      body = find_body(arg);
      if (!body)
      {
         body = present(arg, environment(this_body()));
         if (!body || !body->is_living())
         {
            out("Score: Cannot find '" + arg + "'.\n"); // Sorry ...
            return;
         }
      }
      set_frame_title("Score for " + body->short()); // Title of frame for other people
   }
   else
      set_frame_title("Score"); // Title of frame

   content = score_cmd(body, width);

   num_cur = sizeof(body->query_currencies());
   set_frame_header(" \nExp\n\n\nMoney" + repeat_string("\n", num_cur || 1) + "\nStats\n\n\n\n\nOther\n\n" +
#ifdef USE_KARMA
                    "Karma\n\n" +
#endif
                    "\nWeight");
   set_frame_content(content);
   write(frame_render());
}
