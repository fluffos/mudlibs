// Last edited by deforce on 03-14-2008
// @./path/createmenu->start_menu()
#include <mudlib.h>
#include <playerflags.h>
#include <commands.h>
#include <security.h>

inherit M_INPUT;
inherit M_ACCESS;

string get_stat_name(string stat);
string get_stat_full_name(string stat);
string format_stat(string stat);
void ansi_input(string input);
void stats_input(string input);
void display_stats();
void display_human_stats();
void handedness_input(string input);
void display_handedness();
void team_input(string input);
void display_team();
void add_to_stat(string stat, int value);
void set_human_bonus(string stat);
void set_human_sacrifice(string stat);
void set_human_modifier(int value);
void validate_human_stats();
void start_menu();
void complete_character();

// Stats Menu
void display_stats()
{
   write("\n%^BOLD%^Attributes:%^RESET%^\n\n");

   write("Remaining Points: " + (this_body()->query_points_remaining() / 5) + "\n\n");

   write(format_stat("str") + "     " + format_stat("int") + "\n");
   write(format_stat("con") + "     " + format_stat("cha") + "\n");
   write(format_stat("agi") + "     " + format_stat("luc") + "\n");
   write(format_stat("dex") + "     " + format_stat("for") + "\n");
   write(format_stat("per") + "\n\n");

   modal_simple((: stats_input :), "Type 'help' for more info > ");
}

void display_human_stats()
{
   object this_body = this_body();
   int human_race_modifier = this_body->query_human_race_modifier();

   validate_human_stats();

   write("\n%^BOLD%^Attributes:%^RESET%^\n\n");

   write("  Remaining Points: " + (this_body->query_points_remaining() / 5) + "\n");
   write("Attribute Modifier: " + human_race_modifier + "\n");

   if (human_race_modifier)
   {
      write(sprintf("             Bonus: %-12s     Sacrifice: %s\n",
         capitalize(get_stat_full_name(this_body->query_human_race_bonus_attribute())),
         capitalize(get_stat_full_name(this_body->query_human_race_sacrifice_attribute()))));
   }

   write("\n");
   write("     " + format_stat("str") + "     " + format_stat("int") + "\n");
   write("     " + format_stat("con") + "     " + format_stat("cha") + "\n");
   write("     " + format_stat("agi") + "     " + format_stat("luc") + "\n");
   write("     " + format_stat("dex") + "     " + format_stat("for") + "\n");
   write("     " + format_stat("per") + "\n\n");

   modal_simple((: stats_input :), "Type 'help' for more info > ");
}

void display_handedness()
{
   write("\nType 'left' or 'right' to continue.\n\n");

   modal_simple((: handedness_input :), "Type 'help' for more info > ");
}

void display_team()
{
   write("\nType 'imperial', 'rebel' or 'neutral' to continue.\n\n");

   modal_simple((: team_input :), "Type 'help' for more info > ");
}

string format_stat(string stat)
{
   object this_body = this_body();

   if (this_body->is_human())
   {
      string sacrifice = this_body->query_human_race_sacrifice_attribute();
      string bonus = this_body->query_human_race_bonus_attribute();

      if (this_body->query_human_race_modifier() && (sacrifice != bonus))
      {
         if (sacrifice == stat)
         {
            return sprintf("%%^BOLD%%^%12s%%^RESET%%^ [%%^BOLD%%^%s%%^RESET%%^]: %%^BOLD%%^%%^RED%%^%2d%%^RESET%%^ / %%^BOLD%%^%%^RED%%^%-2d%%^RESET%%^",
               capitalize(get_stat_full_name(stat)), stat,
               (call_other(this_body, "query_" + stat) / 5),
               (call_other(this_body, "query_race_" + stat + "_max") / 5));
         }
         else if (bonus == stat)
         {
            return sprintf("%%^BOLD%%^%12s%%^RESET%%^ [%%^BOLD%%^%s%%^RESET%%^]: %%^BOLD%%^%%^GREEN%%^%2d%%^RESET%%^ / %%^BOLD%%^%%^GREEN%%^%-2d%%^RESET%%^",
               capitalize(get_stat_full_name(stat)), stat,
               (call_other(this_body, "query_" + stat) / 5),
               (call_other(this_body, "query_race_" + stat + "_max") / 5));
         }
      }
   }

   return sprintf("%%^BOLD%%^%12s%%^RESET%%^ [%%^BOLD%%^%s%%^RESET%%^]: %2d / %-2d",
      capitalize(get_stat_full_name(stat)), stat,
      (call_other(this_body, "query_" + stat) / 5),
      (call_other(this_body, "query_race_" + stat + "_max") / 5));
}

