#ifndef __COMMAND_H__
#define __COMMAND_H__

nosave void create();
nosave string process_input(string cmd);

nosave int cmdAll(string arg);

int eventForce(string cmd);

int Setup();

string *AddSearchPath(mixed val);
string *RemoveSearchPath(mixed val);
string *GetSearchPath();
int GetForced();
string GetClient();
string SetCommandFail(string str);
string GetCommandFail();

#endif /* __COMMAND_H__ */
