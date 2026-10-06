#ifndef __COMMAND_H__
#define __COMMAND_H__

protected void create();
protected string process_input(string cmd);

protected int cmdAll(string arg);

int eventForce(string cmd);

int Setup();

string *AddSearchPath(mixed val);
string *RemoveSearchPath(mixed val);
string *GetSearchPath();
int GetForced();
int GetClient();
string SetCommandFail(string str);
string GetCommandFail();

#endif /* __COMMAND_H__ */
