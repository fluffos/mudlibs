/* Do not remove the headers from this file! see /USAGE for more info. */

/*
 * By Beek.  Merged in some functionality written by Valentino.
 *
 * Extended and documented by Tsath to check for stats and skill ranks before options are shown.
 */

//: MODULE
// M_CONVERSATION for doing interactive conversations with NPCs.
//
// Three things are needed to run conversations::
//   - A set of conversations options - set_options()
//   - A set of matching replies for the options - set_responses()
//   - A set of options to start from - set_start()
//
// Both the replies and the options have special syntaxes that is used to control
// the interactions. See the functions below for syntax descriptions.
//
// This module supports filtering out certain options depending on the *stats* or *skills* of
// the player. These requirements are specified in the options the players can chose and will
// be limited accordingly. The filters are just added to the end of the reply option string,
// examples follow below.
//
// Special option syntax:
//   - [str>10] - only shown if strength larger than 10
//   - [str=10] - only shown if strength equals 10
//   - [str<10] - only shown if strength less than 10.
//
// Stats are: str, agi, int, con, cha.
//
// Example:
//     ``"I can probably lift that tree trunk for you?[str>60]"``
//
// This also works for skills for <, > and =:
//
// Example:
//     ``"I can shoot that pistol right out of your hand [combat/ranged/pistol>3]"``
//
// The numbers for skills refer to the ranks from 1-20. (See SKILL_D documentation)
//
// For responses (from the NPC), some extra syntax allows you to open up new options and/or
// close others. The responses can also be different types
//
// Special option syntax:
//
//    ``@@add options@@remove options``
//
// The options can be seperated by "," to include more options.
//
// Example:
//     ``"I'll say something.@@add_option1,add_option2@@remove_option3"``
//
// A response can be 4 different things:
//
//   - A simple string that will be said by the NPC - "Hi there!"
//   - An emote that must be performed - "!wave"
//   - A function pointer - (: check_quest item :)
//   - An array combined of all three things above.
//
// Example:
//     ``set_responses("hello":({"Hi there!","!wave",(: check_quest_item:) }));``
//
// .. TAGS: RST

#include <config/skills.h>

inherit M_ACTIONS;
inherit M_INPUT;

private
mapping stats = (["str":"Strength", "agi":"Agility", "int":"Intelligence", "con":"Constitution", "cha":"Charisma"]);

void simple_action(string);
string query_name();

mapping options = ([]);
mapping responses = ([]);

mapping current = ([]);
mapping start = ([]);
mixed *default_start = ({});
mixed goodbye_action;
int can_talk = 1;

//: FUNCTION set_goodbye
// This action is used when the NPC says goodbye.
void set_goodbye(mixed arg)
{
   goodbye_action = arg;
}

//: FUNCTION add_option
// Adds a single option to the actions available.
// See also set_option() documentation.
void add_option(string key, mixed act)
{
   options[key] = act;
}

//: FUNCTION remove_option
// Removes a single option from the actions available.
// See also add_option() documentation.
void remove_option(string key)
{
   map_delete(options, key);
}

//: FUNCTION add_options
// Adds a mapping of options to the actions available.
// See also set_option() documentation.
void add_options(mapping m)
{
   options += m;
}

//: FUNCTION add_response
// Adds a single key and response to the responses available.
void add_response(string key, mixed act)
{
   responses[key] = act;
}

//: FUNCTION add_responses
// Adds a mapping of responses to be available.
void add_responses(mapping m)
{
   responses += m;
}

//: FUNCTION add_to_start
// Adds a start option for everyone.
void add_to_start(string key)
{
   if (member_array(key, default_start) == -1)
      default_start += ({key});
}

//: FUNCTION add_start
// Adds a start option for a specific target.
varargs void add_start(mixed *a, object target)
{
   if (target)
      start[target] += a;
   else
      default_start += a;
}

//: FUNCTION set_can_talk
// Can be used to turn off if the NPC can talk or not, e.g. if they are
// moving to a different location they might not be able to talk while moving.
void set_can_talk(int i)
{
   can_talk = i;
}

private
int check_option(string key)
{
   string stat_chk, s, skill;
   int req, gt, lt, eq;
   string option = options[key];

   // Less than, greater than and equals checks.
   if (sscanf(option, "%s[%s>%d]", s, stat_chk, req) == 3)
      gt = 1;
   else if (sscanf(option, "%s[%s<%d]", s, stat_chk, req) == 3)
      lt = 1;
   else if (sscanf(option, "%s[%s=%d]", s, stat_chk, req) == 3)
      eq = 1;

#ifdef SKILL_CONFIG_USES_TRAINING_PTS
   // This section strips away training options where the body has no training points.
   if (strsrch(option, "#T#") != -1)
   {
      if (sscanf(option, "%s#T#%s skill.", s, skill) == 2)
      {
         if (this_body()->query_training_pts(skill) == 0)
            return 0;
         s = s + skill;
      }
      options[key] = s;
   }
#endif

   // If at this points we have no "s", there's nothing that can strip away the option.
   if (strlen(s) == 0)
      return 1;

   if (gt || lt || eq)
   {
      if (strlen(stat_chk) == 3)
      {
         int stat = call_other(this_body(), "query_" + stat_chk);
         if ((gt && req > stat) || (lt && req < stat) || (eq && req == stat))
            return 0;
         s = "[<229>" + stats[stat_chk] + "<res>] " + s;
      }
      else
      {
         int skill_rank = SKILL_D->skill_rank(this_body(), stat_chk);
         if ((gt && skill_rank <= req) || (lt && skill_rank >= req) || (eq && skill_rank == req))
            return 0;
         s = "[<209>Skill: " + explode(stat_chk, "/")[ < 1] + "<res>] " + s;
      }
      options[key] = s;
   }
   return 1;
}