string get_stat_name(string stat)
{
   switch(lower_case(stat))
   {
      case "strength":
      case "str":
         return "str";
      case "constitution":
      case "con":
         return "con";
      case "agility":
      case "agi":
         return "agi";
      case "dexterity":
      case "dex":
         return "dex";
      case "perception":
      case "per":
         return "per";
      case "intelligence":
      case "int":
         return "int";
      case "charisma":
      case "cha":
         return "cha";
      case "luck":
      case "luc":
         return "luc";
      case "force":
      case "for":
         return "for";
   }

   return 0;
}

string get_stat_full_name(string stat)
{
   switch(lower_case(stat))
   {
      case "strength":
      case "str":
         return "strength";
      case "constitution":
      case "con":
         return "constitution";
      case "agility":
      case "agi":
         return "agility";
      case "dexterity":
      case "dex":
         return "dexterity";
      case "perception":
      case "per":
         return "perception";
      case "intelligence":
      case "int":
         return "intelligence";
      case "charisma":
      case "cha":
         return "charisma";
      case "luck":
      case "luc":
         return "luck";
      case "force":
      case "for":
         return "force";
   }

   return 0;
}

void add_to_stat(string s, int val)
{
   string stat_shortname;
   string set_stat;
   string query_stat;
   int pts, newval;

   stat_shortname = get_stat_name(s);

   if (!stat_shortname)
   {
      write("\n%^YELLOW%^Invalid attribute name.%^RESET%^\n");
      write("Choices are: str, con, agi, dex, per, int, cha, luc, for.\n\n");

      return;
   }

   pts = this_body()->query_points_remaining();

   if ((pts - val) < 0)
   {
      int levels = val / 5;

      write("\n%^YELLOW%^You do not have " + levels + " point" + (levels > 1 ? "s" : "") + " left to distribute.%^RESET%^\n");

      return;
   }

   set_stat = "set_" + stat_shortname;
   query_stat = "query_" + stat_shortname;

   newval = call_other(this_body(), query_stat);

   if ((newval + val) < call_other(this_body(), "query_race_" + stat_shortname + "_min"))
   {
      int levels = val / -5;

      write("\n%^YELLOW%^You cannot reduce " + get_stat_full_name(s) + " (" + stat_shortname + ") by " + levels + " point" + (levels > 1 ? "s" : "") + ".%^RESET%^\n");

      return;
   }
   else if ((newval + val) > call_other(this_body(), "query_race_" + stat_shortname + "_max"))
   {
      write("\n%^YELLOW%^You cannot raise " + get_stat_full_name(s) + " (" + stat_shortname + ") any higher.%^RESET%^\n");

      return;
   }

   write("\n" + (val > 0 ? "%^BOLD%^%^GREEN%^Added" : "%^BOLD%^%^RED%^Subtracted") + " " + abs(val / 5) + " point" + (abs(val / 5) > 1 ? "s" : "") + " " + ((val > 0) ? "to" : "from") + " " + get_stat_full_name(s) + ".%^RESET%^\n");

   this_body()->set_points_remaining(pts - val);
   newval = call_other(this_body(), query_stat) + val;
   call_other(this_body(), set_stat, newval);
   // call_other(this_body(), query_stat, newval);
}

