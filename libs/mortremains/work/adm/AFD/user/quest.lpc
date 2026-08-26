// The quest handler functions for the user object.
// Written by Chronos 8/28/95.
// query_num_quests() returns how many quests have been solved.
// query_quests_array() returns the quest string array.
// quest_solved(x) adds a quest to the array of solved quests.
// remove_quest(x) removes a quest from the solved quest array.
#include <quest.h>

string *quests;

int query_num_quests() {
  return sizeof(quests);
}

string* query_quests_array() {
  return quests;
}

int quest_solved(string new_quest) {
  quests += ({ new_quest }) ;
  return 1;
}

int query_quests(string duh) {
  if (!quests || !duh) return 0;
  if (member_array(duh, quests) == -1) return 0;
  else return 1;
}

int remove_quest(string quest) {
  quests -= ({ quest }) ;
  return 1;
}