//: FUNCTION set_options
// Set a mapping of keys and options. These options are typically things the player says in the conversation and can
// select from. Only keys added using set_start() will be shown initially. Other options can be introduced later in the
// conversation using the add and remove syntax described in the set_responses() function.
void set_options(mapping m)
{
   options = m;
}

//: FUNCTION set_responses
// Set a mapping of keys (that must match the option keys), and responses. The responses use a special syntax described
// below, that will allow adding and removing new options.
void set_responses(mapping m)
{
   responses = m;
}

//: FUNCTION set_start
// Sets the options that the menu contains initially.
varargs void set_start(mixed *a, object target)
{
   if (target)
      start[target] = a;
   else
      default_start = a;
}

mixed direct_talk_to_liv()
{
   return can_talk ? 1 : "#That person cannot talk right now.";
}

mixed direct_talk_with_liv()
{
   return can_talk ? 1 : "#That person cannot talk right now.";
}

void continue_conversation(object, string);

//: FUNCTION show_menu
// Shows the conversation menu to ob.
void show_menu(object ob)
{
   int n = 1;

   if (!current[ob])
   {
      continue_conversation(ob, "q");
      return;
   }

   write("\n");

   foreach (string option in current[ob])
   {
      if (check_option(option))
         printf("   %%^MENU_CHOICE%%^%2d%%^RESET%%^: %s\n", n++, options[option]);
      else
         current[ob] -= ({option});
   }
   printf("    %%^MENU_CHOICE%%^q%%^RESET%%^: Quit talking to " + query_name() + ".\n");

   modal_simple(( : continue_conversation, ob:), "[choice] :>");
}

//: FUNCTION do_action
// Do a specific action whether it's talking, calling a function, training or doing an emote.
void do_action(object ob, mixed action)
{
   string add;
   string remove;
   string train;

   if (arrayp(action))
      foreach (mixed act in action)
         do_action(ob, act);
   else
   {
      if (functionp(action))
         evaluate(action);
      else if (stringp(action))
      {
         action = replace_string(action, "$t", ob->query_name());
         if (sscanf(action, "%s@@%s", action, add) == 2)
         {
            if (sscanf(add, "%s@@%s", add, remove) == 2)
               current[ob] -= explode(remove, ",");
            current[ob] += explode(add, ",");
         }

         if (sscanf(action, "%s#T#%s", action, train) == 2)
         {
            if (action[0] == '!')
               do_game_command(action[1..]);
            else
               do_game_command("say " + action);
            // Are we a trainer? Otherwise ignore this part...
            if (this_object()->is_trainer())
               this_object()->do_training(ob, train);
            return;
         }

         if (action[0] == '!')
            do_game_command(action[1..]);
         else
            do_game_command("say " + action);
      }
      else
      {
         if (wizardp(ob))
         {
            if (!action)
               write("Error: no response found\n");
            else
               write("Error: invalid type response\n");
         }
         simple_action("$N $vare not sure what to say in response to that.");
         show_menu(ob);
      }
   }
}

//: FUNCTION bye
// Handle goodbye for ob.
void bye(object ob)
{
   map_delete(current, ob);

   if (goodbye_action)
      do_action(ob, goodbye_action);
}

//: FUNCTION exit_conversations
// Exit the conversation if the NPC needs to leave.
// Default is to say "Sorry, I have to go", but this can
// be changed using ``set_goodbye(action)``.
void exit_conversations()
{
   foreach (object body in keys(current))
   {
      if (present(body, environment(this_object())))
      {
         body->modal_pop();
         map_delete(current, body);
         do_action(body, goodbye_action || "Sorry, I have to go.");
      }
   }
}

//: FUNCTION continue_conversation
// Continue the conversation with ob given specific input.
// Used internally in the menu system.
void continue_conversation(object ob, string input)
{
   int num;
   string tmp;
   string response;
   string option;
   string tag;

   if (input == "q" || !current[ob])
   {
      return bye(ob);
   }
   if (sscanf(input, "%d%s", num, tmp) != 2 || tmp != "")
   {
      simple_action("$N $vsuggest that you use the numbers to indicate what you want to say.");
      show_menu(ob);
      return;
   }
   if (num <= 0 || num > sizeof(current[ob]))
   {
      simple_action("$N $vsuggest that you pick a legal option.");
      show_menu(ob);
      return;
   }
   num--;
   tag = current[ob][num];
   // Strip away [Blargh] tags infront of options.
   if (sscanf(options[tag], "[%s] %s", tmp, option) != 2)
      option = options[tag];
   ob->simple_action("$N $vsay: " + option);
   response = responses[tag];
   current[ob] -= ({tag});

   do_action(ob, response);

   if (sizeof(current[ob]))
      show_menu(ob);
   else
      return bye(ob);
}

//: FUNCTION filter_start
// Override this function, to filter start options for a specific body.
// See M_GUILD_MASTER for an example where the guild master adds an option to
// join or leave the guild depending on the state of the body.
string *filter_start(string *a, object body)
{
   return a;
}

//: FUNCTION begin_conversation
// Begins the conversation for this_body(). The start options are default start options,
// but filtered through the filter_start() function.
void begin_conversation()
{
   current[this_body()] = start[this_body()] || default_start;
   current[this_body()] = filter_start(current[this_body()], this_body());

   show_menu(this_body());
}
