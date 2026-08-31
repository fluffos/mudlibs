/* Do not remove the headers from this file! see /USAGE for more info. */

#include <daemons.h>
#define QP_TO_XP_RATIO 10

int has_status_line();
void update_status_line();
void add_experience(int x);

mapping quests;
int points;
int deaths;

void save_me();

private
add_quest_pts(int pts)
{
   points += pts;
   add_experience(QP_TO_XP_RATIO * pts);
}

int begin_quest(string domain, string quest, int pts)
{
   if (!quests)
      quests = ([]);
   if (!quests[domain])
      quests[domain] = ([]);

   if (previous_object() != find_object(QUEST_D))
      return 0;

   // IF we have the key already, the quest has begun already
   if (member_array(quest, keys(quests[domain])) != -1)
      return 0;

   quests[domain][quest] = "begin";
   add_quest_pts(pts);
   save_me();
   return 1;
}

int forced_set_quest_task(string domain, string quest, string task)
{
   quests[domain][quest] = task;
   return 1;
}

int update_quest(string domain, string quest, string task, string prev_task, int pts)
{
   if (!quests)
      quests = ([]);

   if (previous_object() != find_object(QUEST_D) && !wizardp(this_body()))
      return 0;

   // Cannot update something that hasn't been begun
   if (!mapp(quests[domain]) || member_array(quest, keys(quests[domain])) == -1)
      return 0;

   // Not at the right previous step in the quest
   if (quests[domain][quest] != prev_task)
      return 0;

   quests[domain][quest] = task;

   add_quest_pts(pts);

   return 1;
}

void remove_quest(string domain, string quest)
{
   if (quests[domain] && quests[domain][quest])
      map_delete(quests[domain], quest);
   if (sizeof(keys(quests[domain])) == 0)
      map_delete(quests, domain);
   save_me();
}

string quest_task(string domain, string quest)
{
   if (!mapp(quests))
      quests = ([]);
   if (mapp(quests[domain]) && stringp(quests[domain][quest]))
      return quests[domain][quest];
   return "None";
}

int check_quest(string domain, string quest)
{
   int retVal = 0;
   if (!quests)
      return 0;
   if (!quests[domain])
      return 0;
   retVal = member_array(quest, keys(quests[domain])) != -1;
   if (!retVal)
      return 0;

   switch (quests[domain][quest])
   {
   case "end":
      return 2;
   default:
      return 1;
   }
   return retVal;
}

mapping query_quests()
{
   return quests;
}

protected
void rack_up_a_death()
{
   deaths++;
   points -= 20;
   save_me();

#ifdef USE_STATUS_LINE
   if (has_status_line())
      update_status_line();
#endif
}

int query_deaths()
{
   return deaths;
}

int query_score()
{
   return points;
}
