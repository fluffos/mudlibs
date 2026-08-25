#ifndef __CHAT_H__
#define __CHAT_H__

protected void create();

protected string cache_commands(string str);
protected void net_dead();

void eventReconnect();
int eventDestruct();

string *AddChannel(mixed val);
string *RemoveChannel(mixed val);
string *GetChannels();

string *RestrictChannel(mixed val);
string *UnrestrictChannel(mixed val);
string *GetRestrictedChannels();

#endif /* __CHAT_H__ */