void set_human_bonus(string stat)
{
   object this_body = this_body();
   string stat_shortname = get_stat_name(stat);

   if (!stat_shortname)
   {
      write("\n%^YELLOW%^Invalid attribute name.%^RESET%^\n");
      write("Choices are: str, con, agi, dex, per, int, cha, luc, for.\n\n");

      return;
   }

   this_body->set_human_race_bonus_attribute(stat_shortname);

   write("\n%^BOLD%^%^GREEN%^Set " + get_stat_full_name(stat) + " as your bonus attribute.%^RESET%^\n");
}

void set_human_sacrifice(string stat)
{
   object this_body = this_body();
   string stat_shortname = get_stat_name(stat);

   if (!stat_shortname)
   {
      write("\n%^YELLOW%^Invalid attribute name.%^RESET%^\n");
      write("Choices are: str, con, agi, dex, per, int, cha, luc, for.\n\n");

      return;
   }

   this_body->set_human_race_sacrifice_attribute(stat_shortname);

   write("\n%^BOLD%^%^RED%^Set " + get_stat_full_name(stat) + " as your sacrifice attribute.%^RESET%^\n");
}

void set_human_modifier(int value)
{
   if ((value < 0) || (value > 2))
   {
      write("\n%^YELLOW%^Your attribute modifier must be from 0 to 2.%^RESET%^\n");

      return;
   }

   this_body()->set_human_race_modifier(value);

   write("\n%^BOLD%^%^GREEN%^Set your attribute modifier to " + value + ".%^RESET%^\n");
}

void validate_human_stats()
{
   object this_body = this_body();

   foreach (string stat in ({ "str", "con", "agi", "dex", "per", "int", "cha", "luc", "for" }) )
   {
      int min = call_other(this_body, "query_race_" + stat + "_min");
      int max = call_other(this_body, "query_race_" + stat + "_max");
      int current = call_other(this_body, "query_" + stat);
      int points_remaining = this_body->query_points_remaining();

      if (max < current)
      {
         int difference = current - max;
         call_other(this_body, "set_" + stat, max);
         this_body->set_points_remaining(points_remaining + difference);	
      }
      else if (min > current)
      {
         int difference = min - current;
         call_other(this_body, "set_" + stat, min);
         this_body->set_points_remaining(points_remaining - difference);
      }
   }
}

void ansi_input(string input)
{
   switch (lower_case(input))
   {
      case "y":
      case "yes":
      case "aye":
         this_user()->query_shell_ob()->set_variable("ansi", 1);
         this_user()->update_translations();
         break;
   }

   write("\n%^BOLD%^Character Creation%^RESET%^\n\n");
   write("Section 1 of 3: Attributes\n");

   this_body()->is_human() ? display_human_stats() : display_stats();
}

