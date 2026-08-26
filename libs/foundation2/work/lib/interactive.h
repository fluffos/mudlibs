#ifndef __INTERACTIVE_H__
#define __INTERACTIVE_H__

nosave void create();
int Setup();
nosave void InitPath();
nosave void net_dead();
nosave void restart_heart();
void eventDescribeEnvironmentoom(int verbose);
varargs int eventMoveLiving(mixed dest, string msg);
int eventDestruct();
int cmdQuit(string str);
nosave int cmdAll(string str);

int GetAge();
int GetBirth();
string query_cwd();
void SetEmail(string str);
string GetEmail();
void SetId(string *bogus);
string *GetId();
int id(string str);
int GetLoginTime();
void SetKeyName(string str);
string GetKeyName();
void SetNews(string type, int sz);
int GetNews(string type);
string SetPassword(string str);
void SetPosition(string str);
string GetPosition();
string GetPrompt();
void SetRealName(string str);
string GetRealName();
string GetShort();
int SetBriefMode(int x);
int GetBriefMode();
int SetWhereBlock();
int GetWhereBlock();
string get_path();
string GetName();
string SetCapName(string str);
string GetCapName();
mixed *GetCommands();

#endif /* __INTERACTIVE_H__ */
