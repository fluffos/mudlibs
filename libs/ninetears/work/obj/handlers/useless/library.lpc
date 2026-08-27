nosave inherit "std/object";
 
#define RESTORE_PATH "/save/library/"
#include "quest_handler.h"
 
nosave string player_name;
string *quests, text_file, player_title;
int *times;
 
void setup()
{
  set_name("library");
}

void init_data(string pl_name)
{
  player_name = pl_name;
  quests = ({ });
  text_file = "";
  player_title = 0;
  times = ({ });
}

int get_data_file(string name)
{
  if(player_name != name) {
    if(restore_object(RESTORE_PATH+name,1)) {
      player_name = name;
      return 1;
    } else {
      return 0;
    }    
  } else {
    return 1;
  }
}
 
void save_data_file(string name)
{
  save_object(RESTORE_PATH + name,1);
}

string query_title(string name) {
  if(get_data_file(name))
    return player_title;
  else
    return 0;
}
 
string *query_quests(string name) {
  if(get_data_file(name))
    return quests + ({ });
  else
    return ({ });
}

string get_highest_quest(string name) {
  int loop, highest;
 
  if(!get_data_file(name))
    return "Sorry";
  if(!sizeof(quests))
    return "None";
  for(highest = loop = 0; loop < sizeof(quests); loop++)
    if(QUEST_HANDLER->query_quest_level(quests[loop]) > highest)
      highest = loop;
  return quests[highest];
}
 
int get_highest_quest_level(string name) {
  int highest;
  string qu_name;
 
  if(!get_data_file(name))
    return 0;
  if(!sizeof(quests))
    return 0;
  qu_name = get_highest_quest(name);
  if((highest = member_array(qu_name, quests)) == -1)
    return 0;
  return (int)QUEST_HANDLER->query_quest_level(quests[highest]);
}
 
string get_most_recent_quest(string name) {
  int loop, highest;

  
  if(!get_data_file(name))
    return "Sorry";
  if(sizeof(quests) == 0)
    return "None";
  return quests[sizeof(quests) - 1];
}
 
int get_most_recent_time(string name) {
  int loop, hightime;
 
  if(!get_data_file(name))
    return -1;
  if(!sizeof(quests))
    return 0;
  return times[sizeof(times) - 1];
}

int get_highest_quest_time(string name) {
  int hightime;
  string temp;
 
  if(!get_data_file(name))
    return -1;
  if(sizeof(quests) == 0)
    return 0;
  temp = get_highest_quest(name);
  hightime = member_array(temp, quests);
  return times[hightime];
}

int set_quest(string pl_name, string qu_name) {
  int qu_level, pos;
  object ob;

  if(!get_data_file(pl_name))
    init_data(pl_name);
  if(member_array(qu_name, quests) != -1)
    return 0;

  quests += ({ qu_name });
  times += ({ time() });
  qu_level = (int)QUEST_HANDLER->query_quest_level(qu_name);
  QUEST_HANDLER->quest_completed(pl_name, qu_name, previous_object());
  if(qu_level >= get_highest_quest_level(pl_name)) {
    player_title = (string)QUEST_HANDLER->query_quest_title(qu_name);
    if(ob = find_player(pl_name))
      ob->set_title(player_title);
  }
  seteuid((string)"secure/master"->get_root_uid());
  save_data_file(pl_name);
  seteuid("Room");
  return 1;
}
 
int query_quest_time(string pl_name, string qu_name) {
  int time;
 
  if(!get_data_file(name))
    return 0;
  time = member_array(qu_name, quests);
  if(time == -1) {
    return 0;
  }
  return times[time];
}

string query_story(string name) {
  string *story;
  int i;
 
  if(!get_data_file(name))
    return "You can find nothing in the library on " + name + ".\n";

  if(text_file != "")
    return read_file(text_file);

  if(!sizeof(quests))
    return capitalize(name) + " has lead a most unadventurous life.";

  story = ({ });
  for(i = 0; i < sizeof(quests); i++)
    story += ({ QUEST_HANDLER->query_quest_story(quests[i]) });

  if(sizeof(quests) == 1)
    return capitalize(name) + " has " + story[0] + ".\n";
  else
    return capitalize(name) + " has " +
           implode(story[0..sizeof(story)-2], ", ") + " and " +
           story[sizeof(story)-1] + ".\n";
}

void set_title(string who, string what) {
  if (!"/secure/login"->test_user(who))
    return ;
  get_data_file(who);
  player_title = what;
  save_data_file(who);
}

int query_quest_done(string player, string quest) {
  if(get_data_file(player))
    return (member_array(quest, quests) != -1);
  else
    return 0;
}

int query_quest_points(string name) {
  int tot, i;
  
  get_data_file(name);
  for(i=0; i<sizeof(quests); i++)
    tot += (int)QUEST_HANDLER->query_quest_level(quests[i]);
  return tot;
}
