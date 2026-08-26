/* Do not remove the headers from this file! see /USAGE for more info. */
// Work in NonProgress ... will be finished sometime after Vendor has been redone. probably for a7
//
// Finished 10-20 years after by Tsath.

//: MODULE
// M_TRAINER, module for turning NPCs into skill trainers. This module depends and inherits
// functionality from NPC_CONVERSATION to allow the training to use conversations as interface.
//
// Works:
// - Skill training
//

#include <config/skills.h>
#include <config/stats.h>

inherit M_CONVERSATION;
inherit CLASS_SKILL;

void add_response(string key, mixed act);
void add_option(string key, mixed act);
void add_to_start(string key);
varargs void targetted_action(mixed msg, object target, mixed *obs...);

private
mapping skill_restrictions = ([]);
private
string *skills_we_train = ({});
private
mapping trainer_msgs = MESSAGES_D->query_messages("trainer-default");
private
string *stats_we_train = ({});
private
string currency; // Loaded during create()
private
int stat_cost = 10; // Overridden in create()
private
mapping stat_abrevs = (["strength":"str", "agility":"agi", "intelligence":"int", "willpower":"wil"]);

void set_trainer_msgs(mapping msgs)
{
   string *msg_names = keys(trainer_msgs);
   foreach (string key, string msg in msgs)
   {
      if (!member_array(key, msg_names) + 1)
         error("Invalid msg name: " + key);
      trainer_msgs[key] = msg;
   }
}

void set_trainer_skill(string s, int value)
{
   this_object()->set_skill(s, value);
   skills_we_train += ({s});
}

void set_train_stat(mixed s)
{
   if (arrayp(s))
      stats_we_train = s;
   if (stringp(s))
      stats_we_train += ({s});
}

int is_trainer()
{
   return 1;
}

void set_train_restrict(mixed *restrictions)
{
   string *valid_skills = SKILL_D->query_skills();

   foreach (string skill, string restriction in restrictions)
   {
      if (member_array(skill, valid_skills) == -1)
         error("Invalid skill: " + skill);
      skill_restrictions += ([skill:restriction]);
   }
}

void do_training(object trainee, string skill)
{
   class skill trainee_skill = trainee->query_skill(skill);

   if (!trainee_skill)
      return;
   else
   {
      int trainee_skillpts = trainee_skill->skill_points;
      int trainer_skill = this_object()->query_skill_pts(skill);
      string msg;

      if (trainee_skill->training_points == 0)
         msg = trainer_msgs["no_pts_msg"];
      else if (member_array(skill, keys(skill_restrictions)) != -1 ||
               member_array(skill, keys(this_object()->query_skills())) == -1)
         msg = trainer_msgs["unable_msg"];
      else if (trainee_skillpts < trainer_skill)
      {
         for (int i = 0; i < trainee_skill->training_points; i++)
         {
            trainee->test_skill(skill, trainee_skillpts + 1);
         }
         trainee->clear_training_points(skill);

         switch (trainee->query_skill_pts(skill) - trainee_skillpts)
         {
         case 0..1:
            msg = trainer_msgs["fail_msg"];
            break;
         case 2..6:
            msg = trainer_msgs["low_msg"];
            break;
         case 7..13:
            msg = trainer_msgs["mid_msg"];
            break;
         case 14..18:
            msg = trainer_msgs["high_msg"];
            break;
         default:
            msg = trainer_msgs["very_high_msg"];
         }
      }
      else
         msg = trainer_msgs["reject_msg"];

      targetted_action(msg, trainee);
   }
}

varargs int stat_train_cost(string statstr)
{
   int cost = stat_cost;
   int stat;

   cost = cost * STAT_TRAIN_SCALE;
#ifdef STAT_TRAIN_SCALES_WITH_LEVEL
   cost = this_body()->query_level() * cost;
#endif
#ifdef STAT_TRAIN_SCALES_WITH_STAT
   if (statstr && strlen(statstr))
      stat = call_other(this_body(), "query_" + stat_abrevs[statstr]);
   else
      stat = max(({
          this_body()->query_str(),
          this_body()->query_agi(),
          this_body()->query_int(),
          this_body()->query_wil(),
      }));
   cost = cost * (stat + 1);
#endif

   return cost;
}

void train_stat(string s)
{
   string abr;
   object b=this_body();
   int cost = stat_train_cost(s);

   if (undefinedp(stat_abrevs[s]))
      error("Unknown stat '" + s + "'.");

   // No spare points, end it here.
   if (!b->spare_points())
   {
      targetted_action(trainer_msgs["no_stat_pts_msg"], b);
      return;
   }

   if (b->query_amt_currency(currency) < cost)
   {
      targetted_action(trainer_msgs["no_money"], b);
      return;
   }

   abr = stat_abrevs[s];
   b->subtract_money(currency, cost);
   b->targetted_action("$N $vgive $t $o.", this_object(), cost + " " + currency);
   targetted_action(trainer_msgs["stat_train"], b, s);

   call_other(b, "inc_mod_" + abr);
   b->refresh_stats();

   //Need this one again to update potential price hike. Must be done after stat increase.
   add_option("stat_" + s, "Train my " + s + ", please. [" + stat_train_cost(s) + " " + currency + "]");
}

void begin_conversation()
{
   if (sizeof(stats_we_train))
   {
      int train_cost;
      if (sscanf(STAT_TRAIN_COST, "%d %s", stat_cost, currency) != 2)
         error("STAT_TRAIN_COST is " + STAT_TRAIN_COST +
               " in /include/config/skills.h incorrect format, should be \"50 gold\" or similar.");

      foreach (string s in stats_we_train)
      {
         add_option("stat_" + s, "Train my " + s + ", please. [" + stat_train_cost(s) + " " + currency + "]");
         add_response("stat_" + s, ({"Okay! @@stat_" + s, ( : train_stat, s:)}));
         add_to_start("stat_" + s);
      }
   }
   ::begin_conversation();
}

void setup_trainer_conversation(int skill_max)
{
   add_option("rank", "What skill rank are you?");
   add_response("rank", "I can train your skills to around rank " + SKILL_D->skill_title_from_pts(skill_max));
   add_to_start("rank");

   foreach (string skill in skills_we_train)
   {
      add_option(skill, "I want to train my #T#" + skill + " skill.");
      add_response(skill, "Okay, " + skill + " it is...#T#" + skill);
      add_to_start(skill);
   }
}