void stats_input(string input)
{
   string stat;
   int val;

   if (sscanf(input, "a %s %d", stat, val) == 2)
   {
      add_to_stat(stat, (val * 5));
   }
   else if (sscanf(input, "a %s", stat) == 1)
   {
      add_to_stat(stat, 5);
   }
   else if (sscanf(input, "s %s %d", stat, val) == 2)
   {
      add_to_stat(stat, (val * -5));
   }
   else if (sscanf(input, "s %s", stat) == 1)
   {
      add_to_stat(stat, -5);
   }
   else if (this_body()->is_human() && (sscanf(input, "bonus %s", stat) == 1))
   {
      set_human_bonus(stat);
   }
   else if (this_body()->is_human() && (sscanf(input, "sacrifice %s", stat) == 1))
   {
      set_human_sacrifice(stat);
   }
   else if (this_body()->is_human() && (sscanf(input, "mod %d", val) == 1))
   {
      set_human_modifier(val);
   }
   else if (input == "help")
   {
      write("\nType 'help <attribute>' for info about a particular attribute.\n");
      write("Type 'a <attribute> [value]' to add one or more points to an attribute.\n");
      write("Type 's <attribute> [value]' to substract one or more points from an attribute.\n\n");
      write("Examples: 'a str' will add one point to strength.\n");
      write("          's dex 5' will subtract five points from dexterity.\n\n");

      if (this_body()->is_human())
      {
         write("Type 'bonus <attribute>' to choose your positive modifier.\n");
         write("Type 'sacrifice <attribute>' to choose your negative modifier.\n");
         write("Type 'mod <value>' to set the modifier from 0 to 2.\n\n");
      }

      write("Type 'list' to see your current attributes.\n");
      write("Type 'done' after you've distributed all points and are satisfied.\n\n");

      modal_simple((: stats_input :), "Type 'help' for more info > ");
      return;
   }
   else if (sscanf(input, "help %s", stat) == 1)
   {
      string stat_shortname = get_stat_name(stat);

      if (stat_shortname)
      {
         write("\n" + read_file("/help/player/attributes/" + get_stat_full_name(stat)) + "\n");
      }
      else
      {
         write("\n%^YELLOW%^'" + capitalize(stat) + "' is not a valid attribute.%^RESET%^\n");
      }

      modal_simple((: stats_input :), "Type 'help' for more info > ");
   }
   else if (input == "done")
   {
      int points = this_body()->query_points_remaining();

      if ((points > 0) && !wizardp(this_body()))
      {
         int levels = (points / 5);

         write("\n%^YELLOW%^You still have " + levels + " point" + (levels > 1 ? "s" : "") + " to distribute to your stats.%^RESET%^\n");
         write("You must distribute all of your points to continue.\n");
      }
      else
      {
         write("\nSection 2 of 3: Dominant Hand\n");

         display_handedness();

         return;
      }
   }
   else
   {
      this_body()->do_game_command(input);
   }

   this_body()->is_human() ? display_human_stats() : display_stats();
}

void handedness_input(string input)
{
   string hand;

   if (sscanf(input, "%s", hand) == 1)
   {
      if ((hand == "left") || (hand == "right"))
      {
         this_body()->set_dominant_hand(hand);

         write("\nSection 3 of 3: Team\n");

         display_team();

         return;
      }
   }
   else if (input == "help")
   {
      write("\nThe hand you choose will have better coordination with one-handed weapons.\n");
      write("It will also be the first choice for performing actions, such as wielding a\n");
      write("one-handed weapon, when the hand isn't specified.\n");

      display_handedness();

      return;
   }
   else
   {
      this_body()->do_game_command(input);
   }

   display_handedness();
}

void team_input(string input)
{
   string team;

   if (sscanf(input, "%s", team) == 1)
   {
      if ((team == "imperial") || (team == "rebel") || (team == "neutral"))
      {
         if (team == "imperial")
         {
            this_body()->set_team_alignment(-100);
            this_user()->channel_add("empire");
         }
         else if (team == "rebel")
         {
            this_body()->set_team_alignment(100);
            this_user()->channel_add("rebel");
         }
         else
         {
            this_body()->set_team_alignment(0);
            this_user()->channel_add("neutral");
         }

         complete_character();

         return;
      }
   }
   else if (input == "help")
   {
      write("\nYou will have easier access to certain areas, depending on your team alignment.\n");
      write("All three options have advantages and disadvantages,\n");
      write("and neither is better or worse than any other.\n\n");

      write("If you're unsure at this point, there is no penalty for a Neutral\n");
      write("switching to Rebel or Imperial.\n");

      display_team();

      return;
   }
   else
   {
      this_body()->do_game_command(input);
   }

   display_team();
}

void complete_character()
{
   this_body()->set_max_health(this_body()->query_max_health() + (this_body()->query_con() / 5));
   this_body()->set_health(this_body()->query_max_health());
   this_body()->clear_flag(F_IN_EDIT);
   write("\n%^BOLD%^Your character is complete.  Welcome to " + mud_name() + "!%^RESET%^\n\n");

   // Move to start location
   this_body()->set_start_location(START);
   this_body()->move_to_start();
   this_body()->force_look(1);

   // Update carry capacity
   this_body()->refresh_stats();

   destruct(this_object());
}

void start_menu()
{
   this_body()->set_flag(F_IN_EDIT);
   modal_push((: ansi_input :), "\nWould you like to enable color? ");
}