#ifndef __QUEST__
#define __QUEST__

//#include "/adm/daemons/questd.lpc"
mapping query_quests();
mapping query_branch(string branch);
mapping query_quest(string branch, int qid);
int set_quest(string branch, int qid, mapping info);
int check_trigger(string branch, int qid, string msg);
int check_end(object who, string branch, int qid);

#endif
